#include <iostream>

class Position {
 public:
    int x_;
    int y_;

 public:
    Position operator+(const Position& arg) {
        Position pos;
        pos.x_ = x_ + arg.x_;
        pos.y_ = y_ + arg.y_;
        return pos;
    }
};

int main() {
    Position pos1;
    pos1.x_ = 0;
    pos1.y_ = 0;
    Position pos2;
    pos2.x_ = 1;
    pos2.y_ = 1;
    Position pos3 = pos1 + pos2;
    Position pos4 = pos1.operator+(pos2);

    std::cout << pos3.x_ << " , " << pos3.y_ << std::endl;
    return 0;
}