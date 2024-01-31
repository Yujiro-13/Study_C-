#include <iostream>
#include <stdio.h>

int main()
{
    uint64_t num40 = 40;
    uint64_t num41 = 41;
    uint64_t num42 = 42;
    uint64_t num43 = 43;
    uint64_t num44 = 44;
    uint64_t num45 = 45;
    uint64_t num46 = 46;

    uint64_t Hexadecimal = (1ULL << num40) | (1ULL << num41) |  (1ULL << num45) |(1ULL << num42) | (1ULL << num46);

    std::cout << "Hexadecimal:" << Hexadecimal << std::endl;
    std::cout << "Hexadecimal:" << std::hex << Hexadecimal << std::endl;

    return 0;
}