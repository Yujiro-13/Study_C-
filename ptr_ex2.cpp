//  構造体ポインタ型変数をグローバル変数のように使用する（メモリ確保にスマートポインタを使用）

#include <iostream>
#include <memory>

// 構造体の定義
struct MyStruct {
    int value;
};

// グローバルな構造体ポインタスマートポインタ変数の宣言
std::unique_ptr<MyStruct> globalStructPointer = nullptr;

// 関数の定義
void setGlobalStructPointerValue(int value) {
    // グローバルな構造体スマートポインタを使用して値を設定
    if (globalStructPointer != nullptr) {
        globalStructPointer->value = value;
    }
}

void printGlobalStructPointerValue() {
    // グローバルな構造体スマートポインタを使用して値を表示
    if (globalStructPointer != nullptr) {
        std::cout << "Global Struct Pointer Value: " << globalStructPointer->value << std::endl;
    } else {
        std::cout << "Global Struct Pointer is null." << std::endl;
    }
}

int main() {
    // スマートポインタを使用してメモリの動的確保を行い、グローバルな構造体ポインタにそのアドレスを割り当てる
    globalStructPointer = std::make_unique<MyStruct>();

    // グローバルな構造体スマートポインタを使用して値を設定および表示
    setGlobalStructPointerValue(42);
    printGlobalStructPointerValue();

    // スマートポインタがスコープを抜けるときにメモリが自動的に解放される

    return 0;
}
