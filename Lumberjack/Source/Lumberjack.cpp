#include "../Include/Lumberjack.hpp"
#include "../Include/ResourceHolder.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

Textures::ID toTextureID(Lumberjack::Type type)
{
	switch (type)
	{
	case Lumberjack::frame_1:
		return Textures::Lumberjack_1;
	case Lumberjack::frame_2:
		return Textures::Lumberjack_2;
	case Lumberjack::frame_3:
		return Textures::Lumberjack_3;
	}

	return Textures::Lumberjack_1;
}

// Constructor
Lumberjack::Lumberjack(const TextureHolder& texture)
	: mType(frame_1)
	, mSprite(texture.get(toTextureID(frame_1)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

// Draw this object
void Lumberjack::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}

void Lumberjack::animate()
{

}