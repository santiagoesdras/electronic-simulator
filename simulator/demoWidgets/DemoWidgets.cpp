#include "raylib.h"
#include "../widgets/button.h"
#include "../widgets/label.h"
#include "../widgets/textfield.h"

int main() {
    InitWindow(800, 600, "Demo UI");
    SetTargetFPS(60);

    char input[64] = "";
    bool inputActive = false;
    bool clicked = false;

    while (!WindowShouldClose()) {
        Vector2 mouse = GetMousePosition();
        Rectangle inputBox = { 100, 150, 300, 40 };
        Rectangle buttonBox = { 100, 220, 120, 40 };

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            inputActive = CheckCollisionPointRec(mouse, inputBox);
            clicked = CheckCollisionPointRec(mouse, buttonBox);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        Label({ 100, 100 }, "Escribe tu nombre:");
        TextField(inputBox, input, 64, inputActive);
        if (Button(buttonBox, "Aceptar")) {
            clicked = true;
        }

        if (clicked && std::strlen(input) > 0) {
            DrawText(TextFormat("Hola, %s!", input), 100, 300, 24, DARKGREEN);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
