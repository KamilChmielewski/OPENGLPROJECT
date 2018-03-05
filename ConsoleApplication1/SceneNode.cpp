#include "SceneNode.h"

SceneNode::SceneNode(ObjMesh * mesh, Texture2D * texture) : ObjSceneObject(mesh, texture)
{
	
}

SceneNode::~SceneNode()
{

}

void SceneNode::AddChild(SceneNode * s)
{
	_childern.push_back(s);
	s->_parent = this;
}

void SceneNode::SetParentPosition(Vector3 parentPosition)
{
	_parentPosition.x = parentPosition.x;
	_parentPosition.y = parentPosition.y;
	_parentPosition.z = parentPosition.z;
}

void SceneNode::SetChildPositionWS(Vector3 childPosition)
{
	_childPosition.x = _parentPosition.x + childPosition.x;
	_childPosition.y = _parentPosition.y + childPosition.y;
	_childPosition.z = _parentPosition.z + childPosition.z;
}

void SceneNode::MoveParent(Vector3 moveAmount)
{
	_parentPosition.x += moveAmount.x;
	_parentPosition.y += moveAmount.y;
	_parentPosition.z += moveAmount.z;
}

void SceneNode::TranslateAroundParent() //Thinking is if parent moves so does the child because of setChildPosition
{
	//_parent->_parentPosition->x;
	glTranslatef(_parent->_parentPosition.x + _childPosition.x, _parent->_parentPosition.y + _childPosition.y, _parent->_parentPosition.z + _childPosition.z);
}

void SceneNode::Update()
{

}

void SceneNode::Draw()
{

	if (_mesh->textureEnabled == true)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());

		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glVertexPointer(3, GL_FLOAT, 0, &_mesh->vertices[0]);
		glNormalPointer(GL_FLOAT, 0, &_mesh->normals[0]);
		glTexCoordPointer(2, GL_FLOAT, 0, &_mesh->textures[0]);

		glPushMatrix();
		glScalef(1.0f, 1.0f, 1.0f);
	
		if (_parent)
		{
			glTranslatef(_parentPosition.x, _parentPosition.y, _parentPosition.z);
			glTranslatef(_childPosition.x, _childPosition.y, _childPosition.z);
		}

		if (!_parent)
		{
			glTranslatef(_childPosition.x, _childPosition.y, _childPosition.z);
		}

		glDrawArrays(GL_TRIANGLES, 0, _mesh->vertices.size());

		glPopMatrix();

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
}

