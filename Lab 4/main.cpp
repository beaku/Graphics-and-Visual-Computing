#include <GL/glut.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble base=0.5;
GLdouble height=1.0;
GLdouble height2 = -1.0;
GLint slices =50;
GLint stacks =50;


void displayCone(void)
{

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-4);
    glColor3f(0.2, 0.2, 0.8);
    glRotatef(90,1,0,0);
    glRotatef(xRotated,0.0,0.0,1.0);
    glScalef(1.0,1.0,1.0);


    glutWireCone(base,height,slices,stacks);
    glTranslatef(0,0,2);
    glutWireCone(base,height2,slices,stacks);
    glFlush();
}

void reshapeCone(int x, int y)
{
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0

    gluPerspective(60.0,(GLdouble)x/(GLdouble)y,0.5,20.0);

    glViewport(0,0,x,y);  //Use the whole window for rendering
}

void idleCone(void)
{

    xRotated += 0.01;
    displayCone();
}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,800);
    glutCreateWindow("Dual Cone Rotation");
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    yRotated = 30.0;
    xRotated=30.0;
    zRotated=30.0;
    glClearColor(0.0,0.0,0.0,0.0);
    glutDisplayFunc(displayCone);
    glutReshapeFunc(reshapeCone);
    glutIdleFunc(idleCone);
    glutMainLoop();
    return 0;
}