#include <stdio.h>

int main()
{
    short num = 50;         //  変数定義
    short & refnum = num;   //  参照変数の定義

    printf("num:%d\n", num);

    refnum = 80;            //  参照変数の書き換え

    printf("num:%d\n", num);

    //  「num」「refnum」の番地表示
    printf("num   :0x%p\n", &num);
    printf("refnum:0x%p\n", &refnum);

    return 0;
}