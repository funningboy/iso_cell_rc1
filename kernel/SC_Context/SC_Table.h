#ifndef _SC_TABLE_H_
#define _SC_TABLE_H_

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

#include "kernel/SC_Context/SC_Define.h"
#include "kernel/SC_Context/SC_Module.h"
#include "kernel/SC_Context/SC_Port.h"
#include "kernel/SC_Context/SC_Cell.h"
#include "kernel/SC_Context/SC_Time.h"
#include "kernel/SC_Context/SC_Power.h"
#include "kernel/SC_Context/SC_Logic.h"
#include "kernel/SC_Context/SC_Domain.h"
#include "kernel/SC_Context/SC_Pass.h"
#include "kernel/SC_Context/SC_Type.h"
#include "kernel/SC_Lib/SC_Lib.h"


using namespace std;
using namespace xVerilog;


class SC_Table : public SC_Module {

public:
    typedef  std::map< std::string, SC_Module* >                                   ModuleMap_D;
    typedef  std::map< SC_Module::SC_Port_D*, SC_Module::SC_Port_D* >              O2N_Port_D;
    typedef  std::vector< SC_Cell* >                                               CellVec_D;

    typedef  std::map< std::string, SC_Module* >::iterator                         ModuleMap_iter;
    typedef  std::map< SC_Module::SC_Port_D*, SC_Module::SC_Port_D* >::iterator    O2N_Port_iter;
    typedef  std::vector< SC_Cell* >::iterator                                     CellVec_iter;


public:
      SC_Table(){}

     ~SC_Table(){
              ModuleMap.clear();
              O2N_Port_Map.clear();
              LeafCellVec.clear();
      } 


public:

void                   set_ModuleMap( std::string str, SC_Module *sc_module ){ ModuleMap[str] = sc_module; }

bool                   is_ModuleMap_Contain( std::string str ){ return ModuleMap.find(str) != ModuleMap.end(); } 

SC_Module             *get_ModuleMap( std::string str ){ 

                       if(is_ModuleMap_Contain(str))
                          return ModuleMap[str]; 

                      return NULL;
                      }

ModuleMap_D            get_ModuleMap(){ return ModuleMap; }

void                   clr_ModuleMap(){ ModuleMap.clear(); }


public :

void                   set_O2N_Port(SC_Module::SC_Port_D *sc_port_o, SC_Module::SC_Port_D *sc_port_n){ O2N_Port_Map[sc_port_o] = sc_port_n; }

bool                   is_O2N_Port_Contain(SC_Module::SC_Port_D* sc_port){ return O2N_Port_Map.find(sc_port) != O2N_Port_Map.end(); }


SC_Module::SC_Port_D  *get_O2N_Port(SC_Module::SC_Port_D *sc_port){ 
                     
                       if(is_O2N_Port_Contain(sc_port))
                          return O2N_Port_Map[sc_port]; 

                       return NULL;
                       } 

O2N_Port_D             get_O2N_Port(){ return O2N_Port_Map; } 

void                   clr_O2N_Port(){ O2N_Port_Map.clear(); }


public :

void                   copy_Port_2_New(SC_Module::SC_Port_D *sc_port_o, SC_Module::SC_Port_D *sc_port_n);

void                   copy_Cell_2_New(SC_Module::SC_Cell_D *sc_cell_o, SC_Module::SC_Cell_D *sc_cell_n);

void                   copy_Module_2_New(SC_Module *sc_module_o, SC_Module *sc_module_n);

void                   copy_AND_Logic_2_New(SC_Module::SC_Cell_D* sc_cell_o, SC_Module::SC_Cell_D* sc_cell_n);

void                   copy_NAND_Logic_2_New(SC_Module::SC_Cell_D* sc_cell_o, SC_Module::SC_Cell_D* sc_cell_n);

void                   copy_OR_Logic_2_New(SC_Module::SC_Cell_D* sc_cell_o, SC_Module::SC_Cell_D* sc_cell_n);

void                   copy_NOR_Logic_2_New(SC_Module::SC_Cell_D* sc_cell_o, SC_Module::SC_Cell_D* sc_cell_n);

void                   copy_XOR_Logic_2_New(SC_Module::SC_Cell_D* sc_cell_o, SC_Module::SC_Cell_D* sc_cell_n);

void                   copy_XNOR_Logic_2_New(SC_Module::SC_Cell_D* sc_cell_o, SC_Module::SC_Cell_D* sc_cell_n);

void                   copy_BUF_Logic_2_New(SC_Module::SC_Cell_D* sc_cell_o, SC_Module::SC_Cell_D* sc_cell_n);

void                   copy_INV_Logic_2_New(SC_Module::SC_Cell_D* sc_cell_o, SC_Module::SC_Cell_D* sc_cell_n);


public :               
void                   clr_Template_Context(){
                       //delete Module
                       //delete Cell
                       //delete Port
                       }

public :

void                   set_RootContext(std::string str);

void                   gen_RootContext(SC_Module *sc_module);

SC_Module             *get_RootModule(){ return RootModule; }                      



public :

void                   set_LeafCellVec(SC_Cell *sc_cell){ LeafCellVec.push_back(sc_cell); }

CellVec_D              get_LeafCellVec(){ return LeafCellVec; }                  


public :

void                   set_Root_Boundary(SC_Module *sc_root);

public :

void                   dump_Template_Context();

void                   dump_O2N_Port_Context();

void                   dump_Root_Context(SC_Module *sc_module);



private:     
     std::map< std::string, SC_Module* >  ModuleMap;

     std::map< SC_Module::SC_Port_D*, SC_Module::SC_Port_D* > O2N_Port_Map;  // sc old 2 new port map 

     SC_Module*   RootModule; 

     std::vector< SC_Cell* > LeafCellVec;
};

#endif
