#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <SFML/Audio.hpp>
#include "Projectil.h"

class Jugador
{
private:
	sf::CircleShape mPlayer;
	bool mIsMovingUp = false;
	std::vector<Projectil> projectils;
	sf::Texture playerTexture; // Textura del jugador
	sf::Sprite playerSprite; // Sprite del jugador
public:
	Jugador();
	void update();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	sf::CircleShape Draw();
	void disparaProjectil(float x, float y, float vx, float vy);
	const std::vector<Projectil>& llencarProjectils() const;
};