#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <stdio.h>

bool running;
const int FPS = 60;
const int frameDelay = 1000 / FPS; // 1000 ms / 60 ≈ 16.67 ms

int main(int argc, char** argv)
{
	if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_CAMERA)) running = true;

	while(running)
	{
		Uint32 frameStart = SDL_GetTicks();  // start time of frame

 		Uint32 frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < frameDelay) {
            SDL_Delay(frameDelay - frameTime);
			printf("hi");
        }
	}

	SDL_Quit();
}

void end_game()
{
	running = false;
}
