#pragma once
#include "Player.h"
#include "Structures.h"
#include <math.h>

//http://www.lighthouse3d.com/tutorials/glut-tutorial/mouse-putting-it-all-together/
//http://www.swiftless.com/tutorials/opengl/camera3.html have a read
//https://www.opengl.org/discussion_boards/showthread.php/131147-Using-glutMotionFunc Mouse functionailty

class Camera
{
private:
	//setting up angles and distance between player and camera
	CameraInfo* _camera; //This is public because Hello GL will need this, unless I have get methods
	//const GLfloat _distanceFromPlayer = 10.0f;
	//const GLfloat _distanceFromPlayerX = -10.0f;
	//GLfloat _angleAroundPlayer = 0.0f;
	//const GLfloat _pitch = 5.0f; //This is how high the camera will be/ then again I can just use Y
	//Player to get X, Y, Z
	Vector3 _playerCameraPos;
	Vector3 _cameraPos;
	Vector3 _rotation;
	Player* _playerPos;

	Vector3 _cameraPosition;
	float _distanceFromPlayer;
	float _angleAroundPlayer;
	float _pitch = 20;
	float _yaw = 0;
	float _roll;
	
	float _horizontalDistance;
	float _verticalDistance;

	void calculateZoom(int direction);
	void calculatePitch(int mouseYAxis);
	void calculateAngleArounrdPlayer(int mouseXAxis);

	float calculateHorizontalDistance();
	float calculateVerticalDistance();

	void calculateCameraPosition();

public:	
	//Methods
	Camera(Player * playerPosition, Vector3 playerPos);
	~Camera();

	void move(int mouseXAxis, int mouseYAxis);

	GLfloat getEyeX();
	GLfloat getEyeY();
	GLfloat getEyeZ();

	float getPitch() { return _pitch; }
	float getYaw() { return _yaw; }
	float getRoll() { return _roll; }


	void Update();
};