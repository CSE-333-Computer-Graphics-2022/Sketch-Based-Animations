#include "fun.h"
// int yPos = 520;
float moon_position = 710;
// float dropSpeed[PAR_SIZE] = {1};    // 60 drops
int loop = 0;
void Moon()
{
    glColor3f(1.0, 1.0, 1.0 );
    DrawCircle(400, moon_position, 50, 1000);
}

void moontimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, moontimer, 0);
    if (moon_position > 240) {
        moon_position -= 1;
    }
}