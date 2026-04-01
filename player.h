#ifndef PLAYER_H
#define PLAYER_H

#include <SDL3/SDL.h>

#define startingPositionX 500
#define startingPositionY 500

struct Player 
{
	int x;
	int y;
};

void InitPlayer(struct Player *player)
{
	player->x = startingPositionX;
	player->y = startingPositionY;
}

void UpdatePlayer(struct Player *player)
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

	if(state[SDL_SCANCODE_W]) player->y -= 10;
	if(state[SDL_SCANCODE_S]) player->y += 10;
	if(state[SDL_SCANCODE_A]) player->x -= 10;
	if(state[SDL_SCANCODE_D]) player->x += 10;
}

#endif //PLAYER_H
