// Copyright [2025] <mbshin>

#include <iostream>

class Knight {
 private:
    int hp_;
    int attack_;
    int posX_;
    int posY_;

 public:
    Knight() {}

    explicit Knight(int hp) {
        hp_ = hp;
        attack_ = 10;
        posX_ = 0;
        posY_ = 0;
    }
};

// int main() {
//     Knight k5;
//     k5 = (Knight)1;
//     return 0;
// }
