#include <iostream>

#include <iostream>

typedef struct
{
    int x;
    int y;
} Point;

class ClassA
{
public:
    ClassA() {}
    ~ClassA() {}
    void getPoint(Point &pa)
    {
        /*PA.x = pa.x;
        PA.y = pa.y;*/
        PA = pa; // 目標値などとして値を保持する場合は、このようにコピーを取る
        for (uint8_t i = 0; i < 10; i++)
        {
            pa.x++; // 参照渡しで、参照元の値も変更したい場合は、このように引数の値を変更する
            pa.y++;
            std::cout << "PA.x:" << PA.x << std::endl;
            std::cout << "PA.y:" << PA.y << std::endl;
            std::cout << "pa.x:" << pa.x << std::endl;
            std::cout << "pa.y:" << pa.y << std::endl;
        }
        std::cout << "ClassA::getPoint" << std::endl;
    }
    void Calc_val()
    {
        PA.x = 100;
        PA.y = 200;
    }

private:
    Point PA;
    int numA;
};

class ClassB
{
public:
    ClassB() {}
    ~ClassB() {}
    void getPoint(Point &pb)
    {
        /*PB.x = pb.x;
        PB.y = pb.y;*/
        PB = pb;
        std::cout << "ClassB::getPoint" << std::endl;
        std::cout << "pb.x:" << pb.x << std::endl;
        std::cout << "pb.y:" << pb.y << std::endl;
    }

private:
    Point PB;
    int numB;
};

class ClassC
{
public:
    ClassC() {}
    ~ClassC() {}
    void getPoint(Point &pc)
    {
        PC = pc;
        std::cout << "ClassC::getPoint" << std::endl;
        std::cout << "pc.x:" << pc.x << std::endl;
        std::cout << "pc.y:" << pc.y << std::endl;
    }

private:
    ClassA CA;
    ClassB CB;
    Point PC;
    int numC;
};

Point p{10, 20};
int main()
{
    ClassA a;
    ClassB b;

    std::cout << "p.x:" << p.x << std::endl;
    std::cout << "p.y:" << p.y << std::endl;
    a.getPoint(p);
    // b.getPoint(p);
    // a.Calc_val();
    std::cout << "p.x:" << p.x << std::endl;
    std::cout << "p.y:" << p.y << std::endl;
    return 0;
}
