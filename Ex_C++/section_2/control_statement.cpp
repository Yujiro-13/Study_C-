#include <iostream>

int main()
{
    int x = 5;

    if (x == 5)
    {
        //...
    }
    else if (x == 6)
    {
        //...
    }
    else
    {
        //...
    }
    /*条件分岐をしたい時には if を使用*/

    switch (x)
    {
    case 0:
        // x == 0 のときの処理
        break;
    case 1:
        // x == 1 のときの処理
        break;
    default:
        // x がそれ以外のときの処理
        break;
    }
    /*一つの変数の値を調べながら分岐するような処理を書きたい場合は switch 文を使用*/
    /*ただし switch 文が使用できるのは下記のいずれかの場合に限る

    ・整数型
    ・列挙型
    ・整数型か列挙型へ暗黙に変換できるクラス型*/

    /*フォールスルー*/
    switch (x)
    {
    case 0:
        // x == 0 のときの処理
    case 1:
        // x == 1 のときの処理
    default:
        // x がそれ以外のときの処理
    }
    /*break を書いた場合は switch 文の処理はそこで終わるが、 break を書かなかった場合はそのまま下の case に処理が流れる。
    つまり上記のコードは x == 0 であれば case 0 内の処理を行った後に case 1 内の処理を行い、最後に default の処理を行う。 x == 1 であれば同様の振る舞いが case 1 から始まる。
    このような switch 文の仕様をフォールスルーと呼ぶ。 これは case 0 と case 1 の処理が同じものになる場合に使用すると便利*/

    bool done = false;

    while (!done)
    {
        x += x - 3;

        std::cout << x << std::endl;

        if (x % 5 == 0)
        {
            done = true;
        }
    }
    /*while は () に渡された条件が true である限り { ... } 内の処理を実行し続ける*/

    do
    {
        x += x - 3;

        std::cout << x << std::endl;

        if (x % 5 == 0)
        {
            done = true;
        }
    } while (!done);
    /*最初の1回は無条件で do { ... } 内の処理を実行し、 2回目以降は while () に渡された条件が true である限り do { ... } 内の処理を実行し続ける*/

    for (int i = 0; i < 10; ++i)
    {
        std::cout << i << std::endl;
    }
    /*for はループするたびに変化する変数を使うことができる*/

    /*ループ文 while、 do-while、 for のループ処理は break または continue で中断することができる*/

    // break
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == j)
            {
                break; // j のループ文を抜ける
            }

            std::cout << i << "," << j << std::endl;
        }
    }

    // continue
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == j)
            {
                continue; // j のループ処理をスキップ
            }

            std::cout << i << "," << j << std::endl;
        }
    }

    do
    {
        std::cout << "done" << std::endl;
        continue; // ループ処理をスキップ (先頭に戻る動作なら無限ループとなる)

        std::cout << "never reached" << std::endl; // 実行されない
    } while (false);                               // 条件が false であるため1回目で終了
}