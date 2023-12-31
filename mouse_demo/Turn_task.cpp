#include "include/Turn_task.hpp"

Turn_task::Turn_task() : Base_task() {}

int Turn_task::main_task_1() {
    turn_left();
    turn_right();
    std::cout << "main_task_1 : Turn" << std::endl;
    return 0;
}

int Turn_task::turn_left() {
    Interupt interupt(this);    // インタラプトはまとめられるかも
    set_s->enable = FALSE;
    set_m->flag = RIGHT;
    
    local_deg = set_m->deg;
    while((set_v->tar.deg - (set_m->deg - local_deg)) > (set_v->tar.ang_vel * set_v->tar.ang_vel) / (2.0 * set_m->ang_acc)){
        std::cout << "set_m->deg : " << set_m->deg << std::endl;

    }
    set_m->ang_acc = -(set_m->ang_acc);
    while(set_v->tar.deg > (set_m->deg - local_deg)){
        std::cout << "set_m->deg : " << set_m->deg << std::endl;
    }

    
    std::cout << "turn_left" << std::endl;
    return 0;
}

int Turn_task::turn_right() {
    Interupt interupt(this);
    set_s->enable = FALSE;
    set_m->flag = LEFT;
    
    local_deg = set_m->deg;
    while((set_v->tar.deg - (set_m->deg - local_deg)) > (set_v->tar.ang_vel * set_v->tar.ang_vel) / (2.0 * set_m->ang_acc)){
        std::cout << "set_m->deg : " << set_m->deg << std::endl;

    }
    set_m->ang_acc = -(set_m->ang_acc);
    while(set_v->tar.deg > (set_m->deg - local_deg)){
        std::cout << "set_m->deg : " << set_m->deg << std::endl;
    }

    
    std::cout << "turn_right" << std::endl;
    return 0;
}