#include <iostream>

void fuc(int *num){
    *num = 10;
}

int main(){
    int num = 0;
    fuc(&num);
    std::cout << num << std::endl;
    return 0;
}