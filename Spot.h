#pragma once

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4996)
#include "glew.h"
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"

class Spot {

public:

	GLfloat dir[3];
	Spot(float, float, float);

};