#include <iostream>
#include <string>
#include <memory>
#include "cp_ptr2.cpp"


int x = 100;
int *ptr1 = &x; //  ポインタptr1にxのアドレスを代入

void set_ptr(){
    ptr1 = &x;
    std::cout << *ptr1 << std::endl;
    cp_ptr(ptr1);
}