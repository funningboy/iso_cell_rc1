#ifndef _SC_TYPE_H_
#define _SC_TYPE_H_

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace xVerilog;

namespace xVerilog {

class SC_Type {

public : 
      enum SC_TYPE {
           SC_TYPE_CLK,     // clock
           SC_TYPE_RST,     // reset
           SC_TYPE_WIRE,    // wire
           SC_TYPE_ENABLE,
           SC_TYPE_undef
       };


public :
       SC_Type(){}
      ~SC_Type(){}

public:
      void         set_Type( SC_TYPE type ){  Type = type; }
      SC_TYPE      get_Type(){  return Type; }

public :
     void          dump_Context(){

                   std::cout << "@ "        << this << std::endl;
                   std::cout << " @Type   " << this->get_Type() << std::endl;      
    }
     


private :
      SC_TYPE         Type;

 };

}

#endif
