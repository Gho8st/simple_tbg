#include "battle_state.h"
#include "menu_state.h"
#include "state_manager.h"
#include "raylib.h"
#include "raygui.h"
#include "imgui.h"

void display_debug(Entity player, Entity enemy, bool check);

BattleState::BattleState(StateManager& manager, bool debug) : manager(manager),
    player(20, 100),
    enemy(15, 100) 
{
    this->debug = debug;
}


void BattleState::update() {
    if (player.get_health() > 0 && enemy.get_health() > 0) {
        if (!ifPlayerTurn) {
            player.take_damage(enemy.get_attack());
            ifPlayerTurn = !ifPlayerTurn;
        }
    } else {
        if (player.get_health() > 0) outcome = Outcome::Player;
        else outcome = Outcome::Enemy;
    }
}

void BattleState::draw() {
    display_debug(player, enemy, debug);

    if (outcome == Outcome::None) {
        DrawText("Welcome to Battle Screen", 200, 200, 20, GRAY);
        
        DrawCircle(250, 400, 25, GREEN);
        DrawText(TextFormat("HP: %d", player.get_health()), 250, 430, 15, BLACK);
        DrawCircle(475, 400, 25, RED);
        DrawText(TextFormat("HP: %d", enemy.get_health()), 475, 430, 15, BLACK);
        
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
    } else {
        if (outcome == Outcome::Player) {
            DrawText("Player Won!!!", 200, 200, 20, GRAY);
        } else {
            DrawText("Enemy Won!!!", 200, 200, 20, GRAY);
        }

        if (GuiButton({250, 250, 100, 25}, "Return")) {
            manager.change_state(std::make_unique<MenuState>(manager, debug));
        }
    }
}

void display_debug(Entity player, Entity enemy, bool check) {
    if (check) {
        ImGui::Begin("Debug Overlay", &check);
        if (ImGui::CollapsingHeader("Game Stats")) {
            ImGui::Text("Player - HP: %d | Atk: %d", player.get_health(), player.get_attack());
            ImGui::Text("Enemy - HP: %d | Atk: %d", enemy.get_health(), enemy.get_attack());
        }

        ImGui::End();
    }
}