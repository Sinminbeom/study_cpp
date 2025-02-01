#include <iostream>

class Knight {
 public:
    int GetHP(int, int) {
        std::cout << "GetHP()" << std::endl;
        return 0;
    }
};

void HelloWorld() {
    std::cout << "Hello World" << std::endl;
}

typedef int(Knight::*PMEMFUNC)(int, int);

class Functor {
 public:
    void operator()() {
        std::cout << "Functor TEST" << std::endl;
        std::cout << value_ << std::endl;
    }

 public:
    int value_ = 0;
};

class MoveTask {
 public:
    void operator()() {
        std::cout << "해당 좌표로 플레이어 이동" << std::endl;
    }
 public:
    int player_id_;
    int pos_x_;
    int pos_y_;
};

int main() {
    Knight k1;

    PMEMFUNC fn;
    fn = &Knight::GetHP;
    int result = (k1.*fn)(1, 2);

    Knight* k2 = new Knight();
    // int result1 = k1->*fn(1,2);
    int result2 = (k2->*fn)(1,2);

    void (*FUNC)(void);
    FUNC = &HelloWorld;
    FUNC();

    typedef void(*FUNCTEST)(void);
    FUNCTEST functest;
    functest = &HelloWorld;
    functest();

    /**
     * 함수 포인터의 단점
     * 1) 시그니처가 안맞으면 사용할 수 없다.
     * 2) 상태를 가질 수 없다.
     */

    Functor functor;
    functor();

    MoveTask task;
    task.player_id_ = 100;
    task.pos_x_ = 5;
    task.pos_y_ = 0;

    task();

    return 0;
}