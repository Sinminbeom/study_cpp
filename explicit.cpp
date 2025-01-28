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

    Knight(const Knight& knight) {
        std::cout << "Knight 복사 생성자" << std::endl;
        hp_ = knight.hp_;
        attack_ = knight.attack_;
        posX_ = knight.posX_;
        posY_ = knight.posY_;
    }

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
    // k5 = 1; // ERROR

    Knight k1;
    Knight k2(k1);
    Knight k3 = k1;
    return 0;
}
