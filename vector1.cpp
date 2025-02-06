#include <iostream>
#include <vector>

int main() {
    // 반복자(iterator) : 포인터와 유사한 개념, 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소르 이동 가능

    std::vector<int> v(10);
    
    // for (int i = 0; i < v.size(); i++) {
    for (std::vector<int>::size_type i = 0; i < v.size(); i++) {
        v[i] = i;
    }

    std::vector<int>::iterator it;
    int* ptr;

    it = v.begin();
    ptr = &v[0];

    std::cout << *it << std::endl;
    std::cout << *ptr << std::endl;

    std::cout << "===========================" << std::endl;
    // it++보다 ++it가 미세하게나마 성능이 조금 더 좋다
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << (*it) << std::endl;
    }

    int* ptrBegin = &v[0];
    int* ptrEnd = ptrBegin + 10;

    for(std::vector<int>::iterator it = v.begin(); it != v.end();) {
        int data = *it;
        if (data == 3) {
            it = v.erase(it);
        } else {
            ++it;
        }
    }

    std::cout << "===========================" << std::endl;

    for(int* ptr = ptrBegin; ptr != ptrEnd; ++ptr) {
        std::cout << *ptr << std::endl;
    }

    return 0;
}