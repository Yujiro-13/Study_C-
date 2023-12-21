
int main()
{
    int x = 5;

    const int x = 5; //const を付けると値の書き換えが禁止
    x = 10; // エラー

    constexpr int x = 5; //constexpr を付けると定数

    /*const の値は実行時に決定しますが constexpr の値はコンパイル時に決定*/

    auto x = 5;  // x は int と推論

    /*変数の宣言時には明示的に型を指定しなくても auto を使うと 右辺の値から型を推論することができる*/
}
