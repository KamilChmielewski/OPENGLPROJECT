#pragma once
#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library
#include "../SOIL.h"
#include "../Simple OpenGL Image Library/src/SOIL.h"

class Texture2D
{
private:
	GLuint _ID; //Texture ID
	int _width, _height;


public:
	Texture2D();
	~Texture2D();

	int LoadTexture(const char* textureFileName);

	GLuint GetID() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
	
};

