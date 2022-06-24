#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<math.h>

GLfloat angle1 = 160.0;
GLfloat angle2 = 200.0;
GLfloat angle3 = 200.0;
float m=0;
float mount=0;
float mm=500;
float flag=0;
float flag2=500;
int F=0;
float b2_speed=5;
float ba_posion=0;
int counter=0;
float scale_cloud;
void sceenario(void);
void girl();
void hare_walking();
void cloud();
void circle(GLdouble rad);
void hare();
void hare_sleep();
#define PI 3.1416
void drawLeftCircle()   // the filled one
{
    /**-----------Head------------**/
    glPushMatrix();
    glColor3f(0,.5,0);
    glScalef(.5,.7,.5);
    glTranslatef(110+350,245,1);
    circle(20);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,0);
    glScalef(.5,.7,.5);
    glTranslatef(110+350,245,1);
    circle(5);
    glPopMatrix();
    /**-----------Neck-----------**/
    glPushMatrix();
    glColor3f(0,.5,0);
    glScalef(.5,.7,.5);
    glTranslatef(210+350,180,1);
    glRotatef(20,0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(-70,90,1);
    glVertex3f(-70,50,1);
    glVertex3f(-50,50,1);
    glVertex3f(-50,90,1);
    glEnd();
    glPopMatrix();
    /**-----------Leg1-----------**/
    glPushMatrix();
    glColor3f(0,.7,0);
    glScalef(.5,.7,.5);
    glTranslatef(230+350,110,1);

    glBegin(GL_POLYGON);
    glVertex3f(-80,90,1);
    glVertex3f(-85,70,1);
    glVertex3f(-45,70,1);
    glVertex3f(-50,90,1);
    glEnd();
    glPopMatrix();
    /**-----------LEg2-----------**/
    glPushMatrix();
    glColor3f(0,.7,0);
    glScalef(.5,.7,.5);
    glTranslatef(300+350,110,1);
    //glRotatef(20,0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(-80,90,1);
    glVertex3f(-85,70,1);
    glVertex3f(-45,70,1);
    glVertex3f(-50,90,1);
    glEnd();
    glPopMatrix();
    /**-----------Body-----------------**/
    glPushMatrix();
    float radius = 70;
    float twoPI = 2 * PI;

    glColor3f(0,.5,0);
    glScalef(.5,0.7,.5);
    glTranslatef(200+350,200,1);
    //glTranslatef(550,150,1);
    glRotatef(-90,0,0,1);
    glBegin(GL_TRIANGLE_FAN);

    for (float i = PI; i <= twoPI; i += 0.001)
        glVertex2f((sin(i)*radius), (cos(i)*radius));

    glEnd();
    glPopMatrix();

}

void drawstring(float x, float y, float z, char *string)
{
    char *ct;
    glRasterPos3f(x,y,z);

    for(ct=string; *ct!='\0'; ct++)
    {
        glColor3f(0.0, 0.0, 0.0);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *ct);
    }
}






void myInit(void)
{
    glColor3f(1.0f,0.0f,0.0f);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void sleeping_body2()
{
    glColor3f(0.0,0.5,0.1);
    glLineWidth(4.0);
    glPushMatrix();
       glScalef(.15,.15,.15);
    //glTranslatef(220, 200, 0);
    //glTranslatef(1250, 650, 0);
    glTranslatef(200-m*6.68, 2050, 0);
//glTranslatef(1300, 600, 0);
//glTranslatef(1300, 600, 0);
    glRotatef( 70, 0, 0, 1);

    glBegin(GL_LINE_LOOP);
        glVertex2i(40, 10);
        glVertex2i(0, 0);
        glVertex2i(-40, 10);
        glVertex2i(-40, 160);
        glVertex2i(-10, 180);
        glVertex2i(60, 180);
        glVertex2i(20, 100);
        glVertex2i(60, 60);
    glEnd();
    glPopMatrix();

    /**------------------------------Body Starts---------------------------**/

    //glViewport(1000,100,500,500);
    glColor3f(0.7,.2,0);
    glPushMatrix();
    glScalef(.15,.15,.15);
    glTranslatef(120-m*6.68, 2400, 0);
    glRotatef( 70+190, 0, 0, 1);

    //glTranslatef(1000, 500, 0);
    glBegin(GL_POLYGON);
        glVertex2i(400, 300);
        glVertex2i(310, 370);
        glVertex2i(280, 400);  //(x,y) First point
        glVertex2i(180, 400);
        glVertex2i(130, 370);
        glVertex2i(130, 340);
        glVertex2i(155, 330);
        glVertex2i(130, 310);
        glVertex2i(130, 290);
        glVertex2i(180, 270);
        glVertex2i(180, 150);
        glVertex2i(250, 150);
        glVertex2i(300, 80);
        glVertex2i(390, 80);
        glVertex2i(430, 120);
    glEnd();
    glPopMatrix();
    /**-------------------------------------Body Ends----------------------------**/

    /**-------------------------------------Eye starts---------------------------
   
   
    /**-------------------------------------Eye ends---------------------------**/



    /**....................................Leg1 starts........................**/

    glClearColor(1.0, 1.0, 1.0, 1.0);

    // Leg

    glColor3f(0.0,0.6,0.0);
    glLineWidth(4.0);
    glPushMatrix();
    glScalef(.15,.15,.15);
    //glTranslatef(220, 200, 0);
    //glTranslatef(1250, 650, 0);
    glTranslatef(220-m*6.68, 2005, 0);
//glTranslatef(1300, 600, 0);
    glRotatef( 70, 0, 0, 1);
//glRotatef( -angle1, 0, 0, 1);
    glBegin(GL_LINE_LOOP);
        glVertex2i(40, 10);
        glVertex2i(0, 0);
        glVertex2i(-40, 10);
        glVertex2i(-40, 160);
        glVertex2i(-10, 180);
        glVertex2i(60, 180);
        glVertex2i(20, 100);
        glVertex2i(60, 60);
    glEnd();
    glPopMatrix();
    //glFlush();
    //glutPostRedisplay();

/**....................................Leg1 ends............................................**/

    /**.................................Arm starts........................................**/
    glColor3f(.0,0.9,0);
    glPushMatrix();
     glScalef(.15,.15,.15);
    //glTranslatef(220, 200, 0);
    //glTranslatef(1250, 650, 0);
    glTranslatef(0-m*6.68, 2100, 0);
//glTranslatef(1300, 600, 0);
//glTranslatef(1300, 600, 0);
    glRotatef( -50, 0, 0, 1);
    //glRotatef( 1, 0, 0, -angle3);

    glBegin(GL_POLYGON);
        glVertex2i(220, 270);
        glVertex2i(200, 250);
        glVertex2i(250, 250);
        glVertex2i(130+angle3*.5, 200-angle3*.5);
        glVertex2i(130+angle3*.5, 180-angle3*.5);
        glVertex2i(120+angle3*.5, 180-angle3*.5);
    glEnd();


    glColor3f(0,0,0);

    drawstring(300, 550, 0.0, "Z Z");
    drawstring(250, 450, 0.0, "Z Z");
    drawstring(200, 500 , 0.0, "Z Z");
    glPopMatrix();
    glutPostRedisplay();
    /**....................................ARM END............................................**/


}
void body2()
{
    //glClear(GL_COLOR_BUFFER_BIT);

    //sceenario();
    /**------------------- Second Leg    angle2----------------------**/

    glColor3f(0.0,0.6,0.9);
    glLineWidth(4.0);
    glPushMatrix();
    glScalef(.2,.2,.2);
    glTranslatef(1250+b2_speed*m+ba_posion, 1150, 0);
    //
    //else
    //glTranslatef(1250-m, 1150, 0);


    //glTranslatef(1300, 600, 0);
    glRotatef( -angle2, 0, 0, 1);

    glBegin(GL_LINE_LOOP);
        glVertex2i(30, 10);
        glVertex2i(0, 0);
        glVertex2i(-30, 10);
        glVertex2i(-30, 160);
        glVertex2i(-10, 180);
        glVertex2i(40, 180);
        glVertex2i(10, 100);
        glVertex2i(40, 50);
    glEnd();
    glPopMatrix();

    /**------------------------------Body Starts---------------------------**/

    //glViewport(1000,100,500,500);
    glColor3f(0.7,.2,0);
    glPushMatrix();
    glScalef(.2,.2,.2);
    glTranslatef(1000+b2_speed*m+ba_posion, 950, 0);
    glBegin(GL_POLYGON);
        glVertex2i(400, 300);
        glVertex2i(310, 370);
        glVertex2i(280, 400);  //(x,y) First point
        glVertex2i(180, 400);
        glVertex2i(130, 370);
        glVertex2i(130, 340);
        glVertex2i(155, 330);
        glVertex2i(130, 310);
        glVertex2i(130, 290);
        glVertex2i(180, 270);
        glVertex2i(180, 150);
        glVertex2i(250, 150);
        glVertex2i(300, 80);
        glVertex2i(390, 80);
        glVertex2i(430, 120);
    glEnd();
    glPopMatrix();
    /**-------------------------------------Body Ends----------------------------**/
