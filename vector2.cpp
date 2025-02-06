#include <iostream>

template<typename T>
class Iterator {
 public:
    T* ptr_;
};

template<typename T>
class Vector {
 public:
    Vector() : data_(nullptr), size_(0), capacity_(0) {

    }
    ~Vector() {
        if (data_)
            delete[] data_;
    }

    void push_back(const T& val) {
        if (size_ == capacity_) {
            int new_capacity = static_cast<int>(capacity_ * 1.5);

            if (new_capacity == capacity_) {
                new_capacity++;
            }

            reserve(new_capacity);
        }

        data_[size_] = val;

        size_++;
    }

    void reserve(int capacity) {
        capacity_ = capacity;

        T* new_data = new T[capacity];

        for (int i = 0; i < size_; i ++) {
            new_data[i] = data_[i];
        }

        if (data_)
            delete[] data_;

        data_ = new_data;
    }

    T& operator[](int index) {
        return data_[index];
    }

    int size() { return size_; }
    int capacity() { return capacity_; }


 private:
    T* data_;
    int size_;
    int capacity_;
};

int main() {
    Vector<int> v;
    v.reserve(100);
    for (int i = 0; i < 100; i++) {
        v.push_back(i);
        std::cout << v.size() << " " << v.capacity() << std::endl;
    }

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }
    return 0;
}