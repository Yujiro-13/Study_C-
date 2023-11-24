#ifndef DEMO_MAIN_HPP
#define DEMO_MAIN_HPP

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "structs.hpp"
//#include "interupt.hpp"
//#include "Set.hpp"

class Base_task{    // base class    タスクを作るときはこのクラスを継承する
    public:
        Base_task();
        virtual ~Base_task();
        virtual int main_task_1();
        virtual int search();
        virtual int run();
        virtual int stop();
        virtual int turn();
        virtual int back();
        virtual int slalom();
        virtual int log();
        void cp_tar(std::shared_ptr<t_motion_val> v);
        void cp_param(std::shared_ptr<t_motion> m);
        void cp_pid(std::shared_ptr<t_control> c);
        void cp_wall_th(std::shared_ptr<t_wall_sens> s);
        std::shared_ptr<t_motion> set_m;
        std::shared_ptr<t_motion_val> set_v;
        std::shared_ptr<t_control> set_c;
        std::shared_ptr<t_wall_sens> set_s;


    protected:
        int m_mode;

        

};


class Search_task : public Base_task{
    public:
        Search_task();
        virtual int main_task_1() override;
        virtual int search() override;
        
    
    protected:
        float vel;
        float acc;
        float ang_vel;
        float max_vel;
        float end_vel;
};

class Run_task : public Base_task{
    public:
        Run_task();
        virtual int main_task_1() override;
        virtual int run() override;
    
    protected:
        float I_tar_ang_vel = 0;
        float I_ang_vel = 0;
        float I_tar_vel = 0;
        float I_vel = 0;
        float vel;
        float ang_vel;
        float deg;
        t_motion* motion;
        t_control* con;
        t_wall_sens* sen;
        t_motion_val* val;
        //Interupt* interupt;
};

class Turn_task : public Base_task{
    public:
        Turn_task();
        virtual int main_task_1() override;
        virtual int turn() override;
    
    protected:
        float deg;
        float ang_vel;
        float max_ang_vel;
        float end_ang_vel;
};

class Back_task : public Base_task{
    public:
        Back_task();
        virtual int main_task_1() override;
        virtual int back() override;
    
    protected:
        float vel;
        float acc;
        float ang_vel;
        float max_vel;
        float end_vel;
};

class Slalom_task : public Base_task{
    public:
        Slalom_task();
        virtual int main_task_1() override;
        virtual int slalom() override;
    
    protected:
        float vel;
        float acc;
        float ang_vel;
        float max_vel;
        float end_vel;
};

class Log_task : public Base_task{
    public:
        Log_task();
        virtual int main_task_1() override;
        virtual int log() override;
    
    protected:
        float vel;
        float acc;
        float ang_vel;
        float max_vel;
        float end_vel;
};




#endif