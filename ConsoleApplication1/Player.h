#pragma once
#include "Structures.h"
#include "ObjSceneObject.h"
#include "GLUTCallback.h"

class Player : public ObjSceneObject
{
private:
	 Vector3 _position;
	 Vector3 _rotation;

public:
	Player(ObjMesh* mesh, Texture2D* texture, Vector3 position);
	
	//Player Movement
	void Move(Vector3 moveAmount);
	
	//Used by camera for third person view
	GLfloat GetX();
	GLfloat GetY();
	GLfloat GetZ();

	void Update();
	void Draw();

};