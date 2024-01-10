#include <iostream>

using namespace std;

class Player {
public:
	Player(int x, int y)
		:x { x }, y { y }
	{
	}
	void SetPosition(int x, int y) {
		this->x = x;
		this->y = y;
	}
	// const로 클래스 인스턴스를 만들면 값을 바꾸지 않는 함수도 쓰지 못한다
	// const object를 선언해야한다.
	void PrintPosition() const {
		cout << x << ", " << y << endl;
	}
private:
	int x;
	int y;
};

int main() {
	Player player{ 0, 0 };
	player.SetPosition(10, 10);
	player.PrintPosition();

	const Player player1{ 0, 0 };
	//player1.SetPosition(10, 19);
	player1.PrintPosition();
	return 0;
}