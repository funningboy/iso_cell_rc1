#ifndef _ISO_DEFINE_ISOLATION_CELL_H_
#define _ISO_DEFINE_ISOLATION_CELL_H_

#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

using namespace std;

namespace xISOPower {

class ISO_DefineIsolationCell {

public : 
         enum ISO_LOCATION {
              ISO_LOC_FROM,
              ISO_LOC_TO,
              ISO_LOC_undef
         };

public :
        ISO_DefineIsolationCell(){}
       ~ISO_DefineIsolationCell(){}

public :
       void          set_ISO_Cell( std::string iso_cell ){ ISO_Cell = iso_cell; }
       std::string   get_ISO_Cell(){                       return ISO_Cell;     }

public :
       void          set_ISO_Enable( std::string iso_enable ){ ISO_Enable = iso_enable; }
       std::string   get_ISO_Enable(){                         return ISO_Enable;       }

public :
       void          set_ISO_Location( ISO_LOCATION iso_location ){ ISO_Location = iso_location; }            
       ISO_LOCATION  get_ISO_Location(){                            return ISO_Location;         }


public :
       void          dump_Context(){

                     std::cout << "ISO_DefineIsolationCell" << std::endl;
                     
                     std::cout << "ISO_Cell       :: " << this->get_ISO_Cell()     << std::endl;
                     std::cout << "ISO_Enable     :: " << this->get_ISO_Enable()   << std::endl;
                     std::cout << "ISO_Location   :: " << this->get_ISO_Location() << std::endl;
       }

private :
 
      std::string      ISO_Cell;
      std::string      ISO_Enable;
      ISO_LOCATION     ISO_Location;
     
 };
}
#endif
