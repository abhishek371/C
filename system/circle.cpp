//pk+=pk+2(x(k)+1)+(y(k+1)sq-y(k)sq)-(y(k+1)-y(k))+1

#include<stdio.h>
#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>

double R;

void CircleF()
{

    double x=0;
    double y=R,h=1-R;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    glBegin(GL_POINTS);

    glVertex2d(x,y);
    glVertex2d(y,x);
    glVertex2d(y,-x);
    glVertex2d(x,-y);
    glVertex2d(-x,-y);
    glVertex2d(-y,-x);
    glVertex2d(-y,x);
    glVertex2d(-x,y);


    while(y>x)
    {
        if(h<0)
        h=h+2*x+3;
        else
        {
            h=h+2*(x-y)+5;
            y=y-1;

        }
        x=x+1;

    glVertex2d(x,y);
    glVertex2d(y,x);
    glVertex2d(y,-x);
    glVertex2d(x,-y);
    glVertex2d(-x,-y);
    glVertex2d(-y,-x);
    glVertex2d(-y,x);
    glVertex2d(-x,y);

    }

    glEnd();
    glutSwapBuffers();

}
//p(k+1)=p(k)+2dy-2dx(y(k+1)-y(K))
//p(o)=2dy-dx
void init()
{

    glClearColor(1.0,1.0,1.0,0);
    glColor3f(0.0,1.0,0.0);
    gluOrtho2D(-200,200,-200,200);

}

void reshape(int w, int h)
{
 glViewport(0.0, 0.0, w, h);
}
//p(1k+1)=pk+r(y)sq+2(x(k)+1)r(y)sq+r(x)sq(y(k+1)sq-y(k)sq)-r(x)sq(y(k+1)-y(k))
//p(o)=r(y)sq+r(x)sq/4-r(y)(r(x)sq)
//p(2k+1)=pk+r(x)sq-2(y(k)+1)r(x)sq+r(y)sq(x(k+1)sq-x(k)sq)-r(y)sq(x(k+1)-x(k))

int main(int argc, char **argv)
{

    R = 100;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
     glutCreateWindow("Circle drawing");
    init();
    glutDisplayFunc(CircleF);
    glutIdleFunc(CircleF);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
