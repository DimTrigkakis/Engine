#include "Source.h"
#include "stdio.h"
#include "Scenegraph.h"
#include "Core.h"

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4996)
#include "glew.h"
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"

#include <windows.h>

#include <stdio.h>  /* defines FILENAME_MAX */
#include <direct.h>
#define GetCurrentDir _getcwd

Source::Source(Scenegraph *scene) {
	this->scene = scene;
	char *textures[] = { "./Release/worldtex.bmp"};

	for (int i = 0; i < sizeof(textures) / sizeof(char*); i++)
		LoadTexture(textures[i],i);

	scene->addGobject(NULL,"Constance",0,draw);
	//Spot *S = new Spot(0,1,0);
	Spot *S = NULL;
	Light *L = new Light(0,10,0,0,1,0,S);
	Light *L2 = new Light(0, 0, 10, 1, 0, 0, S);
	scene->addLight(NULL,"Light0",0,L);
	scene->addLight(NULL, "Light1", 1, L2);
}

void draw(Gobject *g)
{
	if (g->tid != -1)
		SetTexture(g->tid);

	glColor3f(0.9, 0.9, 0.9);
	glutSolidTeapot(0.5);
}

void Source::Animate(double timeval) {
	fprintf(stderr, "%f", timeval);
	this->scene->g[0].rotation[0] += (float)timeval*0.1;
}