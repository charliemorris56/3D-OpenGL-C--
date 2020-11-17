#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "SceneObject.h"
#include <fstream>
#include <iostream>

class StaticObjects : public SceneObject
{
private:
	Vector3 _position;
	void Keyboard(unsigned char key, int x, int y);
	POINT p;

public:
	StaticObjects(Mesh* mesh, Texture2D* texture, float X, float Y, float Z);
	~StaticObjects();

	void Draw();
	void Update();
};

