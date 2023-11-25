#include "structs.hpp"
#include "setup_parameter.hpp"
#include <iostream>


setup_parameter::setup_parameter(){}

setup_parameter::~setup_parameter(){}

void setup_parameter::input_param(t_motion &m){
    set_m = &m;
}

void setup_parameter::input_tar(t_motion_val &v){
    set_v = &v;
}

void setup_parameter::input_pid(t_control &c){
    set_c = &c;
}

void setup_parameter::input_wall_th(t_wall_sens &s){
    set_s = &s;
}

void setup_parameter::setup_param(){
    
}


void setupParameter(t_motion* param, t_control* pid, t_wall_sens* wall, t_motion_val* val)  //parameter setup
{
    


    val->tar.vel = 0.3;   //  構造体つなげ方逆の方がいい（後ろに来る変数ほど自由度が高くなる）
    val->tar.ang_vel = 0;
    val->tar.deg = 0;
    val->tar.len = 90;
    param->acc = 1.0;
    param->ang_acc = 0;

    std::cout << val->tar.vel << std::endl;
    std::cout << param->acc << std::endl;

    pid->v.Kp = 0;
    pid->v.Ki = 0;
    pid->v.Kd = 0;
    pid->o.Kp = 0;
    pid->o.Ki = 0;
    pid->o.Kd = 0;
    pid->d.Kp = 0;
    pid->d.Ki = 0;
    pid->d.Kd = 0;
    pid->wall.Kp = 0;

    wall->th_wall.fl = 0;
    wall->th_wall.fr = 0;
    wall->th_wall.l = 0;
    wall->th_wall.r = 0;
    wall->th_control.l = 0;
    wall->th_control.r = 0;

    


}

