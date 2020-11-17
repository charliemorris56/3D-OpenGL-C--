#include "HelloGL.h"

//Vertex HelloGL::vertices[] = { 1, 1, 1,  -1, 1, 1,  -1,-1, 1,      // v0-v1-v2 (front)
//				-1,-1, 1,   1,-1, 1,   1, 1, 1,      // v2-v3-v0
//
//				1, 1, 1,   1,-1, 1,   1,-1,-1,      // v0-v3-v4 (right)
//				1,-1,-1,   1, 1,-1,   1, 1, 1,      // v4-v5-v0
//
//				1, 1, 1,   1, 1,-1,  -1, 1,-1,      // v0-v5-v6 (top)
//				-1, 1,-1,  -1, 1, 1,   1, 1, 1,      // v6-v1-v0
//
//				-1, 1, 1,  -1, 1,-1,  -1,-1,-1,      // v1-v6-v7 (left)
//				-1,-1,-1,  -1,-1, 1,  -1, 1, 1,      // v7-v2-v1
//
//				-1,-1,-1,   1,-1,-1,   1,-1, 1,      // v7-v4-v3 (bottom)
//				1,-1, 1,  -1,-1, 1,  -1,-1,-1,      // v3-v2-v7
//
//				1,-1,-1,  -1,-1,-1,  -1, 1,-1,      // v4-v7-v6 (back)
//				-1, 1,-1,   1, 1,-1,   1,-1,-1 };    // v6-v5-v4
//
//Color HelloGL::colors[] = { 1, 1, 1,   1, 1, 0,   1, 0, 0,      // v0-v1-v2 (front)
//				1, 0, 0,   1, 0, 1,   1, 1, 1,      // v2-v3-v0
//
//				1, 1, 1,   1, 0, 1,   0, 0, 1,      // v0-v3-v4 (right)
//				0, 0, 1,   0, 1, 1,   1, 1, 1,      // v4-v5-v0
//
//				1, 1, 1,   0, 1, 1,   0, 1, 0,      // v0-v5-v6 (top)
//				0, 1, 0,   1, 1, 0,   1, 1, 1,      // v6-v1-v0
//
//				1, 1, 0,   0, 1, 0,   0, 0, 0,      // v1-v6-v7 (left)
//				0, 0, 0,   1, 0, 0,   1, 1, 0,      // v7-v2-v1
//
//				0, 0, 0,   0, 0, 1,   1, 0, 1,      // v7-v4-v3 (bottom)
//				1, 0, 1,   1, 0, 0,   0, 0, 0,      // v3-v2-v7
//
//				0, 0, 1,   0, 0, 0,   0, 1, 0,      // v4-v7-v6 (back)
//				0, 1, 0,   0, 1, 1,   0, 0, 1 };    // v6-v5-v4
//
//Vertex HelloGL::indexedVertices[] = { 1, 1, 1,  -1, 1, 1,  // v0,v1,
//				-1,-1, 1,   1,-1, 1,   // v2,v3
//				1,-1,-1,   1, 1,-1,    // v4,v5
//				-1, 1,-1,   -1,-1,-1 }; // v6,v7
//
//Color HelloGL::indexedColors[] = { 1, 1, 1,   1, 1, 0,   // v0,v1,
//				1, 0, 0,   1, 0, 1,   // v2,v3
//				0, 0, 1,   0, 1, 1,   // v4,v5
//				0, 1, 0,   0, 0, 0 }; //v6,v7
//
//GLushort HelloGL::indices[] = { 0, 1, 2,  2, 3, 0,      // front
//				0, 3, 4,  4, 5, 0,      // right
//				0, 5, 6,  6, 1, 0,      // top
//				1, 6, 7,  7, 2, 1,      // left
//				7, 4, 3,  3, 2, 7,      // bottom
//				4, 7, 6,  6, 5, 4 };    // back


HelloGL::HelloGL(int argc, char* argv[])
{	
	InitGL(argc, argv);	
	InitObject();
	
	InitLighting();

	glutMainLoop();
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//DrawPolygon();
	//DrawCube();
	//DrawCubeArray();
	//DrawCubeIndexed();
	for (int i = 0; i < 201; i++)
	{
		objects[i]->Draw();
	}
		
	glFlush();
	glutSwapBuffers();
}

//void HelloGL::DrawPolygon()
//{
//	/*glPushMatrix();
//	glTranslatef(0.0f, 0.0f, -5.0f);
//	glRotatef(rotationTriangle, 0.0f, 1.0f, 0.0f);
//	glBegin(GL_POLYGON); //Tringle
//	{
//		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
//		glVertex2f(-0.75, 0.0);
//		glVertex2f(0.0, 0.5);
//		glColor4f(1.0f, 0.0f, 1.0f, 0.0f);
//		glVertex2f(0.75, 0.0);
//		glEnd();
//	}
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.0f, 0.0f, -5.0f);
//	glRotatef(rotationSquare, 1.0f, 0.0f, 0.0f);
//	glBegin(GL_POLYGON); //Square
//	{
//		glColor4f(0.0f, 1.0f, 0.0f, 0.0f);
//		glVertex2f(0.0, 0.5);
//		glVertex2f(-0.5, 0.5);
//		glColor4f(0.0f, 1.0f, 1.0f, 0.0f);
//		glVertex2f(-0.5, 0.0);
//		glVertex2f(0.0, 0.0);
//		glEnd();
//	}
//	glPopMatrix();
//
//	glPushMatrix();
//	glRotatef(rotationSquare, 1.0f, 0.2f, -0.1f);
//	glutWireCube(0.5f);
//	glPopMatrix();*/
//}

void HelloGL::Update()
{
	glLoadIdentity();

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));

	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);

	for (int i = 0; i < 201; i++)
	{
		objects[i]->Update();
	}
	
	glutPostRedisplay();
	//rotationTriangle += 0.05f;
	//
	//rotationSquare -= 0.15f;
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	//if (key == 't')
	//{
	//	rotationTriangle += 0.5f;
	//}
	//else if (key == 'y')
	//{
	//	rotationTriangle -= 0.5f;
	//}

	//if (key == 'q')
	//{
	//	rotationSquare += 0.5f;
	//}
	//else if (key == 'e')
	//{
	//	rotationSquare -= 0.5f;
	//}

	if (key == 'w')
	{
		camera->eye.y += 0.1f;
	}
	else if (key == 's')
	{
		camera->eye.y -= 0.1f;
	}	
	else if (key == 'a')
	{
		camera->eye.x += 0.1f;
	}
	else if (key == 'd')
	{
		camera->eye.x -= 0.1f;
	}
	else if (key == 'r')
	{
		_lightData->Ambient.x = 100.0;
		_lightData->Ambient.y = 0.2;
		_lightData->Ambient.z = 0.2;
	}
	else if (key == 'g')
	{
		_lightData->Ambient.x = 0.2;
		_lightData->Ambient.y = 100.0;
		_lightData->Ambient.z = 0.2;
	}
	else if (key == 'b')
	{
		_lightData->Ambient.x = 0.2;
		_lightData->Ambient.y = 0.2;
		_lightData->Ambient.z = 100.0;
	}
}

void HelloGL::InitObject()
{
	//Rotation initialising
	/*rotationTriangle = 0.0f;
	rotationSquare = 0.0f;*/

	//Camera setup 
	camera = new Camera();
	camera->eye.x = 0.0f;
	camera->eye.y = 0.0f;
	camera->eye.z = 1.0f;
	/*camera->eye.x = 5.0f;
	camera->eye.y = 5.0f;
	camera->eye.z = -5.0f;*/
	camera->center.x = 0.0f;
	camera->center.y = 0.0f;
	camera->center.z = 0.0f;
	camera->up.x = 0.0f;
	camera->up.y = 1.0f;
	camera->up.z = 0.0f;

	Texture2D* texture = new Texture2D();
	Texture2D* texture2 = new Texture2D();
	texture->Load((char*)"stars.raw", 515, 512);
	texture2->Load((char*)"stars2.raw", 515, 512);

	//Cube::Load((char*)"cube.txt");
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube3.txt");
	Mesh* pyramidMesh = MeshLoader::Load((char*)"cube3.txt");

	for (int i = 0; i < 200; i++)
	{
		objects[i] = new FlyingObjects(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f, (rand() % 360) / 100.0f);
	}
	objects[200] = new StaticObjects(pyramidMesh, texture2, 1.0f, 1.0f, -10.0f);
}

void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Programming");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800); //Set the viewport to be the entire window
	gluPerspective(45, 1, 0.1, 1000); //Set the correct perspective
	glMatrixMode(GL_MODELVIEW);

	//Culling
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void HelloGL::InitLighting()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;
	
	_lightData = new Lighting();
	_lightData->Ambient.x = 0.2;
	_lightData->Ambient.y = 0.2;
	_lightData->Ambient.z = 0.2;
	_lightData->Ambient.w = 1.0;
	_lightData->Diffuse.x = 0.8;
	_lightData->Diffuse.y = 0.8;
	_lightData->Diffuse.z = 0.8;
	_lightData->Diffuse.w = 1.0;
	_lightData->Specular.x = 0.2;
	_lightData->Specular.y = 0.2;
	_lightData->Specular.z = 0.2;
	_lightData->Specular.w = 1.0;
}

//void HelloGL::DrawCube()
//{
//
//	glBegin(GL_TRIANGLES);
//	// face v0-v1-v2
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 1, 1);
//	glColor3f(1, 1, 0);
//	glVertex3f(-1, 1, 1);
//	glColor3f(1, 0, 0);
//	glVertex3f(-1, -1, 1);
//	// face v2-v3-v0
//	glColor3f(1, 0, 0);
//	glVertex3f(-1, -1, 1);
//	glColor3f(1, 0, 1);
//	glVertex3f(1, -1, 1);
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 1, 1);
//	// face v0-v3-v4
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 1, 1);
//	glColor3f(1, 0, 1);
//	glVertex3f(1, -1, 1);
//	glColor3f(0, 0, 1);
//	glVertex3f(1, -1, -1);
//	// face v4-v5-v0
//	glColor3f(0, 0, 1);
//	glVertex3f(1, -1, -1);
//	glColor3f(0, 1, 1);
//	glVertex3f(1, 1, -1);
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 1, 1);
//	// face v0-v5-v6
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 1, 1);
//	glColor3f(0, 1, 1);
//	glVertex3f(1, 1, -1);
//	glColor3f(0, 1, 0);
//	glVertex3f(-1, 1, -1);
//	// face v6-v1-v0
//	glColor3f(0, 1, 0);
//	glVertex3f(-1, 1, -1);
//	glColor3f(1, 1, 0);
//	glVertex3f(-1, 1, 1);
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 1, 1);
//	// face  v1-v6-v7
//	glColor3f(1, 1, 0);
//	glVertex3f(-1, 1, 1);
//	glColor3f(0, 1, 0);
//	glVertex3f(-1, 1, -1);
//	glColor3f(0, 0, 0);
//	glVertex3f(-1, -1, -1);
//	// face v7-v2-v1
//	glColor3f(0, 0, 0);
//	glVertex3f(-1, -1, -1);
//	glColor3f(1, 0, 0);
//	glVertex3f(-1, -1, 1);
//	glColor3f(1, 1, 0);
//	glVertex3f(-1, 1, 1);
//	// face v7-v4-v3
//	glColor3f(0, 0, 0);
//	glVertex3f(-1, -1, -1);
//	glColor3f(0, 0, 1);
//	glVertex3f(1, -1, -1);
//	glColor3f(1, 0, 1);
//	glVertex3f(1, -1, 1);
//	// face v3-v2-v7
//	glColor3f(1, 0, 1);
//	glVertex3f(1, -1, 1);
//	glColor3f(1, 0, 0);
//	glVertex3f(-1, -1, 1);
//	glColor3f(0, 0, 0);
//	glVertex3f(-1, -1, -1);
//	// face v4-v7-v6
//	glColor3f(0, 0, 1);
//	glVertex3f(1, -1, -1);
//	glColor3f(0, 0, 0);
//	glVertex3f(-1, -1, -1);
//	glColor3f(0, 1, 0);
//	glVertex3f(-1, 1, -1);
//	// face v6-v5-v4
//	glColor3f(0, 1, 0);
//	glVertex3f(-1, 1, -1);
//	glColor3f(0, 1, 1);
//	glVertex3f(1, 1, -1);
//	glColor3f(0, 0, 1);
//	glVertex3f(1, -1, -1);
//	glEnd();
//}
//
//void HelloGL::DrawCubeArray()
//{
//
//	glPushMatrix();
//
//	glBegin(GL_TRIANGLES);
//	for (int i = 0; i < 36; i++)
//	{
//		glColor3fv(&colors[i].r);
//		glVertex3fv(&vertices[i].x);		
//	}
//	glEnd();
//
//	glPopMatrix();
//}
//

//void HelloGL::DrawCubeIndexed()
//{
//	glPushMatrix();
//
//	glBegin(GL_TRIANGLES);
//	for (int i = 0; i < 36; i++)
//	{
//		glColor3f(indexedColors[indices[i]].r, indexedColors[indices[i]].g, indexedColors[indices[i]].b);
//		glVertex3f(indexedVertices[indices[i]].x, indexedVertices[indices[i]].y, indexedVertices[indices[i]].z);
//	}
//	glEnd();
//
//	glPopMatrix();
//}


HelloGL::~HelloGL(void)
{
	delete camera;
	camera = NULL;
	for (int i = 0; i < 201; i++)
	{
		delete objects[i];
		objects[i] = NULL;
	}
}