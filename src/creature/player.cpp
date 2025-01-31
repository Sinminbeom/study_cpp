#include "creature/player.h"

void Player::PrintInfo() {
    std::cout << "====================================" << std::endl;
    std::cout << "[플레이어 정보] " << "HP: " << hp_ << " ATT: " << attack_ << " DEF:" << defance_ << std::endl;
    std::cout << "====================================" << std::endl;
}