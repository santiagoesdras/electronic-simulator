#pragma once
#include "raylib.h"

inline bool Button(Rectangle bounds, const char* label) {
    DrawRectangleRec(bounds, LIGHTGRAY);
    DrawRectangleLinesEx(bounds, 2, DARKGRAY);
    DrawText(label, bounds.x + 10, bounds.y + 10, 20, BLACK);
    return CheckCollisionPointRec(GetMousePosition(), bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}
