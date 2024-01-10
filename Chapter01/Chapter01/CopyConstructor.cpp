//#include <iostream>
//
//using namespace std;
//
//class Player
//{
//public:
//	// delegating constructor
//	// constructor overrloading
//	Player()
//		:Player{10, 10}
//	{
//		cout << "니가 그다음이구나!!!" << endl;
//	}
//
//	Player(int _hp, int _xp)
//		: hp{ _hp }, xp{ _xp }
//	{
//		cout << "가장 먼저 생성자 호출!!!!" << endl;
//	}
//
//	//Player(const Player& other)
//	//	: hp{ other.hp }, xp { other.xp }
//	//{
//	//	cout << "복사 생성자 호출!!!!" << endl;
//	//}
//
//	void Print() {
//		cout << hp << "  " << xp << endl;
//	}
//private:
//	int hp;
//	int xp;
//};
//
//void PrintInformation(Player player) {
//	player.Print();
//}
//
//int main() {
//	Player player;
//	PrintInformation(player);
//}