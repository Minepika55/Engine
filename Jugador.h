#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
#include <SFML/Audio.hpp>
#include "Projectil.h"

class Jugador
{
private:
	sf::CircleShape mPlayer;//Cercle que representa al jugador
	bool mIsMovingUp = false;//Boolean per saber si el jugador es direigeix amunt
	std::vector<Projectil> projectils;//Vector dels projectils
	sf::Texture playerTexture;//Textura del jugador
	sf::Sprite playerSprite;//Sprite del jugador
public:
	Jugador();
	void update();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);//Void per els controls
	sf::CircleShape Draw();//Void per dibuixar al jugador
	void disparaProjectil(float x, float y, float vx, float vy);//Void per disparar els projectils desde el jugador
	const std::vector<Projectil>& llencarProjectils() const;//Vector que guarda els projectils que dispara el jugador
};