#include <iostream>
#include <bitset>

int main()
{
    int x, y = 5;
    x + y;             // 加算
    x - y;             // 減算
    x *y;              // 乗算
    x / y;             // 除算
    x % y;             // 剰余
    int div = 100 / 0; // 実行時エラー
    int mod = 100 % 0; // 実行時エラー

    int ix = 100;
    int iy = 50;
    double dx = 100.0;
    double dy = 50.0;

    auto a = ix / iy; // int = int / int
    // auto b = ix / dy; // double = double(intから変換) / double
    auto c = dx / iy; // double = double / double(intから変換)
    auto d = dx / dy; // double = double / double

    ++x; // 前置インクリメント
    x++; // 後置インクリメント
    --x; // 前置デクリメント
    x--; // 後置デクリメント

    int a = 5;
    int b = 0;

    b = ++a;                     // aをインクリメントしてから、bに代入する
    std::cout << a << std::endl; // 6
    std::cout << b << std::endl; // 6

    int a = 5;
    int b = 0;

    b = a++;                     // aをbに代入してから、aをインクリメントする
    std::cout << a << std::endl; // 6
    std::cout << b << std::endl; // 5

    /*使用する状況にも依るが、 後置インクリメント/デクリメントよりも前置インクリメント/デクリメントのほうが効率が良いとされている*/

    int z = 1;
    ~x;     // 否定
    x << y; // 左シフト
    x >> z; // 右シフト
    x & y;  // 論理積
    x | y;  // 論理和
    x ^ y;  // 排他的論理和

    /*std::bitset を使うことで、ビット列(2進数)での表記が確認できる*/
    auto bits_a = std::bitset<8>("00001111"); // 15を8ビットで表す: 00001111
    std::cout << ~bits_a << std::endl;        // 否定: 11110000
    std::cout << (bits_a << 2) << std::endl;  // 左に2シフト: 00111100
    std::cout << (bits_a >> 2) << std::endl;  // 右に2シフト: 00000011

    auto bits_b = std::bitset<8>("00111100");    // 60を8ビットで表す: 00111100
    std::cout << (bits_a & bits_b) << std::endl; // 論理積: 00001100
    std::cout << (bits_a | bits_b) << std::endl; // 論理和: 00111111
    std::cout << (bits_a ^ bits_b) << std::endl; // 排他的論理和: 00110011

    unsigned int a = 0x0000000f;            // 15
    std::cout << std::showbase << std::hex; // 基数のプレフィックスを出力 + 16進法で出力
    std::cout << ~a << std::endl;           // 0xfffffff0
    std::cout << (a << 2) << std::endl;     // 0x3c
    std::cout << (a >> 2) << std::endl;     // 0x3

    unsigned int b = 0x0000003c;       // 60
    std::cout << (a & b) << std::endl; // 0xc
    std::cout << (a | b) << std::endl; // 0x3f
    std::cout << (a ^ b) << std::endl; // 0x33

    a += b;  // a = a + b と同じ
    a -= b;  // a = a - b
    a *= b;  // a = a * b
    a /= b;  // a = a / b
    a %= b;  // a = a % b
    a &= b;  // a = a & b
    a |= b;  // a = a | b
    a ^= b;  // a = a ^ b
    a <<= b; // a = a << b
    a >>= b; // a = a >> b

    int x = 2;
    x *= 4 + 3;
    std::cout << x << std::endl; // 14

    int y = 2;
    y = y * 4 + 3;
    std::cout << y << std::endl; // 11

    /*代入演算子は算術演算子よりも後に解釈される。 複合代入も、代入演算子と同様に算術演算子よりも後に解釈されることになる*/
}