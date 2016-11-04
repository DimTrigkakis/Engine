#include "Core.h"
#include "Project.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
	Project p = Project();
	return run(&argc,argv);
};

