#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

int x, y;
float i, j;


void myInit (void)
{
    glClearColor(0.40, 0.45, 0.45, 1.0);
    glColor3f(0.5, 0.2, 0.2);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-780, 780, -420, 420);
}


void display (void)
{
    for (j = 0; j < 10000; j += 0.01)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINES);
        glVertex2f(10,10);
        glVertex2f(100+(150*cos(j)),100+(150*sin(j)));
        glEnd();
        glFlush();
        glBegin(GL_LINES);
        glVertex2f(100+(150*cos(j)),100+(150*sin(j)));
        glVertex2f(100+(150*cos(j))+(70*sin(2*j)),100+(150*sin(j))+(70*cos(2*j)));
        glEnd();
        glFlush();

    }
}


int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1360, 768);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Line Pivot");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}
