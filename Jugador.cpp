#include "Jugador.h"
void Jugador::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)//Void que executa els inputs del jugador
{
	if (key == sf::Keyboard::Up)//Void que controla els salts
		mIsMovingUp = isPressed;
	if (key == sf::Keyboard::Space && isPressed) {//Void que controla els dispars
		disparaProjectil(mPlayer.getPosition().x, mPlayer.getPosition().y, 0.5f, 10.f);
	}
}

void Jugador::update()//Void que actualitza el moviment i projectils del jugador
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

Jugador::Jugador() {//Void que crea el jugador a l'escena
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Yellow);
	playerTexture.loadFromFile("sprites/player.png");
	playerSprite.setTexture(playerTexture);
}
sf::CircleShape Jugador::Draw() {//Void que dibuixa el cercle del jugador
	return mPlayer;
}

void Jugador::disparaProjectil(float x, float y, float vx, float vy) {//Void que crea el projectil
	projectils.emplace_back(x, y, vx, vy);
}

const std::vector<Projectil>& Jugador::llencarProjectils() const {//Void que llenca el projectil
	return projectils;
}

