#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Image
{
public:
    // Constructor
    Image(SDL_Renderer* renderer, const char* path, int x, int y, float w, float h)
        : renderer(renderer), path(path), x(x), y(y), w(w), h(h)
    {
        img = IMG_LoadTexture(renderer, path);
        if (!img) {
            // Handle error (optional)
            SDL_Log("Failed to load texture: %s, %s", path, IMG_GetError());
        }

        // Initialize texture rectangle
        texture.x = x;
        texture.y = y;
        texture.w = w;
        texture.h = h;
    }

    Image(SDL_Renderer* renderer, const char* path, int x, int y, float w, float h, SDL_Rect customRect)
        : renderer(renderer), path(path), x(x), y(y), w(w), h(h)
    {
        img = IMG_LoadTexture(renderer, path);
        if (!img) {
            // Handle error (optional)
            SDL_Log("Failed to load texture: %s, %s", path, IMG_GetError());
        }

        // Initialize texture rectangle
        customRect.x = x;
        customRect.y = y;
        customRect.w = w;
        customRect.h = h;
    }

    // Destructor to clean up the texture
    ~Image()
    {
        if (img) {
            SDL_DestroyTexture(img);
        }
    }

    SDL_Texture* getTexture()
    {
        return img;
    }

    void setX(int value)
    {
        texture.x = value;
    }

    void setY(int value)
    {
        texture.y = value;
    }

    int getY()
    {
        return texture.y;    
    }

    int getX()
    {
        return texture.x;
    }

    // Draw the image to the screen
    void drawImage() const
    {
        SDL_RenderCopy(renderer, img, nullptr, &texture);
    }

private:
    SDL_Renderer* renderer;
    SDL_Texture* img;
    SDL_Rect texture;
    const char* path;
    int x, y, w, h;
};
