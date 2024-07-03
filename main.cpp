#include <GL/glut.h>
#include <cmath>

using namespace std;
/*
 * OpenGL program to rotate a square on click of left mouse button and stop rotation on click
    of right mouse button
 */

float theta = 0;
float x, y, r = 50;
bool rotationEnabled = false;

void init(){
    gluOrtho2D(-100, 100, -100, 100);
}

void idle(){
    if (rotationEnabled){
        theta += 0.01;
        if (theta > 360)
            theta = 0;
    }
    glutPostRedisplay();
}

void display(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 1);

    x = r * cos(theta * 3.14f / 180);
    y = r * sin(theta * 3.14f/ 180);

    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(-1 * y, x);
    glVertex2f(-1 * x, -1 * y);
    glVertex2f(y, -1 * x);
    glEnd();

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        rotationEnabled = true;
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        rotationEnabled = false;
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600, 600);
    glutCreateWindow("IDLE");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}