#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include "Platforming.h"
#include "Pipes.h"
#include "Sky.h"
#include "Player.h"
#include "Collision.h"
#include "Logic.h"

int main(int argc, char* argv[])
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Flappy Bird", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Logic logic;

    bool running = true;
    SDL_Event event;
    Player player(renderer, 100, 100, 34 * 1.5, 24 * 1.5); //init player

    Pipes pipe(renderer);
    pipe.createPipes(renderer, 852); //create pipes

    Platforming platform(renderer); //create platform

    Sky sky(renderer); //render sky

    Collision col; //enable collision

    while (running)
    {

        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_SPACE) {
                    if (logic.isGameRunning())
                    {
                        player.jump();
                    }
                    else
                    {
                        logic.setGameRunning(true);
                    }
                }
            }
        }

        if(logic.isGameRunning())
        {
            player.update();
            pipe.updatePipes();
            platform.updatePlatforms();
        }

        if (player.getOnGround())
        {
            logic.setGameRunning(false);
        }

        for (auto* _pipe : pipe.pipes)
        {
            if (col.checkCol(player, _pipe))
            {
                logic.setGameRunning(false);
                player.setX(100);
                player.setY(100);
                pipe.pipes.clear();
                pipe.createPipes(renderer, 852);
            }
        }

        if (player.getOnGround())
        {
            logic.setGameRunning(false);
            player.setX(100);
            player.setY(100);
            player.setOnGround(false);
            pipe.pipes.clear();
            pipe.createPipes(renderer, 852);
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        player.getSetPos();

        sky.drawSky();
        player.drawPlayer();
        platform.drawPlatforms();
        pipe.drawPipes();

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}