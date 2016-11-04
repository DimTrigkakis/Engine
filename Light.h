#pragma once
#include "Spot.h"

class Light {
public:
	float x;
	float y;
	float z;

	float r;
	float g;
	float b;

	Spot* spot;

	Light(float x, float y, float z, float r, float g, float b,Spot* spot);

};