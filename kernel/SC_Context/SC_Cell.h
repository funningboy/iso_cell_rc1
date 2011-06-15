#ifndef _SC_CELL_H_
#define _SC_CELL_H_

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

#include <stdio.h>
#include <assert.h>

#include "kernel/SC_Context/SC_Define.h"
#include "kernel/SC_Context/SC_Domain.h"
#include "kernel/SC_Context/SC_Pass.h"
#include "kernel/SC_Lib/SC_Lib.h"

using namespace std;
using namespace xVerilog;

namespace xVerilog {

class SC_Module;

class SC_Cell : public SC_LIB,
                public SC_Domain,
                public SC_Pass {

public:
       enum SC_TLIB {
            SC_TLIB_AND,
            SC_TLIB_NAND,
            SC_TLIB_OR,
            SC_TLIB_NOR,
            SC_TLIB_XOR,
            SC_TLIB_XNOR,
            SC_TLIB_BUF,
            SC_TLIB_INV,
            SC_TLIB_DFF,
            SC_TLIB_undef
      };


public:
       typedef SC_Port< Def_Arrive_Time, Def_Switch_Power >   SC_Port_D;
       typedef std::vector< SC_Port_D* >                      PortVec;
       typedef std::vector< SC_Port_D* >::iterator            PortVec_iter;
 

public:
   SC_Cell(){}

  ~SC_Cell(){
              MPortVec.clear();
            }


public:
      void           set_Parent( SC_Module *parent ){ Parent = parent; }
      SC_Module     *get_Parent() { return Parent; }

 
public:
      void           set_Self( SC_Module *self ){ Self = self; }
      SC_Module     *get_Self() { return Self; }


public:
      void           set_TLib(SC_TLIB tlib){ TLib = tlib; }
      SC_TLIB        get_TLib(){ return TLib; }


public:
      void           set_ModuleName( std::string str ){ ModuleName = str;  }
      std::string    get_ModuleName(){ return ModuleName; }


public:
      void           set_CellName( std::string str ){   CellName = str; }
      std::string    get_CellName(){ return CellName; }


public:
       void       set_PortVec( SC_Port_D *sc_port ){ MPortVec.push_back(sc_port); }

       bool       is_PortVec_Contain( SC_Port_D *sc_port ){ 

                  return std::find(MPortVec.begin(), MPortVec.end(), sc_port) != MPortVec.end();
                  }

       void       del_PortVec( SC_Port_D *sc_port ){

                        PortVec_iter i = std::find(MPortVec.begin(), MPortVec.end(), sc_port);   
                               
                        if( i != MPortVec.end() )
                              MPortVec.erase(i);
                      
                  }

       std::vector< SC_Port_D* >  get_PortVec() { return MPortVec;  }


       void       clr_PortVec(){  MPortVec.clear(); }


public : 
      void        dump_Context(){

                  std::cout << "@ " << this << endl;
                  std::cout << "   ModuleName  " << this->get_ModuleName() << std::endl;
                  std::cout << "   CellName    " << this->get_CellName()   << std::endl;
                  std::cout << "  @Parent      " << this->get_Parent()     << std::endl;
                  std::cout << "  @Self        " << this->get_Self()       << std::endl;

                  SC_Domain *sc_domain = dynamic_cast<SC_Domain*>(this);
                             sc_domain->dump_Context();

                  SC_Pass   *sc_pass   = dynamic_cast<SC_Pass*>(this);
                             sc_pass->dump_Context();
 
                  PortVec p_vec = this->get_PortVec();
                  std::cout << "   CellPortVec List " << std::endl;
  
                  for(PortVec_iter p_it = p_vec.begin(); 
                                   p_it != p_vec.end(); ++p_it){

                      SC_Port_D *sc_p = static_cast<SC_Port_D*>(*p_it);
                      assert ( sc_p != NULL && "SC_Cell->dump_Context");
                      sc_p->dump_Context();
                  }
      }

 

private:
  
   std::vector< SC_Port_D* > MPortVec;

   SC_Module       *Parent;
   SC_Module       *Self;

   std::string     ModuleName;
   std::string     CellName;

   SC_TLIB         TLib;
  };
}

#endif
