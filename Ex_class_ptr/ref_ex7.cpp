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
            PA = pa; // 目標値などとして値を保持する場合は、このようにコピーを取る
            
            pa.x = 100; // 参照渡しで、参照元の値も変更したい場合は、このように引数の値を変更する
            pa.y = 200;
            std::cout << "PA.x:" << PA.x << std::endl;
            std::cout << "PA.y:" << PA.y << std::endl;
            std::cout << "pa.x:" << pa.x << std::endl;
            std::cout << "pa.y:" << pa.y << std::endl;
            std::cout << "ClassA::getPoint" << std::endl;
        }
        private:
            Point PA;
            int numA;
};

class ClassB {
    public:
        ClassB() {}
        ~ClassB() {}
        void getPoint(Point &pb) {
            PB = pb;
            std::cout << "ClassB::getPoint" << std::endl;
            std::cout << "pb.x:" << pb.x << std::endl;
            std::cout << "pb.y:" << pb.y << std::endl;
        }

    private:
        Point PB;
};

class ClassC {
    public:
        ClassC() {}
        ~ClassC() {}
        void getPoint(Point &pc) {
            /*PB.x = pb.x;
            PB.y = pb.y;*/
            PC = pc;
            std::cout << "ClassC::getPoint" << std::endl;
            std::cout << "pc.x:" << pc.x << std::endl;
            std::cout << "pc.y:" << pc.y << std::endl;
        }

    private:
        Point PC;
};

class ClassD {
    public:
        ClassD() {}
        ~ClassD() {}
        void getPoint(Point &pd) {
            /*PB.x = pb.x;
            PB.y = pb.y;*/
            PD = pd;
            std::cout << "ClassD::getPoint" << std::endl;
            std::cout << "pd.x:" << pd.x << std::endl;
            std::cout << "pd.y:" << pd.y << std::endl;
        }

    private:
        Point PD;
};

int main() {
    ClassA a;
    ClassB b;
    ClassC c;
    ClassD d;
    Point p{10, 20};
    std::cout << "p.x:" << p.x << std::endl;
    std::cout << "p.y:" << p.y << std::endl;
    a.getPoint(p);
    b.getPoint(p);
    std::cout << "p.x:" << p.x << std::endl;
    std::cout << "p.y:" << p.y << std::endl;
    return 0;
}