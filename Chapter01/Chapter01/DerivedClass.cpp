#include <iostream>
using namespace std;



class Entity {
protected:
	int x;
	int y;
public:
	Entity(int x, int y)
		: x{ x }, y { y }
	{
	}

	void showPosition() {
		cout << "[" << x << ", " << y << "]" << endl;
	}
	
	void talk() {
		cout << "Hello." << endl;
	}
};

class Player : public Entity {
private:
	int _hp;
	int _xp;
	int _speed;
public:
	Player(int x, int y, int speed)
		: Entity{ x, y }, _speed{speed}
	{
	}

	void move(int dx, int dy) {
		x += dx;
		y += dy;
	}

	void setHP(int hp) {
		this->_hp = hp;
	}
};

int main() {
	Entity entity{ 1, 1 };
	entity.showPosition();
	entity.talk();

	Player player{ 1, 1, 100 };
	player.move(5, 5);
	player.showPosition();
	player.talk();
}