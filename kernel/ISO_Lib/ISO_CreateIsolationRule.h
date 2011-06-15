#ifndef _ISO_CREATE_CREATE_ISOLATION_RULE_H_
#define _ISO_CREATE_CREATE_ISOLATION_RULE_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

using namespace std;

namespace xISOPower {

class ISO_CreateIsolationRule {

public : 
         enum ISO_OUT_HL {
              ISO_OUT_H,
              ISO_OUT_L,
              ISO_OUT_undef,
         }; 


         enum ISO_CONDITION {
              ISO_COND_ON,
              ISO_COND_OFF,
              ISO_COND_undef,
         };

public : 
       typedef   std::pair<ISO_CONDITION,std::string>     ISO_CondPair;
       
public :
        ISO_CreateIsolationRule(){}
       ~ISO_CreateIsolationRule(){}

public :
        void          set_ISO_Name( std::string iso_name ){ ISO_Name = iso_name; }
        std::string   get_ISO_Name(){                       return ISO_Name;     }

public :
       void           set_ISO_From( std::string iso_from ){ ISO_From = iso_from; }
       std::string    get_ISO_From(){                       return ISO_From;     }

public :
       void           set_ISO_To( std::string iso_to ){     ISO_To = iso_to;     }
       std::string    get_ISO_To(){                         return ISO_To;       }

public :
       void           set_ISO_Condition(ISO_CONDITION iso_cond ,std::string iso_cond_nm){  ISO_MCondPair = make_pair(iso_cond,iso_cond_nm); }
       ISO_CondPair   get_ISO_Condition(){                  return ISO_MCondPair;} 

public :
       void           set_ISO_OUT_HL(ISO_OUT_HL iso_hl ){   ISO_Out_Hl = iso_hl; }
       ISO_OUT_HL     get_ISO_OUT_HL(){                     return ISO_Out_Hl;   }


public :
       void dump_Context(){

            std::cout << "ISO_CreateIsolationRule" << std::endl;

            std::cout << "ISO_Name  :: " << this->get_ISO_Name()   << std::endl;
            std::cout << "ISO_From  :: " << this->get_ISO_From()   << std::endl;
            std::cout << "ISO_TO    :: " << this->get_ISO_To()     << std::endl;
            std::cout << "ISO_OUT_HL:: " << this->get_ISO_OUT_HL() << std::endl;
            std::cout << "ISO_Condition :: " << this->get_ISO_Condition().first << " :: " << this->get_ISO_Condition().second << std::endl; 
            std::cout << std::endl;
            std::cout << std::endl;
      }

private :
 
      std::string  ISO_Name;
      std::string  ISO_From;
      std::string  ISO_To;
      ISO_OUT_HL   ISO_Out_Hl; 
      std::pair<ISO_CONDITION,std::string>  ISO_MCondPair;      
 };
}
#endif
