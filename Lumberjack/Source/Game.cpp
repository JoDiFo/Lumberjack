#include "../Include/Game.hpp"

// Constructor
Game::Game()
	: mName("Lumberjack")
	, mWindow(sf::VideoMode(640, 360), mName, sf::Style::Close)
{
}

// Destructor
Game::~Game()
{
}

// Handles all events
void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

// Updating the state of the game
void Game::update(sf::Time deltaTime)
{
	//	Update all objects
}

// Render objects
void Game::render()
{
	mWindow.clear();
	// Draw objects
	mWindow.display();
}

// Main game loop
void Game::run()
{
	const auto TimePerFrame{ sf::seconds(1.f / 60.f) };
	sf::Clock clock;
	sf::Time TimeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		processEvents();
		TimeSinceLastUpdate += clock.restart();

		while (TimeSinceLastUpdate > TimePerFrame)
		{
			TimeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}