
SC_Util *sc_util = new SC_Util();

typedef std::vector<SC_Module::SC_Port_D*>           PtVec;
typedef std::vector<SC_Module::SC_Port_D*>::iterator PtVec_iter;

PtVec   pt_vv;
SC_Module::SC_Port_D *sc_src = sc_util->split_path_2_Port(sc_root,test_p);
                               sc_util->get_PreestPassVec(sc_src,&pt_vv);

sc_src->dump_Context();
std::cout << sc_util->get_HierarchyName(sc_src) << std::endl;

std::cout << "====================" << std::endl;

for(PtVec_iter pt_it  = pt_vv.begin();
               pt_it != pt_vv.end();  ++pt_it){
               
    SC_Module::SC_Port_D *sc_preest_p = static_cast<SC_Module::SC_Port_D*>(*pt_it);
                          sc_preest_p->dump_Context();
    std::cout << sc_util->get_HierarchyName(sc_preest_p) << std::endl;
}

