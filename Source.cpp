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

// Shaders

#include "glslprogram.h"
GLSLProgram	*Pattern;
float		 Time;



GLfloat CubeVertices[][3] =
{
	{ -1,-1,-1 },
	{ 1,-1,-1 },
	{ -1,1,-1 },
	{ 1,1,-1 },
	{ -1,-1,1 },
	{ 1,-1,1 },
	{ -1,1,1 },
	{ 1,1,1 }
};

GLfloat CubeColors[][3] =
{
	{ 0,0,0 },
	{ 0,0,1 },
	{ 0,1,0 },
	{ 0,1,1 },
	{ 1,0,0 },
	{ 1,0,1 },
	{ 1,1,0 },
	{ 1,1,1 }
};

GLuint CubeIndices[][4] =
{
	{ 0, 2, 3, 1 },
	{ 4, 5, 7, 6 },
	{ 1, 3, 7, 5 },
	{ 0, 4, 6, 2 },
	{ 2, 6, 7, 3 },
	{ 0, 1, 5, 4 }
};

GLuint vertexbuffer;
GLuint indicebuffer;
GLuint colorbuffer;

Source::Source(Scenegraph *scene) {

	this->Init();
	this->scene = scene;
	char *textures[] = { "./Release/worldtex.bmp"};

	for (int i = 0; i < sizeof(textures) / sizeof(char*); i++)
		LoadTexture(textures[i],i);

	scene->addGobject(NULL,"Constance",-1,draw);
	//Spot *S = new Spot(0,1,0);
	Spot *S = NULL;
	Light *L = new Light(0,3,0,1,1,1,S);
	Light *L2 = new Light(3, 0, 0, 1, 1, 1, S);
	Gobject* parent_light_0 = scene->addLight(NULL,"Light0",0,L);
	Gobject* parent_light_1 = scene->addLight(NULL, "Light1", 1, L2);
	//fprintf(stderr, "%p %p %p", parent_light_0, parent_light_1, o3);
}

void
Source::Init()
{
	// Shader compilation

	Pattern = new GLSLProgram();
	bool valid = Pattern->Create("pattern.vert", "pattern.frag");
	if (!valid)
	{
		fprintf(stderr, "Shader cannot be created!\n");
	}
	else
	{
		fprintf(stderr, "Shader created.\n");
	}
	Pattern->SetVerbose(false);

	// Current Vertex Array Object
	
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(GLfloat) * 8 * 2, CubeVertices, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 3 * sizeof(GLfloat) * 8, 3 * sizeof(GLfloat) * 8, CubeColors);

	glGenBuffers(1, &indicebuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicebuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 6 * 4,	CubeIndices, GL_STATIC_DRAW);

}


void draw(Gobject *g)
{

	if (g->tid != -1)
		SetTexture(g->tid);

	//glDisable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	GLfloat ad[] = { 50.0f / 256.0f, 20.0f / 256.0f, 20.0f / 256.0f, 1.0f };
	GLfloat s[] = { 0.1, 0.1, 0.1f, 1 };
	GLfloat shin = 0.0f;
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, ad );
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, s);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &shin);
	glShadeModel(GL_SMOOTH);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicebuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

	glVertexPointer(3, GL_FLOAT, 3 * sizeof(GLfloat), (char *)0);
	glColorPointer(3, GL_FLOAT, 3 * sizeof(GLfloat), (char *)0 + (3 * sizeof(GLfloat) * 8));
	glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, (char *)0);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glFrontFace(GL_CW);
	glutSolidTeapot(1.0);
	glFrontFace(GL_CCW);

}

void Source::Animate(int timeval) {
	Yrot += 1.0f;
	//this->scene->g[0]->rotation[1] += timeval*0.1f;
}