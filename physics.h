#ifndef PHYSICS_H
#define PHYSICS_H
#include "./utility/linear_algebra/linear_algebra.h"

typedef struct
{
	Vec2* positions;
	Vec2 velocities[1000];
	int capacity;
	int active_count;
} physics_context;

void physics_init(physics_context* ctx, Vec2* entity_position_array, int max_entities);
void update_physics();

#endif //PHYSICS_H
