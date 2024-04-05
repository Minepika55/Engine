#include "Projectil.h"


Projectil::Projectil(float x, float y, float vx, float vy) {
    shape.setRadius(20.f);
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Red);
    velocity.x = vx;
    velocity.y = 0;
}

void Projectil::update() {
    shape.move(velocity);
}

sf::CircleShape Projectil::getShape() const {
    return shape;
}