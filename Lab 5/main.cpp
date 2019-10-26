#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535897932364

void cylinder(GLfloat radius, GLfloat height,GLubyte R, GLubyte G, GLubyte B) {
    GLfloat x = 0.0, y = 0.0, theta = 0.0, step_height = 0.0, step_height_prev = 0.0, increment = PI / 8;
    glColor3ub(R - 255, G - 100, B - 20);
    glBegin(GL_QUAD_STRIP);
    theta = 0.0;
    step_height = height/6;
    step_height_prev = 0.0;
    while (step_height < height) {
        while (theta < 2 * PI) {
            x = radius * cos(theta);
            y = radius * sin(theta);
            glVertex3f(x, y, height);
            glVertex3f(x, y, 0.0);
            theta = theta + increment;
        }
        glVertex3f(radius,0.0,step_height);
        glVertex3f(radius, 0.0, 0.0);
        step_height=step_height+ (height/6);
}
    glVertex3f(radius, 0.0, step_height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();
    glColor3ub(R-255,G-100,B-200);
    glBegin(GL_POLYGON);
    theta = 0.0;
    while( theta < 2*PI ) {
        x = radius * cos(theta);
        y = radius * sin(theta);
        glVertex3f(x, y , height);
        theta = theta + increment;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,-0.5,-3.0);
    glRotatef(-60, 1.0, 0.0, 0.0);
    cylinder(0.4, 1.2, 255, 160, 100);
    glFlush();
}
void reshape(int width, int height)
{
    if (width == 0 || height == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)width/(GLdouble)height,0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, width, height);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutCreateWindow("Cylinder");
    glClearColor(1.0,1.0,1.0,0.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}