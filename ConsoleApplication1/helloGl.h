#pragma once
#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL\freeglut.h" //freeglut library

#include "GLUTCallback.h"
#include "ObjSceneObject.h"
#include "Player.h"
#include "Terrain.h"
#include "ModelLoader.h"
#include "Camera2.h"
#include "SceneNode.h"
#include <math.h>
#include <cstdlib> 
#include <ctime> 

//http://stackoverflow.com/questions/5681948/multiple-textures-opengl-glut-c // use recursion?

//https://cboard.cprogramming.com/game-programming/98968-multiple-textures-opengl.html //Potential multiple textures
#define REFRESHRATE 16

class helloGl
{
private:
	CameraInfo* _camera;
	Player* _player;
	Terrain* _terrain[20];
	Camera2 objCamera;

	//ScreenSize
	int WINDOW_WIDTH = 1920;
	int WINDOW_HEIGHT = 1080;

	//Lighting
	Lighting* _lightData;
	Vector4* _lightPosition;
	Material* _material;

	//Doing testing for sceneNode

	SceneNode* whiteHouse;
	SceneNode* whiteHouse1;
	
	SceneNode* bodyFlat;
	SceneNode* bodyFlat1;
	
	//variables
	float _rotation;
	float _moveShip;

public:

	helloGl(int argc, char* argv[]);
	void LightingForGame();
	void Display();
	~helloGl(void);
	void InitObjects(); 
	void InitGL(int argc, char* argv[]);
	void Update();

	//Testing Ground
	void Draw_Grid();
	void DrawString(const char* text, const Vector3* position, const Colour* color);

	void Keyboard(unsigned char key, int x, int y);
	void Motion(int x, int y);
	void Mouse(int button, int state, int x, int y);
};
