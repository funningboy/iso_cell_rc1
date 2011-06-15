//    ISO_1:
//     Message: Power of isolation control pin can be shut-off while isolation cell is
//     power-on.
//     Description:
//       I. Ensures the isolation control signal is powered ON when the receiving
//            domain is ON.
//       II. Violation of this rule can cause leakage power consumption in the isolation
//            cells.
//       III. Similar to Cadence Conformal Low Power Verify: ISO4

#ifndef _ISO_R5_PASS_H_
#define _ISO_R5_PASS_H_

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


class ISO_R5_Pass {

public :
       typedef std::pair< SC_Module::SC_Port_D*, SC_Module::SC_Port_D*  >     ErrPair;
       typedef std::map<  SC_Module::SC_Port_D*, ErrPair >                    ErrMap;
       typedef std::map<  SC_Module::SC_Port_D*, ErrPair >::iterator          ErrMap_iter; 


public : 
        ISO_R5_Pass(SC_Table  *_sc_table,
                    ISO_Table *_iso_table) : sc_table(_sc_table),
                                             iso_table(_iso_table) {}

       ~ISO_R5_Pass(){
                       Preest_p_Vec.clear();
                       Nxtest_p_Vec.clear();
                       Enable_p_Vec.clear();
       }

public :
       SC_Util     *sc_util;
       ISO_Util    *iso_util;

public :
       void  run_ISO_R5_Trace_Pass();

       void  run_ISO_R5_Ctrl_Pass(SC_Module::SC_Port_D *sc_iso_en_p,
                                  SC_Module::SC_Port_D *sc_pre_p,
                                  SC_Module::SC_Port_D *sc_nxt_p);
 
       void  run_ISO_R5_Rule_Pass(SC_Module::SC_Cell_D *sc_cell,
                                  SC_Module::SC_Port_D *sc_iso_en_p);

       SC_Module::SC_Port_D *run_ISO_R5_Deep_Pass(SC_Module::SC_Port_D *sc_iso_en_p);


public :
       void  run_ISO_R5_AND_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                    SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R5_NAND_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                     SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R5_OR_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                   SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R5_NOR_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                    SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R5_XOR_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                    SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R5_XNOR_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                     SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R5_BUF_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                    SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R5_INV_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                    SC_Module::SC_Port_D *sc_iso_en_p);


public :
       void  run_ISO_R5_AND_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R5_NAND_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R5_OR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R5_NOR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R5_XOR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R5_XNOR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R5_BUF_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R5_INV_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);


public :
       void  run_ISO_R5_Logic_Data_Ctrl_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                      SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R5_Logic_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);


public :
       void   run_ISO_R5_BUF_INV_PreestPassVec(SC_Module::SC_Port_D *sc_port,
                                               SC_Module::PortVec   *port_vec);

      SC_Module::SC_Cell_D  *is_ISO_R5_BUF_INV_Contain(SC_Module::SC_Port_D *sc_port);


public :
       void  set_ISO_R5_ErrMessage(SC_Module::SC_Port_D *sc_en_p,
                                   SC_Module::SC_Port_D *sc_pre_p,
                                   SC_Module::SC_Port_D *sc_nxt_p);

       void  dump_ISO_R5_ErrMessage(ofstream *sc_file);


private :
      
      SC_Table           *sc_table;
      ISO_Table          *iso_table;    

      SC_Module::PortVec  Preest_p_Vec;
      SC_Module::PortVec  Nxtest_p_Vec;

      SC_Module::PortVec  Enable_p_Vec;

      ErrMap              MErrMap; 


      
 };
#endif

