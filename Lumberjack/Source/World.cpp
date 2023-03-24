#include "../Include/World.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#define DEBUG 1

World::World(sf::RenderWindow& window)
	: mWindow(window)
	, mWorldView(window.getDefaultView())
	, mTextures()
	, mSceneGraph()
	, mSceneLayers()
	, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
	, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
	, mScrollSpeed(-50.f)
	, mLog(nullptr)
	, mPlayer(nullptr)
{
	loadTextures();
	buildScene();

#if (DEBUG == 1)
	std::cout << "mWorldBounds:\t" << mWorldBounds.height << 'x' << mWorldBounds.width << std::endl;
	std::cout << "mWorldView:\t" << mWorldView.getSize().x << 'x' << mWorldView.getSize().y << std::endl;
#endif

	// Prepare the view
	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
	// Move the log sidewards
	sf::Vector2f position = mLog->getPosition();
	sf::Vector2f velocity = mLog->getVelocity();

	// If the log touches borders, flip its X velocity
	if (position.x <= mWorldBounds.left + 100.f
		|| position.x >= mWorldBounds.left + mWorldBounds.width - 100.f)
	{
		velocity.x = -velocity.x;
		mLog->setVelocity(velocity);
	}

	// Apply movements
	mSceneGraph.update(dt);
}

void World::draw()
{
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

CommandQueue& World::getCommandQueue()
{
	return mCommadQueue;
}

void World::loadTextures()
{
	mTextures.load(Textures::Forest, "../Media/Images/Background.jpg");
	mTextures.load(Textures::Oak, "../Media/Images/oak.png");
	mTextures.load(Textures::Lumberjack_1, "../Media/Images/Swinging/Lumberjack1.png");
	mTextures.load(Textures::Lumberjack_2, "../Media/Images/Swinging/Lumberjack2.png");
	mTextures.load(Textures::Lumberjack_3, "../Media/Images/Swinging/Lumberjack3.png");
}

void World::buildScene()
{
	// Initialize the different layers
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();

		mSceneGraph.attachChild(std::move(layer));
	}

	// Prepare the background
	sf::Texture& texture = mTextures.get(Textures::Forest);
	sf::IntRect textureRect(mWorldBounds);
	texture.setRepeated(true);

	// Add the background sprite to the scene
	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	// Add player's sprite
	std::unique_ptr<Lumberjack> lumberjack(new Lumberjack(mTextures));
	mPlayer = lumberjack.get();
	mPlayer->setPosition(mSpawnPosition.x, mSpawnPosition.y -60.f);
	mPlayer->setScale(3.f, 3.f);
	mSceneLayers[Front]->attachChild(std::move(lumberjack));

	// Add log's sprite
	std::unique_ptr<Log> log(new Log(Log::Oak, mTextures));
	mLog = log.get();
	mLog->setPosition(mSpawnPosition);
	mLog->setVelocity(55.f);
	mLog->setScale(6.f, 6.f); // This is temporary later I will have a bigger sprite
	mSceneLayers[Front]->attachChild(std::move(log));
}