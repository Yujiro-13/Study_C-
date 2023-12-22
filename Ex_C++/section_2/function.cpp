#include <iostream>

void HelloWorld(int n);  // 前方宣言

int main() {
    HelloWorld(10);

    return 0;
}

void HelloWorld(int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "[" << i << "] " << "Hello World!" << std::endl;
    }
}
