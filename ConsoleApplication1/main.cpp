#include "helloGl.h"
#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library
int main(int argc, char* argv[])
{
	helloGl* game = new helloGl(argc, argv); //Creates an instance of our game
	return 0; //Assumes a sucessful exit if our game exits and we make it to this
}