#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <paradigm_physics.h>
#include <linear_algebra.h>
#include <iostream>
#include <cstdio>
#include <entt/entt.hpp>

bool running;
const int FPS = 60;
const int frameDelay = 1000 / FPS; // 1000 ms / 60 ≈ 16.67 ms

int main(int argc, char **argv)
{
	if(!SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_CAMERA))
	{
		SDL_Log("SDL_Init failed: %s", SDL_GetError());
		return -1;
	}

	SDL_Window* window = nullptr;
	SDL_Renderer *renderer = nullptr;

	if(!SDL_CreateWindowAndRenderer("Paradigm Engine", 800, 600, 0, &window, &renderer))
	{
		SDL_Log("Window/renderer creation failed: %s", SDL_GetError());
		SDL_Quit();
		return -1;
	}

	running = true;

	while(running) //main game loop
	{
		Uint32 frameStart = SDL_GetTicks();  // start time of frame

		//----POLL----
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			//exit loop if quit event
			if(event.type == SDL_EVENT_QUIT)	
			{
				running = false;
			}
		}
	
		//----CLEAR----
		SDL_SetRenderDrawColor(renderer, 0, 0, 50, 255);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		//----PRESENT----
		SDL_RenderPresent(renderer);

		//----DELTA TIME----
 		Uint32 frameTime = SDL_GetTicks() - frameStart; //get delta time

		if (frameTime < frameDelay) 
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
