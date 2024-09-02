#pragma once
#include <vector>
#include <SDL.h>
#include "Util.h"

class Player
{
public:
    Player(SDL_Renderer* renderer, int x, float y, float w, float h)
        : renderer(renderer), x(x), y(y), w(w), h(h), velocityY(0), onGround(false)
    {
        
    }

    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return w; }
    int getHeight() const { return h; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setWidth(int w) { this->w = w; }
    void setHeight(int h) { this->h = h; }

    void jump()
    {
        velocityY = -12;
        if (onGround)
        {
            onGround = false;
        }
    }

    bool getOnGround()
    {
        return onGround;
    }

    void applyGravity()
    {
        velocityY += gravity;
        y += velocityY;

        if (y >= groundLevel)
        {
            y = groundLevel;
            velocityY = 0;
            onGround = true;
        }
    }

    void update()
    {
        applyGravity();
    }

    void setOnGround(bool val)
    {
        onGround = val;
    }

    SDL_Rect getRect() const
    {
        return { x, y, w, h };
    }

    void getSetPos()
    {
        SDL_Rect playerRect = getRect();
        setX(x);
        setY(y);
    }

    void drawPlayer()
    {
        playerSprite->setX(x);
        playerSprite->setY(y);
        playerSprite->drawImage();
    }

private:
    SDL_Renderer* renderer;
    Image* playerSprite = new Image(renderer, "D:\\Public\\Me\\Flappy_Bird\\Game\\x64\\Release\\assets\\yellowbird-midflap.png", this->getX(), this->getY(), 34 * 1.5, 24 * 1.5);
    int x, y, w, h;
    int velocityY;
    bool onGround;
    const int groundLevel = 455;
    const int gravity = 1;
};