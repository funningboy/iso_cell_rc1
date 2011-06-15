#ifndef _SC_Pass_H_
#define _SC_Pass_H_

#include <iostream>

using namespace std;

namespace xVerilog {

class SC_Pass {

public  :
         SC_Pass(){}
        ~SC_Pass(){}

public  :
       void          set_Pass(bool pass){  Pass = pass; }
       bool          get_Pass(){ return Pass; }

public  :
        void   dump_Context(){
//               std::cout << "@ "        << this << std::endl;
               std::cout << " @Pass   " << this->get_Pass() << std::endl;
        }

private :
      bool  Pass; 
 };
}

#endif
