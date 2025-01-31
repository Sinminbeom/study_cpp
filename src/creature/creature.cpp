#include "creature/creature.h"

void Creature::OnAttacked(Creature* attacker) {
    int damage = attacker->attack_ - defance_;
    if (damage < 0)
        damage = 0;
    
    hp_ -= damage;
    if (hp_ < 0)
        hp_ = 0;
}