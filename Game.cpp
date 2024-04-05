#include "Game.h"
Game::Game()//Codi que crea la finestra del joc
	: mWindow(sf::VideoMode(1280, 960), "SFML Game Engine")
	, mPlayer()

{
	bgTexture.loadFromFile("sprites/bg.jpeg");//Codi que carrega el fons
	bgSprite.setTexture(bgTexture);
	initEnemics();//Codi que carrega els enemics
}
void Game::run()//Codi que s'executa durant el joc
{
	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}
void Game::processEvents()//Codi que controla els inputs
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			mPlayer.handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			mPlayer.handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::initEnemics() {//Codi que crea i coloca els enemics
	for (const auto& pos : enemicSpawn) {
		enemics.emplace_back(pos.x, pos.y, 0.005f, 0.005f);
	}
}

void Game::update() {//Codi que va actualitzant els enemics el jugador i les bales
	for (auto& enemic : enemics) {
		enemic.update();
		for (const auto& projectil : mPlayer.llencarProjectils()) {//Codi que controla si els enemics han xocat contra un projectil
			if (enemic.getShape().getGlobalBounds().intersects(projectil.getShape().getGlobalBounds())) {
				enemicsMatats++;//Puja el comptador
				enemics.erase(std::remove(enemics.begin(), enemics.end(), enemic), enemics.end());//Esborra l'enemic
				break;
			}
		}
	}
	for (auto& enemic : enemics) {//Codi que detecta si l'enemic ha tocat la part esquerra de la pantalla i causa un Game Over
		enemic.update();
		if (enemic.getShape().getGlobalBounds().intersects(mPlayer.Draw().getGlobalBounds())) {
			//mWindow.close();//Game Over
		}
	}
	mPlayer.update();
}

void Game::render()//Codi que renderitza tots els elements del joc
{
	mWindow.clear();
	mWindow.draw(bgSprite);
	for (const auto& enemic : enemics) {
		mWindow.draw(enemic.getShape());
	}
	mWindow.draw(mPlayer.Draw());
	for (const auto& projectil : mPlayer.llencarProjectils()) {
		mWindow.draw(projectil.getShape());
	}
	mWindow.display();
}