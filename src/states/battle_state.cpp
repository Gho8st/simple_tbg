#include "battle_state.h"
#include "state_manager.h"
#include "raylib.h"
#include "raygui.h"

BattleState::BattleState(StateManager& manager) : manager(manager),
    player(20, 100),
    enemy(15, 100) 
{

}


void BattleState::update() {
    if (!ifPlayerTurn) {
        player.take_damage(enemy.get_attack());
        ifPlayerTurn = !ifPlayerTurn;
    }
}

void BattleState::draw() {
    DrawText("Welcome to Battle Screen", 200, 200, 20, GRAY);
    DrawText(TextFormat("Player- HP: %d | ATK: %d", player.get_health(), player.get_attack()), 200, 250, 20, BLACK);
    DrawText(TextFormat("Enemy- HP: %d | ATK: %d", enemy.get_health(), enemy.get_attack()), 200, 270, 20, BLACK);

    DrawCircle(250, 400, 25, GREEN);
    DrawCircle(475, 400, 25, RED);
    
    if (ifPlayerTurn) {
        if (GuiButton({200, 300, 100, 25}, "Attack")) {
            enemy.take_damage(player.get_attack());
            ifPlayerTurn = !ifPlayerTurn;
        }
        if (GuiButton({300, 300, 100, 25}, "Heal")) {
            player.heal(20);
            ifPlayerTurn = !ifPlayerTurn;
        }
    }
}