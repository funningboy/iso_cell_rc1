#ifndef _SC_PORT_H_
#define _SC_PORT_H_

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

#include "kernel/SC_Context/SC_Module.h"
#include "kernel/SC_Context/SC_Power.h"
#include "kernel/SC_Context/SC_Time.h"
#include "kernel/SC_Context/SC_Logic.h"
#include "kernel/SC_Context/SC_Type.h"
#include "kernel/SC_Context/SC_Domain.h"
#include "kernel/SC_Context/SC_Pass.h"


using namespace std;
using namespace xVerilog;

namespace xVerilog {

class SC_Module;

template <class TArriveTime, class TSwitchPower>

class SC_Port  : public SC_Time<TArriveTime>,
                 public SC_Power<TSwitchPower>, 
                 public SC_Logic,
                 public SC_Type,
                 public SC_Domain,
                 public SC_Pass    {

public :
      typedef  SC_Port< TArriveTime, TSwitchPower >         SC_Port_D;
      typedef  SC_Time< TArriveTime >                       SC_Time_D;
      typedef  SC_Power<TSwitchPower >                      SC_Power_D;
      typedef  SC_Logic                                     SC_Logic_D;
      typedef  SC_Type                                      SC_Type_D;
      typedef  SC_Domain                                    SC_Domain_D;
      typedef  SC_Pass                                      SC_Pass_D;
      typedef typename std::vector< SC_Port_D* >            PortVec;
      typedef typename std::vector< SC_Port_D* >::iterator  PortVec_iter;


public :
       SC_Port(){}

      ~SC_Port(){ 
                  PrePortVec.clear();
                  NxtPortVec.clear();
                }

public :
        void              set_Parent( SC_Module *parent ){ Parent = parent;  }
        SC_Module        *get_Parent(){ return Parent; } 

public : 
        void              set_Name( std::string name ){ Name = name; }
        std::string       get_Name(){ return Name; }

public:
      void                 set_PrePortVec( SC_Port_D  *sc_port ){ PrePortVec.push_back(sc_port);  }

      bool                 is_PrePortVec_Contain( SC_Port_D *sc_port ){ 

                           return std::find(PrePortVec.begin(),PrePortVec.end(),sc_port) != PrePortVec.end();
                           }

      void                 del_PrePortVec( SC_Port_D *sc_port ){

                           PortVec_iter pt = std::find(PrePortVec.begin(),PrePortVec.end(),sc_port);                                                    

                           if( pt != PrePortVec.end() )
                               PrePortVec.erase(pt);
                           
                           }

      std::vector< SC_Port_D* > get_PrePortVec(){ return PrePortVec; }


      bool                 has_PrePortVec(){ return !PrePortVec.empty(); }


public :
      void                 set_NxtPortVec( SC_Port_D  *sc_port ){ NxtPortVec.push_back(sc_port);  }

      bool                 is_NxtPortVec_Contain( SC_Port_D *sc_port ){ 

                           return std::find(NxtPortVec.begin(),NxtPortVec.end(),sc_port) != NxtPortVec.end();

                           }

      void                 del_NxtPortVec( SC_Port_D *sc_port ){

                           PortVec_iter pt = std::find(NxtPortVec.begin(),NxtPortVec.end(),sc_port);                                                    

                           if( pt != NxtPortVec.end() )
                               NxtPortVec.erase(pt);

                           }

      std::vector< SC_Port_D* > get_NxtPortVec(){ return NxtPortVec; }


      bool                 has_NxtPortVec(){ return !NxtPortVec.empty(); }

public :
     void                  dump_Context(){

                           std::cout << "@ " << this << endl;
                           std::cout << "   Name         " << this->get_Name()        << std::endl;
                           std::cout << "  @Parent       " << this->get_Parent()      << std::endl;
                         
                           SC_Domain *sc_domain = dynamic_cast<SC_Domain*>(this);
                                      sc_domain->dump_Context();

                           SC_Pass   *sc_pass   = dynamic_cast<SC_Pass*>(this);
                                      sc_pass->dump_Context();

                           PortVec pre_p_vec      = this->get_PrePortVec();
                           PortVec nxt_p_vec      = this->get_NxtPortVec();

                           std::cout << "   PrePortVec List" << std::endl;
                           for(PortVec_iter p_it  = pre_p_vec.begin(); 
                                            p_it != pre_p_vec.end(); ++p_it)
                           std::cout << "   @ " << (*p_it) << std::endl;
                           
                           std::cout << "   NxtPortVec List" << std::endl;
                           for(PortVec_iter p_it  = nxt_p_vec.begin(); 
                                            p_it != nxt_p_vec.end(); ++p_it)
                           std::cout << "   @ " << (*p_it) << std::endl;

     }
     


private :
      std::string     Name;
 
      std::vector< SC_Port_D* > PrePortVec;
      std::vector< SC_Port_D* > NxtPortVec; 

      SC_Module       *Parent;
 };

}

#endif
