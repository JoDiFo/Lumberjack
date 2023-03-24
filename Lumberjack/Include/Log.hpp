#pragma once

#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/Graphics/Sprite.hpp>

class Log : public Entity
{
public:
	enum Type
	{
		Oak,
		Birch,
		Maple,
		Spruce,
		allTypes
	};

private:
	Type			mType;
	sf::Sprite		mSprite;

public:	
	Log(Type type, const TextureHolder& textures);

private:
	virtual void	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};

