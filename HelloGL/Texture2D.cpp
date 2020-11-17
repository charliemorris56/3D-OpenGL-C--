#include "Texture2D.h"

#include <iostream>
#include <string>
#include <streambuf>

using namespace std;

Texture2D::Texture2D()
{
	this->_ID = 0;
	this->_height = 0;
	this->_width = 0;
}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &_ID);
}

bool Texture2D::Load(char* path, int width, int height)
{
	//char* tempTextureData = nullptr;
	//int fileSize;
	ifstream inFile;
	_width = width;
	_height = height;

	//debug
	std::string* ptrStrBuff;

	inFile.open(path, ios::binary);

	if (!inFile.good())
	{
		cerr << "Can't open texture file " << path << endl;
		return false;
	}

	//inFile.seekg(0, ios::end);
	//fileSize = static_cast<int>(inFile.tellg());
	//tempTextureData = new char[fileSize];
	//inFile.seekg(0, ios::beg);
	//inFile.read(tempTextureData, fileSize);
	ptrStrBuff = new std::string(std::istreambuf_iterator<char>(inFile), std::istreambuf_iterator<char>());
	inFile.close();

	glGenTextures(1, &_ID);
	glBindTexture(GL_TEXTURE_2D, _ID);
	//glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, ptrStrBuff->c_str()); 
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, _width, _height, GL_RGB, GL_UNSIGNED_BYTE, ptrStrBuff->c_str());
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//int nTest = gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);

	//delete[] tempTextureData;

	delete ptrStrBuff;
	return true;
}