#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "structs.hpp"

class setup_parameter
{
public:
    setup_parameter();
    ~setup_parameter();
    
    void input_tar(t_motion_val &v);
    void input_param(t_motion &m);
    void input_pid(t_control &c);
    void input_wall_th(t_wall_sens &s);
    void setup_param();

private:
    t_motion* set_m;
    t_control* set_c;
    t_wall_sens* set_s;
    t_motion_val* set_v;
};





