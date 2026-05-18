#ifndef PARADIGM_PHYSICS_C
#define PARADIGM_PHYSICS_C
#include "paradigm_physics.h"


PhysicsContext* physics_init(const uint32_t count)
{
	PhysicsContext* ctx = (PhysicsContext*)malloc(sizeof(PhysicsContext));
	if(!ctx) return NULL;

	ctx->count = count; 

	//blob total size
	size_t total_size = (sizeof(float) * count * 9) + (sizeof(uint8_t) * count * 1) + (sizeof(uint32_t) * count * 2);

	ctx->blob_start = malloc(total_size);
	if(!ctx->blob_start)
	{
		free(ctx);
		return NULL;
	}
	memset(ctx->blob_start, 0, total_size); //set memory to zero

	//convert to byte addressable memory	
	char* base = (char*)ctx->blob_start;
	char* currentAddress = base;

	//4 bit allignment macro
	#define ALIGN_4(addr) (((addr) + 3) & ~3)

	ctx->mass_array = (uint32_t*)currentAddress;
	currentAddress += sizeof(uint32_t) * count; 
	currentAddress = (char*)ALIGN_4((uintptr_t)currentAddress);

	ctx->moment_of_inertia_array = (uint32_t*)currentAddress;
	currentAddress += sizeof(uint32_t) * count;
	currentAddress = (char*)ALIGN_4((uintptr_t)currentAddress);

	ctx->x_array = (float*)currentAddress;
	currentAddress += sizeof(float) * count;
	currentAddress = (char*)ALIGN_4((uintptr_t)currentAddress);

	ctx->y_array = (float*)currentAddress;
	currentAddress += sizeof(float) * count;
	currentAddress = (char*)ALIGN_4((uintptr_t)currentAddress);

	ctx->velocity_x_array = (float*)currentAddress;
	currentAddress += sizeof(float) * count;
	currentAddress = (char*)ALIGN_4((uintptr_t)currentAddress);

	ctx->velocity_y_array = (float*)currentAddress;
	currentAddress += sizeof(float) * count;
	currentAddress = (char*)ALIGN_4((uintptr_t)currentAddress);

	ctx->force_x_array = (float*)currentAddress;
	currentAddress += sizeof(float) * count;
	currentAddress = (char*)ALIGN_4((uintptr_t)currentAddress);

	ctx->force_y_array = (float*)currentAddress;
	currentAddress += sizeof(float) * count;
	currentAddress = (char*)ALIGN_4((uintptr_t)currentAddress);

	ctx->angle_array = (float*)currentAddress;
	currentAddress += sizeof(float) * count;
	currentAddress = (char*)ALIGN_4((uintptr_t)currentAddress);
	
	ctx->angular_velocity_array = (float*)currentAddress;
	currentAddress += sizeof(float) * count;
	currentAddress = (char*)ALIGN_4((uintptr_t)currentAddress);
	
	ctx->torque_array = (float*)currentAddress;
	currentAddress += sizeof(float) * count;
	currentAddress = (char*)ALIGN_4((uintptr_t)currentAddress);

	ctx->state_array = (uint8_t*)currentAddress;
	currentAddress += sizeof(uint8_t) * count;
	currentAddress = (char*)ALIGN_4((uintptr_t)currentAddress);

	return ctx;
}

void physics_apply_force(PhysicsContext* ctx, int handle, float fx, float fy)
{
	ctx->force_x_array[handle] += fx; 
	ctx->force_y_array[handle] += fy;
}

void update_physics(PhysicsContext* ctx, float delta_time)
{
	for(int i = 0; i < ctx->count; i++) 
	{
		ctx->velocity_x_array[i] += ctx->force_x_array[i] * delta_time * (1/ctx->mass_array[i]);
		ctx->velocity_y_array[i] += ctx->force_y_array[i] * delta_time * (1/ctx->mass_array[i]);
		
		//forces used
		ctx->force_y_array[i] = 0;	
		ctx->force_x_array[i] = 0;

		ctx->x_array[i] += ctx->velocity_x_array[i] * delta_time;
		ctx->y_array[i] += ctx->velocity_y_array[i] * delta_time;
	}
}

#endif //PARADIGM_PHYSICS_C
