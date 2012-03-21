#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<math.h>
#include "classes.h"
using namespace std;
int ww=500, wh = 500;
int unit = 80;

void setval(int x, int y){

}
void init( void){
		glShadeModel(GL_SMOOTH);
		glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
		glClearDepth(1.0f);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glEnable(GL_COLOR_MATERIAL);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display(void){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		Point p1 (0.0f, 0.0f);
		Point p2 (0.0f, 1.0f);
		Point p3 (1.0f, 1.0f);
		Point p4 (1.0f, 0.0f);
		Color c (1.0f, 0.0f, 0.0f);
		Quadrangle q (p1, p2, 0, c, c);
		glBegin(GL_POINTS);
		q.draw();
		glEnd();
		glutSwapBuffers();
}
void reshape(int w, int h){
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if( h==0 ){
		gluPerspective(unit, (float) w, 1.0, 5000.0);
	}
	else{
		gluPerspective(unit, (float)w/(float)h, 1.0, 5000.0);
	}
	glMatrixMode( GL_MODELVIEW);
	glLoadIdentity();
	ww= w;
	wh= h;
}
void keyboard( unsigned char key, int x, int y){
	switch (key){
		case 'q':
			exit(0);
		default:
			break;
	}
}

void arrow_keys( int a_keys, int x, int y){
	switch(a_keys){
		case GLUT_KEY_UP:
			glutFullScreen();
			break;
		case GLUT_KEY_DOWN:
			glutReshapeWindow(500, 500);
			break;
		default:
			break;
	}
}
void mouse(int btn, int state, int x, int y){
	if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN){

	}
}

int main(int argc, char** argv){




	glutInit( &argc, argv);
	init();
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize( 500, 500);
	glutCreateWindow( "graffITi");
	glutDisplayFunc( display);
	glutReshapeFunc(reshape);
	glutMouseFunc( mouse);
	glutMotionFunc( setval);
	glutKeyboardFunc(keyboard);
//	glutIdleFunc(display);
	glutSpecialFunc( arrow_keys);
	glutMainLoop();
}

