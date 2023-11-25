#ifndef BASE_TASK_HPP
#define BASE_TASK_HPP

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
        virtual int main_task_1(std::shared_ptr<t_local_dir> l);
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
        std::shared_ptr<t_motion_dir> set_d;
        std::shared_ptr<t_local_dir> set_l;


    protected:
        int m_mode;
        float tar_speed;
        float length;
        float calc_l;
        float calc_r;
        //float V_l;
        //float V_r;

        

};


class Search_task : public Base_task{
    public:
        Search_task();
        virtual int main_task_1(std::shared_ptr<t_local_dir> l) override;
        virtual int search() override;
        
    
    protected:
        float vel;
        float acc;
        float ang_vel;
        float max_vel;
        float end_vel;
};



class Turn_task : public Base_task{
    public:
        Turn_task();
        virtual int main_task_1(std::shared_ptr<t_local_dir> l) override;
        virtual int turn() override;
    
    protected:
        float deg;
        float ang_vel;
        float max_ang_vel;
        float end_ang_vel;
        float local_deg;
        //t_local_dir Turn_flag;
};

class Back_task : public Base_task{
    public:
        Back_task();
        virtual int main_task_1(std::shared_ptr<t_local_dir> l) override;
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
        virtual int main_task_1(std::shared_ptr<t_local_dir> l) override;
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
        virtual int main_task_1(std::shared_ptr<t_local_dir> l) override;
        virtual int log() override;
    
    protected:
        float vel;
        float acc;
        float ang_vel;
        float max_vel;
        float end_vel;
};




#endif