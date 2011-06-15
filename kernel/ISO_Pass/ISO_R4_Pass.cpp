
#include "kernel/ISO_Pass/ISO_R4_Pass.h"

void   ISO_R4_Pass::set_ISO_R4_ErrMessage(SC_Module::SC_Port_D *sc_preest_p,
                                          SC_Module::SC_Port_D *sc_port,
                                          std::string sc_rule_nm){

        assert( sc_preest_p != NULL &&
                sc_port     != NULL && 
                !sc_rule_nm.empty() &&
                sc_table    != NULL &&
                iso_table   != NULL && "ISO_R4_Pass->run_ISO_R4_ErrMessage");

        MErrMap[sc_rule_nm].push_back(make_pair(sc_preest_p,sc_port));         
}




void  ISO_R4_Pass::dump_ISO_R4_ErrMessage(ofstream *sc_file){

      assert( sc_file != NULL && "ISO_R5_Pass->dump_ISO_R5_ErrMessage");

      *sc_file << " ISO_4: \n";
      *sc_file << " Message: Power domain crossing does not have user-defined isolation cell. \n";
      *sc_file << " Description: \n";
      *sc_file << "  I. Report error when there is an OFF-ON/ON-OFF crossing between two power \n";
      *sc_file << "       domains that does not have a user-defined isolation cell. \n";
      *sc_file << "  II. Netlist bug can cause tape-out failure. \n";
      *sc_file << "  III. Similar to Cadence Conformal Low Power Verify: ISO7 \n";
      *sc_file << "\n";
      *sc_file << "\n";

     for(ISO_R4_Pass::ErrMap_iter err_map_it  = MErrMap.begin();
                                  err_map_it != MErrMap.end();  ++err_map_it){

        std::string sc_rule_nm       = err_map_it->first;
        ISO_R4_Pass::ErrVec  err_vec = err_map_it->second;

        for(ISO_R4_Pass::ErrVec_iter err_vec_it  = err_vec.begin();
                                     err_vec_it != err_vec.end();  ++err_vec_it){ 
            
            SC_Module::SC_Port_D *sc_preest_p = err_vec_it->first;
            SC_Module::SC_Port_D *sc_port     = err_vec_it->second;

            std::string sc_preest_nm = sc_util->get_HierarchyName(sc_preest_p);             
            std::string sc_port_nm   = sc_util->get_HierarchyName(sc_port);

            SC_Module::SC_Domain_D *sc_preest_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_preest_p);  
            SC_Module::SC_Domain_D *sc_port_d   = dynamic_cast<SC_Module::SC_Domain_D*>(sc_port);

            std::string sc_preest_d_nm = sc_preest_d->get_Name();
            std::string sc_port_d_nm   = sc_port_d->get_Name();

            *sc_file << " Driver is :"       << sc_preest_nm << " ( power domain " << sc_preest_d_nm << " )\n";
            *sc_file << " Matching rule : "  << sc_rule_nm   << "\n";
            *sc_file << " Leaf load : "      << sc_port_nm   << " ( power domain " << sc_port_d_nm  << " )\n";
            *sc_file << "\n";
         }
     } 
}




void  ISO_R4_Pass::run_ISO_R4_Check_Pass(SC_Module::SC_Port_D *sc_preest_p,
                                          SC_Module::SC_Port_D *sc_port){

      assert( sc_preest_p != NULL &&
              sc_port     != NULL &&
              sc_table    != NULL &&
              iso_table   != NULL && "ISO_R4_Pass->run_ISO_R4_Check_Pass");

      SC_Module::SC_Domain_D *sc_preest_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_preest_p);
      SC_Module::SC_Domain_D *sc_port_d   = dynamic_cast<SC_Module::SC_Domain_D*>(sc_port);

      std::string sc_preest_d_nm = sc_preest_d->get_Name();
      std::string sc_port_d_nm   = sc_port_d->get_Name();

      std::string iso_rule_nm        = iso_util->get_ISO_Rule_Name(iso_table,sc_preest_d_nm,sc_port_d_nm);
      ISO_Util::ModeMap iso_mode_map = iso_util->get_ISO_Mode_Names(iso_table,sc_preest_d_nm,sc_port_d_nm);

      bool pass = false;

      for(ISO_Util::ModeMap_iter mode_it  = iso_mode_map.begin();
                                 mode_it != iso_mode_map.end();  ++mode_it){

          ISO_Util::StrVec iso_mode_vec = mode_it->second;
          assert( iso_mode_vec.size()==2 && "run_ISO_R4_Check_Pass");  
       
          std::string iso_to_cond   = iso_mode_vec.back();  iso_mode_vec.pop_back();
          std::string iso_from_cond = iso_mode_vec.back();  iso_mode_vec.pop_back();

          float iso_from_vt = iso_util->get_ISO_Condition_Voltage(iso_table,iso_from_cond);
          float iso_to_vt   = iso_util->get_ISO_Condition_Voltage(iso_table,iso_to_cond);
         
          if( iso_from_vt != iso_to_vt )
              pass = true;           
       } 

      if( !iso_rule_nm.empty()  &&
           pass                 ) 
           set_ISO_R4_ErrMessage(sc_preest_p,sc_port,iso_rule_nm);

}





SC_Module::SC_Cell_D  *ISO_R4_Pass::is_ISO_R4_BUF_Contain(SC_Module::SC_Port_D *sc_port,
                                                          std::string sc_domain_nm){

        assert(  sc_port     != NULL  &&
                !sc_domain_nm.empty() &&
                 sc_table    != NULL  &&
                 iso_table   != NULL  && "ISO_R4_Pass->is_ISO_R4_BUF_Contain");

        SC_Module::SC_Pass_D * sc_port_ps = dynamic_cast<SC_Module::SC_Pass_D*>(sc_port);
  
        SC_Module *sc_module = sc_port->get_Parent(); 
        assert( sc_module != NULL && "ISO_R4_Pass->is_ISO_R4_BUF_Contain");

        std::string sc_module_nm    = sc_module->get_ModuleName();
        SC_Module::CellVec cell_vec = sc_module->get_CellVec();

        for(SC_Module::CellVec_iter cell_it  = cell_vec.begin();
                                    cell_it != cell_vec.end();  ++cell_it){

            SC_Module::SC_Cell_D    *sc_cell   = dynamic_cast<SC_Module::SC_Cell_D*>(*cell_it);
            SC_Module::SC_Domain_D  *sc_cell_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_cell);
            assert( sc_cell != NULL && "ISO_R4_Pass->is_ISO_R4_BUF_Contain");

            if( sc_cell->get_Self() == NULL                    &&
                sc_cell->get_TLib() == SC_Cell::SC_TLIB_BUF    &&
                sc_domain_nm.compare(sc_cell_d->get_Name())==0 ){

                SC_LIB::SC_BUF *sc_buf = dynamic_cast<SC_LIB::SC_BUF*>(sc_cell);
               
                if( sc_buf->get_Src() == sc_port ||
                    sc_buf->get_Dst() == sc_port ) 
                    return sc_cell;
            }
        }
return NULL;
}




void   ISO_R4_Pass::run_ISO_R4_BUF_PreestVec(SC_Module::SC_Port_D *sc_port,
                                             std::string           sc_domain_nm,
                                             SC_Module::PortVec   *port_vec ){

       assert(  sc_port   != NULL    &&
               !sc_domain_nm.empty() && 
                sc_table  != NULL    &&
                iso_table != NULL    && "ISO_R4_Pass->run_ISO_R4_BUF_PreestVec");

       SC_Module::PortVec  preest_p_vec;
       sc_util->get_PreestPassVec(sc_port,&preest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);

           SC_Module::SC_Cell_D *re_sc_cell = is_ISO_R4_BUF_Contain(sc_preest_p,sc_domain_nm);

           if( re_sc_cell == NULL )
               port_vec->push_back(sc_preest_p);
           else
               run_ISO_R4_BUF_PreestVec(sc_preest_p,sc_domain_nm,port_vec); 
       }

}    
       



void   ISO_R4_Pass::run_ISO_R4_BUF_NxtestVec(SC_Module::SC_Port_D *sc_port,
                                             std::string           sc_domain_nm,
                                             SC_Module::PortVec   *port_vec ){

       assert(  sc_port   != NULL    &&
               !sc_domain_nm.empty() &&
                sc_table  != NULL    &&
                iso_table != NULL    && "ISO_R4_Pass->run_ISO_R4_BUF_NxtestVec");

       SC_Module::PortVec  nxtest_p_vec;
       sc_util->get_NxtestPassVec(sc_port,&nxtest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = nxtest_p_vec.begin();
                                    p_it != nxtest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_nxtest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);

           SC_Module::SC_Cell_D *re_sc_cell = is_ISO_R4_BUF_Contain(sc_nxtest_p,sc_domain_nm);

           if( re_sc_cell == NULL )
               port_vec->push_back(sc_nxtest_p);
           else
               run_ISO_R4_BUF_NxtestVec(sc_nxtest_p,sc_domain_nm,port_vec); 
       }

}




bool   ISO_R4_Pass::run_ISO_R4_Rule_Pass(SC_Module::SC_Port_D *sc_preest_p,
                                         SC_Module::SC_Port_D *sc_port){

       assert( sc_preest_p != NULL &&
               sc_port     != NULL && 
               sc_table    != NULL &&
               iso_table   != NULL && "ISO_R4_Pass->run_ISO_R4_Rule_Pass");

       SC_Module::SC_Domain_D *sc_preest_p_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_preest_p);  
       SC_Module::SC_Domain_D *sc_port_d     = dynamic_cast<SC_Module::SC_Domain_D*>(sc_port);

       SC_Module::SC_Pass_D *sc_preest_p_ps  = dynamic_cast<SC_Module::SC_Pass_D*>(sc_preest_p);  
       SC_Module::SC_Pass_D *sc_port_ps      = dynamic_cast<SC_Module::SC_Pass_D*>(sc_port);

       std::string sc_preest_d_nm = sc_preest_p_d->get_Name();
       std::string sc_port_d_nm   = sc_port_d->get_Name();

       if( sc_port_d_nm.compare(sc_preest_d_nm) !=0 ){

           SC_Module *sc_preest_m = sc_preest_p->get_Parent();
           SC_Module *sc_port_m   = sc_port->get_Parent();

           assert( sc_preest_m != NULL && 
                   sc_port_m   != NULL && "ISO_R4_Pass->run_ISO_R4_Rule_Pass");

           std::string sc_preest_m_nm = sc_preest_m->get_ModuleName();   
           std::string sc_port_m_nm   = sc_port_m->get_ModuleName();

           if( !iso_util->is_ISO_Cell_Contain(iso_table,sc_preest_m_nm) && 
               !iso_util->is_ISO_Cell_Contain(iso_table,sc_port_m_nm)   )
              return true;
           
       }

return false;
}




void   ISO_R4_Pass::run_ISO_R4_AND_Data_PrePass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R4_Pass->run_ISO_R4_AND_Pass");

       SC_LIB::SC_AND *sc_and = dynamic_cast<SC_LIB::SC_AND*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_and->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_and->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R4_Pass->run_ISO_R4_AND_Pass");

       // @ src1
       SC_Module::PortVec  preest_p_vec;
       sc_util->get_PreestPassVec(sc_src1_p,&preest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R4_Pass->run_ISO_R4_AND_Pass");

           SC_Module::SC_Domain_D *sc_preest_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_preest_p);

           bool iso_r4_ps = run_ISO_R4_Rule_Pass(sc_preest_p,sc_src1_p);

           if( iso_r4_ps )
               run_ISO_R4_Check_Pass(sc_preest_p,sc_src1_p);
     }

       preest_p_vec.clear();

       // @ src2
       sc_util->get_PreestPassVec(sc_src2_p,&preest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R4_Pass->run_ISO_R4_AND_Pass");

           bool iso_r4_ps = run_ISO_R4_Rule_Pass(sc_preest_p,sc_src2_p);

           if( iso_r4_ps )
               run_ISO_R4_Check_Pass(sc_preest_p,sc_src2_p);
      }
}




void   ISO_R4_Pass::run_ISO_R4_NAND_Data_PrePass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R4_Pass->run_ISO_R4_NAND_Pass");

       SC_LIB::SC_NAND *sc_nand = dynamic_cast<SC_LIB::SC_NAND*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_nand->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_nand->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R4_Pass->run_ISO_R4_NAND_Pass");

       // @ src1
       SC_Module::PortVec  preest_p_vec;
       sc_util->get_PreestPassVec(sc_src1_p,&preest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R4_Pass->run_ISO_R4_NAND_Pass");

           bool iso_r4_ps = run_ISO_R4_Rule_Pass(sc_preest_p,sc_src1_p);

           if( iso_r4_ps )
               run_ISO_R4_Check_Pass(sc_preest_p,sc_src1_p);
 
      }

       preest_p_vec.clear();

       // @ src2
       sc_util->get_PreestPassVec(sc_src2_p,&preest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R4_Pass->run_ISO_R4_NAND_Pass");

           bool iso_r4_ps = run_ISO_R4_Rule_Pass(sc_preest_p,sc_src2_p);

           if( iso_r4_ps )
               run_ISO_R4_Check_Pass(sc_preest_p,sc_src2_p);
 
      }
}





void   ISO_R4_Pass::run_ISO_R4_OR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R4_Pass->run_ISO_R4_OR_Pass");

       SC_LIB::SC_OR *sc_or = dynamic_cast<SC_LIB::SC_OR*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_or->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_or->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R4_Pass->run_ISO_R4_OR_Pass");

       // @ src1
       SC_Module::PortVec  preest_p_vec;
       sc_util->get_PreestPassVec(sc_src1_p,&preest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R4_Pass->run_ISO_R4_OR_Pass");

           bool iso_r4_ps = run_ISO_R4_Rule_Pass(sc_preest_p,sc_src1_p);

           if( iso_r4_ps )
               run_ISO_R4_Check_Pass(sc_preest_p,sc_src1_p);
      }

       preest_p_vec.clear();

       // @ src2
       sc_util->get_PreestPassVec(sc_src2_p,&preest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R4_Pass->run_ISO_R4_OR_Pass");

           bool iso_r4_ps = run_ISO_R4_Rule_Pass(sc_preest_p,sc_src2_p);

           if( iso_r4_ps )
               run_ISO_R4_Check_Pass(sc_preest_p,sc_src2_p);
       }
}





void   ISO_R4_Pass::run_ISO_R4_NOR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R4_Pass->run_ISO_R4_NOR_Pass");

       SC_LIB::SC_NOR *sc_nor = dynamic_cast<SC_LIB::SC_NOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_nor->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_nor->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R4_Pass->run_ISO_R4_NOR_Pass");

       // @ src1
       SC_Module::PortVec  preest_p_vec;
       sc_util->get_PreestPassVec(sc_src1_p,&preest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R4_Pass->run_ISO_R4_NOR_Pass");

           bool iso_r4_ps = run_ISO_R4_Rule_Pass(sc_preest_p,sc_src1_p);

           if( iso_r4_ps )
               run_ISO_R4_Check_Pass(sc_preest_p,sc_src1_p);
 
       }

       preest_p_vec.clear();

       // @ src2
       sc_util->get_PreestPassVec(sc_src2_p,&preest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R4_Pass->run_ISO_R4_NOR_Pass");

           bool iso_r4_ps = run_ISO_R4_Rule_Pass(sc_preest_p,sc_src2_p);

           if( iso_r4_ps )
               run_ISO_R4_Check_Pass(sc_preest_p,sc_src2_p);
      }
}





void   ISO_R4_Pass::run_ISO_R4_XOR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R4_Pass->run_ISO_R4_XOR_Pass");

       SC_LIB::SC_XOR *sc_xor = dynamic_cast<SC_LIB::SC_XOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_xor->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_xor->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R4_Pass->run_ISO_R4_XOR_Pass");

       // @ src1
       SC_Module::PortVec  preest_p_vec;
       sc_util->get_PreestPassVec(sc_src1_p,&preest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R4_Pass->run_ISO_R4_XOR_Pass");

           bool iso_r4_ps = run_ISO_R4_Rule_Pass(sc_preest_p,sc_src1_p);

           if( iso_r4_ps )
               run_ISO_R4_Check_Pass(sc_preest_p,sc_src1_p);
      }

       preest_p_vec.clear();

       // @ src2
       sc_util->get_PreestPassVec(sc_src2_p,&preest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R4_Pass->run_ISO_R4_XOR_Pass");

           bool iso_r4_ps = run_ISO_R4_Rule_Pass(sc_preest_p,sc_src2_p);

           if( iso_r4_ps )
               run_ISO_R4_Check_Pass(sc_preest_p,sc_src2_p);
       }
}





void   ISO_R4_Pass::run_ISO_R4_XNOR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R4_Pass->run_ISO_R4_XNOR_Pass");

       SC_LIB::SC_XNOR *sc_xnor = dynamic_cast<SC_LIB::SC_XNOR*>(sc_cell);

       SC_Module::SC_Port_D *sc_src1_p = sc_xnor->get_Src1();
       SC_Module::SC_Port_D *sc_src2_p = sc_xnor->get_Src2();

       assert( sc_src1_p != NULL &&
               sc_src2_p != NULL && "ISO_R4_Pass->run_ISO_R4_XNOR_Pass");

       // @ src1
       SC_Module::PortVec  preest_p_vec;
       sc_util->get_PreestPassVec(sc_src1_p,&preest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R4_Pass->run_ISO_R4_XNOR_Pass");

           bool iso_r4_ps = run_ISO_R4_Rule_Pass(sc_preest_p,sc_src1_p);

           if( iso_r4_ps ) 
               run_ISO_R4_Check_Pass(sc_preest_p,sc_src1_p);
      }

       preest_p_vec.clear();

       // @ src2
       sc_util->get_PreestPassVec(sc_src2_p,&preest_p_vec);

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R4_Pass->run_ISO_R4_XNOR_Pass");

           bool iso_r4_ps = run_ISO_R4_Rule_Pass(sc_preest_p,sc_src2_p);

           if( iso_r4_ps )
               run_ISO_R4_Check_Pass(sc_preest_p,sc_src2_p);
       }
}




void   ISO_R4_Pass::run_ISO_R4_BUF_Data_PrePass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R4_Pass->run_ISO_R4_BUF_Pass");

       SC_LIB::SC_BUF *sc_buf = dynamic_cast<SC_LIB::SC_BUF*>(sc_cell);

       SC_Module::SC_Port_D *sc_src_p = sc_buf->get_Src();
       SC_Module::SC_Port_D *sc_dst_p = sc_buf->get_Dst();

       assert( sc_src_p != NULL && 
               sc_dst_p != NULL && "ISO_R4_Pass->run_ISO_R4_BUF_Pass");

       SC_Module::SC_Domain_D *sc_cell_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_cell);

       std::string sc_cell_d_nm = sc_cell_d->get_Name();

       // @ src
       SC_Module::PortVec  preest_p_vec;
       sc_util->get_PreestPassVec(sc_src_p,&preest_p_vec);

       SC_Module::PortVec PreestVec;
       SC_Module::PortVec NxtestVec;

       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R4_Pass->run_ISO_R4_BUF_Pass");

           bool iso_r4_ps  = run_ISO_R4_Rule_Pass(sc_preest_p,sc_src_p);

           PreestVec.clear();
           NxtestVec.clear();

          if( iso_r4_ps ){

              SC_Module::SC_Domain_D *sc_preest_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_preest_p);
              assert( sc_preest_d != NULL && "ISO_R4_Pass->run_ISO_R4_BUF_Pass");

              std::string sc_preest_d_nm       = sc_preest_d->get_Name();
              SC_Module::SC_Cell_D *re_sc_cell = is_ISO_R4_BUF_Contain(sc_preest_p,sc_preest_d_nm);
              SC_LIB::SC_BUF       *re_sc_buf  = dynamic_cast<SC_LIB::SC_BUF*>(re_sc_cell);

              run_ISO_R4_BUF_NxtestVec(sc_dst_p,sc_cell_d_nm,&NxtestVec);

              if( re_sc_cell != NULL )
                  run_ISO_R4_BUF_PreestVec(re_sc_buf->get_Src(),sc_preest_d_nm,&PreestVec); 

              if( PreestVec.empty() )
                  PreestVec.push_back(sc_preest_p);

              if( NxtestVec.empty() )   
                  NxtestVec.push_back(sc_src_p);

              for( SC_Module::PortVec_iter pre_it = PreestVec.begin(); pre_it != PreestVec.end(); ++pre_it)
               for( SC_Module::PortVec_iter nxt_it = NxtestVec.begin(); nxt_it != NxtestVec.end(); ++nxt_it){
                    bool re_iso_r4_ps = run_ISO_R4_Rule_Pass(*pre_it,*nxt_it);

                    if( re_iso_r4_ps )
                    run_ISO_R4_Check_Pass(*pre_it,*nxt_it);
               }
          }
       } 
}




void   ISO_R4_Pass::run_ISO_R4_INV_Data_PrePass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL &&
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R4_Pass->run_ISO_R4_INV_Pass");

       SC_LIB::SC_INV *sc_inv = dynamic_cast<SC_LIB::SC_INV*>(sc_cell);

       SC_Module::SC_Port_D *sc_src_p = sc_inv->get_Src();
       assert( sc_src_p != NULL && "ISO_R4_Pass->run_ISO_R4_INV_Pass");

       // @ src
       SC_Module::PortVec  preest_p_vec;
       sc_util->get_PreestPassVec(sc_src_p,&preest_p_vec);
 
       for(SC_Module::PortVec_iter  p_it  = preest_p_vec.begin();
                                    p_it != preest_p_vec.end();   ++p_it){

           SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
           assert( sc_preest_p != NULL && "ISO_R4_Pass->run_ISO_R4_INV_Pass");

           bool iso_r4_ps = run_ISO_R4_Rule_Pass(sc_preest_p,sc_src_p);

           if( iso_r4_ps )
               run_ISO_R4_Check_Pass(sc_preest_p,sc_src_p);
       }
}




void   ISO_R4_Pass::run_ISO_R4_Logic_Data_PrePass(SC_Module::SC_Cell_D *sc_cell){

       assert( sc_cell   != NULL && 
               sc_table  != NULL &&
               iso_table != NULL && "ISO_R4_Pass->run_ISO_R4_Trace_Pass");

       SC_Cell::SC_TLIB sc_tlib = sc_cell->get_TLib(); 

       if(sc_tlib == SC_Cell::SC_TLIB_AND  ){ run_ISO_R4_AND_Data_PrePass(sc_cell);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_NAND ){ run_ISO_R4_NAND_Data_PrePass(sc_cell); }
  else if(sc_tlib == SC_Cell::SC_TLIB_OR   ){ run_ISO_R4_OR_Data_PrePass(sc_cell);   }
  else if(sc_tlib == SC_Cell::SC_TLIB_NOR  ){ run_ISO_R4_NOR_Data_PrePass(sc_cell);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_XOR  ){ run_ISO_R4_XOR_Data_PrePass(sc_cell);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_XNOR ){ run_ISO_R4_XNOR_Data_PrePass(sc_cell); }
  else if(sc_tlib == SC_Cell::SC_TLIB_BUF  ){ run_ISO_R4_BUF_Data_PrePass(sc_cell);  }
  else if(sc_tlib == SC_Cell::SC_TLIB_INV  ){ run_ISO_R4_INV_Data_PrePass(sc_cell);  }

}




void   ISO_R4_Pass::run_ISO_R4_Trace_Pass(){

       assert( sc_table  != NULL &&
               iso_table != NULL && "ISO_R4_Pass->run_ISO_R4_Trace_Pass");

        SC_Module::CellVec cell_vec = sc_table->get_LeafCellVec();               

        for(SC_Module::CellVec_iter cell_it  = cell_vec.begin();
                                    cell_it != cell_vec.end();   ++cell_it){

            SC_Module::SC_Cell_D *sc_cell = static_cast<SC_Module::SC_Cell_D*>(*cell_it);
            assert( sc_cell != NULL && "ISO_R4_Pass->run_ISO_R4_Trace_Pass");
  
            // @ Library 
            if( sc_util->is_Deepest_Module(sc_cell) ){
   
                SC_Module *sc_module = sc_cell->get_Parent();
                assert( sc_module != NULL && "ISO_R5_Pass->run_ISO_R5_Trace_Pass");
    
                std::string module_nm = sc_module->get_ModuleName();

                if( !iso_util->is_ISO_Cell_Contain(iso_table,module_nm) )
                     run_ISO_R4_Logic_Data_PrePass(sc_cell);

            }
        }
}  
