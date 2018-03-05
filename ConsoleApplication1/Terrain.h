#pragma once
#include "Structures.h"
#include "ObjSceneObject.h"
#include "GLUTCallback.h"

class Terrain : public ObjSceneObject
{
	private:
	Vector3 _position;

	public:
	Terrain(ObjMesh* mesh, Texture2D* texture, Vector3 position);

	void Move(Vector3 moveAmount);
	void Update();
	void Draw();
};