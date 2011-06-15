
#ifndef _ISO_UTIL_H_
#define _ISO_UTIL_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <sstream>

#include <boost/algorithm/string.hpp>

#include "kernel/ISO_Lib/ISO_CreateIsolationRule.h"
#include "kernel/ISO_Lib/ISO_CreateNominalCondition.h"
#include "kernel/ISO_Lib/ISO_CreatePowerDomain.h"
#include "kernel/ISO_Lib/ISO_CreatePowerMode.h"
#include "kernel/ISO_Lib/ISO_DefineIsolationCell.h"
#include "kernel/ISO_Context/ISO_Table.h"

using namespace std;
using namespace xISOPower;

namespace xISOPower {

class ISO_Table;

class ISO_Util {

public :
       typedef std::vector<std::string>                    StrVec;
       typedef std::vector<std::string>::iterator          StrVec_iter;
       typedef std::map<std::string, StrVec>               ModeMap;
       typedef std::map<std::string, StrVec>::iterator     ModeMap_iter;           

public :

      ISO_Util(){}
     ~ISO_Util(){}

public :

      int          get_HierarchySize(std::string iso_nm); 

      StrVec      get_HierarchyVec(std::string iso_nm); 

      std::string  get_HierarchyName(std::vector<std::string> vec);

       bool                    is_ISO_Cell_Contain(ISO_Table *iso_table, 
                                                   std::string iso_cell);

       bool                    is_ISO_Cell_Enable_Contain(ISO_Table *iso_table,
                                                          std::string iso_cell,
                                                          std::string iso_enable);

      std::string              get_ISO_Cell_Enable(ISO_Table *iso_table,
                                                   std::string iso_cell);

      ISO_DefineIsolationCell::ISO_LOCATION   get_ISO_Cell_Location(ISO_Table *iso_table,
                                                                    std::string iso_cell);
 

      std::string              get_ISO_Instance_Domain(ISO_Table *iso_table,
                                                       std::string iso_nm);

      std::string              get_ISO_BoundaryPort_Domain(ISO_Table *iso_table,
                                                           std::string iso_nm);

      std::string              get_ISO_Rule_Name(ISO_Table *iso_table,
                                                 std::string from,
                                                 std::string to);


      ISO_CreateIsolationRule::ISO_CondPair   get_ISO_Rule_Condition(ISO_Table *iso_table,
                                                     std::string from,
                                                     std::string to);


      ModeMap              get_ISO_Mode_Names(ISO_Table *iso_table,
                                                 std::string from,
                                                 std::string to);


     float                 get_ISO_Condition_Voltage(ISO_Table *iso_table,
                                                     std::string condition);     

private :

 };
} 
#endif
