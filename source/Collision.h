#pragma once
#include "Player.h"

class Collision
{
public:
    bool checkCol(const Player& player, Image* pipe)
    {
        SDL_Rect playerRect = player.getRect();
        SDL_Rect pipeRect = { pipe->getX(), pipe->getY(), 52, 320 };
        if (checkCollision(playerRect, pipeRect)) {
            return true;
        }

        SDL_Rect rotatedPipeRect = { pipe->getX(), pipe->getY() - 320 - 160, 52, 320 };
        if (checkCollision(playerRect, rotatedPipeRect)) {
            return true;
        }

        return false;
    }

private:
    bool checkCollision(const SDL_Rect& a, const SDL_Rect& b)
    {
        if (a.x + a.w <= b.x ||
            b.x + b.w <= a.x ||
            a.y + a.h <= b.y ||
            b.y + b.h <= a.y)
        {
            return false;
        }
        return true;
    }
};