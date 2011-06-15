
#include "kernel/ISO_Pass/ISO_R2_Pass.h"


void   ISO_R2_Pass::set_ISO_R2_ErrMessage(SC_Module::SC_Port_D *sc_pre_p,
                                          SC_Module::SC_Port_D *sc_nxt_p,
                                          SC_Module::SC_Cell_D *sc_cell){

        assert( sc_pre_p  != NULL &&
                sc_nxt_p  != NULL && 
                sc_table  != NULL &&
                iso_table != NULL && "ISO_R2_Pass->run_ISO_R2_Rule_Pass");

        MErrMap[sc_cell] = make_pair(sc_pre_p,sc_nxt_p);                
}




void  ISO_R2_Pass::dump_ISO_R2_ErrMessage(ofstream *sc_file){

      assert( sc_file != NULL && "ISO_R2_Pass->dump_ISO_R2_ErrMessage");

      *sc_file << "\n";
      *sc_file << "\n";
      *sc_file << " ISO_2: \n";
      *sc_file << " Message: Source and destination domains of the isolation cells are the same. \n";
      *sc_file << " Description: \n";
      *sc_file << "   I. This rule can find redundant isolation cells in the netlist. \n";
      *sc_file << "   II. Similar to Cadence Conformal Low Power Verify: ISO3.2 \n";
      *sc_file << "\n";
      *sc_file << "\n";

     for(ISO_R2_Pass::ErrMap_iter err_it  = MErrMap.begin();
                                  err_it != MErrMap.end();  ++err_it){

         SC_Module::SC_Cell_D *sc_cell = err_it->first;

         std::string sc_module_nm = sc_cell->get_ModuleName(); 
         std::string sc_cell_nm   = sc_util->get_HierarchyName(sc_cell);

         SC_Module::SC_Port_D *sc_pre_p = err_it->second.first;
         SC_Module::SC_Port_D *sc_nxt_p = err_it->second.second;

         std::string sc_pre_p_nm = sc_util->get_HierarchyName(sc_pre_p);             
         std::string sc_nxt_p_nm = sc_util->get_HierarchyName(sc_nxt_p);

         SC_Module::SC_Domain_D *sc_pre_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_pre_p);  
         SC_Module::SC_Domain_D *sc_nxt_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_nxt_p);

         std::string sc_pre_d_nm = sc_pre_d->get_Name();
         std::string sc_nxt_d_nm = sc_nxt_d->get_Name();

         *sc_file << "Instance:           " << sc_cell_nm  <<  "( " << sc_module_nm << " )\n";
         *sc_file << "Source domain:      " << sc_pre_d_nm <<  "\n";
         *sc_file << "Destination domain: " << sc_nxt_d_nm <<  "\n";
         *sc_file << "Source pin:         " << sc_pre_p_nm <<  "\n";
         *sc_file << "Destination pin:    " << sc_nxt_p_nm <<  "\n";

     }
}




SC_Module::SC_Port_D *ISO_R2_Pass::run_ISO_R2_Deep_Pass(SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_iso_en_p != NULL && "ISO_R2_Pass::run_ISO_R2_Deep_Pass");

       SC_Module::PortVec deep_vec = sc_iso_en_p->get_NxtPortVec();
       assert( deep_vec.size()==1 && "ISO_R2_Pass::run_ISO_R2_Deep_Pass");

       SC_Module::PortVec_iter deep_it = deep_vec.begin();
       SC_Module::SC_Port_D *sc_deep_p = static_cast<SC_Module::SC_Port_D*>(*deep_it); 

return sc_deep_p;  
}




void   ISO_R2_Pass::run_ISO_R2_Rule_Pass(SC_Module::SC_Cell_D *sc_cell){

       assert(  sc_cell     != NULL &&
                sc_table    != NULL &&
                iso_table   != NULL && "ISO_R2_Pass->run_ISO_R2_Rule_Pass");

       for(SC_Module::PortVec_iter pre_it = Preest_p_Vec.begin(); pre_it != Preest_p_Vec.end(); ++pre_it)
        for(SC_Module::PortVec_iter nxt_it = Nxtest_p_Vec.begin(); nxt_it != Nxtest_p_Vec.end(); ++nxt_it){

            SC_Module::SC_Port_D *sc_pre_p = static_cast<SC_Module::SC_Port_D*>(*pre_it);
            SC_Module::SC_Port_D *sc_nxt_p = static_cast<SC_Module::SC_Port_D*>(*nxt_it);

            assert( sc_pre_p != NULL &&
                    sc_nxt_p != NULL && "ISO_R2_Pass->run_ISO_R2_Rule_Pass");

            SC_Module::SC_Domain_D *sc_pre_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_pre_p); 
            SC_Module::SC_Domain_D *sc_nxt_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_nxt_p);

            std::string sc_pre_d_nm = sc_pre_d->get_Name();
            std::string sc_nxt_d_nm = sc_nxt_d->get_Name();

            if( sc_nxt_d_nm.compare( sc_pre_d_nm)==0 )
                set_ISO_R2_ErrMessage(sc_pre_p,sc_nxt_p,sc_cell);

        }

}




void   ISO_R2_Pass::run_ISO_R2_AND_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R2_Pass->run_ISO_R2_AND_Pass");

       SC_LIB::SC_AND *sc_and = dynamic_cast<SC_LIB::SC_AND*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_and->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_and->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R2_Pass->run_ISO_R2_AND_Pass");

       SC_Module::PortVec Src1_p_Vec; 
       SC_Module::PortVec Src2_p_Vec; 

       Preest_p_Vec.clear();

       // @ src1
       if( sc_src1_p != sc_iso_en_p ){
           sc_util->get_PreestPassVec(sc_src1_p,&Src1_p_Vec);
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       }

       // @ src2
       if( sc_src2_p != sc_iso_en_p ){
           sc_util->get_PreestPassVec(sc_src2_p,&Src2_p_Vec);
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );
       }

       Src1_p_Vec.clear();
       Src2_p_Vec.clear();
}




void   ISO_R2_Pass::run_ISO_R2_AND_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R2_Pass->run_ISO_R2_AND_Data_NxtPass");

       SC_LIB::SC_AND *sc_and = dynamic_cast<SC_LIB::SC_AND*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_and->get_Dst();

       assert( sc_dst_p != NULL && "ISO_R2_Pass->run_ISO_R2_AND_Data_NxtPass");

      // @ dst
       Nxtest_p_Vec.clear();
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R2_Pass::run_ISO_R2_NAND_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                 SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R2_Pass->run_ISO_R2_NAND_Data_PrePass");

       SC_LIB::SC_NAND *sc_nand = dynamic_cast<SC_LIB::SC_NAND*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_nand->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_nand->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R2_Pass->run_ISO_R2_NAND_Data_PrePass");

       SC_Module::PortVec Src1_p_Vec; 
       SC_Module::PortVec Src2_p_Vec; 

       Preest_p_Vec.clear();

       // @ src1
       if( sc_src1_p != sc_iso_en_p ){
           sc_util->get_PreestPassVec(sc_src1_p,&Src1_p_Vec);
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       }

       // @ src2
       if( sc_src2_p != sc_iso_en_p ){
           sc_util->get_PreestPassVec(sc_src2_p,&Src2_p_Vec);
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );
       }

       Src1_p_Vec.clear();
       Src2_p_Vec.clear();
}





void   ISO_R2_Pass::run_ISO_R2_NAND_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R2_Pass->run_ISO_R2_NAND_Data_NxtPass");

       SC_LIB::SC_NAND *sc_nand = dynamic_cast<SC_LIB::SC_NAND*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_nand->get_Dst();

       assert( sc_dst_p != NULL && "ISO_R2_Pass->run_ISO_R2_NAND_Data_NxtPass");

      // @ dst
       Nxtest_p_Vec.clear();
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R2_Pass::run_ISO_R2_OR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                               SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R2_Pass->run_ISO_R2_OR_Data_PrePass");

       SC_LIB::SC_OR *sc_or = dynamic_cast<SC_LIB::SC_OR*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_or->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_or->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R2_Pass->run_ISO_R2_OR_Data_PrePass");

       SC_Module::PortVec Src1_p_Vec; 
       SC_Module::PortVec Src2_p_Vec; 

       Preest_p_Vec.clear();

       // @ src1
       if( sc_src1_p != sc_iso_en_p ){
           sc_util->get_PreestPassVec(sc_src1_p,&Src1_p_Vec);
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       }

       // @ src2
       if( sc_src2_p != sc_iso_en_p ){
           sc_util->get_PreestPassVec(sc_src2_p,&Src2_p_Vec);
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );
       }

       Src1_p_Vec.clear();
       Src2_p_Vec.clear();
}




void   ISO_R2_Pass::run_ISO_R2_OR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R2_Pass->run_ISO_R2_OR_Data_NxtPass");

       SC_LIB::SC_OR *sc_or = dynamic_cast<SC_LIB::SC_OR*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_or->get_Dst();

       assert( sc_dst_p != NULL && "ISO_R2_Pass->run_ISO_R2_OR_Data_NxtPass");

      // @ dst
       Nxtest_p_Vec.clear();
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R2_Pass::run_ISO_R2_NOR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R2_Pass->run_ISO_R2_NOR_Pass");

       SC_LIB::SC_NOR *sc_nor = dynamic_cast<SC_LIB::SC_NOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_nor->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_nor->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R2_Pass->run_ISO_R2_NOR_Pass");

       SC_Module::PortVec Src1_p_Vec; 
       SC_Module::PortVec Src2_p_Vec; 

       Preest_p_Vec.clear();

       // @ src1
       if( sc_src1_p != sc_iso_en_p ){
           sc_util->get_PreestPassVec(sc_src1_p,&Src1_p_Vec);
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       }

       // @ src2
       if( sc_src2_p != sc_iso_en_p ){
           sc_util->get_PreestPassVec(sc_src2_p,&Src2_p_Vec);
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );
       }

       Src1_p_Vec.clear();
       Src2_p_Vec.clear();
}




void   ISO_R2_Pass::run_ISO_R2_NOR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R2_Pass->run_ISO_R2_NOR_Data_NxtPass");

       SC_LIB::SC_NOR *sc_nor = dynamic_cast<SC_LIB::SC_NOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_nor->get_Dst();

       assert( sc_dst_p  != NULL && "ISO_R2_Pass->run_ISO_R2_NOR_Data_NxtPass");

      // @ dst
       Nxtest_p_Vec.clear();
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R2_Pass::run_ISO_R2_XOR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R2_Pass->run_ISO_R2_XOR_Pass");

       SC_LIB::SC_XOR *sc_xor = dynamic_cast<SC_LIB::SC_XOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_xor->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_xor->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R2_Pass->run_ISO_R2_XOR_Pass");

       SC_Module::PortVec Src1_p_Vec; 
       SC_Module::PortVec Src2_p_Vec; 

       Preest_p_Vec.clear();

       // @ src1
       if( sc_src1_p != sc_iso_en_p ){
           sc_util->get_PreestPassVec(sc_src1_p,&Src1_p_Vec);
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       }

       // @ src2
       if( sc_src2_p != sc_iso_en_p ){
           sc_util->get_PreestPassVec(sc_src2_p,&Src2_p_Vec);
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );
       }

       Src1_p_Vec.clear();
       Src2_p_Vec.clear();
}




void   ISO_R2_Pass::run_ISO_R2_XOR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R2_Pass->run_ISO_R2_XOR_Data_NxtPass");

       SC_LIB::SC_XOR *sc_xor = dynamic_cast<SC_LIB::SC_XOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_xor->get_Dst();

       assert( sc_dst_p != NULL && "ISO_R2_Pass->run_ISO_R2_XOR_Data_NxtPass");

       // @ Dst
       Nxtest_p_Vec.clear();
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R2_Pass::run_ISO_R2_XNOR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                 SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R2_Pass->run_ISO_R2_XNOR_Data_PrePass");

       SC_LIB::SC_XNOR *sc_xnor = dynamic_cast<SC_LIB::SC_XNOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_xnor->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_xnor->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R2_Pass->run_ISO_R2_XNOR_Data_PrePass");

       SC_Module::PortVec Src1_p_Vec; 
       SC_Module::PortVec Src2_p_Vec; 

       Preest_p_Vec.clear();

       // @ src1
       if( sc_src1_p != sc_iso_en_p ){
           sc_util->get_PreestPassVec(sc_src1_p,&Src1_p_Vec);
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       }

       // @ src2
       if( sc_src2_p != sc_iso_en_p ){ 
           sc_util->get_PreestPassVec(sc_src2_p,&Src2_p_Vec);
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );
       }

       Src1_p_Vec.clear();
       Src2_p_Vec.clear();
}





void   ISO_R2_Pass::run_ISO_R2_XNOR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R2_Pass->run_ISO_R2_XNOR_Data_NxtPass");

       SC_LIB::SC_XNOR *sc_xnor = dynamic_cast<SC_LIB::SC_XNOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_xnor->get_Dst();

       assert( sc_dst_p != NULL && "ISO_R2_Pass->run_ISO_R2_XNOR_Data_NxtPass");

       // @dst
       Nxtest_p_Vec.clear(); 
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R2_Pass::run_ISO_R2_BUF_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R2_Pass->run_ISO_R2_BUF_Data_PrePass");

       SC_LIB::SC_BUF *sc_buf = dynamic_cast<SC_LIB::SC_BUF*>(sc_cell);

       SC_Module::SC_Port_D *sc_src_p = sc_buf->get_Src();
       assert( sc_src_p != NULL && "ISO_R2_Pass->run_ISO_R2_BUF_Data_PrePass");

       // @ src
       Preest_p_Vec.clear();

       if( sc_src_p == sc_iso_en_p )
       return;

       sc_util->get_PreestPassVec(sc_src_p,&Preest_p_Vec);
}




void   ISO_R2_Pass::run_ISO_R2_BUF_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R2_Pass->run_ISO_R2_BUF_Data_NxtPass");

       SC_LIB::SC_BUF *sc_buf = dynamic_cast<SC_LIB::SC_BUF*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_buf->get_Dst();

       assert( sc_dst_p != NULL && "ISO_R2_Pass->run_ISO_R2_BUF_Data_NxtPass");

       // @ dst 
       Nxtest_p_Vec.clear();
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R2_Pass::run_ISO_R2_INV_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R2_Pass->run_ISO_R2_INV_Data_PrePass");

       SC_LIB::SC_INV *sc_inv = dynamic_cast<SC_LIB::SC_INV*>(sc_cell);

       SC_Module::SC_Port_D *sc_src_p = sc_inv->get_Src();
       assert( sc_src_p != NULL && "ISO_R2_Pass->run_ISO_R2_INV_Data_PrePass");

       // @ src
       Preest_p_Vec.clear();

       if( sc_src_p == sc_iso_en_p )
       return;

       sc_util->get_PreestPassVec(sc_src_p,&Preest_p_Vec);
}




void   ISO_R2_Pass::run_ISO_R2_INV_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R2_Pass->run_ISO_R2_INV_Data_NxtPass");

       SC_LIB::SC_INV *sc_inv = dynamic_cast<SC_LIB::SC_INV*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_inv->get_Dst();
       assert( sc_dst_p != NULL && "ISO_R2_Pass->run_ISO_R2_INV_Data_NxtPass");

       // @ dst
       Nxtest_p_Vec.clear();
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R2_Pass::run_ISO_R2_Logic_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                  SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell   != NULL && 
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R2_Pass->run_ISO_R2_Trace_Pass");

       SC_Cell::SC_TLIB sc_tlib = sc_cell->get_TLib(); 

       if(sc_tlib == SC_Cell::SC_TLIB_AND  ){ run_ISO_R2_AND_Data_PrePass(sc_cell,sc_iso_en_p);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_NAND ){ run_ISO_R2_NAND_Data_PrePass(sc_cell,sc_iso_en_p); }
  else if(sc_tlib == SC_Cell::SC_TLIB_OR   ){ run_ISO_R2_OR_Data_PrePass(sc_cell,sc_iso_en_p);   }
  else if(sc_tlib == SC_Cell::SC_TLIB_NOR  ){ run_ISO_R2_NOR_Data_PrePass(sc_cell,sc_iso_en_p);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_XOR  ){ run_ISO_R2_XOR_Data_PrePass(sc_cell,sc_iso_en_p);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_XNOR ){ run_ISO_R2_XNOR_Data_PrePass(sc_cell,sc_iso_en_p); }
  else if(sc_tlib == SC_Cell::SC_TLIB_BUF  ){ run_ISO_R2_BUF_Data_PrePass(sc_cell,sc_iso_en_p);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_INV  ){ run_ISO_R2_INV_Data_PrePass(sc_cell,sc_iso_en_p);  }

}




void   ISO_R2_Pass::run_ISO_R2_Logic_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL && 
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R2_Pass->run_ISO_R2_Trace_Pass");

       SC_Cell::SC_TLIB sc_tlib = sc_cell->get_TLib(); 

       if(sc_tlib == SC_Cell::SC_TLIB_AND  ){ run_ISO_R2_AND_Data_NxtPass(sc_cell);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_NAND ){ run_ISO_R2_NAND_Data_NxtPass(sc_cell); }
  else if(sc_tlib == SC_Cell::SC_TLIB_OR   ){ run_ISO_R2_OR_Data_NxtPass(sc_cell);   }
  else if(sc_tlib == SC_Cell::SC_TLIB_NOR  ){ run_ISO_R2_NOR_Data_NxtPass(sc_cell);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_XOR  ){ run_ISO_R2_XOR_Data_NxtPass(sc_cell);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_XNOR ){ run_ISO_R2_XNOR_Data_NxtPass(sc_cell); }
  else if(sc_tlib == SC_Cell::SC_TLIB_BUF  ){ run_ISO_R2_BUF_Data_NxtPass(sc_cell);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_INV  ){ run_ISO_R2_INV_Data_NxtPass(sc_cell);  }

}




void   ISO_R2_Pass::run_ISO_R2_Trace_Pass(){

       assert( sc_table  != NULL &&
               iso_table != NULL && "ISO_R2_Pass->run_ISO_R2_Trace_Pass");

        SC_Module::CellVec cell_vec = sc_table->get_LeafCellVec();               

        for(SC_Module::CellVec_iter cell_it  = cell_vec.begin();
                                    cell_it != cell_vec.end();   ++cell_it){

            SC_Module::SC_Cell_D *sc_cell = static_cast<SC_Module::SC_Cell_D*>(*cell_it);
            assert( sc_cell != NULL && "ISO_R2_Pass->run_ISO_R2_Trace_Pass");

            // @ Library 
            if( sc_util->is_Deepest_Module(sc_cell) ){

                SC_Module *sc_module = sc_cell->get_Parent();
                assert( sc_module != NULL && "ISO_R2_Pass->run_ISO_R2_Trace_Pass");

                std::string module_nm = sc_module->get_ModuleName();

                if( iso_util->is_ISO_Cell_Contain(iso_table,module_nm) ){

                    std::string iso_en_nm = iso_util->get_ISO_Cell_Enable(iso_table,module_nm);

                    SC_Module::SC_Port_D *sc_iso_en_p = sc_util->split_path_2_Port(sc_module,iso_en_nm);
                    assert( sc_iso_en_p != NULL && "ISO_R2_Pass->run_ISO_R2_Trace_Pass");

                    // set 2 deepest logic
                    sc_iso_en_p = run_ISO_R2_Deep_Pass(sc_iso_en_p);

                    run_ISO_R2_Logic_Data_PrePass(sc_cell,sc_iso_en_p);
                    run_ISO_R2_Logic_Data_NxtPass(sc_cell);
                    run_ISO_R2_Rule_Pass(sc_cell);

               }       
            }

        }
} 
