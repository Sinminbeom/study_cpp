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
};

int main() {
    Knight k1;
    Knight k2(k1);
    Knight k3 = k1;
    return 0;
}