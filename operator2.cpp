#include <iostream>

class Position {
 public:
    int x_;
    int y_;

 public:
    void operator=(int arg) {
        std::cout << "operator= 대입 연산자!!!!!" << std::endl;
        x_ = arg;
        y_ = arg;
    } 
};

int main() {
    Position pos5;
    pos5 = 5;
    return 0;
}