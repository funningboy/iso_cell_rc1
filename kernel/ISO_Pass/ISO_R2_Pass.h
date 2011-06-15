//. ISO_2:
//Message: Source and destination domains of the isolation cells are the same.
//Description:
//I. This rule can find redundant isolation cells in the netlist.
//II. Similar to Cadence Conformal Low Power Verify: ISO3.2

#ifndef _ISO_R2_PASS_H_
#define _ISO_R2_PASS_H_

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


class ISO_R2_Pass {

public :
       typedef std::pair< SC_Module::SC_Port_D*, SC_Module::SC_Port_D* >   ErrPair;
       typedef std::map< SC_Module::SC_Cell_D*, ErrPair >                  ErrMap;
       typedef std::map< SC_Module::SC_Cell_D*, ErrPair >::iterator        ErrMap_iter;  


public : 
        ISO_R2_Pass(SC_Table  *_sc_table,
                    ISO_Table *_iso_table) : sc_table(_sc_table),
                                             iso_table(_iso_table) {}

       ~ISO_R2_Pass(){
                       Preest_p_Vec.clear();
                       Nxtest_p_Vec.clear();
                
                       MErrMap.clear();
       }

public :
       SC_Util     *sc_util;
       ISO_Util    *iso_util;

public :

       void  run_ISO_R2_Trace_Pass();

       void  run_ISO_R2_Rule_Pass(SC_Module::SC_Cell_D *sc_cell);

       SC_Module::SC_Port_D *run_ISO_R2_Deep_Pass(SC_Module::SC_Port_D *sc_iso_en_p);
 

public :
       void  run_ISO_R2_AND_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                         SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R2_NAND_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                          SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R2_OR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                        SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R2_NOR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                         SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R2_XOR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                         SC_Module::SC_Port_D *sc_iso_en_p);
 
       void  run_ISO_R2_XNOR_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                          SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R2_BUF_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                         SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R2_INV_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                         SC_Module::SC_Port_D *sc_iso_en_p);


public :
       void  run_ISO_R2_AND_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R2_NAND_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R2_OR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R2_NOR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R2_XOR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R2_XNOR_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R2_BUF_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);

       void  run_ISO_R2_INV_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);


public :
       void  run_ISO_R2_Logic_Data_PrePass(SC_Module::SC_Cell_D *sc_cell,
                                           SC_Module::SC_Port_D *sc_iso_en_p);

       void  run_ISO_R2_Logic_Data_NxtPass(SC_Module::SC_Cell_D *sc_cell);


public :
       void  set_ISO_R2_ErrMessage(SC_Module::SC_Port_D *sc_pre_p,
                                   SC_Module::SC_Port_D *sc_nxt_p,
                                   SC_Module::SC_Cell_D *sc_cell);


      void  dump_ISO_R2_ErrMessage(ofstream *sc_file);



private :
      
      SC_Table           *sc_table;
      ISO_Table          *iso_table;    

      SC_Module::PortVec  Preest_p_Vec;
      SC_Module::PortVec  Nxtest_p_Vec;

      ErrMap              MErrMap;
 };
#endif
