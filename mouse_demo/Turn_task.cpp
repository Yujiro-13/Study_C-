#include "Turn_task.hpp"

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
