//#include <iostream>
//
//using namespace std;
//
//class Base {
//public:
//	Base()
//		: value{ 0 }
//	{
//		cout << "Base no argument" << endl;
//	}
//	Base(int value )
//		: value{ value }
//	{
//		cout << "Base one argument" << endl;
//	}
//	Base(const Base& other)
//		: value{other.value}
//	{
//		
//	}
//	~Base()
//	{
//		cout << "Base Destructor" << endl;
//	}
//private:
//	int value;
//};
//
//class Derived : public Base {
//public:
//	Derived()
//		: doubleValue{ 0 }
//	{
//		cout << "Derived no argument" << endl;
//	}
//	Derived(int doubleValue)
//		: Base{ doubleValue }, doubleValue{ doubleValue * 2 }
//	{
//		cout << "Derived one argument" << endl;
//	}
//	Derived(const Derived& other)
//		: Base{ other }, doubleValue { other.doubleValue }
//	{
//	}
//	~Derived()
//	{
//		cout << "Derived Destructor" << endl;
//	}
//private:
//	int doubleValue;
//};
//
//int main() {
//	//Base a;
//	//Base b{ 1 };
//	//Derived c;
//	//Derived d{ 1 };
//	Derived e1{ 100 };
//	Derived e2{ e1 };
//	return 0;
//}