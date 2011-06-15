#ifndef _ISO_CREATE_NOMINAL_CONDITION_H_
#define _ISO_CREATE_NOMINAL_CONDITION_H_

#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

using namespace std;

namespace xISOPower {

class ISO_CreateNominalCondition {

public :
        ISO_CreateNominalCondition(){}
       ~ISO_CreateNominalCondition(){}

public :
       void          set_ISO_Name( std::string iso_name ){ ISO_Name = iso_name; }
       std::string   get_ISO_Name(){                       return ISO_Name;     }

public :
       void          set_ISO_Voltage( float iso_voltage ){ ISO_Voltage = iso_voltage; }            
       float         get_ISO_Voltage(){                    return ISO_Voltage;        }

public :
       void           dump_Context(){

                      std::cout << "ISO_CreateNominalCondition" << std::endl;
                  
                      std::cout << "ISO_Name    :: " << this->get_ISO_Name()    << std::endl;
                      std::cout << "ISO_Voltage :: " << this->get_ISO_Voltage() << std::endl; 
                      std::cout << std::endl;
                      std::cout << std::endl;
       }

private :
 
      std::string      ISO_Name;
      float            ISO_Voltage;
     
 };
}
#endif
