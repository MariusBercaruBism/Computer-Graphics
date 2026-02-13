#include "Scene.h"

// Scene constructor, initilises OpenGL
// You should add further variables to need initilised.
Scene::Scene(Input* in)
{
	// Store pointer for input class
	input = in;
	initialiseOpenGL();

	// Other OpenGL / render setting should be applied here.


	// Initialise scene variables

}

void Scene::handleInput(float dt)
{
	// Handle user input
}

void Scene::update(float dt)
{
	//don't attack me now but i looked up the individual rotations for each planet
	//im not sure if they're a 1:1 simulation with these values but should be good enough like this
	sunRot += 5.0f * dt;
	mercuryRot += 100.0f * dt;
	venusRot += 75.0f * dt;
	earthRot += 50.0f * dt;
	marsRot += 40.0f * dt;
	jupiterRot += 20.0f * dt;
	saturnRot += 15.0f * dt;
	uranusRot += 10.0f * dt;
	neptuneRot += 8.0f * dt;

	earthMoonRot += 200.0f * dt;
	neptuneMoon1Rot += 120.0f * dt;
	neptuneMoon2Rot += 90.0f * dt;
	neptuneMoonMoonRot += 300.0f * dt;
}

void Scene::render() {
	//hey, i know we learned lighting this week and i'd love to add shading to each planet
	//but i'll keep the code clean for now and maybe we'll do something with that later okay?
	//also i've no idea how to add elliptical rotations and i don't have much time left sooo i'm scraping that idea

	/*
	update: i just discovered that if i change the eye perspective in gluLookAt i can achieve some semblance of an elliptical rotation
	but this is more obvious when i make planets rotate around the y axis instead of the z axis, so i changed that too
	sorry but they have no visible orbits for now
	*/

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Set the camera
	//i sort of want to give it an isometric look like in tunic
	gluLookAt(18.0f, 15.0f, 18.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Render geometry/scene here -------------------------------------	

	//moving the camera back a bit to fit everything on the screen
	//glTranslatef(0.0f, 0.0f, -30.0f);

	//i grabbed planet colors from https://ohmycolor.app/color-picker/ 

	//sun
	glPushMatrix();
	glRotatef(sunRot, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glutSolidSphere(0.5f, 20, 20);
	glPopMatrix();

	//mercury
	glPushMatrix();
	glRotatef(mercuryRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(1.2f, 0.0f, 0.0f);
	glColor3f(0.752941f, 0.752941f, 0.752941f);
	glutSolidSphere(0.1f, 20, 20);
	glPopMatrix();

	//venus
	glPushMatrix();
	glRotatef(venusRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(2.5f, 0.0f, 0.0f);
	glColor3f(0.980f, 0.519f, 0.911f);
	glutSolidSphere(0.15f, 20, 20);
	glPopMatrix();

	//earth
	glPushMatrix();
	glRotatef(earthRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(4.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glutSolidSphere(0.2f, 20, 20);

	//this segment is for earth's moon
	glPushMatrix();
	glRotatef(earthMoonRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.4f, 0.0f, 0.0f);
	glColor3f(0.8f, 0.8f, 0.8f);
	glutSolidSphere(0.05f, 20, 20);
	glPopMatrix();

	glPopMatrix();

	//mars
	glPushMatrix();
	glRotatef(marsRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(5.6f, 0.0f, 0.0f);
	glColor3f(0.970f, 0.308f, 0.0873f);
	glutSolidSphere(0.17f, 20, 20);
	glPopMatrix();

	//jupiter
	glPushMatrix();
	glRotatef(jupiterRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(7.6f, 0.0f, 0.0f);
	glColor3f(0.800f, 0.600f, 0.400f);
	glutSolidSphere(0.4f, 20, 20);
	glPopMatrix();

	//saturn
	glPushMatrix();
	glRotatef(saturnRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(9.6f, 0.0f, 0.0f);
	glColor3f(0.900f, 0.800f, 0.600f);
	glutSolidSphere(0.35f, 20, 20);
	glPopMatrix();

	//uranus
	glPushMatrix();
	glRotatef(uranusRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(11.2f, 0.0f, 0.0f);
	glColor3f(0.500f, 0.800f, 0.900f);
	glutSolidSphere(0.25f, 20, 20);
	glPopMatrix();

	//neptune
	glPushMatrix();
	glRotatef(neptuneRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(12.8f, 0.0f, 0.0f);
	glColor3f(0.200f, 0.200f, 0.800f);
	glutSolidSphere(0.25f, 20, 20);

	//this segment is for neptune's moons
	glPushMatrix();
	glRotatef(neptuneMoon1Rot, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.5f, 0.0f, 0.0f);
	glColor3f(0.6f, 0.6f, 0.6f);
	glutSolidSphere(0.08f, 20, 20);

	//this is the moon to the neptune moon above
	glPushMatrix();
	glRotatef(neptuneMoonMoonRot, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.25f, 0.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidSphere(0.04f, 20, 20);
	glPopMatrix();

	glPopMatrix();

	//and this is the second moon to neptune
	glPushMatrix();
	glRotatef(neptuneMoon2Rot, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.7f, 0.0f, 0.0f);
	glColor3f(0.7f, 0.7f, 0.7f);
	glutSolidSphere(0.06f, 20, 20);
	glPopMatrix();

	glPopMatrix();

	calculateFPS();

	// End render geometry --------------------------------------

	// Render text, should be last object rendered.
	renderTextOutput();

	// Swap buffers, after all objects are rendered.
	glutSwapBuffers();
}

void Scene::initialiseOpenGL()
{
	//OpenGL settings
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);			// Cornflour Blue Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glClearStencil(0);									// Clear stencil buffer
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	// Blending function
}

// Handles the resize of the window. If the window changes size the perspective matrix requires re-calculation to match new window size.
void Scene::resize(int w, int h)
{
	width = w;
	height = h;
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio = (float)w / (float)h;
	fov = 45.0f;
	nearPlane = 0.1f;
	farPlane = 100.0f;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(fov, ratio, nearPlane, farPlane);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

// Calculates FPS
void Scene::calculateFPS()
{
	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);

	if (time - timebase > 1000) {
		sprintf_s(fps, "FPS: %4.2f", frame * 1000.0 / (time - timebase));
		timebase = time;
		frame = 0;
	}
}

// Compiles standard output text including FPS and current mouse position.
void Scene::renderTextOutput()
{
	// Render current mouse position and frames per second.
	sprintf_s(mouseText, "Mouse: %i, %i", input->getMouseX(), input->getMouseY());
	displayText(-1.f, 0.96f, 1.f, 0.f, 0.f, mouseText);
	displayText(-1.f, 0.90f, 1.f, 0.f, 0.f, fps);
}

// Renders text to screen. Must be called last in render function (before swap buffers)
void Scene::displayText(float x, float y, float r, float g, float b, char* string) {
	// Get Lenth of string
	int j = strlen(string);

	// Swap to 2D rendering
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 5, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Orthographic lookAt (along the z-axis).
	gluLookAt(0.0f, 0.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	// Set text colour and position.
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	// Render text.
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
	}
	// Reset colour to white.
	glColor3f(1.f, 1.f, 1.f);

	// Swap back to 3D rendering.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, ((float)width / (float)height), nearPlane, farPlane);
	glMatrixMode(GL_MODELVIEW);
}
