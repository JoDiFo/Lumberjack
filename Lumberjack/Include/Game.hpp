#pragma once

#include "World.hpp"
#include "Player.hpp"

#include "SFML/Graphics.hpp"

class Game
{
private:
	const std::string	mName;
	sf::RenderWindow	mWindow;
	World				mWorld;
	Player				mPlayer;

public:
	Game();
	~Game();

public:
	void				run();

private:
	void				processEvents();
	void				update(sf::Time deltaTime);
	void				render();
};
