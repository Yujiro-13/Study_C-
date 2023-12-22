#include <iostream>

int Add(int x, int y) {
    return x + y;
}
// 戻り値の型 (*変数名)(引数の型);
int (*f1)(double);    // double を引数として int を返す関数のポインタ f1
int (*f2)(int, int);  // 2つの int を引数として int を返す関数のポインタ f2

// 関数ポインタには、戻り値の型と引数の型・数・順番が一致している関数のアドレスが代入可能

int main() {
    int (*fp)(int, int) = Add;  // 関数 Add のアドレスを保持する関数ポインタ fp
    int result = fp(3, 5);      // 関数ポインタ fp を介して関数 Add が実行される
    std::cout << result << std::endl;  // 8

    //auto fp = Add;
    /*関数ポインタを変数に代入する際は、 auto を使うことで複雑な関数ポインタの型を書く必要が無くなり簡潔*/

    return 0;
}