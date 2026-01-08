#include "entity.h"
#include <algorithm>
using namespace std;

Entity::Entity(string name, int hp, int atk, int def) {
    id = name;
    attack = atk;
    max_health = health = hp;
    defense = def;
}

void Entity::take_damage(int dmg) {
    health = max(0, health - dmg);
}

void Entity::heal(int hp) {
    health = min(max_health, health + hp);
}

int Entity::get_attack() {return attack;}
int Entity::get_health() {return health;}
int Entity::get_max_health() {return max_health;}
int Entity::get_defense() {return defense;}
string Entity::get_id() {return id;}