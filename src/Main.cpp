#include "fun.h"
float clspeed = 0.0f;
float meghposition = 0.0;
void moontimer(int);
void meghtimer(int);
void appletimer(int);
int state;

float axisshift = 1.0;
void init(void){
    glClearColor(0,0,0,0);
    gluOrtho2D(-960.0, 960.0, -540.0, 540.0);    
}

float apple_position = 0.0;
float apspeed = 0.0f;
void Tree(){
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

    glColor3ub(50,205,50);
    DrawCircle(600, 50, 70, 1000);
    DrawCircle(650, 150, 90, 1000);
    DrawCircle(550, 130, 90, 1000);
    
    DrawCircle(850, 200, 90, 1000);
    DrawCircle(700, 210, 100, 1000);
    
    DrawCircle(900, 50, 70, 1000);
    DrawCircle(950, 150, 90, 1000);
    DrawCircle(850, 130, 90, 1000);
    
    glColor3ub (139,0,0);
    DrawCircle(900,207,20,1000);
    DrawCircle(900,80,20,1000);
    DrawCircle(800,200,20,1000);
    DrawCircle(800,100,20,1000);
    DrawCircle(700,apple_position +250,20,1000);
    DrawCircle(700,180,20,1000);
    DrawCircle(550,195,20,1000);
    
    DrawCircle(500 ,apple_position + 107,20,1000);
    
    DrawCircle(650,107,20,1000);
    DrawCircle(600,20,20,1000);

    
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

void Draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    Sky();
    Hill();
    Moon();
    Megh();
    Ground();
    GroundCurve();
    Soil();
    GroundDownCurve();
    Tree();
    // drawSnow();
    glFlush();
    glutSwapBuffers();
    
}
void key_inpt(int key, int x, int y) 
{
     switch (key) {    
       case 27 : break;
       case 100 : clspeed -= 0.5f; break;
       case 102: clspeed += 0.5f; break;
       case 101: break;
       case 103: apspeed += 0.3f; break;
    }
}
void Megh(){

    glColor3f(1.0, 1.0, 1.0 );

    DrawCircle(meghposition+45, 450, 30, 200);
    DrawCircle(meghposition+45, 450, 30, 200);
    DrawCircle(meghposition+80, 465, 30, 200);
    DrawCircle(meghposition+120, 450, 30, 200);
    DrawCircle(meghposition+80, 450, 30, 200);
    
    DrawCircle(meghposition+225, 430, 20, 200);
    DrawCircle(meghposition+250, 440, 25, 200);
    DrawCircle(meghposition+275, 430, 20, 200);
    DrawCircle(meghposition+240, 418, 15, 200);
    DrawCircle(meghposition+260, 417, 15, 200);

    DrawCircle(meghposition+400, 450, 30, 200);
    DrawCircle(meghposition+440, 470, 30, 200);
    DrawCircle(meghposition+480, 450, 30, 200);
    DrawCircle(meghposition+440, 435, 25, 200);
    DrawCircle(meghposition+80, 450, 30, 200);
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
    glutDisplayFunc(Draw);
    glutTimerFunc(0, moontimer,0);
    glutTimerFunc(0, meghtimer, 0);
    glutTimerFunc(0, appletimer, 0);
    glutSpecialFunc(key_inpt);
    glutMainLoop();
    return 0;

}
