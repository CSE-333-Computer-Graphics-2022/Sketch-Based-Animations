#include "fun.h"
#include <cstdlib>
float clspeed = 0.0f;
float meghposition = 0.0;
const int PAR_SIZE = 500;
float dropCPos[PAR_SIZE] = {0};
float dropSpeed[PAR_SIZE] = {0};
void moontimer(int);
void meghtimer(int);
void Naukatimer(int);
void appletimer(int);
int state;
bool showRain = false;

float axisshift = 1.0;
void init(void){
    glClearColor(0,0,0,0);
    gluOrtho2D(-960.0, 960.0, -540.0, 540.0);    
}

void initDropSpeed() {
    for (int loop=0; loop<PAR_SIZE; loop++) {
        dropSpeed[loop] = (float)(rand() % (40 -10 +1))/(float)10.0f;
    }
}

void Par(int yParPosition) {
    glColor3f(0.5, 0.5, 1.0);
    for (int loop=0; loop<PAR_SIZE; loop++) {
        DrawCircle( (2000/PAR_SIZE)*(loop-(PAR_SIZE/2)+1), yParPosition-dropCPos[loop], 3, 1000);
    }
}

void dropTimer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000/60, dropTimer, 0);
    for (int loop=0; loop<=PAR_SIZE; loop++) {
        if (dropCPos[loop]>1040) {
            dropCPos[loop] = 0;
        } else {
            dropCPos[loop] += dropSpeed[loop];
        }
    }
}

float boat_position = 0.0;
float osc_attr = 0.0f;
void Nauka(){
    //boat up side
    //boat roof
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2i(boat_position-800, 50+osc_attr);
    glVertex2i(boat_position-500, 50+osc_attr);
    glVertex2i(boat_position-450, -20+osc_attr);
    glVertex2i(boat_position-750, -20+osc_attr);
    glEnd();
    //boat roof traingle
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(boat_position-800, 50+osc_attr);
    glVertex2i(boat_position-750, -20+osc_attr);
    glVertex2i(boat_position-850, -20+osc_attr);

    glEnd();
    
    //boat down side
    glColor3ub(0,0,0);//Forest Green
    glBegin(GL_QUADS);
    glVertex2i(boat_position-900, -20+osc_attr);
    glVertex2i(boat_position-400, -20+osc_attr);
    glVertex2i(boat_position-500, -80+osc_attr);
    glVertex2i(boat_position-800, -80+osc_attr);
    glEnd();
}

float apple_position = 0.0;
float apspeed = 0.0f;
bool isUp = true;
void Vriksh(){
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(700.5,1.5);
    glVertex2f(750.5,50.5);
    glVertex2f(630.5,120.5);
    glVertex2f(630.5,70.5);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19.5);
    glVertex2f(750.5,50.5);
    glVertex2f(800.5,1.5);
    glVertex2f(850.5,90.5);
    glVertex2f(850.5,130.5);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3ub(139,69,19);
    glVertex2f(700.5,1.5);
    glVertex2f(750.5,50.5);
    glVertex2f(800.5,1.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(700.5,1.5);
    glVertex2f(700.5,-400.5);
    glVertex2f(750.5,-450.5);
    glVertex2f(800.5,-400.5);
    glVertex2f(800.5,1.5);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3ub(139,69,19);
    glVertex2f(600,-30);
    glVertex2f(700.5,-100);
    glVertex2f(700.5,-50);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(700.5,-400.5);
    glVertex2f(800.5,-400.5);
    glVertex2f(850.5,-425.5);
    glVertex2f(650.5,-425.5);
    glEnd();

    int circle_attr[16][3] = {
        {600, 50, 70, },
        {650, 150, 90,},
        {550, 130, 90,},
        {850, 200, 90,},
        {700, 210, 100,},
        {900, 50,  70,},
        {950, 150, 90,},
        {850, 130, 90,},
        {900,207,20,},
        {900,80,20, },
        {800,100,20,},
        {700,180,20,},
        {550,195,20,},
        {650,107,20,},
        {600,20,20,}};

    glColor3ub(50,205,50);
    for (int i = 0; i<9; i++) { DrawCircle(circle_attr[i][0], circle_attr[i][1], circle_attr[i][2], 1000); }
    
    glColor3ub (139,0,0);
    for (int i = 9; i<16; i++) { DrawCircle(circle_attr[i][0], circle_attr[i][1], circle_attr[i][2], 1000); }
    DrawCircle(800,apple_position +200,20,1000);
    DrawCircle(700,apple_position +250,20,1000);
    DrawCircle(500 ,apple_position + 107,20,1000);
}

void Naukatimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, Naukatimer, 0);
    if (boat_position > 2000) {
        boat_position = -940;
    } else boat_position += 1;
    if (osc_attr > 10) {
        isUp = false;
    } else if (osc_attr < -5) {
        isUp = true;
    }
    if (isUp) {
        osc_attr += 0.4;
    } else osc_attr -= 0.4;
}

void appletimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, appletimer, 0);
    if (apple_position < 250) {
        apple_position -= apspeed;
    }
    else if(apple_position > 1000){
        apple_position = 50.0f;
        apspeed = 0.0f;
    }
}
float kukkutspeed = 0.0;
float kukkut_position = 0.0 ;
void Kukkut(){
    glColor3ub(139,69,19);
    DrawCircle(kukkut_position-580, -395, 20, 1000);
    glColor3f(0.0f, 0.0f, 0.0f);
    DrawCircle(kukkut_position-580, -395, 5, 1000);
    glColor3ub(139,69,19);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex2i(kukkut_position-563,-394);
    glVertex2i(kukkut_position-549,-399);
    glVertex2i(kukkut_position-563,-399);
    glVertex2i(kukkut_position-549,-399);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(kukkut_position-600.5,-395);
    glVertex2i(kukkut_position-564.5,-405);
    glVertex2i(kukkut_position-574.5,-441.5);
    glVertex2i(kukkut_position-605.5,-431.5);
    glEnd();
    DrawCircle(kukkut_position-594.5, -450, 22, 1000);
    
    glBegin(GL_POLYGON);
    glVertex2i(kukkut_position-665.5,-450);
    glVertex2i(kukkut_position-614.5,-439);
    
    glVertex2i(kukkut_position-584.5,-471.5);

    glVertex2i(kukkut_position-655.5,-470);
    glEnd();
    Halfcircle(80, 50, kukkut_position-654.5, -450.5);
    
    glLineWidth(4.0f);
    glBegin(GL_LINES);

    glVertex2i(kukkut_position-640,-500);
    glVertex2i(kukkut_position-640,-521);
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2i(kukkut_position-640,-520);
    glVertex2i(kukkut_position-650,-522.5);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2i(kukkut_position-640,-520);
    glVertex2i(kukkut_position-630,-522.5);

    glVertex2i(kukkut_position-640,-520);
    glVertex2i(kukkut_position-633.5,-526.5);
    glEnd();
    
    
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    
    glVertex2i(kukkut_position-665,-500);
    glVertex2i(kukkut_position-665,-518);
    glEnd();
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2i(kukkut_position-665,-518);
    glVertex2i(kukkut_position-675,-520.5);
    glEnd();
    
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2i(kukkut_position-665,-518);
    glVertex2i(kukkut_position-655,-520.5);
    
    glVertex2i(kukkut_position-665,-518);
    glVertex2i(kukkut_position-658.5,-524.5);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2i(kukkut_position-780, -440);
    glVertex2i( kukkut_position-700, -460);
    glVertex2i(kukkut_position-790, -445);

    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2i(kukkut_position-780, -450);
    glVertex2i(kukkut_position-700, -460);
    glVertex2i(kukkut_position-790, -455);

    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2i(kukkut_position-780, -460);
    glVertex2i(kukkut_position-700, -460);
    glVertex2i(kukkut_position-790, -465);

    glEnd();
}
void KukkutTimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(200, KukkutTimer, 0);
    if(kukkut_position < -1000.0f){
    	kukkut_position = 900.0f;
    }
    else if (kukkut_position < 1400) {
        kukkut_position += kukkutspeed;
    }
    else
    	kukkut_position  = -1000.0f;
}
void Draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    Sky();
    Moon();
    River();
    Nauka();
    Hill();
    Megh();
    Bhoomi();
    GroundCurve();
    Soil();
    GroundDownCurve();
    Vriksh();
    Kukkut();
    // for (int yh = 520; yh >= -520; yh-=30) Par(yh+(rand() % (10 - 0 + 1)));
    // Par(520+(rand() % (10+ 1)));
    if (showRain) Par(520);
    // drawSnow();
    glFlush();
    glutSwapBuffers();
    
}
void key_inpt(int key, int x, int y) 
{
     printf("key_code =%d  \n",key);
     switch (key) {    
       case 27 : break;
       case 100 : clspeed -= 0.5f;    
                break;
       case 102: clspeed += 0.5f;     
                break;
       case 101: kukkutspeed += 0.5f;    
                break;
       case 103: apspeed += 0.3f;     
                break;
       case 117: showRain = !showRain; // right alt
                break;
    }
}
void Megh(){
    if (showRain) glColor3f(200/256.0f,197/256.0f,205/256.0f);
    else glColor3f(220/256.0f,200/256.0f,215/256.0f);
    int circle_attr[15][3] = {
        {45, 450, 30, },
        {45, 450, 30,},
        {80, 465, 30, },
        {120, 450, 30,},
        {80, 450, 30, },
        {225, 430, 20,},
        {250, 440, 25,},
        {275, 430, 20,},
        {240, 418, 15,},
        {260, 417, 15,},
        {400, 450, 30,},
        {440, 470, 30,},
        {480, 450, 30,},
        {440, 435, 25,},
        {80, 450, 30, }};
    for (int i = 0; i<15; i++) { DrawCircle(meghposition+circle_attr[i][0], circle_attr[i][1], circle_attr[i][2], 200); }
    if (showRain) {
        int shift = -800;
        int circle_attr1[15][3] = {
        {shift+45, 450, 30, },
        {shift+45, 450, 30,},
        {shift+80, 465, 30, },
        {shift+120, 450, 30,},
        {shift+80, 450, 30, },
        {shift+225, 430, 20,},
        {shift+250, 440, 25,},
        {shift+275, 430, 20,},
        {shift+240, 418, 15,},
        {shift+260, 417, 15,},
        {shift+400, 450, 30,},
        {shift+440, 470, 30,},
        {shift+480, 450, 30,},
        {shift+440, 435, 25,},
        {80, 450, 30, }};
    for (int i = 0; i<15; i++) { DrawCircle(meghposition+circle_attr1[i][0], circle_attr1[i][1], circle_attr1[i][2], 200); }
    }
}

void meghtimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, meghtimer, 0);
    if(meghposition < -1000.0f){
    	meghposition = 960.0f;
    	clspeed = 0.5f;
    }
    else if (meghposition<960) {
        meghposition += clspeed;
    }
    else
    	meghposition  = -1000.0f;
}

int main(int argc,char **argv){
    
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_SINGLE );
    glutInitWindowPosition(200,200);
    glutInitWindowSize(1920,1080);
    glutCreateWindow("Village");
    init();
    initDropSpeed();
    glutDisplayFunc(Draw);
    glutTimerFunc(0, Naukatimer, 0);
    glutTimerFunc(0, moontimer,0);
    glutTimerFunc(0, meghtimer, 0);
    glutTimerFunc(0, appletimer, 0);
    glutTimerFunc(0, dropTimer, 0);
    glutTimerFunc(0, KukkutTimer, 0);
    glutSpecialFunc(key_inpt);
    glutMainLoop();
    return 0;

}


