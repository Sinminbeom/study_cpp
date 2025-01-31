#include "game/field.h"
#include "creature/monster.h"
#include "creature/player.h"
// #include <stdlib.h>

Field::Field() : monster_(nullptr) {
}

Field::~Field() {
    if (monster_ != nullptr)
        delete monster_;
}

void Field::Update(Player* player) {
    if (monster_ == nullptr) {
       CreateMonster();
    }

    StartBattle(player);
}

void Field::CreateMonster() {
    int randValue = 1 + rand() % 3;

    switch(randValue) {
        case MT_SLIME:
            monster_ = new Slime();
            break;
        case MT_ORC:
            monster_ = new Orc();
            break;
        case MT_SKELETON:
            monster_ = new Skeleton();
            break;
    }
}

void Field::StartBattle(Player* player) {
    while(true) {
        player->PrintInfo();
        monster_->PrintInfo();

        // 플레이어->몬스터 공격
        monster_->OnAttacked(player);

        if (monster_->IsDead()) {
            monster_->PrintInfo();
            delete monster_;
            monster_ = nullptr;
            break;
        }

        // 몬스터->플레리어 공격격
        player->OnAttacked(monster_);

        if (player->IsDead()) {
            player->PrintInfo();
            break;
        }
    }
}