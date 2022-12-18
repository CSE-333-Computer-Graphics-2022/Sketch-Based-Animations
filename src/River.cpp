#include "fun.h"

void River(){
    glBegin(GL_QUADS);
    glColor3ub(65,105,225); //blue color
    glVertex2i(-960, 200);
    glColor4f(0.00, 0.75, 1.00, 1.0);
    glVertex2i(960, 200);
    glColor4f(0.00, 0.75, 1.00, 1.0);
    glVertex2i(960, -300);
    glColor4f(0.00, 0.75, 1.00, 1.0);
    glVertex2i(-960, -300);
    glEnd();
}