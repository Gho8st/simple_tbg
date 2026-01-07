#include <iostream>
#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"
#include "state_manager.h"
#include "menu_state.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2 || argc > 2) {
        cout << "Invalid argument given\n";
        return 1;
    }

    int arg = stoi(argv[1]);
    bool debug;
    if (arg == 1) debug = false;
    else if (arg == 2) debug = true;
    
    const int screenWidth = 800;
    const int screenHeight = 640;
    
    InitWindow(screenWidth, screenHeight, "Hello World");
    SetTargetFPS(60);
    StateManager stateManager;
    stateManager.change_state(std::make_unique<MenuState>(stateManager, debug));
    rlImGuiSetup(true);
    
    while(!WindowShouldClose()) {
        stateManager.update();
        BeginDrawing();
        ClearBackground(RAYWHITE);

        rlImGuiBegin();
        stateManager.draw();
        rlImGuiEnd();
        EndDrawing();
    }

        CloseWindow();

    return 0;
}