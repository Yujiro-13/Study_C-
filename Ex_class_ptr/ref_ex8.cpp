#include <iostream>
#include <memory>

// 構造体の定義
struct MyStruct {
    int data;
};

// クラスAの定義
class ClassA {
public:
    // 構造体へのスマートポインタを受け取るメンバ関数
    void setData(std::shared_ptr<MyStruct> &myStruct) {
        myStructA = myStruct; // 任意の値を設定
        //Calc_val();
    }
    void Calc_val(int num){
        myStructA->data = num;
    }
    private:
    
    std::shared_ptr<MyStruct> myStructA;
};

// クラスBの定義
class ClassB {
public:
    // 構造体へのスマートポインタを受け取るメンバ関数
    void displayData(const std::shared_ptr<MyStruct> &myStruct) {
        myStructB = myStruct; // 任意の値を設定
        std::cout << "Data in ClassB: " << myStructB->data << std::endl;
    }
    void Calc_val(int num){
        myStructB->data = num;
    }
    private:
    std::shared_ptr<MyStruct> myStructB;
};

class ClassC {
public:
    // 構造体へのスマートポインタを受け取るメンバ関数
    void displayData(const std::shared_ptr<MyStruct> &myStruct) {
        myStructC = myStruct; // 任意の値を設定
        std::cout << "Data in ClassC: " << myStructC->data << std::endl;
    }
    void Calc_val(int num){
        myStructC->data = num;
    }
    private:
    std::shared_ptr<MyStruct> myStructC;
};

int main() {
    // 構造体のスマートポインタを作成
    std::shared_ptr<MyStruct> myStruct = std::make_shared<MyStruct>();

    // クラスAのインスタンスを作成し、構造体のスマートポインタを受け渡しで設定
    ClassA classA;
    classA.setData(myStruct);
    classA.Calc_val(100);

    // クラスBのインスタンスを作成し、構造体のスマートポインタを受け渡しで表示
    ClassB classB;
    classB.displayData(myStruct);

    classA.Calc_val(200);
    classB.displayData(myStruct);

    classA.Calc_val(300);
    classB.displayData(myStruct);

    classB.Calc_val(400);

    ClassC classC;
    classC.displayData(myStruct);

    return 0;
}
