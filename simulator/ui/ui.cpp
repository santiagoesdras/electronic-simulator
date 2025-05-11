// File interface

#include "ui.h"
#include "raylib.h"
#include "..\..\external\names.h"

void UI::init() {
    const int screentWidth = 800;
    const int screentHeight = 450;

    InitWindow(screentWidth, screentHeight, "Electronic simulator");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Desarrolladores de ElectronicLab Gt: ", 15, 15, 40, BLACK);
        int x = 20, y = 55, size = 30;
        const char** names = getNames();
        for(int i = 0; i < 3 ; i ++){
            std::string actualName = " - " + std::string(names[i]);
            DrawText(actualName.c_str(), x, y, size, BLACK);
            y += 35;
        }
        EndDrawing();
    }

    CloseWindow();
}
