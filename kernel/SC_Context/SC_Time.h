#ifndef _SC_TIME_H_
#define _SC_TIME_H_

#include <iostream>

#include "kernel/SC_Context/SC_Define.h"

using namespace std;

namespace xVerilog {

template <class TArriveTime>
class SC_Time {

public :
       SC_Time(){}
      ~SC_Time(){}

public :
      void          set_ArriveTime( TArriveTime  arrive_time ){  ArriveTime =  arrive_time; }
      TArriveTime   get_ArriveTime(){  return ArriveTime;  }

public :
     void                  dump_Context(){

                           std::cout << "@ "               << this << endl;
                           std::cout << "  @Arrive_Time  " << this->get_ArriveTime() << std::endl;
     }
     
private :
      TArriveTime     ArriveTime;
 };

}

#endif
