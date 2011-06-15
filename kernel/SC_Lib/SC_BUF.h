#ifndef _SC_BUF_H_
#define _SC_BUF_H_

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

#include "kernel/SC_Context/SC_Define.h"
#include "kernel/SC_Context/SC_Port.h"
#include "kernel/SC_Context/SC_Time.h"
#include "kernel/SC_Context/SC_Power.h"
#include "kernel/SC_Context/SC_Logic.h"

using namespace std;
using namespace xVerilog;

namespace xVerilog {

class SC_BUF {

public :
      typedef  SC_Port< Def_Arrive_Time, Def_Switch_Power >  SC_Port_D;
      typedef  SC_Time< Def_Arrive_Time >                    SC_Time_D;
      typedef  SC_Power< Def_Switch_Power >                  SC_Power_D;
      typedef  SC_Logic                                      SC_Logic_D;
 
public :
      SC_BUF(){}

     ~SC_BUF(){}


public :
      void         set_Src(SC_Port_D * src){ Src = src; }
      SC_Port_D   *get_Src(){ return Src; }


public :
      void         set_Dst(SC_Port_D * dst){ Dst = dst; }
      SC_Port_D   *get_Dst(){ return Dst; }

public :
      void         dump_Context(){

                   std::cout << "@" << this << endl;
                   std::cout << "  @BUF->Src    " << this->get_Src() << endl;
                   std::cout << "  @BUF->Dst    " << this->get_Dst()  << endl;

                   }

public :
      void         run_SC_BUF_Time(){

                   SC_Port_D *src_p  = this->get_Src();
                   SC_Port_D *dst_p  = this->get_Dst();
          
                   assert( src_p  !=NULL &&
                           dst_p  !=NULL && "<Err> SC_OR::run_SC_BUF");

                   SC_Time_D *src_p_t  = dynamic_cast<SC_Time_D*>(src_p);
                   SC_Time_D *dst_p_t  = dynamic_cast<SC_Time_D*>(dst_p);

                   Def_Arrive_Time max_src  =src_p_t->get_ArriveTime(); 

                                   max_src += atof(Def_BUF_Delay);

                   dst_p_t->set_ArriveTime(max_src);

                  }

public :
      void         run_SC_BUF_Logic(){

                   SC_Port_D *src_p = this->get_Src();
                   SC_Port_D *dst_p = this->get_Dst();
         
                   assert( src_p !=NULL &&
                           dst_p !=NULL && "<Err> SC_BUF::run_SC_BUF");

 
                   SC_Logic_D *src_p_l = dynamic_cast<SC_Logic_D*>(src_p);
                   SC_Logic_D *dst_p_l = dynamic_cast<SC_Logic_D*>(dst_p);
          
                   goto TB0; 
         
           TB0 : 
          //  Lookup Table
          //    F(first)    R(result)
          //    0           0
          //    1           1 
          //    f           f
          //    r           r
          //    x           x
          //
          
          dst_p_l->set_CurLogic( src_p_l->get_CurLogic() ); 
         
          return;
     }


private :
      SC_Port_D *Src;                
      SC_Port_D *Dst;

  };


}
#endif
