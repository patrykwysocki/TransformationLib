#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "MyMatrix3D.h"
#include "MyVector3D.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	// // Uncomment for Part 2
	// // ********************
	const int primatives;

	GLuint index;
	Clock clock;
	Time elapsed;
	MyMatrix3 m_matrix;
	MyVector3D m_point1, m_point2, m_point3;
	float rotationAngle = 0.0f;
	// // ********************
};