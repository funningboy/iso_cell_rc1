
#include "kernel/ISO_Pass/ISO_Domain_Pass.h"

void    ISO_Domain_Pass::run_Domain_Verify(SC_Table *sc_table, ISO_Table *iso_table){

        assert( sc_table  != NULL &&
                iso_table != NULL && "ISO_Domain_Pass->run_Domain_Verify");


        SC_Module *sc_root = sc_table->get_RootModule();
        assert( sc_root != NULL && "ISO_Domain_Pass->run_Domain_Verify");

        // @ top module domain
        SC_Module::PortVec input_vec  = sc_root->get_InputPortVec();
        SC_Module::PortVec output_vec = sc_root->get_OutputPortVec();
        SC_Module::PortVec wire_vec   = sc_root->get_WirePortVec();
        SC_Module::CellVec cell_vec   = sc_root->get_CellVec();


        for(SC_Module::PortVec_iter p_it  = input_vec.begin();
                                    p_it != input_vec.end();  ++p_it){

            SC_Module::SC_Port_D *sc_port = static_cast<SC_Module::SC_Port_D*>(*p_it);
            assert( sc_port != NULL && "ISO_Domain_Pass->run_Domain_Verify");

            std::string port_nm = sc_port->get_Name();
            std::string domain  = iso_util->get_ISO_BoundaryPort_Domain(iso_table,port_nm);
            
            SC_Module::SC_Domain_D *sc_domain = dynamic_cast<SC_Module::SC_Domain_D*>(sc_port);
                                    sc_domain->set_Name(domain);
        }



        for(SC_Module::PortVec_iter p_it  = output_vec.begin();
                                    p_it != output_vec.end();  ++p_it){

            SC_Module::SC_Port_D *sc_port = static_cast<SC_Module::SC_Port_D*>(*p_it);
            assert( sc_port != NULL && "ISO_Domain_Pass->run_Domain_Verify");

            std::string port_nm = sc_port->get_Name();
            std::string domain  = iso_util->get_ISO_BoundaryPort_Domain(iso_table,port_nm);
            
            SC_Module::SC_Domain_D *sc_domain = dynamic_cast<SC_Module::SC_Domain_D*>(sc_port);
                                    sc_domain->set_Name(domain);
        }



        for(SC_Module::CellVec_iter cell_it  = cell_vec.begin();
                                    cell_it != cell_vec.end();  ++cell_it){

            SC_Module::SC_Cell_D *sc_cell = static_cast<SC_Module::SC_Cell_D*>(*cell_it);
            assert( sc_cell != NULL && "ISO_Domain_Pass->run_Domain_Verify");

            SC_Module *sc_self = sc_cell->get_Self();
            std::string domain = iso_util->get_ISO_Instance_Domain(iso_table,sc_cell->get_CellName());

            if( sc_self == NULL )
               run_Domain_Deepest(sc_cell,domain);
            else 
               run_Domain_Trace(iso_table,sc_self);
       }

TraceVec.clear();
}





void    ISO_Domain_Pass::run_Domain_AND(SC_Module::SC_Cell_D *sc_cell,std::string iso_nm){

        assert(  sc_cell != NULL &&
                !iso_nm.empty()  && "ISO_Domain_Pass->run_Domain_AND");
 
        SC_LIB::SC_AND  *sc_and = dynamic_cast<SC_LIB::SC_AND*>(sc_cell);
 
        SC_Module::SC_Port_D *sc_src1 = sc_and->get_Src1(); 
        SC_Module::SC_Port_D *sc_src2 = sc_and->get_Src2();
        SC_Module::SC_Port_D *sc_dst  = sc_and->get_Dst();

        assert( sc_src1 != NULL &&
                sc_src2 != NULL &&
                sc_dst  != NULL && "ISO_Domain_Pass->run_Domain_AND");

       SC_Module::SC_Domain_D *sc_cell_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_cell); 
       SC_Module::SC_Domain_D *sc_src1_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_src1);
       SC_Module::SC_Domain_D *sc_src2_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_src2);
       SC_Module::SC_Domain_D *sc_dst_d  = dynamic_cast<SC_Module::SC_Domain_D*>(sc_dst);
 
       sc_cell_d->set_Name(iso_nm);
       sc_src1_d->set_Name(iso_nm);
       sc_src2_d->set_Name(iso_nm);
       sc_dst_d->set_Name(iso_nm);
}





void    ISO_Domain_Pass::run_Domain_NAND(SC_Module::SC_Cell_D *sc_cell,std::string iso_nm){

        assert(  sc_cell != NULL &&
                !iso_nm.empty()  && "ISO_Domain_Pass->run_Domain_NAND");
 
        SC_LIB::SC_NAND  *sc_nand = dynamic_cast<SC_LIB::SC_NAND*>(sc_cell);
 
        SC_Module::SC_Port_D *sc_src1 = sc_nand->get_Src1(); 
        SC_Module::SC_Port_D *sc_src2 = sc_nand->get_Src2();
        SC_Module::SC_Port_D *sc_dst  = sc_nand->get_Dst();

        assert( sc_src1 != NULL &&
                sc_src2 != NULL &&
                sc_dst  != NULL && "ISO_Domain_Pass->run_Domain_AND");

       SC_Module::SC_Domain_D *sc_cell_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_cell); 
       SC_Module::SC_Domain_D *sc_src1_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_src1);
       SC_Module::SC_Domain_D *sc_src2_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_src2);
       SC_Module::SC_Domain_D *sc_dst_d  = dynamic_cast<SC_Module::SC_Domain_D*>(sc_dst);
 
       sc_cell_d->set_Name(iso_nm);
       sc_src1_d->set_Name(iso_nm);
       sc_src2_d->set_Name(iso_nm);
       sc_dst_d->set_Name(iso_nm);
}





void    ISO_Domain_Pass::run_Domain_OR(SC_Module::SC_Cell_D *sc_cell,std::string iso_nm){

        assert(  sc_cell != NULL && 
                !iso_nm.empty()  && "ISO_Domain_Pass->run_Domain_OR");
 
        SC_LIB::SC_OR  *sc_or = dynamic_cast<SC_LIB::SC_OR*>(sc_cell);
 
        SC_Module::SC_Port_D *sc_src1 = sc_or->get_Src1(); 
        SC_Module::SC_Port_D *sc_src2 = sc_or->get_Src2();
        SC_Module::SC_Port_D *sc_dst  = sc_or->get_Dst();

        assert( sc_src1 != NULL &&
                sc_src2 != NULL &&
                sc_dst  != NULL && "ISO_Domain_Pass->run_Domain_OR");

       SC_Module::SC_Domain_D *sc_cell_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_cell); 
       SC_Module::SC_Domain_D *sc_src1_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_src1);
       SC_Module::SC_Domain_D *sc_src2_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_src2);
       SC_Module::SC_Domain_D *sc_dst_d  = dynamic_cast<SC_Module::SC_Domain_D*>(sc_dst);
 
       sc_cell_d->set_Name(iso_nm);
       sc_src1_d->set_Name(iso_nm);
       sc_src2_d->set_Name(iso_nm);
       sc_dst_d->set_Name(iso_nm);
}





void    ISO_Domain_Pass::run_Domain_NOR(SC_Module::SC_Cell_D *sc_cell,std::string iso_nm){

        assert(  sc_cell != NULL &&
                !iso_nm.empty()  && "ISO_Domain_Pass->run_Domain_NOR");
 
        SC_LIB::SC_NOR  *sc_nor = dynamic_cast<SC_LIB::SC_NOR*>(sc_cell);
 
        SC_Module::SC_Port_D *sc_src1 = sc_nor->get_Src1(); 
        SC_Module::SC_Port_D *sc_src2 = sc_nor->get_Src2();
        SC_Module::SC_Port_D *sc_dst  = sc_nor->get_Dst();

        assert( sc_src1 != NULL &&
                sc_src2 != NULL &&
                sc_dst  != NULL && "ISO_Domain_Pass->run_Domain_NOR");

       SC_Module::SC_Domain_D *sc_cell_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_cell); 
       SC_Module::SC_Domain_D *sc_src1_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_src1);
       SC_Module::SC_Domain_D *sc_src2_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_src2);
       SC_Module::SC_Domain_D *sc_dst_d  = dynamic_cast<SC_Module::SC_Domain_D*>(sc_dst);
 
       sc_cell_d->set_Name(iso_nm);
       sc_src1_d->set_Name(iso_nm);
       sc_src2_d->set_Name(iso_nm);
       sc_dst_d->set_Name(iso_nm);
}




void    ISO_Domain_Pass::run_Domain_XOR(SC_Module::SC_Cell_D *sc_cell,std::string iso_nm){

        assert(  sc_cell != NULL &&
                !iso_nm.empty()  &&  "ISO_Domain_Pass->run_Domain_XOR");
 
        SC_LIB::SC_XOR  *sc_xor = dynamic_cast<SC_LIB::SC_XOR*>(sc_cell);
 
        SC_Module::SC_Port_D *sc_src1 = sc_xor->get_Src1(); 
        SC_Module::SC_Port_D *sc_src2 = sc_xor->get_Src2();
        SC_Module::SC_Port_D *sc_dst  = sc_xor->get_Dst();

        assert( sc_src1 != NULL &&
                sc_src2 != NULL &&
                sc_dst  != NULL && "ISO_Domain_Pass->run_Domain_XOR");

       SC_Module::SC_Domain_D  *sc_cell_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_cell); 
       SC_Module::SC_Domain_D  *sc_src1_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_src1);
       SC_Module::SC_Domain_D  *sc_src2_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_src2);
       SC_Module::SC_Domain_D  *sc_dst_d  = dynamic_cast<SC_Module::SC_Domain_D*>(sc_dst);
 
       sc_cell_d->set_Name(iso_nm);
       sc_src1_d->set_Name(iso_nm);
       sc_src2_d->set_Name(iso_nm);
       sc_dst_d->set_Name(iso_nm);
}




void    ISO_Domain_Pass::run_Domain_XNOR(SC_Module::SC_Cell_D *sc_cell,std::string iso_nm){

        assert( sc_cell != NULL && "ISO_Domain_Pass->run_Domain_XNOR");
 
        SC_LIB::SC_XNOR  *sc_xnor = dynamic_cast<SC_LIB::SC_XNOR*>(sc_cell);
 
        SC_Module::SC_Port_D *sc_src1 = sc_xnor->get_Src1(); 
        SC_Module::SC_Port_D *sc_src2 = sc_xnor->get_Src2();
        SC_Module::SC_Port_D *sc_dst  = sc_xnor->get_Dst();

        assert( sc_src1 != NULL &&
                sc_src2 != NULL &&
                sc_dst  != NULL && "ISO_Domain_Pass->run_Domain_XNOR");

       SC_Module::SC_Domain_D *sc_cell_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_cell); 
       SC_Module::SC_Domain_D *sc_src1_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_src1);
       SC_Module::SC_Domain_D *sc_src2_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_src2);
       SC_Module::SC_Domain_D *sc_dst_d  = dynamic_cast<SC_Module::SC_Domain_D*>(sc_dst);
 
       sc_cell_d->set_Name(iso_nm);
       sc_src1_d->set_Name(iso_nm);
       sc_src2_d->set_Name(iso_nm);
       sc_dst_d->set_Name(iso_nm);
}





void    ISO_Domain_Pass::run_Domain_BUF(SC_Module::SC_Cell_D *sc_cell,std::string iso_nm){

        assert( sc_cell != NULL && "ISO_Domain_Pass->run_Domain_BUF");
 
        SC_LIB::SC_BUF  *sc_buf = dynamic_cast<SC_LIB::SC_BUF*>(sc_cell);
 
        SC_Module::SC_Port_D *sc_src = sc_buf->get_Src(); 
        SC_Module::SC_Port_D *sc_dst = sc_buf->get_Dst();

        assert( sc_src != NULL &&
                sc_dst != NULL && "ISO_Domain_Pass->run_Domain_BUF");

       SC_Module::SC_Domain_D *sc_cell_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_cell); 
       SC_Module::SC_Domain_D *sc_src_d  = dynamic_cast<SC_Module::SC_Domain_D*>(sc_src);
       SC_Module::SC_Domain_D *sc_dst_d  = dynamic_cast<SC_Module::SC_Domain_D*>(sc_dst);
 
       sc_cell_d->set_Name(iso_nm);
       sc_src_d->set_Name(iso_nm);
       sc_dst_d->set_Name(iso_nm);
}





void    ISO_Domain_Pass::run_Domain_INV(SC_Module::SC_Cell_D *sc_cell,std::string iso_nm){

        assert( sc_cell != NULL && "ISO_Domain_Pass->run_Domain_INV");
 
        SC_LIB::SC_INV  *sc_inv = dynamic_cast<SC_LIB::SC_INV*>(sc_cell);
 
        SC_Module::SC_Port_D *sc_src = sc_inv->get_Src(); 
        SC_Module::SC_Port_D *sc_dst = sc_inv->get_Dst();

        assert( sc_src != NULL &&
                sc_dst != NULL && "ISO_Domain_Pass->run_Domain_INV");

       SC_Module::SC_Domain_D *sc_cell_d = dynamic_cast<SC_Module::SC_Domain_D*>(sc_cell); 
       SC_Module::SC_Domain_D *sc_src_d  = dynamic_cast<SC_Module::SC_Domain_D*>(sc_src);
       SC_Module::SC_Domain_D *sc_dst_d  = dynamic_cast<SC_Module::SC_Domain_D*>(sc_dst);
 
       sc_cell_d->set_Name(iso_nm);
       sc_src_d->set_Name(iso_nm);
       sc_dst_d->set_Name(iso_nm);
}




void    ISO_Domain_Pass::run_Domain_Deepest(SC_Module::SC_Cell_D *sc_cell,std::string iso_nm){

        assert( sc_cell != NULL && 
                !iso_nm.empty() && "ISO_Domain_Pass->run_Domain_Deepest");

         SC_Cell::SC_TLIB   tlib = sc_cell->get_TLib();

         if( tlib == SC_Cell::SC_TLIB_AND  ){ run_Domain_AND(sc_cell,iso_nm);  }
    else if( tlib == SC_Cell::SC_TLIB_NAND ){ run_Domain_NAND(sc_cell,iso_nm); } 
    else if( tlib == SC_Cell::SC_TLIB_OR   ){ run_Domain_OR(sc_cell,iso_nm);   }
    else if( tlib == SC_Cell::SC_TLIB_NOR  ){ run_Domain_NOR(sc_cell,iso_nm);  }
    else if( tlib == SC_Cell::SC_TLIB_XOR  ){ run_Domain_XOR(sc_cell,iso_nm);  }
    else if( tlib == SC_Cell::SC_TLIB_XNOR ){ run_Domain_XNOR(sc_cell,iso_nm); }
    else if( tlib == SC_Cell::SC_TLIB_BUF  ){ run_Domain_BUF(sc_cell,iso_nm);  }
    else if( tlib == SC_Cell::SC_TLIB_INV  ){ run_Domain_INV(sc_cell,iso_nm);  }

}





void    ISO_Domain_Pass::run_Domain_Trace(ISO_Table *iso_table,SC_Module *sc_module){

        assert( iso_table != NULL &&
                sc_module != NULL && "ISO_Domain_Pass->run_Domain_Trace");

        SC_Module::PortVec input_vec  = sc_module->get_InputPortVec();
        SC_Module::PortVec output_vec = sc_module->get_OutputPortVec();
        SC_Module::PortVec wire_vec   = sc_module->get_WirePortVec();
        SC_Module::CellVec cell_vec   = sc_module->get_CellVec();

        std::string cell_nm = sc_module->get_UniqueName();
        TraceVec.push_back(cell_nm);

        std::string hier_nm = iso_util->get_HierarchyName(TraceVec);
        std::string domain  = iso_util->get_ISO_Instance_Domain(iso_table,hier_nm);

 
        for(SC_Module::PortVec_iter p_it  = input_vec.begin();
                                    p_it != input_vec.end();  ++p_it){

            SC_Module::SC_Port_D *sc_port = static_cast<SC_Module::SC_Port_D*>(*p_it);
            assert( sc_port != NULL && "ISO_Domain_Pass->run_Domain_Trace");
            
            SC_Module::SC_Domain_D *sc_domain = dynamic_cast<SC_Module::SC_Domain_D*>(sc_port);
                                    sc_domain->set_Name(domain);
        }



        for(SC_Module::PortVec_iter p_it  = output_vec.begin();
                                    p_it != output_vec.end();  ++p_it){

            SC_Module::SC_Port_D *sc_port = static_cast<SC_Module::SC_Port_D*>(*p_it);
            assert( sc_port != NULL && "ISO_Domain_Pass->run_Domain_Trace");

            SC_Module::SC_Domain_D *sc_domain = dynamic_cast<SC_Module::SC_Domain_D*>(sc_port);
                                    sc_domain->set_Name(domain);
        }


        for(SC_Module::CellVec_iter cell_it  = cell_vec.begin();
                                    cell_it != cell_vec.end();  ++cell_it){  

            SC_Module::SC_Cell_D *sc_cell = static_cast<SC_Module::SC_Cell_D*>(*cell_it);
            assert( sc_cell != NULL && "ISO_Domain_Pass->run_Domain_Trace");

            SC_Module *sc_module = sc_cell->get_Self();

            // @ deepest SC_Logic
            if( sc_module == NULL ){
                domain  = iso_util->get_ISO_Instance_Domain(iso_table,hier_nm + "/" + sc_cell->get_CellName());
                run_Domain_Deepest(sc_cell,domain);
            } else {
                run_Domain_Trace(iso_table,sc_module);
            }

       }   

      TraceVec.pop_back();   
}
