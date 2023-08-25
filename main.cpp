#include<math.h>
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<stdio.h>
float cx=0;// declare cx as globally
//inti() -> color,axis(prepare the console)
void init()
{
    glClearColor(0,0,0,0);//R,G,B,Alpha-> intensity of color
    glOrtho(-10,+10,-10,+10,-5,+5);//xleft ,xright,y bottom,y top,z
}

void points()
{
    glBegin(GL_POINTS);//start -.Works with gl point
    glVertex2d(-5,3);
    glVertex2d(5,3);
    glVertex2d(5,-3);
    glVertex2d(-5,-3);
    glEnd();//end
}

void lines()
{
    glBegin(GL_LINES);//start -.Works with gl line
    glVertex2d(7,-1);
    glVertex2d(0,-1);

    glVertex2d(0,-1);
    glVertex2d(0,1);

    glVertex2d(0,1);
    glVertex2d(-7,1);
    glEnd();//end
}

void triangle()
{
    glBegin(GL_LINE_LOOP);
    glVertex2d(0,1);
    glVertex2d(-5,-3);
    glVertex2d(5,-3);
    glEnd();
}
void rectangle()
{
    glBegin(GL_LINE_LOOP);
    glVertex2d(8,3);
    glVertex2d(-8,3);
    glVertex2d(-8,-3);
    glVertex2d(8,-3);
    glEnd();
}
void glTriangle()
{
    glBegin(GL_POLYGON);

    glColor3d(0.50,0.40,0.23);
    glVertex2d(3,3);
    glColor3d(0.30,0.20,0.10);
    glVertex2d(3,4);
    glColor3d(0.90,0.80,0.56);
    glVertex2d(-3,4);
    glColor3d(0.10,0.78,0.39);
    glVertex2d(-3,3);
     glColor3d(0.10,0.78,0.39);
    glVertex2d(-5,3);
     glColor3d(0.10,0.78,0.39);
    glVertex2d(-5,0);
     glColor3d(0.56,0.28,0.71);
    glVertex2d(5,0);
    glColor3d(0.23,0.82,0.98);
    glVertex2d(5,3);
    glEnd();
}
void circle(float r1, float r2)
{
    float angle=0.0;
    float x,y;
    int i;
    glColor3f(1,0,1);
    glBegin(GL_POLYGON);
    for(i=0; i<500; i++)
    {
        angle=(360*i)/500;
        x=r1*cos(angle);
        y=r2*sin(angle);
        glVertex2d(x,y);
    }
    glEnd();
}
void square() {
    glBegin(GL_QUADS);//Square shape 4 points-quads
    glVertex2d(1,0);
    glVertex2d(1,1);
    glVertex2d(0,1);
    glVertex2d(0,0);
    glEnd();

}

//How to draw line in backEnd

void directLINE(){
    float  x1=-7,y1=-4,x2=7,y2=4,m,c;
    m=(y2-y1)/(x2-x1);
    c=y1-m*x1;
//when m is less or equal to 1
//x1,y1>go to lower point to upper point
    if(m<=1){
            while(x1<=x2){
            x1=x1+0.001;
            y1=(m*x1)+c;
            glBegin(GL_POINTS);
                glVertex2d(x1,y1);
            glEnd();

            }
//when m is greater or equal to 1
    }else{
         while(y1<=y2){
        y1=y1+0.001;
        x1=(y1-c)/m;
         glBegin(GL_POINTS);
            glVertex2d(x1,y1);
        glEnd();

         }
    }

}
//Digital Differential Analyzer-DDA
void dda(){
      float  x1=-7,y1=-4,x2=7,y2=4,m,c,dx=0.001;
    m=(y2-y1)/(x2-x1);
    c=y1-m*x1;
    float change;
    printf("m=%f ,c=%f\n",m,c);
    if(m<=1){
            change=m * dx;
         while(x1<=x2){
            x1=x1+dx;
            y1=y1+change;//as  x1=1 so we do  not multiply m multiply 1
             glBegin(GL_POINTS);
                glVertex2d(x1,y1);
            glEnd();
         }


    }else{
        change=dx/m;
          while(y1<=y2){
        y1=y1+dx;
        x1=x1+change;
         glBegin(GL_POINTS);
            glVertex2d(x1,y1);
        glEnd();

         }
    }
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);//Enable the background color

    //points();
    //lines();
    //triangle();
    //rectangle();
    //circle(3,3);
    // circle(-3,-3);

cx+=0.01;
if(cx>=15.5)
    cx=-15.5;
glPushMatrix();
glTranslated(cx,0,0);//motion
        glTriangle();

    glPushMatrix();
        glScaled(0.45,0.45,1);//define object size ->multiply ,
        glTranslated(4,0,0);//object transfer
        circle(3,3);
    glPopMatrix();
    glPushMatrix();
        glScaled(0.45,0.45,1);//define object size ->multiply ,
        glTranslated(-4,0,0);//object transfer
        circle(3,3);
    glPopMatrix();
glPopMatrix();

/*
     glPushMatrix();
        circle(3,3);
    glPopMatrix();

    glPushMatrix();
        glScaled(4,3,0);
        glTranslated(0.5,0.5,1);
        circle(3,3);
    glPopMatrix();
*/
   // directLINE();
   //dda();
    glutPostRedisplay();//car motion
    glFlush();//2d use
    //glutSwapBuffers();//3d use

}


int main()
{
    glutInitWindowSize(800,800);//Window size
    glutInitWindowPosition(50,-20);//X axis ,y axis
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE );//Display color| 2D Use

    glutCreateWindow("GLUT Shapes");//Console name

    init();//program define function
    glutDisplayFunc(myDisplay);//my display is a user define function
    glutMainLoop();//Hold the console

    return 0;
}

