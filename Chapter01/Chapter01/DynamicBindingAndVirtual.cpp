//#include <iostream>
//using namespace std;
//
//class Entity {
//public:
//	Entity()
//		: x{ 0 }, y{ 0 }
//	{
//	}
//	Entity(int x, int y)
//		: x{ x }, y{ y }
//	{
//	}
//	virtual ~Entity() {
//		cout << "Entity Destructor" << endl;
//	}
//	virtual void move(int _x, int _y) {
//		cout << "fdfd" << endl;
//		x += _x;
//		y += _y;
//	}
//	virtual void printPosition() const {
//		cout << x << ", " << y << endl;
//	}
//protected:
//	int x;
//	int y;
//};
//
//class Player : public Entity {
//public:
//	Player(int x, int y, int hp, int xp)
//		: Entity{ x, y }, hp{ hp }, xp{ xp }
//	{
//	}
//	~Player() {
//		cout << "Player Destructor" << endl;
//	}
//	virtual void move(int _x, int _y) {
//		x += _x + 1;
//		y += _y + 1;
//	}
//	virtual void printPosition() const override {
//		cout << x << ", " << y << ", " << hp << ", " << xp << endl;
//	}
//private:
//	int hp;
//	int xp;
//};
//
//int main() {
//	/*Entity entity{ 1, 1 };
//	entity.move(1, 1);
//	entity.printPosition();
//	entity.move(3, 3);
//	entity.printPosition();
//
//	Player player{1, 1, 100, 100};
//	player.move(1, 1);
//	player.printPosition();
//	player.move(3, 3);
//	player.printPosition();*/
//
//	// 소멸자에 virtual을 붙여주지 않으면 Entity 의 소멸자만 실행된다
//	// virtual을 붙여야 player 소멸자도 실행된다.
//	//Entity* entityPtr = new Player{ 1, 1, 100, 100 };
//	//entityPtr->move(2, 2);
//	//entityPtr->printPosition();
//	//delete entityPtr;
//
//	//Player player{ 1, 1, 100, 100 };
//	//Entity& entity = player;
//	//entity.move(2, 2);
//	//entity.printPosition();
//
//	Player player2{ 1, 1, 100, 100 };
//	const Entity& entity2 = player2;
//	entity2.printPosition();
//
//
//	return 0;
//}