#include <iostream>
using namespace std;

struct Entity {
    int health;
    int attack;
};
void display(Entity, bool);

int main() {
    Entity player{100, 20}, enemy{90, 10};
    bool ifPlayerTurn = true;
    cout << "Welcome to the Simple Turn Based game.\n";
    
    while (player.health > 0 && enemy.health > 0) {
        display(player, true);
        display(enemy, false);
        if (ifPlayerTurn) {
            cout << "Choose ur move\n";
            cout << "1. Attack\n2. Heal\n";
            
            int move = 0;
            do {
                cin >> move;
            } while (move <= 0 || move > 2);
            
            if (move == 1) enemy.health -= player.attack;
            else player.health += 10;
        } else {
            cout << "Enemy attacks you\n";
            player.health -= enemy.attack;
        }

        ifPlayerTurn = !ifPlayerTurn;
    }

    if (player.health > 0) cout << "Player won\n";
    else cout << "Player lost\n";
    return 0;
}

void display(Entity e1,bool player) {
    string str1 = (player) ? "Player: HP: ": "Enemy: HP: ";
    str1.append(to_string(e1.health));
    str1.append("| ATK: ");
    str1.append(to_string(e1.attack));
    str1.append("\n");
    cout << str1.c_str();
}