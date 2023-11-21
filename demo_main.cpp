#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "structs.hpp"
#include "setup_parameter.hpp"

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

class Set { //set task
    public:
        void call_main_task_1(Base_task *task);
        void set_main_task_1(uint8_t _mode);
        void get_main_task_1(uint8_t _mode_num);
    private:
        uint8_t max_mode_num = 8;
};




Base_task::Base_task(){}

Base_task::~Base_task() {}

int Base_task::main_task_1() { return 0; }

int Base_task::search() { return 0; }

int Base_task::run() { return 0; }

int Base_task::stop() { return 0; }

int Base_task::turn() { return 0; }

int Base_task::back() { return 0; }

int Base_task::slalom() { return 0; }

int Base_task::log() { return 0; }




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

int Run_task::main_task_1() {   //  初期化する変数が多いため、0で初期化する変数はクラスのprotected内に変数を作り初期化、それ以外はsetupparameterで初期化したものを使用する
    t_control* m;                //  と思ったけど、vel.tar.Iなど0で初期化するやつも制御の処理で使うため再検討
    t_wall_sens* sens;
    t_motion* p;

    m->I.tar.vel = 0;
    m->I.vel = 0;
    m->I.tar.ang_vel = 0;
    m->I.ang_vel = 0;
    m->I.tar.deg = 0;
    m->I.deg = 0;

    sens->enable = TRUE;

    while (p->len)
    {
        /* code */
    }
    



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

void Set::call_main_task_1(Base_task *task){    //  ポインタを引数に取る
    task->main_task_1();    //  ポインタのメンバ関数を呼び出す（実行する関数の呼び出し）
}

std::vector<std::shared_ptr<Base_task>> setmode;    //  ポインタの配列を作成

void Set::set_main_task_1(uint8_t _mode){    //  使用可能な処理を登録（LEDで表現できる数の最大数を引数とする）
    

    setmode.push_back(std::make_shared<Search_task>());  //  ポインタを配列に追加（使用する処理の数だけ。最大数に気を付けて）
    setmode.push_back(std::make_shared<Run_task>());
    setmode.push_back(std::make_shared<Turn_task>());
    setmode.push_back(std::make_shared<Back_task>());
    setmode.push_back(std::make_shared<Slalom_task>());
    setmode.push_back(std::make_shared<Log_task>());
    
    std::cout << "setmode" << std::endl;
}


void Set::get_main_task_1(uint8_t _mode_num){
    Set set;
    set.set_main_task_1(max_mode_num);
    std::cout << "get_main_task_1" << std::endl;
    set.call_main_task_1(setmode[_mode_num].get());    //  ポインタの配列の中から、引数で指定した番号のポインタを呼び出す
    
}

int  main(){
    int _mode;
    std::cout << "Enter the number of mode" << std::endl;
    std::cin >> _mode;

    Set set;
    set.get_main_task_1(_mode);

    std::cout << "Finish" << std::endl;

    return 0;
}

