#pragma once
#include "Scenegraph.h"

class Source {

public:
	Source(Scenegraph *scene);
	Scenegraph *scene;
	void Init();
	void Animate(int timeval);
};

void draw_core(Gobject *g);
void draw(Gobject *g);