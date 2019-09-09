#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include<math.h>
using namespace std;

int pntX1, pntY1, r;
double angle,angle1,final_angle;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x+pntX1, y+pntY1);
    glEnd();
}


void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void midPointCircleAlgo()
{
    int x = 0;
    int y = r;
    float decision = 5/4 - r;
    plot(x, y);
    int height = r*cos(final_angle);
    while (y> height)
    {
        if (decision < 0)
        {
            x++;
            decision += 2*x+1;
        }
        else
        {
            y--;
            x++;
            decision += 2*(x-y)+1;
        }
        plot(-x, y);
    }
    x=0,y=r,decision=5/4-r;
    while (y> x)
    {
        if (decision < 0)
        {
            x++;
            decision += 2*x+1;
        }
        else
        {
            y--;
            x++;
            decision += 2*(x-y)+1;
        }
        plot(x, y);
        if(angle>90)
            plot(y,x);
        if(angle>135 and angle<180)
            plot(y,-x);
    }
}

void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(1.0);

    midPointCircleAlgo();

    glFlush ();
}

int main(int argc, char** argv)
{
    cout << "Enter the coordinates of the center:\n\n" << endl;

    cout << "X-coordinate   : "; cin >> pntX1;
    cout << "\nY-coordinate : "; cin >> pntY1;
    cout << "\nEnter radius : "; cin >> r;
    cout << " \n Enter the angle:" << endl;  cin>>angle;
    int i;
    for(i=0;i<10;i++){
        if(i*45>angle)
            break;
    }
    i--;
    angle1=angle-(i*45);
    final_angle = angle1*0.01744;


    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1024, 768);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("Angle Arc Algorithm");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
    return 0;

}
