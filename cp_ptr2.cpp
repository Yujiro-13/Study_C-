#include <iostream> 
#include <string>
#include <memory>


int *ptr2;


int cp_ptr(int *ptr1){
    ptr2 = ptr1;
    
    std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl;
    
    return *ptr2;
}