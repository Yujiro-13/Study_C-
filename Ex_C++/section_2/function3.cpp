#include <iostream>

void Print(int x) {
    std::cout << "int: " << x << std::endl;
}

void Print(double x) {
    std::cout << "double: " << x << std::endl;
}

int main() {
    Print(2);
    Print(2.1);

    return 0;
}

/*関数の引数の個数や型が異なる場合、同じ名前の関数を定義することが出来る。 これを（関数の）オーバーロードと呼ぶ。引数の個数や型の情報を元に呼び出す関数を決定している。*/