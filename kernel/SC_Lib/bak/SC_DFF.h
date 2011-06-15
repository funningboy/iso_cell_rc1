#ifndef _SC_DFF_H_
#define _SC_DFF_H_

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

#include "kernel/SC_Context/SC_Define.h"
#include "kernel/SC_Context/SC_Port.h"
#include "kernel/SC_Context/SC_Domain.h"

using namespace std;
//using namespace xVerilog;

namespace xVerilog {

class SC_DFF  {

public :
      typedef  SC_Port< Def_Arrive_Time, Def_Switch_Power >  SC_Port_D;

public :
      SC_DFF(){}

     ~SC_DFF(){}

public :
      void         set_D(SC_Port_D * d){ D = d; }
      SC_Port_D   *get_D(){           return D; }

public :
      void         set_Q(SC_Port_D * q){ Q = q; }
      SC_Port_D   *get_Q(){           return Q; }


public :
      void         set_Clk(SC_Port_D * clk){ Clk = clk; }
      SC_Port_D   *get_Clk(){              return Clk;  }

public :
      void         set_Rst(SC_Port_D * rst){ Rst = rst; }
      SC_Port_D   *get_Rst(){               return Rst; }


public :
      void         run_SC_Async_Reset_DFF();

      void         run_SC_Sync_Pos_Reset_DFF();

      void         run_SC_Sync_Neg_Reset_DFF();


public :
      void         dump_Context(){

                   std::cout << "@" << this << endl;
                   std::cout << "  @DFF->D      " << this->get_D()   << endl;
                   std::cout << "  @DFF->Q      " << this->get_Q()   << endl;
                   std::cout << "  @DFF->Rst    " << this->get_Rst() << endl;
                   std::cout << "  @DFF->Clk    " << this->get_Clk() << endl;

                   SC_Domain *sc_domain = dynamic_cast<SC_Domain*>(this);
                              sc_domain->dump_Context();
 
                   }

private :
      SC_Port_D *D;
      SC_Port_D *Q;                
      SC_Port_D *Clk;
      SC_Port_D *Rst;

  };
}
#endif
