#include <iostream> 
#include <string>
#include <memory>
#include "mystruct.hpp"


// 設定されたパラメータを使用するファイル

int *ptr2;
t_ab *xy;


int cp_ptr(int *ptr1){
    ptr2 = ptr1;
    
    std::cout << "ptr1 = " << *ptr1 << std::endl;
    std::cout << "ptr2 = " << *ptr2 << std::endl;
    
    return *ptr2;
}

void cp_struct_ptr(t_ab *ab){
    xy = ab;
    
    std::cout << "ab.a = " << (*ab).a << std::endl;
    std::cout << "xy.a = " << (*xy).a << std::endl;
    
    return;
}

void cp_struct_ptr_allow(t_ab *ab){
    xy = ab;
    
    std::cout << "ab.a = " << ab->a << std::endl;
    std::cout << "xy.a = " << xy->a << std::endl;
    
    return;
}