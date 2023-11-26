#include "Search_task.hpp"

Search_task::Search_task() : Base_task() {}

int Search_task::main_task_1(std::shared_ptr<t_local_dir> l) {
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
