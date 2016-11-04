#include "Light.h"

Light::Light(float x, float y, float z, float r, float g, float b, Spot* spot)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->r = r;
	this->g = g;
	this->b = b;
	this->spot = spot;
}