#ifndef _SC_NAND_H_
#define _SC_NAND_H_

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

class SC_NAND {

public :
      typedef  SC_Port< Def_Arrive_Time, Def_Switch_Power >  SC_Port_D;
      typedef  SC_Time< Def_Arrive_Time >                    SC_Time_D;
      typedef  SC_Power< Def_Switch_Power >                  SC_Power_D;
      typedef  SC_Logic                                      SC_Logic_D;
 
public :
      void         set_Src1(SC_Port_D * src1){ Src1 = src1; }
      SC_Port_D   *get_Src1(){ return Src1; }

public :
      void         set_Src2(SC_Port_D * src2){ Src2 = src2; }
      SC_Port_D   *get_Src2(){ return Src2; }

public :
      void         set_Dst(SC_Port_D * dst){ Dst = dst; }
      SC_Port_D   *get_Dst(){ return Dst; }

public :
      void         dump_Context(){

                   std::cout << "@" << this << endl;
                   std::cout << "  @NAND->Src1   " << this->get_Src1() << endl;
                   std::cout << "  @NAND->Src2   " << this->get_Src2() << endl;
                   std::cout << "  @NAND->Dst    " << this->get_Dst()  << endl;

                  }

public : 
      void         run_SC_NAND_Time(){

                   SC_Port_D *src1_p = this->get_Src1();
                   SC_Port_D *src2_p = this->get_Src2();
                   SC_Port_D *dst_p  = this->get_Dst();
          
                   assert( src1_p !=NULL &&
                           src2_p !=NULL &&
                           dst_p  !=NULL && "<Err> SC_OR::run_SC_NAND");

                   SC_Time_D *src1_p_t = dynamic_cast<SC_Time_D*>(src1_p);
                   SC_Time_D *src2_p_t = dynamic_cast<SC_Time_D*>(src2_p);
                   SC_Time_D *dst_p_t  = dynamic_cast<SC_Time_D*>(dst_p);

                   Def_Arrive_Time max_src  = max(src1_p_t->get_ArriveTime(), 
                                                  src2_p_t->get_ArriveTime() );

                                   max_src += atof(Def_NAND_Delay);

                   dst_p_t->set_ArriveTime(max_src);
 
                  }

public :
      void         run_SC_NAND_Logic(){

                   SC_Port_D *src1_p = this->get_Src1();
                   SC_Port_D *src2_p = this->get_Src2();
                   SC_Port_D *dst_p  = this->get_Dst();
          
                   assert( src1_p !=NULL &&
                           src2_p !=NULL &&
                           dst_p  !=NULL && "<Err> SC_NAND::run_SC_NAND");
          
                   SC_Logic::SC_LOGIC first;
                   SC_Logic::SC_LOGIC second;

                   SC_Logic_D *src1_p_l = dynamic_cast<SC_Logic_D*>(src1_p);
                   SC_Logic_D *src2_p_l = dynamic_cast<SC_Logic_D*>(src2_p);
                   SC_Logic_D *dst_p_l  = dynamic_cast<SC_Logic_D*>(dst_p);

                   SC_Time_D *src1_p_t = dynamic_cast<SC_Time_D*>(src1_p);
                   SC_Time_D *src2_p_t = dynamic_cast<SC_Time_D*>(src2_p);

         
                            if( src1_p_t->get_ArriveTime() < src2_p_t->get_ArriveTime() ){ 
                                first  = src1_p_l->get_CurLogic();
                                second = src2_p_l->get_CurLogic();
                                goto TB0; 
                            }
          
                       else if( src1_p_t->get_ArriveTime() < src2_p_t->get_ArriveTime() ){ 
                                first  =  src2_p_l->get_CurLogic();
                                second =  src1_p_l->get_CurLogic();
                                goto TB0;
           
                              }
          
                       else  {  first  =  src2_p_l->get_CurLogic();
                                second =  src1_p_l->get_CurLogic();
                                goto TB1; 
                             }
          
           TB0 : 
          /*  Lookup Table
              F(first)  S(second)  R(result)
              0         0          1 
              0         1          1 
              0         f          1
              0         r          1
              0         x          x
              1         0          1
              1         1          0
              1         f          r 
              1         r          f
              1         x          x
              f         0          1
              f         1          1
              f         f          r
              f         r          1
              f         x          x
              r         0          1
              r         1          0
              r         f          1
              r         r          f
              r         x          x
              x         0          x
              x         1          x
              x         f          x
              x         r          x
              x         x          x  
          */
          
           if( first == SC_Logic::SC_LOGIC_0 && second == SC_Logic::SC_LOGIC_0 ||
               first == SC_Logic::SC_LOGIC_0 && second == SC_Logic::SC_LOGIC_1 || 
               first == SC_Logic::SC_LOGIC_0 && second == SC_Logic::SC_LOGIC_f || 
               first == SC_Logic::SC_LOGIC_0 && second == SC_Logic::SC_LOGIC_r || 
               first == SC_Logic::SC_LOGIC_1 && second == SC_Logic::SC_LOGIC_0 ||
               first == SC_Logic::SC_LOGIC_f && second == SC_Logic::SC_LOGIC_0 ||
               first == SC_Logic::SC_LOGIC_f && second == SC_Logic::SC_LOGIC_1 || 
               first == SC_Logic::SC_LOGIC_f && second == SC_Logic::SC_LOGIC_r ||
               first == SC_Logic::SC_LOGIC_r && second == SC_Logic::SC_LOGIC_0 ||
               first == SC_Logic::SC_LOGIC_r && second == SC_Logic::SC_LOGIC_f ){ dst_p_l->set_CurLogic(SC_Logic::SC_LOGIC_1); return; }
           
           if( first == SC_Logic::SC_LOGIC_1 && second == SC_Logic::SC_LOGIC_1 || 
               first == SC_Logic::SC_LOGIC_r && second == SC_Logic::SC_LOGIC_1 ){ dst_p_l->set_CurLogic(SC_Logic::SC_LOGIC_0); return; }
           
           if( first == SC_Logic::SC_LOGIC_1 && second == SC_Logic::SC_LOGIC_r ||
               first == SC_Logic::SC_LOGIC_r && second == SC_Logic::SC_LOGIC_r ){ dst_p_l->set_CurLogic(SC_Logic::SC_LOGIC_f); return; }
          
           if( first == SC_Logic::SC_LOGIC_1 && second == SC_Logic::SC_LOGIC_f ||
               first == SC_Logic::SC_LOGIC_f && second == SC_Logic::SC_LOGIC_f ){ dst_p_l->set_CurLogic(SC_Logic::SC_LOGIC_r); return; }
           
           if( first == SC_Logic::SC_LOGIC_0 && second == SC_Logic::SC_LOGIC_x || 
               first == SC_Logic::SC_LOGIC_1 && second == SC_Logic::SC_LOGIC_x || 
               first == SC_Logic::SC_LOGIC_r && second == SC_Logic::SC_LOGIC_x || 
               first == SC_Logic::SC_LOGIC_f && second == SC_Logic::SC_LOGIC_x || 
               first == SC_Logic::SC_LOGIC_x && second == SC_Logic::SC_LOGIC_0 || 
               first == SC_Logic::SC_LOGIC_x && second == SC_Logic::SC_LOGIC_1 || 
               first == SC_Logic::SC_LOGIC_x && second == SC_Logic::SC_LOGIC_r || 
               first == SC_Logic::SC_LOGIC_x && second == SC_Logic::SC_LOGIC_f || 
               first == SC_Logic::SC_LOGIC_x && second == SC_Logic::SC_LOGIC_x ){ dst_p_l->set_CurLogic(SC_Logic::SC_LOGIC_x); return; }
          
          
          
          
          
           TB1: 
          /*  Lookup Table
              S(same)  S(same)  R(result)
              0         0          0
              0         1          0 
              0         f          0
              0         r          0
              0         x          x
              1         0          0
              1         1          1
              1         f          f 
              1         r          r
              1         x          x
              f         0          0
              f         1          f
              f         f          f
              f         r          0
              f         x          x
              r         0          0
              r         1          r
              r         f          0
              r         r          r
              r         x          x
              x         0          x
              x         1          x
              x         f          x
              x         r          x
              x         x          x  
          */
          
           if( first == SC_Logic::SC_LOGIC_0 && second == SC_Logic::SC_LOGIC_0 ||
               first == SC_Logic::SC_LOGIC_0 && second == SC_Logic::SC_LOGIC_1 || 
               first == SC_Logic::SC_LOGIC_0 && second == SC_Logic::SC_LOGIC_f || 
               first == SC_Logic::SC_LOGIC_0 && second == SC_Logic::SC_LOGIC_r || 
               first == SC_Logic::SC_LOGIC_1 && second == SC_Logic::SC_LOGIC_0 ||
               first == SC_Logic::SC_LOGIC_f && second == SC_Logic::SC_LOGIC_0 ||
               first == SC_Logic::SC_LOGIC_f && second == SC_Logic::SC_LOGIC_r ||
               first == SC_Logic::SC_LOGIC_r && second == SC_Logic::SC_LOGIC_0 || 
               first == SC_Logic::SC_LOGIC_r && second == SC_Logic::SC_LOGIC_f ){ dst_p_l->set_CurLogic(SC_Logic::SC_LOGIC_1); return; }
           
           if( first == SC_Logic::SC_LOGIC_1 && second == SC_Logic::SC_LOGIC_1 ){ dst_p_l->set_CurLogic(SC_Logic::SC_LOGIC_0); return; }
           
           if( first == SC_Logic::SC_LOGIC_1 && second == SC_Logic::SC_LOGIC_r ||
               first == SC_Logic::SC_LOGIC_r && second == SC_Logic::SC_LOGIC_1 ||
               first == SC_Logic::SC_LOGIC_r && second == SC_Logic::SC_LOGIC_r ){ dst_p_l->set_CurLogic(SC_Logic::SC_LOGIC_f); return; }
          
           if( first == SC_Logic::SC_LOGIC_1 && second == SC_Logic::SC_LOGIC_f ||
               first == SC_Logic::SC_LOGIC_f && second == SC_Logic::SC_LOGIC_1 || 
               first == SC_Logic::SC_LOGIC_f && second == SC_Logic::SC_LOGIC_f ){ dst_p_l->set_CurLogic(SC_Logic::SC_LOGIC_r); return; }
          
           if( first == SC_Logic::SC_LOGIC_0 && second == SC_Logic::SC_LOGIC_x || 
               first == SC_Logic::SC_LOGIC_1 && second == SC_Logic::SC_LOGIC_x || 
               first == SC_Logic::SC_LOGIC_f && second == SC_Logic::SC_LOGIC_x || 
               first == SC_Logic::SC_LOGIC_r && second == SC_Logic::SC_LOGIC_x || 
               first == SC_Logic::SC_LOGIC_x && second == SC_Logic::SC_LOGIC_0 || 
               first == SC_Logic::SC_LOGIC_x && second == SC_Logic::SC_LOGIC_1 || 
               first == SC_Logic::SC_LOGIC_x && second == SC_Logic::SC_LOGIC_f || 
               first == SC_Logic::SC_LOGIC_x && second == SC_Logic::SC_LOGIC_r || 
               first == SC_Logic::SC_LOGIC_x && second == SC_Logic::SC_LOGIC_x ){ dst_p_l->set_CurLogic(SC_Logic::SC_LOGIC_x); return; }
          
     }



private :
      SC_Port_D *Src1;
      SC_Port_D *Src2;                
      SC_Port_D *Dst;

  };
}

#endif
