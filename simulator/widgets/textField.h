#pragma once
#include "raylib.h"
#include <cstring>

inline void TextField(Rectangle bounds, char* buffer, int maxLength, bool active) {
    DrawRectangleLinesEx(bounds, 2, active ? BLUE : DARKGRAY);
    DrawText(buffer, bounds.x + 5, bounds.y + 5, 20, BLACK);

    if (active) {
        int key = GetCharPressed();
        while (key > 0) {
            if ((std::strlen(buffer) < maxLength - 1) && key >= 32 && key <= 125) {
                int len = std::strlen(buffer);
                buffer[len] = (char)key;
                buffer[len + 1] = '\0';
            }
            key = GetCharPressed();
        }

        if (IsKeyPressed(KEY_BACKSPACE)) {
            int len = std::strlen(buffer);
            if (len > 0) buffer[len - 1] = '\0';
        }
    }
}
