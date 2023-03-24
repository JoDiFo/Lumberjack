#include "../Include/Log.hpp"
#include "../Include/ResourceHolder.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

Textures::ID toTextureID(Log::Type type)
{
	switch (type)
	{
	case Log::Oak:
		return Textures::Oak;
	case Log::Birch:
		return Textures::Birch;
	case Log::Maple:
		return Textures::Maple;
	case Log::Spruce:
		return Textures::Spruce;
	}

	return Textures::Oak;
}

//	Constructor
Log::Log(Type type, const TextureHolder& textures)
	: mType(type)
	, mSprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

// Draw this object
void Log::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite, states);
}