#pragma once
#include "Gobject.h"
#include <vector>

class Scenegraph {
public:
	int gid = 0;
	std::vector<Gobject> g = {  };

public:
	void draw();
	void addGobject(Gobject* parent, char* name, int gid, int tid, void(*draw_function)(int gid, int tid, char* name));
};