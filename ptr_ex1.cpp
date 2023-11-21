//  構造体ポインタ型変数をグローバル変数のように使用する

#include <iostream>

// 構造体の定義
struct MyStruct {
    int value;
};

// グローバルな構造体ポインタ変数の宣言
MyStruct* globalStructPointer = nullptr;

// 関数の定義
void setGlobalStructPointerValue(int value) {
    // グローバルな構造体ポインタを使用して値を設定
    if (globalStructPointer != nullptr) {
        globalStructPointer->value = value;
    }
}

void printGlobalStructPointerValue() {
    // グローバルな構造体ポインタを使用して値を表示
    if (globalStructPointer != nullptr) {
        std::cout << "Global Struct Pointer Value: " << globalStructPointer->value << std::endl;
    } else {
        std::cout << "Global Struct Pointer is null." << std::endl;
    }
}

int main() {
    // メモリの動的確保を行い、グローバルな構造体ポインタにそのアドレスを割り当てる
    globalStructPointer = new MyStruct;

    // グローバルな構造体ポインタを使用して値を設定および表示
    setGlobalStructPointerValue(42);
    printGlobalStructPointerValue();

    // メモリの解放
    delete globalStructPointer;
    globalStructPointer = nullptr;

    return 0;
}
