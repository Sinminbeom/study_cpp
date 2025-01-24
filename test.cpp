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

int main() {
    // explicit을 붙이지 않으면 자동적으로 형변환이 되는데 이를 막기 위해 explicit을 붙인다.
    Knight k5;
    k5 = (Knight)1; // OK
    k5 = 1; // ERROR
    return 0;
}
