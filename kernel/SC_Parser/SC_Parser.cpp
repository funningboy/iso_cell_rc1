
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         SC_parse
#define yylex           SC_lex
#define yyerror         SC_error
#define yylval          SC_lval
#define yychar          SC_char
#define yydebug         SC_debug
#define yynerrs         SC_nerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

                  

/* Line 189 of yacc.c  */
#line 91 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 108 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 260 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

void set_module_signal(){

     assert( !sc_vv.empty() && "Parser->module_signal" );

     sc_sig_pt_vec  = sc_vv;
 
sc_vv.clear();

}

/* Line 189 of yacc.c  */
#line 276 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 335 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 382 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 441 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 486 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 545 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 594 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

void set_cell_unique_name(){

    assert( !sc_cell_m_str.empty()  &&  "Parser->cell_unique_name" );

    std::stringstream ss;
    ss << sc_cell_u_inx++;

    sc_cell_u_str = "_" + sc_cell_m_str + "_" + ss.str() + "_";
    ss.str("");

}

/* Line 189 of yacc.c  */
#line 613 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 656 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 865 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 1053 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 1075 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 1098 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 1147 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 1196 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 1245 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 1294 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 1343 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 1392 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 1440 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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

/* Line 189 of yacc.c  */
#line 1490 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"

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


/* Line 189 of yacc.c  */
#line 1635 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TMODULE = 258,
     TEDMODULE = 259,
     TINPUT = 260,
     TOUTPUT = 261,
     TWIRE = 262,
     TEND = 263,
     TRSQUARE = 264,
     TLSQUARE = 265,
     TCOLON = 266,
     TINV = 267,
     TAND = 268,
     TNAND = 269,
     TOR = 270,
     TNOR = 271,
     TXOR = 272,
     TXNOR = 273,
     TBUF = 274,
     TNOT = 275,
     TDFF = 276,
     TLIBRARY = 277,
     TDESIGN = 278,
     TIDENTIFIER = 279,
     TINTEGER = 280,
     TDOUBLE = 281,
     TCEQ = 282,
     TCNE = 283,
     TCLT = 284,
     TCLE = 285,
     TCGT = 286,
     TCGE = 287,
     TEQUAL = 288,
     TLPAREN = 289,
     TRPAREN = 290,
     TLBRACE = 291,
     TRBRACE = 292,
     TCOMMA = 293,
     TDOT = 294,
     TPLUS = 295,
     TMINUS = 296,
     TMUL = 297,
     TDIV = 298
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 1628 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"


        std::string      *sc_string;
        int              *sc_int;
	int              token;



/* Line 214 of yacc.c  */
#line 1723 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 1735 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  236

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,    16,    17,    28,    33,    39,
      45,    47,    49,    51,    53,    56,    59,    62,    65,    74,
      78,    87,    91,   100,   104,   111,   117,   124,   130,   137,
     143,   150,   156,   163,   169,   176,   182,   189,   195,   202,
     208,   215,   221,   227,   235,   237,   241,   249,   259,   263,
     269,   271,   274,   279,   285,   292,   300,   302,   305,   310,
     316,   323,   331,   335,   340,   347,   355,   364
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    46,    -1,    -1,    29,    22,    47,    31,
      49,    29,    43,    22,    31,    -1,    -1,    46,    29,    23,
      48,    31,    49,    29,    43,    23,    31,    -1,     3,    50,
      51,     4,    -1,    49,     3,    50,    51,     4,    -1,    24,
      34,    58,    35,     8,    -1,    52,    -1,    53,    -1,    54,
      -1,    55,    -1,    51,    52,    -1,    51,    53,    -1,    51,
      54,    -1,    51,    55,    -1,     5,    10,    25,    11,    25,
       9,    58,     8,    -1,     5,    58,     8,    -1,     6,    10,
      25,    11,    25,     9,    58,     8,    -1,     6,    58,     8,
      -1,     7,    10,    25,    11,    25,     9,    58,     8,    -1,
       7,    58,     8,    -1,    13,    24,    34,    56,    35,     8,
      -1,    13,    34,    56,    35,     8,    -1,    14,    24,    34,
      56,    35,     8,    -1,    14,    34,    56,    35,     8,    -1,
      15,    24,    34,    56,    35,     8,    -1,    15,    34,    56,
      35,     8,    -1,    16,    24,    34,    56,    35,     8,    -1,
      16,    34,    56,    35,     8,    -1,    17,    24,    34,    56,
      35,     8,    -1,    17,    34,    56,    35,     8,    -1,    18,
      24,    34,    56,    35,     8,    -1,    18,    34,    56,    35,
       8,    -1,    19,    24,    34,    56,    35,     8,    -1,    19,
      34,    56,    35,     8,    -1,    20,    24,    34,    56,    35,
       8,    -1,    20,    34,    56,    35,     8,    -1,    24,    24,
      34,    56,    35,     8,    -1,    24,    34,    56,    35,     8,
      -1,    39,    24,    34,    58,    35,    -1,    39,    24,    34,
      36,    58,    37,    35,    -1,    57,    -1,    36,    58,    37,
      -1,    56,    38,    39,    24,    34,    58,    35,    -1,    56,
      38,    39,    24,    34,    36,    58,    37,    35,    -1,    56,
      38,    57,    -1,    56,    38,    36,    58,    37,    -1,    24,
      -1,    12,    24,    -1,    24,    10,    25,     9,    -1,    12,
      24,    10,    25,     9,    -1,    24,    10,    25,    11,    25,
       9,    -1,    12,    24,    10,    25,    11,    25,     9,    -1,
      24,    -1,    12,    24,    -1,    24,    10,    25,     9,    -1,
      12,    24,    10,    25,     9,    -1,    24,    10,    25,    11,
      25,     9,    -1,    12,    24,    10,    25,    11,    25,     9,
      -1,    58,    38,    24,    -1,    58,    38,    12,    24,    -1,
      58,    38,    24,    10,    25,     9,    -1,    58,    38,    12,
      24,    10,    25,     9,    -1,    58,    38,    24,    10,    25,
      11,    25,     9,    -1,    58,    38,    12,    24,    10,    25,
      11,    25,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1663,  1663,  1667,  1667,  1668,  1668,  1671,  1680,  1695,
    1705,  1710,  1715,  1720,  1725,  1730,  1735,  1740,  1750,  1758,
    1770,  1778,  1789,  1797,  1808,  1816,  1824,  1832,  1840,  1848,
    1856,  1864,  1872,  1880,  1888,  1896,  1904,  1912,  1920,  1928,
    1936,  1944,  1956,  1963,  1970,  1977,  1984,  1992,  2000,  2008,
    2019,  2024,  2031,  2037,  2044,  2053,  2065,  2070,  2077,  2083,
    2090,  2099,  2109,  2114,  2121,  2127,  2134,  2143
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TMODULE", "TEDMODULE", "TINPUT",
  "TOUTPUT", "TWIRE", "TEND", "TRSQUARE", "TLSQUARE", "TCOLON", "TINV",
  "TAND", "TNAND", "TOR", "TNOR", "TXOR", "TXNOR", "TBUF", "TNOT", "TDFF",
  "TLIBRARY", "TDESIGN", "TIDENTIFIER", "TINTEGER", "TDOUBLE", "TCEQ",
  "TCNE", "TCLT", "TCLE", "TCGT", "TCGE", "TEQUAL", "TLPAREN", "TRPAREN",
  "TLBRACE", "TRBRACE", "TCOMMA", "TDOT", "TPLUS", "TMINUS", "TMUL",
  "TDIV", "$accept", "program", "top_stmt", "$@1", "$@2", "modules_stmt",
  "module_signal_stmt", "module_contains_stmt", "module_input_stmt",
  "module_output_stmt", "module_wire_stmt", "module_cell_stmt",
  "module_links_stmt", "module_ident_stmt", "module_vector_stmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    47,    46,    48,    46,    49,    49,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    57,    57,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     9,     0,    10,     4,     5,     5,
       1,     1,     1,     1,     2,     2,     2,     2,     8,     3,
       8,     3,     8,     3,     6,     5,     6,     5,     6,     5,
       6,     5,     6,     5,     6,     5,     6,     5,     6,     5,
       6,     5,     5,     7,     1,     3,     7,     9,     3,     5,
       1,     2,     4,     5,     6,     7,     1,     2,     4,     5,
       6,     7,     3,     4,     6,     7,     8,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     3,     1,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     7,    14,    15,
      16,    17,     0,     0,     0,    57,     0,     0,     0,     0,
      19,     0,    21,     0,    23,     0,     0,    50,     0,     0,
       0,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     4,
       0,     0,     0,     9,     0,    62,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     0,    58,     0,    63,     0,     0,     0,
       0,     0,     0,     0,    45,     0,    25,     0,     0,    48,
       0,    27,     0,    29,     0,    31,     0,    33,     0,    35,
       0,    37,     0,    39,     0,    41,    59,     0,     0,     0,
       0,     0,     0,     0,    24,     0,    52,     0,     0,     0,
       0,     0,    26,    28,    30,    32,    34,    36,    38,    40,
       0,    60,     0,    64,     0,     0,     0,     0,    53,     0,
       0,     0,    42,    49,     0,    61,    65,     0,     0,    18,
      20,    22,     0,    54,     0,     0,     0,     0,    66,    55,
      43,     0,    46,    67,     0,    47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     7,    10,    12,    15,    32,    33,    34,
      35,    36,    90,    91,    42
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -50
static const yytype_int16 yypact[] =
{
      -6,    12,    82,    54,   -50,   -50,    93,    65,   -50,   133,
      99,   124,    11,   133,   104,   127,   124,   117,    34,     8,
       6,     9,    15,     7,    45,    46,    47,    73,    74,    85,
      94,   105,    86,   -50,   -50,   -50,   -50,   127,   181,   122,
     188,   201,     0,   189,     4,   192,    14,   193,    16,   179,
      48,   182,    48,   185,    48,   194,    48,   196,    48,   197,
      48,   198,    48,   199,    48,   200,    48,   -50,   -50,   -50,
     -50,   -50,   107,   184,   202,   210,   204,   213,    52,   211,
     -50,   212,   -50,   215,   -50,    48,   203,   214,     8,   216,
      40,   -50,    48,   114,    48,   115,    48,   119,    48,   120,
      48,   121,    48,   129,    48,   131,    48,   135,   -50,   -50,
     205,   217,   106,   -50,   219,   225,   220,   221,   222,   136,
     227,   223,    29,   207,   230,    49,   137,   231,   141,   236,
     142,   241,   143,   242,   147,   243,   148,   244,   149,   245,
     153,   246,   -50,   186,   -50,   232,   248,   234,   247,   251,
     252,   254,   238,   187,   -50,    50,   -50,     8,   240,   -50,
     257,   -50,   258,   -50,   259,   -50,   260,   -50,   261,   -50,
     262,   -50,   263,   -50,   264,   -50,   -50,   249,   266,   253,
     190,     8,     8,     8,   -50,   191,   -50,   255,     8,   154,
      57,   239,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     267,   -50,   195,   -50,   256,    18,    20,    21,   -50,   265,
     268,   170,   -50,   -50,    53,   -50,   -50,   269,   270,   -50,
     -50,   -50,   273,   -50,   250,     8,   155,   274,   -50,   -50,
     -50,   172,   -50,   -50,   271,   -50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,   -50,   -50,   -50,   275,   276,   218,   -28,   -26,
     -24,   -22,   -49,   159,   -20
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      44,    46,    48,    93,    68,    95,    69,    97,    70,    99,
      71,   101,    80,   103,    16,   105,    43,   107,    40,    45,
      40,    40,    82,     1,    84,    47,   219,    40,   220,   221,
      41,    49,    41,    41,     4,    77,   119,    16,    78,    41,
      17,    50,    78,   126,    68,   128,    69,   130,    70,   132,
      71,   134,    78,   136,    78,   138,    78,   140,    78,    78,
      86,    86,    40,    39,   114,    40,   154,    78,   122,    51,
      53,    55,    87,    87,    41,   124,   115,    41,   125,    52,
      54,    56,     5,     6,    88,   157,   188,    89,   158,   225,
      67,    20,    21,    22,   213,    78,     9,    57,    59,    23,
      24,    25,    26,    27,    28,    29,    30,    58,    60,    61,
      31,   108,    20,    21,    22,   144,     8,   145,    63,    62,
      23,    24,    25,    26,    27,    28,    29,    30,    64,    65,
      13,    31,    20,    21,    22,   189,    11,   190,    19,    66,
      23,    24,    25,    26,    27,    28,    29,    30,    14,   127,
     129,    31,   125,   125,   131,   133,   135,   125,   125,   125,
      38,   205,   206,   207,   137,    74,   139,   125,   211,   125,
     141,   151,   160,   125,   125,   125,   162,   164,   166,   125,
     125,   125,   168,   170,   172,   125,   125,   125,   174,   212,
     232,   125,    78,    78,   226,   176,   186,   177,   187,   203,
     208,   204,   209,    73,   216,   231,   217,   224,    78,   234,
      78,    76,    75,    85,    79,   109,    92,    81,    83,    94,
     111,   113,   116,   117,   121,   110,   118,   120,    96,   112,
      98,   100,   102,   104,   106,   147,   142,   152,   156,   161,
     123,   155,   143,   146,   163,   148,   149,   150,   153,   165,
     167,   169,   171,   173,   175,    72,   181,   178,   179,   180,
     182,   183,   184,   185,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   214,   200,   201,   215,   223,   202,   228,
     210,   218,   229,   233,   159,   230,     0,     0,    18,     0,
     222,     0,    37,     0,   227,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   235
};

static const yytype_int16 yycheck[] =
{
      20,    21,    22,    52,    32,    54,    32,    56,    32,    58,
      32,    60,     8,    62,     3,    64,    10,    66,    12,    10,
      12,    12,     8,    29,     8,    10,     8,    12,     8,     8,
      24,    24,    24,    24,    22,    35,    85,     3,    38,    24,
      29,    34,    38,    92,    72,    94,    72,    96,    72,    98,
      72,   100,    38,   102,    38,   104,    38,   106,    38,    38,
      12,    12,    12,    29,    12,    12,    37,    38,    88,    24,
      24,    24,    24,    24,    24,    35,    24,    24,    38,    34,
      34,    34,     0,    29,    36,    36,    36,    39,    39,    36,
       4,     5,     6,     7,    37,    38,    31,    24,    24,    13,
      14,    15,    16,    17,    18,    19,    20,    34,    34,    24,
      24,     4,     5,     6,     7,     9,    23,    11,    24,    34,
      13,    14,    15,    16,    17,    18,    19,    20,    34,    24,
      31,    24,     5,     6,     7,   155,     3,   157,    34,    34,
      13,    14,    15,    16,    17,    18,    19,    20,    24,    35,
      35,    24,    38,    38,    35,    35,    35,    38,    38,    38,
      43,   181,   182,   183,    35,    43,    35,    38,   188,    38,
      35,    35,    35,    38,    38,    38,    35,    35,    35,    38,
      38,    38,    35,    35,    35,    38,    38,    38,    35,    35,
      35,    38,    38,    38,   214,     9,     9,    11,    11,     9,
       9,    11,    11,    22,     9,   225,    11,    37,    38,    37,
      38,    10,    24,    34,    25,    31,    34,    25,    25,    34,
      10,     8,    11,    11,    10,    23,    11,    24,    34,    25,
      34,    34,    34,    34,    34,    10,    31,    10,     8,     8,
      24,    34,    25,    24,     8,    25,    25,    25,    25,     8,
       8,     8,     8,     8,     8,    37,     9,    25,    10,    25,
       9,     9,     8,    25,    24,     8,     8,     8,     8,     8,
       8,     8,     8,    34,    25,     9,     9,     9,    25,     9,
      25,    25,     9,     9,   125,    35,    -1,    -1,    13,    -1,
      25,    -1,    16,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    45,    46,    22,     0,    29,    47,    23,    31,
      48,     3,    49,    31,    24,    50,     3,    29,    49,    34,
       5,     6,     7,    13,    14,    15,    16,    17,    18,    19,
      20,    24,    51,    52,    53,    54,    55,    50,    43,    29,
      12,    24,    58,    10,    58,    10,    58,    10,    58,    24,
      34,    24,    34,    24,    34,    24,    34,    24,    34,    24,
      34,    24,    34,    24,    34,    24,    34,     4,    52,    53,
      54,    55,    51,    22,    43,    24,    10,    35,    38,    25,
       8,    25,     8,    25,     8,    34,    12,    24,    36,    39,
      56,    57,    34,    56,    34,    56,    34,    56,    34,    56,
      34,    56,    34,    56,    34,    56,    34,    56,     4,    31,
      23,    10,    25,     8,    12,    24,    11,    11,    11,    56,
      24,    10,    58,    24,    35,    38,    56,    35,    56,    35,
      56,    35,    56,    35,    56,    35,    56,    35,    56,    35,
      56,    35,    31,    25,     9,    11,    24,    10,    25,    25,
      25,    35,    10,    25,    37,    34,     8,    36,    39,    57,
      35,     8,    35,     8,    35,     8,    35,     8,    35,     8,
      35,     8,    35,     8,    35,     8,     9,    11,    25,    10,
      25,     9,     9,     9,     8,    25,     9,    11,    36,    58,
      58,    24,     8,     8,     8,     8,     8,     8,     8,     8,
      25,     9,    25,     9,    11,    58,    58,    58,     9,    11,
      25,    58,    35,    37,    34,     9,     9,    11,    25,     8,
       8,     8,    25,     9,    37,    36,    58,    25,     9,     9,
      35,    58,    35,     9,    37,    35
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 1663 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 1667 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    { sc_pass = false; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 1668 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    { sc_pass = true;  ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 1672 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                    set_module();
                                    
                                    #ifdef SC_Debug  
                                           sc_dump("@ SC_Module " + sc_module_str + " Pass");
                                    #endif 
                     ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 1681 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {

                                    set_module();

                                    #ifdef SC_Debug 
                                           sc_dump("@ SC_Module " + sc_module_str + " Pass"); 
                                    #endif
                     ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 1696 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {         
                                    sc_module_str = (*(yyvsp[(1) - (5)].sc_string));   
                              
                                    set_module_signal(); 
                     ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 1705 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    { 
                                            #ifdef SC_Debug 
                                                   sc_dump("    SC_Module_Input_Pass");  
                                            #endif 
                     ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 1710 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    { 
                                            #ifdef SC_Debug 
                                                   sc_dump("    SC_Module_Output_Pass"); 
                                            #endif
                     ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 1715 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                            #ifdef SC_Debug   
                                                   sc_dump("    SC_Module_Wire_Pass");   
                                            #endif
                     ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 1720 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    { 
                                            #ifdef SC_Debug 
                                                   sc_dump("    SC_Module_Cell_Pass");  
                                            #endif
                     ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 1725 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    { 
                                            #ifdef SC_Debug 
                                                   sc_dump("    SC_Module_Input_Pass");  
                                            #endif 
                     ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 1730 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    { 
                                            #ifdef SC_Debug 
                                                   sc_dump("    SC_Module_Output_Pass"); 
                                            #endif
                     ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 1735 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    { 
                                            #ifdef SC_Debug 
                                                   sc_dump("    SC_Module_Wire_Pass");   
                                            #endif
                     ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 1740 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                            #ifdef SC_Debug 
                                                   sc_dump("    SC_Module_Cell_Pass");   
                                            #endif
                     ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 1751 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {  
                       sc_msb = atoi((*(yyvsp[(3) - (8)].sc_string)).c_str());
                       sc_lsb = atoi((*(yyvsp[(5) - (8)].sc_string)).c_str());
                       
                       set_module_input_div();
                     ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 1759 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                       sc_msb = 0;
                       sc_lsb = 0;

                       set_module_input_only(); 
                     ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 1771 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                       sc_msb = atoi((*(yyvsp[(3) - (8)].sc_string)).c_str());
                       sc_lsb = atoi((*(yyvsp[(5) - (8)].sc_string)).c_str());
                       
                       set_module_output_div();
                     ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 1779 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                        sc_msb = 0;
                        sc_lsb = 0;

                       set_module_output_only();
                     ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 1790 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                       sc_msb = atoi((*(yyvsp[(3) - (8)].sc_string)).c_str());
                       sc_lsb = atoi((*(yyvsp[(5) - (8)].sc_string)).c_str());
                       
                       set_module_wire_div();
                     ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 1798 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                        sc_msb = 0;
                        sc_lsb = 0;

                        set_module_wire_only();
                     ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 1809 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "and";
                                       sc_cell_u_str = (*(yyvsp[(2) - (6)].sc_string));

                                       set_and_logic_module_cell();
                     ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 1817 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "and";

                                       set_cell_unique_name();
                                       set_and_logic_module_cell();
                     ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 1825 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "nand";
                                       sc_cell_u_str = (*(yyvsp[(2) - (6)].sc_string));

                                       set_nand_logic_module_cell();
                     ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 1833 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "nand";

                                       set_cell_unique_name();
                                       set_nand_logic_module_cell();
                     ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 1841 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "or";
                                       sc_cell_u_str = (*(yyvsp[(2) - (6)].sc_string));

                                       set_or_logic_module_cell();
                     ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 1849 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "or";

                                       set_cell_unique_name();
                                       set_or_logic_module_cell();
                     ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 1857 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "nor";
                                       sc_cell_u_str = (*(yyvsp[(2) - (6)].sc_string));

                                       set_nor_logic_module_cell();
                     ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 1865 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "nor";

                                       set_cell_unique_name();
                                       set_nor_logic_module_cell();
                     ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 1873 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "xor";
                                       sc_cell_u_str = (*(yyvsp[(2) - (6)].sc_string));

                                       set_xor_logic_module_cell();
                     ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 1881 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "xor";

                                       set_cell_unique_name();
                                       set_xor_logic_module_cell();
                     ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 1889 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "xnor";
                                       sc_cell_u_str = (*(yyvsp[(2) - (6)].sc_string));

                                       set_xnor_logic_module_cell();
                     ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 1897 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "xnor";

                                       set_cell_unique_name();
                                       set_xnor_logic_module_cell();
                     ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 1905 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "buf";
                                       sc_cell_u_str = (*(yyvsp[(2) - (6)].sc_string));

                                       set_buf_logic_module_cell();
                     ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 1913 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "buf";

                                       set_cell_unique_name();
                                       set_buf_logic_module_cell();
                     ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 1921 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "not";
                                       sc_cell_u_str = (*(yyvsp[(2) - (6)].sc_string));

                                       set_inv_logic_module_cell();
                     ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 1929 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = "not";

                                       set_cell_unique_name();
                                       set_inv_logic_module_cell();
                     ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 1937 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = (*(yyvsp[(1) - (6)].sc_string));
                                       sc_cell_u_str = (*(yyvsp[(2) - (6)].sc_string));

                                       set_module_cell();
                     ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 1945 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                       sc_cell_m_str = (*(yyvsp[(1) - (5)].sc_string));

                                       set_cell_unique_name();
                                       set_module_cell();
                     ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 1957 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                         sc_cell_p_str = (*(yyvsp[(2) - (5)].sc_string));
                                         add_inv_logic_module_cell();
                                         set_module_links_indirect();
                     ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 1964 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                         sc_cell_p_str = (*(yyvsp[(2) - (7)].sc_string));
                                         add_inv_logic_module_cell();
                                         set_module_links_indirect();
                     ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1971 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                         sc_cell_p_str = "";
                                         add_inv_logic_module_cell();
                                         set_module_links_direct();
                     ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 1978 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                         sc_cell_p_str = "";
                                         add_inv_logic_module_cell();
                                         set_module_links_direct();
                     ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1985 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                         sc_cell_p_str = (*(yyvsp[(4) - (7)].sc_string));
                                         add_inv_logic_module_cell();
                                         set_module_links_indirect();         

                     ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 1993 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                         sc_cell_p_str = (*(yyvsp[(4) - (9)].sc_string));
                                         add_inv_logic_module_cell();
                                         set_module_links_indirect();   

                     ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 2001 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                         sc_cell_p_str = "";
                                         add_inv_logic_module_cell();
                                         set_module_links_direct();
 
                     ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 2009 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                         sc_cell_p_str = "";
                                         add_inv_logic_module_cell();
                                         set_module_links_direct();
                     ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 2020 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                          sc_vv.push_back(*(yyvsp[(1) - (1)].sc_string));
                     ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 2025 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {                    
                                          std::string nm = (*(yyvsp[(2) - (2)].sc_string));
                                          sc_vv.push_back("__sc_inv__"+nm);
                                          sc_inv.push_back((*(yyvsp[(2) - (2)].sc_string)));
                     ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 2032 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                          std::string nm = (*(yyvsp[(1) - (4)].sc_string)) + "[" + (*(yyvsp[(3) - (4)].sc_string)) + "]"; 
                                          sc_vv.push_back(nm);
                     ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 2038 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                          std::string nm = (*(yyvsp[(2) - (5)].sc_string)) + "[" + (*(yyvsp[(4) - (5)].sc_string)) + "]";
                                          sc_vv.push_back("__sc_inv__"+nm);
                                          sc_inv.push_back(nm);
                     ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 2045 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                          sc_msb       = atoi((*(yyvsp[(3) - (6)].sc_string)).c_str());
                                          sc_lsb       = atoi((*(yyvsp[(5) - (6)].sc_string)).c_str());
                                          sc_token_str = (*(yyvsp[(1) - (6)].sc_string));

                                          set_module_vector_div();
                     ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 2054 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                          sc_msb = atoi((*(yyvsp[(4) - (7)].sc_string)).c_str());
                                          sc_lsb = atoi((*(yyvsp[(6) - (7)].sc_string)).c_str());
                                          sc_token_str = (*(yyvsp[(2) - (7)].sc_string));

                                          set_moudle_vector_inv_div();
                     ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 2066 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    { 
                                          sc_vv.push_back((*(yyvsp[(1) - (1)].sc_string))); 
                     ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 2071 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {                    
                                          std::string nm = (*(yyvsp[(2) - (2)].sc_string));
                                          sc_vv.push_back("__sc_inv__"+nm);
                                          sc_inv.push_back(nm);
                     ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 2078 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                          std::string nm = (*(yyvsp[(1) - (4)].sc_string)) + "[" + (*(yyvsp[(3) - (4)].sc_string)) + "]";
                                          sc_vv.push_back(nm);
                     ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 2084 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                          std::string nm = (*(yyvsp[(2) - (5)].sc_string)) + "[" + (*(yyvsp[(4) - (5)].sc_string)) + "]";
                                          sc_vv.push_back("__sc_inv__"+nm);
                                          sc_inv.push_back(nm);
                     ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 2091 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                          sc_msb = atoi((*(yyvsp[(3) - (6)].sc_string)).c_str());
                                          sc_lsb = atoi((*(yyvsp[(5) - (6)].sc_string)).c_str());
                                          sc_token_str = (*(yyvsp[(1) - (6)].sc_string));

                                          set_module_vector_div();
                     ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 2100 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {

                                          sc_msb = atoi((*(yyvsp[(4) - (7)].sc_string)).c_str());
                                          sc_lsb = atoi((*(yyvsp[(6) - (7)].sc_string)).c_str());
                                          sc_token_str = (*(yyvsp[(2) - (7)].sc_string));

                                          set_moudle_vector_inv_div();
                     ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 2110 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    { 
                                          sc_vv.push_back((*(yyvsp[(3) - (3)].sc_string)));
                     ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 2115 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                          std::string nm = (*(yyvsp[(2) - (4)].sc_string));
                                          sc_vv.push_back("__sc_inv__"+nm);
                                          sc_inv.push_back(nm);
                     ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 2122 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                          std::string nm = (*(yyvsp[(1) - (6)].sc_string)) + "[" + (*(yyvsp[(3) - (6)].sc_string)) + "]";
                                          sc_vv.push_back(nm);
                     ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 2128 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                          std::string nm = (*(yyvsp[(2) - (7)].sc_string)) + "[" + (*(yyvsp[(4) - (7)].sc_string)) + "]";
                                          sc_vv.push_back("__sc_inv__"+nm);
                                          sc_inv.push_back(nm);
                     ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 2135 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                          sc_msb       = atoi((*(yyvsp[(5) - (8)].sc_string)).c_str());
                                          sc_lsb       = atoi((*(yyvsp[(7) - (8)].sc_string)).c_str());
                                          sc_token_str = (*(yyvsp[(3) - (8)].sc_string));

                                          set_module_vector_div();
                     ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 2144 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"
    {
                                          sc_msb       = atoi((*(yyvsp[(6) - (9)].sc_string)).c_str());
                                          sc_lsb       = atoi((*(yyvsp[(8) - (9)].sc_string)).c_str());
                                          sc_token_str = (*(yyvsp[(4) - (9)].sc_string));

                                          set_moudle_vector_inv_div();
                     ;}
    break;



/* Line 1455 of yacc.c  */
#line 3848 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 2156 "/home/sean/桌面/iso_cell_rc1/kernel/SC_Parser/SC_Parser.y"


