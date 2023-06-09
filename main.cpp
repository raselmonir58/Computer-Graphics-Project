#include<windows.h>
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#define PI 3.141516

bool smoke=true;
bool space=true;
bool land=true;
bool fire=true;
bool fireoff=true;
bool door=true;
bool road=true;
bool mover=true;
bool house1=true;
bool house2=true;
bool tree=true;
bool water=true;
bool night=true;

int i;
int triangle1=40;
   GLfloat tp1=2.0f*PI;


GLfloat position = 0.0f;
GLfloat position1 = 0.0f;
GLfloat position2 = 0.0f;
GLfloat position3 = 0.0f;
GLfloat speed = 0.0f;
GLfloat speed1 = 0.018f;
GLfloat speed2 = 0.03f;
GLfloat speed3 = 0.0f;


GLfloat s=0.5;


void update(int value) { ////////////////////////////////////////////////////////////////////////fly

    if(position >1.0f) ////if(position <1){position = -0.9f; position -=speed;}
        position = 1.0f;

    position -= speed;

glutPostRedisplay();
glutTimerFunc(100, update, 0);
}

void update1(int value1) {/////////////////////////////////////////////////////////////////////// space

    if(space==false)
    {if(position1 >1.0)
        position1 = 1.0f;

    position1 -= speed1;}


glutPostRedisplay();
glutTimerFunc(100, update1, 0);
}

void update2(int value2) {//////////////////////////////////////////////////////////////////////landing

    if(land==false){
    if(position2 <-1.3)
        position2 = -1.3f;

    position2 -= speed2;}

glutPostRedisplay();
glutTimerFunc(100, update2, 0);
}

void update3(int value3)
{
  if(space==false){
   s-=0.013f;}

glutPostRedisplay();
glutTimerFunc(100, update3, 0);
}

void update4(int value4) {/////////////////////////////////////////////////////////////////////// space

    if(mover==false)
    {if(position3 <-1.5)
        position3 = -1.5f;

    position3 -= speed3;}


glutPostRedisplay();
glutTimerFunc(100, update1, 0);
}


void display() {
    glClearColor(0.0f,0.0f,0.3f,1.0f);
   glClear(GL_COLOR_BUFFER_BIT);
   glLineWidth(20);





   //////////////////////////////////////////////////////////rocket
glPushMatrix();

   glTranslatef(0,-position, 0.0f);

   glBegin(GL_TRIANGLES); //////////////HEAD
   glColor3ub(238,28,37);

   glVertex2f(0.24f,0.6f);//a
   glVertex2f(0.14f, 0.42f);//b
   glVertex2f(0.34f, 0.42f);//c
   glEnd();

   glBegin(GL_POLYGON);/////////////////HEAD  Lower Body
   glColor3ub(230,230,230);
   glVertex2f(0.14f, 0.42f);//b
   glVertex2f(0.14f, 0.08f);//d
   glVertex2f(0.15f, 0.06f);//E
   glVertex2f(0.33f, 0.06f);//f
   glVertex2f(0.34f, 0.08f);//g
   glVertex2f(0.34f, 0.42f);//c
   glEnd();

   GLfloat pbg=0.24f; GLfloat qbg=0.25f; GLfloat rbg=-0.077f;////////////////////glass background

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(130,130,130);
   glVertex2f(pbg,qbg);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  pbg+(rbg*cos(i*tp1/triangle1)), qbg+(rbg*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   GLfloat pg=0.24f; GLfloat qg=0.25f; GLfloat rg=-0.07f;////////////////////glass

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(35,172,196);
   glVertex2f(pg,qg);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  pg+(rg*cos(i*tp1/triangle1)), qg+(rg*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   glBegin(GL_QUADS); /////////////////HEAD Lower Body shadow
   glColor3ub(187,188,192);
   glVertex2f(0.33f, 0.42f);//N'
   glVertex2f(0.33f, 0.06f);//f
   glVertex2f(0.34f, 0.08f);//g
   glVertex2f(0.34f, 0.42f);//c
   glEnd();

   glBegin(GL_QUADS); /////////////////Middle small QUAD
   glColor3ub(187,188,192);
   glVertex2f(0.15f, 0.06f);//E
   glVertex2f(0.15f, 0.01f);//H
   glVertex2f(0.33f, 0.01f);//I
   glVertex2f(0.33f, 0.06f);//f
   glEnd();

   glBegin(GL_POLYGON); ///////////////// UNDER BODY QUAD
   glColor3ub(230,230,230);
   glVertex2f(0.15f, 0.01f);//H
   glVertex2f(0.14f, -0.01f);//K
   glVertex2f(0.14f, -0.74f);//L
   glVertex2f(0.34f, -0.74f);//M
   glVertex2f(0.34f, -0.01f);//J
   glVertex2f(0.33f, 0.01f);//I
   glEnd();

   glBegin(GL_QUADS); /////////////////UNDER BODY QUAD shadow
   glColor3ub(187,188,192);
   glVertex2f(0.33f, -0.74f);//N
   glVertex2f(0.34f, -0.74f);//M
   glVertex2f(0.34f, -0.01f);//J
   glVertex2f(0.33f, 0.01f);//I
   glEnd();


   glBegin(GL_POLYGON); ///////////////// LEFT WING
   glColor3ub(230,230,230);


   glVertex2f(0.1f, -0.25f);//P
   glVertex2f(0.05f, -0.25f);//Q
   glVertex2f(0.01f, -0.74f);//R
   glVertex2f(0.14f, -0.74f);//L
   glVertex2f(0.14f, -0.23f);//O


   glEnd();

   glBegin(GL_QUADS); /////////////////lEFT WING shadow
   glColor3ub(187,188,192);
   glVertex2f(0.1f, -0.25f);//P
   glVertex2f(0.06f, -0.74f);//S
   glVertex2f(0.14f, -0.74f);//L
   glVertex2f(0.14f, -0.23f);//O
   glEnd();


   ///////////////////////////////////////////RIGHT WING
   glBegin(GL_POLYGON);
   glColor3ub(230,230,230);


   glVertex2f(0.34f, -0.74f);//M
   glVertex2f(0.47f, -0.74f);//W
   glVertex2f(0.43f, -0.25f);//V
   glVertex2f(0.38f, -0.25f);//U
   glVertex2f(0.34f, -0.23f);//T

   glEnd();

   glBegin(GL_QUADS); /////////////////RIGHT WING shadow
   glColor3ub(187,188,192);
   glVertex2f(0.38f, -0.25f);//U
   glVertex2f(0.43f, -0.74f);//S'
   glVertex2f(0.47f, -0.74f);//W
   glVertex2f(0.43f, -0.25f);//V
   glEnd();

   glBegin(GL_QUADS); /////////////////LEFT fIRE EXIT
   glColor3ub(96,96,96);
   glVertex2f(0.05f, -0.74f);
   glVertex2f(0.04f, -0.79f);
   glVertex2f(0.11f, -0.79f);
   glVertex2f(0.1f, -0.74f);
   glEnd();

   glBegin(GL_QUADS); /////////////////CENTER fIRE EXIT
   glColor3ub(96,96,96);
   glVertex2f(0.215f, -0.74f);
   glVertex2f(0.205f, -0.79f);
   glVertex2f(0.275f, -0.79f);
   glVertex2f(0.265f, -0.74f);
   glEnd();

   glBegin(GL_QUADS); /////////////////RIGHT fIRE EXIT
   glColor3ub(96,96,96);
   glVertex2f(0.38f, -0.74f);
   glVertex2f(0.37f, -0.79f);
   glVertex2f(0.44f, -0.79f);
   glVertex2f(0.43f, -0.74f);
   glEnd();
glPopMatrix();

////////////////////////////////////////////////////////////////ROCKET LAUNCHER BASE
glPushMatrix();

   glBegin(GL_POLYGON);
   glColor3ub(187,188,192);
   glVertex2f(-0.6f,-0.8f);
   glVertex2f(-0.6f,-1.0f);
   glVertex2f(0.6f,-1.0f);
   glVertex2f(0.6f,-0.8f);
   glEnd();

glPopMatrix();

/////////////////////////////////////////////////////////////////////////LAUNCH PAD ROCKET HOLDER

   glPushMatrix();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.1f,0.6f); //A
   glVertex2f(-0.3f,0.4f); //B
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.3f,0.4f); //B
   glVertex2f(-0.1f,0.4f); //H
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.1f,0.4f); //H
   glVertex2f(-0.2f,0.5f); //T
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.1f,0.4f); //H
   glVertex2f(-0.1f,0.6f); //A
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.3f,0.4f); //B
   glVertex2f(-0.3f,-0.8f); //U
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.1f,0.4f); //H
   glVertex2f(-0.1f,-0.8f); //G
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.3f,0.2f); //I
   glVertex2f(-0.1f,0.2f); //J
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.3f,0.0f); //K
   glVertex2f(-0.1f,0.0f); //L
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.3f,-0.2f); //M
   glVertex2f(-0.1f,-0.2f); //N
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.5f,-0.4f); //D
   glVertex2f(-0.1f,-0.4f); //P
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.5f,-0.6f); //E
   glVertex2f(-0.1f,-0.6f); //Q
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.5f,-0.8f); //F
   glVertex2f(-0.1f,-0.8f); //G
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.5f,-0.8f); //F
   glVertex2f(-0.5f,-0.4f); //D
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.3f,-0.2f); //M
   glVertex2f(-0.5f,-0.4f); //D
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.5f,-0.8f); //F
   glVertex2f(-0.1f,-0.4f); //P
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.5f,-0.6f); //E
   glVertex2f(-0.1f,-0.2f); //N
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.5f,-0.6f); //E
   glVertex2f(-0.3f,-0.8f); //U
   glEnd();


   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.1f,-0.8f); //G
   glVertex2f(-0.5f,-0.4f); //D
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.4f,-0.3f); //C
   glVertex2f(-0.1f,-0.6f); //Q
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.3f,-0.2f); //M
   glVertex2f(-0.1f,-0.4f); //P
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.3f,-0.8f); //U
   glVertex2f(-0.1f,-0.6f); //Q
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.3f,0.4f); //B
   glVertex2f(-0.1f,0.2f); //J
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.1f,0.4f); //H
   glVertex2f(-0.3f,0.2f); //I
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.1f,0.0f); //L
   glVertex2f(-0.3f,0.2f); //I
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.3f,0.0f); //K
   glVertex2f(-0.1f,0.2f); //J
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.3f,0.0f); //K
    glVertex2f(-0.1f,-0.2f); //N
   glEnd();

   glBegin(GL_LINES);
   glColor3ub(187,188,192);
   glVertex2f(-0.3f,-0.2f); //M
   glVertex2f(-0.1f,0.0f); //L
   glEnd();
   glPopMatrix();

   ///////////////////////////////////////////////////////////////////////////************* smoke

   if(smoke==false)
   {
       glPushMatrix();

       glBegin(GL_QUADS); /////////////////////////smoke box
   glColor3ub(240,240,240);
   glVertex2f(0.05f,-0.8f);
   glVertex2f(0.05f,-1.0f);
   glVertex2f(0.44f,-1.0f);
   glVertex2f(0.44f,-0.8f);
   glEnd();

   GLfloat p3=0.55f; GLfloat q3=-0.9f; GLfloat r3=-0.15f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(240,240,240);
   glVertex2f(p3,q3);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  p3+(r3*cos(i*tp1/triangle1)), q3+(r3*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   GLfloat p4=-0.06f; GLfloat q4=-0.9f; GLfloat r4=-0.15f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(240,240,240);
   glVertex2f(p4,q4);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  p4+(r4*cos(i*tp1/triangle1)), q4+(r4*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   GLfloat p5=-0.2f; GLfloat q5=-0.75f; GLfloat r5=-0.15f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(240,240,240);
   glVertex2f(p5,q5);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  p5+(r5*cos(i*tp1/triangle1)), q5+(r5*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   GLfloat p6=-0.3f; GLfloat q6=-0.9f; GLfloat r6=-0.15f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(240,240,240);
   glVertex2f(p6,q6);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  p6+(r6*cos(i*tp1/triangle1)), q6+(r6*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   GLfloat p51=0.69f; GLfloat q51=-0.75f; GLfloat r51=-0.15f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(240,240,240);
   glVertex2f(p51,q51);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  p51+(r51*cos(i*tp1/triangle1)), q51+(r51*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   GLfloat p61=0.79f; GLfloat q61=-0.9f; GLfloat r61=-0.15f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(240,240,240);
   glVertex2f(p61,q61);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  p61+(r61*cos(i*tp1/triangle1)), q61+(r61*sin(i*tp1/triangle1))
                  );
   }
   glEnd();
glPopMatrix();

/////////////////////////////////////////////////////////////////////////////////////////***************fire
glPushMatrix();
   glTranslatef(0,-position, 0.0f);

   glBegin(GL_TRIANGLES);//////////////////////////////////////////left fire
   glColor3ub(240,192,11);
   glVertex2f(0.04f, -0.79f);
   glVertex2f(0.075f, -0.95f);
   glVertex2f(0.11f, -0.79f);
   glEnd();

   glBegin(GL_TRIANGLES);//////////////////////////////////////////center fire
   glColor3ub(240,192,11);
   glVertex2f(0.205f, -0.79f);
   glVertex2f(0.24f, -0.95f);
   glVertex2f(0.275f, -0.79f);
   glEnd();

   glBegin(GL_TRIANGLES);//////////////////////////////////////////right fire
   glColor3ub(240,192,11);
   glVertex2f(0.37f, -0.79f);
   glVertex2f(0.405f, -0.95f);
   glVertex2f(0.44f, -0.79f);
   glEnd();
   glPopMatrix();

   }

   glPushMatrix();

   glBegin(GL_QUADS); /////////////////////////ROCKET HOLDER UP
   glColor3ub(187,188,192);
   glVertex2f(-0.1f,0.22f);
   glVertex2f(-0.1f,0.12f);
   glVertex2f(0.25f,0.12f);
   glVertex2f(0.25f,0.22f);
   glEnd();

   glBegin(GL_QUADS); /////////////////////////ROCKET HOLDER DOWN
   glColor3ub(187,188,192);
   glVertex2f(-0.1f,-0.08f);
   glVertex2f(-0.1f,-0.18f);
   glVertex2f(0.25f,-0.18f);
   glVertex2f(0.25f,-0.08f);
   glEnd();

   glPopMatrix();



 /////////////////////////////////////////////////////////////////////////////****************************moon
  glPushMatrix();
  GLfloat p1=-0.7f; GLfloat q1=0.5f; GLfloat r1=-0.2f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(244,239,207);
   glVertex2f(p1,q1);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  p1+(r1*cos(i*tp1/triangle1)), q1+(r1*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   ///////////////////////////////////////////////////////////////////////moon half circle
   GLfloat p2=-0.65f; GLfloat q2=0.55f; GLfloat r2=-0.17f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3f(0.0f,0.0f,0.3f);
   glVertex2f(p2,q2);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  p2+(r2*cos(i*tp1/triangle1)), q2+(r2*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   ///////////////////////////////////////////////////////////////////////////////////////////////star left

   glBegin(GL_POLYGON);
   glColor3ub(240,192,11);
   glVertex2f(-0.825f,0.85f);//h
   glVertex2f(-0.875f,0.825f);//g
   glVertex2f(-0.825f,0.8f);//f
   glVertex2f(-0.8f,0.75f);//e
   glVertex2f(-0.775f,0.8f);//d
   glVertex2f(-0.725f,0.825f);//c
   glVertex2f(-0.775f,0.85f);//b
   glVertex2f(-0.8f,0.9f);//a
   glEnd();

   glPopMatrix();

////////////////////////////////////////////////////////////////////////////////////////////outer space design


   if(space== false)
   {

    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glPushMatrix();

    //////////////////////////////////////////////////////////////////////earth
    GLfloat pe=0.8f; GLfloat qe=-0.67f; GLfloat re=-0.55f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(0,33,85);
   glVertex2f(pe,qe);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  pe+(re*cos(i*tp1/triangle1)), qe+(re*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   /////////////////////////////////////////////////////////////////////////mars
   GLfloat pm=-0.98f; GLfloat qm=0.7f; GLfloat rm=-0.05f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(155,35,46);
   glVertex2f(pm,qm);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  pm+(rm*cos(i*tp1/triangle1)), qm+(rm*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   /////////////////////////////////////////////////////////////////////////mars spot 1
   GLfloat pms1=-0.98f; GLfloat qms1=0.68f; GLfloat rms1=-0.01f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(185,57,46);
   glVertex2f(pms1,qms1);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  pms1+(rms1*cos(i*tp1/triangle1)), qms1+(rms1*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   /////////////////////////////////////////////////////////////////////////mars spot 2
   GLfloat pms2=-0.96f; GLfloat qms2=0.72f; GLfloat rms2=-0.01f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(185,57,46);
   glVertex2f(pms2,qms2);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  pms2+(rms2*cos(i*tp1/triangle1)), qms2+(rms2*sin(i*tp1/triangle1))
                  );
   }
   glEnd();


   glBegin(GL_POLYGON);//////////////////////////////////////////////earth body Australia
   glColor3ub(79,148,1);

   glVertex2f(0.45f,-0.53f);//a
   glVertex2f(0.4f,-0.6f);//b
   glVertex2f(0.38f,-0.6f);//c
   glVertex2f(0.32f,-0.68f);//d
   glVertex2f(0.32,-0.68f);//e
   glVertex2f(0.3f,-0.78f);//f
   glVertex2f(0.3f,-0.8f);//g
   glVertex2f(0.32f,-0.81f);//h
   glVertex2f(0.35f,-0.88f);//i
   glVertex2f(0.45f,-0.9f);//j
   glVertex2f(0.5f,-0.88f);//k
   glVertex2f(0.52f,-0.9f);//l
   glVertex2f(0.56,-0.91f);//m
   glVertex2f(0.57f,-0.94f);//n
   glVertex2f(0.56f,-0.96f);//o
   glVertex2f(0.58f,-1.0f);//p
   glVertex2f(0.92f,-1.0f);//q
   glVertex2f(0.96f,-0.95f);//r
   glVertex2f(1.0f,-0.95f);//s
   glVertex2f(1.0f,-0.83f);//t
   glVertex2f(0.96,-0.84f);//u
   glVertex2f(0.82f,-0.65f);//v
   glVertex2f(0.8f,-0.59f);//w
   glVertex2f(0.65f,-0.61f);//x
   glVertex2f(0.63f,-0.6f);//y
   glVertex2f(0.58f,-0.54f);//z
   glVertex2f(0.5f,-0.5f);//aa
   glVertex2f(0.47f,-0.54f);//bb

   glEnd();

   glBegin(GL_POLYGON);//////////////////////////////////////////////earth body Australia
   glColor3ub(79,148,1);

   glVertex2f(0.92f,-0.2f);//a
   glVertex2f(0.89f,-0.14f);//b
   glVertex2f(0.9f,-0.2f);//c
   glVertex2f(0.82f,-0.22f);//d
   glVertex2f(0.76,-0.19f);//e
   glVertex2f(0.69f,-0.21f);//f
   glVertex2f(0.75f,-0.24f);//g
   glVertex2f(0.71f,-0.42f);//h
   glVertex2f(0.67f,-0.34f);//i
   glVertex2f(0.63f,-0.32f);//j
   glVertex2f(0.6f,-0.33f);//k
   glVertex2f(0.61f,-0.37f);//l
   glVertex2f(0.71,-0.45f);//m
   glVertex2f(0.8f,-0.53f);//n
   glVertex2f(0.83f,-0.53f);//o
   glVertex2f(0.81f,-0.61f);//p
   glVertex2f(0.95f,-0.8f);//q
   glVertex2f(1.0f,-0.79f);//r
   glVertex2f(1.0f,-0.25f);//s

   glEnd();
   glPopMatrix();

////////////////////////////////////////**************************Rocket scaling, translated, rotated***************
   glPushMatrix();

   glTranslatef(position1,-position1, 0.0f);
   glTranslated(0.4,-0.7,0.0);
   glRotated(90,15,15,15);

   glScaled(s,s,s);


   glBegin(GL_TRIANGLES); //////////////HEAD
   glColor3ub(238,28,37);

   glVertex2f(0.24f,0.6f);//a
   glVertex2f(0.14f, 0.42f);//b
   glVertex2f(0.34f, 0.42f);//c
   glEnd();

   glBegin(GL_POLYGON);/////////////////HEAD  Lower Body
   glColor3ub(230,230,230);
   glVertex2f(0.14f, 0.42f);//b
   glVertex2f(0.14f, 0.08f);//d
   glVertex2f(0.15f, 0.06f);//E
   glVertex2f(0.33f, 0.06f);//f
   glVertex2f(0.34f, 0.08f);//g
   glVertex2f(0.34f, 0.42f);//c
   glEnd();

   GLfloat pbg=0.24f; GLfloat qbg=0.25f; GLfloat rbg=-0.077f;////////////////////glass background

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(130,130,130);
   glVertex2f(pbg,qbg);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  pbg+(rbg*cos(i*tp1/triangle1)), qbg+(rbg*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   GLfloat pg=0.24f; GLfloat qg=0.25f; GLfloat rg=-0.07f;////////////////////glass

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(35,172,196);
   glVertex2f(pg,qg);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  pg+(rg*cos(i*tp1/triangle1)), qg+(rg*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   glBegin(GL_QUADS); /////////////////HEAD Lower Body shadow
   glColor3ub(187,188,192);
   glVertex2f(0.33f, 0.42f);//N'
   glVertex2f(0.33f, 0.06f);//f
   glVertex2f(0.34f, 0.08f);//g
   glVertex2f(0.34f, 0.42f);//c
   glEnd();

   glBegin(GL_QUADS); /////////////////HEAD Lower Body QUAD
   glColor3ub(187,188,192);
   glVertex2f(0.15f, 0.06f);//E
   glVertex2f(0.15f, 0.01f);//H
   glVertex2f(0.33f, 0.01f);//I
   glVertex2f(0.33f, 0.06f);//f
   glEnd();

   glBegin(GL_POLYGON); ///////////////// UNDER BODY QUAD
   glColor3ub(230,230,230);
   glVertex2f(0.15f, 0.01f);//H
   glVertex2f(0.14f, -0.01f);//K
   glVertex2f(0.14f, -0.74f);//L
   glVertex2f(0.34f, -0.74f);//M
   glVertex2f(0.34f, -0.01f);//J
   glVertex2f(0.33f, 0.01f);//I
   glEnd();

   glBegin(GL_QUADS); /////////////////UNDER BODY QUAD shadow
   glColor3ub(187,188,192);
   glVertex2f(0.33f, -0.74f);//N
   glVertex2f(0.34f, -0.74f);//M
   glVertex2f(0.34f, -0.01f);//J
   glVertex2f(0.33f, 0.01f);//I
   glEnd();


   glBegin(GL_POLYGON); ///////////////// LEFT WING
   glColor3ub(230,230,230);


   glVertex2f(0.1f, -0.25f);//P
   glVertex2f(0.05f, -0.25f);//Q
   glVertex2f(0.01f, -0.74f);//R
   glVertex2f(0.14f, -0.74f);//L
   glVertex2f(0.14f, -0.23f);//O


   glEnd();

   glBegin(GL_QUADS); /////////////////lEFT WING shadow
   glColor3ub(187,188,192);
   glVertex2f(0.1f, -0.25f);//P
   glVertex2f(0.06f, -0.74f);//S
   glVertex2f(0.14f, -0.74f);//L
   glVertex2f(0.14f, -0.23f);//O
   glEnd();


   ///////////////////////////////////////////RIGHT WING
   glBegin(GL_POLYGON);
   glColor3ub(230,230,230);


   glVertex2f(0.34f, -0.74f);//M
   glVertex2f(0.47f, -0.74f);//W
   glVertex2f(0.43f, -0.25f);//V
   glVertex2f(0.38f, -0.25f);//U
   glVertex2f(0.34f, -0.23f);//T

   glEnd();

   glBegin(GL_QUADS); /////////////////RIGHT WING shadow
   glColor3ub(187,188,192);
   glVertex2f(0.38f, -0.25f);//U
   glVertex2f(0.43f, -0.74f);//S'
   glVertex2f(0.47f, -0.74f);//W
   glVertex2f(0.43f, -0.25f);//V
   glEnd();

   glBegin(GL_QUADS); /////////////////LEFT fIRE EXIT
   glColor3ub(96,96,96);
   glVertex2f(0.05f, -0.74f);
   glVertex2f(0.04f, -0.79f);
   glVertex2f(0.11f, -0.79f);
   glVertex2f(0.1f, -0.74f);
   glEnd();

   glBegin(GL_QUADS); /////////////////CENTER fIRE EXIT
   glColor3ub(96,96,96);
   glVertex2f(0.215f, -0.74f);
   glVertex2f(0.205f, -0.79f);
   glVertex2f(0.275f, -0.79f);
   glVertex2f(0.265f, -0.74f);
   glEnd();

   glBegin(GL_QUADS); /////////////////RIGHT fIRE EXIT
   glColor3ub(96,96,96);
   glVertex2f(0.38f, -0.74f);
   glVertex2f(0.37f, -0.79f);
   glVertex2f(0.44f, -0.79f);
   glVertex2f(0.43f, -0.74f);
   glEnd();

   /////////////////////////////////////////////////////////////////////////////////////////fire



   glBegin(GL_TRIANGLES);//////////////////////////////////////////left fire
   glColor3ub(240,192,11);
   glVertex2f(0.04f, -0.79f);
   glVertex2f(0.075f, -0.95f);
   glVertex2f(0.11f, -0.79f);
   glEnd();

   glBegin(GL_TRIANGLES);//////////////////////////////////////////center fire
   glColor3ub(240,192,11);
   glVertex2f(0.205f, -0.79f);
   glVertex2f(0.24f, -0.95f);
   glVertex2f(0.275f, -0.79f);
   glEnd();

   glBegin(GL_TRIANGLES);//////////////////////////////////////////right fire
   glColor3ub(240,192,11);
   glVertex2f(0.37f, -0.79f);
   glVertex2f(0.405f, -0.95f);
   glVertex2f(0.44f, -0.79f);
   glEnd();

   glPopMatrix();
   }




   if(land==false)
   {
       glClearColor(0.0f,0.0f,0.0f,1.0f);
   glClear(GL_COLOR_BUFFER_BIT);

   glPushMatrix();


    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3ub(255,128,0); // Red

	glVertex2f(-1.0f, -0.3f);    // x, y
	glVertex2f(1.0f, -0.3f);
	glVertex2f(1.0f, -1.f);    // x, y
	glVertex2f(-1.f, -1.5f);



	    glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3ub(255,255,102); // Red

	glVertex2f(-1.0f, -0.3f);    // x, y
	glVertex2f(1.0f, -0.3f);
	glVertex2f(1.0f, 1.f);    // x, y
	glVertex2f(-1.f, 1.5f);

	glEnd();

	glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3ub(255,153,51); // Yellow

	glVertex2f(-1.f, 0.1f);
	glVertex2f(-0.99f, 0.13f);
	glVertex2f(-0.98f, 0.15f);
	glVertex2f(-0.98f, 0.16f);
	glVertex2f(-0.97f, 0.17f);
	glVertex2f(-0.97f, 0.18f);
	glVertex2f(-0.97f, 0.2f);
	glVertex2f(-0.96f, 0.2f);
	glVertex2f(-0.96f, 0.19f);
	glVertex2f(-0.92f, 0.12f);
	glVertex2f(-0.90f, 0.14f);
	glVertex2f(-0.90f, 0.2f);
    glVertex2f(-0.85f, 0.2f);
	glVertex2f(-0.8f, 0.0f);
	glVertex2f(-0.78f, -0.04f);
	glVertex2f(-0.67f, -0.3f);
    glVertex2f(-0.65f, -0.32f);
	glVertex2f(-0.65f, -0.31f);
	glVertex2f(-1.f, -0.3f);
	//glVertex2f(-0.92f, 0.12f);
	//glVertex2f(-0.4f, 0.6f);
	//glVertex2f(-0.3f, 0.4f);

	glEnd();



	glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3ub(255,153,51); // Yellow

	//glVertex2f(-0.93f, -0.48f);
	//glVertex2f(-0.91f, -0.42f);
	//glVertex2f(-0.90f, -0.41f);
	glVertex2f(-0.74f, -0.3f);
	glVertex2f(-0.74f, -0.16f);
	glVertex2f(-0.7f, -0.1f);
	glVertex2f(-0.67f, -0.1f);
	glVertex2f(-0.65f, 0.05f);
	glVertex2f(-0.62f, 0.05f);
	glVertex2f(-0.56f, 0.21f);
    glVertex2f(-0.55f, 0.21f);
	glVertex2f(-0.53f, 0.11f);
    glVertex2f(-0.52f, 0.11f);
	glVertex2f(-0.55f, 0.28f);
	glVertex2f(-0.52f, 0.3f);
    glVertex2f(-0.55f, 0.48f);
	glVertex2f(-0.50f, 0.3f);
    glVertex2f(-0.50f, 0.4f);
	glVertex2f(-0.40f, 0.17f);
    glVertex2f(-0.38f, 0.17f);
	glVertex2f(-0.34f, 0.02f);
	glVertex2f(-0.338f, 0.02f);
	glVertex2f(-0.34f, 0.1f);
	glVertex2f(-0.31f, 0.02f);

	glVertex2f(-0.29f, 0.02f);
	glVertex2f(-0.27f, -0.03f);
    glVertex2f(-0.26f, -0.02f);
	glVertex2f(-0.23f, -0.02f);
	glVertex2f(-0.20f, -0.10f);
	glVertex2f(-0.15f, -0.16f);
	glVertex2f(-0.10f, -0.20f);
    glVertex2f(-0.05f, -0.25f);
    glVertex2f(-0.04f, -0.26f);
    glVertex2f(-0.0f, -0.3f);

	glEnd();



	glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3ub(255,153,51); // Yellow

	//glVertex2f(1.0f, 0.19f);
   // glVertex2f(0.98f, 0.19f);
    //glVertex2f(0.91f, 0.0f);
//
    glVertex2f(0.88f, -0.07f);
    glVertex2f(0.84f, -0.04f);
    glVertex2f(0.82f, -0.07f);
    glVertex2f(0.80f, -0.05f);
    glVertex2f(0.79f, -0.04f);
    glVertex2f(0.77f, 0.0f);
    	glVertex2f(0.76f, 0.0f);
    glVertex2f(0.75f, 0.01f);
    glVertex2f(0.756f, 0.12f);
    	glVertex2f(0.74f, 0.15f);
    glVertex2f(0.66f, -0.06f);
    glVertex2f(0.62f, -0.02f);
    	glVertex2f(0.61f, 0.04f);
    glVertex2f(0.6f, 0.04f);
    glVertex2f(0.58f, 0.0f);
    	glVertex2f(0.54f, -0.09f);
    glVertex2f(0.52f, -0.09f);
    glVertex2f(0.50f, -0.14f);
    glVertex2f(0.50f, -0.10f);
    glVertex2f(0.47f, -0.10f);
    glVertex2f(0.40f, -0.20f);
    glVertex2f(0.30f, -0.23f);
    glVertex2f(0.27f, -0.28f);
    glVertex2f(0.25f, -0.3f);
    glVertex2f(0.54f, -0.35f);
    glVertex2f(1.0f, -0.35f);


	glEnd();


//shadow 1
	glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3ub(204,102,0); // Yellow
	//glVertex2f(1.0f, 0.19f);
    //glVertex2f(0.98f, 0.19f);
    //glVertex2f(0.91f, 0.0f);

    glVertex2f(-1.0f, -0.58f);
    glVertex2f(-0.9f, -0.58f);
    glVertex2f(-0.8f, -0.57f);
    glVertex2f(-0.72f, -0.55f);
    glVertex2f(-0.70f, -0.54f);
    glVertex2f(-0.60f, -0.53f);
    glVertex2f(-0.40f, -0.58f);
    glVertex2f(-0.35f, -0.60f);
    glVertex2f(-0.0f, -0.61f);
    glVertex2f(0.1f, -0.58f);
    glVertex2f(0.35f, -0.58f);
    glVertex2f(0.1f, -0.59f);
    glVertex2f(0.0f, -0.61f);
    glVertex2f(-0.2f, -0.62f);
   glVertex2f(-1.0f, -0.60f);
  //  glVertex2f(-0.0f, -0.0f);
   // glVertex2f(-0.0f, -0.0f);



	glEnd();
//shadow 2
	glBegin(GL_POLYGON);   // These vertices form a closed polygon
	glColor3ub(204,102,0); // Yellow
	//glVertex2f(1.0f, 0.19f);
    //glVertex2f(0.98f, 0.19f);
    //glVertex2f(0.91f, 0.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.74f);
    glVertex2f(0.77f, -0.77f);
    glVertex2f(0.8f, -0.8f);
    glVertex2f(0.70f, -0.80f);
    glVertex2f(0.60f, -0.83f);
    glVertex2f(0.50f, -0.83f);
    glVertex2f(0.40f, -0.82f);
    glVertex2f(0.30f, -0.81f);
    glVertex2f(0.40f, -0.89f);
    glVertex2f(0.15f, -0.90f);
    glVertex2f(0.0f, -0.93f);
    glVertex2f(-0.30f, -0.88f);
    glVertex2f(-0.60f, -0.89f);
    glVertex2f(-0.80f, -0.85f);
    glVertex2f(-0.62f, -0.78f);
    glVertex2f(-1.00f, -0.72f);
	glEnd();


	//shadow 3
	glBegin(GL_POLYGON);   // These vertices form a closed polygon
	glColor3ub(204,102,0); // Yellow
	//glVertex2f(1.0f, 0.19f);
    //glVertex2f(0.98f, 0.19f);
    //glVertex2f(0.91f, 0.0f);
    glVertex2f(1.0f, -0.62f);
    glVertex2f(0.90f, -0.62f);
    glVertex2f(0.70f, -0.63f);
    glVertex2f(0.50f, -0.63f);
    glVertex2f(0.40f, -0.65f);
    glVertex2f(0.20f, -0.69f);
    glVertex2f(0.50f, -0.68f);
    glVertex2f(0.70f, -0.67f);
    glVertex2f(0.80f, -0.66f);
    glVertex2f(1.0f, -0.69f);

	glEnd();

	if(night==false)///////////////////////////////////////////////////////////////////////night
   {
       glPushMatrix();
       ///////////////////////////////////////////////////////////////////////////////////////////////////night sky
       glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3ub(80,80,80); // Red

	glVertex2f(-1.0f, -0.3f);    // x, y
	glVertex2f(1.0f, -0.3f);
	glVertex2f(1.0f, 1.f);    // x, y
	glVertex2f(-1.f, 1.5f);

	glEnd();

	glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3ub(255,153,51); // Yellow

	glVertex2f(-1.f, 0.1f);
	glVertex2f(-0.99f, 0.13f);
	glVertex2f(-0.98f, 0.15f);
	glVertex2f(-0.98f, 0.16f);
	glVertex2f(-0.97f, 0.17f);
	glVertex2f(-0.97f, 0.18f);
	glVertex2f(-0.97f, 0.2f);
	glVertex2f(-0.96f, 0.2f);
	glVertex2f(-0.96f, 0.19f);
	glVertex2f(-0.92f, 0.12f);
	glVertex2f(-0.90f, 0.14f);
	glVertex2f(-0.90f, 0.2f);
    glVertex2f(-0.85f, 0.2f);
	glVertex2f(-0.8f, 0.0f);
	glVertex2f(-0.78f, -0.04f);
	glVertex2f(-0.67f, -0.3f);
    glVertex2f(-0.65f, -0.32f);
	glVertex2f(-0.65f, -0.31f);
	glVertex2f(-1.f, -0.3f);
	//glVertex2f(-0.92f, 0.12f);
	//glVertex2f(-0.4f, 0.6f);
	//glVertex2f(-0.3f, 0.4f);

	glEnd();



	glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3ub(255,153,51); // Yellow

	//glVertex2f(-0.93f, -0.48f);
	//glVertex2f(-0.91f, -0.42f);
	//glVertex2f(-0.90f, -0.41f);
	glVertex2f(-0.74f, -0.3f);
	glVertex2f(-0.74f, -0.16f);
	glVertex2f(-0.7f, -0.1f);
	glVertex2f(-0.67f, -0.1f);
	glVertex2f(-0.65f, 0.05f);
	glVertex2f(-0.62f, 0.05f);
	glVertex2f(-0.56f, 0.21f);
    glVertex2f(-0.55f, 0.21f);
	glVertex2f(-0.53f, 0.11f);
    glVertex2f(-0.52f, 0.11f);
	glVertex2f(-0.55f, 0.28f);
	glVertex2f(-0.52f, 0.3f);
    glVertex2f(-0.55f, 0.48f);
	glVertex2f(-0.50f, 0.3f);
    glVertex2f(-0.50f, 0.4f);
	glVertex2f(-0.40f, 0.17f);
    glVertex2f(-0.38f, 0.17f);
	glVertex2f(-0.34f, 0.02f);
	glVertex2f(-0.338f, 0.02f);
	glVertex2f(-0.34f, 0.1f);
	glVertex2f(-0.31f, 0.02f);

	glVertex2f(-0.29f, 0.02f);
	glVertex2f(-0.27f, -0.03f);
    glVertex2f(-0.26f, -0.02f);
	glVertex2f(-0.23f, -0.02f);
	glVertex2f(-0.20f, -0.10f);
	glVertex2f(-0.15f, -0.16f);
	glVertex2f(-0.10f, -0.20f);
    glVertex2f(-0.05f, -0.25f);
    glVertex2f(-0.04f, -0.26f);
    glVertex2f(-0.0f, -0.3f);

	glEnd();



	glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3ub(255,153,51); // Yellow

	//glVertex2f(1.0f, 0.19f);
   // glVertex2f(0.98f, 0.19f);
    //glVertex2f(0.91f, 0.0f);
//
    glVertex2f(0.88f, -0.07f);
    glVertex2f(0.84f, -0.04f);
    glVertex2f(0.82f, -0.07f);
    glVertex2f(0.80f, -0.05f);
    glVertex2f(0.79f, -0.04f);
    glVertex2f(0.77f, 0.0f);
    	glVertex2f(0.76f, 0.0f);
    glVertex2f(0.75f, 0.01f);
    glVertex2f(0.756f, 0.12f);
    	glVertex2f(0.74f, 0.15f);
    glVertex2f(0.66f, -0.06f);
    glVertex2f(0.62f, -0.02f);
    	glVertex2f(0.61f, 0.04f);
    glVertex2f(0.6f, 0.04f);
    glVertex2f(0.58f, 0.0f);
    	glVertex2f(0.54f, -0.09f);
    glVertex2f(0.52f, -0.09f);
    glVertex2f(0.50f, -0.14f);
    glVertex2f(0.50f, -0.10f);
    glVertex2f(0.47f, -0.10f);
    glVertex2f(0.40f, -0.20f);
    glVertex2f(0.30f, -0.23f);
    glVertex2f(0.27f, -0.28f);
    glVertex2f(0.25f, -0.3f);
    glVertex2f(0.54f, -0.35f);
    glVertex2f(1.0f, -0.35f);


	glEnd();




       GLfloat pm=0.24f; GLfloat qm=0.40f; GLfloat rm=-0.077f;//////////////////////////////////////////////mars moon

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(255,255,255);
   glVertex2f(pm,qm);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  pm+(rm*cos(i*tp1/triangle1)), qm+(rm*sin(i*tp1/triangle1))
                  );
   }
   glEnd();
   GLfloat pm2=0.50f; GLfloat qm2=0.45f; GLfloat rm2=-0.077f;
     glBegin(GL_TRIANGLE_FAN);//moon 2
   glColor3ub(255,255,255);
   glVertex2f(pm2,qm2);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  pm2+(rm2*cos(i*tp1/triangle1)), qm2+(rm2*sin(i*tp1/triangle1))
                  );
   }
   glEnd();
   glPopMatrix();
   }

	/////////////////////////////////////////////////////////////////////////////////////////////////////house12

   if(house1==false)
   {
   glPushMatrix();
   // house back left
glBegin(GL_QUADS);
	glColor3ub(199,211,213);

	glVertex2f(-.90f, -0.1f);
	glVertex2f(-0.77f, -0.1f);
	glVertex2f(-0.77f, -0.63f);
	glVertex2f(-0.90f, -0.63f);
glEnd();
glBegin(GL_QUADS);//roof
	glColor3ub(146,204,212);

	glVertex2f(-.91f, -0.1f);
	glVertex2f(-0.76, -0.1f);
	glVertex2f(-0.76f, -0.07f);
	glVertex2f(-0.91f, -0.07f);
glEnd();

glBegin(GL_QUADS);//window left up
	glColor3ub(240,248,249);

	glVertex2f(-0.88f, -0.17f);
	glVertex2f(-0.88f, -0.13f);
	glVertex2f(-0.85f, -0.13f);
	glVertex2f(-0.85f, -0.17f);
glEnd();

glBegin(GL_QUADS);//window left 2nd
	glColor3ub(240,248,249);

	glVertex2f(-0.88f, -0.24f);
	glVertex2f(-0.88f, -0.19f);
	glVertex2f(-0.85f, -0.19f);
	glVertex2f(-0.85f, -0.24f);
glEnd();

glBegin(GL_QUADS);//window left 3rd
	glColor3ub(240,248,249);

	glVertex2f(-0.88f, -0.26f);
	glVertex2f(-0.88f, -0.31f);
	glVertex2f(-0.85f, -0.31f);
	glVertex2f(-0.85f, -0.26f);
glEnd();

glBegin(GL_QUADS);//window right1st up
	glColor3ub(240,248,249);

	glVertex2f(-0.83f, -0.17f);
	glVertex2f(-0.83f, -0.13f);
	glVertex2f(-0.80f, -0.13f);
	glVertex2f(-0.80f, -0.17f);
glEnd();


glBegin(GL_QUADS);//window right 2nd up
	glColor3ub(240,248,249);

	glVertex2f(-0.83f, -0.19f);
	glVertex2f(-0.83f, -0.24f);
	glVertex2f(-0.80f, -0.24f);
	glVertex2f(-0.80f, -0.19f);
glEnd();


glBegin(GL_QUADS);//window right3rdst up
	glColor3ub(240,248,249);

	glVertex2f(-0.83f, -0.26f);
	glVertex2f(-0.83f, -0.31f);
	glVertex2f(-0.80f, -0.31f);
	glVertex2f(-0.80f, -0.26f);
glEnd();

//house 1 from left
  glBegin(GL_QUADS);
	glColor3ub(81,172,189);

	glVertex2f(-.97f, -0.63f);
	glVertex2f(-0.97f, -0.40f);
	glVertex2f(-0.85f, -0.40f);
	glVertex2f(-0.85f, -0.63f);
glEnd();

  glBegin(GL_QUADS);//roof
	glColor3ub(146,58,145);

	glVertex2f(-0.98f, -0.40f);
	glVertex2f(-0.84f, -0.40f);
	glVertex2f(-0.855f, -0.29f);
	glVertex2f(-0.965f, -0.29f);
glEnd();
 glBegin(GL_QUADS);
	glColor3ub(146,58,145);

	glVertex2f(-0.965f, -0.29f);
	glVertex2f(-0.95f, -0.29f);
	glVertex2f(-0.95f, -0.26f);
	glVertex2f(-0.965f, -0.26f);
glEnd();

  glBegin(GL_QUADS);//left window up
	glColor3ub(141,209,218);

	glVertex2f(-0.95f, -0.50f);
	glVertex2f(-0.93f, -0.50f);
	glVertex2f(-0.93f, -0.43f);
	glVertex2f(-0.95f, -0.43f);
glEnd();

glBegin(GL_QUADS);//left window down
	glColor3ub(141,209,218);

	glVertex2f(-0.95f, -0.60f);
	glVertex2f(-0.93f, -0.60f);
	glVertex2f(-0.93f, -0.53f);
	glVertex2f(-0.95f, -0.53f);
glEnd();

 glBegin(GL_QUADS);//right window up
	glColor3ub(141,209,218);

	glVertex2f(-0.90f, -0.50f);
	glVertex2f(-0.88f, -0.50f);
	glVertex2f(-0.88f, -0.43f);
	glVertex2f(-0.90f, -0.43f);
glEnd();

 glBegin(GL_QUADS);//right window down
	glColor3ub(141,209,218);

	glVertex2f(-0.90f, -0.62f);
	glVertex2f(-0.88f, -0.62f);
	glVertex2f(-0.88f, -0.545f);
	glVertex2f(-0.90f, -0.545f);

glEnd();

glBegin(GL_TRIANGLES);   //
glColor3ub(135,206,235);

	glVertex2f(-0.90f, -0.545f);    // x, y
	glVertex2f(-0.88f, -0.545f);
	glVertex2f(-0.89f,  -0.53f);
	glEnd();


	//house 3 from left

glBegin(GL_QUADS);  //structure
glColor3ub(137,209,207);

	glVertex2f(-0.83f, -0.63f);
	glVertex2f(-0.63f, -0.63f);
	glVertex2f(-0.63f, -0.23f);
	glVertex2f(-0.83f, -0.23f);
	glEnd();

	glBegin(GL_QUADS);  //roof
glColor3ub(81,172,189);

	glVertex2f(-0.84f, -0.23f);
	glVertex2f(-0.62f, -0.23f);
	glVertex2f(-0.65f, -0.17f);
	glVertex2f(-0.81f, -0.17f);
	glEnd();

		glBegin(GL_QUADS);  //roof antena
glColor3ub(10,73,123);

	glVertex2f(-0.80f, -0.17f);
	glVertex2f(-0.77f, -0.17f);
	glVertex2f(-0.77f, -0.13f);
	glVertex2f(-0.80f, -0.13f);
	glEnd();

		glBegin(GL_QUADS);  //window from left
glColor3ub(219,239,243);

	glVertex2f(-0.81f, -0.35f);
	glVertex2f(-0.78f, -0.35f);
	glVertex2f(-0.78f, -0.28f);
	glVertex2f(-0.81f, -0.28f);
	glEnd();
		glBegin(GL_QUADS);  //window from left 2ndst row
glColor3ub(219,239,243);

	glVertex2f(-0.75f, -0.35f);
	glVertex2f(-0.72f, -0.35f);
	glVertex2f(-0.72f, -0.28f);
	glVertex2f(-0.75f, -0.28f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(219,239,243);//window 3rd

	glVertex2f(-0.69f, -0.35f);
	glVertex2f(-0.66f, -0.35f);
	glVertex2f(-0.66f, -0.28f);
	glVertex2f(-0.69f, -0.28f);
	glEnd();
//window 2nd rpw
	glBegin(GL_QUADS);  //window from lleft 1st 2nd row
glColor3ub(219,239,243);

	glVertex2f(-0.81f, -0.38f);
	glVertex2f(-0.78f, -0.38f);
	glVertex2f(-0.78f, -0.45f);
	glVertex2f(-0.81f, -0.45f);
	glEnd();

		glBegin(GL_QUADS);  //window from left 2ndst row
glColor3ub(219,239,243);

	glVertex2f(-0.75f, -0.38f);
	glVertex2f(-0.72f, -0.38f);
	glVertex2f(-0.72f, -0.45f);
	glVertex2f(-0.75f, -0.45f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3ub(219,239,243);//window 3rd

	glVertex2f(-0.69f, -0.38f);
	glVertex2f(-0.66f, -0.38f);
	glVertex2f(-0.66f, -0.45f);
	glVertex2f(-0.69f, -0.45f);
	glEnd();
	//window 3rd rpw
	glBegin(GL_QUADS);//1st
glColor3ub(219,239,243);

	glVertex2f(-0.81f, -0.48f);
	glVertex2f(-0.78f, -0.48f);
	glVertex2f(-0.78f, -0.55f);
	glVertex2f(-0.81f, -0.55f);
	glEnd();
glBegin(GL_QUADS);  //2nd
glColor3ub(219,239,243);

	glVertex2f(-0.75f, -0.48f);
	glVertex2f(-0.72f, -0.48f);
	glVertex2f(-0.72f, -0.55f);
	glVertex2f(-0.75f, -0.55f);
	glEnd();
glBegin(GL_QUADS);
	glColor3ub(219,239,243);//window 3rd

	glVertex2f(-0.69f, -0.48f);
	glVertex2f(-0.66f, -0.48f);
	glVertex2f(-0.66f, -0.55f);
	glVertex2f(-0.69f, -0.55f);
	glEnd();

   glPopMatrix();
   }

   if(house2==false)
   {

    glPushMatrix();
       // house 4
glBegin(GL_QUADS);
	glColor3ub(81,172,188);//window 3rd

	glVertex2f(-0.66f, -0.63f);
	glVertex2f(-0.53f, -0.63f);
	glVertex2f(-0.53f, -0.40f);
	glVertex2f(-0.66f, -0.40f);
	glEnd();

	glBegin(GL_QUADS);//roof
	glColor3ub(146,58,145);

	glVertex2f(-0.68f, -0.40f);
	glVertex2f(-0.51f, -0.40f);
	glVertex2f(-0.54f, -0.30f);
	glVertex2f(-0.65f, -0.30f);
	glEnd();
	//window from left 1st row
		glBegin(GL_QUADS);//1st
glColor3ub(219,239,243);
	glVertex2f(-0.65f, -0.48f);
	glVertex2f(-0.62f, -0.48f);
	glVertex2f(-0.62f, -0.43f);
	glVertex2f(-0.65f, -0.43f);
	glEnd();

			glBegin(GL_QUADS);//2md
glColor3ub(219,239,243);
	glVertex2f(-0.61f, -0.48f);
	glVertex2f(-0.58f, -0.48f);
	glVertex2f(-0.58f, -0.43f);
	glVertex2f(-0.61f, -0.43f);
	glEnd();

    glBegin(GL_QUADS);//3rd
    glColor3ub(219,239,243);
	glVertex2f(-0.57f, -0.48f);
	glVertex2f(-0.54f, -0.48f);
	glVertex2f(-0.54f, -0.43f);
	glVertex2f(-0.57f, -0.43f);
	glEnd();
	//window from 2nd
	glBegin(GL_QUADS);//1st
    glColor3ub(219,239,243);
	glVertex2f(-0.65f, -0.55f);
	glVertex2f(-0.62f, -0.55f);
	glVertex2f(-0.62f, -0.50f);
	glVertex2f(-0.65f, -0.50f);
	glEnd();
	glBegin(GL_QUADS);//2md
glColor3ub(219,239,243);
	glVertex2f(-0.61f, -0.55f);
	glVertex2f(-0.58f, -0.55f);
	glVertex2f(-0.58f, -0.50f);
	glVertex2f(-0.61f, -0.50f);
	glEnd();
	glBegin(GL_QUADS);//3rd
glColor3ub(219,239,243);
	glVertex2f(-0.57f, -0.55f);
	glVertex2f(-0.54f, -0.55f);
	glVertex2f(-0.54f, -0.50f);
	glVertex2f(-0.57f, -0.50f);
	glEnd();


	//window from 3nd

	glBegin(GL_QUADS);//1st
glColor3ub(219,239,243);
	glVertex2f(-0.65f, -0.62f);
	glVertex2f(-0.62f, -0.62f);
	glVertex2f(-0.62f, -0.57f);
	glVertex2f(-0.65f, -0.57f);
	glEnd();
glBegin(GL_QUADS);//2md
glColor3ub(48,135,175);
	glVertex2f(-0.61f, -0.63f);
	glVertex2f(-0.58f, -0.63f);
	glVertex2f(-0.58f, -0.56f);
	glVertex2f(-0.61f, -0.56f);
	glEnd();
	glBegin(GL_QUADS);//3rd
glColor3ub(219,239,243);
	glVertex2f(-0.57f, -0.62f);
	glVertex2f(-0.54f, -0.62f);
	glVertex2f(-0.54f, -0.57f);
	glVertex2f(-0.57f, -0.57f);
	glEnd();




	////house 5
	glBegin(GL_QUADS);//3rd
glColor3ub(43,135,175);
	glVertex2f(-0.51f, -0.63f);
	glVertex2f(-0.37f, -0.63f);
	glVertex2f(-0.37f, -0.27f);
	glVertex2f(-0.51f, -0.27f);
	glEnd();

		glBegin(GL_QUADS);//roof
glColor3ub(10,73,123);
	glVertex2f(-0.52f, -0.27f);
	glVertex2f(-0.36f, -0.27f);
	glVertex2f(-0.38f, -0.18f);
	glVertex2f(-0.50f, -0.18f);
	glEnd();
	//window 1st column
			glBegin(GL_QUADS);//1st
glColor3ub(125,180,205);
	glVertex2f(-0.50f, -0.30f);
	glVertex2f(-0.47f, -0.30f);
	glVertex2f(-0.47f, -0.36f);
	glVertex2f(-0.50f, -0.36f);
	glEnd();

	glBegin(GL_QUADS);//2st
glColor3ub(125,180,205);
	glVertex2f(-0.50f, -0.38f);
	glVertex2f(-0.47f, -0.38f);
	glVertex2f(-0.47f, -0.44f);
	glVertex2f(-0.50f, -0.44f);
	glEnd();

	glBegin(GL_QUADS);//3rd
glColor3ub(125,180,205);
	glVertex2f(-0.50f, -0.46f);
	glVertex2f(-0.47f, -0.46f);
	glVertex2f(-0.47f, -0.52f);
	glVertex2f(-0.50f, -0.52f);
	glEnd();

	glBegin(GL_QUADS);//4st
glColor3ub(125,180,205);
	glVertex2f(-0.50f, -0.54f);
	glVertex2f(-0.47f, -0.54f);
	glVertex2f(-0.47f, -0.60f);
	glVertex2f(-0.50f, -0.60f);
	glEnd();
	//window 2nd column
	glBegin(GL_QUADS);//1st
glColor3ub(125,180,205);
	glVertex2f(-0.46f, -0.30f);
	glVertex2f(-0.43f, -0.30f);
	glVertex2f(-0.43f, -0.36f);
	glVertex2f(-0.46f, -0.36f);
	glEnd();

	glBegin(GL_QUADS);//2st
glColor3ub(125,180,205);
	glVertex2f(-0.46f, -0.38f);
	glVertex2f(-0.43f, -0.38f);
	glVertex2f(-0.43f, -0.44f);
	glVertex2f(-0.46f, -0.44f);
	glEnd();

	glBegin(GL_QUADS);//3rd
glColor3ub(125,180,205);
	glVertex2f(-0.46f, -0.46f);
	glVertex2f(-0.43f, -0.46f);
	glVertex2f(-0.43f, -0.52f);
	glVertex2f(-0.46f, -0.52f);
	glEnd();

	glBegin(GL_QUADS);//4st
glColor3ub(146,58,145);
	glVertex2f(-0.46f, -0.54f);
	glVertex2f(-0.43f, -0.54f);
	glVertex2f(-0.43f, -0.63f);
	glVertex2f(-0.46f, -0.63f);
	glEnd();

		//window 3st column
			glBegin(GL_QUADS);//1st
glColor3ub(125,180,205);
	glVertex2f(-0.42f, -0.30f);
	glVertex2f(-0.39f, -0.30f);
	glVertex2f(-0.39f, -0.36f);
	glVertex2f(-0.42f, -0.36f);
	glEnd();

	glBegin(GL_QUADS);//2st
glColor3ub(125,180,205);
	glVertex2f(-0.42f, -0.38f);
	glVertex2f(-0.39f, -0.38f);
	glVertex2f(-0.39f, -0.44f);
	glVertex2f(-0.42f, -0.44f);
	glEnd();

	glBegin(GL_QUADS);//3rd
glColor3ub(125,180,205);
	glVertex2f(-0.42f, -0.46f);
	glVertex2f(-0.39f, -0.46f);
	glVertex2f(-0.39f, -0.52f);
	glVertex2f(-0.42f, -0.52f);
	glEnd();

	glBegin(GL_QUADS);//4st
glColor3ub(125,180,205);
	glVertex2f(-0.42f, -0.54f);
	glVertex2f(-0.39f, -0.54f);
	glVertex2f(-0.39f, -0.60f);
	glVertex2f(-0.42f, -0.60f);
	glEnd();


	////house 6
	glBegin(GL_QUADS);
glColor3ub(87,170,161);
	glVertex2f(-0.33f, -0.63f);
	glVertex2f(-0.15f, -0.63f);
	glVertex2f(-0.15f, -0.38f);
	glVertex2f(-0.33f, -0.38f);
	glEnd();

		glBegin(GL_QUADS);//roof
glColor3ub(146,58,145);
	glVertex2f(-0.34f, -0.38f);
	glVertex2f(-0.14f, -0.38f);
	glVertex2f(-0.16f, -0.30f);
	glVertex2f(-0.32f, -0.30f);
	glEnd();
//window by row
		glBegin(GL_QUADS);//1st
glColor3ub(193,230,233);
	glVertex2f(-0.32f, -0.46f);
	glVertex2f(-0.28f, -0.46f);
	glVertex2f(-0.28f, -0.40f);
	glVertex2f(-0.32f, -0.40f);
	glEnd();

	glBegin(GL_QUADS);//window
glColor3ub(193,230,233);
	glVertex2f(-0.26f, -0.46f);
	glVertex2f(-0.22f, -0.46f);
	glVertex2f(-0.22f, -0.40f);
	glVertex2f(-0.26f, -0.40f);
	glEnd();
glBegin(GL_QUADS);//3rd
glColor3ub(193,230,233);
	glVertex2f(-0.20f, -0.46f);
	glVertex2f(-0.16f, -0.46f);
	glVertex2f(-0.16f, -0.40f);
	glVertex2f(-0.20f, -0.40f);
	glEnd();

	//window 2nd column
	glBegin(GL_QUADS);//1st
glColor3ub(193,230,233);
	glVertex2f(-0.32f, -0.50f);
	glVertex2f(-0.28f, -0.50f);
	glVertex2f(-0.28f, -0.56f);
	glVertex2f(-0.32f, -0.56f);
	glEnd();

	glBegin(GL_QUADS);//3rd
glColor3ub(193,230,233);
	glVertex2f(-0.20f, -0.50f);
	glVertex2f(-0.16f, -0.50f);
	glVertex2f(-0.16f, -0.56f);
	glVertex2f(-0.20f, -0.56f);
	glEnd();
glBegin(GL_QUADS);//3rd
glColor3ub(10,73,123);
	glVertex2f(-0.26f, -0.50f);
	glVertex2f(-0.22f, -0.50f);
	glVertex2f(-0.22f, -0.63f);
	glVertex2f(-0.26f, -0.63f);
	glEnd();

	glPopMatrix();
   }

   if(tree==false)///////////////////////////////////////////////////////////////////tree
   {

       glPushMatrix();
       //tree1
glBegin(GL_TRIANGLES);   //
glColor3ub(0,128,0);
	glVertex2f(-1.0f, -0.59f);    // x, y
	glVertex2f(-0.95f, -0.59f);
	glVertex2f(-0.975f,  -0.52f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(0,128,0);
	glVertex2f(-1.0f, -0.57f);    // x, y
	glVertex2f(-0.95f, -0.57f);
	glVertex2f(-0.975f,  -0.52f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(0,128,0);
	glVertex2f(-1.0f, -0.55f);    // x, y
	glVertex2f(-0.95f, -0.55f);
	glVertex2f(-0.975f,  -0.52f);
	glEnd();
	glBegin(GL_QUADS);//3rd
glColor3ub(128,0,0);
	glVertex2f(-0.98f, -0.59f);
	glVertex2f(-0.97f, -0.59f);
	glVertex2f(-0.97f, -0.65f);
	glVertex2f(-0.98f, -0.65f);
	glEnd();

	//tree 2
	glBegin(GL_TRIANGLES);   //
glColor3ub(0,128,0);
	glVertex2f(-.85f, -0.59f);    // x, y
	glVertex2f(-0.80f, -0.59f);
	glVertex2f(-0.825f,  -0.52f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(0,128,0);
	glVertex2f(-0.85f, -0.57f);    // x, y
	glVertex2f(-0.80f, -0.57f);
	glVertex2f(-0.825f,  -0.52f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(0,128,0);
	glVertex2f(-0.85f, -0.55f);    // x, y
	glVertex2f(-0.80f, -0.55f);
	glVertex2f(-0.825f,  -0.52f);
	glEnd();
	glBegin(GL_QUADS);//3rd
glColor3ub(128,0,0);
	glVertex2f(-0.82f, -0.59f);
	glVertex2f(-0.83f, -0.59f);
	glVertex2f(-0.83f, -0.65f);
	glVertex2f(-0.82f, -0.65f);
	glEnd();
//tree 3
	glBegin(GL_TRIANGLES);   //
glColor3ub(0,128,0);
	glVertex2f(-.35f, -0.59f);    // x, y
	glVertex2f(-0.40f, -0.59f);
	glVertex2f(-0.375f,  -0.52f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(0,128,0);
	glVertex2f(-0.35f, -0.57f);    // x, y
	glVertex2f(-0.40f, -0.57f);
	glVertex2f(-0.375f,  -0.52f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(0,128,0);
	glVertex2f(-0.35f, -0.55f);    // x, y
	glVertex2f(-0.40f, -0.55f);
	glVertex2f(-0.375f,  -0.52f);
	glEnd();
	glBegin(GL_QUADS);//3rd
glColor3ub(128,0,0);
	glVertex2f(-0.37f, -0.59f);
	glVertex2f(-0.38f, -0.59f);
	glVertex2f(-0.38f, -0.65f);
	glVertex2f(-0.37f, -0.65f);
	glEnd();

//tree 4
	glBegin(GL_TRIANGLES);   //
glColor3ub(0,128,0);
	glVertex2f(-.15f, -0.59f);    // x, y
	glVertex2f(-0.10f, -0.59f);
	glVertex2f(-0.125f,  -0.52f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(0,128,0);
	glVertex2f(-0.15f, -0.57f);    // x, y
	glVertex2f(-0.10f, -0.57f);
	glVertex2f(-0.125f,  -0.52f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3ub(0,128,0);
	glVertex2f(-0.15f, -0.55f);    // x, y
	glVertex2f(-0.10f, -0.55f);
	glVertex2f(-0.125f,  -0.52f);
	glEnd();
	glBegin(GL_QUADS);//3rd
glColor3ub(128,0,0);
	glVertex2f(-0.12f, -0.59f);
	glVertex2f(-0.13f, -0.59f);
	glVertex2f(-0.13f, -0.65f);
	glVertex2f(-0.12f, -0.65f);
	glEnd();

	mover=true;

	glPopMatrix();
   }

   if(water==false)//////////////////////////////////////////////////////////////////////////////////water
   {

       glPushMatrix();
       glLineWidth(2);
       //water
   	glBegin(GL_POLYGON);   // These vertices form a closed polygon

	glColor3ub(103,200,243);

    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.74f);
    glVertex2f(0.77f, -0.77f);
    glVertex2f(0.8f, -0.8f);
    glVertex2f(0.70f, -0.80f);
    glVertex2f(0.60f, -0.83f);
    glVertex2f(0.50f, -0.83f);
    glVertex2f(0.40f, -0.82f);
    glVertex2f(0.30f, -0.81f);
    glVertex2f(0.40f, -0.89f);
    glVertex2f(0.15f, -0.90f);
    glVertex2f(0.0f, -0.93f);
    glVertex2f(-0.30f, -0.88f);
    glVertex2f(-0.60f, -0.89f);
    glVertex2f(-0.80f, -0.85f);
    glVertex2f(-0.62f, -0.78f);
    glVertex2f(-1.00f, -0.72f);
	glEnd();
	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(-0.8f,-0.87f); //B
   glVertex2f(-0.87f,-0.87f); //J
   glEnd();

   	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(-0.83f,-0.86f); //B
   glVertex2f(-0.85f,-0.86f); //J
   glEnd();

	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(-0.65f,-0.88f); //B
   glVertex2f(-0.68f,-0.88f); //J
   glEnd();

   	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(-0.8f,-0.87f); //B
   glVertex2f(-0.87f,-0.87f); //J
   glEnd();

   	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(-0.35f,-0.92f); //B
   glVertex2f(-0.40f,-0.92f); //J
   glEnd();

   	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(-0.1f,-0.94f); //B
   glVertex2f(-0.15f,-0.94f); //J
   glEnd();

   	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(-0.0f,-0.96f); //B
   glVertex2f(-0.14f,-0.96f); //J
   glEnd();

   	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(0.05f,-0.97f); //B
   glVertex2f(0.1f,-0.97f); //J
   glEnd();

   	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(0.3f,-0.95f); //B
   glVertex2f(0.35f,-0.95f); //J
   glEnd();

   	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(0.5f,-0.97f); //B
   glVertex2f(0.55f,-0.97f); //J
   glEnd();
   	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(0.58f,-0.87f); //B
   glVertex2f(0.63f,-0.87f); //J
   glEnd();

   	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(0.75f,-0.85f); //B
   glVertex2f(0.70f,-0.85f); //J
   glEnd();

   	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(0.95f,-0.89f); //B
   glVertex2f(0.90f,-0.89f); //J
   glEnd();

   	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(-0.95f,-0.97f); //B
   glVertex2f(-0.90f,-0.97f); //J
   glEnd();

   	   glBegin(GL_LINES);
   glColor3ub(255,255,255);
   glVertex2f(-0.95f,-0.8f); //B
   glVertex2f(-0.90f,-0.8f); //J
   glEnd();

   glPopMatrix();
   }



	glPopMatrix();



////////////////////////////////////////////////////////////************************rocket landing on mars

       glPushMatrix();

       glTranslatef(0.0f,position2, 0.0f);
   glTranslated(0.3,1.0,0.0);
   glScalef(0.4f,0.4f,0.0f);


       glBegin(GL_TRIANGLES); //////////////HEAD
   glColor3ub(238,28,37);

   glVertex2f(0.24f,0.6f);//a
   glVertex2f(0.14f, 0.42f);//b
   glVertex2f(0.34f, 0.42f);//c
   glEnd();

   glBegin(GL_POLYGON);/////////////////HEAD  Lower Body
   glColor3ub(230,230,230);
   glVertex2f(0.14f, 0.42f);//b
   glVertex2f(0.14f, 0.08f);//d
   glVertex2f(0.15f, 0.06f);//E
   glVertex2f(0.33f, 0.06f);//f
   glVertex2f(0.34f, 0.08f);//g
   glVertex2f(0.34f, 0.42f);//c
   glEnd();

   GLfloat pbg=0.24f; GLfloat qbg=0.25f; GLfloat rbg=-0.077f;////////////////////glass background

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(130,130,130);
   glVertex2f(pbg,qbg);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  pbg+(rbg*cos(i*tp1/triangle1)), qbg+(rbg*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   GLfloat pg=0.24f; GLfloat qg=0.25f; GLfloat rg=-0.07f;////////////////////glass

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(35,172,196);
   glVertex2f(pg,qg);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  pg+(rg*cos(i*tp1/triangle1)), qg+(rg*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   glBegin(GL_QUADS); /////////////////HEAD Lower Body shadow
   glColor3ub(187,188,192);
   glVertex2f(0.33f, 0.42f);//N'
   glVertex2f(0.33f, 0.06f);//f
   glVertex2f(0.34f, 0.08f);//g
   glVertex2f(0.34f, 0.42f);//c
   glEnd();

   glBegin(GL_QUADS); /////////////////HEAD Lower Body QUAD
   glColor3ub(187,188,192);
   glVertex2f(0.15f, 0.06f);//E
   glVertex2f(0.15f, 0.01f);//H
   glVertex2f(0.33f, 0.01f);//I
   glVertex2f(0.33f, 0.06f);//f
   glEnd();

   glBegin(GL_POLYGON); ///////////////// UNDER BODY QUAD
   glColor3ub(230,230,230);
   glVertex2f(0.15f, 0.01f);//H
   glVertex2f(0.14f, -0.01f);//K
   glVertex2f(0.14f, -0.74f);//L
   glVertex2f(0.34f, -0.74f);//M
   glVertex2f(0.34f, -0.01f);//J
   glVertex2f(0.33f, 0.01f);//I
   glEnd();

   glBegin(GL_QUADS); /////////////////UNDER BODY QUAD shadow
   glColor3ub(187,188,192);
   glVertex2f(0.33f, -0.74f);//N
   glVertex2f(0.34f, -0.74f);//M
   glVertex2f(0.34f, -0.01f);//J
   glVertex2f(0.33f, 0.01f);//I
   glEnd();

   ////////////////////////////////////////opening door

   if(door==false)
    {
   glBegin(GL_QUADS);
   glColor3ub(110,110,110);
   glVertex2f(0.16f, -0.1f);//A'
   glVertex2f(0.16f, -0.6f);//B'
   glVertex2f(0.32f, -0.6f);//C'
   glVertex2f(0.32f, -0.1f);//D'
   glEnd();

   ////////////////////////////////////// ************************************************ASTRONATUE

   glPushMatrix();
   glBegin(GL_QUADS);///////////////// ////////////////BODY
   glColor3ub(220,220,220);
   glVertex2f(0.21f, -0.3f);//A
   glVertex2f(0.21f, -0.45f);//C
   glVertex2f(0.27f, -0.45f);//D
   glVertex2f(0.27f, -0.3f);//B
   glEnd();

   glBegin(GL_QUADS);/////////////////////////////////// THROAT
   glColor3ub(240,240,240);
   glVertex2f(0.23f, -0.25f);//i
   glVertex2f(0.23f, -0.3f);//j
   glVertex2f(0.25f, -0.3f);//l
   glVertex2f(0.25f, -0.25f);//k
   glEnd();

   GLfloat ph=0.24f; GLfloat qh=-0.27f; GLfloat rh=-0.025f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(240,240,240);
   glVertex2f(ph,qh);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  ph+(rh*cos(i*tp1/triangle1)), qh+(rh*sin(i*tp1/triangle1))
                  );
   }
   glEnd();
   GLfloat ph1=0.24f; GLfloat qh1=-0.275f; GLfloat rh1=-0.021f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(245,68,12);
   glVertex2f(ph,qh);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  ph1+(rh1*cos(i*tp1/triangle1)), qh1+(rh1*sin(i*tp1/triangle1))
                  );
   }
   glEnd();


   glBegin(GL_QUADS);///////////////////////////////////Left Hand
   glColor3ub(245,68,12);
   glVertex2f(0.2f, -0.3f);//E
   glVertex2f(0.2f, -0.43f);//F
   glVertex2f(0.21f, -0.43f);//G
   glVertex2f(0.21f, -0.3f);//A
   glEnd();

   GLfloat plh=0.205f; GLfloat qlh=-0.43f; GLfloat rlh=-0.009f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(240,240,240);
   glVertex2f(plh,qlh);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  plh+(rlh*cos(i*tp1/triangle1)), qlh+(rlh*sin(i*tp1/triangle1))
                  );
   }
   glEnd();


   glBegin(GL_QUADS);///////////////////////////////////Right Hand
   glColor3ub(245,68,12);
   glVertex2f(0.27f, -0.3f);//B
   glVertex2f(0.27f, -0.43f);//J
   glVertex2f(0.28f, -0.43f);//K
   glVertex2f(0.28f, -0.3f);//L
   glEnd();

   GLfloat prh=0.275f; GLfloat qrh=-0.43f; GLfloat rrh=-0.009f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(240,240,240);
   glVertex2f(prh,qrh);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  prh+(rrh*cos(i*tp1/triangle1)), qrh+(rrh*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   glBegin(GL_QUADS);///////////////////////////////////Left leg
   glColor3ub(245,68,12);
   glVertex2f(0.215f, -0.45f);//M
   glVertex2f(0.215f, -0.6f);//N
   glVertex2f(0.23f, -0.6f);//O
   glVertex2f(0.241f, -0.45f);//P
   glEnd();

   glBegin(GL_QUADS);///////////////////////////////////Right leg
   glColor3ub(245,68,12);
   glVertex2f(0.241f, -0.45f);//P
   glVertex2f(0.25f, -0.6f);//Q
   glVertex2f(0.265f, -0.6f);//R
   glVertex2f(0.265f, -0.45f);//S
   glEnd();
   glPopMatrix();

   }




   glBegin(GL_POLYGON); ///////////////// LEFT WING
   glColor3ub(230,230,230);


   glVertex2f(0.1f, -0.25f);//P
   glVertex2f(0.05f, -0.25f);//Q
   glVertex2f(0.01f, -0.74f);//R
   glVertex2f(0.14f, -0.74f);//L
   glVertex2f(0.14f, -0.23f);//O


   glEnd();

   glBegin(GL_QUADS); /////////////////lEFT WING shadow
   glColor3ub(187,188,192);
   glVertex2f(0.1f, -0.25f);//P
   glVertex2f(0.06f, -0.74f);//S
   glVertex2f(0.14f, -0.74f);//L
   glVertex2f(0.14f, -0.23f);//O
   glEnd();


   ///////////////////////////////////////////RIGHT WING
   glBegin(GL_POLYGON);
   glColor3ub(230,230,230);


   glVertex2f(0.34f, -0.74f);//M
   glVertex2f(0.47f, -0.74f);//W
   glVertex2f(0.43f, -0.25f);//V
   glVertex2f(0.38f, -0.25f);//U
   glVertex2f(0.34f, -0.23f);//T

   glEnd();

   glBegin(GL_QUADS); /////////////////RIGHT WING shadow
   glColor3ub(187,188,192);
   glVertex2f(0.38f, -0.25f);//U
   glVertex2f(0.43f, -0.74f);//S'
   glVertex2f(0.47f, -0.74f);//W
   glVertex2f(0.43f, -0.25f);//V
   glEnd();

   glBegin(GL_QUADS); /////////////////LEFT fIRE EXIT
   glColor3ub(96,96,96);
   glVertex2f(0.05f, -0.74f);
   glVertex2f(0.04f, -0.79f);
   glVertex2f(0.11f, -0.79f);
   glVertex2f(0.1f, -0.74f);
   glEnd();

   glBegin(GL_QUADS); /////////////////CENTER fIRE EXIT
   glColor3ub(96,96,96);
   glVertex2f(0.215f, -0.74f);
   glVertex2f(0.205f, -0.79f);
   glVertex2f(0.275f, -0.79f);
   glVertex2f(0.265f, -0.74f);
   glEnd();

   glBegin(GL_QUADS); /////////////////RIGHT fIRE EXIT
   glColor3ub(96,96,96);
   glVertex2f(0.38f, -0.74f);
   glVertex2f(0.37f, -0.79f);
   glVertex2f(0.44f, -0.79f);
   glVertex2f(0.43f, -0.74f);
   glEnd();


   if(road==false)
    {

   glBegin(GL_QUADS);
   glColor3ub(80,80,200);
   glVertex2f(0.16f, -0.6f);//B'
   glVertex2f(0.05f, -0.9f);//E'
   glVertex2f(0.21f, -0.9f);//F'
   glVertex2f(0.32f, -0.6f);//C'

   glEnd();
   }

   if(mover==false)
    {
        glTranslatef(position3,0.0f,0);
        glScaled(1.5,1.5,0.0);

      glPushMatrix();
   glBegin(GL_QUADS);///////////////// ////////////////BODY
   glColor3ub(220,220,220);
   glVertex2f(0.21f, -0.3f);//A
   glVertex2f(0.21f, -0.45f);//C
   glVertex2f(0.27f, -0.45f);//D
   glVertex2f(0.27f, -0.3f);//B
   glEnd();

   glBegin(GL_QUADS);/////////////////////////////////// THROAT
   glColor3ub(240,240,240);
   glVertex2f(0.23f, -0.25f);//i
   glVertex2f(0.23f, -0.3f);//j
   glVertex2f(0.25f, -0.3f);//l
   glVertex2f(0.25f, -0.25f);//k
   glEnd();

   GLfloat ph=0.24f; GLfloat qh=-0.27f; GLfloat rh=-0.025f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(240,240,240);
   glVertex2f(ph,qh);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  ph+(rh*cos(i*tp1/triangle1)), qh+(rh*sin(i*tp1/triangle1))
                  );
   }
   glEnd();
   GLfloat ph1=0.24f; GLfloat qh1=-0.275f; GLfloat rh1=-0.021f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(245,68,12);
   glVertex2f(ph,qh);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  ph1+(rh1*cos(i*tp1/triangle1)), qh1+(rh1*sin(i*tp1/triangle1))
                  );
   }
   glEnd();


   glBegin(GL_QUADS);///////////////////////////////////Left Hand
   glColor3ub(245,68,12);
   glVertex2f(0.2f, -0.3f);//E
   glVertex2f(0.2f, -0.43f);//F
   glVertex2f(0.21f, -0.43f);//G
   glVertex2f(0.21f, -0.3f);//A
   glEnd();

   GLfloat plh=0.205f; GLfloat qlh=-0.43f; GLfloat rlh=-0.009f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(240,240,240);
   glVertex2f(plh,qlh);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  plh+(rlh*cos(i*tp1/triangle1)), qlh+(rlh*sin(i*tp1/triangle1))
                  );
   }
   glEnd();


   glBegin(GL_QUADS);///////////////////////////////////Right Hand
   glColor3ub(245,68,12);
   glVertex2f(0.27f, -0.3f);//B
   glVertex2f(0.27f, -0.43f);//J
   glVertex2f(0.28f, -0.43f);//K
   glVertex2f(0.28f, -0.3f);//L
   glEnd();

   GLfloat prh=0.275f; GLfloat qrh=-0.43f; GLfloat rrh=-0.009f;

   glBegin(GL_TRIANGLE_FAN);
   glColor3ub(240,240,240);
   glVertex2f(prh,qrh);
   for(i=0; i<=triangle1;i++)
   {
       glVertex2f(
                  prh+(rrh*cos(i*tp1/triangle1)), qrh+(rrh*sin(i*tp1/triangle1))
                  );
   }
   glEnd();

   glBegin(GL_QUADS);///////////////////////////////////Left leg
   glColor3ub(245,68,12);
   glVertex2f(0.215f, -0.45f);//M
   glVertex2f(0.215f, -0.6f);//N
   glVertex2f(0.23f, -0.6f);//O
   glVertex2f(0.241f, -0.45f);//P
   glEnd();

   glBegin(GL_QUADS);///////////////////////////////////Right leg
   glColor3ub(245,68,12);
   glVertex2f(0.241f, -0.45f);//P
   glVertex2f(0.25f, -0.6f);//Q
   glVertex2f(0.265f, -0.6f);//R
   glVertex2f(0.265f, -0.45f);//S
   glEnd();

   door=true;
   road=true;

   glPopMatrix();
   }



   /////////////////////////////////////////////////////////////////////////////////////////fire

if(fire)
{
   glBegin(GL_TRIANGLES);//////////////////////////////////////////left fire
   glColor3ub(240,192,11);
   glVertex2f(0.04f, -0.79f);
   glVertex2f(0.075f, -0.95f);
   glVertex2f(0.11f, -0.79f);
   glEnd();

   glBegin(GL_TRIANGLES);//////////////////////////////////////////center fire
   glColor3ub(240,192,11);
   glVertex2f(0.205f, -0.79f);
   glVertex2f(0.24f, -0.95f);
   glVertex2f(0.275f, -0.79f);
   glEnd();

   glBegin(GL_TRIANGLES);//////////////////////////////////////////right fire
   glColor3ub(240,192,11);
   glVertex2f(0.37f, -0.79f);
   glVertex2f(0.405f, -0.95f);
   glVertex2f(0.44f, -0.79f);
   glEnd();
}
glPopMatrix();

}



      if(fireoff==false)
   {
       fire=false;
   }



glFlush();
}

void handleMouse(int button, int state, int x, int y)
{
if (button == GLUT_LEFT_BUTTON)
{
    speed1 += 0.1f;
}
if (button == GLUT_RIGHT_BUTTON)
{speed1 -= 0.1f;   }
glutPostRedisplay();
}


void handleKeypress(unsigned char key, int x, int y)
{
switch (key) {
case 'f':
    speed = 0.03f;
    smoke = false;
    break;
case 's':
    space = false;
    break;
case 'l':
    land=false;
    break;
case '0':
    fireoff=false;
    break;
case 'd':
    door=false;
    break;
case 'r':
    road=false;
    break;
case 'm':
    mover=false;
    speed3=0.02;
    break;

case '2':
    house1=false;
    break;
case '3':
    house2=false;
    break;
case 't':
    tree=false;
    break;
case 'n':
    night=false;
    break;
case 'w':
    water=false;
    break;
glutPostRedisplay();
}
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(1920,1080);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Translation Animation");
   glutDisplayFunc(display);
   glutTimerFunc(100, update, 0);
   glutTimerFunc(100, update1, 0);
   glutTimerFunc(100, update2, 0);
   glutTimerFunc(100, update3, 0);
   glutTimerFunc(100, update4, 0);
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutMainLoop();
   return 0;
}
