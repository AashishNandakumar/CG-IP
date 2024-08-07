/*
 * program 5: 3D transformations on 3D objects (with builtin functions)
 */

#include <GL/glut.h>
#include <iostream>

float tx = 0, ty = 0, tz = 0;
float scale = 1;
float angleX = 0, angleY = 0, angleZ = 0;

void init() {
    glClearColor(0, 0, 0, 0);
    gluOrtho2D(-1, 1, -1, 1);
    glEnable(GL_DEPTH_TEST);
}

void drawCube() {
    glBegin(GL_QUADS);

    // front face
    glColor3f(1, 0, 0);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);

    // back face
    glColor3f(0, 1, 0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);

    // left face
    glColor3f(0, 0, 1);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);

    // right face
    glColor3f(1, 1, 0);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);

    // top face
    glColor3f(0, 1, 1);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);

    // bottom face
    glColor3f(1, 0, 1);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, -0.5);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(tx, ty, tz);
    glRotatef(angleX, 1, 0, 0);
    glRotatef(angleY, 0, 1, 0);
    glRotatef(angleZ, 0, 0, 1);
    glScalef(scale, scale, scale);

    drawCube();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'u':
            tx += 0.1;
            break;
        case 'U':
            tx -= 0.1;
            break;
        case 'v':
            ty += 0.1;
            break;
        case 'V':
            ty -= 0.1;
            break;
        case 't':
            tz += 0.1;
            break;
        case 'T':
            tx -= 0.1;
            break;
        case 's':
            scale += 0.1;
            if (scale > 2.0)scale = 2.0;
            break;
        case 'S':
            scale -= 0.1;
            if (scale < 0.1) scale = 0.1;
            break;
        case 'x':
            angleX += 5;
            break;
        case 'X':
            angleX -= 5;
            break;
        case 'y':
            angleY += 5;
            break;
        case 'Y':
            angleY -= 5;
            break;
        case 'z':
            angleZ += 5;
            break;
        case 'Z':
            angleZ -= 5;
            break;
        case 27:
            exit(0);
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(400, 200);
    glutCreateWindow("Basic 3D operations on a 3D object");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}

