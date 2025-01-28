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
};

class Knight {
 public:
    Knight() {
        pet_ = new Pet();
    }

    ~Knight() {
        delete pet_;
    }

    // 복사 생성자
    Knight(const Knight& knight) {
        hp_ = knight.hp_;
        pet_ = new Pet(*knight.pet_);
    }

    // 복사 대입 연산자
    Knight& operator=(const Knight& knight) {
        hp_ = knight.hp_;
        pet_ = new Pet(*knight.pet_);
        return *this;
    }
 public:
    int hp_;
    Pet* pet_;
};

int main() {
    // 생성자와 복사 생성자와 복사 대입 연산자는 꼭 정의를 해줘야한다.

    Knight knight1;
    knight1.hp_ = 100;

    std::cout << &knight1.pet_ << std::endl;

    // 복사 생성자
    // Knight knight2 = knight1;
    // std::cout << &knight2.pet_ << std::endl;

    // 복사 대입 연산자
    Knight knight3;
    knight3 = knight1;
    std::cout << &knight3.pet_ << std::endl;
    return 0;
}