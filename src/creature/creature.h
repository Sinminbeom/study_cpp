#pragma once

enum CreatureType {
    CT_Player,
    CT_Monster
};

class Creature {
 public:
    Creature(int creature_type)
        : creature_type_(creature_type), hp_(0), attack_(0), defance_(0) {

    }
 protected:
    int hp_;
    int attack_;
    int defance_;
    int creature_type_;
};