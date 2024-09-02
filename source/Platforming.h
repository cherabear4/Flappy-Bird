#include <vector>
#include <SDL.h>
#include "Util.h"

class Platforming
{
public:
	Platforming(SDL_Renderer* renderer) : renderer(renderer)
	{
		platforms.push_back(new Image(renderer, "D:\\Public\\Me\\Flappy_Bird\\Game\\x64\\Release\\assets\\base.png", 1136, 500, 336, 112));
		platforms.push_back(new Image(renderer, "D:\\Public\\Me\\Flappy_Bird\\Game\\x64\\Release\\assets\\base.png", 800, 500, 336, 112));
		platforms.push_back(new Image(renderer, "D:\\Public\\Me\\Flappy_Bird\\Game\\x64\\Release\\assets\\base.png", 464, 500, 336, 112));
		platforms.push_back(new Image(renderer, "D:\\Public\\Me\\Flappy_Bird\\Game\\x64\\Release\\assets\\base.png", 128, 500, 336, 112));
		platforms.push_back(new Image(renderer, "D:\\Public\\Me\\Flappy_Bird\\Game\\x64\\Release\\assets\\base.png", -208, 500, 336, 112));
	}

	void updatePlatforms()
	{
		for (auto* platform : platforms)
		{
			int newX = platform->getX() - 2;
			if (newX < -336) {
				newX = 1136;
			}
			platform->setX(newX);
		}
	}

	void drawPlatforms()
	{
		for (const auto* platform : platforms)
		{
			platform->drawImage();
		}
	}

	~Platforming()
	{
		for (auto* platform : platforms)
		{
			delete platform;
		}
	}
public:
	std::vector<Image*> platforms;
	SDL_Renderer* renderer;
};