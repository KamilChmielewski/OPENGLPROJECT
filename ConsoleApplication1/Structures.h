#pragma once
#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library
#include <vector>

struct Vertex
{
	GLfloat x, y, z;
};

struct Colour
{
	GLfloat r, b, g;
};

struct Textures
{
	GLfloat u, v;
};

struct Vector3
{
		GLfloat x;
		GLfloat y;
		GLfloat z;

	Vector3()
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}

	Vector3(GLfloat x, GLfloat y, GLfloat z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

struct treenode
{
	char data;
	treenode * child;
	treenode * sibling;
};

	struct CameraInfo
	{
		Vector3 eye;
		Vector3 center;
		Vector3 up;
	};

	struct ObjMesh
	{
		std::vector<Vertex> vertices;
		std::vector<Vertex> normals;
		std::vector<Textures> textures;

		bool textureEnabled = false;

		//setting up the indices
		unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];

		std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
	};
	
	struct Vector4
	{
		GLfloat x, y, z, w;
	};

	struct Lighting
	{
		Vector4 Ambient;
		Vector4 Diffuse;
		Vector4 Specular;
	};

	struct Material
	{
		Vector4 Ambient;
		Vector4 Diffuse;
		Vector4 Specular;

		GLfloat Shininess;
	};

	
		
