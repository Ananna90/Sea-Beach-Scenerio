#include<bits/stdc++.h>
#include <cstdio>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include<windows.h>
#include<MmSystem.h>

using namespace std;

#define PI 3.14159265358979323846

GLfloat i = 0.0f;

//INITIALIZING

GLfloat position_sun = 0.0f;    ///SUN
GLfloat position_sun_down = 0.0f;
GLfloat speed_sun = 0.0175f;

GLfloat position_moon = 0.0f;   ///MOON
GLfloat position_moon_down = 0.0f;
GLfloat speed_moon = 0.0175f;

GLfloat position_cloud = 0.0f;  ///CLOUD
GLfloat speed_cloud = 0.02f;

GLfloat rain_position1 = 0.0f;  ///RAIN
GLfloat rain_speed1 = 0.0f;
GLfloat rain_position2 = 0.0f;
GLfloat rain_speed2 = 0.01f;
boolean RainController = false;

GLfloat position_ship = 0.0f;   ///SHIP
GLfloat speed_ship = 0.01f;
GLfloat ship_position = 0.0f;

GLfloat position_sea_wave = 0.0f;   ///SEA WAVE
GLfloat speed_sea_wave = 0.05f;

void load_Start();
void load_DayBack();


void Idle()
{
    glutPostRedisplay();    ///IF NEED RE-DISPLAY
}

void update_sun(int value)  ///UPDATE SUN
{

    if(position_sun <-1.0)
    {
        position_sun = 1.0f;
        position_sun_down = 1.0f;
    }
    position_sun -= speed_sun;
    position_sun_down -= speed_sun/3;

    glutTimerFunc(135, update_sun, 0);
}

void update_ship(int value)     ///UPDATE SHIP
{

    if(position_ship <-1.0)
    {
        position_ship = 1.0f;
    }
    position_ship -= speed_ship;

    glutTimerFunc(100, update_ship, 0);


}

void update_sea_wave(int value)     ///UPDATE SEA WAVE
{
    position_sea_wave -= 50;
    if(position_sea_wave <= -80)
        position_sea_wave = 0;

    glutPostRedisplay();

    glutTimerFunc(1500,update_sea_wave,0);
}

void update_moon(int value)     ///UPDATE MOON
{
    if(position_moon <-1.0)
    {
        position_moon = 1.0f;
        position_moon_down = 1.0f;
    }
    position_moon -= speed_moon;
    position_moon_down -= speed_moon/3;

    glutTimerFunc(80, update_moon, 0);
}

void update_cloud(int value)    ///UPDATE CLOUD
{

    if(position_cloud <-1.0)
    {
        position_cloud = 1.0f;
    }
    position_cloud -= speed_sun;

    glutTimerFunc(100, update_cloud, 0);
}





void update_rain(int value)     ///UPDATE RAIN
{
    if(rain_position1 <-1.0)
        rain_position1 = 0.2f;

    rain_position1 -= rain_speed1;

    if(rain_position2 >1.0)
        rain_position2 = -1.0f;

    rain_position2 += rain_speed2;

    glutTimerFunc(30, update_rain, 0);
}

void load_Restart(int x)
{
    glutDisplayFunc(load_Start);    ///CALLBACK DISPLAY FUNCTION
}

void Ship()         ///SHIP STRUCTURE 01
{
    glScalef(.2,.2,0);

    glTranslatef(.3,.9,0);
    glPushMatrix();
    glTranslatef(-position_ship,0.0, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(52, 73, 94 );
    glVertex2f(-0.3f, -0.2f);
    glVertex2f(-0.3f, -0.4f);
    glVertex2f(0.1f, -0.4f);
    glVertex2f(0.3f, -0.2f);
    glEnd();

    glBegin(GL_POLYGON);    /// 1st floor
    glColor3ub(51, 0, 128);
    glVertex2f(-0.25f, -0.07f);
    glVertex2f(-0.25f, -0.2f);
    glVertex2f(0.15f, -0.2f);
    glVertex2f(0.1f, -0.07f);
    glEnd();

    glBegin(GL_QUADS);      ///window 1
    glColor3ub(255, 0, 255);
    glVertex2f(-0.2f, -0.09f);
    glVertex2f(-0.2f, -0.18f);
    glVertex2f(-0.15f, -0.18f);
    glVertex2f(-0.15f, -0.09f);
    glEnd();

    glBegin(GL_QUADS);     ///window 2
    glColor3ub(241, 196, 15);
    glVertex2f(-0.1f, -0.09f);
    glVertex2f(-0.1f, -0.18f);
    glVertex2f(-0.05f, -0.18f);
    glVertex2f(-0.05f, -0.09f);
    glEnd();

    glBegin(GL_QUADS);     ///window 3
    glColor3ub(255, 0, 255);
    glVertex2f(0.0f, -0.09f);
    glVertex2f(0.0f, -0.18f);
    glVertex2f(0.05f, -0.18f);
    glVertex2f(0.05f, -0.09f);
    glEnd();


    glBegin(GL_POLYGON);    ///2nd floor
    glColor3ub(33, 97, 140);
    glVertex2f(-0.2f, 0.05f);
    glVertex2f(-0.2f, -0.07f);
    glVertex2f(0.06f, -0.07f);
    glVertex2f(0.02f, 0.05f);
    glEnd();

    glBegin(GL_QUADS);     ///window 1
    glColor3ub(0, 153, 51);
    glVertex2f(-0.18f, 0.03f);
    glVertex2f(-0.18f, -0.061f);
    glVertex2f(-0.13f, -0.061f);
    glVertex2f(-0.13f, 0.03f);
    glEnd();

    glBegin(GL_QUADS); ///window 2
    glColor3ub(0, 153, 51);
    glVertex2f(-0.06f, 0.03f);
    glVertex2f(-0.06f, -0.061f);
    glVertex2f(-0.01f, -0.061f);
    glVertex2f(-0.01f, 0.03f);
    glEnd();
    glPopMatrix();

    glLoadIdentity();
}

void Ship_2()       ///SHIP STRUCTURE 02
{
    glPushMatrix();
    glTranslatef(-position_ship,0.0f, 0.0f);
    glScalef(0.5,0.5,0.0);
    glTranslatef(-0.7,0.6,0.0);
    glBegin(GL_POLYGON);

    glColor3ub(10, 10, 30);

    glVertex2f(-0.6f,-0.7f);
    glVertex2f(-0.5f,-0.8f);
    glVertex2f(0.3f,-0.8f);
    glVertex2f(0.4f,-0.7f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(227, 218, 209);

    glVertex2f(-0.48f,-0.6f);
    glVertex2f(-0.5f,-0.7f);
    glVertex2f(0.2f,-0.7f);
    glVertex2f(0.15f,-0.6f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(255, 255, 255);

    glVertex2f(-0.48f,-0.65f);
    glVertex2f(-0.48f,-0.68f);
    glVertex2f(0.15f,-0.68f);
    glVertex2f(0.15f,-0.65f);

    glEnd();

    glBegin(GL_POLYGON);    ///chimni

    glColor3ub(217, 185, 24);

    glVertex2f(-0.4f,-0.5f);
    glVertex2f(-0.4f,-0.6f);
    glVertex2f(-.3f,-0.6f);
    glVertex2f(-.3f,-0.5f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(217, 185, 24);

    glVertex2f(-0.2f,-0.5f);
    glVertex2f(-0.2f,-0.6f);
    glVertex2f(-.1f,-0.6f);
    glVertex2f(-.1f,-0.5f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(217, 185, 24);

    glVertex2f(-0.0f,-0.5f);
    glVertex2f(-0.0f,-0.6f);
    glVertex2f(.1f,-0.6f);
    glVertex2f(.1f,-0.5f);

    glEnd();

    glBegin(GL_POLYGON);    ///chimni border

    glColor3ub(8, 7, 6);

    glVertex2f(-0.4f,-0.5f);
    glVertex2f(-0.4f,-0.48f);
    glVertex2f(-.3f,-0.48f);
    glVertex2f(-.3f,-0.5f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(8, 7, 6);

    glVertex2f(-0.2f,-0.5f);
    glVertex2f(-0.2f,-0.48f);
    glVertex2f(-.1f,-0.48f);
    glVertex2f(-.1f,-0.5f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(8, 7, 6);

    glVertex2f(-0.0f,-0.5f);
    glVertex2f(-0.0f,-0.48f);
    glVertex2f(.1f,-0.48f);
    glVertex2f(.1f,-0.5f);

    glEnd();

    glLoadIdentity();
    glPopMatrix();


}

void Tower()        ///TOWER STRUCTURE
{
    glTranslatef(0.7,-0.5,0.0);
    glScalef(0.8,0.8,0.0);
    glBegin(GL_QUADS);
    glColor3ub(27, 38, 49);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(-0.2f, -0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2f(-0.15f, 0.28f);
    glVertex2f(-0.18f, 0.28f);
    glVertex2f(-0.18f, 0.1f);
    glVertex2f(-0.15f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(110, 44, 0);
    glVertex2f(0.15f, 0.28f);
    glVertex2f(0.18f, 0.28f);
    glVertex2f(0.18f, 0.1f);
    glVertex2f(0.15f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 38, 49);
    glVertex2f(-0.2f, 0.32f);
    glVertex2f(0.2f, 0.32f);
    glVertex2f(0.2f, 0.28f);
    glVertex2f(-0.2f, 0.28f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(27, 38, 49);
    glVertex2f(-0.2, 0.32);
    glVertex2f(0.0, 0.52);
    glVertex2f(0.2, 0.32);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.0, 0.5);
    glVertex2f(0.0, 0.65);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(188, 0, 0);
    glVertex2f(0.0, 0.6);
    glVertex2f(0.05, 0.625);
    glVertex2f(0.0, 0.65);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(-0.2, -0.1);
    glVertex2f(-0.3, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.2, -0.1);
    glVertex2f(0.3, -0.5);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(-0.2, -0.1);
    glVertex2f(0.28, -0.4);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.2, -0.1);
    glVertex2f(-0.28, -0.4);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(0.08, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(-0.08, -0.1);
    glVertex2f(-0.08, -0.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();

    glTranslatef(0.0, -0.05, 0.0);
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();

    glTranslatef(0.0, -0.05, 0.0);   ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);   ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);       ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);       ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);       ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();


    glTranslatef(0.0, -0.05, 0.0);       ///LoadIdentity();
    glBegin(GL_LINES);
    glColor3ub(94, 0, 0);
    glVertex2f(0.08, -0.1);
    glVertex2f(-0.08, -0.1);
    glEnd();

    glLoadIdentity();
}

void Rain()         ///RAIN STRUCTURE
{
    glPushMatrix();
    glTranslatef(rain_position2,rain_position1, 0.0f);

    glColor3ub(174, 214, 241);  /// Rain line 1
    glBegin(GL_LINES);
    glVertex2f (-0.40,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();


    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glLoadIdentity();

    glPopMatrix();
    glTranslatef(0,0.4,0);


    glPushMatrix();
    glTranslatef(rain_position2,rain_position1, 0.0f);


    glColor3ub(174, 214, 241);       /// Rain line 2
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();


    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glLoadIdentity();

    glPopMatrix();

    glTranslatef(0,-0.4,0);

    glPushMatrix();
    glTranslatef(rain_position2,rain_position1, 0.0f);


    glColor3ub(174, 214, 241);   /// Rain line 3
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();


    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glLoadIdentity();

    glPopMatrix();

    glTranslatef(0,-0.8,0);

    glPushMatrix();
    glTranslatef(rain_position2,rain_position1, 0.0f);


    glColor3ub(174, 214, 241);      ///Rain line 4
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(-.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();


    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,-0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();

    glTranslatef(.2,0.1,0);

    glColor3ub(174, 214, 241);
    glBegin(GL_LINES);
    glVertex2f (-0.4,0.47);
    glVertex2f (-0.35,0.28);
    glEnd();


    glPopMatrix();

    glLoadIdentity();

}

void Sun()      ///SUN STRUCTURE
{
    glPushMatrix();
    glTranslatef(-position_sun, 0.0/*position_sun_down*/, 0.0f);
    int is;
    GLfloat xs=-0.8f;
    GLfloat ys=0.8f;
    GLfloat radiuss =.17f;
    int triangleAmounts = 100;
    GLfloat twicePis = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 209, 26);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
    glEnd();
    glPopMatrix();
}

void Moon()     ///MOON STRUCTURE
{
    glPushMatrix();
    glTranslatef(-position_moon, 0.0/*position_moon_down*/, 0.0f);
    int is;
    GLfloat xs=-0.8f;
    GLfloat ys=0.8f;
    GLfloat radiuss =.1f;
    int triangleAmounts = 100;
    GLfloat twicePis = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,240);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
    glEnd();

    glTranslatef(0.04,0.05,0.0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(44,62,80);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
    glEnd();
    glLoadIdentity();
    glPopMatrix();
}

void Cloud()        ///CLOUD STRUCTURE
{
    glPushMatrix();
    glTranslatef(position_cloud, 0.0f, 0.0f);
    float xC,yC,radiusC,triangleAmountC,twicePiC;
    xC= -0.4f, yC= 0.7f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC; iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
    glEnd();
    xC= -0.3f, yC= 0.7f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(204, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC; iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
    glEnd();
    xC= -0.37f, yC= 0.67f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(204, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC; iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
    glEnd();


    glTranslatef(0.5f,0.1,0);
    xC= -0.4f, yC= 0.7f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC; iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
    glEnd();
    xC= -0.3f, yC= 0.7f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(204, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC; iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
    glEnd();
    xC= -0.37f, yC= 0.67f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(204, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC; iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
    glEnd();

    glTranslatef(0.5f,-0.19,0);
    xC= -0.4f, yC= 0.7f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(230, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC; iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
    glEnd();
    xC= -0.3f, yC= 0.7f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(204, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC; iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
    glEnd();
    xC= -0.37f, yC= 0.67f, radiusC =.09f;
    triangleAmountC = 20;
    twicePiC = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(204, 255, 255);
    glVertex2f(xC, yC);
    for(int iC = 0; iC <= triangleAmountC; iC++)
    {
        glVertex2f(xC + (radiusC * cos(iC *  twicePiC / triangleAmountC)),yC + (radiusC * sin(iC * twicePiC / triangleAmountC)));
    }
    glEnd();
    glLoadIdentity();
    glPopMatrix();
}


void Tree()     ///TREE STRUCTURE
{
    glScalef(0.5,0.5,0.0);
    glTranslatef(1.0,-0.9,0.0);
    glBegin(GL_QUADS);
    glColor3ub(156, 139, 102);

    glVertex2f(0.8, -0.3f);
    glVertex2f(0.75, -0.3f);
    glVertex2f(0.75, -0.9f);
    glVertex2f(0.8, -0.9f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(36, 211, 47);
    glVertex2f(0.65,-0.4);
    glVertex2f(0.9,-0.4);
    glVertex2f(0.775,-0.1);
    glEnd();

    glTranslatef(0,0.06,0);

    glBegin(GL_TRIANGLES);
    glColor3ub(36, 211, 47);
    glVertex2f(0.65,-0.4);
    glVertex2f(0.9,-0.4);
    glVertex2f(0.775,-0.1);
    glEnd();

    glTranslatef(0.0f,0.1f,0);
    glBegin(GL_TRIANGLES);
    glColor3ub(36, 211, 47);
    glVertex2f(0.65,-0.4);
    glVertex2f(0.9,-0.4);
    glVertex2f(0.775,-0.1);
    glEnd();

    glLoadIdentity();
}

void Umbrella()     ///UMBRELLA STRUCTURE
{
    glTranslatef(-0.75, 0.00, 0.0);

    glBegin(GL_QUADS);
    glColor3ub(156, 156, 161);

    glVertex2f(-0.01, -0.6f);
    glVertex2f(0.01, -0.6f);
    glVertex2f(0.01, -0.9f);
    glVertex2f(-0.01, -0.9f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(245, 203, 66);
    glVertex2f(-0.05,-0.65);
    glVertex2f(0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(245, 105, 66);
    glVertex2f(0.13,-0.64);
    glVertex2f(0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(24, 161, 26);
    glVertex2f(-0.13,-0.64);
    glVertex2f(-0.05,-0.65);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(82, 235, 212);
    glVertex2f(-0.18,-0.63);
    glVertex2f(-0.13,-0.64);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(232, 9, 9);
    glVertex2f(0.18,-0.63);
    glVertex2f(0.13,-0.64);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(179, 2, 219);
    glVertex2f(0.21,-0.62);
    glVertex2f(0.18,-0.63);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(18, 51, 219);
    glVertex2f(-0.21,-0.62);
    glVertex2f(-0.18,-0.63);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(142, 136, 148);
    glVertex2f(-0.23,-0.61);
    glVertex2f(-0.21,-0.62);
    glVertex2f(0.0,-0.45);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(117, 118, 128);
    glVertex2f(0.23,-0.61);
    glVertex2f(0.21,-0.62);
    glVertex2f(0.0,-0.45);
    glEnd();

    glLoadIdentity();
}

void Seat()     ///SEAT STRUCTURE
{
    glScalef(1.8,1.8, 0);
    glTranslatef(-0.42, 0.42, 0.0);

    glBegin(GL_QUADS);
    glColor3ub(150, 124, 45);
    glVertex2f(0.13, -0.83f);
    glVertex2f(0.15, -0.83f);
    glVertex2f(0.15, -0.86f);
    glVertex2f(0.13, -0.866f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(171, 151, 89);
    glVertex2f(0.09, -0.83f);
    glVertex2f(0.16, -0.83f);
    glVertex2f(0.08, -0.88f);
    glVertex2f(0.02, -0.88f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(150, 124, 45);
    glVertex2f(0.02, -0.8f);
    glVertex2f(0.08, -0.8f);
    glVertex2f(0.08, -0.9f);
    glVertex2f(0.02, -0.9f);
    glEnd();

    glLoadIdentity();
}


void Day_Sky()      ///DAY SKY
{

    glBegin(GL_QUADS);
    glColor3ub(0, 153, 255);
    glVertex2f(-1.0, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, .95f);
    glVertex2f(-1.0f, .95f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(26, 163, 255);
    glVertex2f(-1.0, .95f);
    glVertex2f(1.0f, .95f);
    glVertex2f(1.0f, .90f);
    glVertex2f(-1.0f, .90f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(51, 173, 255);
    glVertex2f(-1.0, .90f);
    glVertex2f(1.0f, .90f);
    glVertex2f(1.0f, .85f);
    glVertex2f(-1.0f, .85f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(77, 184, 255);
    glVertex2f(-1.0, .85f);
    glVertex2f(1.0f, .85f);
    glVertex2f(1.0f, .80f);
    glVertex2f(-1.0f, .80f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102, 194, 255);
    glVertex2f(-1.0, .80f);
    glVertex2f(1.0f, .80f);
    glVertex2f(1.0f, .70f);
    glVertex2f(-1.0f, .70f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(128, 204, 255);
    glVertex2f(-1.0, .70f);
    glVertex2f(1.0f, .70f);
    glVertex2f(1.0f, .60f);
    glVertex2f(-1.0f, .60f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(153, 214, 255);
    glVertex2f(-1.0, .60f);
    glVertex2f(1.0f, .60f);
    glVertex2f(1.0f, .40f);
    glVertex2f(-1.0f, .40f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(179, 224, 255);
    glVertex2f(-1.0, .40f);
    glVertex2f(1.0f, .40f);
    glVertex2f(1.0f, .15f);
    glVertex2f(-1.0f, .15f);
    glEnd();

    glEnable(GL_LIGHTING);
    GLfloat sun_shine[] = {77, 77, 0, 7.5};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, sun_shine);
    Sun();
    glDisable(GL_LIGHTING);

    Cloud();


}

void Evening_Sky()  ///EVENING SKY
{
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 153);
    glVertex2f(-1.0, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, .95f);
    glVertex2f(-1.0f, .95f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 0);
    glVertex2f(-1.0, .95f);
    glVertex2f(1.0f, .95f);
    glVertex2f(1.0f, .90f);
    glVertex2f(-1.0f, .90f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 77);
    glVertex2f(-1.0, .90f);
    glVertex2f(1.0f, .90f);
    glVertex2f(1.0f, .85f);
    glVertex2f(-1.0f, .85f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 102);
    glVertex2f(-1.0, .85f);
    glVertex2f(1.0f, .85f);
    glVertex2f(1.0f, .80f);
    glVertex2f(-1.0f, .80f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 128);
    glVertex2f(-1.0, .80f);
    glVertex2f(1.0f, .80f);
    glVertex2f(1.0f, .70f);
    glVertex2f(-1.0f, .70f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 153);
    glVertex2f(-1.0, .70f);
    glVertex2f(1.0f, .70f);
    glVertex2f(1.0f, .60f);
    glVertex2f(-1.0f, .60f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 179);
    glVertex2f(-1.0, .60f);
    glVertex2f(1.0f, .60f);
    glVertex2f(1.0f, .40f);
    glVertex2f(-1.0f, .40f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 204);
    glVertex2f(-1.0, .40f);
    glVertex2f(1.0f, .40f);
    glVertex2f(1.0f, .15f);
    glVertex2f(-1.0f, .15f);
    glEnd();

    Sun();

    Cloud();



}

void drawCircle(float x1, float y1,double radius)
{
    float x2, y2;
    float angle;
    glBegin(GL_POLYGON);
    for (angle = .1f; angle<361.0f; angle += 1.0f)
    {
        x2 = x1 + sin(angle)*radius;
        y2 = y1 + cos(angle)*radius;
        glVertex2f(x2, y2);
    }
    glEnd();
}

void Stars()        ///STARS STRUCTURE
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(255,255,240);
    drawCircle(0.2,0.9,0.006);
    drawCircle(0.4,0.9,0.006);
    drawCircle(0.6,0.9,0.006);
    drawCircle(0.8,0.9,0.006);
    drawCircle(-0.2,0.9,0.006);
    drawCircle(-0.4,0.9,0.006);
    drawCircle(-0.6,0.9,0.006);
    drawCircle(-0.8,0.9,0.006);
    drawCircle(-0.9,0.8,0.006);
    drawCircle(-0.7,0.8,0.006);
    drawCircle(-0.5,0.8,0.006);
    drawCircle(-0.3,0.8,0.006);
    drawCircle(-0.0,0.9,0.006);
    drawCircle(-0.1,0.8,0.006);
    drawCircle(0.1,0.8,0.006);
    drawCircle(0.3,0.8,0.006);
    drawCircle(0.5,0.8,0.006);
    drawCircle(0.7,0.8,0.006);
    drawCircle(0.9,0.8,0.006);

    drawCircle(0.2,0.7,0.006);
    drawCircle(0.4,0.7,0.006);
    drawCircle(0.6,0.7,0.006);
    drawCircle(0.8,0.7,0.006);
    drawCircle(-0.2,0.7,0.006);
    drawCircle(-0.4,0.7,0.006);
    drawCircle(-0.6,0.7,0.006);
    drawCircle(-0.8,0.7,0.006);
    drawCircle(-0.9,0.6,0.006);
    drawCircle(-0.7,0.6,0.006);
    drawCircle(-0.5,0.6,0.006);
    drawCircle(-0.3,0.6,0.006);
    drawCircle(-0.0,0.7,0.006);
    drawCircle(-0.1,0.6,0.006);
    drawCircle(0.1,0.6,0.006);
    drawCircle(0.3,0.6,0.006);
    drawCircle(0.5,0.6,0.006);
    drawCircle(0.7,0.6,0.006);
    drawCircle(0.9,0.6,0.006);

    drawCircle(0.2,0.5,0.006);
    drawCircle(0.4,0.5,0.006);
    drawCircle(0.6,0.5,0.006);
    drawCircle(0.8,0.5,0.006);
    drawCircle(-0.2,0.5,0.006);
    drawCircle(-0.4,0.5,0.006);
    drawCircle(-0.6,0.5,0.006);
    drawCircle(-0.8,0.5,0.006);
    drawCircle(-0.9,0.4,0.006);
    drawCircle(-0.7,0.4,0.006);
    drawCircle(-0.5,0.4,0.006);
    drawCircle(-0.3,0.4,0.006);
    drawCircle(-0.0,0.5,0.006);
    drawCircle(-0.1,0.4,0.006);
    drawCircle(0.1,0.4,0.006);
    drawCircle(0.3,0.4,0.006);
    drawCircle(0.5,0.4,0.006);
    drawCircle(0.7,0.4,0.006);
    drawCircle(0.9,0.4,0.006);
    glPopMatrix();
    glEnd();
}

void Night_Sky()    ///NIGHT SKY
{
    glBegin(GL_QUADS);
    glColor3ub(44,62,80);
    glVertex2f(-1.0, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, .15f);
    glVertex2f(-1.0f, .15f);
    glEnd();

    Moon();
    Stars();
}

void Sea_Texute(int r, int g, int b)    ///SEA TEXTURE
{
    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    glVertex2f(-0.95, 0.13);
    glVertex2f(-0.90, 0.13);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    glVertex2f(-0.75, 0.124);
    glVertex2f(-0.70, 0.124);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    glVertex2f(-0.55, 0.134);
    glVertex2f(-0.50, 0.134);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    glVertex2f(-0.35, 0.120);
    glVertex2f(-0.30, 0.120);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    glVertex2f(-0.15, 0.110);
    glVertex2f(-0.10, 0.110);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    glVertex2f(0.05, 0.130);
    glVertex2f(0.10, 0.130);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    glVertex2f(0.25, 0.1);
    glVertex2f(0.20, 0.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    glVertex2f(0.45, 0.13);
    glVertex2f(0.40, 0.13);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    glVertex2f(0.65, 0.1);
    glVertex2f(0.60, 0.1);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(r, g, b);
    glVertex2f(0.85, 0.1);
    glVertex2f(0.80, 0.1);
    glEnd();
}

void Day_Sea()      ///DAY SEA
{
    glBegin(GL_QUADS);
    glColor3ub(102, 153, 202);
    glVertex2f(-1.0, .15f); // top left
    glVertex2f(1.0f, .15f); // top right
    glVertex2f(1.0, -0.30f); // top left
    glVertex2f(-1.0f, -0.30f); // top right
    glEnd();


   Sea_Texute(61, 117, 227);       ///SEA TEXURE
    glTranslatef(0.02,-0.075,0.0);
    Sea_Texute(61, 117, 227);
    glLoadIdentity();
    glTranslatef(0.07,-0.15,0.0);
    Sea_Texute(61, 117, 227);
    glLoadIdentity();
    glTranslatef(-0.05,-0.2275,0.0);
    Sea_Texute(61, 117, 227);
    glLoadIdentity();
    glTranslatef(0.03,-0.35,0.0);
    Sea_Texute(61, 117, 227);
    glLoadIdentity();

}

void Evening_Sea()      ///EVENING SEA
{
    glBegin(GL_QUADS);
    glColor3ub(77, 136, 255);
    glVertex2f(-1.0, .15f);  // top left
    glVertex2f(1.0f, .15f);  // top right
    glVertex2f(1.0, -0.30f);  // top left
    glVertex2f(-1.0f, -0.30f);  // top right
    glEnd();


    Sea_Texute(51, 114, 242);     ///SEA TEXURE
    glTranslatef(0.02,-0.075,0.0);
    Sea_Texute(51, 114, 242);
    glLoadIdentity();

    glTranslatef(0.07,-0.15,0.0);
    Sea_Texute(51, 114, 242);
    glLoadIdentity();

    glTranslatef(-0.05,-0.2275,0.0);
    Sea_Texute(51, 114, 242);
    glLoadIdentity();

    glTranslatef(0.03,-0.35,0.0);
    Sea_Texute(51, 114, 242);
    glLoadIdentity();
}

void Night_Sea()        ///NIGHT SEA
{
    glBegin(GL_QUADS);
    glColor3ub(150,255,105);
    glVertex2f(-1.0, .15f); // top left
    glVertex2f(1.0f, .15f); // top right
    glVertex2f(1.0, -0.30f); // top left
    glVertex2f(-1.0f, -0.30f); // top right
    glEnd();


    Sea_Texute(17, 63, 156);        ///SEA TEXURE
    glTranslatef(0.02,-0.075,0.0);
    Sea_Texute(17, 63, 156);
    glLoadIdentity();

    glTranslatef(0.07,-0.15,0.0);
    Sea_Texute(17, 63, 156);
    glLoadIdentity();

    glTranslatef(-0.05,-0.2275,0.0);
    Sea_Texute(17, 63, 156);
    glLoadIdentity();

    glTranslatef(0.03,-0.35,0.0);
    Sea_Texute(17, 63, 156);
    glLoadIdentity();
}

void Sea_Wave(int r, int g, int b)      ///SEA WAVE
{
    glPushMatrix();
    glTranslatef(position_sea_wave, 0.0f, 0.0f);

    glTranslatef(0.0f, -0.14f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);

    glVertex2f(-1.0, -0.14f);
    glVertex2f(-0.9f, -0.2f);
    glVertex2f(-0.8, -0.14f);
    glVertex2f(-0.7f, -0.2f);
    glVertex2f(-0.6f, -0.14f);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.4f, -0.14f);
    glVertex2f(-0.3f, -0.2f);
    glVertex2f(-0.2f, -0.14f);
    glVertex2f(-0.1f, -0.2f);
    glVertex2f(0.0f, -0.14f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.2f, -0.14f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.4f, -0.14f);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.6f, -0.14f);
    glVertex2f(0.7f, -0.2f);
    glVertex2f(0.8f, -0.14f);
    glVertex2f(0.9f, -0.2f);
    glVertex2f(1.0f, -0.14f);
    glEnd();

    glTranslatef(0.1f, -0.01f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);

    glVertex2f(-1.0, -0.14f);
    glVertex2f(-0.9f, -0.2f);
    glVertex2f(-0.8, -0.14f);
    glVertex2f(-0.7f, -0.2f);
    glVertex2f(-0.6f, -0.14f);
    glVertex2f(-0.5f, -0.2f);
    glVertex2f(-0.4f, -0.14f);
    glVertex2f(-0.3f, -0.2f);
    glVertex2f(-0.2f, -0.14f);
    glVertex2f(-0.1f, -0.2f);
    glVertex2f(0.0f, -0.14f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.2f, -0.14f);
    glVertex2f(0.3f, -0.2f);
    glVertex2f(0.4f, -0.14f);
    glVertex2f(0.5f, -0.2f);
    glVertex2f(0.6f, -0.14f);
    glVertex2f(0.7f, -0.2f);
    glVertex2f(0.8f, -0.14f);
    glVertex2f(0.9f, -0.2f);
    glVertex2f(1.0f, -0.14f);
    glEnd();

    glPopMatrix();
}

void Day_Mountain()         ///DAY MOUNTAIN
{
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(0.0f, 0.45f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();

    glScalef(0.8,0.8,0.0);
    glTranslatef(0.18,0.0335,0.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();
    glLoadIdentity();

    glScalef(0.8,0.8,0.0);
    glTranslatef(-0.18,0.0335,0.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 102, 0);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();
    glLoadIdentity();
}

void Evening_Mountain()     ///EVENING MOUNTAIN
{
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 77, 0);
    glVertex2f(0.0f, 0.45f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();

    glScalef(0.8,0.8,0.0);
    glTranslatef(0.18,0.0335,0.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 77, 0);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();
    glLoadIdentity();

    glScalef(0.8,0.8,0.0);
    glTranslatef(-0.18,0.0335,0.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 77, 0);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();
    glLoadIdentity();
}

void Night_Mountain()   ///NIGHT MOUNTAIN
{
    glBegin(GL_TRIANGLES);
    glColor3ub(10, 51, 10);
    glVertex2f(0.0f, 0.45f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();

    glScalef(0.8,0.8,0.0);
    glTranslatef(0.18,0.0335,0.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(10, 51, 10);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();
    glLoadIdentity();

    glScalef(0.8,0.8,0.0);
    glTranslatef(-0.18,0.0335,0.0);
    glBegin(GL_TRIANGLES);
    glColor3ub(10, 51, 10);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(-0.15f, 0.15f);
    glEnd();
    glLoadIdentity();
}

void Day_Sand()     ///DAY SAND
{
    glBegin(GL_QUADS);
    glColor3ub(243, 213, 120);
    glVertex2f(-1.0, -0.30f);
    glVertex2f(1.0f, -0.30f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    Umbrella();    ///ADD SEATS AND UMBRELLA
    Seat();
    glTranslatef(0.9,0.0,0.0);
    Umbrella();
    glLoadIdentity();

    glTranslatef(0.9,0.0,0.0);
    Seat();
    glLoadIdentity();

    glScalef(0.7, 0.7, 0.0);
    glTranslatef(0.35,-0.05,0.0);
    Umbrella();
    glLoadIdentity();

    glScalef(0.7, 0.7, 0.0);
    glTranslatef(0.35,-0.05,0.0);
    Seat();
    glLoadIdentity();

}

void Night_Sand()   ///NIGHT SAND
{
    glBegin(GL_QUADS);
    glColor3ub(170, 149, 8);
    glVertex2f(-1.0, -0.30f);
    glVertex2f(1.0f, -0.30f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();




    Umbrella();     ///ADD SEATS AND UMBRELLA
    Seat();
    glTranslatef(0.9,0.0,0.0);
    Umbrella();
    glLoadIdentity();
    glTranslatef(0.9,0.0,0.0);
    Seat();
    glLoadIdentity();
    glScalef(0.7, 0.7, 0.0);
    glTranslatef(0.35,-0.05,0.0);
    Umbrella();
    glLoadIdentity();
    glScalef(0.7, 0.7, 0.0);
    glTranslatef(0.35,-0.05,0.0);
    Seat();
    glLoadIdentity();
}

void Evening_Sand()     ///EVENING SAND
{
    glBegin(GL_QUADS);
    glColor3ub(249, 233, 185);
    glVertex2f(-1.0, -0.30f);
    glVertex2f(1.0f, -0.30f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();


    Umbrella();         ///ADD SEATS AND UMBRELLA
    Seat();
    glTranslatef(0.9,0.0,0.0);
    Umbrella();
    glLoadIdentity();
    glTranslatef(0.9,0.0,0.0);
    Seat();
    glLoadIdentity();
    glScalef(0.7, 0.7, 0.0);
    glTranslatef(0.35,-0.05,0.0);
    Umbrella();
    glLoadIdentity();
    glScalef(0.7, 0.7, 0.0);
    glTranslatef(0.35,-0.05,0.0);
    Seat();
    glLoadIdentity();
}

void sound()
{

    PlaySound("play.wav", NULL, SND_ASYNC|SND_FILENAME);

}
void handleKeypress(unsigned char key, int x, int y) ///EVENT HANDLER
{
    switch (key)
    {
    ///RAIN START
    case 'r':
        RainController = true;
        break;

    case 'R':
        RainController = true;
        break;

    ///RAIN END
    case 'd':
        RainController = false;
        break;

    case 'D':
        RainController = false;
        break;
    ///Sound Start
    case 's':
        sound();
        break;

    default:
        exit(0);
        break;
    }
}

///VIEWS


void View_Night()   ///NIGHT TIME
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Night_Sea();
    Night_Sky();
    Night_Sand();
    Sea_Wave(0, 34, 102);
    Night_Mountain();
    Ship();
    Ship_2();
    Tower();
    glTranslatef(0.05,0.1,0.0);
    Tree();
    glLoadIdentity();
    Tree();


    if(RainController == true)
    {
        Rain();
    }
    glutTimerFunc(5500,load_Restart,0);
    position_sun = 0.0f;
    glFlush();
}

void load_Night(int x)
{
    glutDisplayFunc(View_Night);
}

void View_Evening()     ///EVENING TIME
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    Evening_Sea();
    Evening_Sky();
    Evening_Sand();
    Sea_Wave(77, 136, 255);
    Evening_Mountain();
    Ship();
    Ship_2();
    Tower();
    glTranslatef(0.05,0.1,0.0);
    Tree();
    glLoadIdentity();
    Tree();

    glLoadIdentity();
    if(RainController == true)
    {
        Rain();
    }
    glutTimerFunc(5500,load_Night,0);
    position_moon = 0.0f;

    glFlush();
}

void load_Evening(int x)
{
    glutDisplayFunc(View_Evening);
}

void View_Day()     ///DAY TIME
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    Day_Sea();
    Day_Sky();
    Day_Sand();
    Sea_Wave(102, 153, 255);
    Day_Mountain();
    Ship();
    Ship_2();
    Tower();

    glTranslatef(0.05,0.1,0.0);
    Tree();
    glLoadIdentity();

    Tree();

    glLoadIdentity();

    if(RainController == true)
    {
        Rain();
    }
    glutTimerFunc(5500,load_Evening,0);

    glFlush();
}

void load_Day(int x)
{
    glutDisplayFunc(View_Day);
}

void load_Start()
{
    glutDisplayFunc(View_Day);
}

int main(int argc, char** argv)
{
    cout<<"\npress R or r for rain start"<< endl;
    cout<<"\npress D or d for rain stop"<< endl;
    cout<<"\npress S or s for Play Sound"<< endl;

    glutInit(&argc, argv);
    glutInitWindowSize(900, 640);
    glutInitWindowPosition(400, 80);
    glutCreateWindow("Sea Beach View");



    glutDisplayFunc(load_Start);

    glutTimerFunc(100, update_sun, 0);
    glutTimerFunc(100, update_cloud, 0);
    glutTimerFunc(100, update_moon, 0);
    glutTimerFunc(100, update_rain, 0);
    glutTimerFunc(100, update_ship, 0);
    glutTimerFunc(100, update_sea_wave, 0);

    glutKeyboardFunc(handleKeypress);

    glutIdleFunc(Idle);
    //PlaySound(TEXT("play.wav"), NULL, SND_ALIAS | SND_APPLICATION);
    //sound();
    glutMainLoop();

    return 0;
}

