//
//  main.cpp
//  Lab 1.2
//
//  Created by Amir on 14.02.2023.
//

#include <iostream>
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <cmath>
void init()
{
    glClearColor(0.9, 0.9, 0.9, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-8.0, 8.0, -2.0, 2.0);
};
void draw()
{
    GLfloat r = 0.0, g = 0.0, b = 0.0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glViewport(0, 0, 800, 600);
    GLint x, y, h = 60, w = 60;
    for(x = 0; x <= 800; x += w)
    {
        for(y = 0; y <= 600; y += h)
        {
            glViewport(x, y, w, h);
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_TRIANGLE_FAN);
                glVertex2f(0, 0);
                for (int i = 0; i <= 360; i++) {
                    glVertex2f(5*cos(i) + 5, 5*sin(i) + 5);
                }
            glEnd();
        }
    }
    glFlush( );
};
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(250, 250);
    glutCreateWindow("Mozaika");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
}

