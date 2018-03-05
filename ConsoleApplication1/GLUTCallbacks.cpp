#include "helloGl.h"
#include "GLUTCallback.h"
#include "Player.h"

namespace GLUTCallbacks
{
	namespace
	{ 
		helloGl* helloGL = nullptr;
	}
	
	void Init(helloGl * gl)
	{
		helloGL = gl; 
	}
	
	void Display() 
	{
		if (helloGL != nullptr)
			helloGL->Display(); 
	}

	void Timer(int preferredRefresh)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloGL->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}

	void Motion(int x, int y)
	{
		helloGL->Motion(x, y);
	}

	void Keyboard(unsigned char key, int x, int y)
	{
		helloGL->Keyboard(key, x, y);
	}	

	void Mouse(int button, int state, int x, int y)
	{
		helloGL->Mouse(button, state, x, y);
	}
}