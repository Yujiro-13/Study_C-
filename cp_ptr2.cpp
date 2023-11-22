#include <iostream> 
#include <string>
#include <memory>





int func(){
    int x = 100;
    int *ptr1 = &x; //  ポインタptr1にxのアドレスを代入
    std::cout << *ptr1 << std::endl;
    
    return *ptr1;
}