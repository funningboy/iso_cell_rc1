#ifndef _ISO_Domain_PASS_H_
#define _ISO_Domain_PASS_H_

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


class ISO_Domain_Pass {

public : 
        ISO_Domain_Pass(){}
       ~ISO_Domain_Pass(){}

public :
       SC_Util     *sc_util;
       ISO_Util    *iso_util;
       
public :
      void    run_Domain_Verify(SC_Table *sc_table, ISO_Table *iso_table);

      void    run_Domain_Trace(ISO_Table *iso_table, SC_Module *sc_module);
 
      void    run_Domain_Deepest(SC_Module::SC_Cell_D *sc_cell, std::string iso_nm);

      void    run_Domain_AND(SC_Module::SC_Cell_D *sc_cell, std::string iso_nm);

      void    run_Domain_NAND(SC_Module::SC_Cell_D *sc_cell, std::string iso_nm);

      void    run_Domain_OR(SC_Module::SC_Cell_D *sc_cell, std::string iso_nm);

      void    run_Domain_NOR(SC_Module::SC_Cell_D *sc_cell, std::string iso_nm);

      void    run_Domain_XOR(SC_Module::SC_Cell_D *sc_cell, std::string iso_nm);

      void    run_Domain_XNOR(SC_Module::SC_Cell_D *sc_cell, std::string iso_nm);

      void    run_Domain_BUF(SC_Module::SC_Cell_D *sc_cell, std::string iso_nm);

      void    run_Domain_INV(SC_Module::SC_Cell_D *sc_cell, std::string iso_nm);


private :
      std::vector<std::string>  TraceVec;

 };
#endif
