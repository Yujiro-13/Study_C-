#include <iostream>

// 構造体の定義
struct MyStruct
{
    int data;
};

// クラスAの定義
class ClassA
{
public:
    // 構造体へのポインタを受け取るメンバ関数
    void setData(MyStruct *myStruct)
    {
        myStructA = myStruct; // 任意の値を設定
        // Calc_val();
    }
    void Calc_val(int num)
    {
        myStructA->data = num;
    }

private:
    MyStruct *myStructA;
};

// クラスBの定義
class ClassB
{
public:
    // 構造体へのポインタを受け取るメンバ関数
    void displayData(MyStruct *myStruct)
    {
        myStructB = myStruct; // 任意の値を設定
        std::cout << "Data in ClassB: " << myStructB->data << std::endl;
    }
    void Calc_val(int num)
    {
        myStructB->data = num;
    }

private:
    MyStruct *myStructB;
};

// クラスCの定義
class ClassC
{
public:
    // 構造体へのポインタを受け取るメンバ関数
    void displayData(MyStruct *myStruct)
    {
        myStructC = myStruct; // 任意の値を設定
        std::cout << "Data in ClassC: " << myStructC->data << std::endl;
    }
    void Calc_val(int num)
    {
        myStructC->data = num;
    }

private:
    MyStruct *myStructC;
};

void setmode(uint8_t &mode, MyStruct &myStructInstance, ClassA &classA, ClassB &classB, ClassC &classC)
{
    switch (mode)
    {
    case 0:
        // クラスAのインスタンスを作成し、構造体のポインタを受け渡しで設定
        classA.setData(&myStructInstance);
        classA.Calc_val(100);

        // クラスBのインスタンスを作成し、構造体のポインタを受け渡しで表示
        classB.displayData(&myStructInstance);

        classA.Calc_val(200);
        classB.displayData(&myStructInstance);

        classA.Calc_val(300);
        classB.displayData(&myStructInstance);

        classB.Calc_val(400);

        classC.displayData(&myStructInstance);

        classC.Calc_val(500);
        classB.displayData(&myStructInstance);
        classC.displayData(&myStructInstance);
        break;
    case 1:
        classB.Calc_val(600);
        classB.displayData(&myStructInstance);
        classC.displayData(&myStructInstance);
        break;
    case 2:
        classC.Calc_val(700);
        classB.displayData(&myStructInstance);
        classC.displayData(&myStructInstance);
        break;

    default:
        break;
    }
}

uint8_t mode = 0;
bool flag = true;
MyStruct myStructInstance;
ClassA classA;
ClassB classB;
ClassC classC;

int main()
{

    while (flag)
    {
        std::cout << "mode:" << std::endl;
        // std::cin >> mode;
        scanf("%hhd", &mode);

        // 不要な改行文字をクリア
        // std::cin.clear();
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        setmode(mode, myStructInstance, classA, classB, classC);
        // break;
    }

    return 0;
}
