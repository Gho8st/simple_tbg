#ifndef ENTITY
#define ENITTY

class Entity {
    private:
        int health;
        int max_health;
        int attack;
        
    public:
        Entity(int atk, int hp);
        int get_attack();
        int get_health();

        void take_damage(int dmg);
        void heal(int hp);
};

#endif