#pragma once
#include <SFML/Graphics.hpp>

class Enemic
{
public://Classe per l'enemic
    Enemic(float x, float y, float vx, float vy);//Enemic en si
    void update();
    sf::CircleShape getShape() const;
    bool operator==(const Enemic& other) const {//Bool que analitza la posicio acyual de l'enemic
        return shape.getPosition() == other.shape.getPosition();
    }

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;//Vector per especificar la velocitat i direccio de l'enemic
};