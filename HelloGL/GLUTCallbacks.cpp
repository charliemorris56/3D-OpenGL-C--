#include "GLUTCallbacks.h"
#include "HelloGL.h"

namespace GLUTCallbacks
{
	namespace
	{
		HelloGL* helloGL = nullptr;
	}

	void Init(HelloGL* gl)
	{
		helloGL = gl;
	}

	void Display()
	{
		if (helloGL != nullptr)
		{
			helloGL->Display();
		}
	}
	void Timer(int perferredRefresh)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloGL->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;
		glutTimerFunc(perferredRefresh - updateTime, GLUTCallbacks::Timer, perferredRefresh);
	}
	void Keyboard(unsigned char key, int x, int y)
	{
		helloGL->Keyboard(key, x, y);
	}
}


