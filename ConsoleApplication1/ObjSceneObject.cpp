#include "ObjSceneObject.h"

ObjSceneObject::ObjSceneObject(ObjMesh * mesh, Texture2D * texture)
{
	_mesh = mesh;
	_texture = texture;
}

ObjSceneObject::~ObjSceneObject(void)
{
}
