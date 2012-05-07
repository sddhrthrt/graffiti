#include<stdio.h>
#include <stdlib.h>
#include<GL/glut.h>
#include<math.h>
float scale=1;
int x_rubber=900;
int y_rubber=900;
int year[50];
float fertility_china[50];
float fertility_ethiopia[50];
float fertility_india[50];
float fertility_uganda[50];
float fertility_america[50];
float fertility_vietnam[50];
float life_expectancy_china[50];
float life_expectancy_ethiopia[50];
float life_expectancy_india[50];
float life_expectancy_uganda[50];
float life_expectancy_america[50];
float life_expectancy_vietnam[50];
float population_china[50];
float population_ethiopia[50];
float population_india[50];
float population_uganda[50];
float population_america[50];
float population_vietnam[50];
void circle (int xc,int yc,int r);
void DDA_algorithm(float x0,float y0,float x1,float y1)
{
	int j,k,l;
	float x_inc,y_inc,x,y,dx,dy,steps;
	dx=x1-x0;
	dy=y1-y0;
	x=x0;y=y0;
	//glColor3f(1.0,0.0,0.0);
	glVertex2f(x0,y0);
	if(abs(dx)>abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	x_inc=dx/steps;
	y_inc=dy/steps;
	for(j=0;j<=steps;j++)
	{
		x=x_inc+x;
		y=y_inc+y;
		glVertex2f(x,y);
	}
}
void fill(float xc,float yc,float r)
{
	float x,y;
	for(x=xc-r;x<=xc+r;x+=1)
	for(y=yc-r;y<=yc+r;y+=1)
	{
		if (((((x-xc)*(x-xc))/(r*r))+(((y-yc)*(y-yc))/(r*r))-1)<0)
			glVertex2f(x,y);
	}
}
void plot_line()
{
	int i;
	for(i=0;i<49;i++)
	{
	glColor3f(0.0f,1.0f,0.0f);
	DDA_algorithm(fertility_ethiopia[i]*100,life_expectancy_ethiopia[i]*10,fertility_ethiopia[i+1]*100,life_expectancy_ethiopia[i+1]*10);
	glColor3f(1.0f,0.0f,0.0f);
	DDA_algorithm(fertility_china[i]*100,life_expectancy_china[i]*10,fertility_china[i+1]*100,life_expectancy_china[i+1]*10);
	glColor3f(0.0f,0.0f,1.0f);
	DDA_algorithm(fertility_india[i]*100,life_expectancy_india[i]*10,fertility_india[i+1]*100,life_expectancy_india[i+1]*10);
	glColor3f(1.0f,1.0f,0.0f);
	DDA_algorithm(fertility_uganda[i]*100,life_expectancy_uganda[i]*10,fertility_uganda[i+1]*100,life_expectancy_uganda[i+1]*10);
	glColor3f(1.0f,0.0f,1.0f);
	DDA_algorithm(fertility_america[i]*100,life_expectancy_america[i]*10,fertility_america[i+1]*100,life_expectancy_america[i+1]*10);
	glColor3f(0.0f,1.0f,1.0f);
	DDA_algorithm(fertility_vietnam[i]*100,life_expectancy_vietnam[i]*10,fertility_vietnam[i+1]*100,life_expectancy_vietnam[i+1]*10);
	}
}



void plot_points()
{
	int i,j,x=50,y=50,l=150;
	glColor3f(0.9f,0.9f,0.9f);
	for(i=50;i<=850;i++)
	{
		for(j=50;j<=850;j++)
		{
			glVertex2f(j,i);
		}
	}
	glColor3f(0.0f,0.0f,0.0f);
	while(l<=850)
	{
		for(j=50;j<=850;j++)
		{
			glVertex2f(x,j);
			glVertex2f(j,y);
			glVertex2f(j,l);
			glVertex2f(l,j);
		}
		l=l+100;
	}
}

//void extend_screenlength(int p,int q)
//{
//	glOrtho(0,p,0,q,0,1);
	//glutInitWindowSize(700,700);
//}

void year_count(int yr)
{
	int rem[4];
	int i=0;
	while(yr!=0)
	{
		rem[i]=yr%10;
		yr=yr/10;
		i++;
	}
	for(i=0;i<4;i++)
	{
		glColor3f(1.0f,0.08f,0.2f);
		//printf("%d\n",rem[i]);
		glPointSize(5.0f);
		if(rem[i]==1)
			   {
			          DDA_algorithm(650-(i*100)-50,310-50,650-(i*100)-50,390-50);
			          DDA_algorithm(630-(i*100)-50,370-50,650-(i*100)-50,390-50);
			          DDA_algorithm(630-(i*100)-50,310-50,670-(i*100)-50,310-50);
			    }    
		if(rem[i]==2)
			{
				  DDA_algorithm(610-(i*100)-50,390-50,690-(i*100)-50,390-50);
			          DDA_algorithm(690-(i*100)-50,390-50,690-(i*100)-50,350-50);
			          DDA_algorithm(690-(i*100)-50,350-50,610-(i*100)-50,350-50);
			          DDA_algorithm(610-(i*100)-50,350-50,610-(i*100)-50,310-50);
			          DDA_algorithm(610-(i*100)-50,310-50,690-(i*100)-50,310-50);
			 }
			if(rem[i]==3)
			{
				DDA_algorithm(610-(i*100)-50,390-50,690-(i*100)-50,390-50);
				DDA_algorithm(690-(i*100)-50,390-50,690-(i*100)-50,310-50);
				DDA_algorithm(690-(i*100)-50,310-50,610-(i*100)-50,310-50);
				DDA_algorithm(610-(i*100)-50,350-50,690-(i*100)-50,350-50);
			}
			if(rem[i]==4)		
			{
				DDA_algorithm(610-(i*100)-50,390-50,610-(i*100)-50,350-50);
				DDA_algorithm(610-(i*100)-50,350-50,690-(i*100)-50,350-50);
				DDA_algorithm(650-(i*100)-50,370-50,650-(i*100)-50,310-50);
			}
			if(rem[i]==5)
			{
				DDA_algorithm(690-(i*100)-50,390-50,610-(i*100)-50,390-50);
				DDA_algorithm(610-(i*100)-50,390-50,610-(i*100)-50,350-50);
				DDA_algorithm(610-(i*100)-50,350-50,690-(i*100)-50,350-50);
				DDA_algorithm(690-(i*100)-50,350-50,690-(i*100)-50,310-50);
				DDA_algorithm(690-(i*100)-50,310-50,610-(i*100)-50,310-50);
			}
			if(rem[i]==6)
			{
				DDA_algorithm(610-(i*100)-50,390-50,690-(i*100)-50,390-50);
				DDA_algorithm(610-(i*100)-50,390-50,610-(i*100)-50,310-50);	
				DDA_algorithm(610-(i*100)-50,310-50,690-(i*100)-50,310-50);
				DDA_algorithm(690-(i*100)-50,310-50,690-(i*100)-50,350-50);
				DDA_algorithm(690-(i*100)-50,350-50,610-(i*100)-50,350-50);
			}
			if(rem[i]==7)
			{
				DDA_algorithm(610-(i*100)-50,390-50,690-(i*100)-50,390-50);
				DDA_algorithm(640-(i*100)-50,350-50,690-(i*100)-50,350-50);
				DDA_algorithm(690-(i*100)-50,390-50,640-(i*100)-50,310-50);
			}
			if(rem[i]==8)
			{
				DDA_algorithm(610-(i*100)-50,310-50,690-(i*100)-50,310-50);
				DDA_algorithm(690-(i*100)-50,310-50,690-(i*100)-50,390-50);
				DDA_algorithm(690-(i*100)-50,390-50,610-(i*100)-50,390-50);
				DDA_algorithm(610-(i*100)-50,390-50,610-(i*100)-50,310-50);
				DDA_algorithm(610-(i*100)-50,350-50,690-(i*100)-50,350-50);
			}
			if(rem[i]==9)
			{
				DDA_algorithm(610-(i*100)-50,350-50,610-(i*100)-50,390-50);
				DDA_algorithm(610-(i*100)-50,390-50,690-(i*100)-50,390-50);
				DDA_algorithm(690-(i*100)-50,390-50,690-(i*100)-50,310-50);
				DDA_algorithm(610-(i*100)-50,350-50,690-(i*100)-50,350-50);
				DDA_algorithm(610-(i*100)-50,310-50,690-(i*100)-50,310-50);
			}
			if(rem[i]==0)
			{
				DDA_algorithm(610-(i*100)-50,310-50,690-(i*100)-50,310-50);
				DDA_algorithm(690-(i*100)-50,310-50,690-(i*100)-50,390-50);
				DDA_algorithm(690-(i*100)-50,390-50,610-(i*100)-50,390-50);
				DDA_algorithm(610-(i*100)-50,390-50,610-(i*100)-50,310-50);
			}	
	}
	/*glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(fertility_china*100,life_expectancy_china*10);
	circle(fertility_china*100,life_expectancy_china*10,60);
	fill(fertility_china*100,life_expectancy_china*10,60);	*/
}
void plot_points_china(float fertility_china,float life_expectancy_china,float population_china)
{
	glColor3f(1.0f,0.0f,0.0f);
	glVertex2f(fertility_china*100,life_expectancy_china*10);
	circle(fertility_china*100,life_expectancy_china*10,population_china/20000000);
	fill(fertility_china*100,life_expectancy_china*10,population_china/20000000);	
}
void plot_points_ethiopia(float fertility_ethiopia,float life_expectancy_ethiopia,float population_ethiopia)
{
	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(fertility_ethiopia*100,life_expectancy_ethiopia*10);
	circle(fertility_ethiopia*100,life_expectancy_ethiopia*10,population_ethiopia*3/10000000);
	fill(fertility_ethiopia*100,life_expectancy_ethiopia*10,population_ethiopia*3/10000000);
//	DDA_algorithm(fertility_ethiopia[i]*50,life_expectancy_ethiopia[i]*5,fertility_ethiopia[i+1]*50,life_expectancy_ethiopia[i+1]*5);
}
	
void plot_points_india(float fertility_india,float life_expectancy_india,float population_india)
{
	glColor3f(0.0f,0.0f,1.0f);
	glVertex2f(fertility_india*100,life_expectancy_india*10);
	circle(fertility_india*100,life_expectancy_india*10,population_india/20000000);
	fill(fertility_india*100,life_expectancy_india*10,population_india/20000000);
//	     DDA_algorithm(fertility_india[i]*50,life_expectancy_india[i]*5,fertility_india[i+1]*50,life_expectancy_india[i+1]*5);
}
void plot_points_uganda(float fertility_uganda,float life_expectancy_uganda,float population_uganda)
{
	glColor3f(1.0f,1.0f,0.0f);
	glVertex2f(fertility_uganda*100,life_expectancy_uganda*10);
	circle(fertility_uganda*100,life_expectancy_uganda*10,population_uganda*7/10000000);
	fill(fertility_uganda*100,life_expectancy_uganda*10,population_uganda*7/10000000);
	     //DDA_algorithm(fertility_uganda[i]*50,life_expectancy_uganda[i]*5,fertility_uganda[i+1]*50,life_expectancy_uganda[i+1]*5);
}
void plot_points_america(float fertility_america,float life_expectancy_america,float population_america)
{
	glColor3f(1.0f,0.0f,1.0f);
	glVertex2f(fertility_america*100,life_expectancy_america*10);
	circle(fertility_america*100,life_expectancy_america*10,population_america*1.2/10000000);
	fill(fertility_america*100,life_expectancy_america*10,population_america*1.2/10000000);
	    // DDA_algorithm(fertility_america[i]*50,life_expectancy_america[i]*5,fertility_america[i+1]*50,life_expectancy_america[i+1]*5);
}
void plot_points_vietnam(float fertility_vietnam,float life_expectancy_vietnam,float population_vietnam)
{
	glColor3f(0.0f,1.0f,1.0f);
	glVertex2f(fertility_vietnam*100,life_expectancy_vietnam*10);
	circle(fertility_vietnam*100,life_expectancy_vietnam*10,population_vietnam*3/10000000);
	fill(fertility_vietnam*100,life_expectancy_vietnam*10,population_vietnam*3/10000000);
	     //DDA_algorithm(fertility_vietnam[i]*50,life_expectancy_vietnam[i]*5,fertility_vietnam[i+1]*50,life_expectancy_vietnam[i+1]*5);
}

void font()
{
	glColor3f(1.0f,0.08f,0.2f);
	//to print fertility rate at x axis
	DDA_algorithm(100,10,100,35);//F
	DDA_algorithm(100,35,125,35);
	DDA_algorithm(100,23,125,23);
	
	DDA_algorithm(135,35,135,10);//E
	DDA_algorithm(135,35,160,35);
	DDA_algorithm(135,23,160,23);
	DDA_algorithm(135,10,160,10);
	
	DDA_algorithm(170,35,170,10);//R
	DDA_algorithm(170,35,195,35);
	DDA_algorithm(195,35,195,23);
	DDA_algorithm(195,23,170,23);
	DDA_algorithm(170,23,195,10);
	
	DDA_algorithm(205,35,230,35);//T
	DDA_algorithm(218,35,218,10);
	
	DDA_algorithm(240,35,265,35);//I
	DDA_algorithm(253,35,253,10);
	DDA_algorithm(240,10,265,10);

	DDA_algorithm(275,35,275,10);//L
	DDA_algorithm(275,10,300,10);
	
	DDA_algorithm(310,35,335,35);//I
	DDA_algorithm(323,35,323,10);
	DDA_algorithm(310,10,335,10);
	
	DDA_algorithm(345,35,370,35);//T
	DDA_algorithm(358,35,358,10);
	
	DDA_algorithm(380,35,393,23);//Y
	DDA_algorithm(393,23,405,35);
	DDA_algorithm(393,23,380,10);
	
	DDA_algorithm(440,35,440,10);//R
	DDA_algorithm(440,35,465,35);
	DDA_algorithm(465,35,465,23);
	DDA_algorithm(465,23,440,23);
	DDA_algorithm(440,23,465,10);
	
	DDA_algorithm(488,35,475,10);
	DDA_algorithm(488,35,500,10);
	DDA_algorithm(482,18,493,18);
	
	DDA_algorithm(510,35,535,35);//T
	DDA_algorithm(523,35,523,10);
	
	DDA_algorithm(545,35,545,10);//E
	DDA_algorithm(545,35,570,35);
	DDA_algorithm(545,23,570,23);
	DDA_algorithm(545,10,570,10);
	
	DDA_algorithm(580,23,830,23);
	DDA_algorithm(830,28,830,18);
	DDA_algorithm(830,28,840,23);
	DDA_algorithm(830,18,840,23);
	
	
	//to print life expectancyfloat population_china[50];
float population_ethiopia[50];
float population_india[50];
float population_uganda[50];
float population_america[50];
float population_vietnam[50];
	
	
}
	

void circle2(int xc,int yc,int x,int y)
{
	glVertex2f (xc+x,yc+y);
	glVertex2f (xc-x,yc+y);
	glVertex2f (xc+x,yc-y);
	glVertex2f (xc-x,yc-y);
	glVertex2f (xc+y,yc+x);
	glVertex2f (xc-y,yc+x);
	glVertex2f (xc+y,yc-x);
	glVertex2f (xc-y,yc-x);

}

void circle (int xc,int yc,int r)
{
	int p,x,y;

	x=0;
	y=r;
	p=3-2*r;
	while(x<y)
	{
		circle2(xc,yc,x,y);
		if(p<0)
			p=p+4*x+6;
		else
		{
		p=p+4*(x-y)+10;
		y=y-1;
		}
		x=x+1;
	}
	if (x==y)
		circle2(xc,yc,x,y);
		
	
}
void Init()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,900,0,900,0,01);
}

void keyboard(unsigned char key,int x,int y)
{
	float s=1;
	switch(key)
	{
	case '+':
		
	//	glColor3f(1.0f,1.0f,1.0f);
		scale=scale+0.02;
		x_rubber=x_rubber+1;
		y_rubber=y_rubber+1;
		//extend_screenlength(x_rubber,x_rubber);
		//printf("%d\n",x_rubber);	
		break;
	}
}
	/*case '-':=0.1f;break;
	case 'a':getAxis(1);
		 angle-=2.0f;
		 break;	
	case 'd':getAxis(1);
		 angle+=2.0f;
		 break;
	case 'w':getAxis(2);
		 angle-=2.0f;
		 break;	
	case 's':getAxis(2);
		 angle+=2.0f;
		 break;	
	case ' ':glutFullScreen();
		 break;
	case 'm':glutReshapeWindow(500,500);
		 break;	
	case 27:exit(0);break;
	default:break;
	}
glutPostRedisplay();
}*/

void Display ()
{
	int l,k,j;
	glClear(GL_COLOR_BUFFER_BIT);
	for(l=0;l<49;l++)
	{
		glPointSize(2.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_POINTS);
		plot_points();
		year_count(year[l]);
		plot_points_china(fertility_china[l],life_expectancy_china[l],population_china[l]);
		plot_points_ethiopia(fertility_ethiopia[l],life_expectancy_ethiopia[l],population_ethiopia[l]);
		plot_points_india(fertility_india[l],life_expectancy_india[l],population_india[l]);
		plot_points_uganda(fertility_uganda[l],life_expectancy_uganda[l],population_uganda[l]);
		plot_points_america(fertility_america[l],life_expectancy_america[l],population_america[l]);
		plot_points_vietnam(fertility_vietnam[l],life_expectancy_vietnam[l],population_vietnam[l]);
		//plot_line();
		font();
	//	glutDisplayFunc(Display);
		for(k=0;k<1000000;k++)
		{
			for(j=0;j<50;j++);
		}
		glEnd();
		glFlush();
		glutSwapBuffers();
	}
	
}


int main(int argc, char** argv)
{
	//year_count(2153);
	int i,j;
	for(i=0;i<50;i++)
	scanf("%d",&year[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&life_expectancy_china[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&life_expectancy_ethiopia[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&life_expectancy_india[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&life_expectancy_uganda[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&life_expectancy_america[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&life_expectancy_vietnam[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&fertility_china[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&fertility_ethiopia[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&fertility_india[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&fertility_uganda[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&fertility_america[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&fertility_vietnam[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&population_china[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&population_ethiopia[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&population_india[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&population_uganda[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&population_america[i]);
	for(i=0;i<50;i++)
	scanf("%f \n",&population_vietnam[i]);
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(500,500);
	glutCreateWindow("chandrakanth");
	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutKeyboardFunc(keyboard);
	Init();
	glutMainLoop();
}

