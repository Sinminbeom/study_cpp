#include <iostream>

class Pet {
 public:
    Pet() {
        std::cout << "Pet()" << std::endl;
    }
    Pet(const Pet& pet) {
        std::cout << "Pet(const Pet& pet)" << std::endl;
    }

    ~Pet() {
        std::cout << "~Pet()" << std::endl;
    }

    Pet& operator=(const Pet& pet) {
        std::cout << "Pet& operator=(const Pet& pet)" << std::endl;
        return *this;
    }
};

class Player {
 public:
    Player() {
        std::cout << "Player()" << std::endl;
    }

    ~Player() {
        std::cout << "~Player()" << std::endl;
    }

    Player(const Player& player) {
        std::cout << "Player(const Player& player)" << std::endl;
        level_ = player.level_;
    }

    Player& operator=(const Player& player) {
        std::cout << "Player operator=(const Player& player)" << std::endl;
        level_ = player.level_;
        return *this;
    }

 public:
    int level_;
};

class Knight: public Player {
 public:
    Knight() {
    }

    ~Knight() {
    }

    /*
    // 복사 생성자
    Knight(const Knight& knight): Player(knight), pet_(knight.pet_) {
        std::cout << "Knight(const Knight& knight)" << std::endl;
        hp_ = knight.hp_;
    }
    */
    // 복사 대입 연산자
    Knight& operator=(const Knight& knight) {
        Player::operator=(knight);
        hp_ = knight.hp_;
        pet_ = knight.pet_;
        return *this;
    }

 public:
    int hp_;
    Pet pet_;
};

int main() {

    /**
     * 1. 복사 생성자
     *  1) 암묵적
     *      부모 클래스 복사 생성자
     *      멤버 클래스 복사 생성자
     * ex)
     * Player(const Player& player)
     * Pet(const Pet& pet)
     * 
     *  2) 명시적
     *      부모 클래스 생성자
     *      멤버 클래스 생성자
     * ex)
     * Player()
     * Pet()
     * Knight(const Knight& knight)
     * 
     * 2. 복사 대입 연산자
     *   1) 암묵적
     *      부모 클래스 복사 대입 연산자
     *      멤버 클래스 복사 대입 연산자
     *   2) 명시적
     *      아무것도 안해줌
     */

    Knight knight1;
    knight1.hp_ = 100;
    knight1.level_ = 10;

    std::cout << "================ 복사 생성자 =======================" << std::endl;

    // 복사 생성자
    Knight knight2 = knight1;

    std::cout << "================ 복사 대입 연산자 =======================" << std::endl;

    // 복사 대입 연산자
    Knight knight3;
    knight3 = knight1;

    return 0;
}