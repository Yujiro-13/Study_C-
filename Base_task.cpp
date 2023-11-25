#include "Base_task.hpp"
#include "interupt.hpp"

Base_task::Base_task(){}

Base_task::~Base_task() {}

int Base_task::main_task_1(std::shared_ptr<t_local_dir> l) { return 0; }    //  方向定義をここで行う（仮）

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

int Search_task::main_task_1(std::shared_ptr<t_local_dir> l) {
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


Turn_task::Turn_task() : Base_task() {}

int Turn_task::main_task_1(std::shared_ptr<t_local_dir> l) {
    Interupt interupt(this);
    set_s->enable = FALSE;
    set_m->flag = RIGHT;
    //set_m->flag = LEFT;
    local_deg = set_m->deg;
    while((set_v->tar.deg - (set_m->deg - local_deg)) > (set_v->tar.ang_vel * set_v->tar.ang_vel) / (2.0 * set_m->ang_acc)){
        std::cout << "set_m->deg : " << set_m->deg << std::endl;

    }
    set_m->ang_acc = -(set_m->ang_acc);
    while(set_v->tar.deg > (set_m->deg - local_deg)){
        std::cout << "set_m->deg : " << set_m->deg << std::endl;
    }

    std::cout << "main_task_1 : Turn" << std::endl;
    return 0;
}

int Turn_task::turn() {
    std::cout << "turn" << std::endl;
    return 0;
}

Back_task::Back_task() : Base_task() {}

int Back_task::main_task_1(std::shared_ptr<t_local_dir> l) {
    std::cout << "main_task_1 : Back" << std::endl;
    return 0;
}

int Back_task::back() {
    std::cout << "back" << std::endl;
    return 0;
}

Slalom_task::Slalom_task() : Base_task() {}

int Slalom_task::main_task_1(std::shared_ptr<t_local_dir> l) {
    std::cout << "main_task_1 : Slalom" << std::endl;
    return 0;
}

int Slalom_task::slalom() {
    std::cout << "slalom" << std::endl;
    return 0;
}

Log_task::Log_task() : Base_task() {}

int Log_task::main_task_1(std::shared_ptr<t_local_dir> l) {
    std::cout << "main_task_1 : Log" << std::endl;
    return 0;
}

int Log_task::log() {
    std::cout << "log" << std::endl;
    return 0;
}

