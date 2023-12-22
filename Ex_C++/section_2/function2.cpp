#include <iostream>

int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; ++i) {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }

    return 0;
}
/*main関数にも引数を渡すことが可能。main関数に渡される引数をコマンドライン引数と呼ぶ。 
コマンドライン引数は、プログラム実行時に実行ファイル名に続けて半角スペース区切りで複数指定することが出来る*/

/*# 実行ファイル名 <引数1> <引数2> <引数3> ...
$ ./a.exe XXX YYY ZZZ*/