//#include <iostream>
//
//using namespace std;
//
//class Player
//{
//public:
//	// delegating constructor
//	// constructor overrloading
//	/*Player()
//		:Player{10, 10}
//	{
//		cout << "니가 그다음이구나!!!" << endl;
//	}*/
//
//	//Player(int _hp, int _xp)
//	//	: hp{ _hp }, xp{ _xp }
//	//{
//	//	cout << "가장 먼저 생성자 호출!!!!" << endl;
//	//}
//
//	Player(int _hp, int _xp, int* _test)
//		: hp{ _hp }, xp{ _xp }, test{ _test }
//	{
//		cout << "가장 먼저 생성자 호출!!!!" << endl;
//	}
//
//	/*Player(const Player& other)
//		: hp{ other.hp }, xp { other.xp }
//	{
//		cout << "복사 생성자 호출!!!!" << endl;
//	}*/
//
//	~Player()
//	{
//		delete test;
//	}
//
//	void Print() {
//		cout << hp << "  " << xp << " " << *test << endl;
//		//cout << hp << "  " << xp << " " << endl;
//	}
//
//	void setHP(int _hp) {
//		this->hp = _hp;
//	}
//
//private:
//	int hp;
//	int xp;
//	int* test;
//};
//
//void PrintInformation(Player player) {
//	player.Print();
//}
//
//int main() {
//	int* minbeom = new int(5);
//	Player player{ 10, 10, minbeom};
//	PrintInformation(player);
//	player.Print();
//}