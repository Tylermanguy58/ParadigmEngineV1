#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <paradigm_physics.h>
#include <linear_algebra.h>
#include <cstdio>

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

	Mat3 matrix;
	mat3_identity(&matrix);
	PhysicsContext* ctx = physics_init(40);


	while(running)
	{
		Uint32 frameStart = SDL_GetTicks();  // start time of frame

		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_EVENT_QUIT)	
			{
				running = false;
			}
		}
	
		char buffer[256];	
		mat3_to_string(&matrix, buffer, sizeof(buffer));	
		
		SDL_Log("Matrix:\n%s", buffer);

		//ctx->force_x_array[39] = 20;
	
		//update_physics(ctx, 1.0f/60.0f);

		/*for(int i = 0; i < ctx->count; i++)
		{
			snprintf(buffer, sizeof(buffer), "Entity %i:\n", i);
			SDL_Log("%s", buffer);

			snprintf(buffer, sizeof(buffer), "\tX: %f\n", ctx->x_array[i]);
			SDL_Log("%s", buffer);
			
			snprintf(buffer, sizeof(buffer), "\tY: %f\n", ctx->y_array[i]);
			SDL_Log("%s", buffer);
			
			snprintf(buffer, sizeof(buffer), "\tVX: %f\n", ctx->velocity_x_array[i]);
			SDL_Log("%s", buffer);
			
			snprintf(buffer, sizeof(buffer), "\tVY: %f\n", ctx->velocity_y_array[i]);
			SDL_Log("%s", buffer);
			
			snprintf(buffer, sizeof(buffer), "\tFX: %f\n", ctx->force_x_array[i]);
			SDL_Log("%s", buffer);
			
			snprintf(buffer, sizeof(buffer), "\tFY: %f\n", ctx->force_y_array[i]);
			SDL_Log("%s", buffer);
		}*/

		//----CLEAR----
		SDL_SetRenderDrawColor(renderer, 0, 0, 50, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		//SDL_FRect rect = { player.x, player.y, 100, 100 };
		//SDL_RenderFillRect(renderer, &rect);

		//----PRESENT----
		SDL_RenderPresent(renderer);

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
