#include <Game.h>

// // Uncomment for Part 2
// // ********************
bool flip = false;
int current = 1;
// // ********************

Game::Game() : window(VideoMode(800, 600), "OpenGL"), 
primatives(2),
m_point1(1.0, 1, -5.0),
m_point2(0, -0, -5.0),
m_point3(1.5, -0.0, -5.0)
{
	// // Uncomment for Part 2
	// // ********************
	index = glGenLists(primatives);
	// // ********************
}


Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	// // Uncomment for Part 2
	// // ********************
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);


	//glNewList(index, GL_COMPILE);
	//glBegin(GL_TRIANGLES);
	//{
	//	glColor3f(0.0f, 0.0f, 1.0f);
	//	glVertex3f(0.0, 2.0, -5.0);
	//	glVertex3f(-2.0, -2.0, -5.0);
	//	glVertex3f(2.0, -2.0, -5.0);
	//}
	//glEnd();
	//glEndList();

	//glNewList(index + 1, GL_COMPILE);
	//glBegin(GL_TRIANGLES);
	//{
	//	glColor3f(0.0f, 1.0f, 0.0f);
	//	glVertex3f(0.2, 0.0, -2.0);
	//	glVertex3f(-2.0, -2.0, -2.0);
	//	glVertex3f(2.0, -2.0, -2.0);
	//}
	glEnd();
	glEndList();

	// // Uncomment for Part 2
	// // ********************
}

void Game::update()
{

	// // Uncomment for Part 2
	// // ********************
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.0005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	// // ********************

	cout << "Update up" << endl;
}

void Game::draw()
{

	// // Uncomment for Part 2
	// // ********************
	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	{
		glVertex3f(m_point1.getX(), m_point1.getY(), m_point1.getZ());
		glVertex3f(m_point2.getX(), m_point2.getY(), m_point2.getZ());
		glVertex3f(m_point3.getX(), m_point3.getY(), m_point3.getZ());

	}
	glEnd();

	////Investigate Here!!!!!
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//{
	//	glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	//{
	//	glTranslatef(0.0010f, 0.0010f, 0.0010f);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	//{
	//	glTranslatef(-0.0010f, -0.0010f, -0.0010f);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	//{
	//	glScalef(1.0001f, 1.0f, 1.0f);
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	//{
	//	glScalef(0.9999f, 1.0f, 1.0f);
	//}

	////up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		m_point1 = m_matrix.rotationX(0.01)*m_point1;
		m_point2 =m_matrix.rotationX(0.01)*m_point2;
		m_point3 =m_matrix.rotationX(0.01)*m_point3;
	}
	//down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		m_point1 = m_matrix.rotationX(-0.01)*m_point1;
		m_point2 = m_matrix.rotationX(-0.01)*m_point2;
		m_point3 = m_matrix.rotationX(-0.01)*m_point3;
	}
	//left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		m_point1 = m_matrix.rotationY(0.01)*m_point1;
		m_point2 = m_matrix.rotationY(0.01)*m_point2;
		m_point3 = m_matrix.rotationY(0.01)*m_point3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		m_point1 = m_matrix.rotationY(-0.01)*m_point1;
		m_point2 = m_matrix.rotationY(-0.01)*m_point2;
		m_point3 = m_matrix.rotationY(-0.01)*m_point3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		m_point1 = m_matrix.rotationZ(1)*m_point1;
		m_point2 = m_matrix.rotationZ(1)*m_point2;
		m_point3 = m_matrix.rotationZ(1)*m_point3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		m_point1 = m_matrix.rotationZ(-1)*m_point1;
		m_point2 = m_matrix.rotationZ(-1)*m_point2;
		m_point3 = m_matrix.rotationZ(-1)*m_point3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		m_point1 = m_matrix.scale(1.001,0.0001)*m_point1;
		m_point2 = m_matrix.scale(1.0, 0.0001)*m_point2;
		m_point3 = m_matrix.scale(1.0, 0.0001)*m_point3;
	}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//{
	//	m_point1 = m_matrix.translate(0.5,0.5)*m_point1;
	//	m_point2 = m_matrix.translate(0.5,0.5)*m_point2;
	//	m_point3 = m_matrix.translate(0.5,0.5)*m_point3;
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//{
	//	m_point1 = m_matrix.translate(-0.5, -0.5)*m_point1;
	//	m_point2 = m_matrix.translate(-0.5, -0.5)*m_point2;
	//	m_point3 = m_matrix.translate(-0.5, -0.5)*m_point3;
	//}

	//moves triangles to the right

	cout << "Drawing Primative " << current << endl;
	glCallList(current);
	// // Uncomment for Part 2
	// // ********************

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

