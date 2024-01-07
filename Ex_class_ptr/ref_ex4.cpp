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
        PA = pa;
        std::cout << "ClassA::getPoint" << std::endl;
        std::cout << "PA.x:" << PA.x << std::endl;
        std::cout << "PA.y:" << PA.y << std::endl;
    }
    void Calc_val(){
        PA.x = 100;
        PA.y = 200;
    }

private:
    Point PA;
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
};

int main()
{
    ClassA a;
    ClassB b;
    Point p{10, 20};
    std::cout << "p.x:" << p.x << std::endl;
    std::cout << "p.y:" << p.y << std::endl;
    a.getPoint(p);
    // b.getPoint(p);
    a.Calc_val();
    std::cout << "p.x:" << p.x << std::endl;
    std::cout << "p.y:" << p.y << std::endl;
    return 0;
}
