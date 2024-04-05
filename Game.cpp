#include "Game.h"
Game::Game()
	: mWindow(sf::VideoMode(1280, 960), "SFML Game Engine")
	, mPlayer()

{
	bgTexture.loadFromFile("sprites/bg.jpeg");
	bgSprite.setTexture(bgTexture);
	initEnemics();
}
void Game::run()
{
	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
}
void Game::processEvents()
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

void Game::initEnemics() {
	for (const auto& pos : enemicSpawn) {
		enemics.emplace_back(pos.x, pos.y, 0.005f, 0.005f);
	}
}

void Game::update() {
	for (auto& enemic : enemics) {
		enemic.update();
		for (const auto& projectil : mPlayer.llencarProjectils()) {
			if (enemic.getShape().getGlobalBounds().intersects(projectil.getShape().getGlobalBounds())) {
				enemicsMatats++;
				enemics.erase(std::remove(enemics.begin(), enemics.end(), enemic), enemics.end());
				break;
			}
		}
	}
	for (auto& enemic : enemics) {
		enemic.update();
		if (enemic.getShape().getGlobalBounds().intersects(mPlayer.Draw().getGlobalBounds())) {
			//mWindow.close();//Game Over
		}
	}
	mPlayer.update();
}

void Game::render()
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