#include <iostream>

int Add(int a, int b) {
    return a + b;
}

int Sub(int a, int b) {
    return a - b;
}

class Item {
 public:
    Item() : item_id_(0), rarity_(0), owner_id_(0) {

    }
 public:
    int item_id_; // 아이템을 구분하기 위한 ID
    int rarity_; // 희귀도
    int owner_id_; // 소지자 ID
};

// typedef bool(ITEM_SELECTOR)(Item*);

Item* FindItem(Item items[], int item_count, bool(*ITEM_SELECTOR)(Item*)) {
// Item* FindItem(Item items[], int item_count, ITEM_SELECTOR* selector) {
    for (int i = 0; i < item_count; i++) {
        Item* item = &items[i];
        if (ITEM_SELECTOR(item)) {
        // if (selector(item)) {
            return item;
        }
    }

    return nullptr;
}

Item* FindItemByRarity(Item items[], int item_count, int rarity) {
    for (int i = 0; i < item_count; i++) {
        Item* item = &items[i];
        if (item->rarity_ == rarity) {
            return item;
        }
    }

    return nullptr;
}

Item* FindItemByItemId(Item items[], int item_count, int item_id) {
    for (int i = 0; i < item_count; i++) {
        Item* item = &items[i];
        if (item->rarity_ == item_id) {
            return item;
        }
    }

    return nullptr;
}

bool IsRareItem(Item* item) {
    return item->rarity_ >= 2;
}

int main() {

    int a = 10;
    typedef int DATA;

    DATA* pointer = &a;

    // 둘다 같다
    typedef int(FUNC_TYPE)(int, int);
    using FUNC_TYPE = int(int, int);

    FUNC_TYPE* fn = nullptr;
    fn = Add;
    fn = Sub;

    int(*FUNC_TYPE2)(int, int);
    FUNC_TYPE2 = Add;
    FUNC_TYPE2(1, 2);
    int result2 = (*FUNC_TYPE2)(1,2);
    std::cout << result2 << std::endl;

    int result = fn(1,2);
    std::cout << result << std::endl;

    int result1 = (*fn)(1,2); // 함수 포인터는 *(접근 연산자) 붙어도 함수 주소!
    std::cout << result1 << std::endl;

    Item items[10] = {};
    items[3].rarity_ = 2;
    Item* rare_item = FindItem(items, 10, IsRareItem);
    std::cout << rare_item->rarity_ << std::endl;
    return 0;
}
