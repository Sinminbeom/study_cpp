#include <iostream>

enum ItemType {
    IT_WEAPON = 0,
    IT_ARMOR = 1,
    IT_THWEAPON = 2
};

class Item {
 public:
    ItemType item_type_;

 public:
    Item() {
        std::cout << "Item()" << std::endl;
    }

    Item(ItemType item_type): item_type_(item_type) {
        std::cout << "Item(ItemType item_type)" << std::endl;
    }

    virtual ~Item() {
        std::cout << "~Item()" << std::endl;
    }
};

class Weapon: public Item {
 public:
    Weapon(): Item(IT_WEAPON) {
        std::cout << "Weapon()" << std::endl;
    }

    Weapon(ItemType item_type): Item(item_type) {
        std::cout << "Weapon()" << std::endl;
    }

    ~Weapon() {
        std::cout << "~Weapon()" << std::endl;
    }
};

class THWeapon: public Weapon {
 public:
    THWeapon(): Weapon(IT_THWEAPON) {
        std::cout << "THWeapon()" << std::endl;
    }

    ~THWeapon() {
        std::cout << "~THWeapon()" << std::endl;
    }
};

class Armor: public Item {
 public:
    Armor(): Item(IT_ARMOR) {
        std::cout << "Armor()" << std::endl;
    }
    ~Armor() {
        std::cout << "~Armor()" << std::endl;
    }
};

int main() {
    Item* inventory[20] = {};
    srand((unsigned int)time(nullptr));

    for (int i = 0; i < 20; i++) {
        int randValue = rand() % 3;
        switch (randValue) {
            case IT_WEAPON:
                inventory[i] = new Weapon();
                break;
            case IT_ARMOR:
                inventory[i] = new Armor();
                break;
            case IT_THWEAPON:
                inventory[i] = new THWeapon();
                break;
        }
    }

    for (int i = 0; i < 20; i++) {
        Item* item = inventory[i];
        if (item == nullptr)
            continue;


        if (item->item_type_ == IT_THWEAPON) {
            THWeapon* th_weapon = (THWeapon*)item;
            delete th_weapon;
        }

        // delete item;
        // if (item->item_type_ == IT_WEAPON) {
        //     Weapon* weapon = (Weapon*)item;
        //     delete weapon;
        // } else if (item->item_type_ == IT_ARMOR) {
        //     Armor* armor = (Armor*)item;
        //     delete armor;
        // }
    }
    return 0;
}