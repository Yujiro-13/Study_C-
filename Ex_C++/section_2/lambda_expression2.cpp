#include <functional>
#include <iostream>

int Add(int x, int y) {
    return x + y;
}

/*std::function で関数ポインタやラムダ式（キャプチャを持つラムダ式も含む）を保持することが出来る。 std::function を使うことで、関数ポインタのような複雑な構文が簡潔になるという利点もある。*/

int main() {
    std::function<int(int, int)> f = Add;  // std::function<戻り値の型(引数の型)> 変数名
    int result = f(3, 5);                  // f を介して関数 Add が実行される
    std::cout << result << std::endl;      // 8

    f = [](int x, int y) { return x * y; };  // ラムダ式も保持可能
    std::cout << f(4, 7) << std::endl;       // 28

    return 0;
}