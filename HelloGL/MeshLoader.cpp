#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	//void LoadColours(ifstream& inFile, Mesh& mesh);
	void LoadNormals(ifstream& inFile, Mesh& mesh);
	void LoadTexCoord(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);

	//LOAD VERTICES
	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x >> mesh.Vertices[i].y >> mesh.Vertices[i].z;
				//std::cout << mesh.VertexCount << mesh.Vertices[i].x << mesh.Vertices[i].y << mesh.Vertices[i].z << "\n";
			}
		}
	}

	////LOAD COLOURS
	//void LoadColours(ifstream& inFile, Mesh& mesh)
	//{ 
	//	inFile >> mesh.ColorCount;
	//	mesh.Colors = new Color[mesh.ColorCount];
	//	for (int i = 0; i < mesh.ColorCount; i++)
	//	{
	//		inFile >> mesh.Colors[i].r >> mesh.Colors[i].g >> mesh.Colors[i].b;
	//		//cout << mesh.ColorCount << mesh.Colors[i].r << mesh.Colors[i].g << mesh.Colors[i].b << "\n";
	//	}
	//}

	//LOAD NORMALS
	void LoadNormals(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.NormalCount;
		mesh.Normals = new Vector3[mesh.NormalCount];
		for (int i = 0; i < mesh.NormalCount; i++)
		{
			inFile >> mesh.Normals[i].x >> mesh.Normals[i].y >> mesh.Normals[i].z;
		}
	}

	//Load TexCoord
	void LoadTexCoord(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.TexCoordCount;
		mesh.TexCoords = new TexCoord[mesh.TexCoordCount];
		for (int i = 0; i < mesh.TexCoordCount; i++)
		{
			inFile >> mesh.TexCoords[i].u >> mesh.TexCoords[i].v;
		}
	}

	//Load Indices
	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{		
		inFile >> mesh.IndexCount;
		mesh.Indices = new GLushort[mesh.IndexCount];
		for (int i = 0; i < mesh.IndexCount; i++)
		{
			inFile >> mesh.Indices[i];
			//std::cout << mesh.IndexCount << mesh.Indices[i];
		}
	}

	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}

		LoadVertices(inFile, *mesh);
		//LoadColours(inFile, *mesh);
		LoadTexCoord(inFile, *mesh);
		LoadNormals(inFile, *mesh);		
		LoadIndices(inFile, *mesh);

		return mesh;
	}
}