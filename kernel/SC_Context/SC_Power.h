#ifndef _SC_POWER_H_
#define _SC_POWER_H_

#include <iostream>

#include "kernel/SC_Context/SC_Define.h"

using namespace std;

namespace xVerilog {

template <class TSwitchPower>
class SC_Power {

public :
       SC_Power(){}
      ~SC_Power(){}

public:
      void          set_SwitchPower( TSwitchPower  switch_power ){ SwitchPower = switch_power; }
      TSwitchPower  get_SwitchPower(){ return SwitchPower; }

public :
     void            dump_Context(){

                     std::cout << "@ "                << this << endl;
                     std::cout << "   @Switch_Power " << this->get_SwitchPower() << std::endl;
    }
     


private :
      TSwitchPower    SwitchPower; 
 };

}

#endif
