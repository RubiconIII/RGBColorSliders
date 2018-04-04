//RGB Color Sliders
//by Curtis Hohl
//3/31/18

#include <GL/glut.h>

void init();
void display();

float rx = 200.0, ry = 100.0;
float gx = 200.0, gy = 75.0;
float bx = 200.0, by = 50.0;
float r = .5, g = .5, b = .5;

void sliderMove(float x, float y) {
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(15.0);

	glColor3f(1.0, 0.0, 0.0);
	sliderMove(rx, ry);

	glColor3f(0.0, 1.0, 0.0);
	sliderMove(gx, gy);

	glColor3f(0.0, 0.0, 1.0);
	sliderMove(bx, by);

	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	glVertex2f(0, 300);
	glVertex2f(400, 300);
	glVertex2f(400, 125);
	glVertex2f(0, 125);
	glEnd();

	glFlush();
}

void keyboardFunc(unsigned char Key, int x, int y) {
	switch (Key) {
	case 'q':
		rx -= 10;
		r -= .1;
		display();
		break;
	case 'w':
		rx += 10;
		r += .1;
		display();
		break;
	case 'a':
		gx -= 10;
		g -= .1;
		display();
		break;
	case 's':
		gx += 10;
		g += .1;
		display();

		break;
	case 'z':
		bx -= 10;
		b -= .1;
		display();
		break;
	case 'x':
		bx += 10;
		b += .1;
		display();
		break;
	};
}


int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("RGB Color Sliders");

	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboardFunc);

	glutMainLoop();

	return 0;
}