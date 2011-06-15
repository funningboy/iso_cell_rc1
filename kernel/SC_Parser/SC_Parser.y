%{
        #include <iostream>
        #include <sstream>
        #include <vector>
        #include <map>
        #include <string>

	#include <stdlib.h> 
        #include <stdio.h>
        #include <assert.h>

        #include "kernel/SC_Context/SC_Define.h"
        #include "kernel/SC_Context/SC_Module.h"
        #include "kernel/SC_Context/SC_Port.h"
        #include "kernel/SC_Context/SC_Cell.h"
        #include "kernel/SC_Context/SC_Table.h"
        #include "kernel/SC_Context/SC_Time.h"
        #include "kernel/SC_Context/SC_Power.h"
        #include "kernel/SC_Context/SC_Logic.h"
        #include "kernel/SC_Context/SC_Type.h"
        #include "kernel/SC_Context/SC_Domain.h"
        #include "kernel/SC_Context/SC_Pass.h"


        using namespace std;
        using namespace xVerilog;

        SC_Module              *t_sc_module;
        SC_Module::SC_Port_D   *t_sc_port;
        SC_Module::SC_Cell_D   *t_sc_cell;

        SC_Table               *t_sc_table = new SC_Table();


        typedef  SC_Time<  Def_Arrive_Time  >   SC_Time_D;
        typedef  SC_Power< Def_Switch_Power >   SC_Power_D;
        typedef  SC_Logic                       SC_Logic_D;
        typedef  SC_Type                        SC_Type_D;
        typedef  SC_Domain                      SC_Domain_D;
        typedef  SC_Pass                        SC_Pass_D;


        std::string       sc_module_str;   // module name
        std::string       sc_cell_m_str;   // cell module name
        std::string       sc_cell_u_str;   // cell unique name
        std::string       sc_cell_p_str;   // cell port name
        std::string       sc_token_str;

        bool              sc_pass;         // Design = true, Library = false
        int               sc_msb;
        int               sc_lsb;
        int               sc_cell_u_inx =0;   // cell unique inx

        typedef std::vector<std::string>                                 sc_vv_D;
 
        typedef std::vector<std::string>::iterator                       sc_vv_iter;
        typedef std::vector<std::string>::reverse_iterator               sc_vv_rev_iter;
        typedef std::vector<std::string>::iterator                       sc_inv_iter;
        typedef std::vector<std::string>::iterator                       sc_sig_pt_iter;
        typedef std::map<std::string, SC_Module::SC_Port_D* >::iterator  sc_in_pt_iter;
        typedef std::map<std::string, SC_Module::SC_Port_D* >::iterator  sc_ot_pt_iter;
        typedef std::map<std::string, SC_Module::SC_Port_D* >::iterator  sc_wr_pt_iter;
        typedef std::map<std::string, SC_Module::SC_Cell_D* >::iterator  sc_cell_iter;
        typedef std::vector< SC_Module::SC_Port_D* >::iterator           sc_cell_pt_iter;
         
        std::vector<std::string>                                         sc_vv;
        std::vector<std::string>                                         sc_inv;
        std::vector<std::string>                                         sc_sig_pt_vec;
 
        std::map<std::string, SC_Module::SC_Port_D* >                    sc_in_pt_map;
        std::map<std::string, SC_Module::SC_Port_D* >                    sc_ot_pt_map;
        std::map<std::string, SC_Module::SC_Port_D* >                    sc_wr_pt_map;
        std::map<std::string, sc_vv_D >                                  sc_div_in_pt_map;
        std::map<std::string, sc_vv_D >                                  sc_div_ot_pt_map;
        std::map<std::string, sc_vv_D >                                  sc_div_wr_pt_map;
        std::map<std::string, SC_Module::SC_Cell_D* >                    sc_cell_map;
        std::vector< SC_Module::SC_Port_D* >                             sc_cell_pt_vec; 
       
	extern int SC_lex();
	void SC_error(const char *s) { printf("ERROR: %s\n", s); }

	void sc_dump(std::string str ) { std::cout << str << std::endl; }

                  
%}





%{
bool stringCompare( const string &left, const string &right ){
   for( string::const_iterator lit = left.begin(), rit = right.begin(); lit != left.end() && rit != right.end(); ++lit, ++rit )
      if( tolower( *lit ) < tolower( *rit ) )
         return true;
      else if( tolower( *lit ) > tolower( *rit ) )
         return false;
   if( left.size() < right.size() )
      return true;
   return false;
}
%}





%{
void set_module(){

      assert( !sc_module_str.empty() &&
              !sc_in_pt_map.empty()  &&
              !sc_ot_pt_map.empty()  &&
              !sc_cell_map.empty()   &&  "Parser->module" );

      SC_Module *sc_module = new SC_Module(); 

      assert( sc_module != NULL && "Parser->module" );

      sc_module->set_ModuleName(sc_module_str);

      SC_Domain_D *sc_module_d = dynamic_cast<SC_Domain_D*>(sc_module);
      SC_Pass_D   *sc_module_p = dynamic_cast<SC_Pass_D*>(sc_module);

      ( sc_pass == true )? sc_module_p->set_Pass(true) :
                           sc_module_p->set_Pass(false);

      // @ input insert
      for(sc_in_pt_iter in  = sc_in_pt_map.begin(); 
                        in != sc_in_pt_map.end(); ++in){

         SC_Module::SC_Port_D *pp = static_cast<SC_Module::SC_Port_D*>(in->second);
 
         assert( pp != NULL && "Parser->module" );
    
         pp->set_Parent(sc_module);
         sc_module->set_InputPortVec(pp);
      }


       // @ output insert
       for(sc_ot_pt_iter ot  = sc_ot_pt_map.begin(); 
                         ot != sc_ot_pt_map.end(); ++ot){

         SC_Module::SC_Port_D *pp = static_cast<SC_Module::SC_Port_D*>(ot->second);

         assert( pp != NULL && "Parser->module" );
     
         pp->set_Parent(sc_module);
         sc_module->set_OutputPortVec(pp);
      }


        // @ wire insert
        for(sc_wr_pt_iter wr  = sc_wr_pt_map.begin(); 
                          wr != sc_wr_pt_map.end(); ++wr ){

         SC_Module::SC_Port_D *pp = static_cast<SC_Module::SC_Port_D*>(wr->second);

         assert( pp != NULL && "Parser->module" );
 
         pp->set_Parent(sc_module);
         sc_module->set_WirePortVec(pp);
      }

  
        // @ Cell insert 
         for(sc_cell_iter cell  = sc_cell_map.begin(); 
                          cell != sc_cell_map.end(); ++cell ){

         SC_Module::SC_Cell_D *cc = static_cast<SC_Module::SC_Cell_D*>(cell->second);

         assert( cc != NULL && "Parser->module" );
 
         cc->set_Parent(sc_module);
         cc->set_Self(NULL);
         sc_module->set_CellVec(cc);    
      } 


     // @ Signal update
     int inx = 0;

     for(sc_sig_pt_iter sig  = sc_sig_pt_vec.begin(); 
                        sig != sc_sig_pt_vec.end(); ++sig){

        // @ input div 
        if( sc_div_in_pt_map.find((*sig)) != sc_div_in_pt_map.end() ){

         sc_vv_D sc_vvi = sc_div_in_pt_map[(*sig)];
         assert( !sc_vvi.empty() && "Parser->module"); 

         for(sc_vv_iter vvi  = sc_vvi.begin(); 
                        vvi != sc_vvi.end();   ++vvi){

             SC_Module::SC_Port_D *sc_module_p = sc_in_pt_map[(*vvi)];
             assert( sc_module_p !=NULL && "Parser->module");

             sc_module->set_SignalVec((*vvi),sc_module_p,inx++);
         }
       } 

       // @ output div
        if( sc_div_ot_pt_map.find((*sig)) != sc_div_ot_pt_map.end() ){

         sc_vv_D sc_vvi = sc_div_ot_pt_map[(*sig)];
         assert( !sc_vvi.empty() && "Parser->module"); 

         for(sc_vv_iter vvi  = sc_vvi.begin(); 
                        vvi != sc_vvi.end();   ++vvi){

             SC_Module::SC_Port_D *sc_module_p = sc_ot_pt_map[(*vvi)];
             assert( sc_module_p !=NULL && "Parser->module");

             sc_module->set_SignalVec((*vvi),sc_module_p,inx++);
         }
       }

    
      // @ no div
        if( sc_div_in_pt_map.find((*sig)) == sc_div_in_pt_map.end() &&
            sc_div_ot_pt_map.find((*sig)) == sc_div_ot_pt_map.end() ){

             // @ map
             SC_Module::SC_Port_D *sc_module_p = ( sc_in_pt_map.find((*sig)) != sc_in_pt_map.end() )? sc_in_pt_map[(*sig)] :
                                                 ( sc_ot_pt_map.find((*sig)) != sc_ot_pt_map.end() )? sc_ot_pt_map[(*sig)] : NULL;

             assert( sc_module_p !=NULL && "Parser->module");
             sc_module->set_SignalVec((*sig),sc_module_p,inx++);
        }

    }


    // @ push 2 SC_Table
      t_sc_table->set_ModuleMap(sc_module_str,sc_module);


     
      sc_in_pt_map.clear();
      sc_ot_pt_map.clear();
      sc_wr_pt_map.clear();

      sc_div_in_pt_map.clear();
      sc_div_ot_pt_map.clear();
      sc_div_wr_pt_map.clear();
      sc_cell_map.clear();
      sc_cell_pt_vec.clear(); 
 
      sc_sig_pt_vec.clear();

      sc_vv.clear();
      sc_inv.clear();
}
%} 




%{
void set_module_signal(){

     assert( !sc_vv.empty() && "Parser->module_signal" );

     sc_sig_pt_vec  = sc_vv;
 
sc_vv.clear();

}
%}





%{
void  set_module_input_div(){

      std::string nm  = "";
   
      std::stringstream ss;
      std::vector<std::string> tp_vec;

      tp_vec.clear();  
 
      assert( sc_msb > sc_lsb  &&
              sc_lsb ==0       && 
              !sc_vv.empty()   && "Parser->module_input_div");
   
      for(sc_vv_iter vi  = sc_vv.begin(); 
                     vi != sc_vv.end();   ++vi){

         for(int i=sc_msb; i>=sc_lsb; --i){ 
   
              ss << i;
              nm = std::string((*vi)) + "[" + ss.str() + "]";
              ss.str("");
             
              SC_Module::SC_Port_D *sc_module_p = new SC_Module::SC_Port_D(); 
              assert( sc_module_p !=NULL && "Parser->module_input_div");

              sc_module_p->set_Name(nm);
              sc_module_p->set_Parent(NULL);

              SC_Time_D   *sc_module_p_tm  = dynamic_cast<SC_Time_D*>  (sc_module_p);
              SC_Power_D  *sc_module_p_pr  = dynamic_cast<SC_Power_D*> (sc_module_p);
              SC_Logic_D  *sc_module_p_lg  = dynamic_cast<SC_Logic_D*> (sc_module_p);
              SC_Type_D   *sc_module_p_tp  = dynamic_cast<SC_Type_D*>  (sc_module_p); 
              SC_Domain_D *sc_module_p_dm  = dynamic_cast<SC_Domain_D*>(sc_module_p);
              SC_Pass_D   *sc_module_p_ps  = dynamic_cast<SC_Pass_D*>  (sc_module_p);

              sc_module_p_tm->set_ArriveTime(0);
              sc_module_p_pr->set_SwitchPower(0);
              sc_module_p_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
              sc_module_p_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
              sc_module_p_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

              ( sc_pass == true )? sc_module_p_ps->set_Pass(true) :
                                   sc_module_p_ps->set_Pass(false);

              sc_in_pt_map[nm] = sc_module_p;
              tp_vec.push_back(nm);
         }
              sc_div_in_pt_map[(*vi)] = tp_vec;
      }

sc_vv.clear();

}
%}




%{
void  set_module_input_only(){

      std::string nm; 
 
      assert( (!sc_vv.empty()) && "Parser->module_input_only");
    
        for(sc_vv_iter vi  = sc_vv.begin(); 
                       vi != sc_vv.end(); ++vi){

            nm = std::string((*vi));

            SC_Module::SC_Port_D *sc_module_p = new SC_Module::SC_Port_D();
 
              assert( sc_module_p !=NULL && "Parser->module_input_div");

              sc_module_p->set_Name(nm);
              sc_module_p->set_Parent(NULL);

              SC_Time_D   *sc_module_p_tm  = dynamic_cast<SC_Time_D*>  (sc_module_p);
              SC_Power_D  *sc_module_p_pr  = dynamic_cast<SC_Power_D*> (sc_module_p);
              SC_Logic_D  *sc_module_p_lg  = dynamic_cast<SC_Logic_D*> (sc_module_p);
              SC_Type_D   *sc_module_p_tp  = dynamic_cast<SC_Type_D*>  (sc_module_p); 
              SC_Domain_D *sc_module_p_dm  = dynamic_cast<SC_Domain_D*>(sc_module_p);
              SC_Pass_D   *sc_module_p_ps  = dynamic_cast<SC_Pass_D*>  (sc_module_p);

              sc_module_p_tm->set_ArriveTime(0);
              sc_module_p_pr->set_SwitchPower(0);
              sc_module_p_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
              sc_module_p_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
              sc_module_p_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

              ( sc_pass == true )? sc_module_p_ps->set_Pass(true) :
                                   sc_module_p_ps->set_Pass(false);
               
             sc_in_pt_map[nm] = sc_module_p;                              
        }

sc_vv.clear();

}
%}





%{
void  set_module_output_div(){

      std::string nm  = "";
   
      std::stringstream ss;
      std::vector<std::string> tp_vec;

      tp_vec.clear();  
 
      assert( sc_msb > sc_lsb  &&
              sc_lsb ==0       && 
              !sc_vv.empty()   && "Parser->module_output_div");
   
      for(sc_vv_iter vi  = sc_vv.begin(); 
                     vi != sc_vv.end();  ++vi){

         for(int i=sc_msb; i>=sc_lsb; --i){ 
   
              ss << i;
              nm = std::string((*vi)) + "[" + ss.str() + "]";
              ss.str("");

              SC_Module::SC_Port_D *sc_module_p = new SC_Module::SC_Port_D();
              assert( sc_module_p !=NULL && "Parser->module_input_div");

              sc_module_p->set_Name(nm);
              sc_module_p->set_Parent(NULL);

              SC_Time_D   *sc_module_p_tm  = dynamic_cast<SC_Time_D*>  (sc_module_p);
              SC_Power_D  *sc_module_p_pr  = dynamic_cast<SC_Power_D*> (sc_module_p);
              SC_Logic_D  *sc_module_p_lg  = dynamic_cast<SC_Logic_D*> (sc_module_p);
              SC_Type_D   *sc_module_p_tp  = dynamic_cast<SC_Type_D*>  (sc_module_p); 
              SC_Domain_D *sc_module_p_dm  = dynamic_cast<SC_Domain_D*>(sc_module_p);
              SC_Pass_D   *sc_module_p_ps  = dynamic_cast<SC_Pass_D*>  (sc_module_p);

              sc_module_p_tm->set_ArriveTime(0);
              sc_module_p_pr->set_SwitchPower(0);
              sc_module_p_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
              sc_module_p_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
              sc_module_p_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

              ( sc_pass == true )? sc_module_p_ps->set_Pass(true) :
                                   sc_module_p_ps->set_Pass(false);
 
             sc_ot_pt_map[nm] = sc_module_p;
             tp_vec.push_back(nm);
         }
             sc_div_ot_pt_map[(*vi)] = tp_vec;
      }

sc_vv.clear();

}
%}




%{
void  set_module_output_only(){

      std::string nm; 
 
      assert( (!sc_vv.empty()) && "Parser->module_output_only");
    
        for(sc_vv_iter vi  = sc_vv.begin(); 
                       vi != sc_vv.end(); ++vi){

            nm = std::string((*vi));
    
            SC_Module::SC_Port_D *sc_module_p = new SC_Module::SC_Port_D();
            assert( sc_module_p !=NULL && "Parser->module_output_only");

            sc_module_p->set_Name(nm);
            sc_module_p->set_Parent(NULL);
 
            SC_Time_D   *sc_module_p_tm  = dynamic_cast<SC_Time_D*>  (sc_module_p);
            SC_Power_D  *sc_module_p_pr  = dynamic_cast<SC_Power_D*> (sc_module_p);
            SC_Logic_D  *sc_module_p_lg  = dynamic_cast<SC_Logic_D*> (sc_module_p);
            SC_Type_D   *sc_module_p_tp  = dynamic_cast<SC_Type_D*>  (sc_module_p); 
            SC_Domain_D *sc_module_p_dm  = dynamic_cast<SC_Domain_D*>(sc_module_p);
            SC_Pass_D   *sc_module_p_ps  = dynamic_cast<SC_Pass_D*>  (sc_module_p);

            sc_module_p_tm->set_ArriveTime(0);
            sc_module_p_pr->set_SwitchPower(0);
            sc_module_p_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
            sc_module_p_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
            sc_module_p_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);
            
            ( sc_pass == true )? sc_module_p_ps->set_Pass(true) :
                                 sc_module_p_ps->set_Pass(false);

            sc_ot_pt_map[nm] = sc_module_p;                              
        }

sc_vv.clear();

}
%}




%{
void  set_module_wire_div(){

      std::string nm  = "";
   
      std::stringstream ss;
      std::vector<std::string> tp_vec;

      tp_vec.clear();  
 
      assert( sc_msb > sc_lsb  &&
              sc_lsb ==0       && 
              !sc_vv.empty()   && "Parser->module_wire_div");
   
      for(sc_vv_iter vi  = sc_vv.begin(); 
                     vi != sc_vv.end();  ++vi){

         for(int i=sc_msb; i>=sc_lsb; --i){ 
   
              ss << i;
              nm = std::string((*vi)) + "[" + ss.str() + "]";
              ss.str("");

              SC_Module::SC_Port_D *sc_module_p = new SC_Module::SC_Port_D();
              assert( sc_module_p !=NULL && "Parser->module_wire_div");

              sc_module_p->set_Name(nm);
              sc_module_p->set_Parent(NULL);

              SC_Time_D   *sc_module_p_tm  = dynamic_cast<SC_Time_D*>  (sc_module_p);
              SC_Power_D  *sc_module_p_pr  = dynamic_cast<SC_Power_D*> (sc_module_p);
              SC_Logic_D  *sc_module_p_lg  = dynamic_cast<SC_Logic_D*> (sc_module_p);
              SC_Type_D   *sc_module_p_tp  = dynamic_cast<SC_Type_D*>  (sc_module_p); 
              SC_Domain_D *sc_module_p_dm  = dynamic_cast<SC_Domain_D*>(sc_module_p);
              SC_Pass_D   *sc_module_p_ps  = dynamic_cast<SC_Pass_D*>  (sc_module_p);

              sc_module_p_tm->set_ArriveTime(0);
              sc_module_p_pr->set_SwitchPower(0);
              sc_module_p_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
              sc_module_p_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
              sc_module_p_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

              ( sc_pass == true )? sc_module_p_ps->set_Pass(true) :
                                   sc_module_p_ps->set_Pass(false);
 
             sc_wr_pt_map[nm] = sc_module_p;
             tp_vec.push_back(nm);
         }
             sc_div_wr_pt_map[(*vi)] = tp_vec;
      }

sc_vv.clear();

}
%}




%{
void  set_module_wire_only(){

      std::string nm; 
 
      assert( (!sc_vv.empty()) && "Parser->module_wire_only");
    
        for(sc_vv_iter vi  = sc_vv.begin(); 
                       vi != sc_vv.end();  ++vi){

            nm = std::string((*vi));
    
            SC_Module::SC_Port_D *sc_module_p = new SC_Module::SC_Port_D();
            assert( sc_module_p !=NULL && "Parser->module_wire_only");

            sc_module_p->set_Name(nm);
            sc_module_p->set_Parent(NULL);

            SC_Time_D   *sc_module_p_tm  = dynamic_cast<SC_Time_D*>  (sc_module_p);
            SC_Power_D  *sc_module_p_pr  = dynamic_cast<SC_Power_D*> (sc_module_p);
            SC_Logic_D  *sc_module_p_lg  = dynamic_cast<SC_Logic_D*> (sc_module_p);
            SC_Type_D   *sc_module_p_tp  = dynamic_cast<SC_Type_D*>  (sc_module_p); 
            SC_Domain_D *sc_module_p_dm  = dynamic_cast<SC_Domain_D*>(sc_module_p);
            SC_Pass_D   *sc_module_p_ps  = dynamic_cast<SC_Pass_D*>  (sc_module_p);

            sc_module_p_tm->set_ArriveTime(0);
            sc_module_p_pr->set_SwitchPower(0);
            sc_module_p_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
            sc_module_p_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
            sc_module_p_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

            ( sc_pass == true )? sc_module_p_ps->set_Pass(true) :
                                 sc_module_p_ps->set_Pass(false);

            sc_wr_pt_map[nm] = sc_module_p;                              
        }

sc_vv.clear();

}
%}








%{
void set_cell_unique_name(){

    assert( !sc_cell_m_str.empty()  &&  "Parser->cell_unique_name" );

    std::stringstream ss;
    ss << sc_cell_u_inx++;

    sc_cell_u_str = "_" + sc_cell_m_str + "_" + ss.str() + "_";
    ss.str("");

}
%}






%{
void set_module_cell(){

     assert( !sc_cell_m_str.empty()  && 
             !sc_cell_u_str.empty()  &&
             !sc_cell_pt_vec.empty() && "Parser->module_cell"); 

     SC_Module::SC_Cell_D *sc_cell = new SC_Module::SC_Cell_D();

     assert( sc_cell!=NULL && "Parser->module_cell");

                           sc_cell->set_Parent(NULL);
                           sc_cell->set_Self(NULL);
                           sc_cell->set_ModuleName(sc_cell_m_str);
                           sc_cell->set_CellName(sc_cell_u_str);
                           sc_cell->set_TLib(SC_Cell::SC_TLIB_undef);

                           SC_Domain_D *sc_cell_dm  = dynamic_cast<SC_Domain_D*>(sc_cell);
                           SC_Pass_D   *sc_cell_ps  = dynamic_cast<SC_Pass_D*>  (sc_cell);

                           ( sc_pass == true )? sc_cell_ps->set_Pass(true) :
                                                sc_cell_ps->set_Pass(false);

           for(sc_cell_pt_iter cp  = sc_cell_pt_vec.begin(); 
                               cp != sc_cell_pt_vec.end(); ++cp){

                           SC_Module::SC_Port_D *pp = static_cast<SC_Module::SC_Port_D*>(*cp);

                           assert( pp != NULL && "Parser->module_cell");
                           sc_cell->set_PortVec(pp);
           }

sc_cell_map[sc_cell_u_str] = sc_cell;

sc_cell_pt_vec.clear();

}
%}





%{
void set_module_links_indirect(){

    std::stringstream ss;
    std::string nm = "";
    int         inx = 0;

    assert( !sc_vv.empty()          &&
            !sc_cell_p_str.empty()  && "Parser->module_links_indirect");

    for(sc_vv_rev_iter vv  = sc_vv.rbegin(); 
                       vv != sc_vv.rend();  ++vv){


        if( sc_div_in_pt_map.find((*vv)) != sc_div_in_pt_map.end() ){

         sc_vv_D sc_vvi = sc_div_in_pt_map[(*vv)];
         assert( !sc_vvi.empty() && "Parser->module_links_indirect"); 

         for(sc_vv_rev_iter vvi  = sc_vvi.rbegin(); 
                            vvi != sc_vvi.rend(); ++vvi){
             ss << inx++;
             nm = sc_cell_p_str + "[" + ss.str() + "]";  
             ss.str("");

             SC_Module::SC_Port_D *sc_cell_p = new SC_Module::SC_Port_D();
             assert( sc_cell_p !=NULL && "Parser->module_links_indirect");

             sc_cell_p->set_Name(nm);
             sc_cell_p->set_Parent(NULL);

             SC_Time_D   *sc_cell_p_tm  = dynamic_cast<SC_Time_D*>  (sc_cell_p);
             SC_Power_D  *sc_cell_p_pr  = dynamic_cast<SC_Power_D*> (sc_cell_p);
             SC_Logic_D  *sc_cell_p_lg  = dynamic_cast<SC_Logic_D*> (sc_cell_p);
             SC_Type_D   *sc_cell_p_tp  = dynamic_cast<SC_Type_D*>  (sc_cell_p); 
             SC_Domain_D *sc_cell_p_dm  = dynamic_cast<SC_Domain_D*>(sc_cell_p);
             SC_Pass_D   *sc_cell_p_ps  = dynamic_cast<SC_Pass_D*>  (sc_cell_p);

             sc_cell_p_tm->set_ArriveTime(0);
             sc_cell_p_pr->set_SwitchPower(0);
             sc_cell_p_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

             ( sc_pass == true )? sc_cell_p_ps->set_Pass(true) :
                                  sc_cell_p_ps->set_Pass(false);

             SC_Module::SC_Port_D *sc_module_p = sc_in_pt_map[(*vvi)];
             assert( sc_module_p !=NULL && "Parser->module_links_indirect");

             sc_module_p->set_NxtPortVec(sc_cell_p);
             sc_cell_p->set_PrePortVec(sc_module_p);
             
             sc_cell_pt_vec.push_back(sc_cell_p);
          }
       } 




        if( sc_div_ot_pt_map.find((*vv)) != sc_div_ot_pt_map.end() ){

         sc_vv_D sc_vvi = sc_div_ot_pt_map[(*vv)];
         assert( !sc_vvi.empty() && "Parser->module_links_indirect"); 

         for(sc_vv_rev_iter vvi  = sc_vvi.rbegin(); 
                            vvi != sc_vvi.rend();  ++vvi){
             ss << inx++;
             nm = sc_cell_p_str + "[" + ss.str() + "]";  
             ss.str("");

             SC_Module::SC_Port_D *sc_cell_p = new SC_Module::SC_Port_D();
             assert( sc_cell_p !=NULL && "Parser->module_links_indirect");

             sc_cell_p->set_Name(nm);
             sc_cell_p->set_Parent(NULL);

             SC_Time_D   *sc_cell_p_tm  = dynamic_cast<SC_Time_D*>  (sc_cell_p);
             SC_Power_D  *sc_cell_p_pr  = dynamic_cast<SC_Power_D*> (sc_cell_p);
             SC_Logic_D  *sc_cell_p_lg  = dynamic_cast<SC_Logic_D*> (sc_cell_p);
             SC_Type_D   *sc_cell_p_tp  = dynamic_cast<SC_Type_D*>  (sc_cell_p); 
             SC_Domain_D *sc_cell_p_dm  = dynamic_cast<SC_Domain_D*>(sc_cell_p);
             SC_Pass_D   *sc_cell_p_ps  = dynamic_cast<SC_Pass_D*>  (sc_cell_p);

             sc_cell_p_tm->set_ArriveTime(0);
             sc_cell_p_pr->set_SwitchPower(0);
             sc_cell_p_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

             ( sc_pass == true )? sc_cell_p_ps->set_Pass(true) : 
                                  sc_cell_p_ps->set_Pass(false);

             SC_Module::SC_Port_D *sc_module_p = sc_ot_pt_map[(*vvi)];
             assert( sc_module_p !=NULL && "Parser->module_links_indirect");

             sc_module_p->set_NxtPortVec(sc_cell_p);
             sc_cell_p->set_PrePortVec(sc_module_p);
            
             sc_cell_pt_vec.push_back(sc_cell_p);
          }
        }
    

       // @ wire div
        if( sc_div_wr_pt_map.find((*vv)) != sc_div_wr_pt_map.end() &&
            sc_div_in_pt_map.find((*vv)) == sc_div_in_pt_map.end() &&
            sc_div_ot_pt_map.find((*vv)) == sc_div_ot_pt_map.end() ){

         sc_vv_D sc_vvi = sc_div_wr_pt_map[(*vv)];
         assert( !sc_vvi.empty() && "Parser->module_links_indirect"); 

         for(sc_vv_rev_iter vvi  = sc_vvi.rbegin(); 
                            vvi != sc_vvi.rend(); ++vvi){
             ss << inx++;
             nm = sc_cell_p_str + "[" + ss.str() + "]";  
             ss.str("");

             SC_Module::SC_Port_D *sc_cell_p = new SC_Module::SC_Port_D();
             assert( sc_cell_p !=NULL && "Parser->module_links_indirect");

             sc_cell_p->set_Name(nm);
             sc_cell_p->set_Parent(NULL);

             SC_Time_D   *sc_cell_p_tm  = dynamic_cast<SC_Time_D*>  (sc_cell_p);
             SC_Power_D  *sc_cell_p_pr  = dynamic_cast<SC_Power_D*> (sc_cell_p);
             SC_Logic_D  *sc_cell_p_lg  = dynamic_cast<SC_Logic_D*> (sc_cell_p);
             SC_Type_D   *sc_cell_p_tp  = dynamic_cast<SC_Type_D*>  (sc_cell_p); 
             SC_Domain_D *sc_cell_p_dm  = dynamic_cast<SC_Domain_D*>(sc_cell_p);
             SC_Pass_D   *sc_cell_p_ps  = dynamic_cast<SC_Pass_D*>  (sc_cell_p);

             sc_cell_p_tm->set_ArriveTime(0);
             sc_cell_p_pr->set_SwitchPower(0);
             sc_cell_p_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

             ( sc_pass == true )? sc_cell_p_ps->set_Pass(true) :
                                  sc_cell_p_ps->set_Pass(false);

             SC_Module::SC_Port_D *sc_module_p = sc_wr_pt_map[(*vvi)];
             assert( sc_module_p !=NULL && "Parser->module_links_indirect");

             sc_module_p->set_NxtPortVec(sc_cell_p);
             sc_cell_p->set_PrePortVec(sc_module_p);
             
             sc_cell_pt_vec.push_back(sc_cell_p);
           }
        }



        if( sc_div_wr_pt_map.find((*vv)) == sc_div_wr_pt_map.end() &&
            sc_div_in_pt_map.find((*vv)) == sc_div_in_pt_map.end() &&
            sc_div_ot_pt_map.find((*vv)) == sc_div_ot_pt_map.end() ){

             if( sc_vv.size()==1 ){
                 nm = sc_cell_p_str;
             } else {
                 ss << inx++;
                 nm = sc_cell_p_str + "[" + ss.str() + "]";  
                 ss.str("");
             }
 
             SC_Module::SC_Port_D *sc_cell_p = new SC_Module::SC_Port_D();
             assert( sc_cell_p !=NULL && "Parser->module_links_indirect");

             sc_cell_p->set_Name(nm);
             sc_cell_p->set_Parent(NULL);

             SC_Time_D   *sc_cell_p_tm  = dynamic_cast<SC_Time_D*>  (sc_cell_p);
             SC_Power_D  *sc_cell_p_pr  = dynamic_cast<SC_Power_D*> (sc_cell_p);
             SC_Logic_D  *sc_cell_p_lg  = dynamic_cast<SC_Logic_D*> (sc_cell_p);
             SC_Type_D   *sc_cell_p_tp  = dynamic_cast<SC_Type_D*>  (sc_cell_p); 
             SC_Domain_D *sc_cell_p_dm  = dynamic_cast<SC_Domain_D*>(sc_cell_p);
             SC_Pass_D   *sc_cell_p_ps  = dynamic_cast<SC_Pass_D*>  (sc_cell_p);

             sc_cell_p_tm->set_ArriveTime(0);
             sc_cell_p_pr->set_SwitchPower(0);
             sc_cell_p_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

             ( sc_pass == true )? sc_cell_p_ps->set_Pass(true) :
                                  sc_cell_p_ps->set_Pass(false);

             SC_Module::SC_Port_D *sc_module_p = ( sc_in_pt_map.find((*vv)) != sc_in_pt_map.end() )? sc_in_pt_map[(*vv)] :
                                                 ( sc_ot_pt_map.find((*vv)) != sc_ot_pt_map.end() )? sc_ot_pt_map[(*vv)] :
                                                 ( sc_wr_pt_map.find((*vv)) != sc_wr_pt_map.end() )? sc_wr_pt_map[(*vv)] : NULL;

             assert( sc_module_p !=NULL && "Parser->module_links_indirect");

             sc_module_p->set_NxtPortVec(sc_cell_p);
             sc_cell_p->set_PrePortVec(sc_module_p);
             
             sc_cell_pt_vec.push_back(sc_cell_p);
         }

    }

sc_vv.clear();

} 
%} 





%{
void set_module_links_direct(){

assert( sc_cell_p_str.empty() && 
        !sc_vv.empty()        && "Parser->module_links_direct");


    for(sc_vv_rev_iter vv  = sc_vv.rbegin(); 
                       vv != sc_vv.rend(); ++vv){


        if( sc_div_in_pt_map.find((*vv)) != sc_div_in_pt_map.end() ){

         sc_vv_D sc_vvi = sc_div_in_pt_map[(*vv)];
         assert( !sc_vvi.empty() && "Parser->module_links_direct"); 

         for(sc_vv_rev_iter vvi  = sc_vvi.rbegin(); 
                            vvi != sc_vvi.rend(); ++vvi){

             SC_Module::SC_Port_D *sc_cell_p = new SC_Module::SC_Port_D();
             assert( sc_cell_p !=NULL && "Parser->module_links_direct");

             sc_cell_p->set_Name((*vvi));
             sc_cell_p->set_Parent(NULL);

             SC_Time_D   *sc_cell_p_tm  = dynamic_cast<SC_Time_D*>  (sc_cell_p);
             SC_Power_D  *sc_cell_p_pr  = dynamic_cast<SC_Power_D*> (sc_cell_p);
             SC_Logic_D  *sc_cell_p_lg  = dynamic_cast<SC_Logic_D*> (sc_cell_p);
             SC_Type_D   *sc_cell_p_tp  = dynamic_cast<SC_Type_D*>  (sc_cell_p); 
             SC_Domain_D *sc_cell_p_dm  = dynamic_cast<SC_Domain_D*>(sc_cell_p);
             SC_Pass_D   *sc_cell_p_ps  = dynamic_cast<SC_Pass_D*>  (sc_cell_p);

             sc_cell_p_tm->set_ArriveTime(0);
             sc_cell_p_pr->set_SwitchPower(0);
             sc_cell_p_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

             ( sc_pass == true )? sc_cell_p_ps->set_Pass(true) :
                                  sc_cell_p_ps->set_Pass(false);

             SC_Module::SC_Port_D *sc_module_p = sc_in_pt_map[(*vvi)];
             assert( sc_module_p !=NULL && "Parser->module_links_direct");

             sc_module_p->set_NxtPortVec(sc_cell_p);
             sc_cell_p->set_PrePortVec(sc_module_p);
             
             sc_cell_pt_vec.push_back(sc_cell_p);
          }
       } 




        if( sc_div_ot_pt_map.find((*vv)) != sc_div_ot_pt_map.end() ){

         sc_vv_D sc_vvi = sc_div_ot_pt_map[(*vv)];
         assert( !sc_vvi.empty() && "Parser->module_links_direct"); 

         for(sc_vv_rev_iter vvi  = sc_vvi.rbegin(); 
                            vvi != sc_vvi.rend(); ++vvi){

             SC_Module::SC_Port_D *sc_cell_p = new SC_Module::SC_Port_D();
             assert( sc_cell_p !=NULL && "Parser->module_links_direct");

             sc_cell_p->set_Name((*vvi));
             sc_cell_p->set_Parent(NULL);

             SC_Time_D   *sc_cell_p_tm  = dynamic_cast<SC_Time_D*>  (sc_cell_p);
             SC_Power_D  *sc_cell_p_pr  = dynamic_cast<SC_Power_D*> (sc_cell_p);
             SC_Logic_D  *sc_cell_p_lg  = dynamic_cast<SC_Logic_D*> (sc_cell_p);
             SC_Type_D   *sc_cell_p_tp  = dynamic_cast<SC_Type_D*>  (sc_cell_p); 
             SC_Domain_D *sc_cell_p_dm  = dynamic_cast<SC_Domain_D*>(sc_cell_p);
             SC_Pass_D   *sc_cell_p_ps  = dynamic_cast<SC_Pass_D*>  (sc_cell_p);

             sc_cell_p_tm->set_ArriveTime(0);
             sc_cell_p_pr->set_SwitchPower(0);
             sc_cell_p_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

             ( sc_pass == true )? sc_cell_p_ps->set_Pass(true) :
                                  sc_cell_p_ps->set_Pass(false);

             SC_Module::SC_Port_D *sc_module_p = sc_ot_pt_map[(*vvi)];
             assert( sc_module_p !=NULL && "Parser->module_links_direct");

             sc_module_p->set_PrePortVec(sc_cell_p);
             sc_cell_p->set_NxtPortVec(sc_module_p);
            
             sc_cell_pt_vec.push_back(sc_cell_p);
          }
        }
    


        if( sc_div_wr_pt_map.find((*vv)) != sc_div_wr_pt_map.end() &&
            sc_div_in_pt_map.find((*vv)) == sc_div_in_pt_map.end() &&
            sc_div_ot_pt_map.find((*vv)) == sc_div_ot_pt_map.end() ){

         sc_vv_D sc_vvi = sc_div_wr_pt_map[(*vv)];
         assert( !sc_vvi.empty() && "Parser->module_links_direct"); 

         for(sc_vv_rev_iter vvi  = sc_vvi.rbegin(); 
                            vvi != sc_vvi.rend(); ++vvi){

             SC_Module::SC_Port_D *sc_cell_p = new SC_Module::SC_Port_D();
             assert( sc_cell_p !=NULL && "Parser->module_links_direct");

             sc_cell_p->set_Name((*vvi));
             sc_cell_p->set_Parent(NULL);

             SC_Time_D   *sc_cell_p_tm  = dynamic_cast<SC_Time_D*>  (sc_cell_p);
             SC_Power_D  *sc_cell_p_pr  = dynamic_cast<SC_Power_D*> (sc_cell_p);
             SC_Logic_D  *sc_cell_p_lg  = dynamic_cast<SC_Logic_D*> (sc_cell_p);
             SC_Type_D   *sc_cell_p_tp  = dynamic_cast<SC_Type_D*>  (sc_cell_p); 
             SC_Domain_D *sc_cell_p_dm  = dynamic_cast<SC_Domain_D*>(sc_cell_p);
             SC_Pass_D   *sc_cell_p_ps  = dynamic_cast<SC_Pass_D*>  (sc_cell_p);

             sc_cell_p_tm->set_ArriveTime(0);
             sc_cell_p_pr->set_SwitchPower(0);
             sc_cell_p_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

             ( sc_pass == true )? sc_cell_p_ps->set_Pass(true) :
                                  sc_cell_p_ps->set_Pass(false);

             SC_Module::SC_Port_D *sc_module_p = sc_wr_pt_map[(*vvi)];
             assert( sc_module_p !=NULL && "Parser->module_links_direct");

             sc_module_p->set_NxtPortVec(sc_cell_p);
             sc_cell_p->set_PrePortVec(sc_module_p);
             
             sc_cell_pt_vec.push_back(sc_cell_p);
           }
        }


        if( sc_div_wr_pt_map.find((*vv)) == sc_div_wr_pt_map.end() &&
            sc_div_in_pt_map.find((*vv)) == sc_div_in_pt_map.end() &&
            sc_div_ot_pt_map.find((*vv)) == sc_div_ot_pt_map.end() ){

             SC_Module::SC_Port_D *sc_cell_p = new SC_Module::SC_Port_D();
             assert( sc_cell_p !=NULL && "Parser->module_links_direct");

             sc_cell_p->set_Name((*vv));
             sc_cell_p->set_Parent(NULL);
 
             SC_Time_D   *sc_cell_p_tm  = dynamic_cast<SC_Time_D*>  (sc_cell_p);
             SC_Power_D  *sc_cell_p_pr  = dynamic_cast<SC_Power_D*> (sc_cell_p);
             SC_Logic_D  *sc_cell_p_lg  = dynamic_cast<SC_Logic_D*> (sc_cell_p);
             SC_Type_D   *sc_cell_p_tp  = dynamic_cast<SC_Type_D*>  (sc_cell_p); 
             SC_Domain_D *sc_cell_p_dm  = dynamic_cast<SC_Domain_D*>(sc_cell_p);
             SC_Pass_D   *sc_cell_p_ps  = dynamic_cast<SC_Pass_D*>  (sc_cell_p);

             sc_cell_p_tm->set_ArriveTime(0);
             sc_cell_p_pr->set_SwitchPower(0);
             sc_cell_p_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
             sc_cell_p_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);
            
             ( sc_pass == true )? sc_cell_p_ps->set_Pass(true) :
                                  sc_cell_p_ps->set_Pass(false);

             SC_Module::SC_Port_D *sc_module_p = ( sc_in_pt_map.find((*vv)) != sc_in_pt_map.end() )? sc_in_pt_map[(*vv)] :
                                                 ( sc_ot_pt_map.find((*vv)) != sc_ot_pt_map.end() )? sc_ot_pt_map[(*vv)] :
                                                 ( sc_wr_pt_map.find((*vv)) != sc_wr_pt_map.end() )? sc_wr_pt_map[(*vv)] : NULL;

             assert( sc_module_p !=NULL && "Parser->module_links_direct");

             sc_module_p->set_NxtPortVec(sc_cell_p);
             sc_cell_p->set_PrePortVec(sc_module_p);
             
             sc_cell_pt_vec.push_back(sc_cell_p);
         }

    }

sc_vv.clear();

}
%}





%{
void set_module_vector_div(){

     std::stringstream ss;
     std::string nm = "";
 
     assert( sc_msb > sc_lsb && "Parser->module_vector_stmt");
  
     for(int i=sc_msb; i>=sc_lsb; --i){

         ss << i;
         nm = sc_token_str + "[" + ss.str() + "]";
         sc_vv.push_back(nm);
         ss.str("");
     }
}
%}





%{
void set_moudle_vector_inv_div(){
                                      
     std::stringstream ss;
     std::string nm = "";
  
     assert( sc_msb > sc_lsb && "Parser->module_vector_stmt");
  
      for(int i=sc_msb; i>=sc_lsb; --i){

         ss << i;
         nm = sc_token_str + "[" + ss.str() + "]";
         sc_vv.push_back("__sc_inv__"+ nm);
         sc_inv.push_back(nm);
         ss.str("");
     }
}
%}





%{
void set_and_logic_module_cell(){
  
     int inx = 0;

     assert( !sc_cell_m_str.empty()  && 
             !sc_cell_u_str.empty()  &&
             !sc_cell_pt_vec.empty() && "Parser->and_logic_module_cell"); 

     SC_Module::SC_Cell_D *sc_cell = new SC_Module::SC_Cell_D();
     SC_LIB::SC_AND      *sc_and = dynamic_cast<SC_LIB::SC_AND*>(sc_cell);

     assert( sc_cell!=NULL && "Parser->and_logic_module_cell");

                           sc_cell->set_Parent(NULL);
                           sc_cell->set_Self(NULL);
                           sc_cell->set_ModuleName(sc_cell_m_str);
                           sc_cell->set_CellName(sc_cell_u_str);
                           sc_cell->set_TLib(SC_Cell::SC_TLIB_AND);
                           sc_cell->set_Pass(false);

      assert( (int)sc_cell_pt_vec.size() == 3 && "Parser->and_logic_module_cell");

      for(sc_cell_pt_iter cp  = sc_cell_pt_vec.begin(); 
                          cp != sc_cell_pt_vec.end(); ++cp){

           SC_Module::SC_Port_D *pp = static_cast<SC_Module::SC_Port_D*>(*cp);

           assert( pp!= NULL && "Parser->and_logic_module_cell");
           sc_cell->set_PortVec(pp);

               if(inx == 0){ sc_and->set_Dst(pp);   }
          else if(inx == 1){ sc_and->set_Src1(pp);  }
          else             { sc_and->set_Src2(pp);  }

        inx++;
      }

sc_cell_map[sc_cell_u_str] = sc_cell;

sc_cell_pt_vec.clear();

}
%}





%{
void set_nand_logic_module_cell(){
  
     int inx = 0;

     assert( !sc_cell_m_str.empty()  && 
             !sc_cell_u_str.empty()  &&
             !sc_cell_pt_vec.empty() && "Parser->nand_logic_module_cell"); 

     SC_Module::SC_Cell_D *sc_cell = new SC_Module::SC_Cell_D();
     SC_LIB::SC_NAND    *sc_nand = dynamic_cast<SC_LIB::SC_NAND*>(sc_cell);

     assert( sc_cell!=NULL && "Parser->nand_logic_module_cell");

                           sc_cell->set_Parent(NULL);
                           sc_cell->set_Self(NULL);
                           sc_cell->set_ModuleName(sc_cell_m_str);
                           sc_cell->set_CellName(sc_cell_u_str);
                           sc_cell->set_TLib(SC_Cell::SC_TLIB_NAND);
                           sc_cell->set_Pass(false);

      assert( (int)sc_cell_pt_vec.size() == 3 && "Parser->nand_logic_module_cell");

      for(sc_cell_pt_iter cp  = sc_cell_pt_vec.begin(); 
                          cp != sc_cell_pt_vec.end(); ++cp){

           SC_Module::SC_Port_D *pp = static_cast<SC_Module::SC_Port_D*>(*cp);

           assert( pp!= NULL && "Parser->nand_logic_module_cell");
           sc_cell->set_PortVec(pp);

               if(inx == 0){ sc_nand->set_Dst(pp);   }
          else if(inx == 1){ sc_nand->set_Src1(pp);  }
          else             { sc_nand->set_Src2(pp);  }

        inx++;
      }

sc_cell_map[sc_cell_u_str] = sc_cell;

sc_cell_pt_vec.clear();

}
%}





%{
void set_or_logic_module_cell(){
  
     int inx = 0;

     assert( !sc_cell_m_str.empty()  && 
             !sc_cell_u_str.empty()  &&
             !sc_cell_pt_vec.empty() && "Parser->or_logic_module_cell"); 

     SC_Module::SC_Cell_D *sc_cell = new SC_Module::SC_Cell_D();
     SC_LIB::SC_OR      *sc_or = dynamic_cast<SC_LIB::SC_OR*>(sc_cell);

     assert( sc_cell!=NULL && "Parser->or_logic_module_cell");

                           sc_cell->set_Parent(NULL);
                           sc_cell->set_Self(NULL);
                           sc_cell->set_ModuleName(sc_cell_m_str);
                           sc_cell->set_CellName(sc_cell_u_str);
                           sc_cell->set_TLib(SC_Cell::SC_TLIB_OR);
                           sc_cell->set_Pass(false);

      assert( (int)sc_cell_pt_vec.size() == 3 && "Parser->or_logic_module_cell");

      for(sc_cell_pt_iter cp  = sc_cell_pt_vec.begin(); 
                          cp != sc_cell_pt_vec.end(); ++cp){

           SC_Module::SC_Port_D *pp = static_cast<SC_Module::SC_Port_D*>(*cp);

           assert( pp!= NULL && "Parser->or_logic_module_cell");
           sc_cell->set_PortVec(pp);

               if(inx == 0){ sc_or->set_Dst(pp);   }
          else if(inx == 1){ sc_or->set_Src1(pp);  }
          else             { sc_or->set_Src2(pp);  }

        inx++;
      }

sc_cell_map[sc_cell_u_str] = sc_cell;

sc_cell_pt_vec.clear();

}
%}





%{
void set_nor_logic_module_cell(){
  
     int inx = 0;

     assert( !sc_cell_m_str.empty()  && 
             !sc_cell_u_str.empty()  &&
             !sc_cell_pt_vec.empty() && "Parser->nor_logic_module_cell"); 

     SC_Module::SC_Cell_D *sc_cell = new SC_Module::SC_Cell_D();
     SC_LIB::SC_NOR     *sc_nor  = dynamic_cast<SC_LIB::SC_NOR*>(sc_cell);

     assert( sc_cell!=NULL && "Parser->nor_logic_module_cell");

                           sc_cell->set_Parent(NULL);
                           sc_cell->set_Self(NULL);
                           sc_cell->set_ModuleName(sc_cell_m_str);
                           sc_cell->set_CellName(sc_cell_u_str);
                           sc_cell->set_TLib(SC_Cell::SC_TLIB_NOR);
                           sc_cell->set_Pass(false);

      assert( (int)sc_cell_pt_vec.size() == 3 && "Parser->nor_logic_module_cell");

      for(sc_cell_pt_iter cp  = sc_cell_pt_vec.begin(); 
                          cp != sc_cell_pt_vec.end(); ++cp){

           SC_Module::SC_Port_D *pp = static_cast<SC_Module::SC_Port_D*>(*cp);

           assert( pp!= NULL && "Parser->nor_logic_module_cell");
           sc_cell->set_PortVec(pp);

               if(inx == 0){ sc_nor->set_Dst(pp);   }
          else if(inx == 1){ sc_nor->set_Src1(pp);  }
          else             { sc_nor->set_Src2(pp);  }

        inx++;
      }

sc_cell_map[sc_cell_u_str] = sc_cell;

sc_cell_pt_vec.clear();

}
%}





%{
void set_xor_logic_module_cell(){
  
     int inx = 0;

     assert( !sc_cell_m_str.empty()  && 
             !sc_cell_u_str.empty()  &&
             !sc_cell_pt_vec.empty() && "Parser->xor_logic_module_cell"); 

     SC_Module::SC_Cell_D *sc_cell = new SC_Module::SC_Cell_D();
     SC_LIB::SC_XOR      *sc_xor = dynamic_cast<SC_LIB::SC_XOR*>(sc_cell);

     assert( sc_cell!=NULL && "Parser->xor_logic_module_cell");

                           sc_cell->set_Parent(NULL);
                           sc_cell->set_Self(NULL);
                           sc_cell->set_ModuleName(sc_cell_m_str);
                           sc_cell->set_CellName(sc_cell_u_str);
                           sc_cell->set_TLib(SC_Cell::SC_TLIB_XOR);
                           sc_cell->set_Pass(false);

      assert( (int)sc_cell_pt_vec.size() == 3 && "Parser->xor_logic_module_cell");

      for(sc_cell_pt_iter cp  = sc_cell_pt_vec.begin(); 
                          cp != sc_cell_pt_vec.end(); ++cp){

           SC_Module::SC_Port_D *pp = static_cast<SC_Module::SC_Port_D*>(*cp);

           assert( pp!= NULL && "Parser->xor_logic_module_cell");
           sc_cell->set_PortVec(pp);

               if(inx == 0){ sc_xor->set_Dst(pp);   }
          else if(inx == 1){ sc_xor->set_Src1(pp);  }
          else             { sc_xor->set_Src2(pp);  }

        inx++;
      }

sc_cell_map[sc_cell_u_str] = sc_cell;

sc_cell_pt_vec.clear();

}
%}





%{
void set_xnor_logic_module_cell(){
  
     int inx = 0;

     assert( !sc_cell_m_str.empty()  && 
             !sc_cell_u_str.empty()  &&
             !sc_cell_pt_vec.empty() && "Parser->xnor_logic_module_cell"); 

     SC_Module::SC_Cell_D *sc_cell = new SC_Module::SC_Cell_D();
     SC_LIB::SC_XNOR    *sc_xnor = dynamic_cast<SC_LIB::SC_XNOR*>(sc_cell);

     assert( sc_cell!=NULL && "Parser->xor_logic_module_cell");

                           sc_cell->set_Parent(NULL);
                           sc_cell->set_Self(NULL);
                           sc_cell->set_ModuleName(sc_cell_m_str);
                           sc_cell->set_CellName(sc_cell_u_str);
                           sc_cell->set_TLib(SC_Cell::SC_TLIB_XOR);
                           sc_cell->set_Pass(false);

      assert( (int)sc_cell_pt_vec.size() == 3 && "Parser->xnor_logic_module_cell");

      for(sc_cell_pt_iter cp  = sc_cell_pt_vec.begin(); 
                          cp != sc_cell_pt_vec.end(); ++cp){

           SC_Module::SC_Port_D *pp = static_cast<SC_Module::SC_Port_D*>(*cp);

           assert( pp!= NULL && "Parser->xnor_logic_module_cell");
           sc_cell->set_PortVec(pp);

               if(inx == 0){ sc_xnor->set_Dst(pp);   }
          else if(inx == 1){ sc_xnor->set_Src1(pp);  }
          else             { sc_xnor->set_Src2(pp);  }

        inx++;
      }

sc_cell_map[sc_cell_u_str] = sc_cell;

sc_cell_pt_vec.clear();

}
%}





%{
void set_buf_logic_module_cell(){
  
     int inx = 0;

     assert( !sc_cell_m_str.empty()  && 
             !sc_cell_u_str.empty()  &&
             !sc_cell_pt_vec.empty() && "Parser->buf_logic_module_cell"); 

     SC_Module::SC_Cell_D *sc_cell = new SC_Module::SC_Cell_D();
     SC_LIB::SC_BUF    *sc_buf     = dynamic_cast<SC_LIB::SC_BUF*>(sc_cell);

     assert( sc_cell!=NULL && "Parser->buf_logic_module_cell");

                           sc_cell->set_Parent(NULL);
                           sc_cell->set_Self(NULL);
                           sc_cell->set_ModuleName(sc_cell_m_str);
                           sc_cell->set_CellName(sc_cell_u_str);
                           sc_cell->set_TLib(SC_Cell::SC_TLIB_BUF);
                           sc_cell->set_Pass(false);

      assert( (int)sc_cell_pt_vec.size() == 2 && "Parser->buf_logic_module_cell");

      for(sc_cell_pt_iter cp  = sc_cell_pt_vec.begin(); 
                          cp != sc_cell_pt_vec.end(); ++cp){

           SC_Module::SC_Port_D *pp = static_cast<SC_Module::SC_Port_D*>(*cp);

           assert( pp!= NULL && "Parser->buf_logic_module_cell");
           sc_cell->set_PortVec(pp);

               if(inx == 0){ sc_buf->set_Dst(pp);  }
          else             { sc_buf->set_Src(pp);  }

        inx++;
      }

sc_cell_map[sc_cell_u_str] = sc_cell;

sc_cell_pt_vec.clear();

}
%}





%{
void set_inv_logic_module_cell(){
  
     int inx = 0;

     assert( !sc_cell_m_str.empty()  && 
             !sc_cell_u_str.empty()  &&
             !sc_cell_pt_vec.empty() && "Parser->inv_logic_module_cell"); 

     SC_Module::SC_Cell_D *sc_cell = new SC_Module::SC_Cell_D();
     SC_LIB::SC_INV    *sc_inv     = dynamic_cast<SC_LIB::SC_INV*>(sc_cell);

     assert( sc_cell!=NULL && "Parser->inv_logic_module_cell");

                           sc_cell->set_Parent(NULL);
                           sc_cell->set_Self(NULL);
                           sc_cell->set_ModuleName(sc_cell_m_str);
                           sc_cell->set_CellName(sc_cell_u_str);
                           sc_cell->set_TLib(SC_Cell::SC_TLIB_INV);
         
                           ( sc_pass == true )? sc_cell->set_Pass(true) :
                                                sc_cell->set_Pass(false);

      assert( (int)sc_cell_pt_vec.size() == 2 && "Parser->inv_logic_module_cell");

      for(sc_cell_pt_iter cp  = sc_cell_pt_vec.begin(); 
                          cp != sc_cell_pt_vec.end(); ++cp){

           SC_Module::SC_Port_D *pp = static_cast<SC_Module::SC_Port_D*>(*cp);

           assert( pp!= NULL && "Parser->inv_logic_module_cell");
           sc_cell->set_PortVec(pp);

               if(inx == 0){ sc_inv->set_Dst(pp);  }
          else             { sc_inv->set_Src(pp);  }

        inx++;
      }

sc_cell_map[sc_cell_u_str] = sc_cell;

sc_cell_pt_vec.clear();

}
%}





%{
void add_inv_logic_module_cell(){


     for( sc_inv_iter inv_it  = sc_inv.begin(); 
                      inv_it != sc_inv.end();   ++inv_it){

     sc_cell_m_str = "not";
     set_cell_unique_name();

     SC_Module::SC_Cell_D *sc_cell = new SC_Module::SC_Cell_D();
     SC_LIB::SC_INV       *sc_inv  = dynamic_cast<SC_LIB::SC_INV*>(sc_cell);

     assert( sc_cell!=NULL && "Parser->add_inv_logic_module_cell");

                           sc_cell->set_Parent(NULL);
                           sc_cell->set_Self(NULL);
                           sc_cell->set_ModuleName(sc_cell_m_str);
                           sc_cell->set_CellName(sc_cell_u_str);
                           sc_cell->set_TLib(SC_Cell::SC_TLIB_INV);
                           
                           SC_Domain_D *sc_cell_dm  = dynamic_cast<SC_Domain_D*>(sc_cell);
                           SC_Pass_D   *sc_cell_ps  = dynamic_cast<SC_Pass_D*>  (sc_cell);

                           ( sc_pass == true )? sc_cell_ps->set_Pass(true) :
                                                sc_cell_ps->set_Pass(false);

     SC_Module::SC_Port_D *sc_module_org_p = ( sc_in_pt_map.find((*inv_it)) != sc_in_pt_map.end() )? sc_in_pt_map[(*inv_it)] :
                                             ( sc_ot_pt_map.find((*inv_it)) != sc_ot_pt_map.end() )? sc_ot_pt_map[(*inv_it)] :
                                             ( sc_wr_pt_map.find((*inv_it)) != sc_wr_pt_map.end() )? sc_wr_pt_map[(*inv_it)] : NULL;




     SC_Module::SC_Port_D *sc_module_new_p = new SC_Module::SC_Port_D();

     assert( sc_module_org_p!=NULL &&
             sc_module_new_p!=NULL && "Parser->add_inv_logic_module_cell");

             sc_module_new_p->set_Name("__sc_inv__"+(*inv_it));
             sc_module_new_p->set_Parent(NULL);

             SC_Time_D   *sc_module_new_tm  = dynamic_cast<SC_Time_D*>  (sc_module_new_p);
             SC_Power_D  *sc_module_new_pr  = dynamic_cast<SC_Power_D*> (sc_module_new_p);
             SC_Logic_D  *sc_module_new_lg  = dynamic_cast<SC_Logic_D*> (sc_module_new_p);
             SC_Type_D   *sc_module_new_tp  = dynamic_cast<SC_Type_D*>  (sc_module_new_p); 
             SC_Domain_D *sc_module_new_dm  = dynamic_cast<SC_Domain_D*>(sc_module_new_p);
             SC_Pass_D   *sc_module_new_ps  = dynamic_cast<SC_Pass_D*>  (sc_module_new_p);

             sc_module_new_tm->set_ArriveTime(0);
             sc_module_new_pr->set_SwitchPower(0);
             sc_module_new_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
             sc_module_new_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
             sc_module_new_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

             ( sc_pass == true )? sc_module_new_ps->set_Pass(true) :
                                  sc_module_new_ps->set_Pass(false);

             sc_wr_pt_map["__sc_inv__"+(*inv_it)] = sc_module_new_p;



 
     SC_Module::SC_Port_D *sc_inv_s_p = new SC_Module::SC_Port_D();
     SC_Module::SC_Port_D *sc_inv_d_p = new SC_Module::SC_Port_D();

     assert( sc_inv_s_p!=NULL &&
             sc_inv_d_p!=NULL && "Parser->add_inv_logic_module_cell");

             sc_inv_s_p->set_Name((*inv_it));
             sc_inv_s_p->set_Parent(NULL); 

             SC_Time_D   *sc_inv_s_tm  = dynamic_cast<SC_Time_D*>  (sc_inv_s_p);
             SC_Power_D  *sc_inv_s_pr  = dynamic_cast<SC_Power_D*> (sc_inv_s_p);
             SC_Logic_D  *sc_inv_s_lg  = dynamic_cast<SC_Logic_D*> (sc_inv_s_p);
             SC_Type_D   *sc_inv_s_tp  = dynamic_cast<SC_Type_D*>  (sc_inv_s_p); 
             SC_Domain_D *sc_inv_s_dm  = dynamic_cast<SC_Domain_D*>(sc_inv_s_p);
             SC_Pass_D   *sc_inv_s_ps  = dynamic_cast<SC_Pass_D*>  (sc_inv_s_p);

             sc_inv_s_tm->set_ArriveTime(0);
             sc_inv_s_pr->set_SwitchPower(0);
             sc_inv_s_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
             sc_inv_s_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
             sc_inv_s_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

             ( sc_pass == true )? sc_inv_s_ps->set_Pass(true) :
                                  sc_inv_s_ps->set_Pass(false);





             sc_inv_d_p->set_Name("__sc_inv__"+(*inv_it));
             sc_inv_d_p->set_Parent(NULL);
  
             SC_Time_D   *sc_inv_d_tm  = dynamic_cast<SC_Time_D*>  (sc_inv_d_p);
             SC_Power_D  *sc_inv_d_pr  = dynamic_cast<SC_Power_D*> (sc_inv_d_p);
             SC_Logic_D  *sc_inv_d_lg  = dynamic_cast<SC_Logic_D*> (sc_inv_d_p);
             SC_Type_D   *sc_inv_d_tp  = dynamic_cast<SC_Type_D*>  (sc_inv_d_p); 
             SC_Domain_D *sc_inv_d_dm  = dynamic_cast<SC_Domain_D*>(sc_inv_d_p);
             SC_Pass_D   *sc_inv_d_ps  = dynamic_cast<SC_Pass_D*>  (sc_inv_d_p);

             sc_inv_d_tm->set_ArriveTime(0);
             sc_inv_d_pr->set_SwitchPower(0);
             sc_inv_d_lg->set_PreLogic(SC_Logic_D::SC_LOGIC_x);
             sc_inv_d_lg->set_CurLogic(SC_Logic_D::SC_LOGIC_x);
             sc_inv_d_tp->set_Type(SC_Type_D::SC_TYPE_WIRE);

              ( sc_pass == true )? sc_inv_d_ps->set_Pass(true) :
                                   sc_inv_d_ps->set_Pass(false);





             sc_cell->set_PortVec(sc_inv_d_p);
             sc_cell->set_PortVec(sc_inv_s_p);

             sc_module_org_p->set_NxtPortVec(sc_inv_s_p);
             sc_inv_s_p->set_PrePortVec(sc_module_org_p);

             sc_module_new_p->set_NxtPortVec(sc_inv_d_p);
             sc_inv_d_p->set_PrePortVec(sc_module_new_p);
             
             sc_inv->set_Src(sc_inv_s_p);
             sc_inv->set_Dst(sc_inv_d_p);
             
       sc_cell_map[sc_cell_u_str] = sc_cell;
    }

sc_inv.clear();

}
%}




%union {

        std::string      *sc_string;
        int              *sc_int;
	int              token;
}



%token <token> TMODULE  TEDMODULE
%token <token> TINPUT   TOUTPUT    TWIRE
%token <token> TEND
%token <token> TRSQUARE TLSQUARE
%token <token> TCOLON

%token <token>  TINV
%token <token>  TAND  TNAND
%token <token>  TOR   TNOR
%token <token>  TXOR  TXNOR
%token <token>  TBUF  TNOT
%token <token>  TDFF
%token <token>  TLIBRARY
%token <token>  TDESIGN

%token <sc_string> TIDENTIFIER TINTEGER TDOUBLE
%token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token <token> TLPAREN TRPAREN TLBRACE TRBRACE TCOMMA TDOT
%token <token> TPLUS TMINUS TMUL TDIV



%start program

%%

program              : top_stmt {}
                     ;


top_stmt             :          TCLT TLIBRARY { sc_pass = false; } TCGT modules_stmt TCLT TDIV TLIBRARY TCGT 
                     | top_stmt TCLT TDESIGN  { sc_pass = true;  } TCGT modules_stmt TCLT TDIV TDESIGN  TCGT  
                     ; 

modules_stmt         :              TMODULE module_signal_stmt module_contains_stmt TEDMODULE
                     {
                                    set_module();
                                    
                                    #ifdef SC_Debug  
                                           sc_dump("@ SC_Module " + sc_module_str + " Pass");
                                    #endif 
                     }
 
                     | modules_stmt TMODULE module_signal_stmt module_contains_stmt TEDMODULE 
                     {

                                    set_module();

                                    #ifdef SC_Debug 
                                           sc_dump("@ SC_Module " + sc_module_str + " Pass"); 
                                    #endif
                     }
       //              | error        { sc_dump("Error in modules_stmt"); }
                     ;  




module_signal_stmt   : TIDENTIFIER TLPAREN module_vector_stmt TRPAREN TEND 
                     {         
                                    sc_module_str = (*$<sc_string>1);   
                              
                                    set_module_signal(); 
                     } 
                     ; 



module_contains_stmt :                      module_input_stmt  { 
                                            #ifdef SC_Debug 
                                                   sc_dump("    SC_Module_Input_Pass");  
                                            #endif 
                     } 
                     |                      module_output_stmt { 
                                            #ifdef SC_Debug 
                                                   sc_dump("    SC_Module_Output_Pass"); 
                                            #endif
                     }
                     |                      module_wire_stmt   {
                                            #ifdef SC_Debug   
                                                   sc_dump("    SC_Module_Wire_Pass");   
                                            #endif
                     }
                     |                      module_cell_stmt   { 
                                            #ifdef SC_Debug 
                                                   sc_dump("    SC_Module_Cell_Pass");  
                                            #endif
                     }
                     | module_contains_stmt module_input_stmt  { 
                                            #ifdef SC_Debug 
                                                   sc_dump("    SC_Module_Input_Pass");  
                                            #endif 
                     } 
                     | module_contains_stmt module_output_stmt { 
                                            #ifdef SC_Debug 
                                                   sc_dump("    SC_Module_Output_Pass"); 
                                            #endif
                     }
                     | module_contains_stmt module_wire_stmt   { 
                                            #ifdef SC_Debug 
                                                   sc_dump("    SC_Module_Wire_Pass");   
                                            #endif
                     }
                     | module_contains_stmt module_cell_stmt   {
                                            #ifdef SC_Debug 
                                                   sc_dump("    SC_Module_Cell_Pass");   
                                            #endif
                     }  
                     ;




module_input_stmt    : TINPUT TLSQUARE TINTEGER TCOLON TINTEGER TRSQUARE module_vector_stmt TEND 
                     {  
                       sc_msb = atoi((*$<sc_string>3).c_str());
                       sc_lsb = atoi((*$<sc_string>5).c_str());
                       
                       set_module_input_div();
                     }

                     | TINPUT module_vector_stmt TEND 
                     {
                       sc_msb = 0;
                       sc_lsb = 0;

                       set_module_input_only(); 
                     }
                     ;




module_output_stmt   : TOUTPUT TLSQUARE TINTEGER TCOLON TINTEGER TRSQUARE module_vector_stmt TEND 
                     {
                       sc_msb = atoi((*$<sc_string>3).c_str());
                       sc_lsb = atoi((*$<sc_string>5).c_str());
                       
                       set_module_output_div();
                     } 

                     | TOUTPUT module_vector_stmt TEND 
                     {
                        sc_msb = 0;
                        sc_lsb = 0;

                       set_module_output_only();
                     }
                     ;



module_wire_stmt     : TWIRE TLSQUARE TINTEGER TCOLON TINTEGER TRSQUARE module_vector_stmt TEND 
                     {
                       sc_msb = atoi((*$<sc_string>3).c_str());
                       sc_lsb = atoi((*$<sc_string>5).c_str());
                       
                       set_module_wire_div();
                     }

                     | TWIRE module_vector_stmt TEND 
                     {
                        sc_msb = 0;
                        sc_lsb = 0;

                        set_module_wire_only();
                     }
                     ;



module_cell_stmt     : TAND TIDENTIFIER TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "and";
                                       sc_cell_u_str = (*$<sc_string>2);

                                       set_and_logic_module_cell();
                     }

                     | TAND TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "and";

                                       set_cell_unique_name();
                                       set_and_logic_module_cell();
                     }

                     | TNAND TIDENTIFIER TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "nand";
                                       sc_cell_u_str = (*$<sc_string>2);

                                       set_nand_logic_module_cell();
                     }

                     | TNAND TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "nand";

                                       set_cell_unique_name();
                                       set_nand_logic_module_cell();
                     }

                     | TOR TIDENTIFIER TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "or";
                                       sc_cell_u_str = (*$<sc_string>2);

                                       set_or_logic_module_cell();
                     }

                     | TOR TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "or";

                                       set_cell_unique_name();
                                       set_or_logic_module_cell();
                     }

                     | TNOR TIDENTIFIER TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "nor";
                                       sc_cell_u_str = (*$<sc_string>2);

                                       set_nor_logic_module_cell();
                     }

                     | TNOR TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "nor";

                                       set_cell_unique_name();
                                       set_nor_logic_module_cell();
                     }

                     | TXOR TIDENTIFIER TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "xor";
                                       sc_cell_u_str = (*$<sc_string>2);

                                       set_xor_logic_module_cell();
                     }

                     | TXOR TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "xor";

                                       set_cell_unique_name();
                                       set_xor_logic_module_cell();
                     }

                     | TXNOR TIDENTIFIER TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "xnor";
                                       sc_cell_u_str = (*$<sc_string>2);

                                       set_xnor_logic_module_cell();
                     }

                     | TXNOR TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "xnor";

                                       set_cell_unique_name();
                                       set_xnor_logic_module_cell();
                     }

                     | TBUF TIDENTIFIER TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "buf";
                                       sc_cell_u_str = (*$<sc_string>2);

                                       set_buf_logic_module_cell();
                     }

                     | TBUF TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "buf";

                                       set_cell_unique_name();
                                       set_buf_logic_module_cell();
                     }

                     | TNOT TIDENTIFIER TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "not";
                                       sc_cell_u_str = (*$<sc_string>2);

                                       set_inv_logic_module_cell();
                     }

                     | TNOT TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = "not";

                                       set_cell_unique_name();
                                       set_inv_logic_module_cell();
                     }

                     | TIDENTIFIER TIDENTIFIER TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = (*$<sc_string>1);
                                       sc_cell_u_str = (*$<sc_string>2);

                                       set_module_cell();
                     }

                     | TIDENTIFIER TLPAREN module_links_stmt TRPAREN TEND
                     {
                                       sc_cell_m_str = (*$<sc_string>1);

                                       set_cell_unique_name();
                                       set_module_cell();
                     }
                     ;




module_links_stmt    :                   TDOT TIDENTIFIER TLPAREN module_vector_stmt TRPAREN
                     {
                                         sc_cell_p_str = (*$<sc_string>2);
                                         add_inv_logic_module_cell();
                                         set_module_links_indirect();
                     }                        

                     |                   TDOT TIDENTIFIER TLPAREN TLBRACE module_vector_stmt TRBRACE TRPAREN        
                     {
                                         sc_cell_p_str = (*$<sc_string>2);
                                         add_inv_logic_module_cell();
                                         set_module_links_indirect();
                     }

                     |                   module_ident_stmt    
                     {
                                         sc_cell_p_str = "";
                                         add_inv_logic_module_cell();
                                         set_module_links_direct();
                     }

                     |                   TLBRACE module_vector_stmt TRBRACE 
                     {
                                         sc_cell_p_str = "";
                                         add_inv_logic_module_cell();
                                         set_module_links_direct();
                     }                                             

                     | module_links_stmt TCOMMA TDOT TIDENTIFIER TLPAREN module_vector_stmt TRPAREN
                     {
                                         sc_cell_p_str = (*$<sc_string>4);
                                         add_inv_logic_module_cell();
                                         set_module_links_indirect();         

                     }                        

                     | module_links_stmt TCOMMA TDOT TIDENTIFIER TLPAREN TLBRACE module_vector_stmt TRBRACE TRPAREN        
                     {
                                         sc_cell_p_str = (*$<sc_string>4);
                                         add_inv_logic_module_cell();
                                         set_module_links_indirect();   

                     }

                     | module_links_stmt TCOMMA module_ident_stmt
                     {
                                         sc_cell_p_str = "";
                                         add_inv_logic_module_cell();
                                         set_module_links_direct();
 
                     }               

                     | module_links_stmt TCOMMA TLBRACE module_vector_stmt TRBRACE 
                     {
                                         sc_cell_p_str = "";
                                         add_inv_logic_module_cell();
                                         set_module_links_direct();
                     } 
                                            
         //            | error { sc_dump("Error in module_links_stmt"); } 
                     ;


module_ident_stmt    : TIDENTIFIER
                     {
                                          sc_vv.push_back(*$<sc_string>1);
                     }

                     | TINV TIDENTIFIER   
                     {                    
                                          std::string nm = (*$<sc_string>2);
                                          sc_vv.push_back("__sc_inv__"+nm);
                                          sc_inv.push_back((*$<sc_string>2));
                     }                    

                     | TIDENTIFIER TLSQUARE TINTEGER TRSQUARE
                     {
                                          std::string nm = (*$<sc_string>1) + "[" + (*$<sc_string>3) + "]"; 
                                          sc_vv.push_back(nm);
                     }

                     | TINV TIDENTIFIER TLSQUARE TINTEGER TRSQUARE
                     {
                                          std::string nm = (*$<sc_string>2) + "[" + (*$<sc_string>4) + "]";
                                          sc_vv.push_back("__sc_inv__"+nm);
                                          sc_inv.push_back(nm);
                     }

                     | TIDENTIFIER TLSQUARE TINTEGER TCOLON TINTEGER TRSQUARE
                     {
                                          sc_msb       = atoi((*$<sc_string>3).c_str());
                                          sc_lsb       = atoi((*$<sc_string>5).c_str());
                                          sc_token_str = (*$<sc_string>1);

                                          set_module_vector_div();
                     }

                     | TINV TIDENTIFIER TLSQUARE TINTEGER TCOLON TINTEGER TRSQUARE
                     {
                                          sc_msb = atoi((*$<sc_string>4).c_str());
                                          sc_lsb = atoi((*$<sc_string>6).c_str());
                                          sc_token_str = (*$<sc_string>2);

                                          set_moudle_vector_inv_div();
                     }
                     ;



module_vector_stmt   :                    TIDENTIFIER        
                     { 
                                          sc_vv.push_back((*$<sc_string>1)); 
                     } 

                     |                    TINV TIDENTIFIER   
                     {                    
                                          std::string nm = (*$<sc_string>2);
                                          sc_vv.push_back("__sc_inv__"+nm);
                                          sc_inv.push_back(nm);
                     }                    

                     |                    TIDENTIFIER TLSQUARE TINTEGER TRSQUARE
                     {
                                          std::string nm = (*$<sc_string>1) + "[" + (*$<sc_string>3) + "]";
                                          sc_vv.push_back(nm);
                     }

                     |                    TINV TIDENTIFIER TLSQUARE TINTEGER TRSQUARE
                     {
                                          std::string nm = (*$<sc_string>2) + "[" + (*$<sc_string>4) + "]";
                                          sc_vv.push_back("__sc_inv__"+nm);
                                          sc_inv.push_back(nm);
                     }

                     |                    TIDENTIFIER TLSQUARE TINTEGER TCOLON TINTEGER TRSQUARE
                     {
                                          sc_msb = atoi((*$<sc_string>3).c_str());
                                          sc_lsb = atoi((*$<sc_string>5).c_str());
                                          sc_token_str = (*$<sc_string>1);

                                          set_module_vector_div();
                     }
  
                     |                    TINV TIDENTIFIER TLSQUARE TINTEGER TCOLON TINTEGER TRSQUARE
                     {

                                          sc_msb = atoi((*$<sc_string>4).c_str());
                                          sc_lsb = atoi((*$<sc_string>6).c_str());
                                          sc_token_str = (*$<sc_string>2);

                                          set_moudle_vector_inv_div();
                     }

                     | module_vector_stmt TCOMMA TIDENTIFIER 
                     { 
                                          sc_vv.push_back((*$<sc_string>3));
                     } 

                     | module_vector_stmt TCOMMA TINV TIDENTIFIER
                     {
                                          std::string nm = (*$<sc_string>2);
                                          sc_vv.push_back("__sc_inv__"+nm);
                                          sc_inv.push_back(nm);
                     }
 
                     | module_vector_stmt TCOMMA TIDENTIFIER TLSQUARE TINTEGER TRSQUARE
                     {
                                          std::string nm = (*$<sc_string>1) + "[" + (*$<sc_string>3) + "]";
                                          sc_vv.push_back(nm);
                     }

                     | module_vector_stmt TCOMMA TINV TIDENTIFIER TLSQUARE TINTEGER TRSQUARE
                     {
                                          std::string nm = (*$<sc_string>2) + "[" + (*$<sc_string>4) + "]";
                                          sc_vv.push_back("__sc_inv__"+nm);
                                          sc_inv.push_back(nm);
                     }

                     | module_vector_stmt TCOMMA TIDENTIFIER TLSQUARE TINTEGER TCOLON TINTEGER TRSQUARE
                     {
                                          sc_msb       = atoi((*$<sc_string>5).c_str());
                                          sc_lsb       = atoi((*$<sc_string>7).c_str());
                                          sc_token_str = (*$<sc_string>3);

                                          set_module_vector_div();
                     }

                     | module_vector_stmt TCOMMA TINV TIDENTIFIER TLSQUARE TINTEGER TCOLON TINTEGER TRSQUARE
                     {
                                          sc_msb       = atoi((*$<sc_string>6).c_str());
                                          sc_lsb       = atoi((*$<sc_string>8).c_str());
                                          sc_token_str = (*$<sc_string>4);

                                          set_moudle_vector_inv_div();
                     }
                     ;
      



%%
