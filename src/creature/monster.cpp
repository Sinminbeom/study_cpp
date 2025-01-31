#include "creature/monster.h"

void Monster::PrintInfo() {
    std::cout << "====================================" << std::endl;
    std::cout << "[몬스터 정보] " << "HP: " << hp_ << " ATT: " << attack_ << " DEF:" << defance_ << std::endl;
    std::cout << "====================================" << std::endl;
}