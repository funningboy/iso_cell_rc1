
#ifndef _SC_MODULE_H_
#define _SC_MODULE_H_

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

#include <stdio.h>
#include <assert.h>

#include "kernel/SC_Context/SC_Define.h"
#include "kernel/SC_Context/SC_Port.h"
#include "kernel/SC_Context/SC_Cell.h"
#include "kernel/SC_Context/SC_Signal.h"
#include "kernel/SC_Context/SC_Domain.h"
#include "kernel/SC_Context/SC_Pass.h"
#include "kernel/SC_Lib/SC_Lib.h"

using namespace std;
using namespace xVerilog;

namespace xVerilog {

class SC_Module : public SC_Domain,
                  public SC_Pass {

public :
       typedef SC_Port< Def_Arrive_Time, Def_Switch_Power >     SC_Port_D;
       typedef std::vector< SC_Port_D* >                        PortVec;
       typedef std::vector< SC_Port_D* >::iterator              PortVec_iter;

       typedef SC_Cell                                          SC_Cell_D;
       typedef std::vector< SC_Cell_D* >                        CellVec;
       typedef std::vector< SC_Cell_D* >::iterator              CellVec_iter;

       typedef SC_Signal                                        SC_Signal_D;
       typedef std::vector< SC_Signal_D* >                      SignalVec;
       typedef std::vector< SC_Signal_D* >::iterator            SignalVec_iter;

       typedef SC_Time<  Def_Arrive_Time  >                     SC_Time_D;
       typedef SC_Power< Def_Switch_Power >                     SC_Power_D;
       typedef SC_Logic                                         SC_Logic_D;
       typedef SC_Type                                          SC_Type_D;
       typedef SC_Domain                                        SC_Domain_D;
       typedef SC_Pass                                          SC_Pass_D;

public :
        SC_Module(){}

       ~SC_Module(){                      
                     InputPortVec.clear();
                     OutputPortVec.clear();
                     WirePortVec.clear();
 
                     MSignalVec.clear();

                     MCellVec.clear();
                   } 


public :
       void          set_ModuleName( std::string str ) { ModuleName = str;  }
       std::string   get_ModuleName(){ return ModuleName; }


public :
       void          set_UniqueName( std::string str ) { UniqueName = str;  }
       std::string   get_UniqueName(){ return UniqueName; }


public:
       void       set_InputPortVec( SC_Port_D* sc_port ){ InputPortVec.push_back(sc_port); }

       bool       is_InputPortVec_Contain( SC_Port_D *sc_port ){ 

                  return std::find(InputPortVec.begin(), InputPortVec.end(), sc_port) != InputPortVec.end();
                  }

       void       del_InputPortVec( SC_Port_D* sc_port ){

                        PortVec_iter i = std::find(InputPortVec.begin(), InputPortVec.end(), sc_port);   
                               
                        if( i != InputPortVec.end() )
                              InputPortVec.erase(i);
                      
                  }

       std::vector< SC_Port_D* >  get_InputPortVec() { return InputPortVec;  }


public:
       void       set_OutputPortVec( SC_Port_D* sc_port ){ OutputPortVec.push_back(sc_port); }

       bool       is_OutputPortVec_Contain( SC_Port_D* sc_port ){ 

                  return std::find(OutputPortVec.begin(), OutputPortVec.end(), sc_port) != OutputPortVec.end();
                  }

       void       del_OutputPortVec( SC_Port_D* sc_port ){

                        PortVec_iter i = std::find(OutputPortVec.begin(), OutputPortVec.end(), sc_port);   
                               
                        if( i != OutputPortVec.end() )
                              OutputPortVec.erase(i);
                        
                  }

       std::vector< SC_Port_D* >  get_OutputPortVec() { return OutputPortVec;  }


public:
       void       set_WirePortVec( SC_Port_D* sc_port ){ WirePortVec.push_back(sc_port); }

       bool       is_WirePortVec_Contain( SC_Port_D* sc_port ){ 

                  return std::find(WirePortVec.begin(), WirePortVec.end(), sc_port) != WirePortVec.end();
                  }

       void       del_WirePortVec( SC_Port_D* sc_port ){

                        PortVec_iter i = std::find(WirePortVec.begin(), WirePortVec.end(), sc_port);   
                               
                        if( i != WirePortVec.end() )
                              WirePortVec.erase(i);
                        
                  }

       std::vector< SC_Port_D* >  get_WirePortVec() { return WirePortVec;  }


public :

       void       set_CellVec( SC_Cell_D* sc_cell ){ MCellVec.push_back(sc_cell); }

       bool       is_CellVec_Contain( SC_Cell_D* sc_cell ){ 

                  return std::find(MCellVec.begin(), MCellVec.end(), sc_cell) != MCellVec.end();
                  }

       void       del_CellVec( SC_Cell_D* sc_cell ){

                        CellVec_iter i = std::find(MCellVec.begin(), MCellVec.end(), sc_cell);   
                               
                        if( i != MCellVec.end() )
                              MCellVec.erase(i);
                        
                  }

       std::vector< SC_Cell_D* >  get_CellVec() { return MCellVec;  }


public :
       void        set_SignalVec( std::string port_name, SC_Port_D* sc_port, int port_inx ){ 
 
                                  SC_Signal *sc_signal = new SC_Signal();
   
                                             sc_signal->set_PortName(port_name);
                                             sc_signal->set_PortInx(port_inx);
                                             sc_signal->set_Port(sc_port);
       
                                  MSignalVec.push_back(sc_signal); 
                    } 


       SC_Port_D  *get_Signal( std::string port_name ){ 
       
                     for(SignalVec_iter signal_it  = MSignalVec.begin();
                                        signal_it != MSignalVec.end();   ++signal_it){

                         SC_Signal *sc_signal = static_cast<SC_Signal*>(*signal_it);  

                         assert( sc_signal != NULL && "SC_Module->get_Signal" );
                                             
                                      if( sc_signal->get_PortName() == port_name )
                                          return sc_signal->get_Port();

                       }
                     return NULL;
                    }


       SC_Port_D  *get_Signal( int port_inx ){ 

                     for(SignalVec_iter signal_it  = MSignalVec.begin();
                                        signal_it != MSignalVec.end();   ++signal_it){

                         SC_Signal *sc_signal = static_cast<SC_Signal*>(*signal_it);  

                         assert( sc_signal != NULL && "SC_Module->get_Signal" );
                                             
                                      if( sc_signal->get_PortInx() == port_inx )
                                          return sc_signal->get_Port();

                       }
                     return NULL;
                  }


SignalVec         get_SignalVec(){ return MSignalVec; }


public :
       void        set_Parent(SC_Module *parent){ Parent = parent; }
       SC_Module  *get_Parent(){ return Parent; }

public  : 
        void      dump_Context(){

            PortVec sc_in_vec   = this->get_InputPortVec();
            PortVec sc_ot_vec   = this->get_OutputPortVec();
            PortVec sc_wr_vec   = this->get_WirePortVec();
            CellVec sc_cell_vec = this->get_CellVec();
            
            std::cout << " @SC_Module            " << this                   << std::endl;
            std::cout << " @SC_Module_Parent     " << this->get_Parent()     << std::endl;
            std::cout << "  SC_Module Name       " << this->get_ModuleName() << std::endl;
            std::cout << "  SC_Module_UniqueName " << this->get_UniqueName() << std::endl;
 
            SC_Domain_D *sc_d = dynamic_cast<SC_Domain_D*>(this);
                         sc_d->dump_Context();

            SC_Pass_D *sc_p = dynamic_cast<SC_Pass_D*>(this);
                       sc_p->dump_Context();

            std::cout << "  SC_Module SignalVec"   << std::endl;
       
            for(SignalVec_iter s_it  = MSignalVec.begin(); 
                               s_it != MSignalVec.end();   ++s_it){ 

                SC_Signal_D *sc_s = static_cast<SC_Signal_D*>(*s_it);
                assert( sc_s != NULL && "SC_Module->dump_Context" );

                std::cout << sc_s->get_Port()     << " :: " << 
                             sc_s->get_PortName() << " :: " << 
                             sc_s->get_PortInx()  << std::endl;
            }
       
            std::cout << "  SC_Module InputVec" << std::endl;
       
            for(PortVec_iter p_it  = sc_in_vec.begin(); 
                             p_it != sc_in_vec.end();  ++p_it){

                SC_Port_D *sc_p = static_cast<SC_Port_D*>(*p_it);
                assert( sc_p != NULL && "SC_Module->dump_Context" );
       
                 sc_p->dump_Context(); 
           }
       
       
           std::cout << "  SC_Module OutputVec" << std::endl;
       
           for(PortVec_iter p_it  = sc_ot_vec.begin(); 
                            p_it != sc_ot_vec.end(); ++p_it){

               SC_Port_D *sc_p = static_cast<SC_Port_D*>(*p_it);
               assert( sc_p != NULL && "SC_Module->dump_Context" );
       
               sc_p->dump_Context(); 
           }
       
       
           std::cout << "  SC_Module WireVec" << std::endl;
       
           for(PortVec_iter p_it  = sc_wr_vec.begin(); 
                            p_it != sc_wr_vec.end(); ++p_it){

               SC_Port_D *sc_p = static_cast<SC_Port_D*>(*p_it);
               assert( sc_p != NULL && "SC_Module->dump_Context" );
       
               sc_p->dump_Context(); 
           }
       
        
           std::cout << "  SC_Cell_Vec" << std::endl;
       
           for(CellVec_iter c_it  = sc_cell_vec.begin(); 
                            c_it != sc_cell_vec.end(); ++c_it){

               SC_Cell_D *sc_c = static_cast<SC_Cell_D*>(*c_it);
               assert( sc_c != NULL && "SC_Module->dump_Conext" );
       
               sc_c->dump_Context(); 
          }

           std::cout << std::endl;
           std::cout << std::endl;
 
        }     

   

private :
      std::string    ModuleName;
      std::string    UniqueName;

      std::vector< SC_Signal_D* > MSignalVec;

      std::vector< SC_Port_D* >   InputPortVec;
      std::vector< SC_Port_D* >   OutputPortVec;
      std::vector< SC_Port_D* >   WirePortVec;

      std::vector< SC_Cell_D* >   MCellVec;

      SC_Module    *Parent; 
 
 };
}

#endif
