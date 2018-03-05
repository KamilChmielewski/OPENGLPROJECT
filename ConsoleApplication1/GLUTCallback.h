#pragma once
#include "Structures.h"

class helloGl; //Forward declare HelloGL
namespace GLUTCallbacks
{
	void Init(helloGl * gl);
	void Timer(int preferredRefresh);
	void Display();
	void Keyboard(unsigned char key, int x, int y);
	void Motion(int x, int y);
	void Mouse(int button, int state, int x, int y);
};