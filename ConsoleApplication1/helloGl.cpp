#include "helloGl.h"
#define CAMERASPEED 0.05f

helloGl::helloGl(int argc, char* argv[])
{
	srand(time(NULL));

	InitGL(argc, argv);
	
	InitObjects();

	glutMainLoop();
}
void helloGl::LightingForGame()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();
	_lightData->Ambient.x = 0.9;
	_lightData->Ambient.y = 0.9;
	_lightData->Ambient.z = 0.9;
	_lightData->Ambient.w = 1.0;
	_lightData->Diffuse.x = 0.0;
	_lightData->Diffuse.y = 0.0;
	_lightData->Diffuse.z = 0.0;
	_lightData->Diffuse.w = 1.0;
	_lightData->Specular.x = 0.5;
	_lightData->Specular.y = 0.5;
	_lightData->Specular.z = 0.5;
	_lightData->Specular.w = 1.0;

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.y));
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.z));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.y));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.z));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.y));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.z));

	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->y));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->z));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->w));

	_material = new Material();
	_material->Ambient.x = 1.0;
	_material->Ambient.y = 1.0;
	_material->Ambient.z = 1.0;
	_material->Ambient.w = 1.0;
	_material->Diffuse.x = 0.0;
	_material->Diffuse.y = 0.0;
	_material->Diffuse.z = 0.0;
	_material->Diffuse.w = 0.0;
	_material->Specular.x = 1.0;
	_material->Specular.y = 1.0;
	_material->Specular.z = 1.0;
	_material->Specular.w = 1.0;
	_material->Shininess = 100.0f;

	glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.x));
	glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.y));
	glMaterialfv(GL_FRONT, GL_AMBIENT, &(_material->Ambient.z));
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Diffuse.x));
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Diffuse.y));
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &(_material->Diffuse.z));
	glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.x));
	glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.y));
	glMaterialfv(GL_FRONT, GL_SPECULAR, &(_material->Specular.z));

	glMaterialf(GL_FRONT, GL_SHININESS, _material->Shininess);
}

void helloGl::InitObjects()
{
	Texture2D* texture = new Texture2D();
	texture->LoadTexture("HUMMWV.jpg");
	ObjMesh* objMesh = ModelLoader::Load("HUMMWV.obj");
	
	Vector3 position;
	position.x = 1.0f;
	position.y = 1.0f;
	position.z = 1.0f;

	_player = new Player(objMesh, texture, position);

	Vector3 _flatPos;
	_flatPos.x = -5.0f;
	_flatPos.y = 50.0f;
	_flatPos.z = 1.0f;
	
	Vector3 _whiteHousePos;
	_whiteHousePos.x = -5.0f;
	_whiteHousePos.y = 0.0f;
	_whiteHousePos.z = 15.0f;

	Vector3 _flatPos1;
	_flatPos1.x = -5.0f;
	_flatPos1.y = 1.0f;
	_flatPos1.z = 30.0f;

	Vector3 _whiteHousePos1;
	_whiteHousePos1.x = -5.0f;
	_whiteHousePos1.y = 0.0f;
	_whiteHousePos1.z = 45.0f;

	Vector3 terrainPosition;
	terrainPosition.x = 1.0f;
	terrainPosition.y = -1.0f;
	terrainPosition.z = 1.0f;

	Texture2D* textureTerrain = new Texture2D();
	textureTerrain->LoadTexture("GDT.tga");

	ObjMesh* objMeshTerrain = ModelLoader::Load("PaulShip.obj");

	for (int i = 0; i < 20; i++)
	{
		Vector3 _randomPosition;
		_randomPosition.x = rand() % 100; 
		_randomPosition.y = 100.0f;
		_randomPosition.z = rand() % 100;

		_terrain[i] = new Terrain(objMeshTerrain, textureTerrain, Vector3(rand() % 100, 100, rand() % 100));
	}

	Texture2D* textureBody = new Texture2D();
	textureBody->LoadTexture("flat.tga");
	ObjMesh* flatMesh = ModelLoader::Load("flat.obj");
	
	Texture2D* textureWhiteHouse = new Texture2D();
	textureWhiteHouse->LoadTexture("whiteHouse.tga");
	ObjMesh* whiteHouseMesh = ModelLoader::Load("TheWhiteHouse.obj");

	Texture2D* textureRoad = new Texture2D();
	textureRoad->LoadTexture("road.png");
	ObjMesh* roadMesh = ModelLoader::Load("road.obj");

	bodyFlat = new SceneNode(flatMesh, textureBody);
	bodyFlat->SetParentPosition(_flatPos);
	
	bodyFlat1 = new SceneNode(flatMesh, textureBody);
	bodyFlat1->SetChildPositionWS(_flatPos1);
	bodyFlat->AddChild(bodyFlat1);
	
	whiteHouse = new SceneNode(whiteHouseMesh, textureWhiteHouse);
	whiteHouse->SetChildPositionWS(_whiteHousePos);
	bodyFlat->AddChild(whiteHouse);

	whiteHouse1 = new SceneNode(whiteHouseMesh, textureWhiteHouse);
	whiteHouse1->SetChildPositionWS(_whiteHousePos1);
	bodyFlat->AddChild(whiteHouse1);


	//The camera info is used to set the look down approach with a 45 degree angle
	_camera = new CameraInfo();

	_camera->eye.x = position.x + cos(45) * -10;
	_camera->eye.y = position.y + cos(45) * 3;
	_camera->eye.z = position.z + cos(45) * 0;

							  //Position		//Targert View	Height
	objCamera.Position_Camera(_camera->eye.x, _camera->eye.y, _camera->eye.z,	 0, 1.5f, 0,	0, 1.0f, 0);
	//0, 1.5, 4.0
}

void helloGl::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glEnable(GL_DEPTH_TEST);
	
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glutMotionFunc(GLUTCallbacks::Motion);
	glutMouseFunc(GLUTCallbacks::Mouse);
	
	glEnable(GL_TEXTURE_2D);
	
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0.1, 1000);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);	
		
}

void helloGl::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //This clears the scene so we start a fresh each time 	

	glPushMatrix();
	glTranslatef(objCamera.mView.x, 0.0f, objCamera.mView.z);
	glScalef(0.125f, 0.5f, 0.125f);
	_player->Draw();
	glPopMatrix();

	glPushMatrix();
	glRotatef(10, 0, 1, 0);
	whiteHouse1->Draw();
	glPopMatrix();

	for (int i = 0; i < 20; i++)
	{
		_terrain[i]->Draw();
	}
	Draw_Grid();

	Vector3 v = { 1.0f, 1.0f, 1.0f };

	Colour c = { 1.0f, 0.0f, 0.0f };

	DrawString("WELCOME TO MY SCENE", &v, &c);

	glPushMatrix(); //Drawing a cube

	//bodyFlat->Draw();
	whiteHouse->Draw();
	bodyFlat1->Draw();

	glEnd();
	glPopMatrix();
	
	glFlush(); //Flushes the scene we just drew to the graphics card
	glutSwapBuffers();
}

void helloGl::Update() 
{ 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	_rotation += 0.5f;
	if (_rotation >= 360.0f)
	{
		_rotation = 0.0f;
	}
		
	 _moveShip += 0.0125f;
	for (int i = 0; i < 20; i++)
	{
		_terrain[i]->Update();
		_terrain[i]->Move(Vector3(0.0f, 0.0f, _moveShip));
	}
	//LightingForGame();

	ShowCursor(FALSE); //does not display curosr, Microsoft function

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);


	whiteHouse->GetChildPosition();

	_player->Update();
	_player->GetX();
//	_terrain->Update();

	glutPostRedisplay();
}


void helloGl::Draw_Grid()
{
	for (float i = -500; i <= 500; i += 5)
	{
		glBegin(GL_LINES);
		glColor3ub(150, 190, 150);
		glVertex3f(-500, 0, i);
		glVertex3f(500, 0, i);

		glVertex3f(i, 0, -500);
		glVertex3f(i, 0, 500);
		glEnd();
	}
}

void helloGl::DrawString(const char * text, const Vector3 * position, const Colour * color)
{
	//glScalef(200, 200, 200);

	glPushMatrix();
	
	glDisable(GL_TEXTURE);

	glDisable(GL_LIGHTING);

	glColor3f(1.0 , 0.0 , 0.0);

	glTranslatef(position->x, position->y, position->z);

	glRasterPos2f(0.0f, 0.0f);

	glutBitmapString(GLUT_BITMAP_HELVETICA_18, (unsigned char*)text);

	glEnable(GL_LIGHTING);

	glEnable(GL_TEXTURE);

	glPopMatrix();
}

void helloGl::Keyboard(unsigned char key, int x, int y) //self explained
{
	if (key == 'q')
	{
		objCamera.Mouse_Move(WINDOW_WIDTH, WINDOW_HEIGHT);
	}
	if (key == 'w')
	{
		objCamera.Move_Camera(CAMERASPEED);
	}

	if (key == 'a')
	{

	objCamera.Rotate_Position(-CAMERASPEED);

	}

	if (key == 's')
	{

	objCamera.Move_Camera(-CAMERASPEED);

	}

	if (key == 'd')
	{
		objCamera.Rotate_Position(CAMERASPEED);
	}

	if (key == 'i')
	{
		bodyFlat->MoveParent(Vector3(0.0f, 0.0f, 1.0f));
		whiteHouse->MoveParent(Vector3(0.0f, 0.0f, 1.0f));
		
	}

	if (key == 'e')
	{
		exit(0);
	}

}

void helloGl::Motion(int x, int y) //Here in case I want to use them
{
	
}

void helloGl::Mouse(int button, int state, int x, int y) //Here in case I want to use them
{

}


helloGl::~helloGl()
{

}
