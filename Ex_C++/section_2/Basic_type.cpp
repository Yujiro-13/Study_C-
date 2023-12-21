#include <cstdint>

int main()
{
    bool ok = true;
    /*bool は真偽値を表す型で true または false が設定される*/

    char x = 'x';
    /*char は文字を表す型で 1 バイトの整数型として扱われる*/

    /* サイズはGCC準拠
    char は 1 (8 bit) バイトの整数型として扱われる
    short は 2 (16 bit) バイトの整数型として扱われる
    int は 4 (32 bit) バイトの整数型として扱われる
    long は 4 (大抵64 bit)バイト以上の整数型として扱われる
    */
    unsigned int x = 4000000000;
    /*各整数型に unsigned を付けると正の数しか表現できなくなる代わりに 大きな値が表現できる*/

    std::int32_t x = 5;
    /*上述の整数型は型のサイズがコンパイラによって異なるので 複数のコンパイラに対応するプログラムを書くときは 移植性の面で問題が発生することがある。
    そのようなときはサイズ指定付き整数型を使用*/

    enum Day
    {
        Sun, // 0
        Mon, // 1
        Tue, // 2
        Wed, // 3
        Thu, // 4
        Fri, // 5
        Sat  // 6
    };

    /*enum Day
    {
        Sun = 1, // 1
        Mon,     // 2
        Tue,     // 3
        Wed = 8, // 8
        Thu,     // 9
        Fri,     // 10
        Sat      // 11
    };*/

    /*enum の各列挙子は、内部では整数として扱われる。 各列挙子の定義の際に値を指定しなければ、 0 から順に値が割り振られる
    列挙子 = 整数 と書くことで値を指定することができる。値が指定された列挙子以降は、順に整数が割り振られる*/

    Day day = Fri;
    /*数値型に enum の値を代入することは可能、 enum に数値を直接代入することは出来ない。*/

    int x = Fri; // OK
    // Day day = 5;  // コンパイルエラー

    /*enum SolarSystem
    {
        Sun, // Sun は enum Day 内で定義済みのためコンパイルエラー
        Mercury,
        Venus,
        Earth,
        Mars,
        Jupiter,
        Saturn,
        Uranus,
        Neptune
    };*/
    /*列挙子の名前は被らないようにする必要がある*/

    enum class Day
    {
        Sun, // Day::Sun
        Mon,
        Tue,
        Wed,
        Thu,
        Fri,
        Sat
    };

    Day day = Day::Fri;  // OK  enum class を扱うには 型名::列挙子名
    //Day day = Fri;       // コンパイルエラー

    int x = static_cast<int>(Day::Fri); // OK   明示的に型変換 を行うことで、数値型などに enum class の値の代入が可能

    enum class SolarSystem
    {
        Sun, // Day::Sun と SolarSystem::Sun は区別されるためOK
        Mercury,
        Venus,
        Earth,
        Mars,
        Jupiter,
        Saturn,
        Uranus,
        Neptune
    };

    /*enum class の場合、列挙子の名前は型ごとに区別されるため、 他の列挙型の列挙子と名前が被っても問題ない*/
}