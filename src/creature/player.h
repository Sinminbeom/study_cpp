#pragma once

#include "creature/creature.h"
#include "game/game.h"

enum PlayerType {
    PT_Knight = 1,
    PT_Archer = 2,
    PT_Mage = 3
};

class Player: public Creature {
 public:
    Player(int player_type): Creature(CT_Player), player_type_(player_type) {

    }
    virtual ~Player() {}

    virtual void PrintInfo();
 protected:
    int player_type_;
};

class Knight : public Player {
 public:
    Knight() : Player(PT_Knight) {
        hp_ = 150;
        attack_ = 10;
        defance_ = 5;
    }
};

class Archer : public Player {
 public:
    Archer() : Player(PT_Archer) {
        hp_ = 80;
        attack_ = 15;
        defance_ = 3;
    }
};

class Mage : public Player {
 public:
    Mage() : Player(PT_Mage) {
        hp_ = 50;
        attack_ = 25;
        defance_ = 0;
    }
};