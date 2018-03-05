#include "Camera.h"
#include <iostream>

//https://msdn.microsoft.com/en-us/library/bb203909(v=xnagamestudio.31).aspx read this
//http://www.gamasutra.com/blogs/YoannPignole/20150928/249412/Third_person_camera_design_with_free_move_zone.php looks good fam
//https://www.gamedev.net/resources/_/technical/graphics-programming-and-theory/camera-class-tutorial-r1927 READ FULLY
//https://www.gamedev.net/resources/_/technical/game-programming/creating-a-useful-camera-class-r2160 ALSO READ
//https://learnopengl.com/#!Getting-started/Camera OPENGL CAMERA MOVEMENT READ
//https://www.youtube.com/watch?v=zHlxQoJYUhw watch video

Camera::Camera(Player * playerPosition, Vector3 playerPos)
{
	_playerCameraPos.x = playerPosition->GetX();
	_playerCameraPos.y = playerPosition->GetY();
	_playerCameraPos.z = playerPosition->GetZ();

	_rotation.x = playerPos.x;
	_rotation.y = playerPos.y;
	_rotation.z = playerPos.z;
}

Camera::~Camera()
{
}

void Camera::calculateCameraPosition()
{
	_horizontalDistance = calculateHorizontalDistance();
	_verticalDistance = calculateVerticalDistance();

	float theta = /*_playerPos->getRotationY()*/ _playerCameraPos.y + _angleAroundPlayer;
	float offsetX = _horizontalDistance * sin(theta);
	float offsetZ = _horizontalDistance * cos(theta);

	_cameraPos.y = _playerCameraPos.y + _verticalDistance;
	_cameraPos.x = _playerCameraPos.x - offsetX;
	_cameraPos.z = _playerCameraPos.z - offsetZ;
}

void Camera::calculateZoom(int direction)
{
	float zoomLevel = direction * 0.1;
	_distanceFromPlayer -= zoomLevel;
}

void Camera::calculatePitch(int mouseYAxis)
{
	float pitchChange = mouseYAxis * 0.1f;
	_pitch -= pitchChange;
}

void Camera::calculateAngleArounrdPlayer(int mouseXAxis)
{
	float angleChange = mouseXAxis * 0.1f;
	_angleAroundPlayer -= angleChange;
}

void Camera::move(int mouseXAxis, int mouseYAxis)
{
	calculatePitch(mouseYAxis);
	calculateAngleArounrdPlayer(mouseXAxis);
	calculateCameraPosition();
}

float Camera::calculateHorizontalDistance()
{
	return float (_distanceFromPlayer * cos(_pitch));
}

float Camera::calculateVerticalDistance()
{
	return float (_distanceFromPlayer * sin(_pitch));
}

GLfloat Camera::getEyeX()
{
	 _cameraPos.x = _playerCameraPos.x + cos(45) * -10;
	 return _cameraPos.x;
}

GLfloat Camera::getEyeY()
{
	 _cameraPos.y = _playerCameraPos.y + cos(45) * 10;
	 return _cameraPos.y;
}

GLfloat Camera::getEyeZ()
{
	 _cameraPos.z = _playerCameraPos.z + cos(45) * -0.5;
	 return _cameraPos.z;
}

void Camera::Update()
{
	getEyeX();
	getEyeY();
	getEyeZ();
	
}
