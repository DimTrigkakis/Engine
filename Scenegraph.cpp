#include "Scenegraph.h"
#include "Gobject.h"

void Scenegraph::draw()
{
	for (std::vector<Gobject>::iterator it = (this->g).begin(); it != (this->g).end(); it++)
		it->draw();
}

void Scenegraph::addGobject(Gobject* parent, char* name, int gid, int tid, void (*draw_function)(int gid, int tid, char* name))// draw_function, tid = -1, parent = None, name = None)
{
	Gobject go = Gobject(parent,name,gid,tid,draw_function);
	this->gid += 1;
	std::vector<Gobject>::iterator it;
	it = this->g.begin();
	it = this->g.insert(it,go);
};