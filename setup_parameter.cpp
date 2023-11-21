#include "structs.hpp"
#include "setup_parameter.hpp"


t_motion m;
t_control c;
t_wall_sens w;
t_motion_val v;

void setupParameter(t_motion *&param, t_control *&pid, t_wall_sens *&wall, t_motion_val *&val)  //parameter setup
{
    param = &m; //mのアドレスを指定
    pid = &c;
    wall = &w;
    val = &v;


    val->tar.vel = 0.3;   //  構造体つなげ方逆の方がいい（後ろに来る変数ほど自由度が高くなる）
    val->tar.ang_vel = 0;
    val->tar.deg = 0;
    val->tar.len = 90;
    param->acc = 1.0;
    param->ang_acc = 0;

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

