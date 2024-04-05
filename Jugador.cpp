#include "Jugador.h"
void Jugador::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Up)
		mIsMovingUp = isPressed;
	if (key == sf::Keyboard::Space && isPressed) {
		disparaProjectil(mPlayer.getPosition().x, mPlayer.getPosition().y, 0.5f, 10.f);
	}
}

void Jugador::update()
{
	sf::Vector2f movement(0.f, 0.f);
	movement.y += 0.01f;
	if (mIsMovingUp)
		movement.y -= 0.1f;
	mPlayer.move(movement);

	for (auto& projectil : projectils) {
		projectil.update();
	}
}

Jugador::Jugador() {
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Yellow);
	playerTexture.loadFromFile("sprites/player.png");
	playerSprite.setTexture(playerTexture);
}
sf::CircleShape Jugador::Draw() {
	return mPlayer;
}

void Jugador::disparaProjectil(float x, float y, float vx, float vy) {
	projectils.emplace_back(x, y, vx, vy);
}

const std::vector<Projectil>& Jugador::llencarProjectils() const {
	return projectils;
}

