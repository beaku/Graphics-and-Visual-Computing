////
//// Created by beaku on 14/10/19.
////
//#include <math.h>
//#include <GL/glut.h>
//
//#define PI 3.14159265358979323846
//
//#define WIDTH 640
//#define HEIGHT 480
//
//void init();
//void reshape(int, int);
//void display();
//
////Specifies the radius of the circle
//static int radius = 2;
//
//int main(int argc, char **argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
//    glutInitWindowSize(WIDTH, HEIGHT);
//    glutInitWindowPosition(50, 50);
//    glutCreateWindow("OpenGL - Draw Circle");
//    init();
//    glutReshapeFunc(reshape);
//    glutDisplayFunc(display);
//    glutMainLoop();
//
//    return 0;
//}
//
//void init()
//{
//    glEnable(GL_DEPTH_TEST);
//    glCullFace(GL_BACK);
//    glEnable(GL_CULL_FACE);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100000.0f);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    glClearColor(1.0, 1.0, 1.0, 0.0);
//}
//
//void reshape(int w, int h)
//{
//    glViewport(0, 0, (GLsizei)WIDTH, (GLsizei)HEIGHT);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 100000.0f);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glPushMatrix();
//    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//    glPushMatrix();
//    glColor3f(0.2, 0.3, 0.5);  //Some type of blue
//    //Draw Circle
//    glBegin(GL_POLYGON);
//    for(double i = 0; i < 2 * PI; i += PI / 30) //<-- Change this Value
//        glVertex3f(cos(i) * radius, sin(i) * radius, 0.0);
//    glEnd();
//    //Draw Circle
//    glPopMatrix();
//    glPopMatrix();
//    glFlush();
//    glutSwapBuffers();
//}
//
//
