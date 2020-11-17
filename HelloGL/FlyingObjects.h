#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"
#include <fstream>
#include <iostream>

class FlyingObjects : public SceneObject
{
private:
	/*static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];*/

	/*static Vertex* indexedVertices;
	static Color* indexedColors;
	static GLushort* indices;*/ 
	
	GLfloat _rotation;
	GLfloat _rotationSpeed;

	Vector3 _position;

	Meterial* _material;

	/*static int numVertices, numColors, numIndices;*/

public:
	FlyingObjects(Mesh* mesh, Texture2D* texture, float X, float Y, float Z, GLfloat rotationSpeed);
	~FlyingObjects();

	void Draw();
	void Update();

	void DrawMaterial();

	//static bool Load(char* path);
};

