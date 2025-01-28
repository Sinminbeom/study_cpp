#include <iostream>

class Position {
 public:
    int x_;
    int y_;

 public:
    // Position& operator=(const Position& arg) {
    //     std::cout << "복새 대입 연산자!!!!!" << std::endl;
    //     x_ = arg.x_;
    //     y_ = arg.y_;
    //     return *this;
    // }
};

int main() {
    Position pos5;
    pos5.x_ = 5;
    pos5.y_ = 5;

    Position pos6;
    pos6 = pos5;

    std::cout << pos6.x_ << " : " << pos6.y_ << std::endl;
    return 0;
}
