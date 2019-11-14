#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

using namespace std;

GLfloat angulo = 90;

GLfloat a1 = 0.0f;
GLfloat a2 = 0.0f;
GLfloat a3 = 0.0f;

GLfloat c1 = 0.0f;
GLfloat c2 = 0.0f;
GLfloat c3 = 0.0f;

GLfloat b1 = 0.0f;
GLfloat b2 = 0.0f;
GLfloat b3 = 0.0f;

void chamaFormaFigura();
void alteraJanela(int largura, int altura);
void keyboard(unsigned char key, int x, int y);
void display();
void atualizaImagem(int num);

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 27: 
			exit(0);
            break;
        case 'a':
            a1 += 0.3f;
            a2 += 0.1f;
            a3 += 0.2f;

            c1 += 0.1f;
            c2 += 0.1f;
            c3 += 0.1f;

            b1 += 0.1f;
            b2 += 0.1f;
            b3 += 0.1f;
            break;
        case 'b':
            a1 -= 0.3f;
            a2 -= 0.1f;
            a3 -= 0.2f;

            c1 -= 0.1f;
            c2 -= 0.1f;
            c3 -= 0.1f;

            b1 -= 0.1f;
            b2 -= 0.1f;
            b3 -= 0.1f;
            break;
	}
}

void init() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Bota luz
	glEnable(GL_LIGHT0); //Bota outra luz
	glEnable(GL_LIGHT1); //Bota outra luz
	glEnable(GL_NORMALIZE); 
}

void alteraJanela(int largura, int altura) {
    if (altura == 0){
        altura = 1;
    }
	glViewport(0, 0, largura, altura);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (float) (largura/altura), 1, 200);
}


void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glTranslatef(0.0f, 0.0f, -8.0f);
	
	//pra adicionar luz ambiente
	GLfloat corAmbiente[] = {0.2f + a1, 0.2f + a2, 0.2f + a3, 1.0f}; 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, corAmbiente);
	
	//pra adicionar posicao da luz
	GLfloat corLuz[] = {0.2f + b1, 0.2f + b2, 0.2f + b3, 0.7f}; 
	GLfloat posicaoLuz[] = {8.0f, 2.0f, 10.0f, 1.0f}; 
	// glLightfv(GL_LIGHT0, GL_DIFFUSE, corLuz);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
	
	//pra adicionar luz direcionada
	// GLfloat corLuz1[] = {1.0f - c1, 0.6f - c2, 0.2f + c3, 1.0f};
	// GLfloat posicaoLuz1[] = {-1.0f, 0.5f, 0.9f, 0.0f};
	// glLightfv(GL_LIGHT1, GL_DIFFUSE, corLuz1);
	// glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz1);

	GLfloat luzEspecular[] = {0.0f, 0.2f, 0.2f, 1.0f};
	GLfloat outraLuz[] = {50};
	glMaterialfv(GL_FRONT, GL_SPECULAR, luzEspecular);
//	GLfloat luzEspecular[] = {0.0f, 0.2f, 0.2f, 1.0f};
	glMaterialfv(GL_FRONT, GL_DIFFUSE, corLuz);
	glMaterialfv(GL_FRONT, GL_SHININESS, outraLuz);
    chamaFormaFigura();
	
}

void chamaFormaFigura() {
    glRotatef(angulo, 0.0f, 1.0f, 0.0f);
	glColor3f((20.0/255.0f), (190.0/255.0f), (187.0/255.0f));
	glBegin(GL_QUADS);
	
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	
	glEnd();	
	glutSwapBuffers();
}

void atualizaImagem(int num) {
	angulo += 1.5f;
	if (angulo > 360) {
		angulo -= 360;
	}
	
	glutPostRedisplay();
	glutTimerFunc(25, atualizaImagem, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Ilumina td bb");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(alteraJanela);	
	glutTimerFunc(25, atualizaImagem, 0);	
	glutMainLoop();
	return 0;
}