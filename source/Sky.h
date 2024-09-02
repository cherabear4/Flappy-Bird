#include <vector>
#include <SDL.h>
#include "Util.h"

class Sky
{
public:
	Sky(SDL_Renderer* renderer)
	{
		sky.push_back(new Image(renderer, "D:\\Public\\Me\\Flappy_Bird\\Game\\x64\\Release\\assets\\background-day.png", 0, 0, 288, 512));
		sky.push_back(new Image(renderer, "D:\\Public\\Me\\Flappy_Bird\\Game\\x64\\Release\\assets\\background-day.png", 0 + 288, 0, 288, 512));
		sky.push_back(new Image(renderer, "D:\\Public\\Me\\Flappy_Bird\\Game\\x64\\Release\\assets\\background-day.png", 288 + 288, 0, 288, 512));
	}
	void drawSky()
	{
		for (auto* skyImg : sky)
		{
			skyImg->drawImage();
		}
	}
	~Sky()
	{
		for (auto* skyImg : sky)
		{
			delete skyImg;
		}
	}
public:
	std::vector<Image*> sky;
	SDL_Renderer* renderer;
};