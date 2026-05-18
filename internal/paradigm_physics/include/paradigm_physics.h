#ifndef PARADIGM_PHYSICS_H
#define PARADIGM_PHYSICS_H
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	uint32_t count;

	uint32_t* mass_array;
	float* x_array;
	float* y_array;
	float* velocity_x_array;
	float* velocity_y_array;
	float* force_x_array;
	float* force_y_array;
	
	
	uint32_t* moment_of_inertia_array;
	float* angle_array;
	float* angular_velocity_array;
	float* torque_array;
	
	

	//STATE -> BITMASK FOR FLAGS
	//FLAGS:
	//IS_ACTIVE 0x1
	//IS_DYNAMIC 0x2
	//IS_STATIC 0x4
	//IS_KINEMATIC 0x8
	//IS_TRIGGER 0x10
	uint8_t* state_array;

	void* blob_start;
} PhysicsContext;

PhysicsContext* physics_init(const uint32_t count);


//WILL UTILIZE A COMMAND BUFFER AND BATCH PROCESS SCHEME

void update_physics(PhysicsContext* ctx, float delta_time);

void physics_apply_force(PhysicsContext* ctx, int handle, float fx, float fy);
void physics_apply_impulse(PhysicsContext* ctx, int handle, float ix, float iy);
void physics_set_state(PhysicsContext* ctx, int handle, uint8_t state_flag);
void physics_set_velocity(PhysicsContext* ctx, int handle, float vx, float vy);

#endif //PARADIGM_PHYSICS_H
