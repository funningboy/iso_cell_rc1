
#ifndef _ISO_PASS_MANAGER_H_
#define _ISO_PASS_MANAGER_H_

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

#include "kernel/ISO_Pass/ISO_R2_Pass.h"
#include "kernel/ISO_Pass/ISO_R3_Pass.h"
#include "kernel/ISO_Pass/ISO_R4_Pass.h"
#include "kernel/ISO_Pass/ISO_R5_Pass.h"
#include "kernel/ISO_Pass/ISO_Domain_Pass.h"

using namespace std;
using namespace xVerilog;
using namespace xISOPower;


class ISO_Pass_Manager {

public : 
        ISO_Pass_Manager(){}
       ~ISO_Pass_Manager(){}

public :
       SC_Util     *sc_util;
       ISO_Util    *iso_util;

public :
       void set_SC_Table(SC_Table *sc_table){ _sc_table = sc_table; }

       void set_ISO_Table(ISO_Table *iso_table){ _iso_table = iso_table; } 

       void set_Report(ofstream *sc_file){ _sc_file = sc_file; }

public :
       void run_Domain_Explore(){

            ISO_Domain_Pass *iso_d_p = new ISO_Domain_Pass();
                             iso_d_p->run_Domain_Verify(_sc_table,_iso_table);
                             delete iso_d_p;
            }


public :
      void  run_ISO_R2_Verify(){

            ISO_R2_Pass *iso_r2_p = new ISO_R2_Pass(_sc_table,_iso_table);
                         iso_r2_p->run_ISO_R2_Trace_Pass(); 
                         iso_r2_p->dump_ISO_R2_ErrMessage(_sc_file);
                         delete iso_r2_p;
            }

public :
     void   run_ISO_R3_Verify(){

            ISO_R3_Pass *iso_r3_p = new ISO_R3_Pass(_sc_table,_iso_table);
                         iso_r3_p->run_ISO_R3_Trace_Pass(); 
                         iso_r3_p->dump_ISO_R3_ErrMessage(_sc_file);
                         delete iso_r3_p;
            }

public :
     void   run_ISO_R4_Verify(){

            ISO_R4_Pass *iso_r4_p = new ISO_R4_Pass(_sc_table,_iso_table);
                         iso_r4_p->run_ISO_R4_Trace_Pass(); 
                         iso_r4_p->dump_ISO_R4_ErrMessage(_sc_file);
                         delete iso_r4_p;
            }

public :
     void    run_ISO_R5_Verify(){
 
             ISO_R5_Pass *iso_r5_p = new ISO_R5_Pass(_sc_table,_iso_table);
                          iso_r5_p->run_ISO_R5_Trace_Pass(); 
                          iso_r5_p->dump_ISO_R5_ErrMessage(_sc_file);
                          delete iso_r5_p;
             }


private :
      SC_Table    *_sc_table;   
      ISO_Table   *_iso_table;

      ofstream    *_sc_file;
};
#endif
