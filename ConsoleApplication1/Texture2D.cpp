#include "Texture2D.h"
#include <iostream>
#include <fstream>
//#include "../SOIL.h"


using namespace std;

Texture2D::Texture2D()
{
}

Texture2D::~Texture2D()
{
}

int Texture2D::LoadTexture(const char* textureFileName)
{
	_ID = SOIL_load_OGL_texture // load an image file directly as a new OpenGL texture 
	(
		textureFileName,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
	);

	return _ID;
}



