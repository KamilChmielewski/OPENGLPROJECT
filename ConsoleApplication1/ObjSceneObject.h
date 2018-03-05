#pragma once
#include "Structures.h"
#include "Texture2D.h"

class ObjSceneObject
{
protected:
	ObjMesh* _mesh;
	Texture2D* _texture;
public:
	ObjSceneObject(ObjMesh* mesh, Texture2D* texture);
	virtual ~ObjSceneObject(void);
	virtual void Update() = 0;
	virtual void Draw() = 0;
};