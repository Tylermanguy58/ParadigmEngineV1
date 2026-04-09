#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>
#include "./utility/linear_algebra/linear_algebra.h"

#define startingPositionX 500
#define startingPositionY 500


void InitPlayer(int player_id)
{
	//player->x = startingPositionX;
	//player->y = startingPositionY;
}

void UpdatePlayer(int player_id)
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{

		if(event.type == SDL_EVENT_KEY_DOWN)
		{
			if(event.key.key == SDLK_SPACE)
			{
				SDL_Log("Jump!");
			}
		}
	}
	
	const bool *state = SDL_GetKeyboardState(NULL); 

	//if(state[SDL_SCANCODE_W]) player->y -= 10;
	//if(state[SDL_SCANCODE_S]) player->y += 10;
	//if(state[SDL_SCANCODE_A]) player->x -= 10;
	//if(state[SDL_SCANCODE_D]) player->x += 10;
}

#endif //PLAYER_H
