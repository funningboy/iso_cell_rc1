
#ifndef _ISO_CREATE_POWER_DOMAIN_H_
#define _ISO_CREATE_POWER_DOMAIN_H_

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

using namespace std;

namespace xISOPower {

class ISO_CreatePowerDomain {

public :
       typedef std::vector<std::string>             ISOVec;
       typedef std::vector<std::string>::iterator   ISOVec_iter;

public :
      ISO_CreatePowerDomain(){}
     ~ISO_CreatePowerDomain(){
                               ISO_Instances.clear();
                               ISO_BoundaryPorts.clear();
      }

public :
       void        set_ISO_Instances( ISOVec iso_instance_vv){ ISO_Instances = iso_instance_vv;       }
       void        set_ISO_Instances( std::string iso_instance ){ ISO_Instances.push_back(iso_instance); }
       ISOVec   get_ISO_Instances(){                           return ISO_Instances;                  }

public :
       void        set_ISO_BoundaryPorts( ISOVec iso_boundary_vv ){     ISO_BoundaryPorts = iso_boundary_vv;            }
       void        set_ISO_BoundaryPorts( std::string iso_boundary_port ){ ISO_BoundaryPorts.push_back(iso_boundary_port); }
       ISOVec   get_ISO_BoundaryPorts(){                                return ISO_BoundaryPorts;                       }

public :
       void        set_ISO_Name( std::string iso_name ){ ISO_Name = iso_name; }
       std::string get_ISO_Name(){                       return ISO_Name;     }

public :
       void        set_ISO_Default( bool iso_default ){ ISO_Default = iso_default; }
       bool        get_ISO_Default(){ return ISO_Default; }


public :
       void        dump_Context(){
                   
                   std::cout << "ISO_CreatePowerDomain" << std::endl;
                   std::cout << "ISO_Name     :: " << this->get_ISO_Name()    << std::endl;
                   std::cout << "ISO_Default  :: " << this->get_ISO_Default() << std::endl;
                 
                   std::cout << "ISO_Boundary_Ports   " << std::endl;                   

                   ISOVec boundary_port_vv = this->get_ISO_BoundaryPorts();

                   for(ISOVec_iter it  = boundary_port_vv.begin();
                                    it != boundary_port_vv.end();   ++it){

                   std::cout << "ISO_Boundary_port :: " << (*it) << std::endl;
                   }


                   std::cout << "ISO_Instances        " << std::endl;                   

                   ISOVec instance_vv = this->get_ISO_Instances();

                   for(ISOVec_iter it  = instance_vv.begin();
                                    it != instance_vv.end();   ++it){

                   std::cout << "ISO_Instance    :: " << (*it) << std::endl;
                   }
 
                   std::cout << std::endl;
                   std::cout << std::endl;
       }   


private :
 
      ISOVec    ISO_Instances;
      ISOVec    ISO_BoundaryPorts;
      std::string  ISO_Name; 
      bool         ISO_Default;       
 };
}
#endif
