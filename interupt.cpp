//#include "structs.hpp"
#include "interupt.hpp"
//#include <iostream>
//#include <string>
//#include <memory>
//#include <vector>
//#include "demo_main.cpp"
Set set;

Interupt::Interupt(Base_task* _task) : task(_task){

    set.set_param(task);
    
    std::cout << "Interupt constructor called" << std::endl;
}
Interupt::~Interupt(){
    std::cout << "Interupt destructor called" << std::endl;
}
void Interupt::calc_target(){
    //task->set_m->acc = 0.1;

    std::cout << "task->set_v->tar.vel : " << task->set_v->tar.vel << std::endl;
    std::cout << "task->set_m->acc : " << task->set_m->acc << std::endl;
    std::cout << "calc_target" << std::endl;
    return;
}
void Interupt::calc_wall_ctl(){
    std::cout << "calc_wall_ctl" << std::endl;
    return;
}
void Interupt::FB_ctl(){
    std::cout << "FB_ctl" << std::endl;
    return;
}

