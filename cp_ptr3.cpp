#include <iostream>
#include <string>
#include <memory>
#include "cp_ptr2.cpp"
#include "mystruct.hpp"

// パラメータ設定ファイル

int x = 100;
int *ptr1; //  ポインタptr1にxのアドレスを代入
int w = 300;
t_ab *ab;
t_ab y;


void set_ptr(){
    ptr1 = &x;
    std::cout << "&ptr1 = " << ptr1 << std::endl;
    std::cout << "ptr1 = " << *ptr1 << std::endl;
    cp_ptr(ptr1);
}

void set_struct_ptr(){
    y.a = w;
    ab = &y;
    std::cout << "&ab = " << ab << std::endl;
    std::cout << "ab.a = " << (*ab).a << std::endl;
    cp_struct_ptr(ab);
}

void set_struct_ptr_allow(){
    //y.a = w;
    ab->a = w;  //  ab->a = (*ab).a = y.a = w
    ab = &y;
    std::cout << "ab.a = " << ab->a << std::endl;
    cp_struct_ptr_allow(ab);
}