#version 330 compatibility

uniform float	uTime;		// "Time", from Animate( )
out vec2  	vST;		// texture coords

const float PI = 	3.14159265;
const float AMP = 	0.2;		// amplitude
const float W = 	2.;		// frequency

void
main( )
{ 
	vST = gl_MultiTexCoord0.st;
	vec3 vert = gl_Vertex.xyz;
	vert.x = vert.x+0.1*vert.y;
	int a = int(uTime) % 1000;
	int b = a;
	if (a > 500)
		b = 1000 - a;
	vert.y = 0.1*vert.y+0.9* vert.y* (b)/1000.0f;
	vert.z = vert.z;
	gl_Position = gl_ModelViewProjectionMatrix * vec4( vert, 1. );
}