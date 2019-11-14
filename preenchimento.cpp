#include <GL/glut.h>
#include <stdlib.h>

GLfloat r, g, b;
GLubyte tux[] = {
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x38,
    0x0, 0x0, 0x0, 0x10,
    0x0, 0x0, 0x0, 0x10,
    0x03, 0x0, 0x3e, 0x1c,
    0x03, 0x0, 0x08, 0x14,
    0x02, 0x60, 0x08, 0x74,   
    0x02, 0x60, 0x38, 0x54,
    0x03, 0xc0, 0x28, 0x54,
    0x03, 0xe0, 0x2e, 0x54,
    0x03, 0xe0, 0x2a, 0x54,
    0x3f, 0xe0, 0x2a, 0x50,
    0x3f, 0xe8, 0x2a, 0x10,
    0x3f, 0xe8, 0x0a, 0x10,
    0x27, 0xf8, 0x0a, 0x10,
    0x23, 0xe0, 0x08, 0x0,
    0x0, 0xf0, 0x08, 0x0,
    0x0, 0xfc, 0x0, 0x0,
    0x0, 0xe0, 0x0, 0x0,
    0x0, 0xfc, 0x0, 0x0,
    0x0, 0xfc, 0x0, 0x0,
    0x0, 0xfc, 0x0, 0x0,
    0x0, 0xdc, 0x0, 0x0,
    0x0, 0x7c, 0x0, 0x0,
    0x0, 0x78, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0
};

GLfloat vermelho1, verde1, azul1;
GLfloat vermelho2, verde2, azul2;

int x1 = 50;
int y1 = 50;
int x2 = 270;
int y2 = 50;
int x3 = 270;
int y3 = 270;
int x4 = 50;
int y4 = 270;

int escalaX = 0;
int escalaY = 0;

int largura = 320;
int altura = 320;


void init(void);

void display(void);

void alteraJanela (int altura, int largura);

void mouse(int button , int state, int x, int y);

void keyboard(unsigned char key, int x, int y);

int main(int argc, char ** argv) 

{

    glutInit(&argc, argv);

    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);    
    glutInitWindowSize (largura, altura);
    glutInitWindowPosition (100, 100);
    glutCreateWindow("Preenchimento");
    
    init();
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutReshapeFunc(alteraJanela);
    glutMainLoop();
    return 0;
}


void init(void)

{
//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
glClearColor(1.0, 1.0, 1.0, 1.0);
glOrtho (0, largura, 0, altura, -1 ,1);

}


void display(void)

{

int i;
glClear(GL_COLOR_BUFFER_BIT);
glEnable(GL_POLYGON_STIPPLE);
glColor3f(vermelho1, verde1, azul1);
glPolygonStipple(tux);
glBegin(GL_POLYGON);
glVertex2i(x1, y1);
glVertex2i(x2, y2);
glVertex2i(x3, y3);
glVertex2i(x4, y4);
glVertex2i(x1, y1);
glEnd();
glFlush();
glutSwapBuffers();
// glFlush();
// glutSwapBuffers();

// glEnable(GL_POLYGON_STIPPLE);
// glColor3f(vermelho2, verde2, azul2);
// glPolygonStipple(tux);
// glBegin(GL_POLYGON_BIT);
// glVertex2i(0, 0);
// glVertex2i(600, 0);
// glVertex2i(0, 600);
// glVertex2i(600, 600);
// glVertex2i(0, 0);
// glEnd();
// glFlush();
// glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)

{
switch (key) {

    case 27: 
        exit(0); 
        break;
    }
}

void mouse(int button , int state, int x, int y){
   switch (button ) {
      case GLUT_LEFT_BUTTON:
        escalaX = glutGet(GLUT_WINDOW_WIDTH)/largura;
        escalaY = glutGet(GLUT_WINDOW_HEIGHT)/altura;
        if (state == GLUT_DOWN){
            if ((x>= escalaX*50) && (x<=glutGet(GLUT_WINDOW_WIDTH) - escalaX*50) && (y >= escalaY*50) && (y<=glutGet(GLUT_WINDOW_HEIGHT) - escalaY*50)){
                vermelho1=(GLfloat)rand()/(RAND_MAX+1.0);
                verde1=(GLfloat)rand()/(RAND_MAX+1.0);
                azul1=(GLfloat)rand()/(RAND_MAX+1.0);
                glutPostRedisplay();//atualiza display
            }
        }
         
        break;
    }
}

void alteraJanela(int x, int y){
    if (y == 0){
        y = 1;
    }
    float taxa = 1.0 * (x2/y);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, x, y);
 //   gluPerspective(45, taxa, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}
