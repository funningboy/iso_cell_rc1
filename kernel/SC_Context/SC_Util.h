
#ifndef _SC_UTIL_H_
#define _SC_UTIL_H_

#include <iostream>
#include <sstream>
#include <algorithm>

#include <vector>
#include <map>
#include <utility>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "kernel/SC_Context/SC_Define.h"
#include "kernel/SC_Context/SC_Table.h"
#include "kernel/SC_Context/SC_Module.h"
#include "kernel/SC_Context/SC_Port.h"
#include "kernel/SC_Lib/SC_Lib.h"

#include <boost/algorithm/string.hpp>


using namespace std;
using namespace xVerilog;

namespace xVerilog {

class SC_Module;

class SC_Util {

    typedef  std::vector< SC_Module* >                                             ModuleVec;
    typedef  std::vector< SC_Module* >::iterator                                   ModuleVec_iter;


public :
      SC_Util(){}
     ~SC_Util(){}

public :

     // @ SC_Port
     void          get_NxtestVec(SC_Module::SC_Port_D *sc_port,
                                 SC_Module::PortVec *port_vec);

     
     void          get_NxtOutputVec(SC_Module::SC_Port_D *sc_port,
                                    SC_Module::PortVec *port_vec);

     
     void          get_NxtInputVec(SC_Module::SC_Port_D *sc_port,
                                   SC_Module::PortVec *port_vec);

     
     void          get_PreestVec(SC_Module::SC_Port_D *sc_port,
                                 SC_Module::PortVec *port_vec);

     
     void          get_PreOutputVec(SC_Module::SC_Port_D *sc_port,
                                    SC_Module::PortVec *port_vec);

     
     void          get_PreInputVec(SC_Module::SC_Port_D *sc_port,
                                   SC_Module::PortVec *port_vec);
     
     
     bool          is_Nxtest_Connect(SC_Module::SC_Port_D *sc_p_1,
                                     SC_Module::SC_Port_D *sc_p_2);

     
     bool          is_Preest_Connect(SC_Module::SC_Port_D *sc_p_1,
                                     SC_Module::SC_Port_D *sc_p_2);

     
     // @ SC_Module
     void          get_NxtestVec(SC_Module *sc_module,
                                 ModuleVec *module_vec);

     
     bool          is_Nxtest_Connect(SC_Module *sc_m_1,
                                     SC_Module *sc_m_2);


     bool          is_Preest_Connect(SC_Module *sc_m_1,
                                     SC_Module *sc_m_2);


     SC_Module::SC_Port_D  *split_path_2_Port(SC_Module *sc_module,
                                              std::string path);


     void          get_AND_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                      SC_Module::SC_Port_D *sc_port,
                                      SC_Module::PortVec *port_vec);

     void          get_NAND_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                       SC_Module::SC_Port_D *sc_port,
                                       SC_Module::PortVec *port_vec);

     void          get_OR_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                     SC_Module::SC_Port_D *sc_port,
                                     SC_Module::PortVec *port_vec);

     void          get_NOR_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                      SC_Module::SC_Port_D *sc_port,
                                      SC_Module::PortVec *port_vec);

     void          get_XOR_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                      SC_Module::SC_Port_D *sc_port,
                                      SC_Module::PortVec *port_vec);

     void          get_XNOR_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                       SC_Module::SC_Port_D *sc_port,
                                       SC_Module::PortVec *port_vec);

     void          get_BUF_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                      SC_Module::SC_Port_D *sc_port,
                                      SC_Module::PortVec *port_vec);

     void          get_INV_PrePassVec(SC_Module::SC_Cell_D *sc_cell,
                                      SC_Module::SC_Port_D *sc_port,
                                      SC_Module::PortVec *port_vec);

     void          get_AND_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                      SC_Module::SC_Port_D *sc_port,
                                      SC_Module::PortVec *port_vec);

     void          get_NAND_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                       SC_Module::SC_Port_D *sc_port,
                                       SC_Module::PortVec *port_vec);

     void          get_OR_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                     SC_Module::SC_Port_D *sc_port,
                                     SC_Module::PortVec *port_vec);

     void          get_NOR_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                      SC_Module::SC_Port_D *sc_port,
                                      SC_Module::PortVec *port_vec);

     void          get_XOR_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                      SC_Module::SC_Port_D *sc_port,
                                      SC_Module::PortVec *port_vec);

     void          get_XNOR_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                       SC_Module::SC_Port_D *sc_port,
                                       SC_Module::PortVec *port_vec);

     void          get_BUF_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                      SC_Module::SC_Port_D *sc_port,
                                      SC_Module::PortVec *port_vec);

     void          get_INV_NxtPassVec(SC_Module::SC_Cell_D *sc_cell,
                                      SC_Module::SC_Port_D *sc_port,
                                      SC_Module::PortVec *port_vec);



     void          get_PrePassVec(SC_Module::SC_Port_D *sc_port,
                                  SC_Module::PortVec *port_vec);


     void          get_PreestPassVec(SC_Module::SC_Port_D *sc_port,
                                     SC_Module::PortVec *port_vec);


     void          get_NxtPassVec(SC_Module::SC_Port_D *sc_port,
                                  SC_Module::PortVec *port_vec);


     void          get_NxtestPassVec(SC_Module::SC_Port_D *sc_port,
                                     SC_Module::PortVec *port_vec);


     bool          is_Deepest_Module(SC_Module::SC_Cell_D *sc_cell);
 
         
     // @
     std::string   get_HierarchyName(SC_Module::SC_Port_D *sc_port);

     std::string   get_HierarchyName(SC_Module::SC_Cell_D *sc_cell);

     std::string   get_HierarchyName(SC_Module *sc_module);

//      int          get_HierarchySize(std::string iso_nm); 
//
//      HierVec      get_HierarchyVec(std::string iso_nm); 
//
//      std::string  get_HierarchyName(std::vector<std::string> vec);


private: 

 };  
}
#endif

