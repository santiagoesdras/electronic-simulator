// File interface

#include "ui.h"
#include "raylib.h"

void UI::init() {
    const int screentWidth = 800;
    const int screentHeight = 450;

    InitWindow(screentWidth, screentHeight, "Electronic simulator");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Simulator", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
}
