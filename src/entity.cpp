#include "entity.h"
#include <algorithm>
using namespace std;

Entity::Entity(int atk, int hp) {
    attack = atk;
    max_health = health = hp;
}

void Entity::take_damage(int dmg) {
    health = max(0, health - dmg);
}

void Entity::heal(int hp) {
    health = min(max_health, health + hp);
}

int Entity::get_attack() {return attack;}
int Entity::get_health() {return health;}