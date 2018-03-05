#include "MultipleObjects.h"

MultipleObjects::MultipleObjects()
{
	ObjMesh* _parentMesh = ModelLoader::Load("HUMMWV.obj");
	ObjMesh* _child1Mesh = ModelLoader::Load("PaulShip.obj");
	ObjMesh* _child2Mesh = ModelLoader::Load("deagle.obj");
	Texture2D* _parentTexture = new Texture2D();
	Texture2D* _child1Texture = new Texture2D();
	Texture2D* _child2Texture = new Texture2D();

	_parentTexture->LoadTexture("HUMMWV.jpg");

	thing = new SceneNode(_parentMesh, _parentTexture);
	otherThing = new SceneNode(_child1Mesh, _child1Texture);
	anotherThing = new SceneNode(_child2Mesh, _child2Texture);

	_parentPosition->x = 1.0f;
	_parentPosition->y = 1.0f;
	_parentPosition->z = 1.0f;

	//thing->setParentPosition(_parentPosition);
	//thing->AddChild(thing);

	//_childPosition1->x = 1.0f;
	//_childPosition1->y = 1.0f;
	//_childPosition1->z = 1.0f;   
	//
	//otherThing->setChildPositionWS(_childPosition1); //this should corispond with parent meaning 1,0,1 + 1,1,1;
	//thing->AddChild(otherThing);
	
	
}

MultipleObjects::~MultipleObjects()
{

}

void MultipleObjects::Update()
{
	//thing->Update();

	//otherThing->translateAroundParent();
	//otherThing->Update();
	//otherThing->GetParentPosition();
}

void MultipleObjects::Draw()
{
	//thing->Update();
	//otherThing->Draw();
}
