#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

class Gobject {
public:
	int tid = -1;
	int lid = -1;
	char* name;
	float location[3] = { 0, 0, 0 };
	float rotation[3] = { 0, 0, 0 };

	Gobject* parent = NULL;
	void transform();

public:
	void(*draw_function)(Gobject *g) = NULL;
	void draw();
	Gobject(Gobject* parent, char* name, int tid, int lid, void(*draw_function)(Gobject *g));
};