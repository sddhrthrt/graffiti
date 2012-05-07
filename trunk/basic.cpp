#include<GL/gl.h>
#include<GL/glut.h>
#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<cstring>
#include<math.h>
#include<stdio.h>
int ww=500, wh = 500;
float X=50.0f, Y=50.0f ;

int dragstart_x, dragstart_y, diff_x, diff_y;
float* var_drag_x, *var_drag_y, dummy;
enum mousemode { RELEASE, DRAG } curr_mouse=RELEASE;

int startx=0, starty=0;
int unit = 10;
int menu,menu1,menu2,menu3;
using namespace std;
enum style{ POPULATION, ENVIRONMENT, HEALTH, POPULATION_GRAPH, FOOD_GRAPH}curr_style;
enum representation{ GRAPH, BAR, PIE, DEBUG }curr_representation;
enum states{ CLICK_WAIT, MAIN_MENU, MENU_SELECT,  ANIMATE} curr_mode=CLICK_WAIT;
enum element { INVALID, GRAPHAREA, RESIZE_CORNER };
#include "classes.h"
#include "graphs2.cpp"
Graph_Population g (10, 10, X, Y);
//Graph_Population 2(10,10,60,50);
void init( void){
		glShadeModel(GL_SMOOTH);
		glClearColor(0.9f, 0.9f, 0.9f, 0.9f);
		glClearDepth(1.0f);
		glEnable(GL_COLOR_MATERIAL| GL_POINT_SMOOTH);
		glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
}
void welcomenote(){
	string title1="Scientific Data";
	string title2="Visualization";
	string authors1="Akhil Anantha Chandrakanth ";
	string authors2="Shrimai Siddhartha";
	string note = "Right click for menu at any time.";
	PrintText title_text (title1, 3.0f, Y/2, 6.0f, pallete[2],6.0f);
	title_text.draw();
	title_text.setText(title2);
	title_text.setxy(3.0f, Y/2-7.0f);
	title_text.draw();
	PrintText authors_text (authors1, 3.0f, Y/2-12.0f, 2.6f,pallete[4],3.0f);
	authors_text.draw();
	authors_text.setText(authors2);
	authors_text.setxy(3.0f, Y/2-17.0f);
	authors_text.draw();
	PrintText note_text (note, 3.0f, Y/2-22.0f, 2.4f,pallete[1], 2.0f);
	note_text.draw();
}
void display(void){
			segfile.seekp(ios::beg);
			areas.clear();
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.8f, 0.8f, 0.9f, 0.0f);
			glLoadIdentity();
			switch(curr_mode){
				case 0:
				switch(curr_style){
					case 0:
					g.plot();
					break;
				}
				break;
					
				case 1:
					welcomenote();
					break;
				case 2:
				case 3:
				break;
			}
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
	glMatrixMode( GL_MODELVIEW);
	glLoadIdentity();
}

void menuHandler(int x){
	switch(x){
		case 1: curr_style = POPULATION;
			curr_mode=CLICK_WAIT;
			menu1=glutCreateMenu(menuHandler);
			glutAddMenuEntry("Single Graph", 21);
			glutAddMenuEntry("Multiple Graphs", 22);
			glutAddMenuEntry("Back To Main", 29);	
			glutSetMenu(menu);
			glutChangeToSubMenu(1,"Population Options:",menu1);			
			//glutSetMenu(menu1);
			glutAttachMenu(GLUT_RIGHT_BUTTON);
			
			break;
		case 29:
			glutSetMenu(menu);
			glutAttachMenu(GLUT_RIGHT_BUTTON);
			break;
		case 21:
			g.setState(0);
			menu2=glutCreateMenu(menuHandler);
			glutAddMenuEntry("Population", 31);
			glutAddMenuEntry("CerealProduction", 32);
			glutAddMenuEntry("BirthRate", 33);
			glutAddMenuEntry("DeathRate", 34);
			glutAddMenuEntry("MobilePhones", 35);
			glutAddMenuEntry("Animate", 36);
			glutAddMenuEntry("Back", 19);
			//glutChangeToSubMenu(1,"Population - A Study",menu1);			
			//glutSetMenu(menu1);
			glutAttachMenu(GLUT_RIGHT_BUTTON);
			break;
		case 36:
			g.setState(2);
			break;
		case 31:
			g.setChoice(0);
			g.circ.clear();
			g.createCircle();
			break;
		case 32:
			g.setChoice(2);
			g.circ.clear();
			g.createCircle();
			break;
		case 33:
			g.setChoice(3);
			g.circ.clear();
			g.createCircle();
			break;
		case 34:
			g.setChoice(4);
			g.circ.clear();
			g.createCircle();
			break;
		
		case 35:
			g.setChoice(5);
			break;
		case 19:
			glutSetMenu(menu1);
			glutAttachMenu(GLUT_RIGHT_BUTTON);
			break;
		case 22:
			
			g.setState(1);
			menu3=glutCreateMenu(menuHandler);
			
			glutAddMenuEntry("CerealProduction", 42);
			glutAddMenuEntry("BirthRate", 43);
			glutAddMenuEntry("DeathRate", 44);
			glutAddMenuEntry("MobilePhones", 45);
			glutAddMenuEntry("Back", 19);
			//glutChangeToSubMenu(1,"Population - A Study",menu1);			
			//glutSetMenu(menu1);
			glutAttachMenu(GLUT_RIGHT_BUTTON);
			break;
		
		case 42:
			g.setIndex(2);
			break;
		case 43:
			g.setIndex(3);
			break;
		case 44:
			g.setIndex(4);
			break;
		
		case 45:
			g.setIndex(5);
			break;	
		case 99:
			exit(0);
			break;
		default: break;
		}
}

void keyboard( unsigned char key, int x, int y){
	switch (key){
		case 'q':
			exit(0);
			break;
		case 'i':
			g.zoomInGraph();
			break;
		case 'o':
			g.zoomOutGraph();
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
			glutReshapeWindow(1024, 762);
			break;
		case GLUT_KEY_LEFT:
			g.deltaX-=10;	
			break;
		case GLUT_KEY_RIGHT:
			g.deltaX+=10;	
			break;
		default:
			break;
	}
}
void mouse(int btn, int state, int x, int y){
	y=wh-y;
	if(curr_mode==CLICK_WAIT){
		
		if(btn == GLUT_LEFT_BUTTON && state==GLUT_DOWN){
			element l = Operations::fetchArea(x, y);
		
			switch (l){
				
				case 1:
					// for dragging the graph
					curr_mouse=DRAG;
					diff_x=0;
					diff_y=0;
					dragstart_x=x;
					dragstart_y=y;
					var_drag_x=g.getDeltaX();
					break;
				case 2:
					// for rubber banding technique on the graph
					curr_mouse=DRAG;
					diff_x=0;
					diff_y=0;
					dragstart_x=x;
					dragstart_y=y;
					var_drag_x=g.getDraggedX();
					var_drag_y=g.getDraggedY();
					
				default:
					break;
			}
		}
		else if(btn == GLUT_LEFT_BUTTON && state==GLUT_UP){
			if(curr_mouse==DRAG){
				curr_mouse==RELEASE;
				var_drag_x=&dummy;
				var_drag_y=&dummy;
			}
		}
	}
	
		
}


void setval(int x, int y){
	y=wh-y;
	if(curr_mouse==DRAG){
/*			diff_x=x-dragstart_x;
			diff_y=y-dragstart_y;
			dragstart_x=x;
			dragstart_y=y;
			*var_drag_x+=diff_x/(float)unit;
			*var_drag_y+=diff_y/(float)unit;*/
			*var_drag_x=x/(float)unit-20.0f;
			*var_drag_y=y/(float)unit-20.0f;
			
		}
	
}

int main(int argc, char** argv){
	segfile.open("segfile", ios::out);
	g.read();
	//g2.read();
	Operations::setPallete(1);	
	curr_representation=GRAPH;
	curr_mode=MAIN_MENU;
	var_drag_x=&dummy;
	var_drag_y=&dummy;
	glutInit( &argc, argv);
	init();
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize( 500, 500);
	glutCreateWindow( "graffITi");
	glutFullScreen();
//	glutFullScreen();
	
	menu=glutCreateMenu(menuHandler);
	glutAddMenuEntry("Population - A Study", 1);
	glutAddMenuEntry("Exit", 99);
	
	
			
	glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutDisplayFunc( display);
	glutReshapeFunc(reshape);
	glutMouseFunc( mouse);
	glutMotionFunc( setval);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(display);
	glutSpecialFunc( arrow_keys);
	glutMainLoop();
}

