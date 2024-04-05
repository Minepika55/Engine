#pragma once
#include <SFML/Graphics.hpp>
#include "Jugador.h"
#include <vector>
#include "Enemic.h"
#include <sstream>
#include <SFML/Audio.hpp>


class Game
{
public:
	Game();
	void run();
private:
	void processEvents();
	void update();
	void render();
private:
	sf::RenderWindow mWindow;
	Jugador mPlayer;
	std::vector<Enemic> enemics;
	int enemicsMatats = 0;
};