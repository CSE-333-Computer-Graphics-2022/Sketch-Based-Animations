#include "fun.h"

void Hill(){
   
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0 );
    glVertex2i(70, 434.5);
    glColor4f(0.00, 0.75, 1.00, 1.0);
    glVertex2i(210, 280);
    glColor4f(0.00, 0.75, 1.00, 1.0);
    glVertex2i(-70, 280);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2i(-35.5, 390);
    glColor4f(0.17, 0.43, 0.17, 1.0);
    glVertex2i(150, 280);
    glVertex2i(-150, 280);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2i(160, 390);
    glColor4f(0.17, 0.43, 0.17, 1.0);
    glVertex2i(270, 280);
    glVertex2i(10, 280);
    glEnd();
    glColor3f(1.0, 1.0, 1.0 );
    DrawCircle(30, 405, 10, 1000);
    DrawCircle(40, 405, 10, 1000);
    DrawCircle(50, 410, 12, 1000);
    DrawCircle(60, 405, 10, 1000);
    DrawCircle(70, 410, 12, 1000);
    DrawCircle(80, 405, 10, 1000);
    DrawCircle(90, 410, 12, 1000);
    DrawCircle(100, 405, 10, 1000);
    
    DrawCircle(-20, 412.5, 8, 1000);
    DrawCircle(-10, 415, 10, 1000);
    DrawCircle(0, 412.5, 8, 1000);
    
}
