#include <iostream>
#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc < 2 || argc > 2) {
        cout << "Invalid argument given\n";
        return 1;
    }

    int arg = stoi(argv[1]);
    
    if (arg == 1) {
        const int screenWidth = 800;
        const int screenHeight = 640;

        InitWindow(screenWidth, screenHeight, "Hello World");
        SetTargetFPS(60);

        rlImGuiSetup(true);

        bool showImGuiWindow = true;
        float raygui_slider_value = 0.5f;
        
        while(!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hello World", 190, 200, 20, LIGHTGRAY);

            if(GuiButton({300, 300, 200, 40}, "Button")) {
                TraceLog(LOG_INFO, "Button has been pressed!");
            }

            GuiSlider({300, 350, 200, 20}, "Slider", TextFormat("%0.2f", raygui_slider_value), &raygui_slider_value, 0.0f, 1.0f);

            rlImGuiBegin();
            if(showImGuiWindow) {
                ImGui::Begin("ImGui Window", &showImGuiWindow);
                ImGui::Text("Hello Window!");
                if (ImGui::Button("Button")) {
                    TraceLog(LOG_INFO, "ImGui Button has been pressed!");
                }
                ImGui::End();
            }
            rlImGuiEnd();
            EndDrawing();
        }

        rlImGuiShutdown();
        CloseWindow();
    }

    return 0;
}