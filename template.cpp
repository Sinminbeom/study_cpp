#include <iostream>
#include <ostream>

class Knight {
 public:
    int hp_;
};

// void Print(int a) {
//     std::cout << a << std::endl;
//     std::cout << "@@@@@@@@@@@@@" << std::endl;
// }

// void Print(float a) {
//     std::cout << a << std::endl;
//     std::cout << "@@@@@@@@@@@@@" << std::endl;
// }

template<typename T>
void Print(T a) {
    std::cout << a << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Knight& k1) {
    os << k1.hp_;
    return os;
}

template<>
void Print(Knight knight) {
    std::cout << "knight !!!!!!!!!!!!" << std::endl;
}

class RandomBoxByInt {
 public:
    int GetRandomData() {
        int idx = rand() % 10;
        return data_[idx];
    }
 public:
    int data_[10];
};

template<typename T, int SIZE>
class RandomBox {
 public:
    T GetRandomData() {
        int idx = rand() % SIZE;
        return data_[idx];
    }
 public:
    T data_[SIZE];
};

template<int SIZE>
class RandomBox<double, SIZE> {
 public:
    double GetRandomData() {
        std::cout << "RandomBox<double, SIZE>" << std::endl;
        int idx = rand() % SIZE;
        return data_[idx];
    }
 public:
    double data_[SIZE];
};

int main() {
    Print(5);
    Print(5.2f);

    Knight k1;
    k1.hp_ = 100;

    Print(k1);

    srand(static_cast<unsigned int>(time(nullptr)));

    RandomBoxByInt rbbi1;

    for (int i = 0; i < 10; i++) {
        rbbi1.data_[i] = i;
    }
    int value1 = rbbi1.GetRandomData();
    std::cout << value1 << std::endl;

    RandomBoxByInt rbbi2;

    for (int i = 0; i < 10; i++) {
        rbbi2.data_[i] = i;
    }

    int value2 = rbbi2.GetRandomData();
    std::cout << value2 << std::endl;

    RandomBox<int, 10> rb1;

    for (int i = 0; i < 10; i++) {
        rb1.data_[i] = i;
    }
    int value3 = rb1.GetRandomData();
    std::cout << value3 << std::endl;

    RandomBox<float, 20> rb2;

    for (int i = 0; i < 20; i++) {
        rb2.data_[i] = i + 0.5f;
    }

    float value4 = rb2.GetRandomData();
    std::cout << value4 << std::endl;

    RandomBox<double, 30> rb3;

    for (int i = 0; i < 30; i++) {
        rb3.data_[i] = i + 0.5f;
    }

    float value5 = rb3.GetRandomData();
    std::cout << value5 << std::endl;

    return 0;
}