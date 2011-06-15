#ifndef _ISO_TABLE_H_
#define _ISO_TABLE_H_

#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

#include "kernel/ISO_Lib/ISO_CreateIsolationRule.h"
#include "kernel/ISO_Lib/ISO_CreateNominalCondition.h"
#include "kernel/ISO_Lib/ISO_CreatePowerDomain.h"
#include "kernel/ISO_Lib/ISO_CreatePowerMode.h"
#include "kernel/ISO_Lib/ISO_DefineIsolationCell.h"

#include "kernel/ISO_Context/ISO_Util.h"
#include "kernel/SC_Context/SC_Table.h"

using namespace std;
using namespace xISOPower;


namespace xISOPower {

class ISO_Table {

public :
        typedef std::vector< ISO_CreatePowerDomain*      >           CtPowerDomainVec;
        typedef std::vector< ISO_CreatePowerMode*        >           CtPowerModeVec;
        typedef std::vector< ISO_CreateIsolationRule*    >           CtIsolationRuleVec;
        typedef std::vector< ISO_DefineIsolationCell*    >           DefIsolationCellVec;
        typedef std::vector< ISO_CreateNominalCondition* >           CtNominalConditionVec;

        typedef std::vector< ISO_CreatePowerDomain*      >::iterator CtPowerDomainVec_iter;
        typedef std::vector< ISO_CreatePowerMode*        >::iterator CtPowerModeVec_iter;
        typedef std::vector< ISO_CreateIsolationRule*    >::iterator CtIsolationRuleVec_iter;
        typedef std::vector< ISO_DefineIsolationCell*    >::iterator DefIsolationCellVec_iter;
        typedef std::vector< ISO_CreateNominalCondition* >::iterator CtNominalConditionVec_iter;


public :
        ISO_Table(){}

       ~ISO_Table(){ 

        MCtPowerDomainVec.clear();
        MCtIsolationRuleVec.clear();
        MDefIsolationCellVec.clear();
        MCtNominalConditionVec.clear();
        MCtPowerModeVec.clear();

        }


public :
       void     set_ISO_CreatePowerDomainVec( CtPowerDomainVec vv ){ MCtPowerDomainVec = vv; }

       void     set_ISO_CreatePowerDomainVec( ISO_CreatePowerDomain * iso_c_p_d ){

                assert( iso_c_p_d != NULL && "set_ISO_CreatePowerDomainVec" );
                        MCtPowerDomainVec.push_back(iso_c_p_d);
       }

       CtPowerDomainVec  get_ISO_CreatePowerDomainVec(){ return MCtPowerDomainVec; }


public :
       void     set_ISO_CreateIsolationRuleVec( CtIsolationRuleVec vv ){ MCtIsolationRuleVec = vv; }

       void     set_ISO_CreateIsolationRuleVec( ISO_CreateIsolationRule * iso_c_i_r ){

                assert( iso_c_i_r != NULL && "set_ISO_CreateIsolationRuleVec" );
                        MCtIsolationRuleVec.push_back(iso_c_i_r);
       }

       CtIsolationRuleVec  get_ISO_CreateIsolationRuleVec(){ return MCtIsolationRuleVec; }


public :
       void     set_ISO_DefineIsolationCellVec( DefIsolationCellVec vv ){ MDefIsolationCellVec = vv; }

       void     set_ISO_DefineIsolationCellVec( ISO_DefineIsolationCell * iso_d_i_c ){

                assert( iso_d_i_c != NULL && "set_ISO_DefineIsolationCellVec" );
                        MDefIsolationCellVec.push_back(iso_d_i_c);
       }

       DefIsolationCellVec  get_ISO_DefineIsolationCellVec(){ return MDefIsolationCellVec; }


public :
       void     set_ISO_CreateNominalConditionVec( CtNominalConditionVec vv ){ MCtNominalConditionVec = vv; }

       void     set_ISO_CreateNominalConditionVec( ISO_CreateNominalCondition * iso_c_n_c ){

                assert( iso_c_n_c != NULL && "set_ISO_CreateNominalConditionVec" );
                        MCtNominalConditionVec.push_back(iso_c_n_c);
       }

       CtNominalConditionVec  get_ISO_CreateNominalConditionVec(){ return MCtNominalConditionVec; }


public :
       void     set_ISO_CreatePowerModeVec( CtPowerModeVec vv ){ MCtPowerModeVec = vv; }

       void     set_ISO_CreatePowerModeVec( ISO_CreatePowerMode * iso_c_p_m ){

                assert( iso_c_p_m != NULL && "set_ISO_CreatePowerModeVec" );
                        MCtPowerModeVec.push_back(iso_c_p_m);
       }

       CtPowerModeVec  get_ISO_CreatePowerModeVec(){ return MCtPowerModeVec; }




public :
       void dump_Context(){

       CtPowerDomainVec cpd_vv = get_ISO_CreatePowerDomainVec();

          for(CtPowerDomainVec_iter cpd_it  = cpd_vv.begin();
                                    cpd_it != cpd_vv.end();   ++cpd_it){

             ISO_CreatePowerDomain *iso_cpd = static_cast<ISO_CreatePowerDomain*>(*cpd_it);
             assert( iso_cpd != NULL && "ISO_Table->dump_Context");

                     iso_cpd->dump_Context();
          }


       CtIsolationRuleVec  cir_vv = get_ISO_CreateIsolationRuleVec();

          for(CtIsolationRuleVec_iter cir_it  = cir_vv.begin(); 
                                      cir_it != cir_vv.end();   ++cir_it){

             ISO_CreateIsolationRule *iso_cir = static_cast<ISO_CreateIsolationRule*>(*cir_it);
             assert( iso_cir != NULL && "ISO_Table->dump_Context");

                     iso_cir->dump_Context();
          }


       DefIsolationCellVec  dic_vv = get_ISO_DefineIsolationCellVec(); 

         for(DefIsolationCellVec_iter dic_it  = dic_vv.begin(); 
                                      dic_it != dic_vv.end();   ++dic_it){

             ISO_DefineIsolationCell *iso_dic = static_cast<ISO_DefineIsolationCell*>(*dic_it);
             assert( iso_dic != NULL && "ISO_Table->dump_Context");

                     iso_dic->dump_Context();
          }


       CtNominalConditionVec  cnc_vv = get_ISO_CreateNominalConditionVec();

          for(CtNominalConditionVec_iter cnc_it  = cnc_vv.begin(); 
                                         cnc_it != cnc_vv.end();   ++cnc_it){

             ISO_CreateNominalCondition *iso_cnc = static_cast<ISO_CreateNominalCondition*>(*cnc_it);
             assert( iso_cnc != NULL && "ISO_Table->dump_Context");

                     iso_cnc->dump_Context();
          }

        
       CtPowerModeVec cpm_vv = get_ISO_CreatePowerModeVec();

          for(CtPowerModeVec_iter cpm_it  = cpm_vv.begin(); 
                                  cpm_it != cpm_vv.end();   ++cpm_it){

             ISO_CreatePowerMode *iso_cpm = static_cast<ISO_CreatePowerMode*>(*cpm_it);
             assert( iso_cpm != NULL && "ISO_Table->dump_Context");

                     iso_cpm->dump_Context();
          }
  
       }

private :

        std::vector< ISO_CreatePowerDomain*      > MCtPowerDomainVec;
        std::vector< ISO_CreateIsolationRule*    > MCtIsolationRuleVec;
        std::vector< ISO_DefineIsolationCell*    > MDefIsolationCellVec;
        std::vector< ISO_CreateNominalCondition* > MCtNominalConditionVec;
        std::vector< ISO_CreatePowerMode*        > MCtPowerModeVec;
     
 };
}
#endif
