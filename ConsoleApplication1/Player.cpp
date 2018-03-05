#include "Player.h"
#include "helloGl.h"

Player::Player(ObjMesh * mesh, Texture2D * texture, Vector3 position) : ObjSceneObject(mesh, texture)
{
	_position.x = position.x;
	_position.y = position.y;
	_position.z = position.z;
}

void Player::Move(Vector3 moveAmount)
{
	_position.x += moveAmount.x;
	_position.y += moveAmount.y;
	_position.z += moveAmount.z;
}

GLfloat Player::GetX()
{
	std::cout << _position.x << std::endl;
	return _position.x;
}

GLfloat Player::GetY()
{
	return _position.y;
}

GLfloat Player::GetZ()
{
	return _position.z;
}


void Player::Update()
{
	
}

void Player::Draw()
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

		glScalef(0.1f, 0.1f, 0.1f);
		glTranslatef(_position.x, _position.y, _position.z);

		glDrawArrays(GL_TRIANGLES, 0, _mesh->vertices.size());

		glPopMatrix();

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
	else
	{
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_VERTEX_ARRAY);


		glVertexPointer(3, GL_FLOAT, 0, &_mesh->vertices[0]);
		glNormalPointer(GL_FLOAT, 0, &_mesh->normals[0]);

		glPushMatrix();
		glTranslatef(-4.0f, -0.0f, -6.0f);

		glDrawArrays(GL_TRIANGLES, 0, _mesh->vertices.size());

		glPopMatrix();

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
	}
}


