
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>

#include <stdio.h>
#include <assert.h>

#include "kernel/SC_Lib/SC_DFF.h"

//Ref :: http://www.asic-world.com/tidbits/all_reset.html

void SC_DFF::run_SC_Async_Reset_DFF(){

         assert( D   != NULL &&
                 Q   != NULL &&
                 Rst != NULL &&
                 Clk != NULL && "<Err> SC_DFF::run_SC_Async_Reset_DFF");

                 SC_Logic_D *D_l   = dynamic_cast<SC_Loigc_D*>(D);
                 SC_Logic_D *Q_l   = dynamic_cast<SC_Loigc_D*>(Q);
                 SC_Logic_D *Rst_l = dynamic_cast<SC_Loigc_D*>(Rst);
                 SC_Logic_D *Clk_l = dynamic_cast<SC_Loigc_D*>(Clk);


                  if( Rst_l->get_CurLogic() == SC_Logic::SC_LOGIC_1 ) 
                      Q_l->set_CurLogic(SC_Logic::SC_LOGIC_0); 
}



// Synchronous Reset & Posedge Clk
void SC_DFF::run_SC_Sync_Pos_Reset_DFF(){

         assert( D   != NULL &&
                 Q   != NULL &&
                 Rst != NULL &&
                 Clk != NULL && "<Err> SC_DFF::run_SC_Sync_Reset_DFF");

                 SC_Logic_D *D_l   = dynamic_cast<SC_Loigc_D*>(D);
                 SC_Logic_D *Q_l   = dynamic_cast<SC_Loigc_D*>(Q);
                 SC_Logic_D *Rst_l = dynamic_cast<SC_Loigc_D*>(Rst);
                 SC_Logic_D *Clk_l = dynamic_cast<SC_Loigc_D*>(Clk);


                  if( Rst_l->get_CurLogic()  == SC_Logic::SC_LOGIC_1 && 
                      Clk_l->get_Cur_Logic() == SC_Logic::SC_LOGIC_r ) 
                      Q_l->set_CurLogic(SC_Logic::SC_LOGIC_0);
}



// Synchronous Reset & Negedge Clk
void SC_DFF::run_SC_Sync_Neg_Reset_DFF(){

         assert( D   != NULL &&
                 Q   != NULL &&
                 Rst != NULL &&
                 Clk != NULL && "<Err> SC_DFF::run_SC_Sync_Reset_DFF");

                 SC_Logic_D *D_l   = dynamic_cast<SC_Loigc_D*>(D);
                 SC_Logic_D *Q_l   = dynamic_cast<SC_Loigc_D*>(Q);
                 SC_Logic_D *Rst_l = dynamic_cast<SC_Loigc_D*>(Rst);
                 SC_Logic_D *Clk_l = dynamic_cast<SC_Loigc_D*>(Clk);

                  if( Rst_l->get_CurLogic()  == SC_Logic::SC_LOGIC_1 && 
                      Clk_l->get_Cur_Logic() == SC_Logic::SC_LOGIC_f) 
                      Q->set_CurLogic(SC_Logic::SC_LOGIC_0);
}



void SC_DFF::run_SC_Pos_Clk_DFF(){

         assert( D   != NULL &&
                 Q   != NULL &&
                 Rst != NULL &&
                 Clk != NULL && "<Err> SC_DFF::run_SC_Pos_Clk_DFF");

                 SC_Logic_D *D_l   = dynamic_cast<SC_Loigc_D*>(D);
                 SC_Logic_D *Q_l   = dynamic_cast<SC_Loigc_D*>(Q);
                 SC_Logic_D *Rst_l = dynamic_cast<SC_Loigc_D*>(Rst);
                 SC_Logic_D *Clk_l = dynamic_cast<SC_Loigc_D*>(Clk);


                  if( D_l->get_CurLogic() == SC_Logic::SC_LOGIC_r ) 
                      Q_l->set_CurLogic( D_l->get_CurLogic() );  
}



void SC_DFF::run_SC_Neg_Clk_DFF(){

         assert( D   != NULL &&
                 Q   != NULL &&
                 Rst != NULL &&
                 Clk != NULL && "<Err> SC_DFF::run_SC_Neg_Clk_DFF");

                 SC_Logic_D *D_l   = dynamic_cast<SC_Loigc_D*>(D);
                 SC_Logic_D *Q_l   = dynamic_cast<SC_Loigc_D*>(Q);
                 SC_Logic_D *Rst_l = dynamic_cast<SC_Loigc_D*>(Rst);
                 SC_Logic_D *Clk_l = dynamic_cast<SC_Loigc_D*>(Clk);


                  if( D_l->get_CurLogic() == SC_Logic::SC_LOGIC_f ) 
                      Q_l->set_CurLogic( D_l->get_CurLogic() );  
}
