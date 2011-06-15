
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

#include "kernel/SC_Context/SC_Table.h"




void SC_Table::dump_Template_Context(){

ModuleMap_D tmp_mm = get_ModuleMap();

 for(ModuleMap_iter mm_it  = tmp_mm.begin();
                    mm_it != tmp_mm.end();   ++mm_it){

    SC_Module *sc_module = static_cast<SC_Module*>(mm_it->second);

    assert( sc_module != NULL && "dump_Template_Context");

    sc_module->dump_Context();

  }
}




void SC_Table::dump_O2N_Port_Context(){

O2N_Port_D o2n_port = get_O2N_Port();

for(O2N_Port_iter o2n_it  = o2n_port.begin(); 
                  o2n_it != o2n_port.end();   ++o2n_it){

    SC_Module::SC_Port_D *port_o = static_cast<SC_Module::SC_Port_D*>(o2n_it->first);
    SC_Module::SC_Port_D *port_n = static_cast<SC_Module::SC_Port_D*>(o2n_it->second);

    std::cout << port_o << " :: " << port_n << std::endl;
  }

}



void SC_Table::dump_Root_Context(SC_Module *sc_module){

     if( sc_module == NULL )
     return;

     sc_module->dump_Context();

  SC_Module::CellVec  sc_cell_vec = sc_module->get_CellVec();

  for(SC_Module::CellVec_iter cell_it  = sc_cell_vec.begin(); 
                              cell_it != sc_cell_vec.end();   ++cell_it){

      SC_Module::SC_Cell_D *sc_cell = static_cast<SC_Module::SC_Cell_D*>(*cell_it);

      SC_Module *sc_self = sc_cell->get_Self();
  
      if(sc_self == NULL){
         SC_LIB::SC_AND  *sc_and   = dynamic_cast<SC_LIB::SC_AND*> (sc_cell);
         SC_LIB::SC_NAND *sc_nand  = dynamic_cast<SC_LIB::SC_NAND*>(sc_cell);
         SC_LIB::SC_OR   *sc_or    = dynamic_cast<SC_LIB::SC_OR*>  (sc_cell);
         SC_LIB::SC_NOR  *sc_nor   = dynamic_cast<SC_LIB::SC_NOR*> (sc_cell);
         SC_LIB::SC_XOR  *sc_xor   = dynamic_cast<SC_LIB::SC_XOR*> (sc_cell);
         SC_LIB::SC_XNOR *sc_xnor  = dynamic_cast<SC_LIB::SC_XNOR*>(sc_cell);
         SC_LIB::SC_BUF  *sc_buf   = dynamic_cast<SC_LIB::SC_BUF*> (sc_cell);
         SC_LIB::SC_INV  *sc_inv   = dynamic_cast<SC_LIB::SC_INV*> (sc_cell);
         // DFF??

         SC_Cell::SC_TLIB tlib = sc_cell->get_TLib(); 
        
             if( tlib == SC_Cell::SC_TLIB_AND  ){ sc_and->dump_Context();  }
        else if( tlib == SC_Cell::SC_TLIB_NAND ){ sc_nand->dump_Context(); }
        else if( tlib == SC_Cell::SC_TLIB_OR   ){ sc_or->dump_Context();   }
        else if( tlib == SC_Cell::SC_TLIB_NOR  ){ sc_nor->dump_Context();  }
        else if( tlib == SC_Cell::SC_TLIB_XOR  ){ sc_xor->dump_Context();  }
        else if( tlib == SC_Cell::SC_TLIB_XNOR ){ sc_xnor->dump_Context(); }
        else if( tlib == SC_Cell::SC_TLIB_BUF  ){ sc_buf->dump_Context();  }
        else if( tlib == SC_Cell::SC_TLIB_INV  ){ sc_inv->dump_Context();  }
      }

      dump_Root_Context(sc_self);
  }

}





void SC_Table::copy_Port_2_New(SC_Module::SC_Port_D *sc_port_o,
                               SC_Module::SC_Port_D *sc_port_n){

     assert( sc_port_o != NULL &&
             sc_port_n != NULL && "SC_Table->copy_SC_Port_2_New" );

             sc_port_n->set_Name(       sc_port_o->get_Name()        );
             sc_port_n->set_Parent(     sc_port_o->get_Parent()      );

             SC_Module::SC_Time_D *sc_time_o = dynamic_cast<SC_Module::SC_Time_D*>(sc_port_o);
             SC_Module::SC_Time_D *sc_time_n = dynamic_cast<SC_Module::SC_Time_D*>(sc_port_n);
                                   sc_time_n->set_ArriveTime( sc_time_o->get_ArriveTime() );

             SC_Module::SC_Power_D *sc_power_o = dynamic_cast<SC_Module::SC_Power_D*>(sc_port_o);
             SC_Module::SC_Power_D *sc_power_n = dynamic_cast<SC_Module::SC_Power_D*>(sc_port_n);
                                    sc_power_n->set_SwitchPower( sc_power_o->get_SwitchPower() );

             SC_Module::SC_Logic_D *sc_logic_o = dynamic_cast<SC_Module::SC_Logic_D*>(sc_port_o);
             SC_Module::SC_Logic_D *sc_logic_n = dynamic_cast<SC_Module::SC_Logic_D*>(sc_port_n);
                                    sc_logic_n->set_PreLogic( sc_logic_o->get_PreLogic() );
                                    sc_logic_n->set_CurLogic( sc_logic_o->get_CurLogic() );
                        
             SC_Module::SC_Type_D *sc_type_o = dynamic_cast<SC_Module::SC_Type_D*>(sc_port_o);
             SC_Module::SC_Type_D *sc_type_n = dynamic_cast<SC_Module::SC_Type_D*>(sc_port_n);
                                   sc_type_n->set_Type( sc_type_o->get_Type() );

             SC_Module::SC_Pass_D *sc_pass_o = dynamic_cast<SC_Module::SC_Pass_D*>(sc_port_o); 
             SC_Module::SC_Pass_D *sc_pass_n = dynamic_cast<SC_Module::SC_Pass_D*>(sc_port_n);
                                   sc_pass_n->set_Pass( sc_pass_o->get_Pass() );
}





void SC_Table::copy_Cell_2_New(SC_Module::SC_Cell_D *sc_cell_o,
                               SC_Module::SC_Cell_D *sc_cell_n){

     assert( sc_cell_o != NULL &&
             sc_cell_n != NULL && "SC_Table->copy_SC_Cell_2_New" );

                           sc_cell_n->set_Parent(      sc_cell_o->get_Parent()     );
                           sc_cell_n->set_Self(        sc_cell_o->get_Self()       );
                           sc_cell_n->set_ModuleName(  sc_cell_o->get_ModuleName() );
                           sc_cell_n->set_CellName(    sc_cell_o->get_CellName()   );
                           sc_cell_n->set_TLib(        sc_cell_o->get_TLib()       );

             SC_Module::SC_Pass_D *sc_cell_p_o = dynamic_cast<SC_Module::SC_Pass_D*>(sc_cell_o); 
             SC_Module::SC_Pass_D *sc_cell_p_n = dynamic_cast<SC_Module::SC_Pass_D*>(sc_cell_n);
                                   sc_cell_p_n->set_Pass( sc_cell_p_o->get_Pass() );

            SC_Module::PortVec sc_cell_p_vec = sc_cell_o->get_PortVec();

            assert( !sc_cell_p_vec.empty() && "SC_Table->copy_SC_Cell_2_New");

           for(SC_Module::PortVec_iter cell_p_it  = sc_cell_p_vec.begin(); 
                                       cell_p_it != sc_cell_p_vec.end();   ++cell_p_it){

                           SC_Module::SC_Port_D *cell_p_o = static_cast<SC_Module::SC_Port_D*>(*cell_p_it);
                           SC_Module::SC_Port_D *cell_p_n = new SC_Module::SC_Port_D();

                           assert( cell_p_o != NULL &&
                                   cell_p_n != NULL && "SC_Table->copy_Cell_2_New");

                            copy_Port_2_New(cell_p_o,cell_p_n);
                           
                            sc_cell_n->set_PortVec(cell_p_n);

                            set_O2N_Port(cell_p_o,cell_p_n); 
           }
}
 




void SC_Table::copy_AND_Logic_2_New(SC_Module::SC_Cell_D *sc_cell_o,
                                    SC_Module::SC_Cell_D *sc_cell_n){

     assert( sc_cell_o != NULL &&
             sc_cell_n != NULL && "SC_Table->copy_AND_Logic_2_New");

     SC_LIB::SC_AND *and_o = dynamic_cast<SC_LIB::SC_AND*>(sc_cell_o);
     SC_LIB::SC_AND *and_n = dynamic_cast<SC_LIB::SC_AND*>(sc_cell_n);

     SC_Module::SC_Port_D *src1_n = get_O2N_Port(and_o->get_Src1());
     SC_Module::SC_Port_D *src2_n = get_O2N_Port(and_o->get_Src2());
     SC_Module::SC_Port_D *dst_n  = get_O2N_Port(and_o->get_Dst());

     and_n->set_Src1(src1_n);
     and_n->set_Src2(src2_n);
     and_n->set_Dst(dst_n);

     if( src1_n != NULL &&
         src2_n != NULL &&
         dst_n  != NULL ){

         SC_Module *parent = sc_cell_n->get_Parent();
         assert( parent != NULL && "SC_Table->copy_AND_Logic_2_New" );

         src1_n->set_Parent(parent);
         src2_n->set_Parent(parent);
         dst_n->set_Parent(parent);
    }
}





void SC_Table::copy_NAND_Logic_2_New(SC_Module::SC_Cell_D *sc_cell_o,
                                     SC_Module::SC_Cell_D *sc_cell_n){

     assert( sc_cell_o != NULL &&
             sc_cell_n != NULL && "SC_Table->copy_NAND_Logic_2_New");

     SC_LIB::SC_NAND *nand_o = dynamic_cast<SC_LIB::SC_NAND*>(sc_cell_o);
     SC_LIB::SC_NAND *nand_n = dynamic_cast<SC_LIB::SC_NAND*>(sc_cell_n);

     SC_Module::SC_Port_D *src1_n = get_O2N_Port(nand_o->get_Src1());
     SC_Module::SC_Port_D *src2_n = get_O2N_Port(nand_o->get_Src2());
     SC_Module::SC_Port_D *dst_n  = get_O2N_Port(nand_o->get_Dst());

     nand_n->set_Src1(src1_n);
     nand_n->set_Src2(src2_n);
     nand_n->set_Dst(dst_n);

     if( src1_n != NULL &&
         src2_n != NULL &&
         dst_n  != NULL ){

         SC_Module *parent = sc_cell_n->get_Parent();
         assert( parent != NULL && "SC_Table->copy_NAND_Logic_2_New" );

         src1_n->set_Parent(parent);
         src2_n->set_Parent(parent);
         dst_n->set_Parent(parent);
    }
}





void SC_Table::copy_OR_Logic_2_New(SC_Module::SC_Cell_D *sc_cell_o,
                                   SC_Module::SC_Cell_D *sc_cell_n){

     assert( sc_cell_o != NULL &&
             sc_cell_n != NULL && "SC_Table->copy_OR_Logic_2_New");

     SC_LIB::SC_OR *or_o = dynamic_cast<SC_LIB::SC_OR*>(sc_cell_o);
     SC_LIB::SC_OR *or_n = dynamic_cast<SC_LIB::SC_OR*>(sc_cell_n);

     SC_Module::SC_Port_D *src1_n = get_O2N_Port(or_o->get_Src1());
     SC_Module::SC_Port_D *src2_n = get_O2N_Port(or_o->get_Src2());
     SC_Module::SC_Port_D *dst_n  = get_O2N_Port(or_o->get_Dst());

     or_n->set_Src1(src1_n);
     or_n->set_Src2(src2_n);
     or_n->set_Dst(dst_n);

     if( src1_n != NULL &&
         src2_n != NULL &&
         dst_n  != NULL ){

         SC_Module *parent = sc_cell_n->get_Parent();
         assert( parent != NULL && "SC_Table->copy_OR_Logic_2_New" );

         src1_n->set_Parent(parent);
         src2_n->set_Parent(parent);
         dst_n->set_Parent(parent);
    }
}





void SC_Table::copy_NOR_Logic_2_New(SC_Module::SC_Cell_D *sc_cell_o,
                                    SC_Module::SC_Cell_D *sc_cell_n){

     assert( sc_cell_o != NULL &&
             sc_cell_n != NULL && "SC_Table->copy_NOR_Logic_2_New");

     SC_LIB::SC_NOR *nor_o = dynamic_cast<SC_LIB::SC_NOR*>(sc_cell_o);
     SC_LIB::SC_NOR *nor_n = dynamic_cast<SC_LIB::SC_NOR*>(sc_cell_n);

     SC_Module::SC_Port_D *src1_n = get_O2N_Port(nor_o->get_Src1());
     SC_Module::SC_Port_D *src2_n = get_O2N_Port(nor_o->get_Src2());
     SC_Module::SC_Port_D *dst_n  = get_O2N_Port(nor_o->get_Dst());

     nor_n->set_Src1(src1_n);
     nor_n->set_Src2(src2_n);
     nor_n->set_Dst(dst_n);

     if( src1_n != NULL &&
         src2_n != NULL &&
         dst_n  != NULL ){

         SC_Module *parent = sc_cell_n->get_Parent();
         assert( parent != NULL && "SC_Table->copy_NOR_Logic_2_New" );

         src1_n->set_Parent(parent);
         src2_n->set_Parent(parent);
         dst_n->set_Parent(parent);
    }
}




void SC_Table::copy_XOR_Logic_2_New(SC_Module::SC_Cell_D *sc_cell_o,
                                    SC_Module::SC_Cell_D *sc_cell_n){

     assert( sc_cell_o != NULL &&
             sc_cell_n != NULL && "SC_Table->copy_XOR_Logic_2_New");

     SC_LIB::SC_XOR *xor_o = dynamic_cast<SC_LIB::SC_XOR*>(sc_cell_o);
     SC_LIB::SC_XOR *xor_n = dynamic_cast<SC_LIB::SC_XOR*>(sc_cell_n);

     SC_Module::SC_Port_D *src1_n = get_O2N_Port(xor_o->get_Src1());
     SC_Module::SC_Port_D *src2_n = get_O2N_Port(xor_o->get_Src2());
     SC_Module::SC_Port_D *dst_n  = get_O2N_Port(xor_o->get_Dst());

     xor_n->set_Src1(src1_n);
     xor_n->set_Src2(src2_n);
     xor_n->set_Dst(dst_n);

     if( src1_n != NULL &&
         src2_n != NULL &&
         dst_n  != NULL ){

         SC_Module *parent = sc_cell_n->get_Parent();
         assert( parent != NULL && "SC_Table->copy_XOR_Logic_2_New" );

         src1_n->set_Parent(parent);
         src2_n->set_Parent(parent);
         dst_n->set_Parent(parent);
    }
}





void SC_Table::copy_XNOR_Logic_2_New(SC_Module::SC_Cell_D *sc_cell_o,
                                     SC_Module::SC_Cell_D *sc_cell_n){

     assert( sc_cell_o != NULL &&
             sc_cell_n != NULL && "SC_Table->copy_XNOR_Logic_2_New");

     SC_LIB::SC_XNOR *xnor_o = dynamic_cast<SC_LIB::SC_XNOR*>(sc_cell_o);
     SC_LIB::SC_XNOR *xnor_n = dynamic_cast<SC_LIB::SC_XNOR*>(sc_cell_n);

     SC_Module::SC_Port_D *src1_n = get_O2N_Port(xnor_o->get_Src1());
     SC_Module::SC_Port_D *src2_n = get_O2N_Port(xnor_o->get_Src2());
     SC_Module::SC_Port_D *dst_n  = get_O2N_Port(xnor_o->get_Dst());

     xnor_n->set_Src1(src1_n);
     xnor_n->set_Src2(src2_n);
     xnor_n->set_Dst(dst_n);

     if( src1_n != NULL &&
         src2_n != NULL &&
         dst_n  != NULL ){

         SC_Module *parent = sc_cell_n->get_Parent();
         assert( parent != NULL && "SC_Table->copy_XNOR_Logic_2_New" );

         src1_n->set_Parent(parent);
         src2_n->set_Parent(parent);
         dst_n->set_Parent(parent);
    }
}





void SC_Table::copy_BUF_Logic_2_New(SC_Module::SC_Cell_D *sc_cell_o, 
                                    SC_Module::SC_Cell_D *sc_cell_n){

     assert( sc_cell_o != NULL &&
             sc_cell_n != NULL && "SC_Table->copy_BUF_Logic_2_New");

     SC_LIB::SC_BUF *buf_o = dynamic_cast<SC_LIB::SC_BUF*>(sc_cell_o);
     SC_LIB::SC_BUF *buf_n = dynamic_cast<SC_LIB::SC_BUF*>(sc_cell_n);

     SC_Module::SC_Port_D *src_n  = get_O2N_Port(buf_o->get_Src());
     SC_Module::SC_Port_D *dst_n  = get_O2N_Port(buf_o->get_Dst());

     buf_n->set_Src(src_n);
     buf_n->set_Dst(dst_n);

     if( src_n  != NULL &&
         dst_n  != NULL ){

         SC_Module *parent = sc_cell_n->get_Parent();
         assert( parent != NULL && "SC_Table->copy_BUF_Logic_2_New" );

         src_n->set_Parent(parent);
         dst_n->set_Parent(parent);
    }
}





void SC_Table::copy_INV_Logic_2_New(SC_Module::SC_Cell_D *sc_cell_o,
                                    SC_Module::SC_Cell_D *sc_cell_n){

     assert( sc_cell_o != NULL &&
             sc_cell_n != NULL && "SC_Table->copy_INV_Logic_2_New");

     SC_LIB::SC_INV *inv_o = dynamic_cast<SC_LIB::SC_INV*>(sc_cell_o);
     SC_LIB::SC_INV *inv_n = dynamic_cast<SC_LIB::SC_INV*>(sc_cell_n);

     SC_Module::SC_Port_D *src_n  = get_O2N_Port(inv_o->get_Src());
     SC_Module::SC_Port_D *dst_n  = get_O2N_Port(inv_o->get_Dst());

     inv_n->set_Src(src_n);
     inv_n->set_Dst(dst_n);

     if( src_n  != NULL &&
         dst_n  != NULL ){

         SC_Module *parent = sc_cell_n->get_Parent();
         assert( parent != NULL && "SC_Table->copy_INV_Logic_2_New" );

         src_n->set_Parent(parent);
         dst_n->set_Parent(parent);
    }
}





void SC_Table::copy_Module_2_New(SC_Module *sc_module_o, 
                                 SC_Module *sc_module_n){

 assert( sc_module_o != NULL &&
         sc_module_n != NULL && "SC_Table->copy_SC_Module_2_New" );

 // @ copy name
 sc_module_n->set_ModuleName( sc_module_o->get_ModuleName() );
 sc_module_n->set_UniqueName( sc_module_o->get_UniqueName() );
 sc_module_n->set_Parent(     sc_module_o->get_Parent()     );

 SC_Module::SC_Pass_D *sc_module_o_p = dynamic_cast<SC_Module::SC_Pass_D*>(sc_module_o);
 SC_Module::SC_Pass_D *sc_module_n_p = dynamic_cast<SC_Module::SC_Pass_D*>(sc_module_n);
 sc_module_n_p->set_Pass( sc_module_o_p->get_Pass() );
 
 // @ copy input
 SC_Module::PortVec sc_in_vec = sc_module_o->get_InputPortVec();
 assert( !sc_in_vec.empty() && "SC_Table->copy_SC_Module_2_New" );

 for(SC_Module::PortVec_iter in_it  = sc_in_vec.begin(); 
                             in_it != sc_in_vec.end();   ++in_it){

    SC_Module::SC_Port_D *in_p_o = static_cast<SC_Module::SC_Port_D*>(*in_it);
    SC_Module::SC_Port_D *in_p_n = new SC_Module::SC_Port_D();

    assert( in_p_o != NULL && 
            in_p_n != NULL && "SC_Table->copy_SC_Module_2_New" );
    
    copy_Port_2_New(in_p_o,in_p_n);

    in_p_n->set_Parent(sc_module_n);

    sc_module_n->set_InputPortVec(in_p_n);

    set_O2N_Port(in_p_o,in_p_n);
 }



 // @ copy output
 SC_Module::PortVec sc_ot_vec = sc_module_o->get_OutputPortVec();
 assert( !sc_ot_vec.empty() && "SC_Table->copy_SC_Module_2_New" );

 for(SC_Module::PortVec_iter ot_it  = sc_ot_vec.begin(); 
                             ot_it != sc_ot_vec.end();  ++ot_it){

    SC_Module::SC_Port_D *ot_p_o = static_cast<SC_Module::SC_Port_D*>(*ot_it);
    SC_Module::SC_Port_D *ot_p_n = new SC_Module::SC_Port_D();

    assert( ot_p_o != NULL && 
            ot_p_n != NULL && "SC_Table->copy_SC_Module_2_New" );
   
    copy_Port_2_New(ot_p_o,ot_p_n);

    ot_p_n->set_Parent(sc_module_n);

    sc_module_n->set_OutputPortVec(ot_p_n); 

    set_O2N_Port(ot_p_o,ot_p_n);
 }



 // @ copy wire 
 SC_Module::PortVec sc_wr_vec = sc_module_o->get_WirePortVec();

 for(SC_Module::PortVec_iter wr_it  = sc_wr_vec.begin(); 
                             wr_it != sc_wr_vec.end();  ++wr_it){

    SC_Module::SC_Port_D *wr_p_o = static_cast<SC_Module::SC_Port_D*>(*wr_it);
    SC_Module::SC_Port_D *wr_p_n = new SC_Module::SC_Port_D();

    assert( wr_p_o != NULL && 
            wr_p_n != NULL && "SC_Table->copy_SC_Module_2_New" );
   
    copy_Port_2_New(wr_p_o,wr_p_n);

    sc_module_n->set_WirePortVec(wr_p_n);

    wr_p_n->set_Parent(sc_module_n);

    set_O2N_Port(wr_p_o,wr_p_n);
 }



 // @ copy cell
 SC_Module::CellVec  sc_cell_vec = sc_module_o->get_CellVec();
 assert( !sc_cell_vec.empty() && "SC_Table->copy_SC_Module_2_New");

 for( SC_Module::CellVec_iter cell_it  = sc_cell_vec.begin(); 
                              cell_it != sc_cell_vec.end();  ++cell_it ){

     SC_Module::SC_Cell_D *cell_o = static_cast<SC_Module::SC_Cell_D*>(*cell_it);
     SC_Module::SC_Cell_D *cell_n = new SC_Module::SC_Cell_D();

     assert( cell_o != NULL &&
             cell_n != NULL && "SC_Table->copy_SC_Module_2_New" );

     copy_Cell_2_New(cell_o,cell_n);

     cell_n->set_Parent(sc_module_n);
     cell_n->set_Self(NULL);

     copy_AND_Logic_2_New(cell_o,cell_n);
     copy_NAND_Logic_2_New(cell_o,cell_n);
     copy_OR_Logic_2_New(cell_o,cell_n);
     copy_NOR_Logic_2_New(cell_o,cell_n);
     copy_XOR_Logic_2_New(cell_o,cell_n);
     copy_XNOR_Logic_2_New(cell_o,cell_n);
     copy_BUF_Logic_2_New(cell_o,cell_n);
     copy_INV_Logic_2_New(cell_o,cell_n);

     sc_module_n->set_CellVec(cell_n);
 }


 // @ copy signal
 SC_Module::SignalVec sc_signal_vec = sc_module_o->get_SignalVec();

 for(SC_Module::SignalVec_iter signal_it  = sc_signal_vec.begin(); 
                               signal_it != sc_signal_vec.end();   ++signal_it){

      SC_Module::SC_Signal_D *sc_signal = static_cast<SC_Module::SC_Signal_D*>(*signal_it);

      assert( sc_signal != NULL && "SC_Table->copy_Module_2_New" );

      SC_Module::SC_Port_D *p_o = sc_signal->get_Port();
      SC_Module::SC_Port_D *p_n = get_O2N_Port(p_o);

      assert(  p_o != NULL   &&
               p_n != NULL   && "SC_Table->copy_Module_2_New" );
   
      sc_module_n->set_SignalVec( sc_signal->get_PortName(),
                                  p_n,
                                  sc_signal->get_PortInx() );
 }



//@ copy Link
O2N_Port_D o2n_port = get_O2N_Port();

for(O2N_Port_iter o2n_it  = o2n_port.begin(); 
                  o2n_it != o2n_port.end();   ++o2n_it){

    SC_Module::SC_Port_D *port_o = static_cast<SC_Module::SC_Port_D*>(o2n_it->first);
    SC_Module::SC_Port_D *port_n = static_cast<SC_Module::SC_Port_D*>(o2n_it->second);

    assert( port_o != NULL &&
            port_n != NULL && "SC_Table->copy_SC_Module_2_New" );

    SC_Module::PortVec  pre_p_vec = port_o->get_PrePortVec();
    SC_Module::PortVec  nxt_p_vec = port_o->get_NxtPortVec();

   for(SC_Module::PortVec_iter pre_it  = pre_p_vec.begin(); 
                               pre_it != pre_p_vec.end();   ++pre_it){

       SC_Module::SC_Port_D *pre_p_o  = static_cast<SC_Module::SC_Port_D*>(*pre_it);
       SC_Module::SC_Port_D *pre_p_n  = get_O2N_Port(pre_p_o);

       assert( pre_p_o != NULL &&
               pre_p_n != NULL && "SC_Table->copy_SC_Module_2_New" );

       port_n->set_PrePortVec(pre_p_n);
   }

   for(SC_Module::PortVec_iter nxt_it  = nxt_p_vec.begin(); 
                               nxt_it != nxt_p_vec.end();   ++nxt_it){

       SC_Module::SC_Port_D *nxt_p_o = static_cast<SC_Module::SC_Port_D*>(*nxt_it);
       SC_Module::SC_Port_D *nxt_p_n = get_O2N_Port(nxt_p_o);

       assert( nxt_p_o != NULL &&
               nxt_p_n != NULL && "SC_Table->copy_SC_Module_2_New" );

       port_n->set_NxtPortVec(nxt_p_n);
   }
 }

clr_O2N_Port();

}





void  SC_Table::set_Root_Boundary(SC_Module *sc_root){

      assert( sc_root != NULL && "SC_Table->set_Root_Boundary");

      SC_Module::PortVec sc_ot_vec = sc_root->get_OutputPortVec();
      assert( !sc_ot_vec.empty() && "SC_Table->set_Root_Boundary");

      SC_Module::PortVec sc_in_vec = sc_root->get_InputPortVec();
      assert( !sc_in_vec.empty() && "SC_Table->set_Root_Boundary");
     
 
for(SC_Module::PortVec_iter ot_it  = sc_ot_vec.begin(); 
                             ot_it != sc_ot_vec.end();  ++ot_it){

    SC_Module::SC_Port_D *ot_p = static_cast<SC_Module::SC_Port_D*>(*ot_it);
    assert( ot_p != NULL && "SC_Table->set_Root_Boundary");
   
    SC_Module::SC_Pass_D *ot_ps = dynamic_cast<SC_Module::SC_Pass_D*>(ot_p);
                          ot_ps->set_Pass(false); 
}


for(SC_Module::PortVec_iter in_it  = sc_in_vec.begin(); 
                            in_it != sc_in_vec.end();  ++in_it){

    SC_Module::SC_Port_D *in_p = static_cast<SC_Module::SC_Port_D*>(*in_it);
    assert( in_p != NULL && "SC_Table->set_Root_Boundary");
   
    SC_Module::SC_Pass_D *in_ps = dynamic_cast<SC_Module::SC_Pass_D*>(in_p);
                          in_ps->set_Pass(false); 
}

    SC_Module::SC_Pass_D *sc_root_p = dynamic_cast<SC_Module::SC_Pass_D*>(sc_root);
                          sc_root_p->set_Pass(false);
}





void  SC_Table::set_RootContext(std::string str){

SC_Module *root_o = get_ModuleMap(str);
SC_Module *root_n = new SC_Module();

assert( root_o != NULL &&
        root_n != NULL && "gen_Root_Context" );

copy_Module_2_New(root_o,root_n);
set_Root_Boundary(root_n); 
//root_o->dump_Context();
//std::cout << "-------------------" << std::endl;
//root_n->dump_Context();
//
//dump_O2N_Port_Context();
//exit(0);

gen_RootContext(root_n);

RootModule = root_n; 

clr_ModuleMap();
clr_O2N_Port();
}




void SC_Table::gen_RootContext(SC_Module *sc_module){

std::string    module_nm;
std::string    unique_nm;
std::string    cell_p_nm_o;
int            inx;

       assert( sc_module != NULL && "gen_Root_Context" );

       SC_Module::CellVec cell_vec = sc_module->get_CellVec();
  
   for(SC_Module::CellVec_iter cell_it  = cell_vec.begin(); 
                               cell_it != cell_vec.end();   ++cell_it){
  
       SC_Module::SC_Cell_D *cell = static_cast<SC_Module::SC_Cell_D*>(*cell_it);
       assert( cell != NULL && "gen_Root_Context" );

       // translate cell 2 module map
       module_nm           = cell->get_ModuleName();
       unique_nm           = cell->get_CellName();
       SC_Module *cell_m_o = get_ModuleMap(module_nm);

       // @ deepest logic gate 
       if(cell_m_o == NULL){

          SC_Module::PortVec port_vec  = cell->get_PortVec();
          SC_Module::PortVec_iter p_it = port_vec.begin();

          typedef std::map<SC_Module::SC_Port_D*,SC_Module::SC_Port_D*>           port_map;
          typedef std::map<SC_Module::SC_Port_D*,SC_Module::SC_Port_D*>::iterator port_map_iter;

          port_map pp_map;

          SC_Module::SC_Port_D *port = static_cast<SC_Module::SC_Port_D*>(*p_it);
          assert( port != NULL && "gen_Root_Context");
           
          SC_Module::PortVec pre_p_vec = port->get_PrePortVec();

          for(SC_Module::PortVec_iter pre_p_it  = pre_p_vec.begin();
                                      pre_p_it != pre_p_vec.end();  ++pre_p_it){

          SC_Module::SC_Port_D *pre_p = static_cast<SC_Module::SC_Port_D*>(*pre_p_it);
          assert( pre_p != NULL && "gen_Root_Context");

          pre_p->del_NxtPortVec(port);
          pre_p->set_PrePortVec(port);
 
          port->set_NxtPortVec(pre_p);
          port->del_PrePortVec(pre_p);

         }

          set_LeafCellVec(cell);
 
       // @ recourse
       } else {

          SC_Module *cell_m_n = new SC_Module(); 
     
          assert( cell_m_o != NULL &&
                  cell_m_n != NULL && "gen_Root_Context" );
     
          copy_Module_2_New(cell_m_o,cell_m_n);

          cell_m_n->set_Parent(sc_module);    
          cell_m_n->set_UniqueName(unique_nm);
          cell->set_Parent(sc_module);
          cell->set_Self(cell_m_n); 
            
          // relink Port 2 New Module 
          SC_Module::PortVec cell_p_vec = cell->get_PortVec(); 
          inx = 0;
     
          for(SC_Module::PortVec_iter cell_p_it  = cell_p_vec.begin(); 
                                      cell_p_it != cell_p_vec.end();   ++cell_p_it){
     
            SC_Module::SC_Port_D *cell_p_o = static_cast<SC_Module::SC_Port_D*>(*cell_p_it);
            assert( cell_p_o != NULL && "gen_Root_Context" );
    
            SC_Module::PortVec pre_p_vec = cell_p_o->get_PrePortVec();
            SC_Module::PortVec nxt_p_vec = cell_p_o->get_NxtPortVec();
     
             // indirect/direct case 
             cell_p_nm_o = cell_p_o->get_Name();
             SC_Module::SC_Port_D  *_m_p_n = cell_m_n->get_Signal(cell_p_nm_o); 
 
             if( _m_p_n == NULL )
                 _m_p_n = cell_m_n->get_Signal(inx++);
   
             assert( _m_p_n != NULL && "gen_Root_Context" );
     
             // pre Port 2 new & check connection 
             for(SC_Module::PortVec_iter pre_it  = pre_p_vec.begin(); 
                                         pre_it != pre_p_vec.end();   ++pre_it){
   
                 SC_Module::SC_Port_D *pre_p = static_cast<SC_Module::SC_Port_D*>(*pre_it);
                 assert( pre_p != NULL && "gen_Root_Context" );

                         pre_p->del_NxtPortVec(cell_p_o);
                         cell_p_o->del_PrePortVec(pre_p);
   
                         if( cell_m_n->is_InputPortVec_Contain(_m_p_n) ){ 
                             _m_p_n->set_PrePortVec(pre_p);
                             pre_p->set_NxtPortVec(_m_p_n);

                         } else {
                             _m_p_n->set_NxtPortVec(pre_p);
                             pre_p->set_PrePortVec(_m_p_n);
                         }                    
            }
     
             // nxt Port 2 new & check connection
             for(SC_Module::PortVec_iter nxt_it  = nxt_p_vec.begin(); 
                                         nxt_it != nxt_p_vec.end();  ++nxt_it){
   
                 SC_Module::SC_Port_D *nxt_p = static_cast<SC_Module::SC_Port_D*>(*nxt_it);
                 assert( nxt_p != NULL && "gen_Root_Context" );

                         nxt_p->del_PrePortVec(cell_p_o);
                         cell_p_o->del_NxtPortVec(nxt_p);

                         if( sc_module->is_OutputPortVec_Contain(nxt_p) ){
                             _m_p_n->set_NxtPortVec(nxt_p);
                             nxt_p->set_PrePortVec(_m_p_n);

                         } else { 
                             _m_p_n->set_PrePortVec(nxt_p);
                             nxt_p->set_NxtPortVec(_m_p_n);
                         }
             }
          }
   
          gen_RootContext(cell_m_n);
       }

      cell->clr_PortVec();
   }

clr_O2N_Port();

}





