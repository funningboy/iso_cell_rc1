
#include "kernel/ISO_Context/ISO_Util.h"


bool    ISO_Util::is_ISO_Cell_Contain(ISO_Table *iso_table,
                                      std::string iso_cell){

        assert( !iso_cell.empty()  && 
                 iso_table != NULL && "ISO_Uitl->is_ISO_Cell_Contain");

        ISO_Table::DefIsolationCellVec cell_vec = iso_table->get_ISO_DefineIsolationCellVec();

        for(ISO_Table::DefIsolationCellVec_iter cell_it  = cell_vec.begin();
                                                cell_it != cell_vec.end();  ++cell_it){
   
           ISO_DefineIsolationCell *def_iso_cell = static_cast<ISO_DefineIsolationCell*>(*cell_it);
           assert( def_iso_cell != NULL && "ISO_Util->is_ISO_Cell_Contain");

                       std::string  cell_nm  = def_iso_cell->get_ISO_Cell();

                       if( cell_nm.compare(iso_cell)==0 )
                           return true; 
        }

return false;
}




bool    ISO_Util::is_ISO_Cell_Enable_Contain(ISO_Table *iso_table,
                                             std::string iso_cell,
                                             std::string iso_enable){

        assert( !iso_cell.empty()   &&
                !iso_enable.empty() && 
                 iso_table != NULL  && "ISO_Uitl->is_ISO_Cell_Enable_Contain");

        ISO_Table::DefIsolationCellVec cell_vec = iso_table->get_ISO_DefineIsolationCellVec();

        for(ISO_Table::DefIsolationCellVec_iter cell_it  = cell_vec.begin();
                                                cell_it != cell_vec.end();  ++cell_it){
   
           ISO_DefineIsolationCell *def_iso_cell = static_cast<ISO_DefineIsolationCell*>(*cell_it);
           assert( def_iso_cell != NULL && "ISO_Util->is_ISO_Cell_Contain");

                       std::string  cell_nm  = def_iso_cell->get_ISO_Cell();
                       std::string  cell_en  = def_iso_cell->get_ISO_Enable();
 
                       if( cell_nm.compare(iso_cell)   ==0 &&
                           cell_en.compare(iso_enable) ==0 )
                           return true; 
        }

return false;
}




std::string   ISO_Util::get_ISO_Cell_Enable(ISO_Table *iso_table,
                                            std::string iso_cell){

        assert( !iso_cell.empty()   &&
                 iso_table != NULL  && "ISO_Uitl->get_ISO_Cell_Enable");

        ISO_Table::DefIsolationCellVec cell_vec = iso_table->get_ISO_DefineIsolationCellVec();

        for(ISO_Table::DefIsolationCellVec_iter cell_it  = cell_vec.begin();
                                                cell_it != cell_vec.end();  ++cell_it){
   
           ISO_DefineIsolationCell *def_iso_cell = static_cast<ISO_DefineIsolationCell*>(*cell_it);
           assert( def_iso_cell != NULL && "ISO_Util->is_ISO_Cell_Contain");

                       std::string  cell_nm  = def_iso_cell->get_ISO_Cell();
 
                       if( cell_nm.compare(iso_cell)   ==0 )
                           return def_iso_cell->get_ISO_Enable(); 
        }

return "";
}




ISO_DefineIsolationCell::ISO_LOCATION  ISO_Util::get_ISO_Cell_Location(ISO_Table *iso_table,
                                                                       std::string iso_cell){

        assert( !iso_cell.empty()   &&
                 iso_table != NULL  && "ISO_Uitl->get_ISO_Cell_Condition");

        ISO_Table::DefIsolationCellVec cell_vec = iso_table->get_ISO_DefineIsolationCellVec();

        for(ISO_Table::DefIsolationCellVec_iter cell_it  = cell_vec.begin();
                                                cell_it != cell_vec.end();  ++cell_it){
   
           ISO_DefineIsolationCell *def_iso_cell = static_cast<ISO_DefineIsolationCell*>(*cell_it);
           assert( def_iso_cell != NULL && "ISO_Util->is_ISO_Cell_Contain");

                       std::string  cell_nm  = def_iso_cell->get_ISO_Cell();
 
                       if( cell_nm.compare(iso_cell)   ==0 )
                           return def_iso_cell->get_ISO_Location(); 
        }

return ISO_DefineIsolationCell::ISO_LOC_undef;
}




std::string     ISO_Util::get_HierarchyName(std::vector<std::string> vec){

                std::stringstream ss;
                for(size_t i=0; i<vec.size(); ++i){
                  if(i != 0)
                     ss << "/";

                  ss << vec[i];
                }

                return ss.str();
}



int            ISO_Util::get_HierarchySize(std::string iso_nm){

               assert( !iso_nm.empty() && "ISO_Util->get_HierarchySize");

               std::vector<std::string> str_vec;
               boost::split(str_vec, iso_nm, boost::is_any_of("/"));

               return str_vec.size();
               }





ISO_Util::StrVec   ISO_Util::get_HierarchyVec(std::string iso_nm){

               assert( !iso_nm.empty() && "ISO_Util->get_HierarchyVec");

               std::vector<std::string> str_vec;
               boost::split(str_vec, iso_nm, boost::is_any_of("/"));

               return str_vec;
               }




std::string    ISO_Util::get_ISO_Instance_Domain(ISO_Table *iso_table,
                                                 std::string iso_nm){
                
               bool        pass;
               std::string Default_nm;
 
               assert( iso_table != NULL && 
                       !iso_nm.empty()   && "ISO_Util->get_ISO_Instance_Domain");

               ISO_Table::CtPowerDomainVec c_p_d_vec = iso_table->get_ISO_CreatePowerDomainVec();

       
               for(ISO_Table::CtPowerDomainVec_iter  c_p_d_it  = c_p_d_vec.begin(); 
                                                     c_p_d_it != c_p_d_vec.end();  ++c_p_d_it){
      
                   ISO_CreatePowerDomain *ISO_c_p_d = static_cast<ISO_CreatePowerDomain*>(*c_p_d_it);
       
                   assert( ISO_c_p_d != NULL && "ISO_Util->get_ISO_Instance_Domain");
       
                   ISO_CreatePowerDomain::ISOVec instance_vec  =  ISO_c_p_d->get_ISO_Instances();
                   bool                          iso_default   =  ISO_c_p_d->get_ISO_Default();
                   std::string                   iso_domain_nm =  ISO_c_p_d->get_ISO_Name();

                   if( iso_default == true )
                       Default_nm = iso_domain_nm;

                   // @ instance check
                   for(ISO_CreatePowerDomain::ISOVec_iter inst_it  = instance_vec.begin();
                                                          inst_it != instance_vec.end();  ++inst_it){

                       pass = true;
                       ISO_Util::StrVec hier_iso_vec  = get_HierarchyVec(iso_nm);
                       ISO_Util::StrVec hier_inst_vec = get_HierarchyVec(*inst_it);

                       if( hier_iso_vec.size() >= hier_inst_vec.size()){

                           StrVec_iter  hier_iso_it  = hier_iso_vec.begin();
                           StrVec_iter  hier_inst_it = hier_inst_vec.begin();

                           while( hier_inst_it != hier_inst_vec.end() ){
                                  if( (*hier_inst_it).compare(*hier_iso_it) != 0 ){
                                       pass = false;
                                       break;
                                  }

                              hier_inst_it++;
                              hier_iso_it++;
                           } 
                                     
                         if( pass == true )
                         return iso_domain_nm;
                       }
                   }
               }

return Default_nm;
}





std::string    ISO_Util::get_ISO_BoundaryPort_Domain(ISO_Table *iso_table,
                                                     std::string iso_nm){

               bool        pass;
               std::string Default_nm;

               assert( iso_table != NULL && 
                       !iso_nm.empty()   && "ISO_Util->get_ISO_BoundaryPort_Domain");

               ISO_Table::CtPowerDomainVec c_p_d_vec = iso_table->get_ISO_CreatePowerDomainVec();
       
               for(ISO_Table::CtPowerDomainVec_iter  c_p_d_it  = c_p_d_vec.begin(); 
                                                     c_p_d_it != c_p_d_vec.end();  ++c_p_d_it){

                   ISO_CreatePowerDomain *ISO_c_p_d = static_cast<ISO_CreatePowerDomain*>(*c_p_d_it);
       
                   assert( ISO_c_p_d != NULL && "ISO_Util->get_ISO_BoundaryPort_Domain");
       
                   ISO_CreatePowerDomain::ISOVec boundary_port_vec =  ISO_c_p_d->get_ISO_BoundaryPorts(); 
                   bool                          iso_default       =  ISO_c_p_d->get_ISO_Default();
                   std::string                   iso_domain_nm     =  ISO_c_p_d->get_ISO_Name();

                   if( iso_default ==true )
                       Default_nm = iso_domain_nm;

                   // @ boundary check
                   for(ISO_CreatePowerDomain::ISOVec_iter b_p_it  = boundary_port_vec.begin();
                                                          b_p_it != boundary_port_vec.end();  ++b_p_it){

                       pass = true;       
                       ISO_Util::StrVec hier_iso_vec = get_HierarchyVec(iso_nm);
                       ISO_Util::StrVec hier_b_p_vec = get_HierarchyVec(*b_p_it);

                       if( hier_iso_vec.size() >= hier_b_p_vec.size()){

                           StrVec_iter  hier_iso_it  = hier_iso_vec.begin();
                           StrVec_iter  hier_b_p_it  = hier_b_p_vec.begin();

                           while( hier_b_p_it != hier_b_p_vec.end() ){
                                  if( (*hier_b_p_it).compare(*hier_iso_it) != 0 ){
                                       pass = false;
                                       break;
                                  }

                              hier_b_p_it++;
                              hier_iso_it++;
                           } 
                                     
                          if( pass == true )
                          return iso_domain_nm;
                       }
                   }
               }
                          
return Default_nm;
}





std::string   ISO_Util::get_ISO_Rule_Name(ISO_Table *iso_table,
                                            std::string from, 
                                            std::string to){

               assert( iso_table != NULL &&
                       !from.empty()     &&
                       !to.empty()       && "ISO_Util->get_ISO_Rule_Names" );  

               ISO_Table::CtIsolationRuleVec iso_rule_vec = iso_table->get_ISO_CreateIsolationRuleVec();

               for(ISO_Table::CtIsolationRuleVec_iter iso_rule_it  = iso_rule_vec.begin();
                                                      iso_rule_it != iso_rule_vec.end();   ++iso_rule_it){

                   ISO_CreateIsolationRule *c_iso_r = static_cast<ISO_CreateIsolationRule*>(*iso_rule_it);
                   assert( c_iso_r != NULL && "ISO_Util->get_ISO_Rule_Names");

                 if( from.compare(c_iso_r->get_ISO_From()) == 0 &&
                     to.compare(  c_iso_r->get_ISO_To())   == 0 )
                     return  c_iso_r->get_ISO_Name();

               }

return "";
}




ISO_CreateIsolationRule::ISO_CondPair   ISO_Util::get_ISO_Rule_Condition(ISO_Table *iso_table,
                                                                    std::string from, 
                                                                    std::string to){

               assert( iso_table != NULL &&
                       !from.empty()     &&
                       !to.empty()       && "ISO_Util->get_ISO_Rule_Condition");  

               bool pass = false;

               ISO_Table::CtIsolationRuleVec iso_rule_vec = iso_table->get_ISO_CreateIsolationRuleVec();

               for(ISO_Table::CtIsolationRuleVec_iter iso_rule_it  = iso_rule_vec.begin();
                                                      iso_rule_it != iso_rule_vec.end();   ++iso_rule_it){

                   ISO_CreateIsolationRule *c_iso_r = static_cast<ISO_CreateIsolationRule*>(*iso_rule_it);
                   assert( c_iso_r != NULL && "ISO_Util->get_ISO_Rule_Condition");

                 if( from.compare(c_iso_r->get_ISO_From()) == 0 &&
                     to.compare(  c_iso_r->get_ISO_To())   == 0 )
                     return  c_iso_r->get_ISO_Condition();

               }

               assert( pass && "ISO_Util->get_ISO_Rule_Condition");
}




ISO_Util::ModeMap ISO_Util::get_ISO_Mode_Names(ISO_Table *iso_table,
                                            std::string from, 
                                            std::string to){

               assert( iso_table != NULL &&
                       !from.empty()     &&
                       !to.empty()       && "ISO_Util->get_ISO_Mode_Names" );  

               ModeMap mode_map;

               ISO_Table::CtPowerModeVec iso_mode_vec = iso_table->get_ISO_CreatePowerModeVec();

               for(ISO_Table::CtPowerModeVec_iter iso_mode_it  = iso_mode_vec.begin();
                                                  iso_mode_it != iso_mode_vec.end();   ++iso_mode_it){

                   ISO_CreatePowerMode *c_power_m = static_cast<ISO_CreatePowerMode*>(*iso_mode_it);
                   assert( c_power_m != NULL && "ISO_Util->get_ISO_Mode_Names");

                   ISO_CreatePowerMode::DomainCondMap dom_map = c_power_m->get_ISO_DomainCondition();
                  
                   std::string from_mode_nm;
                   std::string to_mode_nm;

                   for(ISO_CreatePowerMode::DomainCondMap_iter dom_it  = dom_map.begin();
                                                               dom_it != dom_map.end();  ++dom_it){

                       if( from.compare( dom_it->first ) ==0 ) 
                           from_mode_nm = dom_it->second;

                       if( to.compare(   dom_it->first ) ==0 )
                           to_mode_nm   = dom_it->second;

                   }

                   if( !from_mode_nm.empty() &&
                       !to_mode_nm.empty()   ){
                        mode_map[c_power_m->get_ISO_Name()].push_back(from_mode_nm);
                        mode_map[c_power_m->get_ISO_Name()].push_back(to_mode_nm);
                   }       
               }

return mode_map;
}




float      ISO_Util::get_ISO_Condition_Voltage(ISO_Table *iso_table,
                                               std::string condition){

           assert(  iso_table != NULL   &&
                   !condition.empty()   && "ISO_Util->get_ISO_Condition_Voltage");

           ISO_Table::CtNominalConditionVec cond_vec =iso_table->get_ISO_CreateNominalConditionVec();

           for( ISO_Table::CtNominalConditionVec_iter cond_it  = cond_vec.begin();
                                                      cond_it != cond_vec.end();  ++cond_it){

                ISO_CreateNominalCondition *c_nominal_c = static_cast<ISO_CreateNominalCondition*>(*cond_it);
                assert( c_nominal_c != NULL && "ISO_Util->get_ISO_Condition_Voltage");

                if( condition.compare(c_nominal_c->get_ISO_Name())==0 )
                    return c_nominal_c->get_ISO_Voltage();
           }

return -1; 
} 
