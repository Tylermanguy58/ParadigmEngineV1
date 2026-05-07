#ifndef PARADIGM_PHYSICS_H
#define PARADIGM_PHYSICS_H
#include "../../utility/linear_algebra/linear_algebra.h"
#include <stdint.h>
#include <stdlib.h>

typedef struct
{
	uint32_t count;
	float* x;
	float* y;
	float* vx;
	float* vy;
	float* fx;
	float* fy;
	uint8_t* state;
	uint32_t* mass;
	void* blob_start;
} PhysicsContext;

PhysicsContext* physics_init(const uint32_t count);

void update_physics(PhysicsContext* ctx);

#endif //PARADIGM_PHYSICS_H
