#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "structs.hpp"
//#include "demo_main.hpp"
//#include "interupt.hpp"
#include "Set.hpp"


Base_task::Base_task(){}

Base_task::~Base_task() {}

int Base_task::main_task_1() { return 0; }

int Base_task::search() { return 0; }

int Base_task::run() { return 0; }

int Base_task::stop() { return 0; }

int Base_task::turn() { return 0; }

int Base_task::back() { return 0; }

int Base_task::slalom() { return 0; }

int Base_task::log() { return 0; }

void Base_task::cp_param(std::shared_ptr<t_motion> m){  //  ポインタをコピー
    set_m = m;
}

void Base_task::cp_tar(std::shared_ptr<t_motion_val> v){
    set_v = v;
}

void Base_task::cp_pid(std::shared_ptr<t_control> c){
    set_c = c;
}

void Base_task::cp_wall_th(std::shared_ptr<t_wall_sens> s){
    set_s = s;
}





Search_task::Search_task() : Base_task() {}

int Search_task::main_task_1() {
    run();
    turn();
    run();
    stop();
    std::cout << "main_task_1 : Search" << std::endl;
    return 0;
}

int Search_task::search() {
    std::cout << "search" << std::endl;
    return 0;
}

Run_task::Run_task() : Base_task() {}

int Run_task::main_task_1() {   //  初期化する変数が多いため、0で初期化する変数はクラスのprotected内に変数を作り初期化、それ以外はsetupparameterで初期化したものを使用する
   

    //s->enable = TRUE;

    std::cout << set_v->tar.len << std::endl;
    std::cout << set_v->tar.vel << std::endl;
    std::cout << set_m->acc << std::endl;

  
    /*while (((set_v->tar.len - 10) - set_m->len) > 1000.0 * (((set_v->tar.vel)*(set_v->tar.vel) - (set_v->end.vel)*(set_v->end.vel)) / (2.0 * 
    set_m->acc)))
    {
        interupt->calc_target();
    }*/
    

    std::cout << "main_task_1 : Run" << std::endl;
    return 0;
}

int Run_task::run() {
    std::cout << "run" << std::endl;
    return 0;
}

Turn_task::Turn_task() : Base_task() {}

int Turn_task::main_task_1() {
    std::cout << "main_task_1 : Turn" << std::endl;
    return 0;
}

int Turn_task::turn() {
    std::cout << "turn" << std::endl;
    return 0;
}

Back_task::Back_task() : Base_task() {}

int Back_task::main_task_1() {
    std::cout << "main_task_1 : Back" << std::endl;
    return 0;
}

int Back_task::back() {
    std::cout << "back" << std::endl;
    return 0;
}

Slalom_task::Slalom_task() : Base_task() {}

int Slalom_task::main_task_1() {
    std::cout << "main_task_1 : Slalom" << std::endl;
    return 0;
}

int Slalom_task::slalom() {
    std::cout << "slalom" << std::endl;
    return 0;
}

Log_task::Log_task() : Base_task() {}

int Log_task::main_task_1() {
    std::cout << "main_task_1 : Log" << std::endl;
    return 0;
}

int Log_task::log() {
    std::cout << "log" << std::endl;
    return 0;
}




int  main(){
    Set set;
    int _mode;
    //setupParameter(&m,&c,&w,&v);

    
    std::cout << "Enter the number of mode" << std::endl;
    std::cin >> _mode;

   
    set.get_main_task_1(_mode);

    std::cout << "Finish" << std::endl;

    return 0;
}

