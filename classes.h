
class Color{
	public:
		float rgb[3];
		Color(float r, float g, float b){
			rgb[0]=r;
			rgb[1]=g;
			rgb[2]=b;
		};
		Color(){rgb[0]=1.0f; rgb[1]=1.0f; rgb[2]=1.0f;};
		float get(char color){
			switch(color){
				case 'r':
					return rgb[0];
					break;
				case 'g':
					return rgb[1];
					break;
				case 'b':
					return rgb[2];
					break;
			}
		}
		void set(){
			glColor3f(rgb[0],rgb[1],rgb[2]);
		}
};

class Point{
	
	public:
		float coords[3];
		Color color;
		float* getCoords(){
			return coords;
		}
		void setCoords(float x, float y, float z){
			coords[0]=x;
			coords[1]=y;
			coords[2]=z;
		}
		Point() {};
		Point(float x, float y, float z){
			coords[0]=x;
			coords[1]=y;
			coords[2]=z;
			Color color (1.0f, 1.0f, 1.0f);
		};
		Point(float x, float y){
			coords[0]=x;
			coords[1]=y;
			coords[2]=0.0f;
			Color color(1.0f, 1.0f, 1.0f);
		};
		Point(float x, float y, float z, Color c){
			color=c;
			coords[0]=x;
			coords[1]=y;
			coords[2]=z;
		};
		Point(float x, float y, Color c):color(c){
			coords[0]=x;
			coords[1]=y;
			coords[2]=0;
		};
		void draw(){
			color.set();
			glVertex3f(coords[0], coords[1], coords[2]);
		}
};
class Operations{
	public:
	static void bresenham(Point a, Point b){
		float x0=a.getCoords()[0];
		float y0=a.getCoords()[1];
		float x1=b.getCoords()[0];
		float y1=b.getCoords()[1];
		float INCR=0.0001;
		float INCRX=0.0001;
		float INCRY=0.0001;
		float dx=x1-x0;
		float dy=y1-y0;
		float x=x0;
		float y=y0;

		if(dx<0){
			INCRX=0-INCRX;
			dx=0-dx;
		}
		if(dy<0){
			INCRY=0-INCRY;
			dy=0-dy;
		}
		if(dx==0){
			for(int i=0;i<dy/INCR;i++){
				glVertex2f(x0, y0);
				y0+=INCRY;
			}
			return;
		}
		float tdy=2*dy;
		float tdyminustdx=tdy-2*dx;

		float p=tdy-dx;
		for(int i=0;i<(dx/INCR);i++){
			glVertex2f(x, y);
			if(p<0){
				x+=INCRX;
				p=p+tdy;
			}
			else{
				x+=INCRX;
				y+=INCRY;
				p=p+tdyminustdx;
			}
		}
	}
};
class Line{
	public:
		Point a;
		Point b;
		Color color;
		Line(Point from, Point to){
			a=from;
			b=to;
			Color color (1.0f, 1.0f, 1.0f);
		};
		Line(){};
		Line(Point from, Point to, Color c){
			a=from;
			b=to;
			color=c;
		};
		Point getPoint(int index){
			if(index){
				return b;
			}
			else{
				return a;
			}
		}
		void draw(){
			color.set();
			Operations::bresenham(a, b);
		}
};
class Quadrangle{
	public:
		Point a;
		Point b;
		Point c;
		Point d;
		Color linecolor;
		Color fillcolor;
		int state;//filled=1, empty=0
		Quadrangle(Point one, Point two, Point three, Point four, int s){
			a=one;
			b=two;
			c=three;
			d=four;
			state=s;
			Color fillcolor (1.0f, 1.0f, 1.0f);
			Color linecolor(1.0f, 1.0f, 1.0f);
		};
		Quadrangle(Point one, Point two, int s, Color l, Color f){
			a=one;
			Point b (one.getCoords()[0], two.getCoords()[1]);
			Point c (two.getCoords()[0], one.getCoords()[1]);
			d=two;
			state=s;
			fillcolor=f;
			linecolor=l;
		};
		Quadrangle(Point one, Point two){
			a=one;
			Point b(one.getCoords()[0], two.getCoords()[1]);
			Point c(two.getCoords()[0], one.getCoords()[1]);
			d=two;
			state=0;
			Color fillcolor(1.0f, 1.0f, 1.0f);
			Color linecolor(1.0f , 1.0f , 1.0f);
		};
		Quadrangle(Point one, Point two, Point three, Point four, int s, Color l, Color f){
			a=one;
			b=two;
			c=three;
			d=four;
			state=s;
			linecolor=l;
			fillcolor=f;
		};
		Quadrangle(Point one, Point two, Point three, Point four){
			a=one;
			b=two;
			c=three;
			d=four;
			state=0;
			Color fillcolor(1.0f, 1.0f, 1.0f);
			Color linecolor(1.0f, 1.0f, 1.0f);
		};
		Point getPoint(int index){
			switch(index){
				case 0:
					return a;
					break;
				case 1:
					return b;
					break;
				case 2:
					return c;
					break;
				case 3:
					return d;
					break;
				default:
					return a;
					break;
			}
		}
		void draw(){
			linecolor.set();
			Operations::bresenham(a, b);
			Operations::bresenham(b, c);
			Operations::bresenham(c, d);
			Operations::bresenham(d, a);
		}
		void fill(){
			if(state){
			fillcolor.set();
		//	fillPolygon(a, b, c, d);
			}
		}
};


