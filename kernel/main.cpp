
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

#include "kernel/SC_Context/SC_Module.h"
#include "kernel/SC_Context/SC_Port.h"
#include "kernel/SC_Context/SC_Cell.h"
#include "kernel/SC_Context/SC_Table.h"
#include "kernel/SC_Context/SC_Util.h"
#include "kernel/SC_Context/SC_Signal.h"
#include "kernel/SC_Context/SC_Define.h"
#include "kernel/ISO_Context/ISO_Table.h"
#include "kernel/ISO_Context/ISO_Util.h"
#include "kernel/ISO_Pass/ISO_Pass_Manager.h"

extern int          SC_parse();
extern int          ISO_parse();
extern FILE        *SC_in;
extern FILE        *ISO_in;
 
extern ISO_Table   *t_iso_table;
extern SC_Table    *t_sc_table;

using namespace std;
using namespace xVerilog;
using namespace xISOPower;



void dump_help_message(){

std::cout << "<Usage>"                                                 << std::endl;
std::cout << "./ISO_Pass -design           <design_file_list>      \\" << std::endl;
std::cout << "           -library          <library_file_list>     \\" << std::endl;
std::cout << "           -root             <top_module_name>       \\" << std::endl;
std::cout << "           -power_intent     <power_spec_filename>   \\" << std::endl;
std::cout << "           -report           <report_file_name>        " << std::endl;
std::cout << std::endl;
std::cout << std::endl;

std::cout << "<Example>"                                               << std::endl;
std::cout << "./ISO_Pass -design           top.v                   \\" << std::endl;
std::cout << "           -library          lib.v                   \\" << std::endl;
std::cout << "           -root             top                     \\" << std::endl;
std::cout << "           -power_intent     top.pi                  \\" << std::endl;
std::cout << "           -report           rpt.log                   " << std::endl;

}




int main(int argc,char *argv[]){

    enum Def_State {
         Def_Design,
         Def_Library,
         Def_Root,
         Def_PowerIntent,
         Def_Report,
         Def_undef
    };

    std::string                             argv_str;   
    std::string                             glRoot;
    std::string                             glReport;
    std::string                             glPowerIntent;
    std::string                             glCommd;

    Def_State                               Def_Cur;
    Def_State                               Def_Pre;

    std::vector<std::string>                glDesign_vv;
    std::vector<std::string>                glLibrary_vv;

typedef std::vector<std::string>::iterator  vv_iter;


    int i=1;
    while( i<argc ){
         argv_str = argv[i];

          if( argv_str.compare("-design")       ==0 ){  ++i;  Def_Cur = Def_Design;      }
     else if( argv_str.compare("-library")      ==0 ){  ++i;  Def_Cur = Def_Library;     }
     else if( argv_str.compare("-root")         ==0 ){  ++i;  Def_Cur = Def_Root;        }
     else if( argv_str.compare("-power_intent") ==0 ){  ++i;  Def_Cur = Def_PowerIntent; }
     else if( argv_str.compare("-report")       ==0 ){  ++i;  Def_Cur = Def_Report;      }  
     else {                                                   Def_Cur = Def_Pre;         }

     assert( i<argc && "main->menu");

     switch(Def_Cur){ 
       case Def_Design      :   glDesign_vv.push_back(argv[i]);   break; 
       case Def_Library     :   glLibrary_vv.push_back(argv[i]);  break;   
       case Def_PowerIntent :   glPowerIntent = argv[i];          break; 
       case Def_Root        :   glRoot        = argv[i];          break; 
       case Def_Report      :   glReport      = argv[i];          break; 
      } 

     i++;
     Def_Pre = Def_Cur;
    }
    
    if( glDesign_vv.empty()   || 
        glLibrary_vv.empty()  || 
        glPowerIntent.empty() || 
        glRoot.empty()        || 
        glReport.empty()      ){ dump_help_message();  return 0; } 


     glCommd = "echo \"<Library>\" >> _i_top_.v";
     assert( system(glCommd.c_str()) == 0 && "main->cat" );
 
     for(vv_iter vv_ir  = glLibrary_vv.begin();
                 vv_ir != glLibrary_vv.end();  ++vv_ir){

                glCommd = "cat " + (*vv_ir) + " >> _i_top_.v";                  
                assert( system(glCommd.c_str()) ==0 && "main->cat" ); 
     }

     glCommd = "echo \"</Library>\" >> _i_top_.v";
     assert( system(glCommd.c_str()) == 0 && "main->cat" );



     glCommd = "echo \"<Design>\" >> _i_top_.v";
     assert( system(glCommd.c_str()) == 0 && "main->cat" );

     for(vv_iter vv_ir  = glDesign_vv.begin();
                 vv_ir != glDesign_vv.end();  ++vv_ir){

               glCommd = "cat " + (*vv_ir) + " >> _i_top_.v";                  
               assert( system(glCommd.c_str()) ==0 && "main->cat" ); 
     }

     glCommd = "echo \"</Design>\" >> _i_top_.v";
     assert( system(glCommd.c_str()) == 0 && "main->cat" );


   FILE *sc_fp = fopen("_i_top_.v","r");
   assert( sc_fp != NULL && "couldn't open file for reading");

   SC_in  = sc_fp;   
   SC_parse();   
   fclose(sc_fp);

   glCommd = "rm _i_top_.v";
   assert( system(glCommd.c_str()) == 0 && "main->rm");


   FILE *iso_fp = fopen(glPowerIntent.c_str(),"r");
   assert( iso_fp != NULL && "couldn't open file for reading");

   ISO_in = iso_fp;  
   ISO_parse();     
   fclose(iso_fp);



#ifdef SC_Debug
  t_sc_table->dump_Template_Context();
#endif

 
   t_sc_table->set_RootContext(glRoot);


#ifdef SC_Debug
 SC_Module *sc_root = t_sc_table->get_RootModule();
 t_sc_table->dump_Root_Context(sc_root);
#endif


  ofstream t_sc_file;
  t_sc_file.open(glReport.c_str());


 ISO_Pass_Manager *t_pass_man = new ISO_Pass_Manager();

                   t_pass_man->set_SC_Table(t_sc_table);
                   t_pass_man->set_ISO_Table(t_iso_table);
                   t_pass_man->set_Report(&t_sc_file);
     
                   t_pass_man->run_Domain_Explore();
     
                   t_pass_man->run_ISO_R2_Verify();
                   t_pass_man->run_ISO_R3_Verify();
                   t_pass_man->run_ISO_R4_Verify();
                   t_pass_man->run_ISO_R5_Verify();

t_sc_file.close();

delete t_pass_man;
delete t_iso_table;
delete t_sc_table;
return 0;
}
