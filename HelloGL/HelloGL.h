#pragma once
#include<Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include "GL\freeglut.h"
#include "GLUTCallbacks.h"
#include "Structures.h"
#include "FlyingObjects.h"
#include "MeshLoader.h"
#include "StaticObjects.h"
#include "SceneObject.h"
#include "Texture2D.h"

#define REFRESHRATE 16

class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);
	~HelloGL(void);
	void Display();
	//void DrawPolygon();
	void Update();
	void Keyboard(unsigned char key, int x, int y);

	void InitObject();
	void InitGL(int argc, char* argv[]);

	void InitLighting();

	//void DrawCube();
	//void DrawCubeArray();
	//void DrawCubeIndexed();

private:
	//float rotationTriangle;
	//float rotationSquare;

	Camera* camera;
	SceneObject* objects[201]; //200Cubes, and 1 pyrimid

	Vector4* _lightPosition;
	Lighting* _lightData;

	//static Vertex vertices[];
	//static Color colors[];

	//static Vertex indexedVertices[];
	//static Color indexedColors[];
	//static GLushort indices[];
};