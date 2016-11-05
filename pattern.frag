#version 330 compatibility

uniform float	uTime;		// "Time", from Animate( )
in vec2  	vST;		// texture coords

float r(float x, float y)
{
	return ((int(x*2) + int(y*8)) % ((int(uTime/10)) % 5 + 1)) / (5.0f);
}
float r2(float x, float y)
{
	return ((int(x*20) + int(y*20)) % ((int(uTime/100) % (int(uTime/100) % 20 + 1) + 1))) / (5.0f);
}
float r3(float x, float y)
{
	return ((int(x*5) + int(y*5)) % 12) / 12.0f;
}

void
main( )
{
	float random_number = r2(vST[0],vST[1]);
	vec3 myColor = vec3( r(vST[0],vST[1]),r2(vST[0],vST[1])/2,r3(vST[0],vST[1]));
	gl_FragColor = vec4( myColor,  1.0 );
	if( random_number < 0.3 )
		gl_FragColor = vec4(0.2,0.2,0.2, 0.3);
}