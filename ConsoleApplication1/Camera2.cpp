#include "Camera2.h"
#include "Player.h"

Camera2::Camera2()
{
}

Camera2::~Camera2()
{
}

void Camera2::Position_Camera(float pos_x, float pos_y, float pos_z, float view_x, float view_y, float view_z, float up_x, float up_y, float up_z)
{
	mPos = Vector3(pos_x, pos_y, pos_z);
	mView = Vector3(view_x, view_y, view_z);
	mUp = Vector3(up_x, up_y, up_z);
}

void Camera2::Move_Camera(float speed)
{
	Vector3 vVector;
	vVector.x = mView.x - mPos.x;
	vVector.y = mView.y - mPos.y;
	vVector.z = mView.z - mPos.z; //The view vector

	//forwards and backwards camera speed
	mPos.x = mPos.x + vVector.x * speed;
	mPos.z = mPos.z + vVector.z * speed;
	mView.x = mView.x + vVector.x * speed;
	mView.z = mView.z + vVector.z * speed;
}


void Camera2::Rotate_View(float speed) //Rotates the camera view
{
	Vector3 vVector;
	vVector.x = mView.x - mPos.x;
	vVector.y = mView.y - mPos.y;
	vVector.z = mView.z - mPos.z; //The view vector

	mView.z = (float)(mPos.z + sin(speed)*vVector.x + cos(speed)*vVector.z);
	mView.x = (float)(mPos.x + cos(speed)*vVector.x - sin(speed)*vVector.z);
}

void Camera2::Rotate_Position(float speed)
{
	Vector3 vVector;
	vVector.x = mPos.x - mView.x;
	vVector.y = mPos.y - mView.y;
	vVector.z = mPos.z - mView.z;

	mPos.z = (float)(mView.z + sin(speed)*vVector.x + cos(speed)*vVector.z);
	mPos.x = (float)(mView.x + cos(speed)*vVector.x - sin(speed)*vVector.z);
}

void Camera2::Mouse_Move(int wndWidth, int wndHieght)
{
	//MouseInfo mousePos;
	POINT mousePos;
	int mid_X = wndWidth >> 1;
	int mid_Y = wndHieght >> 1;
	float angle_Y = 0.0f;
	float angle_Z = 0.0f;

	GetCursorPos(&mousePos); //built in Microsoft function which gets the mouse curose 2D position (x, y)

	if ((mousePos.x == mid_X) && (mousePos.y == mid_Y))
	{
		return;
	}

	SetCursorPos(mid_X, mid_Y); //Another microsoft function

	//Get the direction from the mouse curose, set a manevering speed
	angle_Y = (float) ( (mid_X - mousePos.x) ) / 1000;
	angle_Z = (float) ( (mid_Y - mousePos.y) ) / 1000;

	//This speed determines the cameras looks speed
	mView.y += angle_Z * 2;

	if (mView.y > 3.5f)
	{
		mView.y = 3.5f;
	}

	if (mView.y < -5.4f)
	{
		mView.y = -5.4f;
	}

	Rotate_Position(-angle_Y);
}

