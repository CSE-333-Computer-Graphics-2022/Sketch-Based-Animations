#include "fun.h"

void Sky(){
    glBegin(GL_QUADS);
    
    //dark blue color
    glColor4f(0.00, 0.75, 1.00, 1.0);
    glVertex2i(-960, 540);
    glVertex2i(960, 540);
    //light blue color
    glColor4f(0.53, 0.81, 0.98, 1.0);
    glVertex2i(960, 280);
    glVertex2i(-960, 280);
    
    glEnd();
}


