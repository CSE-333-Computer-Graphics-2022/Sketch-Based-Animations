#include "fun.h"


// float apple_position = 0.0;
// float apspeed = 0.0f;
// void Tree(){
// //top side
//     glBegin(GL_POLYGON);
//     glColor3ub(139,69,19);
//     glVertex2f(700.5,1.5);
//     glVertex2f(750.5,50.5);
//     glVertex2f(630.5,120.5);
//     glVertex2f(630.5,70.5);
//     glEnd();
    
//     glBegin(GL_POLYGON);
//     glColor3ub(139,69,19.5);
//     glVertex2f(750.5,50.5);
//     glVertex2f(800.5,1.5);
//     glVertex2f(850.5,90.5);
//     glVertex2f(850.5,130.5);
//     glEnd();
    
//     glBegin(GL_TRIANGLES);
//     glColor3ub(139,69,19);
//     glVertex2f(700.5,1.5);
//     glVertex2f(750.5,50.5);
//     glVertex2f(800.5,1.5);
//     glEnd();
    
//     //middle side
//     glBegin(GL_POLYGON);
//     glColor3ub(139,69,19);
//     glVertex2f(700.5,1.5);
//     glVertex2f(700.5,-400.5);
//     glVertex2f(750.5,-450.5);
//     glVertex2f(800.5,-400.5);
//     glVertex2f(800.5,1.5);
//     glEnd();
    
//     glBegin(GL_TRIANGLES);
//     glColor3ub(139,69,19);
//     glVertex2f(600,-30);
//     glVertex2f(700.5,-100);
//     glVertex2f(700.5,-50);
//     glEnd();

//     //down side
//         glBegin(GL_POLYGON);
//         glColor3ub(139,69,19);
//         glVertex2f(700.5,-400.5);
//         glVertex2f(800.5,-400.5);
//         glVertex2f(850.5,-425.5);
//         glVertex2f(650.5,-425.5);
//         glEnd();

    
//     //tree leaf
//     glColor3ub(50,205,50);
//     DrawCircle(600, 50, 70, 1000);
//     DrawCircle(650, 150, 90, 1000);
//     DrawCircle(550, 130, 90, 1000);
    
//     DrawCircle(850, 200, 90, 1000);
//     DrawCircle(700, 210, 100, 1000);
    
//     DrawCircle(900, 50, 70, 1000);
//     DrawCircle(950, 150, 90, 1000);
//     DrawCircle(850, 130, 90, 1000);
    
//     //apple
//     glColor3ub (139,0,0);
//     DrawCircle(900,207,20,1000);
//     DrawCircle(900,80,20,1000);
//     DrawCircle(800,200,20,1000);
//     DrawCircle(800,100,20,1000);
//     DrawCircle(700,apple_position +250,20,1000);
//     DrawCircle(700,180,20,1000);
//     DrawCircle(550,195,20,1000);
    
//     DrawCircle(500 ,apple_position + 107,20,1000);
    
//     DrawCircle(650,107,20,1000);
//     DrawCircle(600,20,20,1000);

    
// }

// void appletimer(int)
// {
//     glutPostRedisplay();
//     glutTimerFunc(1000/60, appletimer, 0);
//     if (apple_position < 250) {
//         apple_position -= apspeed;
//     }
//     else if(apple_position > 1000){
//         apple_position = 50.0f;
//         apspeed = 0.0f;
//     }
// }