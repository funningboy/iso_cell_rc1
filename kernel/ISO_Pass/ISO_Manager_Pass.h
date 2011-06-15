#ifndef _ISO_Manager_PASS_H_
#define _ISO_Manager_PASS_H_

#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

#include "kernel/SC_Context/SC_Table.h"
#include "kernel/SC_Context/SC_Util.h"
#include "kernel/SC_Context/SC_Module.h"

#include "kernel/ISO_Context/ISO_Table.h"
#include "kernel/ISO_Context/ISO_Util.h"

using namespace std;
using namespace xVerilog;
using namespace xISOPower;


class ISO_Manager_Pass {


public : 
        ISO_Manager_Pass(){}
       ~ISO_Manager_Pass(){}

public :
       SC_Util     *sc_util;
       ISO_Util    *iso_util;
       
public :
      void set_SC_Table(SC_Table *sc_table){ mSC_Table = sc_table; }

      void set_ISO_Table(ISO_Table *iso_table){ mISO_Table = iso_table; }

      void set_Root(std::string root ){ Root = root; }

      void set_Report(std::string report){ Report = report; }


public :
      void run_Domain_Verify();

//      void run_ISO_R1_Verify();
//      void run_ISO_R5_Verify();


private :
      SC_Table    *mSC_Table;
      ISO_Table   *mISO_Table;
    
      std::string  Root;
      std::string  Report;
  };
#endif
