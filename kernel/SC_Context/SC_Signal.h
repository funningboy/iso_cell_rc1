
#ifndef _SC_SIGNAL_H_
#define _SC_SIGNAL_H_

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

#include <stdio.h>
#include <assert.h>

#include "kernel/SC_Context/SC_Define.h"
#include "kernel/SC_Context/SC_Module.h"
#include "kernel/SC_Context/SC_Port.h"

using namespace std;
using namespace xVerilog;

namespace xVerilog {

class SC_Module;

class SC_Signal {

public :
       typedef SC_Port< Def_Arrive_Time, Def_Switch_Power >     SC_Port_D;

public :
        SC_Signal(){}

       ~SC_Signal(){}

public :
        void         set_PortName( std::string port_name ){ PortName = port_name; }
        std::string  get_PortName(){                        return PortName;      } 

public :
       void          set_PortInx( int port_inx ){ PortInx = port_inx; }
       int           get_PortInx(){               return PortInx;     }    

public :
       void          set_Port( SC_Port_D* sc_port ){ Port = sc_port;  }
       SC_Port_D    *get_Port(){                     return Port;     }


private:
        std::string  PortName;
        int          PortInx;
        SC_Port_D*   Port;                 
  };
}

#endif 
