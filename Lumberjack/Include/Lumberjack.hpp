#ifndef LUMBERJACK_HPP
#define LUMBERJACK_HPP

#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"

#include "SFML/Graphics/Sprite.hpp"


class Lumberjack : public Entity
{
public:
	enum Type
	{
		frame_1,
		frame_2,
		frame_3,
		allTypes,
	};

private:
	Type		mType;
	sf::Sprite	mSprite;

public:
	Lumberjack(const TextureHolder& texture);
	void			animate();

private:
	virtual void	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

};


#endif // !LUMBERJACK_HPP