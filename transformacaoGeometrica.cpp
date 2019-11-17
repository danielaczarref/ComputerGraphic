#include <GL/glut.h>

#include <stdlib.h>

#include <math.h>

#include <thread>

#include <iostream>

#include <stdio.h>

using namespace std;

static GLfloat spin = 0.0;

static GLfloat c_x = 300;
static GLfloat c_y = 300;

static GLfloat t1 = 0;
static GLfloat t2 = 0;

static int angle = 0;
static GLint anguloTotal = 360;

void init(void);

void display(void);

void abreEfecha();

void abrirPacman();

void fecharPacman();

void specialInputDoTeclado(int key, int x, int y);

void keyboard(unsigned char key, int x, int y);

void mouse(int button, int state, int x, int y);

void spinDisplay();

static GLint tamanho = 65;

bool fechar = true;
void reshape(int x, int y);

int main(int argc, char ** argv) 

{

    glutInit(&argc, argv);

    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA);
    
    glutInitWindowSize (600, 700);
    glutInitWindowPosition (100, 100);

    glutCreateWindow("Transformacao Geometrica - Pacman");
    
    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    // glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialInputDoTeclado);
    //glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}


void init(void)

{

glClearColor(1.0, 1.0, 1.0, 1.0);
glOrtho (0, 600, 0, 600, -1 ,1);
glShadeModel(GL_FLAT);

}

void pacman() {

glPushMatrix();
glTranslatef(c_x,c_y, 0);
glRotatef(angle, 0, t1, t2);
glTranslatef(-c_x,-c_y, 0);
glColor4f(1.0, 1.0, 0.0, 0.5);
glBegin(GL_POLYGON);//-25
float theta = 0;
glVertex2f(c_x, c_y);
for (int i = 65; i<360; i++){
    theta = 2*i*3.142/360; //mema bosta
    glVertex2f(c_x + 4*cos(theta)*20, c_y + 4*sin(theta)*20);
}
glEnd();
glColor4f(0.0, 0.0, 0.0, 0.5);
glBegin(GL_POLYGON);
//float theta = 0;
for (int i =0; i<360; i++){
    theta = i*3.142/180;
    glVertex2f((c_x-20)+10*cos(theta), (c_y+40)+10*sin(theta));
}
glEnd();

glFlush();
glPopMatrix();

}

void display(void)

{

int i;
glClear(GL_COLOR_BUFFER_BIT);

pacman();

glutSwapBuffers();

}

void reshape(int x, int y){
    glViewport(0, 0, (GLsizei) x, (GLsizei) y);
    glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    glOrtho(0, 500, 0, 500, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)

{
switch (key) {

    case 27: exit(0); break;

    }

}

void specialInputDoTeclado(int key, int x, int y) {
    switch(key){
        case GLUT_KEY_UP 
            angle = 45;
            c_y += 3;
            if (c_y == 600){
                c_y = 0;
                c_y += 3;
            }
            t1=0;
            t2=1;
            glutPostRedisplay();
            break;

        case GLUT_KEY_DOWN:
            c_y -= 3;
            if (c_y <= 0) {
                c_y = 600;
                c_y -= 3;
            }
            angle = -90;
            t1=0;
            t2=1;
            glutPostRedisplay();
            break;
    
        case GLUT_KEY_LEFT:

            c_x-=3;
            if (c_x <= 0) {
                c_x = 600;
                c_x -= 3;
            }
            angle=180;
            t1=1;
            t2=0;
            glutPostRedisplay();
            break;
    
        case GLUT_KEY_RIGHT:
            c_x += 3;
            if (c_x >= 600){
                c_x = 0;
                c_x += 3;
            }
            angle = 0;
            t1=1;
            t2=0;
            glutPostRedisplay();
            break;
        }

}
