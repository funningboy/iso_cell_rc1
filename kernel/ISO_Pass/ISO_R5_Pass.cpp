
#include "kernel/ISO_Pass/ISO_R5_Pass.h"

void   ISO_R5_Pass::set_ISO_R5_ErrMessage(SC_Module::SC_Port_D *sc_en_p,
                                          SC_Module::SC_Port_D *sc_pre_p,
                                          SC_Module::SC_Port_D *sc_nxt_p){

        assert( sc_en_p       != NULL &&
                sc_pre_p      != NULL &&
                sc_nxt_p      != NULL && 
                sc_table      != NULL &&
                iso_table     != NULL && "ISO_R5_Pass->run_ISO_R5_ErrMessage");

      MErrMap[sc_en_p] = make_pair(sc_pre_p,sc_nxt_p);
}




void  ISO_R5_Pass::dump_ISO_R5_ErrMessage(ofstream *sc_file){

      assert( sc_file != NULL && "ISO_R5_Pass->dump_ISO_R5_ErrMessage");

     *sc_file << "  \n";
     *sc_file << "  \n";
     *sc_file << " ISO_5: \n";
     *sc_file << " Message: Isolation cell control pin is not connected to the specified signal. \n"; 
     *sc_file << " Description: : \n";
     *sc_file << "  I. This checks that the control pin of the specified isolation instances are \n";
     *sc_file << "       connected to the specified instance port of the corresponding isolation rules. \n";
     *sc_file << "  II. Check the connectivity of the isolation control to prevent design failure. \n";
     *sc_file << "  III. Similar to Cadence Conformal Low Power Verify: ISORULE1.1 \n";
     *sc_file << "  \n";
     *sc_file << "  \n";

     for(ISO_R5_Pass::ErrMap_iter err_it  = MErrMap.begin(); 
                                  err_it != MErrMap.end();  ++err_it){

       SC_Module::SC_Port_D *sc_en_p  = err_it->first;
       SC_Module::SC_Port_D *sc_pre_p = err_it->second.first;
       SC_Module::SC_Port_D *sc_nxt_p = err_it->second.second;

       SC_Module::SC_Domain_D *sc_pre_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_pre_p); 
       SC_Module::SC_Domain_D *sc_nxt_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_nxt_p);

       std::string sc_pre_d_nm = sc_pre_d->get_Name();
       std::string sc_nxt_d_nm = sc_nxt_d->get_Name();

       std::string sc_rule_nm  = iso_util->get_ISO_Rule_Name(iso_table,sc_pre_d_nm,sc_nxt_d_nm);

       ISO_CreateIsolationRule::ISO_CondPair iso_cond = iso_util-> get_ISO_Rule_Condition(iso_table,sc_pre_d_nm,sc_nxt_d_nm);

       std::string iso_cond_nm = iso_cond.second;    
 
       if( iso_cond.first == ISO_CreateIsolationRule::ISO_COND_OFF )
           iso_cond_nm = "!" + iso_cond_nm;

       std::string sc_en_p_nm   = sc_util->get_HierarchyName(sc_en_p);

      *sc_file << " the control pin of " << sc_en_p_nm   << " is connected to a wrong pin\n";
      *sc_file << " Rule "               << sc_rule_nm   << " - specified control pin is "
                                         << iso_cond_nm  << "\n";          
      *sc_file << "\n";

     }

}





SC_Module::SC_Port_D *ISO_R5_Pass::run_ISO_R5_Deep_Pass(SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R5_Pass::run_ISO_R5_Deep_Pass");

       SC_Module::PortVec deep_vec = sc_iso_en_p->get_NxtPortVec();
       assert( deep_vec.size()==1 && "ISO_R5_Pass::run_ISO_R5_Deep_Pass");

       SC_Module::PortVec_iter deep_it = deep_vec.begin();
       SC_Module::SC_Port_D *sc_deep_p = static_cast<SC_Module::SC_Port_D*>(*deep_it); 

return sc_deep_p;  
}





void   ISO_R5_Pass::run_ISO_R5_BUF_INV_PreestPassVec(SC_Module::SC_Port_D *sc_port,
                                                     SC_Module::PortVec   *port_vec ){

       assert(  sc_port   != NULL  &&
                sc_table  != NULL  &&
                iso_table != NULL  && "ISO_R5_Pass->run_ISO_R5_BUF_INV_PreestPassVec");

       SC_Module::PortVec  preest_p_vec;
       sc_util->get_PreestPassVec(sc_port,&preest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R5_Pass->run_ISO_R5_BUF_INV_Preest_PassVec");

           SC_Module::SC_Cell_D *re_sc_cell = is_ISO_R5_BUF_INV_Contain(sc_preest_p);

           if( re_sc_cell == NULL )
               port_vec->push_back(sc_preest_p);
           else
               run_ISO_R5_BUF_INV_PreestPassVec(sc_preest_p,port_vec); 
       }

}





SC_Module::SC_Cell_D  *ISO_R5_Pass::is_ISO_R5_BUF_INV_Contain(SC_Module::SC_Port_D *sc_port){

        assert(  sc_port     != NULL  &&
                 sc_table    != NULL  &&
                 iso_table   != NULL  && "ISO_R5_Pass->is_ISO_R5_BUF_Contain");

        SC_Module::SC_Pass_D * sc_port_ps = dynamic_cast<SC_Module::SC_Pass_D*>(sc_port);
  
        SC_Module *sc_module = sc_port->get_Parent(); 
        assert( sc_module != NULL && "ISO_R5_Pass->is_ISO_R5_BUF_Contain");

        std::string sc_module_nm    = sc_module->get_ModuleName();
        SC_Module::CellVec cell_vec = sc_module->get_CellVec();

        for(SC_Module::CellVec_iter cell_it  = cell_vec.begin();
                                    cell_it != cell_vec.end();  ++cell_it){

            SC_Module::SC_Cell_D    *sc_cell   = dynamic_cast<SC_Module::SC_Cell_D*>(*cell_it);
            SC_Module::SC_Domain_D  *sc_cell_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_cell);
            assert( sc_cell != NULL && "ISO_R5_Pass->is_ISO_R5_BUF_Contain");

            if(  sc_cell->get_Self() == NULL                    &&
                 sc_cell->get_TLib() == SC_Cell::SC_TLIB_BUF    ){

                SC_LIB::SC_BUF *sc_buf = dynamic_cast<SC_LIB::SC_BUF*>(sc_cell);
               
                if( sc_buf->get_Src() == sc_port ||
                    sc_buf->get_Dst() == sc_port ) 
                    return sc_cell;
            }

            if(  sc_cell->get_Self() == NULL                    &&
                 sc_cell->get_TLib() == SC_Cell::SC_TLIB_INV    ){

                SC_LIB::SC_INV *sc_inv = dynamic_cast<SC_LIB::SC_INV*>(sc_cell);
               
                if( sc_inv->get_Src() == sc_port ||
                    sc_inv->get_Dst() == sc_port ) 
                    return sc_cell;
            }
        }

return NULL;
}




void   ISO_R5_Pass::run_ISO_R5_Ctrl_Pass(SC_Module::SC_Port_D *sc_iso_en_p,
                                         SC_Module::SC_Port_D *sc_pre_p,
                                         SC_Module::SC_Port_D *sc_nxt_p){
 
       assert(  sc_iso_en_p  != NULL  &&
                sc_pre_p     != NULL  &&
                sc_nxt_p     != NULL  &&
                sc_table     != NULL  &&
                iso_table    != NULL  && "ISO_R5_Pass->run_ISO_R5_Ctrl_Pass");

       SC_Module *sc_root = sc_table->get_RootModule();
       assert( sc_root != NULL && "ISO_R5_Pass->run_R5_Ctrl_Pass");

       SC_Module::SC_Domain_D *sc_pre_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_pre_p); 
       SC_Module::SC_Domain_D *sc_nxt_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_nxt_p);

       std::string sc_pre_d_nm = sc_pre_d->get_Name();
       std::string sc_nxt_d_nm = sc_nxt_d->get_Name();

       std::string sc_rule_nm  = iso_util->get_ISO_Rule_Name(iso_table,sc_pre_d_nm,sc_nxt_d_nm);

       ISO_CreateIsolationRule::ISO_CondPair iso_cond = iso_util-> get_ISO_Rule_Condition(iso_table,sc_pre_d_nm,sc_nxt_d_nm);

       std::string iso_cond_nm = iso_cond.second;    

       for(SC_Module::PortVec_iter en_it  = Enable_p_Vec.begin();
                                   en_it != Enable_p_Vec.end();  ++en_it){

           SC_Module::SC_Port_D *sc_en_p =  static_cast<SC_Module::SC_Port_D*>(*en_it);
           assert( sc_en_p != NULL && "ISO_R5_Pass->run_ISO_R5_Ctrl_Pass");

           // @ Root check 
           if( sc_root->is_InputPortVec_Contain(sc_en_p) ){
 
               if( iso_cond_nm.compare(sc_en_p->get_Name() )!= 0)
                   set_ISO_R5_ErrMessage(sc_iso_en_p,sc_pre_p,sc_nxt_p);

           // @ Block gate check
           } else {

                  SC_Module::PortVec    Preest_v;
                  SC_Module::SC_Port_D *sc_src;

                  SC_Module::SC_Cell_D *sc_cell = is_ISO_R5_BUF_INV_Contain(sc_en_p);

                  if( sc_cell == NULL ){
                      set_ISO_R5_ErrMessage(sc_iso_en_p,sc_pre_p,sc_nxt_p); 

                 } else { 

                      SC_LIB::SC_BUF *sc_buf = dynamic_cast<SC_LIB::SC_BUF*>(sc_cell);
                      SC_LIB::SC_INV *sc_inv = dynamic_cast<SC_LIB::SC_INV*>(sc_cell);
           
                   if( sc_cell->get_TLib() == SC_Cell::SC_TLIB_BUF )
                       sc_src = sc_buf->get_Src(); 
             
                   if( sc_cell->get_TLib() == SC_Cell::SC_TLIB_INV )
                       sc_src = sc_inv->get_Src();       
           
                       run_ISO_R5_BUF_INV_PreestPassVec(sc_src,&Preest_v);
            
                  for(SC_Module::PortVec_iter p_it  = Preest_v.begin();
                                              p_it != Preest_v.end(); ++p_it){
                  
                      SC_Module::SC_Port_D *sc_nw_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
                      assert( sc_nw_p != NULL && "ISO_R5_Pass->run_ISO_R5_BUF_INV_PreestPass");
                  
                      if( sc_root->is_InputPortVec_Contain(sc_nw_p) ){
                  
                       if( iso_cond_nm.compare(sc_nw_p->get_Name() )!= 0 )
                           set_ISO_R5_ErrMessage(sc_iso_en_p,sc_pre_p,sc_nxt_p);
            
                      } else 
                           set_ISO_R5_ErrMessage(sc_iso_en_p,sc_pre_p,sc_nxt_p); 
                      
                    }
                 }      
            }
      }

}





void   ISO_R5_Pass::run_ISO_R5_Rule_Pass(SC_Module::SC_Cell_D *sc_cell,
                                         SC_Module::SC_Port_D *sc_iso_en_p){

       assert(  sc_cell     != NULL &&
                sc_iso_en_p != NULL &&
                sc_table    != NULL &&
                iso_table   != NULL && "ISO_R5_Pass->run_ISO_R5_Rule_Pass");

       SC_Module *sc_module  = sc_cell->get_Parent();
       std::string sc_iso_nm = sc_module->get_ModuleName();

       ISO_DefineIsolationCell::ISO_LOCATION iso_loc = iso_util->get_ISO_Cell_Location(iso_table,sc_iso_nm);

       SC_Module::SC_Domain_D *sc_cell_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_cell);

       std::string sc_cell_d_nm = sc_cell_d->get_Name();

       for(SC_Module::PortVec_iter pre_it = Preest_p_Vec.begin(); pre_it != Preest_p_Vec.end(); ++pre_it)
        for(SC_Module::PortVec_iter nxt_it = Nxtest_p_Vec.begin(); nxt_it != Nxtest_p_Vec.end(); ++nxt_it){

            SC_Module::SC_Port_D *sc_pre_p = static_cast<SC_Module::SC_Port_D*>(*pre_it);
            SC_Module::SC_Port_D *sc_nxt_p = static_cast<SC_Module::SC_Port_D*>(*nxt_it);

            assert( sc_pre_p != NULL &&
                    sc_nxt_p != NULL && "ISO_R3_Pass->run_ISO_R3_Rule_Pass");

            SC_Module::SC_Domain_D *sc_pre_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_pre_p); 
            SC_Module::SC_Domain_D *sc_nxt_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_nxt_p);

            std::string sc_pre_d_nm = sc_pre_d->get_Name();
            std::string sc_nxt_d_nm = sc_nxt_d->get_Name();

            std::string sc_rule_nm  = iso_util->get_ISO_Rule_Name(iso_table,sc_pre_d_nm,sc_nxt_d_nm);

            if( sc_nxt_d_nm.compare(sc_pre_d_nm)!=0              && 
                sc_cell_d_nm.compare(sc_pre_d_nm)== 0            && 
                iso_loc == ISO_DefineIsolationCell::ISO_LOC_FROM ) 
                run_ISO_R5_Ctrl_Pass(sc_iso_en_p,sc_pre_p,sc_nxt_p);                

            if( sc_nxt_d_nm.compare(sc_pre_d_nm)!=0              && 
                sc_cell_d_nm.compare(sc_nxt_d_nm)== 0            && 
                iso_loc == ISO_DefineIsolationCell::ISO_LOC_TO   )
                run_ISO_R5_Ctrl_Pass(sc_iso_en_p,sc_pre_p,sc_nxt_p); 
                
        }
}




void   ISO_R5_Pass::run_ISO_R5_AND_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                     SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R5_Pass->run_ISO_R5_AND_Pass");

       SC_LIB::SC_AND *sc_and = dynamic_cast<SC_LIB::SC_AND*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_and->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_and->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R5_Pass->run_ISO_R5_AND_Pass");

       SC_Module::PortVec Src1_p_Vec; 
       SC_Module::PortVec Src2_p_Vec; 

       Preest_p_Vec.clear();
       Enable_p_Vec.clear();

       sc_util->get_PreestPassVec(sc_src1_p,&Src1_p_Vec);
       sc_util->get_PreestPassVec(sc_src2_p,&Src2_p_Vec);
 
       // @ src1
       if( sc_src1_p == sc_iso_en_p )
           Enable_p_Vec.insert( Enable_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       else
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       
       // @ src2
       if( sc_src2_p == sc_iso_en_p )
           Enable_p_Vec.insert( Enable_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );
       else
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );

       Src1_p_Vec.clear();
       Src2_p_Vec.clear();
}




void   ISO_R5_Pass::run_ISO_R5_AND_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R5_Pass->run_ISO_R5_AND_Data_NxtPass");

       SC_LIB::SC_AND *sc_and = dynamic_cast<SC_LIB::SC_AND*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_and->get_Dst();

       assert( sc_dst_p != NULL && "ISO_R5_Pass->run_ISO_R5_AND_Data_NxtPass");

      // @ dst
       Nxtest_p_Vec.clear();
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R5_Pass::run_ISO_R5_NAND_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                      SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R5_Pass->run_ISO_R5_NAND_Data_Ctrl_PrePass");

       SC_LIB::SC_NAND *sc_nand = dynamic_cast<SC_LIB::SC_NAND*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_nand->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_nand->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R5_Pass->run_ISO_R5_NAND_Data_Ctrl_PrePass");

       SC_Module::PortVec Src1_p_Vec; 
       SC_Module::PortVec Src2_p_Vec; 

       Preest_p_Vec.clear();
       Enable_p_Vec.clear();

       sc_util->get_PreestPassVec(sc_src1_p,&Src1_p_Vec);
       sc_util->get_PreestPassVec(sc_src2_p,&Src2_p_Vec);
 
       // @ src1
       if( sc_src1_p == sc_iso_en_p )
           Enable_p_Vec.insert( Enable_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       else
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       

       // @ src2
       if( sc_src2_p != sc_iso_en_p )
           Enable_p_Vec.insert( Enable_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );
       else
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );
       

       Src1_p_Vec.clear();
       Src2_p_Vec.clear();
}





void   ISO_R5_Pass::run_ISO_R5_NAND_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R5_Pass->run_ISO_R5_NAND_Data_NxtPass");

       SC_LIB::SC_NAND *sc_nand = dynamic_cast<SC_LIB::SC_NAND*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_nand->get_Dst();

       assert( sc_dst_p != NULL && "ISO_R5_Pass->run_ISO_R5_NAND_Data_NxtPass");

      // @ dst
       Nxtest_p_Vec.clear();
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R5_Pass::run_ISO_R5_OR_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                    SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R5_Pass->run_ISO_R5_OR_Data_Ctrl_PrePass");

       SC_LIB::SC_OR *sc_or = dynamic_cast<SC_LIB::SC_OR*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_or->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_or->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R5_Pass->run_ISO_R5_OR_Data_Ctrl_PrePass");

       SC_Module::PortVec Src1_p_Vec; 
       SC_Module::PortVec Src2_p_Vec; 

       Preest_p_Vec.clear();
       Enable_p_Vec.clear();

       sc_util->get_PreestPassVec(sc_src1_p,&Src1_p_Vec);
       sc_util->get_PreestPassVec(sc_src2_p,&Src2_p_Vec);
 
       // @ src1
       if( sc_src1_p != sc_iso_en_p )
           Enable_p_Vec.insert( Enable_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       else
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );

       // @ src2
       if( sc_src2_p == sc_iso_en_p )
           Enable_p_Vec.insert( Enable_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );
       else
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );

       Src1_p_Vec.clear();
       Src2_p_Vec.clear();
}




void   ISO_R5_Pass::run_ISO_R5_OR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R5_Pass->run_ISO_R5_OR_Data_NxtPass");

       SC_LIB::SC_OR *sc_or = dynamic_cast<SC_LIB::SC_OR*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_or->get_Dst();

       assert( sc_dst_p != NULL && "ISO_R5_Pass->run_ISO_R5_OR_Data_NxtPass");

      // @ dst
       Nxtest_p_Vec.clear();
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R5_Pass::run_ISO_R5_NOR_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                     SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R5_Pass->run_ISO_R5_NOR_Pass");

       SC_LIB::SC_NOR *sc_nor = dynamic_cast<SC_LIB::SC_NOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_nor->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_nor->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R5_Pass->run_ISO_R5_NOR_Pass");

       SC_Module::PortVec Src1_p_Vec; 
       SC_Module::PortVec Src2_p_Vec; 

       Preest_p_Vec.clear();
       Enable_p_Vec.clear();

       sc_util->get_PreestPassVec(sc_src1_p,&Src1_p_Vec);
       sc_util->get_PreestPassVec(sc_src2_p,&Src2_p_Vec);
 
       // @ src1
       if( sc_src1_p == sc_iso_en_p )
           Enable_p_Vec.insert( Enable_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       else 
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       
       // @ src2
       if( sc_src2_p == sc_iso_en_p )
           Enable_p_Vec.insert( Enable_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );
       else
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );
       
       Src1_p_Vec.clear();
       Src2_p_Vec.clear();
}




void   ISO_R5_Pass::run_ISO_R5_NOR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R5_Pass->run_ISO_R5_NOR_Data_NxtPass");

       SC_LIB::SC_NOR *sc_nor = dynamic_cast<SC_LIB::SC_NOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_nor->get_Dst();

       assert( sc_dst_p  != NULL && "ISO_R5_Pass->run_ISO_R5_NOR_Data_NxtPass");

      // @ dst
       Nxtest_p_Vec.clear();
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R5_Pass::run_ISO_R5_XOR_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                     SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R5_Pass->run_ISO_R5_XOR_Pass");

       SC_LIB::SC_XOR *sc_xor = dynamic_cast<SC_LIB::SC_XOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_xor->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_xor->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R5_Pass->run_ISO_R5_XOR_Pass");

       SC_Module::PortVec Src1_p_Vec; 
       SC_Module::PortVec Src2_p_Vec; 

       Preest_p_Vec.clear();

       sc_util->get_PreestPassVec(sc_src1_p,&Src1_p_Vec);
       sc_util->get_PreestPassVec(sc_src2_p,&Src2_p_Vec);
 
       // @ src1
       if( sc_src1_p == sc_iso_en_p )
           Enable_p_Vec.insert( Enable_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       else
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       
       // @ src2
       if( sc_src2_p == sc_iso_en_p )
           Enable_p_Vec.insert( Enable_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );
       else
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );

       Src1_p_Vec.clear();
       Src2_p_Vec.clear();
}




void   ISO_R5_Pass::run_ISO_R5_XOR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R5_Pass->run_ISO_R5_XOR_Data_NxtPass");

       SC_LIB::SC_XOR *sc_xor = dynamic_cast<SC_LIB::SC_XOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_xor->get_Dst();

       assert( sc_dst_p != NULL && "ISO_R5_Pass->run_ISO_R5_XOR_Data_NxtPass");

       // @ Dst
       Nxtest_p_Vec.clear();
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R5_Pass::run_ISO_R5_XNOR_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                      SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R5_Pass->run_ISO_R5_XNOR_Data_Ctrl_PrePass");

       SC_LIB::SC_XNOR *sc_xnor = dynamic_cast<SC_LIB::SC_XNOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_xnor->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_xnor->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R5_Pass->run_ISO_R5_XNOR_Data_Ctrl_PrePass");

       SC_Module::PortVec Src1_p_Vec; 
       SC_Module::PortVec Src2_p_Vec; 

       Preest_p_Vec.clear();
       Enable_p_Vec.clear();

       sc_util->get_PreestPassVec(sc_src1_p,&Src1_p_Vec);
       sc_util->get_PreestPassVec(sc_src2_p,&Src2_p_Vec);

       // @ src1
       if( sc_src1_p == sc_iso_en_p )
           Enable_p_Vec.insert( Enable_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );
       else
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src1_p_Vec.begin(), Src1_p_Vec.end() );

       // @ src2
       if( sc_src2_p == sc_iso_en_p )
           Enable_p_Vec.insert( Enable_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );
       else
           Preest_p_Vec.insert( Preest_p_Vec.end(), Src2_p_Vec.begin(), Src2_p_Vec.end() );

       Src1_p_Vec.clear();
       Src2_p_Vec.clear();
}





void   ISO_R5_Pass::run_ISO_R5_XNOR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R5_Pass->run_ISO_R5_XNOR_Data_NxtPass");

       SC_LIB::SC_XNOR *sc_xnor = dynamic_cast<SC_LIB::SC_XNOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_xnor->get_Dst();

       assert( sc_dst_p != NULL && "ISO_R5_Pass->run_ISO_R5_XNOR_Data_NxtPass");

       // @dst
       Nxtest_p_Vec.clear(); 
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R5_Pass::run_ISO_R5_BUF_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                     SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R5_Pass->run_ISO_R5_BUF_Data_Ctrl_PrePass");

       SC_LIB::SC_BUF *sc_buf = dynamic_cast<SC_LIB::SC_BUF*>(sc_cell);

       SC_Module::SC_Port_D *sc_src_p = sc_buf->get_Src();
       assert( sc_src_p != NULL && "ISO_R5_Pass->run_ISO_R5_BUF_Data_Ctrl_PrePass");

       // @ src
       Preest_p_Vec.clear();
       Enable_p_Vec.clear();

       if( sc_src_p == sc_iso_en_p )
           sc_util->get_PreestPassVec(sc_src_p,&Enable_p_Vec);
       else 
           sc_util->get_PreestPassVec(sc_src_p,&Preest_p_Vec);
      
}




void   ISO_R5_Pass::run_ISO_R5_BUF_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R5_Pass->run_ISO_R5_BUF_Data_NxtPass");

       SC_LIB::SC_BUF *sc_buf = dynamic_cast<SC_LIB::SC_BUF*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_buf->get_Dst();

       assert( sc_dst_p != NULL && "ISO_R5_Pass->run_ISO_R5_BUF_Data_NxtPass");

       // @ dst 
       Nxtest_p_Vec.clear();
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R5_Pass::run_ISO_R5_INV_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                                     SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell     != NULL &&
               sc_iso_en_p != NULL &&
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R5_Pass->run_ISO_R5_INV_Data_Ctrl_PrePass");

       SC_LIB::SC_INV *sc_inv = dynamic_cast<SC_LIB::SC_INV*>(sc_cell);

       SC_Module::SC_Port_D *sc_src_p = sc_inv->get_Src();
       assert( sc_src_p != NULL && "ISO_R5_Pass->run_ISO_R5_INV_Data_Ctrl_PrePass");

       // @ src
       Preest_p_Vec.clear();
       Enable_p_Vec.clear();

       if( sc_src_p == sc_iso_en_p )
           sc_util->get_PreestPassVec(sc_src_p,&Enable_p_Vec);
       else
           sc_util->get_PreestPassVec(sc_src_p,&Preest_p_Vec);
}




void   ISO_R5_Pass::run_ISO_R5_INV_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R5_Pass->run_ISO_R5_INV_Data_NxtPass");

       SC_LIB::SC_INV *sc_inv = dynamic_cast<SC_LIB::SC_INV*>(sc_cell);

       SC_Module::SC_Port_D *sc_dst_p = sc_inv->get_Dst();
       assert( sc_dst_p != NULL && "ISO_R5_Pass->run_ISO_R5_INV_Data_NxtPass");

       // @ dst
       Nxtest_p_Vec.clear();
       sc_util->get_NxtestPassVec(sc_dst_p,&Nxtest_p_Vec);
}




void   ISO_R5_Pass::run_ISO_R5_Logic_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                             SC_Module::SC_Port_D *sc_iso_en_p){

       assert( sc_cell   != NULL && 
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R5_Pass->run_ISO_R5_Trace_Pass");

       SC_Cell::SC_TLIB sc_tlib = sc_cell->get_TLib(); 

       if(sc_tlib == SC_Cell::SC_TLIB_AND  ){ run_ISO_R5_AND_Data_Ctrl_PrePass(sc_cell,sc_iso_en_p);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_NAND ){ run_ISO_R5_NAND_Data_Ctrl_PrePass(sc_cell,sc_iso_en_p); }
  else if(sc_tlib == SC_Cell::SC_TLIB_OR   ){ run_ISO_R5_OR_Data_Ctrl_PrePass(sc_cell,sc_iso_en_p);   }
  else if(sc_tlib == SC_Cell::SC_TLIB_NOR  ){ run_ISO_R5_NOR_Data_Ctrl_PrePass(sc_cell,sc_iso_en_p);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_XOR  ){ run_ISO_R5_XOR_Data_Ctrl_PrePass(sc_cell,sc_iso_en_p);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_XNOR ){ run_ISO_R5_XNOR_Data_Ctrl_PrePass(sc_cell,sc_iso_en_p); }
  else if(sc_tlib == SC_Cell::SC_TLIB_BUF  ){ run_ISO_R5_BUF_Data_Ctrl_PrePass(sc_cell,sc_iso_en_p);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_INV  ){ run_ISO_R5_INV_Data_Ctrl_PrePass(sc_cell,sc_iso_en_p);  }

}




void   ISO_R5_Pass::run_ISO_R5_Logic_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL && 
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R5_Pass->run_ISO_R5_Trace_Pass");

       SC_Cell::SC_TLIB sc_tlib = sc_cell->get_TLib(); 

       if(sc_tlib == SC_Cell::SC_TLIB_AND  ){ run_ISO_R5_AND_Data_NxtPass(sc_cell);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_NAND ){ run_ISO_R5_NAND_Data_NxtPass(sc_cell); }
  else if(sc_tlib == SC_Cell::SC_TLIB_OR   ){ run_ISO_R5_OR_Data_NxtPass(sc_cell);   }
  else if(sc_tlib == SC_Cell::SC_TLIB_NOR  ){ run_ISO_R5_NOR_Data_NxtPass(sc_cell);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_XOR  ){ run_ISO_R5_XOR_Data_NxtPass(sc_cell);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_XNOR ){ run_ISO_R5_XNOR_Data_NxtPass(sc_cell); }
  else if(sc_tlib == SC_Cell::SC_TLIB_BUF  ){ run_ISO_R5_BUF_Data_NxtPass(sc_cell);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_INV  ){ run_ISO_R5_INV_Data_NxtPass(sc_cell);  }

}




void   ISO_R5_Pass::run_ISO_R5_Trace_Pass(){

       assert( sc_table  != NULL &&
               iso_table != NULL && "ISO_R5_Pass->run_ISO_R5_Trace_Pass");

        SC_Module::CellVec cell_vec = sc_table->get_LeafCellVec();               

        for(SC_Module::CellVec_iter cell_it  = cell_vec.begin();
                                    cell_it != cell_vec.end();   ++cell_it){

            SC_Module::SC_Cell_D *sc_cell = static_cast<SC_Module::SC_Cell_D*>(*cell_it);
            assert( sc_cell != NULL && "ISO_R5_Pass->run_ISO_R5_Trace_Pass");
 
            // @ Library 
            if( sc_util->is_Deepest_Module(sc_cell) ){
   
                SC_Module *sc_module = sc_cell->get_Parent();
                assert( sc_module != NULL && "ISO_R5_Pass->run_ISO_R5_Trace_Pass");
    
                std::string module_nm = sc_module->get_ModuleName();

                if( iso_util->is_ISO_Cell_Contain(iso_table,module_nm) ){

                   std::string iso_en = iso_util->get_ISO_Cell_Enable(iso_table,module_nm);

                   SC_Module::SC_Port_D *sc_iso_en_p = sc_util->split_path_2_Port(sc_module,iso_en);
                   assert( sc_iso_en_p != NULL && "ISO_R5_Pass->run_ISO_R5_Trace_Pass");

                   // set 2 deepest logic
                   sc_iso_en_p = run_ISO_R5_Deep_Pass(sc_iso_en_p);

                   run_ISO_R5_Logic_Data_Ctrl_PrePass(sc_cell,sc_iso_en_p);
                   run_ISO_R5_Logic_Data_NxtPass(sc_cell);
                   run_ISO_R5_Rule_Pass(sc_cell,sc_iso_en_p);

             }       
           }

       }
} 
