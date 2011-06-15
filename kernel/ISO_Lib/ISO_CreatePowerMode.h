#ifndef _ISO_CREATE_POWER_MODE_H_
#define _ISO_CREATE_POWER_MODE_H_

#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

using namespace std;

namespace xISOPower {

class ISO_CreatePowerMode {

public : 
       typedef std::map< std::string, std::string >           DomainCondMap;
       typedef std::map< std::string, std::string >::iterator DomainCondMap_iter;
         
public :
        ISO_CreatePowerMode(){}
       ~ISO_CreatePowerMode(){}

public :
       void          set_ISO_Name( std::string iso_name ){ ISO_Name = iso_name; }
       std::string   get_ISO_Name(){                       return ISO_Name;     }

public :
       void          set_ISO_DomainCondition( DomainCondMap iso_domain_condition ){ ISO_DomainCondMap = iso_domain_condition; }       
       void          set_ISO_DomainCondition( std::string iso_domain, std::string iso_condition ){ ISO_DomainCondMap[iso_domain] = iso_condition; }       
       std::string   get_ISO_DomainCondition( std::string iso_domain ){                            return ISO_DomainCondMap[iso_domain];          }
       DomainCondMap get_ISO_DomainCondition(){ return ISO_DomainCondMap; }

public : 
       void          set_ISO_Default( bool iso_default ){ ISO_Default = iso_default; }
       bool          get_ISO_Default(){                   return ISO_Default;        }


public :
      void          dump_Context(){
                  
                    std::cout  << "ISO_CreatePowerMode" << std::endl;
  
                    std::cout << "ISO_Name            :: " << this->get_ISO_Name()           << std::endl;
                    std::cout << "ISO_Default         :: " << this->get_ISO_Default()        << std::endl; 

                    DomainCondMap dm_mm = this->get_ISO_DomainCondition();

                    for(DomainCondMap_iter dm_it  = dm_mm.begin();
                                           dm_it != dm_mm.end();  ++dm_it){

                    std::cout << "ISO_Domain :: " << dm_it->first << " ISO_Condition :: " << dm_it->second << std::endl;

                    }
      }

private :
 
      std::string      ISO_Name;
      DomainCondMap    ISO_DomainCondMap;
      bool             ISO_Default;     
 };
}
#endif
