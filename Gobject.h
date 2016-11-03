#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

class Gobject {
public:
	int gid = 0;
	int tid = -1;
	int lid = -1;
	char* name;
	float location[3] = { 0, 0, 0 };
	float rotation[3] = { 0, 0, 0 };

	Gobject* parent = NULL;
	void transform();

public:
	void(*draw_function)(int gid, int tid, char* name) = NULL;
	void draw();
	Gobject(Gobject* parent, char* name, int gid, int tid, void(*draw_function)(int gid, int tid, char* name));
};