#pragma once
#include <SFML/Graphics.hpp>
#include "Jugador.h"
#include <vector>
#include "Enemic.h"
#include <sstream>
#include <SFML/Audio.hpp>


class Game
{//Aqui tenim la calsse game que guarda tot
public:
	Game();
	void run();
private:
	void processEvents();
	void update();
	void render();
	void initEnemics();
private:
	sf::RenderWindow mWindow;
	Jugador mPlayer;
	std::vector<Enemic> enemics;
	int enemicsMatats = 0;
	std::vector<sf::Vector2f> enemicSpawn = {
	sf::Vector2f(1000.f, 500.f),//Enemic1
	sf::Vector2f(1000.f, 800.f),//Enemic2
	sf::Vector2f(1000.f, 300.f)//Enemic3
	};
	sf::Texture bgTexture;//Textura del fons
	sf::Sprite bgSprite;//Sprite del fons
};