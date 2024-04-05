#include "Projectil.h"


Projectil::Projectil(float x, float y, float vx, float vy) {//Projectil en si amb el seu tamany i velocitat
    shape.setRadius(20.f);
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Red);
    velocity.x = vx;
    velocity.y = 0;
}

void Projectil::update() {//Aquest void fa que el projectil es mogui a una velocitat constant
    shape.move(velocity);
}

sf::CircleShape Projectil::getShape() const {//Aquest void crea l'esfera que representa a cada projectil
    return shape;
}