#pragma once
#include "Structures.h"
#include "SceneNode.h"
#include "ObjSceneObject.h"
#include "ModelLoader.h"

class MultipleObjects
{
private:
	SceneNode* thing;
	SceneNode* otherThing;
	SceneNode* anotherThing;

	Vector3* _parentPosition;
	Vector3* _childPosition1;
	Vector3* _childPosition2;
	
public:
	MultipleObjects();
	~MultipleObjects();
	//void SetUpNodes();
	void Update();
	void Draw();
};