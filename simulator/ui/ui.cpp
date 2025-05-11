// File interface

#include "ui.h"
#include "raylib.h"
#include "names.h"

void UI::init() {
    const int screentWidth = 800;
    const int screentHeight = 450;

    InitWindow(screentWidth, screentHeight, "Electronic simulator");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        int namesCount = 0;
        int x = 190, y = 200, size = 30;
        const char** names = get_names();
        for(int i = 0; i ++ ; i < 3){
            DrawText(names[i], x, y, size, LIGHTGRAY);
            y += 40;
        }
        EndDrawing();
    }

    CloseWindow();
}
