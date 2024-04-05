#include "Enemic.h"

Enemic::Enemic(float x, float y, float vx, float vy) {
    shape.setRadius(25.f);
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Magenta);
    velocity.x = vx;
    velocity.y = vy;
}

void Enemic::update() {
    shape.move(velocity);
}

sf::CircleShape Enemic::getShape() const {
    return shape;
}
