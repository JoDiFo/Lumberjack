#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Command.hpp"

#include "SFML/Window/Event.hpp"

#include <map>

class CommandQueue;

class Player
{
public:
	enum Action
	{
		Swing,
	};

private:
	std::map<sf::Mouse::Button, Action> mKeyBinding;
	std::map<Action, Command> mActionBinding;

public:
	Player();

	void handleEvent(const sf::Event& event, CommandQueue& commands);

	void assignKey(Action action, sf::Mouse::Button button);
	sf::Mouse::Button getAssignedKey(Action action) const;

private:
	void initializeActions();
};

#endif // !PLAYER_HPP

