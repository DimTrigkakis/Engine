#pragma once
#include "Scenegraph.h"

class Source {

public:
	Source(Scenegraph *scene);
	Scenegraph *scene;
	void Animate(double timeval);
};

void draw(Gobject *g);