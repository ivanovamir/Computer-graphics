//
//  main.cpp
//  Lab 1.1
//
//  Created by Amir on 14.02.2023.
//

#include <iostream>
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <cmath>

// Константы m1 и m2
const double m1 = 1.0; // Устанавливаем константы для m1
const double m2 = 1.0; // Устанавливаем константы для m2

const GLfloat red = 1.0f;     // Красный цвет
const GLfloat green = 0.97f;  // Зеленый цвет
const GLfloat blue = 0.86f;   // Синий цвет

// Функция y(t)
double y(double t) {
    return std::sin(m1 * t) * std::cos(m2 * t);
}

// Функция отображения
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Очищаем буфер кадра (framebuffer) | GL_COLOR_BUFFER_BIT - очищаем только цветовой буфер кадра

    // Задаем цвет осей координат
    glColor3f(0.0, 0.0, 0.0);

    // Рисуем ось x
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2d(0.0, 0.0);
    glVertex2d(10.0, 0.0);
    glEnd();

    // Рисуем ось y
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2d(0.0, -1.0);
    glVertex2d(0.0, 1.0);
    glEnd();

    // Рисуем вертикальную ось x
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2d(0.0, 0.0);
    glVertex2d(0.0, -1.0);
    glEnd();

    // Рисуем вертикальную ось y
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2d(0.0, 0.0);
    glVertex2d(0.0, 1.0);
    glEnd();

    // Задаем цвет графика функции
    glColor3f(220/255.0, 20/255.0, 60/255.0);

    // Рисуем график функции
    glLineWidth(1.0);
    glBegin(GL_LINE_STRIP);
    for (double t = 0.0; t <= 100.0; t += 0.01) {
        glVertex2d(t, y(t));
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Graph of y(t)"); // Имя окна
    glClearColor(red, green, blue, 1.0f); // фон окна
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 10.0, -1.0, 1.0); // МСК
    glutDisplayFunc(display); // Отоброжаем функцию "display"
    glutMainLoop(); // Передаем управление внутреннему циклу GLUT
    return 0;
}
