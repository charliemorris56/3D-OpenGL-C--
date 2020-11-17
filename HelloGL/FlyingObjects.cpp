#include "FlyingObjects.h"

//Vertex Cube::indexedVertices[] = { 1, 1, 1,  -1, 1, 1,  // v0,v1,
//				-1,-1, 1,   1,-1, 1,   // v2,v3
//				1,-1,-1,   1, 1,-1,    // v4,v5
//				-1, 1,-1,   -1,-1,-1 }; // v6,v7
//
//Color Cube::indexedColors[] = { 1, 1, 1,   1, 1, 0,   // v0,v1,
//				1, 0, 0,   1, 0, 1,   // v2,v3
//				0, 0, 1,   0, 1, 1,   // v4,v5
//				0, 1, 0,   0, 0, 0 }; //v6,v7
//
//GLushort Cube::indices[] = { 0, 1, 2,  2, 3, 0,      // front
//				0, 3, 4,  4, 5, 0,      // right
//				0, 5, 6,  6, 1, 0,      // top
//				1, 6, 7,  7, 2, 1,      // left
//				7, 4, 3,  3, 2, 7,      // bottom
//				4, 7, 6,  6, 5, 4 };    // back

//Vertex* Cube::indexedVertices = nullptr;
//Color* Cube::indexedColors = nullptr;
//GLushort* Cube::indices = nullptr;
//
//int Cube::numVertices = 0;
//int Cube::numColors = 0;
//int Cube::numIndices = 0;

FlyingObjects::FlyingObjects(Mesh* mesh, Texture2D* texture, float X, float Y, float Z, GLfloat rotationSpeed) : SceneObject(mesh, texture)
{
	_rotation = 0;
	_rotationSpeed = rotationSpeed;
	_position.x = X;
	_position.y = Y;
	_position.z = Z;
}


FlyingObjects::~FlyingObjects()
{
}

void FlyingObjects::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indices != nullptr)
	{
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnable(GL_NORMAL_ARRAY);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);		
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);

		DrawMaterial();
		glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.x));
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Diffuse.x));
		glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.x));
		glMaterialfv(GL_FRONT, GL_SHININESS, &(_material->Shininess));

		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);

		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);

		glPopMatrix();

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}

void FlyingObjects::Update()
{
	_rotation += _rotationSpeed;
	_position.z += 0.1f;
	if (_position.z > 10.0f)
	{
		_position.z = -100.0f;
	}
}

void FlyingObjects::DrawMaterial()
{
	_material = new Meterial();
	_material->Ambient.x = 0.8;
	_material->Ambient.y = 0.05;
	_material->Ambient.z = 0.05;
	_material->Ambient.w = 1.0;
	_material->Diffuse.x = 0.8;
	_material->Diffuse.y = 0.05;
	_material->Diffuse.z = 0.05;
	_material->Diffuse.w = 1.0;
	_material->Specular.x = 1.0;
	_material->Specular.y = 1.0;
	_material->Specular.z = 1.0;
	_material->Specular.w = 1.0;
	_material->Shininess = 100.0f;
}

//bool Cube::Load(char* path)
//{
//	std::ifstream inFile;
//	inFile.open(path);
//	if (!inFile.good())
//	{
//		std::cerr << "Error: Cannot open text file " << path << "\n";
//		return false;
//	}
//
//	inFile >> numVertices;
//	indexedVertices = new Vertex[numVertices];
//	for (int i = 0; i < numVertices; i++)
//	{
//		inFile >> indexedVertices[i].x >> indexedVertices[i].y >> indexedVertices[i].z;
//	}
//
//	inFile >> numColors;
//	indexedColors = new Color[numColors];
//	for (int i = 0; i < numColors; i++)
//	{
//		inFile >> indexedColors[i].r >> indexedColors[i].g >> indexedColors[i].b;
//	}
//	   
//	inFile >> numIndices;
//	indices = new GLushort[numIndices];
//	for (int i = 0; i < numIndices; i++)
//	{
//		inFile >> indices[i];
//	}
//
//	inFile.close();
//
//	return true;
//}
