#ifndef PARADIGM_PHYSICS_C
#define PARADIGM_PHYSICS_C
#include "paradigm_physics.h"

PhysicsContext* physics_init(const uint32_t count)
{
	PhysicsContext* ctx = (PhysicsContext*)malloc(sizeof(PhysicsContext));
	if(!ctx) return NULL;

	ctx->count = count; 

	//blob total size
	size_t total_size = (sizeof(float) * count * 6) + (sizeof(uint8_t) * count) + (sizeof(uint32_t) * count);

	ctx->blob_start = malloc(total_size);
	if(!ctx->blob_start)
	{
		free(ctx);
		return NULL;
	}

	//convert to byte addressable memory	
	char* base = (char*)ctx->blob_start;
	char* currentAddress = base;

	ctx->mass = (uint32_t*)currentAddress;
	currentAddress += sizeof(uint32_t) * count; 

	ctx->x = (float*)currentAddress;
	currentAddress += sizeof(float) * count;

	ctx->y = (float*)currentAddress;
	currentAddress += sizeof(float) * count;

	ctx->vx = (float*)currentAddress;
	currentAddress += sizeof(float) * count;

	ctx->vy = (float*)currentAddress;
	currentAddress += sizeof(float) * count;

	ctx->fx = (float*)currentAddress;
	currentAddress += sizeof(float) * count;

	ctx->fy = (float*)currentAddress;
	currentAddress += sizeof(float) * count;

	ctx->state = (uint8_t*)currentAddress;

	return ctx;
}

void update_physics(PhysicsContext* ctx)
{
			
}

void apply_kinematics(float* fx, float* fy, float* ax, float* ay) 
{

}

#endif //PARADIGM_PHYSICS_C
