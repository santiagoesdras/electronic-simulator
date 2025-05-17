#pragma once
#include  <iostream>
#include "raylib.h"

enum class ButtonShape{
    Rectangle,
    Rounded,
    Circle,
    Triangle,
    Polygon
};

class Button{
    private:
        std::string buttonName = "";
        std::string labelText = "";
        int width = 0;
        int heigth = 0;
        int coordX = 0;
        int coordY = 0;
        Color shapeColor {};
        ButtonShape shape = ButtonShape::Rounded;
    public:
        Button(std::string btnName, std::string txtLabel, int w, int h, Color color, ButtonShape s, int x, int y): 
            buttonName(btnName), labelText(txtLabel), width(w), heigth(h), coordX(x - (width/2)), coordY(y - (heigth/2)), shapeColor(color), shape(s){}
};