#pragma once
#include "Scenegraph.h"

#ifdef WIN32
#include <windows.h>
#pragma warning(disable:4996)
#include "glew.h"
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"

extern int		ActiveButton;			// current button that is down
extern int		DebugOn;				// != 0 means to print debugging info
extern int		MainWindow;				// window id for main graphics window
extern float	Scale;					// scaling factor
extern int		WhichColor;				// index into Colors[ ]
extern int		Xmouse, Ymouse;			// mouse values
extern float	Xrot, Yrot;				// rotation angles in degrees

extern enum ButtonVals
{
	RESET,
	QUIT
};

extern Scenegraph *scene;
extern void SetTexture(int);
extern void LoadTexture(char*,int);
extern GLuint mytextures[2];
extern void	DoMainMenu(int);