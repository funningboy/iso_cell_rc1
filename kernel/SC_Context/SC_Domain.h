#ifndef _SC_Domain_H_
#define _SC_Domain_H_

#include <iostream>

using namespace std;
using namespace xVerilog;

namespace xVerilog {

class SC_Domain {

public  :
         SC_Domain(){}
        ~SC_Domain(){}

public  :
       void          set_Name(std::string name){  Name = name; }
       std::string   get_Name(){ return Name; }

public  :
        void   dump_Context(){
//               std::cout << "@ "          << this << std::endl;
               std::cout << " @Domain   " << this->get_Name() << std::endl;
        }

private :
      std::string Name; 
 };
}

#endif
