#include <iostream>

using namespace std;
class Array {
public:
	Array(int value, int size)
		: size{ size }
	{
		ptr = new int[size];
		for (int i = 0; i < size; i++) {
			ptr[i] = value + i;
		}
	}
	~Array()
	{
		delete[] ptr;
	}
	int GetSize() const {
		return size;
	}
	int GetValue(int index) const {
		if (index < size && index >= 0)
			return ptr[index];
	}
	Array& operator=(const Array& rhs) {
		int minbeom = 3;
		int& test = minbeom;
		Array& test1 = *this;
		if (this == &rhs) {
			return *this;
		}
		delete[] ptr;
		size = rhs.size;
		ptr = new int[size];
		for (int i = 0; i < size; i++) {
			ptr[i] = rhs.ptr[i];
		}
		return *this;
	}
private:
	int* ptr;
	int size;
};

int main() {
	Array array1{ 5, 10 };
	Array array2{ 3, 5 };
	array2 = array1;
	cout << &array1 << endl;
	cout << &array2 << endl;

	return 0;
}