#ifndef ENTITY
#define ENITTY

#include <string>

class Entity {
    private:
        int health;
        int max_health;
        int attack;
        int defense;

        std::string id;
        
    public:
        Entity(std::string id, int hp, int atk, int def);

        int get_attack();
        int get_health();
        int get_max_health();
        int get_defense();
        std::string get_id();

        void take_damage(int dmg);
        void heal(int hp);
};

#endif