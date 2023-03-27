#pragma once

#include "SFML/Graphics.hpp"

class Game
{
private:
	const std::string	mName;
	sf::RenderWindow	mWindow;

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
