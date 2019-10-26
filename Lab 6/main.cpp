#include<bits/stdc++.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include<GL/glu.h>
#endif

#include <stdlib.h>

int flag=1;
GLfloat angle,angle2;
int moving,init_x;
float red1=0.10f,green1=0.6f,blue1=0.5f;

/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-15.0, 15.0, -1.0, 20.0, -15.0, 15.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}
void makecylinder(float height,float Base)
{
    GLUquadricObj *qobj;
    qobj = gluNewQuadric();
    /////////////////////////////////////////////////////////////////////////////////////
    glColor3f(red1, green1, blue1);
    glPushMatrix();
    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    gluCylinder(qobj, Base, Base - (0.2 * Base), height, 20, 20);
    glPopMatrix();
}
void drawTree(float height,float Base)
{
    glPushMatrix();
    float angle;
    makecylinder(height, Base);
    glTranslatef(0.0f, height,0.0f);
    height -=height*0.2f;
    Base -=Base*0.3f;
    for(int a=0; a<3; a++)
    {


        angle = 20+((rand()%50));
        if(angle >48)
            angle = -(20+((rand()%50)));
        if (height > 1)
        {
            glPushMatrix();
            if (flag)
                glRotatef(angle, 1.0f, 0.0f, 1.0f);
            else
                glRotatef(angle, 0.0f, 1.0f, 1.0f);
            flag = !flag;
            drawTree(height, Base); //recursive call
            glPopMatrix();

        }
    }
    //Glut.glutSwapBuffers();
    glPopMatrix();
}
static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;
    srand(GLUT_ELAPSED_TIME);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(angle,0,1,0);
    glRotatef(angle2,0,0,1);

    drawTree(4.5f,0.15f);
    glutSwapBuffers();
    glFlush();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 114 ://red
            red1=1.0f;
            blue1=0.0f;
            green1=0.0f;
            break;
        case 103 ://green
            red1=0.0f;
            blue1=0.0f;
            green1=1.0f;
            break;
        case 98 ://blue
            red1=0.0f;
            blue1=1.0f;
            green1=0.0f;
            break;
        case 121 ://yellow
            red1=1.0f;
            blue1=0.0f;
            green1=1.0f;
            break;
        case 'q':
            exit(0);
            break;

    }

    glutPostRedisplay();
}



void mouse(int btn,int state,int x,int y)
{
    if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
    {
        moving=1;
        init_x=x;
    }
    if(btn==GLUT_LEFT_BUTTON&&state==GLUT_UP)
    {
        moving=0;
    }
}
void motion(int x,int y)
{
    if(moving)
    {
        angle=angle+(x-init_x);
        init_x=x;
        glutPostRedisplay();
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000,640);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Fractal Tree 3D");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);


    glutMainLoop();

    return EXIT_SUCCESS;
}