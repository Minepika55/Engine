#include "Enemic.h"

Enemic::Enemic(float x, float y, float vx, float vy) {//L'enemic amb el seu tamany i velocitats
    shape.setRadius(25.f);
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Magenta);
    velocity.x = vx;
    velocity.y = vy;
}

void Enemic::update() {//Aquest void fa que l'enemic es mogui a una velocitat constant
    shape.move(velocity);
}

sf::CircleShape Enemic::getShape() const {//Aquest void crea l'esfera que representa a l'enemic
    return shape;
}
