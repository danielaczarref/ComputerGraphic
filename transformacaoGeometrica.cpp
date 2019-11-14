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

//glColor4f(1.0, 1.0, 0.0, 0.5);

// glBegin(GL_POLYGON);
// //float theta = 0;
// for (int i = 105; i<180; i++){
//     theta = i*3.142/90;
//     glVertex2f(230+90*cos(theta), 360+80*sin(theta));
// }

// glEnd();
// glFlush();


//Bolinhas Vermelhas

// glColor4f(1.0, 0.0, 0.0, 0.5);

// glBegin(GL_POLYGON);
// //float theta = 0;
// for (int i =0; i<360; i++){
//     theta = i*3.142/180;
//     glVertex2f(300+10*cos(theta), 380+10*sin(theta));
// }

// glEnd();
// glFlush();

// glColor4f(1.0, 0.0, 0.0, 0.5);

// glBegin(GL_POLYGON);
// //float theta = 0;
// for (int i =0; i<360; i++){
//     theta = i*3.142/180;
//     glVertex2f(350+10*cos(theta), 380+10*sin(theta));
// }

// glEnd();
// glFlush();

// glColor4f(1.0, 0.0, 0.0, 0.5);

// glBegin(GL_POLYGON);
// //float theta = 0;
// for (int i =0; i<360; i++){
//     theta = i*3.142/180;
//     glVertex2f(400+10*cos(theta), 380+10*sin(theta));
// }

// glEnd();
// glFlush();

// glColor4f(1.0, 0.0, 0.0, 0.5);

// glBegin(GL_POLYGON);
// //float theta = 0;
// for (int i =0; i<360; i++){
//     theta = i*3.142/180;
//     glVertex2f(450+10*cos(theta), 380+10*sin(theta));
// }

// glEnd();
// glFlush();

// glEnd();
// glFlush();

// glColor4f(1.0, 0.0, 0.0, 0.5);

// glBegin(GL_POLYGON);
// //float theta = 0;
// for (int i =0; i<360; i++){
//     theta = i*3.142/180;
//     glVertex2f(500+10*cos(theta), 380+10*sin(theta));
// }

// glEnd();
// glFlush();

// glColor4f(1.0, 0.0, 0.0, 0.5);

// glBegin(GL_POLYGON);
// //float theta = 0;
// for (int i =0; i<360; i++){
//     theta = i*3.142/180;
//     glVertex2f(550+10*cos(theta), 380+10*sin(theta));
// }

// glEnd();
// glFlush();

// glColor4f(1.0, 0.0, 0.0, 0.5);

// glBegin(GL_POLYGON);
// //float theta = 0;
// for (int i =0; i<360; i++){
//     theta = i*3.142/180;
//     glVertex2f(600+10*cos(theta), 380+10*sin(theta));
// }

// glEnd();
// glFlush();

}

void olho() {

// glColor4f(0.0, 0.0, 0.0, 0.5);

// glBegin(GL_POLYGON);
// float theta = 0;
// for (int i =0; i<360; i++){
//     theta = i*3.142/180;
//     glVertex2f(280+10*cos(theta), 340+10*sin(theta));
// }

// glEnd();
// glFlush();

}

void display(void)

{

int i;
glClear(GL_COLOR_BUFFER_BIT);

// glPushMatrix();
// glTranslatef(spin,0,0);
// glRotatef(0, 0.0, 0.0, 1.0);
//glTranslatef(-spin,0,0);
// glTranslatef(-spin,360,0);

pacman();
//olho();
//glPopMatrix();
glutSwapBuffers();

}

// void mouse(int button, int state, int x, int y){
//     switch (button){
//         case GLUT_LEFT_BUTTON:
//             if (state == GLUT_DOWN){
//                // glutIdleFunc(spinDisplay);
//             }
//             break;
//         case GLUT_MIDDLE_BUTTON:
//             if (state == GLUT_DOWN){
//                 // glutIdleFunc(NULL);
//             }
//             break;
//         default:
//         break;
//     }
// }

// void spinDisplay(){
//     abreEfecha();
//     spin = spin + 2.0f;
//     if (spin > 360){
//         spin = spin - 600;
//     }
//     glutPostRedisplay();
// }

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

    // case 'a':
    //     abrirPacman();
    // break;
    case 32: 
        // abreEfecha();
    //    glutIdleFunc(abreEfecha);
    break;

    }

}

// void abrirPacman(){

    
//      for (int i=0; i<66; i++){
//         tamanho --;
//         glutPostRedisplay();
        
//     }
 
// }

// void fecharPacman() {
        
//        for (int i=0; i<63; i++){
//             tamanho++;
//             glutPostRedisplay();

//         }

// }

// void abreEfecha(){

//     if(fechar){

//         tamanho = tamanho - 3;
//         if(tamanho < 0){
//             fechar = false;
//         }
//     }else{
//         tamanho += 3;
//         if(tamanho > 65){
//             fechar = true;

//         }
//     }

//     glutPostRedisplay();

// }

void specialInputDoTeclado(int key, int x, int y) {
    switch(key){
        case GLUT_KEY_UP:
            // tamanho = 65;
            // anguloTotal = 360; 
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
            // tamanho = 210;
            // anguloTotal = 175;
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