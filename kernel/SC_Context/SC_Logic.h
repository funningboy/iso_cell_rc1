#ifndef _SC_LOGIC_H_
#define _SC_LOGIC_H_

#include <iostream>

using namespace std;

namespace xVerilog {

class SC_Logic {

public :
      enum SC_LOGIC {
           SC_LOGIC_0,      // 0
           SC_LOGIC_1,      // 1
           SC_LOGIC_x,      // x
           SC_LOGIC_r,      // r
           SC_LOGIC_f,      // f
           SC_LOGIC_undef
       };

public :
      SC_Logic(){}
     ~SC_Logic(){}


public:
      void        set_PreLogic( SC_LOGIC pre_logic ){ PreLogic = pre_logic; }
      SC_LOGIC    get_PreLogic(){ return PreLogic; }  


public:
      void        set_CurLogic( SC_LOGIC cur_logic ){ CurLogic = cur_logic; }
      SC_LOGIC    get_CurLogic(){ return CurLogic; }  


public :
     void                  dump_Context(){

                           std::cout << "@ "                << this << endl;
                           std::cout << "   @PreLogic     " << this->get_PreLogic()    << std::endl;
                           std::cout << "   @CurLogic     " << this->get_CurLogic()    << std::endl;
     }
     


private :
      SC_LOGIC        PreLogic;
      SC_LOGIC        CurLogic;       

 };
}

#endif
