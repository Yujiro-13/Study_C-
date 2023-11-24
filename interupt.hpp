#ifndef INTERUPT_HPP
#define INTERUPT_HPP

#include "demo_main.hpp"
#include "Set.hpp"

class Interupt
{
    public:
        Interupt(Base_task* _task);
        ~Interupt();
        void calc_target();
        void calc_wall_ctl();
        void FB_ctl();
        
    private:
        std::shared_ptr<t_motion> param;
        std::shared_ptr<t_motion_val> val;
        std::shared_ptr<t_control> ctl;
        std::shared_ptr<t_wall_sens> sens;
        Base_task* task;

};


#endif