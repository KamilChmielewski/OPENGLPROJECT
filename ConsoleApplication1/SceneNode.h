#pragma once
#include "Structures.h"
#include "ModelLoader.h"
#include <vector>
#include "Texture2D.h"
#include "ObjSceneObject.h"

class SceneNode : public ObjSceneObject
{
	private:
	SceneNode* _parent;
	std::vector<SceneNode*> _childern;
	Vector3 _parentPosition;
	Vector3 _childPosition;

	public:
	SceneNode(ObjMesh * mesh, Texture2D * texture);
	~SceneNode();
	
	void AddChild(SceneNode* s);

	void SetParentPosition(Vector3 parentPosition);
	Vector3 GetParentPosition() { return _parentPosition; }

	void SetChildPositionWS(Vector3 childPosition); //WS == worldSpace get parents poition _childPos + parent pos = childpos 
	GLfloat GetChildPosition() { return _childPosition.y; }

	void MoveParent(Vector3 moveAmount);

	void TranslateAroundParent();

	void Draw();
	void Update();
};