#include <iostream>

#include <iostream>

typedef struct {
    int x;
    int y;
} Point;

class ClassA {
public:
    ClassA() {}
    ~ClassA() {}
    void getPoint(Point &pa) {
        pa.x = 100;
        pa.y = 200;
        std::cout << "ClassA::getPoint" << std::endl;
        std::cout << "pa.x:" << pa.x << std::endl;
        std::cout << "pa.y:" << pa.y << std::endl;
    }
};

class ClassB {
public:
    ClassB() {}
    ~ClassB() {}
    void getPoint(Point &pb) {
        pb.x = 1000;
        pb.y = 2000;
        std::cout << "ClassB::getPoint" << std::endl;
        std::cout << "pb.x:" << pb.x << std::endl;
        std::cout << "pb.y:" << pb.y << std::endl;
    }
};

int main() {
    ClassA a;
    ClassB b;
    Point p{10, 20};
    std::cout << "p.x:" << p.x << std::endl;
    std::cout << "p.y:" << p.y << std::endl;
    a.getPoint(p);
    //b.getPoint(p);
    std::cout << "p.x:" << p.x << std::endl;
    std::cout << "p.y:" << p.y << std::endl;
    return 0;
}
