#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H
#include <math.h>
#include <stdio.h>

typedef struct
{
	float m[9]; //column major 3x3
} Mat3;

typedef struct
{
	float x, y;
} Vec2;

void mat3_identity(Mat3* out); 

void mat3_rotation(Mat3* out, float radians);

void mat3_multiply(Mat3* out, const Mat3* A, const Mat3* B);

void mat3_to_string(const Mat3* mat, char *buffer, size_t buffer_size);

void vec2_to_string(const Vec2* vec2, char *buffer, size_t buffer_size);

#endif //LINEAR_ALGEBRA_H
