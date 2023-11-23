#include <iostream>
#include <string>
#include <vector>
#include "structs.hpp"

class Base_task {
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
    void cp_tar(t_motion_val* v);
    void cp_param(t_motion* m);
    void cp_pid(t_control* c);
    void cp_wall_th(t_wall_sens* s);

protected:
    int m_mode;
    t_motion* set_m;
    t_motion_val* set_v;
    t_control* set_c;
    t_wall_sens* set_s;
};

class Search_task : public Base_task {
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

class Run_task : public Base_task {
public:
    Run_task();
    virtual int main_task_1() override;
    virtual int run() override;

protected:
    float I_tar_ang_vel;
    float I_ang_vel;
    float I_tar_vel;
    float I_vel;
    float vel;
    float ang_vel;
    float deg;
    t_motion* m;
    t_control* c;
    t_wall_sens* s;
    t_motion_val* v;
};

class Turn_task : public Base_task {
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

class Back_task : public Base_task {
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

class Slalom_task : public Base_task {
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

class Log_task : public Base_task {
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

class Set {
public:
    void call_main_task_1(Base_task* task);
    void set_main_task_1(uint8_t _mode);
    void get_main_task_1(uint8_t _mode_num);
    void set_param(Base_task* task);

private:
    uint8_t max_mode_num = 8;
    t_motion param;
    t_motion_val val;
    t_control ctl;
    t_wall_sens sens;
};

Base_task::Base_task() {}

Base_task::~Base_task() {}

int Base_task::main_task_1() { return 0; }

int Base_task::search() { return 0; }

int Base_task::run() { return 0; }

int Base_task::stop() { return 0; }

int Base_task::turn() { return 0; }

int Base_task::back() { return 0; }

int Base_task::slalom() { return 0; }

int Base_task::log() { return 0; }

void Base_task::cp_param(t_motion* m) { set_m = m; }

void Base_task::cp_tar(t_motion_val* v) { set_v = v; }

void Base_task::cp_pid(t_control* c) { set_c = c; }

void Base_task::cp_wall_th(t_wall_sens* s) { set_s = s; }

Search_task::Search_task() : Base_task() {}

int Search_task::main_task_1() {
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

Run_task::Run_task() : Base_task() {}

int Run_task::main_task_1() {
    std::cout << set_v->tar.len << std::endl;
    std::cout << set_v->tar.vel << std::endl;
    std::cout << set_m->acc << std::endl;

    std::cout << "main_task_1 : Run" << std::endl;
    return 0;
}

int Run_task::run() {
    std::cout << "run" << std::endl;
    return 0;
}

Turn_task::Turn_task() : Base_task() {}

int Turn_task::main_task_1() {
    std::cout << "main_task_1 : Turn" << std::endl;
    return 0;
}

int Turn_task::turn() {
    std::cout << "turn" << std::endl;
    return 0;
}

Back_task::Back_task() : Base_task() {}

int Back_task::main_task_1() {
    std::cout << "main_task_1 : Back" << std::endl;
    return 0;
}

int Back_task::back() {
    std::cout << "back" << std::endl;
    return 0;
}

Slalom_task::Slalom_task() : Base_task() {}

int Slalom_task::main_task_1() {
    std::cout << "main_task_1 : Slalom" << std::endl;
    return 0;
}

int Slalom_task::slalom() {
    std::cout << "slalom" << std::endl;
    return 0;
}

Log_task::Log_task() : Base_task() {}

int Log_task::main_task_1() {
    std::cout << "main_task_1 : Log" << std::endl;
    return 0;
}

int Log_task::log() {
    std::cout << "log" << std::endl;
    return 0;
}

std::vector<Base_task*> setmode; // ポインタの配列を作成

void Set::set_main_task_1(uint8_t _mode) {
    setmode.push_back(new Search_task()); // ポインタを配列に追加（使用する処理の数だけ。最大数に気を付けて）
    setmode.push_back(new Run_task());
    setmode.push_back(new Turn_task());
    setmode.push_back(new Back_task());
    setmode.push_back(new Slalom_task());
    setmode.push_back(new Log_task());

    std::cout << "setmode" << std::endl;
}

void Set::get_main_task_1(uint8_t _mode_num) {
    Set set;
    set.set_main_task_1(max_mode_num);
    std::cout << "get_main_task_1" << std::endl;
    set.set_param(setmode[_mode_num]); // パラメータを設定
    set.call_main_task_1(setmode[_mode_num]); // ポインタの配列の中から、引数で指定した番号のポインタを呼び出す
}

void Set::set_param(Base_task* task) {
    param.acc = 1.0;
    param.ang_acc = 0;
    val.tar.vel = 0.3;
    val.tar.ang_vel = 0;
    val.tar.deg = 0;
    val.tar.len = 90;
    ctl.v.Kp = 0;
    ctl.v.Ki = 0;
    ctl.v.Kd = 0;
    ctl.o.Kp = 0;
    ctl.o.Ki = 0;
    ctl.o.Kd = 0;
    ctl.d.Kp = 0;
    ctl.d.Ki = 0;
    ctl.d.Kd = 0;
    ctl.wall.Kp = 0;
    sens.th_wall.fl = 0;
    sens.th_wall.fr = 0;
    sens.th_wall.l = 0;
    sens.th_wall.r = 0;
    sens.th_control.l = 0;
    sens.th_control.r = 0;

    task->cp_param(&param);
    task->cp_tar(&val);
    task->cp_pid(&ctl);
    task->cp_wall_th(&sens);

    std::cout << "set_param" << std::endl;
}

void Set::call_main_task_1(Base_task* task) {
    task->main_task_1(); // ポインタのメンバ関数を呼び出す（実行する関数の呼び出し）
}

int main() {
    Set set;
    int _mode;

    std::cout << "Enter the number of mode" << std::endl;
    std::cin >> _mode;

    set.get_main_task_1(_mode);

    std::cout << "Finish" << std::endl;

    // Clean up allocated memory
    for (auto task : setmode) {
        delete task;
    }

    return 0;
}
