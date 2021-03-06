#pragma once
#include "Structures.h"
#include <math.h>
#include <Windows.h>

class Camera2
{
public:
	Camera2();
	~Camera2();
	
	Vector3 mPos;
	Vector3 mView;
	Vector3 mUp;

	void Move_Camera(float speed);
	void Mouse_Move(int wndWidth, int wndHieght);
	void Rotate_View(float speed);
	void Rotate_Position(float speed);
	void Position_Camera(float pos_x, float pos_y, float pos_z,
						 float view_x, float view_y, float view_z,
						 float up_x, float up_y, float up_z);
private:

};

