#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "include/structs.hpp"
#include "include/Set.hpp"




int  main(){
    Set set;
    
    int _mode;
    
    std::cout << "Enter the number of mode" << std::endl;
    std::cin >> _mode;

   
    set.get_main_task_1(_mode);

    

    //interupt.calc_target();

    std::cout << "Finish" << std::endl;

    return 0;
}

