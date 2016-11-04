#pragma once
#include "Gobject.h"
#include <vector>
#include "Light.h"

class Scenegraph {
public:
	Scenegraph();
	std::vector<Gobject> g = { };

	void draw();
	void addGobject(Gobject* parent, char* name, int tid, void(*draw_function)(Gobject *g));
	void addLight(Gobject* parent, char* name, int lid, Light *l);
};