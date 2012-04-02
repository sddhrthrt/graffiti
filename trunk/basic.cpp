#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<math.h>
#include<stdio.h>
int ww=500, wh = 500;
float X=500.0f, Y=500.0f ;
int unit = 10;
int curr_year=0;

using namespace std;

#include "classes.h"
Graph g ;
void setval(int x, int y){

}
void init( void){
		glShadeModel(GL_SMOOTH);
		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
		glClearDepth(1.0f);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glEnable(GL_COLOR_MATERIAL);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display(void){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
		glLoadIdentity();
		//glTranslatef(0.0f, 0.0f, -6.0f);
		glBegin(GL_POINTS);
			g.plot();
		glEnd();
		glutSwapBuffers();
}
void reshape(int w, int h){
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/*if( h==0 ){
		gluPerspective(unit, (float) w, 1.0, 5000.0);
	}
	else{
		gluPerspective(unit, (float)w/(float)h, 1.0, 5000.0);
	}*/
	ww=w;
	X=(float)ww/(float)unit;
	wh=h;
	Y=(float)wh/(float)unit;
	gluOrtho2D(0.0f, X, 0.0f, Y);
	cout<<X<<", "<<Y<<"\n";
	glMatrixMode( GL_MODELVIEW);
	glLoadIdentity();
}
void keyboard( unsigned char key, int x, int y){
	switch (key){
		case 'q':
			exit(0);
			break;
		case 'n':
			if(curr_year<48){
				curr_year++;
			}
			break;
		case 'p':
			if(curr_year>=1){
				curr_year--;
			}
			break;
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
	g.read();
	glutInit( &argc, argv);
	init();
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize( 500, 500);
	glutCreateWindow( "graffITi");
//	glutFullScreen();
	glutDisplayFunc( display);
	glutReshapeFunc(reshape);
	glutMouseFunc( mouse);
	glutMotionFunc( setval);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(display);
	glutSpecialFunc( arrow_keys);
	glutMainLoop();
}

