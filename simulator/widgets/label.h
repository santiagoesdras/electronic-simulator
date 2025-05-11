#pragma once
#include "raylib.h"

inline void Label(Vector2 pos, const char* text, int fontSize = 20, Color color = DARKGRAY) {
    DrawText(text, pos.x, pos.y, fontSize, color);
}
