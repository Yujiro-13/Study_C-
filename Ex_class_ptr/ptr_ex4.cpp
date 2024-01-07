#include <iostream>

// 構造体の定義
struct MyStruct {
    int data;
};

// クラスAの定義
class ClassA {
public:
    // 構造体へのポインタを受け取るメンバ関数
    void setData(MyStruct* myStruct) {
        myStructA = myStruct; // 任意の値を設定
        //Calc_val();
    }
    void Calc_val(int num) {
        myStructA->data = num;
    }

private:
    MyStruct* myStructA;
};

// クラスBの定義
class ClassB {
public:
    // 構造体へのポインタを受け取るメンバ関数
    void displayData(MyStruct* myStruct) {
        myStructB = myStruct; // 任意の値を設定
        std::cout << "Data in ClassB: " << myStructB->data << std::endl;
    }
    void Calc_val(int num) {
        myStructB->data = num;
    }

private:
    MyStruct* myStructB;
};

class ClassC {
public:
    // 構造体へのポインタを受け取るメンバ関数
    void displayData(MyStruct* myStruct) {
        myStructC = myStruct; // 任意の値を設定
        std::cout << "Data in ClassC: " << myStructC->data << std::endl;
    }
    void Calc_val(int num) {
        myStructC->data = num;
    }

private:
    MyStruct* myStructC;
};

void setmode(int mode) {
    std::cout << "mode:" << mode << std::endl;
}

int main() {
    // 構造体のインスタンスを作成
    MyStruct myStructInstance;

    // クラスAのインスタンスを作成し、構造体のポインタを受け渡しで設定
    ClassA classA;
    classA.setData(&myStructInstance);
    classA.Calc_val(100);

    // クラスBのインスタンスを作成し、構造体のポインタを受け渡しで表示
    ClassB classB;
    classB.displayData(&myStructInstance);

    classA.Calc_val(200);
    classB.displayData(&myStructInstance);

    classA.Calc_val(300);
    classB.displayData(&myStructInstance);

    classB.Calc_val(400);

    ClassC classC;
    classC.displayData(&myStructInstance);

    classC.Calc_val(500);
    classB.displayData(&myStructInstance);
    classC.displayData(&myStructInstance);


    return 0;
}
