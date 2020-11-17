#pragma once
#include<Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include "GL\freeglut.h"

struct Vector3
{
	float x, y, z;
};

struct Camera
{
	Vector3 eye, center, up;
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

struct TexCoord
{
	GLfloat u, v;
};

struct Mesh
{
	Vertex* Vertices;
	//Color* Colors;
	GLushort* Indices;
	int VertexCount, IndexCount, TexCoordCount, NormalCount;
	//int ColorCount;

	TexCoord* TexCoords;

	Vector3* Normals;
};

struct Vector4
{
	float w, x, y, z;
};

struct Lighting
{
	Vector4 Ambient, Diffuse, Specular;
};

struct Meterial
{
	Vector4 Ambient, Diffuse, Specular;
	GLfloat Shininess;
};

//struct TexturedMesh
//{
//	Vertex* Vertices;
//	Color* Colors;
//	GLushort* Indices;
//	int VertexCount, ColorCount, IndexCount;
//};