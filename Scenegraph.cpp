#include "Scenegraph.h"
#include "Gobject.h"

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4996)
#include "glew.h"
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"


Scenegraph::Scenegraph()
{
};

void Scenegraph::draw()
{
	for (std::vector<Gobject>::iterator it = (this->g).begin(); it != (this->g).end(); it++)
		it->draw();
};

void Scenegraph::addGobject(Gobject* parent, char* name, int tid, void (*draw_function)(Gobject *g))// draw_function, tid = -1, parent = None, name = None
{
	Gobject go = Gobject(parent,name,tid,-1,draw_function);
	this->g.push_back(go);
};

void Scenegraph::addLight(Gobject* parent, char* name, int lid, Light *l)// draw_function, tid = -1, parent = None, name = None
{
	Gobject go = Gobject(parent, name, -1, lid, NULL);
	std::vector<Gobject>::iterator it;

	/* Create the light itself */
	go.lid = lid;
	go.location[0] = l->x;
	go.location[1] = l->y;
	go.location[2] = l->z;
	float lightPosition[4] = { l->x, l->y, l->z, 1. };
	float lightColor[4] = { l->r, l->g, l->b, 1.0 };
	glLightfv(GL_LIGHT0 + lid, GL_POSITION, lightPosition);
	glLightfv(GL_LIGHT0 + lid, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0 + lid, GL_SPECULAR, lightColor);
	glLightf(GL_LIGHT0 + lid, GL_CONSTANT_ATTENUATION, 0.1);
	glLightf(GL_LIGHT0 + lid, GL_LINEAR_ATTENUATION, 0.05);
	glLightf(GL_LIGHT0 + lid, GL_QUADRATIC_ATTENUATION, 0);
	if (l->spot != NULL)
	{
		glLightfv(GL_LIGHT0 + lid, GL_SPOT_DIRECTION, l->spot->dir);
		glLightf(GL_LIGHT0 + lid, GL_SPOT_EXPONENT, 1);
		glLightf(GL_LIGHT0 + lid, GL_SPOT_CUTOFF, 60.0);
	}

	glEnable(GL_LIGHT0 + lid);
	this->g.push_back(go);
};