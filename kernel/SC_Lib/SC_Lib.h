#ifndef _SC_LIB_H_
#define _SC_LIB_H_

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

#include "kernel/SC_Context/SC_Define.h"
#include "kernel/SC_Context/SC_Port.h"

#include "kernel/SC_Lib/SC_AND.h"
#include "kernel/SC_Lib/SC_NAND.h"
#include "kernel/SC_Lib/SC_OR.h"
#include "kernel/SC_Lib/SC_NOR.h"
#include "kernel/SC_Lib/SC_XOR.h"
#include "kernel/SC_Lib/SC_XNOR.h"
#include "kernel/SC_Lib/SC_BUF.h"
#include "kernel/SC_Lib/SC_INV.h"


using namespace std;
using namespace xVerilog;

namespace xVerilog {

class SC_LIB : public SC_AND  ,
               public SC_NAND , 
               public SC_OR   ,
               public SC_NOR  ,
               public SC_XOR  ,
               public SC_XNOR ,
               public SC_BUF  ,
               public SC_INV  {

public :
      SC_LIB(){}

      ~SC_LIB(){}

private :

 };
}
#endif
