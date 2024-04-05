#pragma once
#include <SFML/Graphics.hpp>
class Projectil
{//Aqui tenim la calse del preojectil molt semblant a la dels enemics
public:
    Projectil(float x, float y, float vx, float vy);
    void update();
    sf::CircleShape getShape() const;

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;

};

