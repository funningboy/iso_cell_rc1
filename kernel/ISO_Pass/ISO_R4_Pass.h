// ISO_4:
//  Message: Power domain crossing does not have user-defined isolation cell.
//  Description:
//   I. Report error when there is an OFF-ON/ON-OFF crossing between two power
//        domains that does not have a user-defined isolation cell.
//   II. Netlist bug can cause tape-out failure.
//   III. Similar to Cadence Conformal Low Power Verify: ISO7


#ifndef _ISO_R4_PASS_H_
#define _ISO_R4_PASS_H_

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

#include "kernel/SC_Context/SC_Table.h"
#include "kernel/SC_Context/SC_Util.h"

#include "kernel/ISO_Context/ISO_Table.h"
#include "kernel/ISO_Context/ISO_Util.h"

using namespace std;
using namespace xVerilog;
using namespace xISOPower;


class ISO_R4_Pass {

public :
       typedef std::pair  < SC_Module::SC_Port_D*, SC_Module::SC_Port_D* >    ErrPair;
       typedef std::vector< ErrPair >                                         ErrVec;
       typedef std::map< std::string, ErrVec >                                ErrMap;
       typedef std::vector< ErrPair >::iterator                               ErrVec_iter;
       typedef std::map< std::string, ErrVec >::iterator                      ErrMap_iter;


public : 
        ISO_R4_Pass(SC_Table  *_sc_table,
                    ISO_Table *_iso_table) : sc_table(_sc_table),
                                             iso_table(_iso_table) {}

       ~ISO_R4_Pass(){
                      MErrMap.clear();
        }

public :
       SC_Util     *sc_util;
       ISO_Util    *iso_util;

public :

       void  run_ISO_R4_Trace_Pass();

       void  run_ISO_R4_AND_Data_PrePass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R4_NAND_Data_PrePass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R4_OR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R4_NOR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R4_XOR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R4_XNOR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R4_BUF_Data_PrePass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R4_INV_Data_PrePass(SC_Module::SC_Cell_D *sc_cell);


       void  run_ISO_R4_Logic_Data_PrePass(SC_Module::SC_Cell_D *sc_cell);

       std::string  run_ISO_R4_ISO_Pass(SC_Module::SC_Port_D *sc_preest_p,
                                        SC_Module::SC_Port_D *sc_port);

       void  set_ISO_R4_ErrMessage(SC_Module::SC_Port_D *sc_preest_p,
                                   SC_Module::SC_Port_D *sc_port,
                                   std::string sc_rule_nm);

       void  run_ISO_R4_BUF_NxtestVec(SC_Module::SC_Port_D *sc_port,
                                      std::string  sc_domain_nm,
                                      SC_Module::PortVec *port_vec);

       void  run_ISO_R4_BUF_PreestVec(SC_Module::SC_Port_D *sc_port,
                                      std::string  sc_domain_nm,
                                      SC_Module::PortVec *port_vec);

       void  run_ISO_R4_Check_Pass(SC_Module::SC_Port_D *sc_preest_p,
                                   SC_Module::SC_Port_D *sc_port);

       bool  run_ISO_R4_Rule_Pass(SC_Module::SC_Port_D *sc_preest_p,
                                  SC_Module::SC_Port_D *sc_port);

       SC_Module::SC_Cell_D *is_ISO_R4_BUF_Contain(SC_Module::SC_Port_D *sc_preest_p,
                                                   std::string sc_domain_nm);


       
       void  dump_ISO_R4_ErrMessage(ofstream *sc_file);

private :
      
      SC_Table    *sc_table;
      ISO_Table   *iso_table;    

      ErrMap       MErrMap;
 };
#endif
