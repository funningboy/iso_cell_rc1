
#include "kernel/SC_Context/SC_Util.h"





void       SC_Util::get_NxtestVec(SC_Module::SC_Port_D *sc_port, 
                                  SC_Module::PortVec *port_vec){

           assert( sc_port != NULL && "SC_Util->get_NxtestVec" );

           SC_Module::PortVec nxt_p_vec = sc_port->get_NxtPortVec();

           for(SC_Module::PortVec_iter p_it  = nxt_p_vec.begin();
                                       p_it != nxt_p_vec.end();   ++p_it){

                    SC_Module::SC_Port_D *sc_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
                    assert( sc_p != NULL && "SC_Util->get_NxtestVec" );  

                    if( sc_p->has_NxtPortVec() )
                        get_NxtestVec(sc_p,port_vec);
                    else
                        port_vec->push_back(sc_p);
          }
}






void       SC_Util::get_NxtOutputVec(SC_Module::SC_Port_D *sc_port,
                                     SC_Module::PortVec *port_vec){

           assert( sc_port != NULL && "SC_Util->get_NxtOutputVec" );

           SC_Module::PortVec nxt_p_vec = sc_port->get_NxtPortVec();

           for(SC_Module::PortVec_iter p_it  = nxt_p_vec.begin();
                                       p_it != nxt_p_vec.end();   ++p_it){

               SC_Module::SC_Port_D *sc_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
               assert( sc_p != NULL && "SC_Util->get_NxtOutputVec" );  

               SC_Module *sc_mm = sc_p->get_Parent();
               assert( sc_mm != NULL && "SC_Util->get_NxtOutputVec" );    

               if( sc_mm->is_OutputPortVec_Contain(sc_p) )
                   port_vec->push_back(sc_p);
               else
                   get_NxtOutputVec(sc_p,port_vec);

          }
}





void       SC_Util::get_NxtInputVec(SC_Module::SC_Port_D *sc_port,
                                    SC_Module::PortVec *port_vec){

           assert( sc_port != NULL && "SC_Util->get_NxtInputVec" );

           SC_Module::PortVec nxt_p_vec = sc_port->get_NxtPortVec();

           for(SC_Module::PortVec_iter p_it  = nxt_p_vec.begin();
                                       p_it != nxt_p_vec.end();   ++p_it){

               SC_Module::SC_Port_D *sc_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
               assert( sc_p != NULL && "SC_Util->get_NxtInputVec" );  

               SC_Module *sc_mm = sc_p->get_Parent();
               assert( sc_mm != NULL && "SC_Util->get_NxtInputVec" );    

               if( sc_mm->is_InputPortVec_Contain(sc_p) )
                   port_vec->push_back(sc_p);
               else
                   get_NxtInputVec(sc_p,port_vec);

          }
}





void       SC_Util::get_PreestVec(SC_Module::SC_Port_D *sc_port,
                                  SC_Module::PortVec *port_vec){

           assert( sc_port  != NULL && "SC_Util->get_PreestVec" );

           SC_Module::PortVec pre_p_vec = sc_port->get_PrePortVec();

           for(SC_Module::PortVec_iter p_it  = pre_p_vec.begin();
                                       p_it != pre_p_vec.end();   ++p_it){

               SC_Module::SC_Port_D *sc_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
               assert( sc_p != NULL && "SC_Util->get_PreestVec" );  

               if( sc_p->has_PrePortVec() )
                   get_PreestVec(sc_p,port_vec);
               else
                   port_vec->push_back(sc_p);

            }
}




void       SC_Util::get_AND_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                       SC_Module::SC_Port_D *sc_port,
                                       SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_AND_PrePassVec");
    
           SC_AND *sc_and = dynamic_cast<SC_AND*>(sc_cell);

           if( sc_and->get_Dst() == sc_port ){
               port_vec->push_back( sc_and->get_Src1() );
               port_vec->push_back( sc_and->get_Src2() );
           }
}




void       SC_Util::get_AND_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                       SC_Module::SC_Port_D *sc_port,
                                       SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_AND_NxtPassVec");
    
           SC_AND *sc_and = dynamic_cast<SC_AND*>(sc_cell);

           if( sc_and->get_Src1() == sc_port ||
               sc_and->get_Src2() == sc_port ){
               port_vec->push_back( sc_and->get_Dst() );
           }
}




void       SC_Util::get_NAND_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                        SC_Module::SC_Port_D *sc_port,
                                        SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_NAND_PrePassVec");
    
           SC_NAND *sc_nand = dynamic_cast<SC_NAND*>(sc_cell);

           if( sc_nand->get_Dst() == sc_port ){
               port_vec->push_back( sc_nand->get_Src1() );
               port_vec->push_back( sc_nand->get_Src2() );
           }
}





void       SC_Util::get_NAND_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                        SC_Module::SC_Port_D *sc_port,
                                        SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_NAND_NxtPassVec");
    
           SC_NAND *sc_nand = dynamic_cast<SC_NAND*>(sc_cell);

           if( sc_nand->get_Src1() == sc_port ||
               sc_nand->get_Src2() == sc_port ){
               port_vec->push_back( sc_nand->get_Dst() );
           }
}




void       SC_Util::get_OR_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                      SC_Module::SC_Port_D *sc_port,
                                      SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_OR_PrePassVec");
    
           SC_OR *sc_or = dynamic_cast<SC_OR*>(sc_cell);

           if( sc_or->get_Dst() == sc_port ){
               port_vec->push_back( sc_or->get_Src1() );
               port_vec->push_back( sc_or->get_Src2() );
           }
}




void       SC_Util::get_OR_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                      SC_Module::SC_Port_D *sc_port,
                                      SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_OR_NxtPassVec");
    
           SC_OR *sc_or = dynamic_cast<SC_OR*>(sc_cell);

           if( sc_or->get_Src1() == sc_port ||
               sc_or->get_Src2() == sc_port ){
               port_vec->push_back( sc_or->get_Dst() );
           }
}




void       SC_Util::get_NOR_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                       SC_Module::SC_Port_D *sc_port,
                                       SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_NOR_PrePassVec");
    
           SC_NOR *sc_nor = dynamic_cast<SC_NOR*>(sc_cell);

           if( sc_nor->get_Dst() == sc_port ){
               port_vec->push_back( sc_nor->get_Src1() );
               port_vec->push_back( sc_nor->get_Src2() );
           }
}




void       SC_Util::get_NOR_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                       SC_Module::SC_Port_D *sc_port,
                                       SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_NOR_NxtPassVec");
    
           SC_NOR *sc_nor = dynamic_cast<SC_NOR*>(sc_cell);

           if( sc_nor->get_Src1() == sc_port ||
               sc_nor->get_Src2() == sc_port ){
               port_vec->push_back( sc_nor->get_Dst() );
           }
}




void       SC_Util::get_XOR_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                       SC_Module::SC_Port_D *sc_port,
                                       SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_XOR_PrePassVec");
    
           SC_XOR *sc_xor = dynamic_cast<SC_XOR*>(sc_cell);

           if( sc_xor->get_Dst() == sc_port ){
               port_vec->push_back( sc_xor->get_Src1() );
               port_vec->push_back( sc_xor->get_Src2() );
           }
}




void       SC_Util::get_XOR_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                       SC_Module::SC_Port_D *sc_port,
                                       SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_XOR_NxtPassVec");
    
           SC_XOR *sc_xor = dynamic_cast<SC_XOR*>(sc_cell);

           if( sc_xor->get_Src1() == sc_port ||
               sc_xor->get_Src2() == sc_port ){
               port_vec->push_back( sc_xor->get_Dst() );
           }
}




void       SC_Util::get_XNOR_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                        SC_Module::SC_Port_D *sc_port,
                                        SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_XNOR_PrePassVec");
    
           SC_XNOR *sc_xnor = dynamic_cast<SC_XNOR*>(sc_cell);

           if( sc_xnor->get_Dst() == sc_port ){
               port_vec->push_back( sc_xnor->get_Src1() );
               port_vec->push_back( sc_xnor->get_Src2() );
           }
}




void       SC_Util::get_XNOR_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                        SC_Module::SC_Port_D *sc_port,
                                        SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_XNOR_NxtPassVec");
    
           SC_XNOR *sc_xnor = dynamic_cast<SC_XNOR*>(sc_cell);

           if( sc_xnor->get_Src1() == sc_port ||
               sc_xnor->get_Src2() == sc_port ){
               port_vec->push_back( sc_xnor->get_Dst() );
           }
}




void       SC_Util::get_BUF_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                       SC_Module::SC_Port_D *sc_port,
                                       SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_BUF_PrePassVec");
    
           SC_BUF *sc_buf = dynamic_cast<SC_BUF*>(sc_cell);

           if( sc_buf->get_Dst() == sc_port)
           port_vec->push_back( sc_buf->get_Src() );

}




void       SC_Util::get_BUF_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                       SC_Module::SC_Port_D *sc_port,
                                       SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_BUF_NxtPassVec");
    
           SC_BUF *sc_buf = dynamic_cast<SC_BUF*>(sc_cell);

           if( sc_buf->get_Src() == sc_port)
           port_vec->push_back( sc_buf->get_Dst() );

}




void       SC_Util::get_INV_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                       SC_Module::SC_Port_D *sc_port,
                                       SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_INV_PrePassVec");
    
           SC_INV *sc_inv = dynamic_cast<SC_INV*>(sc_cell);

           if( sc_inv->get_Dst() == sc_port )
           port_vec->push_back( sc_inv->get_Src() );

}




void       SC_Util::get_INV_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                       SC_Module::SC_Port_D *sc_port,
                                       SC_Module::PortVec *port_vec){

           assert( sc_cell != NULL &&
                   sc_port != NULL && "SC_Util->get_Nxt_PrePassVec");
    
           SC_INV *sc_inv = dynamic_cast<SC_INV*>(sc_cell);

           if( sc_inv->get_Src() == sc_port )
           port_vec->push_back( sc_inv->get_Dst() );

}




void       SC_Util::get_PrePassVec(SC_Module::SC_Port_D *sc_port,
                                   SC_Module::PortVec *port_vec){

           assert( sc_port != NULL && "SC_Util->get_PrePassVec" );

           SC_Module::SC_Pass_D *sc_ps = dynamic_cast<SC_Module::SC_Pass_D*>(sc_port);

           if( sc_ps->get_Pass() == true ){

               SC_Module *sc_module = sc_port->get_Parent();
               assert( sc_module != NULL && "SC_Util->get_PrePassVec");

               SC_Module::CellVec cell_vec = sc_module->get_CellVec();

               for(SC_Module::CellVec_iter cell_it  = cell_vec.begin();
                                           cell_it != cell_vec.end();   ++cell_it){
 
                   SC_Module::SC_Cell_D *sc_cell = static_cast<SC_Module::SC_Cell_D*>(*cell_it);
                   assert( sc_cell != NULL && "SC_Util->get_PrePassVec");

                   if( sc_cell->get_Self() == NULL ){

                       SC_Cell::SC_TLIB tlib = sc_cell->get_TLib();

                           if( tlib == SC_Cell::SC_TLIB_AND  ){ get_AND_PrePassVec(sc_cell,sc_port,port_vec);  }
                      else if( tlib == SC_Cell::SC_TLIB_NAND ){ get_NAND_PrePassVec(sc_cell,sc_port,port_vec); }    
                      else if( tlib == SC_Cell::SC_TLIB_OR   ){ get_OR_PrePassVec(sc_cell,sc_port,port_vec);   }
                      else if( tlib == SC_Cell::SC_TLIB_NOR  ){ get_NOR_PrePassVec(sc_cell,sc_port,port_vec);  }
                      else if( tlib == SC_Cell::SC_TLIB_XOR  ){ get_XOR_PrePassVec(sc_cell,sc_port,port_vec);  }    
                      else if( tlib == SC_Cell::SC_TLIB_XNOR ){ get_XNOR_PrePassVec(sc_cell,sc_port,port_vec); }
                      else if( tlib == SC_Cell::SC_TLIB_BUF  ){ get_BUF_PrePassVec(sc_cell,sc_port,port_vec);  }    
                      else if( tlib == SC_Cell::SC_TLIB_INV  ){ get_INV_PrePassVec(sc_cell,sc_port,port_vec);  }

                   }
               }
           }
}





void       SC_Util::get_PreestPassVec(SC_Module::SC_Port_D *sc_port,SC_Module::PortVec *port_vec){

           assert( sc_port  != NULL && "SC_Util->get_PreestPassVec" );

           SC_Module::PortVec preest_p_vec;
           get_PreestVec(sc_port,&preest_p_vec);

           for(SC_Module::PortVec_iter p_it  = preest_p_vec.begin();
                                       p_it != preest_p_vec.end();   ++p_it){

                SC_Module::SC_Port_D *sc_p  = static_cast<SC_Module::SC_Port_D*>(*p_it);
                assert( sc_p != NULL && "SC_Util->get_PreestPassVec" );  

                if( sc_p->get_Pass() == true ){
                    SC_Module::PortVec pass_p_vec;
                    get_PrePassVec(sc_p,&pass_p_vec);

                    for(SC_Module::PortVec_iter p_it  = pass_p_vec.begin();
                                                p_it != pass_p_vec.end(); ++p_it){

                        SC_Module::SC_Port_D *sc_pass = static_cast<SC_Module::SC_Port_D*>(*p_it);
                        assert( sc_pass != NULL && "SC_Util->get_PreestPassVec" );  

                        get_PreestPassVec(sc_pass,port_vec);
                    }

                } else { port_vec->push_back(sc_p); }
          }
}





void       SC_Util::get_NxtPassVec(SC_Module::SC_Port_D *sc_port,
                                   SC_Module::PortVec *port_vec){

           assert( sc_port != NULL && "SC_Util->get_NxtPassVec" );

           if( sc_port->get_Pass() == true ){

               SC_Module *sc_module = sc_port->get_Parent();
               assert( sc_module != NULL && "SC_Util->get_NxtPassVec");

               SC_Module::CellVec cell_vec = sc_module->get_CellVec();

               for(SC_Module::CellVec_iter cell_it  = cell_vec.begin();
                                           cell_it != cell_vec.end();   ++cell_it){

                   SC_Module::SC_Cell_D *sc_cell = static_cast<SC_Module::SC_Cell_D*>(*cell_it);
                   assert( sc_cell != NULL && "SC_Util->get_NxtPassVec");

                   if( sc_cell->get_Self() == NULL ){

                       SC_Cell::SC_TLIB tlib = sc_cell->get_TLib();

                           if( tlib == SC_Cell::SC_TLIB_AND  ){ get_AND_NxtPassVec(sc_cell,sc_port,port_vec);  }
                      else if( tlib == SC_Cell::SC_TLIB_NAND ){ get_NAND_NxtPassVec(sc_cell,sc_port,port_vec); }    
                      else if( tlib == SC_Cell::SC_TLIB_OR   ){ get_OR_NxtPassVec(sc_cell,sc_port,port_vec);   }
                      else if( tlib == SC_Cell::SC_TLIB_NOR  ){ get_NOR_NxtPassVec(sc_cell,sc_port,port_vec);  }
                      else if( tlib == SC_Cell::SC_TLIB_XOR  ){ get_XOR_NxtPassVec(sc_cell,sc_port,port_vec);  }    
                      else if( tlib == SC_Cell::SC_TLIB_XNOR ){ get_XNOR_NxtPassVec(sc_cell,sc_port,port_vec); }
                      else if( tlib == SC_Cell::SC_TLIB_BUF  ){ get_BUF_NxtPassVec(sc_cell,sc_port,port_vec);  }    
                      else if( tlib == SC_Cell::SC_TLIB_INV  ){ get_INV_NxtPassVec(sc_cell,sc_port,port_vec);  }

                   }
               }
           }
}




void       SC_Util::get_NxtestPassVec(SC_Module::SC_Port_D *sc_port,SC_Module::PortVec *port_vec){

           assert( sc_port  != NULL && "SC_Util->get_NxtestPassVec" );

           SC_Module::PortVec nxtest_p_vec;
           get_NxtestVec(sc_port,&nxtest_p_vec);

           for(SC_Module::PortVec_iter p_it  = nxtest_p_vec.begin();
                                       p_it != nxtest_p_vec.end();   ++p_it){

               SC_Module::SC_Port_D *sc_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
               assert( sc_p != NULL && "SC_Util->get_NxtestPassVec" );  

              if( sc_p->get_Pass() == true ){
          
                  SC_Module::PortVec pass_p_vec;
                  get_NxtPassVec(sc_p,&pass_p_vec);

                  for(SC_Module::PortVec_iter p_it  = pass_p_vec.begin();
                                              p_it != pass_p_vec.end(); ++p_it){

                      SC_Module::SC_Port_D *sc_pass = static_cast<SC_Module::SC_Port_D*>(*p_it);
                      assert( sc_pass != NULL && "SC_Util->get_NxtestPassVec" );  

                      get_NxtestPassVec(sc_pass,port_vec);
  
                  }
               } else { port_vec->push_back(sc_p); }

           }
}




void       SC_Util::get_PreOutputVec(SC_Module::SC_Port_D *sc_port, SC_Module::PortVec *port_vec){

           assert( sc_port != NULL && "SC_Util->get_PreOutputtVec" );

           SC_Module::PortVec pre_p_vec = sc_port->get_PrePortVec();

           for(SC_Module::PortVec_iter p_it  = pre_p_vec.begin();
                                       p_it != pre_p_vec.end();   ++p_it){

            SC_Module::SC_Port_D *sc_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
            
            assert( sc_p != NULL && "SC_Util->get_PreOutputVec" );  
            SC_Module *sc_mm = sc_p->get_Parent();

            assert( sc_mm != NULL && "SC_Util->get_PreOutputVec" );    

            if( sc_mm->is_OutputPortVec_Contain(sc_p) )
                port_vec->push_back(sc_p);
            else
                get_NxtInputVec(sc_p,port_vec);

          }
}




void       SC_Util::get_PreInputVec(SC_Module::SC_Port_D *sc_port, SC_Module::PortVec *port_vec){

           assert( sc_port != NULL && "SC_Util->get_PreInputtVec" );

           SC_Module::PortVec pre_p_vec = sc_port->get_PrePortVec();

           for(SC_Module::PortVec_iter p_it  = pre_p_vec.begin();
                                       p_it != pre_p_vec.end();   ++p_it){

               SC_Module::SC_Port_D *sc_p = static_cast<SC_Module::SC_Port_D*>(*p_it);
            
               assert( sc_p != NULL && "SC_Util->get_PreInputVec" );  
               SC_Module *sc_mm = sc_p->get_Parent();

               assert( sc_mm != NULL && "SC_Util->get_PreInputVec" );    

               if( sc_mm->is_InputPortVec_Contain(sc_p) )
                   port_vec->push_back(sc_p);
               else
                   get_PreInputVec(sc_p,port_vec);

          }
}





bool     SC_Util::is_Nxtest_Connect(SC_Module::SC_Port_D *sc_p_1, SC_Module::SC_Port_D *sc_p_2){

         assert( sc_p_1 != NULL &&
                 sc_p_2 != NULL && "SC_Util->is_Nxtest_Connrect_Port" );

         if( sc_p_1 == sc_p_2 )
         return true;

         SC_Module::PortVec nxt_vec = sc_p_1->get_NxtPortVec();

         for(SC_Module::PortVec_iter p_it  = nxt_vec.begin();
                                     p_it != nxt_vec.end();   ++p_it){

             SC_Module::SC_Port_D *sc_p = static_cast<SC_Module::SC_Port_D*>(*p_it);

             is_Nxtest_Connect(sc_p,sc_p_2);    
         }
 
return false;
}





bool    SC_Util::is_Preest_Connect(SC_Module::SC_Port_D *sc_p_1, SC_Module::SC_Port_D *sc_p_2){

         assert( sc_p_1 != NULL &&
                 sc_p_2 != NULL && "SC_Util->is_Preest_Connrect_Port" );

         if( sc_p_1 == sc_p_2 )
         return true;

         SC_Module::PortVec pre_vec = sc_p_1->get_PrePortVec();

         for(SC_Module::PortVec_iter p_it  = pre_vec.begin();
                                     p_it != pre_vec.end();   ++p_it){
 
             SC_Module::SC_Port_D *sc_p = static_cast<SC_Module::SC_Port_D*>(*p_it);

             is_Preest_Connect(sc_p,sc_p_2);    
         }
}





void    SC_Util::get_NxtestVec(SC_Module *sc_module, ModuleVec *module_vec){

        assert( sc_module != NULL && "SC_Util->get_NxtestVec" );

        SC_Module::CellVec cell_vec = sc_module->get_CellVec();

        for(SC_Module::CellVec_iter cell_it  = cell_vec.begin(); 
                                    cell_it != cell_vec.end();   ++cell_it){

            SC_Module::SC_Cell_D *sc_cell = static_cast<SC_Module::SC_Cell_D*>(*cell_it);

            SC_Module *sc_mm = sc_cell->get_Self();

            if( sc_mm != NULL )
                get_NxtestVec(sc_mm,module_vec);
            else
                module_vec->push_back(sc_module);

        }
}




//void    SC_Util::get_NxtestVec

bool    SC_Util::is_Nxtest_Connect(SC_Module *sc_m_1, SC_Module *sc_m_2){

        assert( sc_m_1 != NULL &&
                sc_m_2 != NULL && "SC_Util->is_Nxtest_Connect" );

        if( sc_m_1 == sc_m_2 )
        return true;

        SC_Module::CellVec cell_vec = sc_m_1->get_CellVec();

        for(SC_Module::CellVec_iter cell_it  = cell_vec.begin(); 
                                    cell_it != cell_vec.end();   ++cell_it){

            SC_Module::SC_Cell_D *sc_cell = static_cast<SC_Module::SC_Cell_D*>(*cell_it);

            SC_Module *sc_mm = sc_cell->get_Self();

            if( sc_mm != NULL )
                is_Nxtest_Connect(sc_m_1,sc_m_2);

        }

return false;
}





bool    SC_Util::is_Preest_Connect(SC_Module *sc_m_1, SC_Module *sc_m_2){
      
        assert( sc_m_1 != NULL &&
                sc_m_2 != NULL && "SC_Util->is_Preest_Connect" );

        if( sc_m_1 == sc_m_2 )
        return true;

        SC_Module *sc_parent = sc_m_1->get_Parent();

        is_Preest_Connect(sc_parent,sc_m_2);
}





SC_Module::SC_Port_D   *SC_Util::split_path_2_Port(SC_Module *sc_module, std::string path){
 
                        assert( !path.empty()      && 
                                 sc_module != NULL && "SC_Util->split_path_2_Port" );
                
                                std::vector<std::string>           str_vec;
                        typedef std::vector<std::string>::iterator str_vec_iter;
                
                        boost::split(str_vec, path, boost::is_any_of("/"));
                        assert( !str_vec.empty() && "SC_Util->split_path_2_Port");

                        bool              pass = false;
                        SC_Module *t_sc_module = sc_module;


                        for(str_vec_iter str_it  = str_vec.begin(); 
                                         str_it != str_vec.end();   ++str_it){

                            SC_Module::CellVec cell_vec = t_sc_module->get_CellVec();
                                               pass     = false;

                            // @ SC_Cell
                            if( str_it < str_vec.end()-1 ){
                            for(SC_Module::CellVec_iter  cell_it  = cell_vec.begin();
                                                         cell_it != cell_vec.end();   ++cell_it){

                                SC_Module::SC_Cell_D *sc_cell = static_cast<SC_Module::SC_Cell_D*>(*cell_it);
                                assert( sc_cell != NULL && "SC_Util->split_path_2_Port");

                                std::string cell_nm = sc_cell->get_CellName();
                                if( cell_nm.compare((*str_it)) == 0 ){
                                    t_sc_module = sc_cell->get_Self();  
                                    pass = true;
                                 }
                              }
                              assert( pass != false && "SC_Util->split_path_2_Port");
 
                             // @ tail case SC_Port
                             } else {  return t_sc_module->get_Signal((*str_it)); }
                             
                          }
}





bool          SC_Util::is_Deepest_Module(SC_Module::SC_Cell_D *sc_cell){
 
              assert( sc_cell != NULL && "SC_Util->is_Deepest_Module");

              SC_Module *sc_module = sc_cell->get_Parent();
              assert( sc_module != NULL && "SC_Util->is_Deepest_Module");

              SC_Module::CellVec cell_vec = sc_module->get_CellVec();

              if(  sc_cell->get_Pass() == false &&
                   sc_cell->get_Self() == NULL  &&
                   cell_vec.size()     == 1     )
                   return true;

return false;
}




std::string   SC_Util::get_HierarchyName(SC_Module::SC_Port_D *sc_port){

              std::string nm;

              assert( sc_port != NULL && "SC_Util->get_HierarchyName");

              SC_Module *sc_module = sc_port->get_Parent();
              assert( sc_module != NULL && "SC_Util->get_HierarchyName");

              nm = sc_module->get_UniqueName() + "/" + sc_port->get_Name(); 
                           
              while(true){
                    SC_Module *sc_m = sc_module->get_Parent();
 
                    if(sc_m == NULL)
                    break;

                   std::string un_nm = sc_m->get_UniqueName();
//                   assert( !un_nm.empty() && "SC_Util->get_HierarchyName");

                   nm =  un_nm + "/" + nm;
                   sc_module = sc_m;
             }

return nm;
}





std::string   SC_Util::get_HierarchyName(SC_Module *sc_module){

              std::string nm;

              assert( sc_module != NULL && "SC_Util->get_HierarchyName");

              nm = sc_module->get_UniqueName(); 
                           
              while(true){
                    SC_Module *sc_m = sc_module->get_Parent();
 
                    if(sc_m == NULL)
                    break;

                    std::string un_nm = sc_m->get_UniqueName();
//                    assert( !un_nm.empty() && "SC_Util->get_HierarchyName");

                    nm = un_nm + "/" + nm;
                    sc_module = sc_m;
             }

return nm;
}





std::string   SC_Util::get_HierarchyName(SC_Module::SC_Cell_D *sc_cell){

              std::string nm;

              assert( sc_cell != NULL && "SC_Util->get_HierarchyName");

              SC_Module *sc_module = sc_cell->get_Parent();
              assert( sc_module != NULL && "SC_Util->get_HierarchyName");          

              nm = sc_module->get_UniqueName() + "/" + sc_cell->get_CellName(); 

              while(true){
                    SC_Module *sc_m = sc_module->get_Parent();
 
                    if(sc_m == NULL)
                    break;

                    std::string un_nm = sc_m->get_UniqueName();
//                    assert( !un_nm.empty() && "SC_Util->get_HierarchyName");

                    nm = un_nm + "/" + nm;
                    sc_module = sc_m;
             }

return nm;
}





