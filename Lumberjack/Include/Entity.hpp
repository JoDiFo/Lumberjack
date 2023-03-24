#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "SceneNode.hpp"

class Entity : public SceneNode
{
public:
	// Public and access functions
	void				setVelocity(sf::Vector2f velocity);
	void				setVelocity(float vx = 0.0f, float vy = 0.0f);
	sf::Vector2f		getVelocity() const;

private:
	// Private functions
	virtual void		updateCurrent(sf::Time dt);

private:
	// Private members
	sf::Vector2f		mVelocity;
};

#endif // ENTITY_HPP