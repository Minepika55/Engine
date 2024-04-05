#pragma once
#include <SFML/Graphics.hpp>

class Enemic
{
public:
    Enemic(float x, float y, float vx, float vy);
    void update();
    sf::CircleShape getShape() const;
    bool operator==(const Enemic& other) const {
        return shape.getPosition() == other.shape.getPosition();
    }

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
};