#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "structs.hpp"
#include "demo_main.hpp"

class Set { //set task
    public:
        void call_main_task_1(Base_task *task);
        void set_main_task_1(uint8_t _mode);
        void get_main_task_1(uint8_t _mode_num);
        void set_param(Base_task *task);
    private:
        uint8_t max_mode_num = 8;
        std::shared_ptr<t_motion> param;
        std::shared_ptr<t_motion_val> val;
        std::shared_ptr<t_control> ctl;
        std::shared_ptr<t_wall_sens> sens;
        
};

#endif