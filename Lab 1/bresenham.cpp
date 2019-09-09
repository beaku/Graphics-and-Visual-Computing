#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float x1,x2,y1,y2;

void display(void)
{

    int dx,dy,p;
    dx = x2-x1;
    dy = y2-y1;
    int x = x1;
    int y = y1;

    p = 2*(dy-dx);

    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();

    while(x<=x2)
    {
        if(p>=1)
        {

            y = y+1;
            p = p+2*dy-2*dx;
        }
        else
        {

            p = p+2*dy;
        }
        x = x+1;

        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    }


    glFlush();
}

void init(void)
{
    glClearColor(0.7,0.7,0.7,0.7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv) {
    printf("Enter the value of Origin X coordinate : ");
    scanf("%f",&x1);
    printf("Enter the value of Origin Y coordinate : ");
    scanf("%f",&y1);
    printf("Enter the value of Final X coordinate : ");
    scanf("%f",&x2);
    printf("Enter the value of Final Y coordinate : ");
    scanf("%f",&y2);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("Bres Line Algo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}