#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

double X1,Y1,X2,Y2;

void lineF()
{

    double dx=(X2-X1);
    double dy = (Y2-Y1);
    double steps;
    float xInc,yInc,x=X1,y=Y1;
    steps = ( abs(dx) > abs(dy)? abs(dx) : abs(dy));
    xInc = dx/(float)steps;
    yInc = dy/(float)steps;

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POINTS);
    glVertex2d(x,y);
    int k;
    for(k=0;k<steps;k++)
    {

        x+=xInc;
        y+=yInc;
        glVertex2d(x,y);
    }

    glEnd();

    glutSwapBuffers();

}
void init()
{

    glClearColor(1.0,1.0,1.0,0);    //white
    glColor3f(1.0,0.0,0.0);     //Black
    gluOrtho2D(0,640,0,480);

}

void reshape(int w, int h)
{
 glViewport(0.0, 0.0, w, h);
}

int main(int argc, char **argv)
{

    X1 = 100;
    Y1 = 100;
    X2 = 500;
    Y2 = 500;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
 glutInitWindowPosition(100, 100);
     glutCreateWindow("DDA_Line");
    init();
    glutDisplayFunc(lineF);
    glutIdleFunc(lineF);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

