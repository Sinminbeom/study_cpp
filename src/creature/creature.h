#pragma once

enum CreatureType {
    CT_Player,
    CT_Monster
};

class Creature {
 protected:
    int hp_;
    int attack_;
    int defance_;
    int creature_type_;
 public:
    Creature(int creature_type)
        : creature_type_(creature_type), hp_(0), attack_(0), defance_(0) {
    }

    virtual ~Creature() {
    }

    virtual void PrintInfo() = 0;

    void OnAttacked(Creature* attacker);
    bool IsDead() {
        return hp_ <= 0;
    }
};