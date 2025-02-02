#include <iostream>

class Item {
 public:
    int item_id_ = 0;
    int rarity_ = 0;
    int owner_id_ = 0;
};

class FindByItemId {
 public:
    bool operator()(const Item* item) {
        return item_id_ == item->item_id_;
    }
 public:
    int item_id_ = 0;
};

class FindByRarity {
 public:
    bool operator()(const Item* item) {
        return item->rarity_ >= rarity_;
    }
 public:
    int rarity_ = 0;
};

template<typename T>
// Item* FindItem(Item items[], int item_count, bool(*func)(const Item*))  {
// Item* FindItem(Item items[], int item_count, FindByRarity selector)  {
Item* FindItem(Item items[], int item_count, T selector)  {
    for (int i = 0; i < item_count; i++) {
        Item* item = &items[i];
        if (selector(item))
            return item;
    }
    return nullptr;
}

int main() {
    Item items[10];
    items[3].owner_id_ = 100;
    items[8].item_id_ = 100;
    items[7].rarity_ = 3;

    FindByRarity functor1;
    functor1.rarity_ = 1;

    FindByItemId functor2;
    functor2.item_id_ = 100;    

    Item* item1 = FindItem(items, 10, functor1);
    std::cout << item1->rarity_ << std::endl;

    Item* item2 = FindItem(items, 10, functor2);
    std::cout << item2->item_id_ << std::endl;

    return 0;
}
