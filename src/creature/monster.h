#pragma once

#include <iostream>
#include "creature/creature.h"

enum MonsterType {
    MT_SLIME = 1,
    MT_ORC = 2,
    MT_SKELETON = 3
};

class Monster : public Creature {
 public:
    Monster(int monster_type) : Creature(CT_Monster), monster_type_(monster_type) {

    }

    ~Monster() {
        
    }

    virtual void PrintInfo();

 protected:
    int monster_type_;
};

class Slime : public Monster {
 public:
    Slime() : Monster(MT_SLIME) {
        hp_ = 50;
        attack_ = 5;
        defance_ = 2;
    }
};

class Orc : public Monster {
 public:
    Orc() : Monster(MT_ORC) {
        hp_ = 80;
        attack_ = 8;
        defance_ = 3;
    }
};

class Skeleton : public Monster {
 public:
    Skeleton() : Monster(MT_SKELETON) {
        hp_ = 100;
        attack_ = 15;
        defance_ = 4;
    }
};