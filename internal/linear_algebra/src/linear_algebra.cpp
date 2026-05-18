#include "linear_algebra.h"

void mat3_identity(Mat3* out)
{
	out->m[0] = 1.0f;
	out->m[1] = 0.0f;
	out->m[2] = 0.0f;
	
	out->m[3] = 0.0f;
	out->m[4] = 1.0f;
	out->m[5] = 0.0f;
	
	out->m[6] = 0.0f;
	out->m[7] = 0.0f;
	out->m[8] = 1.0f;
}

void mat3_rotation(Mat3* out, float radians)
{
	float c = cosf(radians);
	float s = sinf(radians);
	mat3_identity(out);
	out->m[0] = c;
	out->m[1] = s;
	out->m[3] = -s;
	out->m[4] = c;
}

void mat3_mul(Mat3* out, const Mat3* A, const Mat3* B)
{
	Mat3 result;
	for(int colB = 0; colB < 3; colB++)	
	{
		for(int rowA = 0; rowA < 3; rowA++)
		{
			result.m[rowA + colB * 3] =
				A->m[rowA] * B->m[colB*3] +	
				A->m[rowA + 3] * B->m[1 + colB * 3] +
				A->m[rowA + 6] * B->m[2 + colB * 3];
		}
	}
	*out = result;
}

void mat3_to_string(const Mat3* mat, char *buffer, size_t buffer_size)
{
	if(!buffer || buffer_size == 0) return;
	
	snprintf(buffer, buffer_size, 
		"[%8.3f %8.3f %8.3f]\n"
		"[%8.3f %8.3f %8.3f]\n"
		"[%8.3f %8.3f %8.3f]",
		mat->m[0], mat->m[3], mat->m[6],
		mat->m[1], mat->m[4], mat->m[7],
		mat->m[2], mat->m[5], mat->m[8]);
}

void vec2_to_string(const Vec2* vec2, char *buffer, size_t buffer_size)
{
	if(!buffer || buffer_size == 0) return;
	snprintf(buffer, buffer_size, 
		"[%8.3f]\n"
		"[%8.3f]",
		vec2->x,
		vec2->y);
}
