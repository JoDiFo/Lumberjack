#include "../Include/Player.hpp"
#include "../Include/CommandQueue.hpp"
#include "../Include/Lumberjack.hpp"

#include <string>
#include <algorithm>

struct AnimateLumberjack
{
	AnimateLumberjack(float x, float y)
	{
	}

	void operator() (Lumberjack& lumberjack, sf::Time) const
	{
		lumberjack.animate();
	}

};

Player::Player()
{
	mKeyBinding[sf::Mouse::Left] = Swing;

	// Initialize default actions
	initializeActions();

	for (auto& pair : mActionBinding)
		pair.second.category = Category::Player;
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		auto found = mKeyBinding.find(event.mouseButton.button);
		if (found != mKeyBinding.end())
			commands.push(mActionBinding[found->second]);
	}
}

void Player::assignKey(Action action, sf::Mouse::Button button)
{
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	mKeyBinding[button] = action;
}

sf::Mouse::Button Player::getAssignedKey(Action action) const
{
	for (auto pair : mKeyBinding)
	{
		if (pair.second == action)
			return pair.first;
	}

	return sf::Mouse::ButtonCount;
}

void Player::initializeActions()
{
	mActionBinding[Swing].action = derivedAction<Lumberjack>(AnimateLumberjack(0.f, 0.f));
}