#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define _USE_MATH_DEFINES
#include <math.h>

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4996)
#include "glew.h"
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"

#include "Gobject.h"

void Gobject::transform()
{
	if (this->parent != NULL)
		this->parent->transform();

	glTranslatef(this->location[0], this->location[1], this->location[2]);
	glRotatef((GLfloat) this->rotation[0], 0., 1., 0.);
	glRotatef((GLfloat) this->rotation[1], 0, 1, 0);
	glRotatef((GLfloat) this->rotation[2], 0, 0, 1);

};

void Gobject::draw()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	if (this->lid == -1)
		if (this->parent != NULL)
			this->parent->transform();

	glTranslatef(this->location[0], this->location[1], this->location[2]);
	glRotatef(this->rotation[0], 1, 0, 0);
	glRotatef(this->rotation[1], 0, 1, 0);
	glRotatef(this->rotation[2], 0, 0, 1);

	if (this->draw_function != NULL)
	{

		if (this->tid != -1)
		{
			glEnable(GL_TEXTURE_2D);
			this->draw_function(this->gid, this->tid, this->name);
			glDisable(GL_TEXTURE_2D);
		}
		else
			this->draw_function(this->gid, this->tid, this->name);
	}
	else
	{
		Gobject* p = this->parent;
		float location[] = {this->location[0], this->location[1], this->location[2]};
		while (p != NULL)
		{
			location[0] += p->location[0];
			location[1] += p->location[1];
			location[2] += p->location[2];
			p = p->parent;
		}
		GLfloat light_location[] = { this->location[0], this->location[1], this->location[2], 1.0 };
		glLightfv(GL_LIGHT0 + this->lid, GL_POSITION, light_location);
	}
	glPopMatrix();

}

Gobject::Gobject(Gobject* parent, char* name, int gid, int tid, void(*draw_function)(int gid, int tid, char* name)){
	this->parent = parent;
	this->name = name;
	this->gid = gid;
	this->tid = tid;
	this->draw_function = draw_function;

};