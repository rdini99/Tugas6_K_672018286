#include <GL/glut.h>
#include<windows.h>

void init(void);
void furniture(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void init()
{
    glClearColor(25.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
}

void furniture(void)
{
    //meja
    glBegin(GL_QUADS);
        glColor3ub(184, 134, 11);
        glVertex3f(-10.0, -15.0, 5.0);
        glVertex3f(-30.0, -15.0, 5.0);
        glVertex3f(-30.0, -15.0, -20.0);
        glVertex3f(-10.0, -15.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(184, 134, 11);
        glVertex3f(-10.0, -12.0, 5.0);
        glVertex3f(-30.0, -12.0, 5.0);
        glVertex3f(-30.0, -15.0, 5.0);
        glVertex3f(-10.0, -15.0, 5.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(184, 134, 11);
        glVertex3f(-10.0, -12.0, -20.0);
        glVertex3f(-30.0, -12.0, -20.0);
        glVertex3f(-30.0, -15.0, -20.0);
        glVertex3f(-10.0, -15.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(184, 134, 11);
        glVertex3f(-10.0, -12.0, 5.0);
        glVertex3f(-30.0, -12.0, 5.0);
        glVertex3f(-30.0, -12.0, -20.0);
        glVertex3f(-10.0, -12.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(184, 134, 11);
        glVertex3f(-10.0, -12.0, 5.0);
        glVertex3f(-10.0, -15.0, 5.0);
        glVertex3f(-10.0, -15.0, -20.0);
        glVertex3f(-10.0, -12.0, -20.0);
    glEnd();

    //kaki meja 1
    glBegin(GL_LINES);
    glLineWidth(5);
    glColor3ub(184, 134, 11);
    glVertex3f(-13.0, -15.0, -16.0);
    glVertex3f(-13.0, -20.0, -16.0);
    glEnd();

    //kaki meja 2
    glBegin(GL_LINES);
    glLineWidth(5);
    glColor3ub(184, 134, 11);
    glVertex3f(-27.0, -15.0, -16.0);
    glVertex3f(-27.0, -20.0, -16.0);
    glEnd();

    //kaki meja 3
    glBegin(GL_LINES);
    glLineWidth(5);
    glColor3ub(184, 134, 11);
    glVertex3f(-13.0, -15.0, 1.0);
    glVertex3f(-13.0, -20.0, 1.0);
    glEnd();

    //kaki meja 4
    glBegin(GL_LINES);
    glLineWidth(5);
    glColor3ub(184, 134, 11);
    glVertex3f(-27.0, -15.0, 1.0);
    glVertex3f(-27.0, -20.0, 1.0);
    glEnd();

    //almari
    glBegin(GL_QUADS);
    glColor3ub(240, 128, 128);
        glVertex3f(20.0, -20.0, -22.0);
        glVertex3f(5.0, -20.0, -22.0);
        glVertex3f(5.0, 10.0, -22.0);
        glVertex3f(20.0, 10.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 128, 128);
        glVertex3f(20.0, -20.0, -27.0);
        glVertex3f(5.0, -20.0, -27.0);
        glVertex3f(5.0, 10.0, -27.0);
        glVertex3f(20.0, 10.0, -27.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 128, 128);
        glVertex3f(20.0, -20.0, -27.0);
        glVertex3f(20.0, 10.0, -27.0);
        glVertex3f(20.0, 10.0, -22.0);
        glVertex3f(20.0, -20.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 128, 128);
        glVertex3f(5.0, -20.0, -27.0);
        glVertex3f(5.0, 10.0, -27.0);
        glVertex3f(5.0, 10.0, -22.0);
        glVertex3f(5.0, -20.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(240, 128, 128);
        glVertex3f(5.0, 10.0, -27.0);
        glVertex3f(20.0, 10.0, -27.0);
        glVertex3f(20.0, 10.0, -22.0);
        glVertex3f(5.0, 10.0, -22.0);
    glEnd();

    //garis almari
    glBegin(GL_LINES);
    glLineWidth(5);
    glColor3ub(205, 92, 92);
    glVertex3f(12.5, 10.0, -22.0);
    glVertex3f(12.5, -20.0, -22.0);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(3);
    glColor3ub(255, 250, 250);
    glVertex3f(11.0, -2.0, -22.0);
    glVertex3f(11.0, -6.0, -22.0);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(3);
    glColor3ub(255, 250, 250);
    glVertex3f(14.0, -2.0, -22.0);
    glVertex3f(14.0, -6.0, -22.0);
    glEnd();

    //kursi
    glBegin(GL_QUADS);
    glColor3ub(255, 248, 220);
        glVertex3f(-48.0, -10.0, -22.0);
        glVertex3f(-40.0, -10.0, -22.0);
        glVertex3f(-40.0, -2.0, -22.0);
        glVertex3f(-48.0, -2.0, -22.0);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(5);
    glColor3ub(255, 248, 220);
        glVertex3f(-46.0, -10.0, -22.0);
        glVertex3f(-46.0, -13.0, -22.0);
    glEnd();

    glBegin(GL_LINES);
    glLineWidth(5);
    glColor3ub(255, 248, 220);
        glVertex3f(-42.0, -10.0, -22.0);
        glVertex3f(-42.0, -13.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(255, 248, 220);
        glVertex3f(-48.0, -13.0, -22.0);
        glVertex3f(-40.0, -13.0, -22.0);
        glVertex3f(-40.0, -13.0, -10.0);
        glVertex3f(-48.0, -13.0, -10.0);
    glEnd();

    //kaki kursi
    glBegin(GL_LINES);
        glColor3ub(255, 248, 220);
        glVertex3f(-46.0, -13.0, -22.0);
        glVertex3f(-46.0, -20.0, -22.0);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(255, 248, 220);
        glVertex3f(-42.0, -13.0, -22.0);
        glVertex3f(-42.0, -20.0, -22.0);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(255, 248, 220);
        glVertex3f(-46.0, -13.0, -15.0);
        glVertex3f(-46.0, -20.0, -15.0);
    glEnd();

     glBegin(GL_LINES);
        glColor3ub(255, 248, 220);
        glVertex3f(-42.0, -13.0, -15.0);
        glVertex3f(-42.0, -20.0, -15.0);
    glEnd();

    //TV
    glBegin(GL_LINE_LOOP);
    glColor3ub(47, 79, 79);
        glVertex3f(-15.0, 5.0, -22.0);
        glVertex3f(-3.0, 5.0, -22.0);
        glVertex3f(-3.0, -5.0, -22.0);
        glVertex3f(-15.0, -5.0, -22.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,0,0);
        glVertex3f(-7.0, -5.0, -22.0);
        glVertex3f(-7.5, -5.0, -22.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,0,0);
        glVertex3f(-6.0, -5.0, -22.0);
        glVertex3f(-6.5, -5.0, -22.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(255,0,0);
        glVertex3f(-5.0, -5.0, -22.0);
        glVertex3f(-5.5, -5.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
        glVertex3f(-14.5, 4.25, -22.0);
        glVertex3f(-3.5, 4.25, -22.0);
        glVertex3f(-3.5, -4.25, -22.0);
        glVertex3f(-14.5, -4.25, -22.0);
    glEnd();

    //rak
    glBegin(GL_QUADS);
    glColor3ub(218,112,214);
        glVertex3f(-59.0, -5.0, -20.0);
        glVertex3f(-59.0, 10.0, -20.0);
        glVertex3f(-59.0, 10.0, 0.0);
        glVertex3f(-59.0, -5.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(216,191,216);
        glVertex3f(-56.0, -5.0, -20.0);
        glVertex3f(-56.0, 10.0, -20.0);
        glVertex3f(-59.0, 10.0, -20.0);
        glVertex3f(-59.0, -5.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(216,191,216);
        glVertex3f(-56.0, -5.0, 0.0);
        glVertex3f(-59.0, -5.0, 0.0);
        glVertex3f(-59.0, -5.0, -20.0);
        glVertex3f(-56.0, -5.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(216,191,216);
        glVertex3f(-56.0, 0.0, 0.0);
        glVertex3f(-58.0, 0.0, 0.0);
        glVertex3f(-58.0, 0.0, -20.0);
        glVertex3f(-56.0, 0.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(216,191,216);
        glVertex3f(-56.0, 5.0, 0.0);
        glVertex3f(-58.0, 5.0, 0.0);
        glVertex3f(-58.0, 5.0, -20.0);
        glVertex3f(-56.0, 5.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(216,191,216);
        glVertex3f(-56.0, 10.0, 0.0);
        glVertex3f(-59.0, 10.0, 0.0);
        glVertex3f(-59.0, 10.0, -20.0);
        glVertex3f(-56.0, 10.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(216,191,216);
        glVertex3f(-56.0, -5.0, 0.0);
        glVertex3f(-56.0, 10.0, 0.0);
        glVertex3f(-59.0, 10.0, 0.0);
        glVertex3f(-59.0, -5.0, 0.0);
    glEnd();
}

void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else glClear(GL_COLOR_BUFFER_BIT);

    //genteng
   glBegin(GL_QUADS);
        glColor3ub(128,0,0);
        glVertex3f(-16.0, 0.0, 16.0);
        glColor3ub(0,0,0);
        glVertex3f(20.0, 0.0, 16.0);
        glColor3ub(0,0,0);
        glVertex3f(20.0, 10.0, 10.0);
        glColor3ub(128,0,0);
        glVertex3f(-16.0, 10.0, 10.0);
    glEnd();

  //  tembok depan
   glBegin(GL_QUADS);
   glColor3ub(255,255,0);
       glVertex3f(-60.0, -20.0, 10.0);
     glVertex3f(28.0, -20.0, 10.0);
       glVertex3f(28.0, 18.0, 10.0);
      glVertex3f(-60.0, 18.0, 10.0);
   glEnd();

   //kaca jendela 1
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex3f(-8.5, -10.0, 15.0);
        glVertex3f(-2.5, -10.0, 15.0);
        glVertex3f(-2.5, 4.5, 11.5);
        glVertex3f(-8.5, 4.5, 11.5);
    glEnd();

    //garis jendela 1
    glBegin(GL_LINE_LOOP);
        glColor3ub(139,69,19);
        glVertex3f(-10.0, -12.2, 10.5);
        glVertex3f(-1.0, -12.2, 10.5);
        glVertex3f(-1.0, 6.2, 10.5);
        glVertex3f(-10.0, 6.2, 10.5);
    glEnd();

    //bingkai jendela 1
    glBegin(GL_POLYGON);
        glColor3ub(139,69,19);
        glVertex3f(-10.4, -12.2, 15.0);
        glVertex3f(-0.8, -12.2, 15.0);
        glVertex3f(-0.8, 6.2, 11.0);
        glVertex3f(-10.4, 6.2, 11.0);
    glEnd();

    //kaca jendela 2
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex3f(6.5, -10.0, 15.0);
        glVertex3f(12.5, -10.0, 15.0);
        glVertex3f(12.5, 4.5, 11.0);
        glVertex3f(6.5, 4.5, 11.0);
    glEnd();

    //garis jendela 2
    glBegin(GL_LINE_LOOP);
        glColor3ub(139,69,19);
        glVertex3f(8.0, -12.2, 10.5);
        glVertex3f(13.5, -12.2, 10.5);
        glVertex3f(13.5, 6.2, 10.5);
        glVertex3f(8.0, 6.2, 10.5);
    glEnd();

    //bingkai jendela 2
    glBegin(GL_POLYGON);
        glColor3ub(139,69,19);
        glVertex3f(4.8, -12.2, 15.0);
        glVertex3f(14.2, -12.2, 15.0);
        glVertex3f(14.2, 6.2, 10.5);
        glVertex3f(4.8, 6.2, 10.5);
    glEnd();

    //atap jendela 1
    glBegin(GL_POLYGON);
        glColor3ub(139,69,19);
        glVertex3f(1.0, -2.0, 10.5);
        glVertex3f(3.0, -2.0, 10.5);
        glVertex3f(3.0, 2.0, 14.0);
        glVertex3f(1.0, 2.0, 14.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(139,69,19);
        glVertex3f(1.0, -2.0, 10.5);
        glVertex3f(3.0, -2.0, 10.5);
        glVertex3f(3.0, 6.2, 10.5);
        glVertex3f(1.0, 6.2, 10.5);
    glEnd();

    //atap jendela 2
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
        glVertex3f(-12.0, -2.0, 10.5);
        glVertex3f(-14.0, -2.0, 10.5);
        glVertex3f(-14.0, 2.0, 14.0);
        glVertex3f(-12.0, 2.0, 14.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
        glVertex3f(-12.0, -2.0, 10.5);
        glVertex3f(-14.0, -2.0, 10.5);
        glVertex3f(-14.0, 6.2, 10.5);
        glVertex3f(-12.0, 6.2, 10.5);
    glEnd();

    //atap jendela 3
    glBegin(GL_POLYGON);
        glColor3ub(139,69,19);
        glVertex3f(18.0, -2.0, 10.5);
        glVertex3f(16.0, -2.0, 10.5);
        glVertex3f(16.0, 2.0, 14.0);
        glVertex3f(18.0, 2.0, 14.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(139,69,19);
        glVertex3f(18.0, -2.0, 10.5);
        glVertex3f(16.0, -2.0, 10.5);
        glVertex3f(16.0, 6.2, 10.5);
        glVertex3f(18.0, 6.2, 10.5);
    glEnd();

   // pintu
    glBegin(GL_POLYGON);
       glColor3ub(139,69,19);
       glVertex3f(-35.0, -20.0, 10.5);
       glVertex3f(-25.0, -20.0, 10.5);
       glVertex3f(-25.0, 6.2, 10.5);
       glVertex3f(-35.0, 6.2, 10.5);
   glEnd();

   //gagang pintu
   glBegin(GL_POLYGON);
   glColor3ub(0,0,0);
       glVertex3f(-35.0, -6.0, 10.8);
       glVertex3f(-32.0, -6.0, 10.8);
       glVertex3f(-32.0, -5.0, 10.8);
       glVertex3f(-35.0, -5.0, 10.8);
   glEnd();

    //jendela samping pintu
    glBegin(GL_POLYGON);
        glColor3ub(139,69,19);
        glVertex3f(-40.0, -16.0, 10.5);
        glVertex3f(-40.0, 6.2, 10.5);
        glVertex3f(-56.0, 6.2, 10.5);
        glVertex3f(-56.0, -16.0, 10.5);
    glEnd();

    //kaca jendela
    glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex3f(-54.0, -14.0, 10.6);
        glVertex3f(-42.0, -14.0, 10.6);
        glVertex3f(-42.0, 4.0, 10.6);
        glVertex3f(-54.0, 4.0, 10.6);
    glEnd();

    //batas jendela
    glBegin(GL_LINES);
        glColor3ub(139,69,19);
        glVertex3f(-48.0, -16.0, 10.7);
        glVertex3f(-48.0, 6.2, 10.7);
    glEnd();

    //tembok belakang
    glBegin(GL_QUADS);
        glColor3ub(169,169,169);
        glVertex3f(-60.0, -20.0, -30.0);
        glVertex3f(28.0, -20.0, -30.0);
        glColor3ub(192,192,192);
        glVertex3f(28.0, 18.0, -30.0);
        glVertex3f(-60.0, 18.0, -30.0);
    glEnd();

    //tembok samping kanan
    glBegin(GL_POLYGON);
        glColor3ub(128,128,128);
        glVertex3f(28.0, -20.0, -30.0);
        glVertex3f(28.0, 18.0, -30.0);
        glVertex3f(28.0, 18.0, 10.0);
        glVertex3f(28.0, -20.0, 10.0);
    glEnd();

    //tembok samping kiri 1
    glBegin(GL_POLYGON);
        glColor3ub(128,128,128);
        glVertex3f(-60.0, -20.0, -30.0);
        glVertex3f(-60.0, 18.0, -30.0);
        glVertex3f(-60.0, 18.0, 10.0);
        glVertex3f(-60.0, -20.0, 10.0);
    glEnd();

    //tembok samping kiri 2
    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-60.0, -20.0, 10.0);
        glVertex3f(-60.0, 18.0, 10.0);
        glVertex3f(-60.0, 18.0, 40.0);
        glVertex3f(-60.0, -20.0, 40.0);
    glEnd();

    //atap
    glBegin(GL_QUADS);
        glColor3ub(255,248,220);
        glVertex3f(28.0, 18.0 , 10.0);
        glVertex3f(-60.0, 18.0, 10.0);
        glVertex3f(-60.0, 18.0, -30.0);
        glVertex3f(28.0, 18.0, -30.0);
    glEnd();

    //alas rumah bawah
    glBegin(GL_QUADS);
        glColor3ub(105,105,105);
        glVertex3f(28.0, -20.0, 10.0);
        glVertex3f(-60.0, -20.0, 10.0);
        glColor3ub(169,169,169);
        glVertex3f(-60.0, -20.0, -30.0);
        glVertex3f(28.0, -20.0, -30.0);
    glEnd();

    //teras atas
    glBegin(GL_QUADS);
        glColor3ub(128,0,0);
        glVertex3f(-24.0, -20.0, 9.5);
        glVertex3f(-60.0, -20.0, 9.5);
        glVertex3f(-60.0, -20.0, 40.0);
        glVertex3f(-24.0, -20.0, 40.0);
    glEnd();

    //tumpukan teras
    glBegin(GL_QUADS);
        glColor3ub(128,0,0);
        glVertex3f(-24.0, -21.0, 9.5);
        glVertex3f(-60.0, -21.0, 9.5);
        glVertex3f(-60.0, -21.0, 40.0);
        glVertex3f(-24.0, -21.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(128,0,0);
        glVertex3f(-24.0, -22.0, 9.5);
        glVertex3f(-60.0, -22.0, 9.5);
        glVertex3f(-60.0, -22.0, 40.0);
        glVertex3f(-24.0, -22.0, 40.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(128,0,0);
        glVertex3f(-24.0, -23.0, 9.5);
        glVertex3f(-60.0, -23.0, 9.5);
        glVertex3f(-60.0, -23.0, 40.0);
        glVertex3f(-24.0, -23.0, 40.0);
    glEnd();

    //teras bawah
    glBegin(GL_QUADS);
       glColor3ub(220,220,220);
       glVertex3f(25.0, -24.0, 9.5);
       glVertex3f(-60.0, -24.0, 9.5);
       glColor3ub(128,128,128);
       glVertex3f(-60.0, -24.0, 40.0);
       glVertex3f(25.0, -24.0, 40.0);
    glEnd();

    //lantai teras
    glBegin(GL_LINES);
       glLineWidth(2);
       glColor3ub(255,250,250);
       glVertex3f(-30.0, -20.0, 9.5);
       glVertex3f(-30.0, -20.0, 40.0);
   glEnd();

    glBegin(GL_LINES);
       glLineWidth(2);
       glColor3ub(255,250,250);
       glVertex3f(-38.0, -20.0, 9.5);
        glVertex3f(-38.0, -20.0, 40.0);
    glEnd();

    glBegin(GL_LINES);
       glLineWidth(2);
       glColor3ub(255,250,250);
       glVertex3f(-46.0, -20.0, 9.5);
       glVertex3f(-46.0, -20.0, 40.0);
    glEnd();

    glBegin(GL_LINES);
        glLineWidth(2);
        glColor3ub(255,250,250);
        glVertex3f(-54.0, -20.0, 9.5);
        glVertex3f(-54.0, -20.0, 40.0);
    glEnd();

    glBegin(GL_LINES);
        glLineWidth(2);
        glColor3ub(255,250,250);
        glVertex3f(-24.0, -20.0, 20.0);
        glVertex3f(-60.0, -20.0, 20.0);
    glEnd();

    glBegin(GL_LINES);
        glLineWidth(2);
        glColor3ub(255,250,250);
        glVertex3f(-24.0, -20.0, 30.0);
        glVertex3f(-60.0, -20.0, 30.0);
    glEnd();

    glBegin(GL_LINES);
        glLineWidth(2);
        glColor3ub(255,250,250);
        glVertex3f(-24.0, -20.0, 40.0);
        glVertex3f(-60.0, -20.0, 40.0);
    glEnd();

    //tiang
    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-22.0, 15.0, 41.0);
        glVertex3f(-27.0, 15.0, 41.0);
        glVertex3f(-27.0, -24.0, 41.0);
        glVertex3f(-22.0, -24.0, 41.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-22.0, 15.0, 35.0);
        glVertex3f(-27.0, 15.0, 35.0);
        glVertex3f(-27.0, -24.0, 35.0);
        glVertex3f(-22.0, -24.0, 35.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255,255,0);
        glVertex3f(-22.0, -24.0, 35.0);
        glVertex3f(-22.0, 15.0, 35.0);
        glVertex3f(-22.0, 15.0, 41.0);
        glVertex3f(-22.0, -24.0, 41.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-27.0, -24.0, 35.0);
        glVertex3f(-27.0, 15.0, 35.0);
        glVertex3f(-27.0, 15.0, 41.0);
        glVertex3f(-27.0, -24.0, 41.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-22.0, -24.0, 35.0);
        glVertex3f(-27.0, -24.0, 35.0);
        glVertex3f(-27.0, -24.0, 41.0);
        glVertex3f(-22.0, -24.0, 41.0);
    glEnd();

    //tiang atas
    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-18.0, 10.0 , 35.0);
        glVertex3f(-60.0, 10.0, 35.0);
        glVertex3f(-60.0, 10.0, 41.0);
        glVertex3f(-18.0, 10.0, 41.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-18.0, 5.0 , 35.0);
        glVertex3f(-60.0, 5.0, 35.0);
        glVertex3f(-60.0, 5.0, 41.0);
        glVertex3f(-18.0, 5.0, 41.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-18.0, 5.0 , 35.0);
        glVertex3f(-60.0, 5.0, 35.0);
        glVertex3f(-60.0, 10.0, 35.0);
        glVertex3f(-18.0, 10.0, 35.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-18.0, 5.0 , 41.0);
        glVertex3f(-60.0, 5.0, 41.0);
        glVertex3f(-60.0, 10.0, 41.0);
        glVertex3f(-18.0, 10.0, 41.0);
    glEnd();

    //tiang atas samping 1
    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-27.0, 10.0, 43.0);
        glVertex3f(-22.0, 10.0, 43.0);
        glVertex3f(-22.0, 10.0, 10.0);
        glVertex3f(-27.0, 10.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-27.0, 5.0, 43.0);
        glVertex3f(-22.0, 5.0, 43.0);
        glVertex3f(-22.0, 5.0, 10.0);
        glVertex3f(-27.0, 5.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-27.0, 10.0, 43.0);
        glVertex3f(-27.0, 5.0, 43.0);
        glVertex3f(-27.0, 5.0, 10.0);
        glVertex3f(-27.0, 10.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-22.0, 10.0, 43.0);
        glVertex3f(-22.0, 5.0, 43.0);
        glVertex3f(-22.0, 5.0, 10.0);
        glVertex3f(-22.0, 10.0, 10.0);
    glEnd();

    //tiang kanan atas samping 2
    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-27.0, 18.0, 43.0);
        glVertex3f(-22.0, 18.0, 43.0);
        glVertex3f(-22.0, 18.0, 10.0);
        glVertex3f(-27.0, 18.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-27.0, 13.0, 43.0);
        glVertex3f(-22.0, 13.0, 43.0);
        glVertex3f(-22.0, 13.0, 10.0);
        glVertex3f(-27.0, 13.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-27.0, 18.0, 43.0);
        glVertex3f(-27.0, 13.0, 43.0);
        glVertex3f(-27.0, 13.0, 10.0);
        glVertex3f(-27.0, 18.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-22.0, 18.0, 43.0);
        glVertex3f(-22.0, 13.0, 43.0);
        glVertex3f(-22.0, 13.0, 10.0);
        glVertex3f(-22.0, 18.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-22.0, 13.0, 43.0);
        glVertex3f(-22.0, 18.0, 43.0);
        glVertex3f(-27.0, 18.0, 43.0);
        glVertex3f(-27.0, 13.0, 43.0);
    glEnd();

    //tiang kiri atas samping 2
    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-60.0, 18.0, 43.0);
        glVertex3f(-55.0, 18.0, 43.0);
        glVertex3f(-55.0, 18.0, 10.0);
        glVertex3f(-60.0, 18.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-60.0, 13.0, 43.0);
        glVertex3f(-55.0, 13.0, 43.0);
        glVertex3f(-55.0, 13.0, 10.0);
        glVertex3f(-60.0, 13.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-60.0, 18.0, 43.0);
        glVertex3f(-60.0, 13.0, 43.0);
        glVertex3f(-60.0, 13.0, 10.0);
        glVertex3f(-60.0, 18.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-55.0, 18.0, 43.0);
        glVertex3f(-55.0, 13.0, 43.0);
        glVertex3f(-55.0, 13.0, 10.0);
        glVertex3f(-55.0, 18.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-55.0, 13.0, 43.0);
        glVertex3f(-55.0, 18.0, 43.0);
        glVertex3f(-60.0, 18.0, 43.0);
        glVertex3f(-60.0, 13.0, 43.0);
    glEnd();

    //plafon 1
    glBegin(GL_POLYGON);
        glColor3ub(245,255,250);
        glVertex3f(-27.0, 15.0, 40.0);
        glVertex3f(-60.0, 15.0, 40.0);
        glVertex3f(-60.0, 15.0, 10.0);
        glVertex3f(-27.0, 15.0, 10.0);
    glEnd();

    //plafon 2
    glBegin(GL_POLYGON);
        glColor3ub(255,255,0);
        glVertex3f(-27.0, 15.0, 40.0);
        glVertex3f(-27.0, 23.0, 40.0);
        glVertex3f(-54.0, 23.0, 40.0);
        glVertex3f(-54.0, 15.0, 40.0);
    glEnd();

    //genteng depan teras miring kanan 1
   glBegin(GL_QUADS);
       glColor3ub(128,0,0);
       glVertex3f(-40.0, 35.2, 10.0);
       glColor3ub(0,0,0);
       glVertex3f(-17.0, 14.0, 10.0);
       glColor3ub(128,0,0);
       glVertex3f(-17.0, 14.0, 43.0);
       glColor3ub(0,0,0);
       glVertex3f(-40.0, 35.2, 43.0);
    glEnd();

    //genteng depan teras miring kanan 2
   glBegin(GL_QUADS);
       glColor3ub(128,0,0);
       glVertex3f(-40.0, 35.2, -30.0);
       glColor3ub(0,0,0);
       glVertex3f(-17.0, 14.0, -30.0);
       glColor3ub(128,0,0);
       glVertex3f(-17.0, 14.0, 11.0);
       glColor3ub(0,0,0);
       glVertex3f(-40.0, 35.2, 11.0);
   glEnd();

    //genteng depan teras miring kiri 1
  glBegin(GL_QUADS);
    glColor3ub(128,0,0);
    glVertex3f(-40.0, 35.2, 10.0);
    glColor3ub(0,0,0);
    glVertex3f(-65.0, 14.0, 10.0);
    glColor3ub(128,0,0);
    glVertex3f(-65.0, 14.0, 43.0);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 35.2, 43.0);
  glEnd();

   //genteng belakang 2
    glBegin(GL_QUADS);
    glColor3ub(169,169,169);
        glVertex3f(-55.0, 25.0, -31.0);
        glVertex3f(-40.0, 25.0, -31.0);
        glColor3ub(192,192,192);
        glVertex3f(-40.0, 14.0, -31.0);
        glVertex3f(-55.0, 14.0, -31.0);
    glEnd();

    //genteng depan teras miring kiri 2
  glBegin(GL_QUADS);
    glColor3ub(128,0,0);
    glVertex3f(-40.0, 35.2, -30.0);
    glColor3ub(0,0,0);
    glVertex3f(-65.0, 14.0, -30.0);
    glColor3ub(128,0,0);
    glVertex3f(-65.0, 14.0, 10.0);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 35.2, 10.0);
  glEnd();

    //samping kanan
    glBegin(GL_QUADS);
        glColor3ub(129,129,129);
        glVertex3f(28.0, 35.2, -30.0);
        glVertex3f(28.0, 35.2, 10.0);
        glVertex3f(28.0, 17.0, 10.0);
        glVertex3f(28.0, 17.0, -30.0);
    glEnd();

    //genteng atas
    glBegin(GL_QUADS);
        glColor3ub(128,0,0);
        glVertex3f(-40.0, 35.2, -20.0);
        glColor3ub(0,0,0);
        glVertex3f(25.0, 35.2, -20.0);
        glColor3ub(128,0,0);
        glVertex3f(25.0, 35.2, 0.0);
        glColor3ub(0,0,0);
        glVertex3f(-40.0, 35.2, 0.0);
    glEnd();

    //genteng belakang 1
   glBegin(GL_QUADS);
     glColor3ub(128,0,0);
     glVertex3f(-40.0, 35.2, -20.0);
     glColor3ub(0,0,0);
     glVertex3f(28.0, 35.2, -20.0);
     glColor3ub(128,0,0);
     glVertex3f(28.0, 16.0, -32.0);
     glColor3ub(0,0,0);
     glVertex3f(-40.0, 16.0, -32.0);
   glEnd();

    //genteng depan
glBegin(GL_QUADS);
    glColor3ub(128,0,0);
    glVertex3f(-40.0, 35.2, 0.0);
    glColor3ub(0,0,0);
    glVertex3f(28.0, 35.2, 0.0);
    glColor3ub(128,0,0);
    glVertex3f(28.0, 17.0, 11.0);
    glColor3ub(0,0,0);
    glVertex3f(-40.0, 17.0, 11.0);
glEnd();

    furniture();

    glutSwapBuffers();
}

void idle(){
    if(!mouseDown){
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }else
    mouseDown = false;
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        } else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

int main (int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000,800);
    glutInitWindowPosition(250,80);
    glutCreateWindow("Ramadini Kesumawati-672018286");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);

    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);


    glutIdleFunc(idle);
    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}
