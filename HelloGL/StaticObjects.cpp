#include "StaticObjects.h"

StaticObjects::StaticObjects(Mesh* mesh, Texture2D* texture, float X, float Y, float Z) : SceneObject(mesh, texture)
{
	_position.x = X;
	_position.y = Y;
	_position.z = Z;
}

StaticObjects::~StaticObjects()
{
}

void StaticObjects::Draw()
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

		glPushMatrix();

		glTranslatef(_position.x, _position.y, _position.z);

		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indices);

		glPopMatrix();

		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
	}
}

void StaticObjects::Update()
{
	if (GetCursorPos(&p))
	{
		//cursor position now in p.x and p.y
		float px = p.x;
		float pxx = (px - 500) / 100;
		float py = p.y;
		float pyy = 10 - (py / 100);
				
		_position.x = pxx;
		_position.y = pyy - 5;
	}
}

void StaticObjects::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'i')
	{
		//_position.x += 1.0f;
		std::cout << "TEST";
	}
	else if (key == 'j')
	{

	}
	else if (key == 'k')
	{

	}
	else if (key == 'l')
	{

	}
}
