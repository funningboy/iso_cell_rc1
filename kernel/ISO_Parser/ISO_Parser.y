%{
        #include <iostream>
        #include <sstream>
        #include <vector>
        #include <algorithm>

	#include <stdlib.h> 
        #include <stdio.h>
        #include <assert.h>

        #include "kernel/ISO_Lib/ISO_CreateIsolationRule.h"
        #include "kernel/ISO_Lib/ISO_CreatePowerDomain.h"
        #include "kernel/ISO_Lib/ISO_DefineIsolationCell.h"
        #include "kernel/ISO_Lib/ISO_CreateNominalCondition.h"
        #include "kernel/ISO_Lib/ISO_CreatePowerMode.h"
        #include "kernel/ISO_Context/ISO_Table.h"

        using namespace std;
        using namespace xISOPower;

        ISO_Table  *t_iso_table;

        extern int ISO_lex();
        void ISO_error(const char *s) { printf("ERROR: %s\n", s); }

        enum ISO_TYPE {
             ISO_TYPE_HIGH,
             ISO_TYPE_LOW,
             ISO_TYPE_FROM,
             ISO_TYPE_TO,
             ISO_TYPE_EITHER,
             ISO_TYPE_UP,
             ISO_TYPE_DOWN,
             ISO_TYPE_ON,
             ISO_TYPE_OFF,
             ISO_TYPE_undef
        }; 

        bool                                         ISO_Default;
        std::string                                  ISO_Name;
        std::string                                  ISO_From;
        std::string                                  ISO_To;
        std::string                                  ISO_Condition;
        std::string                                  ISO_Enable;
        std::string                                  ISO_Voltage;
        ISO_TYPE                                     ISO_Out_HL;
        ISO_TYPE                                     ISO_ONOFF;
        ISO_TYPE                                     ISO_FMTO;
        ISO_TYPE                                     ISO_UPDN;

       
        std::vector<std::string>                     vv;
        std::vector<std::string>                     vv1;
        std::vector<std::string>                     vv2;
        std::map<std::string,std::string>            mm;


        std::vector< ISO_CreatePowerDomain*      >   CtPowerDomainVec;
        std::vector< ISO_CreateIsolationRule*    >   CtIsolationRuleVec;
        std::vector< ISO_DefineIsolationCell*    >   DefIsolationCellVec;
        std::vector< ISO_CreateNominalCondition* >   CtNominalConditionVec;
        std::vector< ISO_CreatePowerMode*        >   CtPowerModeVec;

        typedef std::vector<std::string>::iterator   vv_iter;

%}





%{
void set_Clear_All(){

ISO_Default     = false;
ISO_Name        = "";
ISO_From        = "";
ISO_To          = "";
ISO_Condition   = "";
ISO_Enable      = ""; 
ISO_Voltage     = "";
ISO_Out_HL      = ISO_TYPE_undef;
ISO_FMTO        = ISO_TYPE_undef; 
ISO_UPDN        = ISO_TYPE_undef;

vv.clear();
vv1.clear();
vv2.clear();
mm.clear();

}
%}




%{
void set_CreatePowerDomain(){

  ISO_CreatePowerDomain *iso_c_p_d = new ISO_CreatePowerDomain();
  assert( iso_c_p_d != NULL && "ISO_Parser->set_CreatePowerDomain" );

                         iso_c_p_d->set_ISO_Default(ISO_Default);
                         iso_c_p_d->set_ISO_Name(ISO_Name);
                         iso_c_p_d->set_ISO_Instances(vv1);
                         iso_c_p_d->set_ISO_BoundaryPorts(vv2);

  CtPowerDomainVec.push_back(iso_c_p_d);

  set_Clear_All();
}
%}





%{
void set_CreateIsolationRule(){

  ISO_CreateIsolationRule *iso_c_i_r = new ISO_CreateIsolationRule();
  assert( iso_c_i_r != NULL && "ISO_Parser->set_CreateIsolationRule" );

                           iso_c_i_r->set_ISO_Name(ISO_Name);
                           iso_c_i_r->set_ISO_From(ISO_From);
                           iso_c_i_r->set_ISO_To(ISO_To);
                    
                       if( ISO_ONOFF == ISO_TYPE_ON )
                           iso_c_i_r->set_ISO_Condition(ISO_CreateIsolationRule::ISO_COND_ON,ISO_Condition);
                       else
                           iso_c_i_r->set_ISO_Condition(ISO_CreateIsolationRule::ISO_COND_OFF,ISO_Condition);


                       if( ISO_Out_HL == ISO_TYPE_HIGH )
                           iso_c_i_r->set_ISO_OUT_HL(ISO_CreateIsolationRule::ISO_OUT_H);
                       else
                           iso_c_i_r->set_ISO_OUT_HL(ISO_CreateIsolationRule::ISO_OUT_L);
                           
  CtIsolationRuleVec.push_back(iso_c_i_r);

  set_Clear_All();
}
%}





%{
void set_DefineIsolationCell(){

  assert( !vv1.empty() && "ISO_Parser->set_DefineIsolationCell" );

  for(vv_iter v_it  = vv1.begin();
              v_it != vv1.end();   ++v_it){

  ISO_DefineIsolationCell *iso_d_i_c = new  ISO_DefineIsolationCell();
 
  assert( iso_d_i_c != NULL && "ISO_Parser->set_DefineIsolationCell" );

                           iso_d_i_c->set_ISO_Cell((*v_it));
                           iso_d_i_c->set_ISO_Enable(ISO_Enable);

                       if( ISO_FMTO == ISO_TYPE_FROM )
                           iso_d_i_c->set_ISO_Location(ISO_DefineIsolationCell::ISO_LOC_FROM);
                       else
                           iso_d_i_c->set_ISO_Location(ISO_DefineIsolationCell::ISO_LOC_TO);
 

    DefIsolationCellVec.push_back(iso_d_i_c);
  }

 set_Clear_All();
}
%}





%{
void set_CreateNominalCondition(){

  ISO_CreateNominalCondition * iso_c_n_c = new ISO_CreateNominalCondition();

  assert( iso_c_n_c != NULL && "ISO_Parser->set_CreateNominalCondition" );

          iso_c_n_c->set_ISO_Name(ISO_Name);
          iso_c_n_c->set_ISO_Voltage(atof(ISO_Voltage.c_str()));

  CtNominalConditionVec.push_back(iso_c_n_c);

 set_Clear_All();
}
%}




%{ 
void set_CreatePowerMode(){

    ISO_CreatePowerMode *iso_c_p_d = new ISO_CreatePowerMode();

    assert( iso_c_p_d != NULL &&  
            !mm.empty()       && "ISO_Parser->set_CreatePowerMode" );

    iso_c_p_d->set_ISO_Name(ISO_Name); 
    iso_c_p_d->set_ISO_Default(ISO_Default); 
    iso_c_p_d->set_ISO_DomainCondition(mm);
 
    CtPowerModeVec.push_back(iso_c_p_d);

    set_Clear_All(); 
}
%}




%{
void set_ISO_Table(){

     ISO_Table *iso_table = new ISO_Table();

     assert( iso_table != NULL && "ISO_Parser->set_ISO_Table");

     iso_table->set_ISO_CreatePowerDomainVec(CtPowerDomainVec);
     iso_table->set_ISO_CreateIsolationRuleVec(CtIsolationRuleVec);
     iso_table->set_ISO_DefineIsolationCellVec(DefIsolationCellVec);
     iso_table->set_ISO_CreateNominalConditionVec(CtNominalConditionVec);
     iso_table->set_ISO_CreatePowerModeVec(CtPowerModeVec);

     CtPowerDomainVec.clear();
     CtIsolationRuleVec.clear();
     DefIsolationCellVec.clear();
     CtNominalConditionVec.clear();
     CtPowerModeVec.clear();
  
     t_iso_table = iso_table;

}
%}






%union {

        std::string      *iso_string;
        int              *iso_int;
	int              token;

}


%token <token>       TCREATE_POWER_DOMAIN
%token <token>       TDEFAULT
%token <token>       TINSTANCES
%token <token>       TNAME
%token <token>       TBOUNDARY_PORTS
%token <token>       TCREATE_ISOLATION_RULE
%token <token>       TFROM
%token <token>       TTO
%token <token>       TEITHER
%token <token>       TISOLATION_OUTPUT
%token <token>       TISOLATION_CONDITION
%token <token>       THIGH
%token <token>       TLOW
%token <token>       TDEFINE_ISOLATION_CELL
%token <tokne>       TCELLS
%token <token>       TENABLE
%token <token>       TVALID_LOCATION
%token <token>       TCREATE_LEVEL_SHIFTER_RULE
%token <token>       TDEFINE_LEVEL_SHIFTER_CELL
%token <token>       TINPUT_VOLTAGE_RANGE
%token <token>       TOUTPUT_VOLTAGE_RANGE
%token <token>       TDIRECTION
%token <token>       TUP
%token <token>       TDOWN
%token <token>       TCREATE_NOMINAL_CONDITION
%token <token>       TVOLTAGE
%token <token>       TDOMAIN_CONDITIONS
%token <token>       TCREATE_POWER_MODE



%token <iso_string>  TIDENTIFIER 
%token <iso_string>  TINTEGER 
%token <iso_string>  TDOUBLE
%token <token>       TEQUAL
%token <token>       TCLT 
%token <token>       TCGT  
%token <token>       TLPAREN 
%token <token>       TRPAREN 
%token <token>       TLBRACE
%token <token>       TRBRACE  
%token <token>       TRSQUARE 
%token <token>       TLSQUARE
%token <token>       TEND
%token <token>       TSLASH
%token <token>       TINV
%token <token>       TCOLON
%token <token>       TMINUS
%token <token>       TAT


%start program

%%

program                : iso_contains_stmt { set_ISO_Table(); }
                       ;


iso_contains_stmt      :                    iso_contain_stmt 
                       | iso_contains_stmt  iso_contain_stmt
                       ;

iso_contain_stmt       : TCREATE_POWER_DOMAIN        create_power_domains             { set_CreatePowerDomain();      }
                       | TCREATE_ISOLATION_RULE      create_isolation_rules           { set_CreateIsolationRule();    }
                       | TDEFINE_ISOLATION_CELL      define_isolation_cells           { set_DefineIsolationCell();    }
                       | TCREATE_LEVEL_SHIFTER_RULE  create_level_shifter_rules       {/* set_CreateLevelShifterRule();*/ }
                       | TDEFINE_LEVEL_SHIFTER_CELL  define_level_shifter_cells       {/* s set_DefineLevelShifterCell();*/ }
                       | TCREATE_NOMINAL_CONDITION   create_nominal_conditions        { set_CreateNominalCondition(); } 
                       | TCREATE_POWER_MODE          create_power_modes               { set_CreatePowerMode();        }
                       ;     


create_power_domains   :                      create_power_domain 
                       | create_power_domains create_power_domain
                       ;


create_isolation_rules :                        create_isolation_rule
                       | create_isolation_rules create_isolation_rule 
                       ;


define_isolation_cells :                        define_isolation_cell
                       | define_isolation_cells define_isolation_cell
                       ;


create_level_shifter_rules :                            create_level_shifter_rule
                           | create_level_shifter_rules create_level_shifter_rule
                           ;


define_level_shifter_cells :                            define_level_shifter_cell
                           | define_level_shifter_cells define_level_shifter_cell
                           ;


create_nominal_conditions :                            create_nominal_condition
                          | create_nominal_conditions  create_nominal_condition
                          ;

create_power_modes        :                    create_power_mode
                          | create_power_modes create_power_mode
                          ;


create_power_domain    : TMINUS TDEFAULT                                                    { ISO_Default = true;   } 
                       | TMINUS TDEFAULT TSLASH                                             { ISO_Default = true;   }
                       | TMINUS TINSTANCES TLBRACE iso_vectors_stmt TRBRACE                 { vv1 = vv; vv.clear(); } 
                       | TMINUS TINSTANCES TLBRACE iso_vectors_stmt TRBRACE TSLASH          { vv1 = vv; vv.clear(); }
                       | TMINUS TBOUNDARY_PORTS TLBRACE iso_vectors_stmt TRBRACE            { vv2 = vv; vv.clear(); }
                       | TMINUS TBOUNDARY_PORTS TLBRACE iso_vectors_stmt TRBRACE TSLASH     { vv2 = vv; vv.clear(); }
                       | TMINUS TNAME TIDENTIFIER                                           { ISO_Name = (*$<iso_string>3); }
                       | TMINUS TNAME TIDENTIFIER TSLASH                                    { ISO_Name = (*$<iso_string>3); }
                       ;



create_isolation_rule  : TMINUS TNAME TIDENTIFIER                                           { ISO_Name = (*$<iso_string>3); } 
                       | TMINUS TNAME TIDENTIFIER TSLASH                                    { ISO_Name = (*$<iso_string>3); }
                       | TMINUS TFROM TIDENTIFIER                                           { ISO_From = (*$<iso_string>3); }
                       | TMINUS TFROM TIDENTIFIER TSLASH                                    { ISO_From = (*$<iso_string>3); }
                       | TMINUS TTO   TIDENTIFIER                                           { ISO_To   = (*$<iso_string>3); }
                       | TMINUS TTO   TIDENTIFIER TSLASH                                    { ISO_To   = (*$<iso_string>3); }
                       | TMINUS TISOLATION_OUTPUT iso_high_low_stmt                         {} 
                       | TMINUS TISOLATION_OUTPUT iso_high_low_stmt TSLASH                  {}
                       | TMINUS TISOLATION_CONDITION TIDENTIFIER                            { ISO_Condition = (*$<iso_string>3); ISO_ONOFF = ISO_TYPE_ON;  }
                       | TMINUS TISOLATION_CONDITION TIDENTIFIER TSLASH                     { ISO_Condition = (*$<iso_string>3); ISO_ONOFF = ISO_TYPE_ON;  }
                       | TMINUS TISOLATION_CONDITION TINV TIDENTIFIER                       { ISO_Condition = (*$<iso_string>4); ISO_ONOFF = ISO_TYPE_OFF; }
                       | TMINUS TISOLATION_CONDITION TINV TIDENTIFIER TSLASH                { ISO_Condition = (*$<iso_string>4); ISO_ONOFF = ISO_TYPE_OFF; }
                       ;



define_isolation_cell  : TMINUS TCELLS TLBRACE iso_vectors_stmt TRBRACE                     { vv1 = vv; vv.clear(); } 
                       | TMINUS TCELLS TLBRACE iso_vectors_stmt TRBRACE TSLASH              { vv1 = vv; vv.clear(); }
                       | TMINUS TENABLE TIDENTIFIER                                         { ISO_Enable = (*$<iso_string>3); }
                       | TMINUS TENABLE TIDENTIFIER TSLASH                                  { ISO_Enable = (*$<iso_string>3); }
                       | TMINUS TVALID_LOCATION iso_from_to_stmt                            {}
                       | TMINUS TVALID_LOCATION iso_from_to_stmt TSLASH                     {}
                       ;



create_level_shifter_rule : TMINUS TNAME TIDENTIFIER                                        {  ISO_Name = (*$<iso_string>3); }
                          | TMINUS TNAME TIDENTIFIER TSLASH                                 {  ISO_Name = (*$<iso_string>3); }
                          | TMINUS TFROM TIDENTIFIER                                        {  ISO_From = (*$<iso_string>3); } 
                          | TMINUS TFROM TIDENTIFIER TSLASH                                 {  ISO_From = (*$<iso_string>3); }
                          | TMINUS TTO   TIDENTIFIER                                        {  ISO_To   = (*$<iso_string>3); }
                          | TMINUS TTO   TIDENTIFIER TSLASH                                 {  ISO_To   = (*$<iso_string>3); }
                          ;


 
define_level_shifter_cell : TMINUS TCELLS TIDENTIFIER                                       { ISO_Name = (*$<iso_string>3); }
                          | TMINUS TCELLS TIDENTIFIER TSLASH                                
                          | TMINUS TENABLE TIDENTIFIER 
                          | TMINUS TENABLE TIDENTIFIER TSLASH
                          | TMINUS TVALID_LOCATION iso_from_to_stmt
                          | TMINUS TVALID_LOCATION iso_from_to_stmt TSLASH
                          | TMINUS TINPUT_VOLTAGE_RANGE TDOUBLE TCOLON TDOUBLE
                          | TMINUS TINPUT_VOLTAGE_RANGE TDOUBLE TCOLON TDOUBLE TSLASH
                          | TMINUS TOUTPUT_VOLTAGE_RANGE TDOUBLE TCOLON TDOUBLE
                          | TMINUS TOUTPUT_VOLTAGE_RANGE TDOUBLE TCOLON TDOUBLE TSLASH
                          | TMINUS TDIRECTION iso_up_down_stmt
                          | TMINUS TDIRECTION iso_up_down_stmt TSLASH 
                          ; 



create_nominal_condition  : TMINUS TNAME    TIDENTIFIER                                      { ISO_Name    = (*$<iso_string>3); }
                          | TMINUS TNAME    TIDENTIFIER  TSLASH                              { ISO_Name    = (*$<iso_string>3); }
                          | TMINUS TVOLTAGE TDOUBLE                                          { ISO_Voltage = (*$<iso_string>3); }
                          | TMINUS TVOLTAGE TDOUBLE  TSLASH                                  { ISO_Voltage = (*$<iso_string>3); }
                          | TMINUS TVOLTAGE TINTEGER                                         { ISO_Voltage = (*$<iso_string>3); }
                          | TMINUS TVOLTAGE TINTEGER  TSLASH                                 { ISO_Voltage = (*$<iso_string>3); }
                          ;


create_power_mode         : TMINUS TNAME TIDENTIFIER                                         { ISO_Name    = (*$<iso_string>3); }
                          | TMINUS TNAME TIDENTIFIER TSLASH                                  { ISO_Name    = (*$<iso_string>3); }
                          | TMINUS TDOMAIN_CONDITIONS TLBRACE iso_conds_stmt TRBRACE         {}
                          | TMINUS TDOMAIN_CONDITIONS TLBRACE iso_conds_stmt TRBRACE TSLASH  {}
                          | TMINUS TDEFAULT                                                  { ISO_Default = true; }
                          | TMINUS TDEFAULT TSLASH                                           { ISO_Default = true; }
                          ;


iso_high_low_stmt      : THIGH   { ISO_Out_HL = ISO_TYPE_HIGH; } 
                       | TLOW    { ISO_Out_HL = ISO_TYPE_LOW;  } 
                       ;

iso_from_to_stmt       : TFROM   { ISO_FMTO = ISO_TYPE_FROM;   }
                       | TTO     { ISO_FMTO = ISO_TYPE_TO;     }
                       | TEITHER { ISO_FMTO = ISO_TYPE_EITHER; }
                       ;

iso_up_down_stmt       : TUP     { ISO_UPDN = ISO_TYPE_UP;     }
                       | TDOWN   { ISO_UPDN = ISO_TYPE_DOWN;   }
                       ;

iso_conds_stmt         :                  TIDENTIFIER TAT TIDENTIFIER   { mm[(*$<iso_string>1)] = (*$<iso_string>3); } 
                       | iso_conds_stmt   TIDENTIFIER TAT TIDENTIFIER   { mm[(*$<iso_string>2)] = (*$<iso_string>4); }
                       ;
                      

iso_vectors_stmt       :                  TIDENTIFIER { vv.push_back((*$<iso_string>1)); }
                       | iso_vectors_stmt TIDENTIFIER { vv.push_back((*$<iso_string>2)); }
                       ;


%%
