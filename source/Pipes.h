#include <vector>
#include <SDL.h>
#include "Util.h"

class Pipes
{
public:
    Pipes(SDL_Renderer* renderer) 
        : renderer(renderer)
    {}

    int pickRandomYValue()
    {
        int minY = 370;
        int maxY = 450;
        int randomY = minY + (std::rand() % (maxY - minY + 1));
        return randomY;
    }

    void createPipes(SDL_Renderer* renderer, int startX)
    {
        int spacing = 300;
        for (int i = 0; i < 3; ++i)
        {
            int y = pickRandomYValue();
            pipes.push_back(new Image(renderer, "D:\\Public\\Me\\Flappy_Bird\\Game\\x64\\Release\\assets\\pipe-green.png", startX + i * spacing, y, 52, 320));
        }
    }

    void updatePipes()
    {
        int pipeCount = pipes.size();

        for (int i = 0; i < pipeCount; ++i)
        {
            auto* pipe = pipes[i];
            int newX = pipe->getX() - 2;

            if (newX < -52)
            {
                int lastPipeX = pipes[(i + pipeCount - 1) % pipeCount]->getX();
                newX = lastPipeX + pipeSpacing;
                pipe->setY(pickRandomYValue());
            }

            pipe->setX(newX);
        }
    }

    void drawPipes()
    {
        for (auto* pipe : pipes)
        {
            pipe->drawImage();
            SDL_Rect rotPipe{ pipe->getX(), pipe->getY() - 160 - 320, 52, 320 };
            SDL_RenderCopyEx(renderer, pipe->getTexture(), nullptr, &rotPipe, 180, nullptr, SDL_FLIP_NONE);
        }
    }

    ~Pipes()
    {
        for (const auto* pipe : pipes)
        {
            delete pipe;
        }
    }

public:
    std::vector<Image*> pipes;
    SDL_Renderer* renderer;
    const int pipeSpacing = 300;
};