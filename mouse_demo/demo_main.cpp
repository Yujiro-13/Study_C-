#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "structs.hpp"
//#include "interupt.hpp"
#include "Set.hpp"
//#include "Base_task.hpp"




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
