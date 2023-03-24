#include "../Include/Game.hpp"

// Constructor
Game::Game()
	: mName("Lumberjack")
	, mWindow(sf::VideoMode(640, 360), mName, sf::Style::Close)
	, mWorld(mWindow)
{
}

// Destructor
Game::~Game()
{
}

// Handles all events
void Game::processEvents()
{
	CommandQueue& commands = mWorld.getCommandQueue();

	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		mPlayer.handleEvent(event, commands);

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
	mWorld.update(deltaTime);
}

// Render objects
void Game::render()
{
	mWindow.clear();
	mWorld.draw();
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