#include <iostream>

// 構造体の定義
struct MyStruct {
    int data;
};

// クラスAの定義
class ClassA {
public:
    void setData(MyStruct *myStruct) {
        myStructA = myStruct;
        Calc_val();
    }
    // ...
private:
    void Calc_val() {
        myStructA->data = 100;
    }
    MyStruct *myStructA;
};

// クラスBの定義
class ClassB {
public:
    void displayData(MyStruct *myStruct) {
        myStructB = myStruct;
        std::cout << "Data in ClassB: " << myStructB->data << std::endl;
    }
    // ...
private:
    MyStruct *myStructB;
};

int main() {
    // 構造体の静的なインスタンスを作成
    MyStruct myStruct;

    // クラスAのインスタンスを作成し、構造体へのポインタを渡し、設定
    ClassA classA;
    classA.setData(&myStruct);

    // クラスBのインスタンスを作成し、構造体へのポインタを渡し、表示
    ClassB classB;
    classB.displayData(&myStruct);

    return 0;
}
