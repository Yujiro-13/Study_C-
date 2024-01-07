#include <stdio.h>

void funcB(short & numB)
{
    numB = 80;
    printf("numB:%d\n", numB);
    printf("numB:0x%p\n", &numB);
}

int main()
{
    short numA = 50;

    printf("numA:%d\n", numA);
    funcB(numA);
    printf("numA:%d\n", numA);

    //  「numA」「numB」の番地表示
    printf("numA:0x%p\n", &numA);
    

    return 0;
}