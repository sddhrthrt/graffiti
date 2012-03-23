/** \file classes.h
 * Has definitions of all the classes that are used in the code.
 * The classes currently implemented are: Color, Point, Line, Quadrangle. 
 * \author Akhil, Anantha, Shrimai, Siddhartha
 * \date Mar22, 2012
 */
/// Color
/// A class that has an array of size three, holding the r, g, b details of the Color object. 
/// 
class Color{
	public:
		float rgb[3];
		/// \fn Constructor for Color - only one with three arguments. Floats, <=1.0
		Color(float r, float g, float b){
			rgb[0]=r;
			rgb[1]=g;
			rgb[2]=b;
		};
		/// Constructor - initializes color to white
		Color(){rgb[0]=1.0f; rgb[1]=1.0f; rgb[2]=1.0f;};
		/// A function that returns the color value of the object, by channel. Arguments are 'r', 'g', 'b'.
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
		/// Calls glColor3f(rgb[0],rgb[1],rgb[2]);
		void set(){ 
			glColor3f(rgb[0],rgb[1],rgb[2]);
		}
};///< Stores color in float[3] 
/*! \class Point
 * Stores the 3 dimensional coordinates and the color of the particular point.
 */
class Point{
	
	public:
		float coords[3];
		Color color;
		/// returns the 3 element float array which contains x, y, z coordinate of the Point
		float* getCoords(){
			return coords;
		}
		/// call it with three arguments to set the coordinates of a point.
		void setCoords(float x, float y, float z){
			coords[0]=x;
			coords[1]=y;
			coords[2]=z;
		}
		Point() {coords[0]=0.0f, coords[1]=0.0f,coords[2]=0.0f;};
		/// Constructor with only coordinates, Color defaults to white
		Point(float x, float y, float z){
			coords[0]=x;
			coords[1]=y;
			coords[2]=z;
			Color color (1.0f, 1.0f, 1.0f);
		};
		/// Constructor with only 2 coordinates and no color, z and color default to 0 and white respectively
		Point(float x, float y){
			coords[0]=x;
			coords[1]=y;
			coords[2]=0.0f;
			Color color(1.0f, 1.0f, 1.0f);
		};
		/// Constructor with 3 Coordinates and Color.
		Point(float x, float y, float z, Color c){
			color=c;
			coords[0]=x;
			coords[1]=y;
			coords[2]=z;
		};
		/// Construcotor with 2 coordinates and a color. z defaults to 0 again.
		Point(float x, float y, Color c){
			coords[0]=x;
			coords[1]=y;
			coords[2]=0;
			color=c;
		};
		/// Draws the Point using glVertex3f. No glBegin(GL_POINTS) or glEnd() here.
		void draw(){
			color.set();
			glVertex3f(coords[0], coords[1], coords[2]);
		}
};///<Store the x, y, z float coordinates and the Color object of a Point.
/** Operations : A class that has static functions.
 * meaning, you can call these functions as Operations::function() without bothering to
 * create an object of that particular class.
 */
class Operations{
	public:
	/// The generic bresenham. Works for any slope, any angle, anything!
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
	/// This function draws a circle at the given Point, and with radius.
	static void midpointcircle(Point point, float radius){
		float xx,yy;
		xx=point.getCoords()[0];
		yy=point.getCoords()[1];
		float p;
		float x,y;
		y=radius;
		p=(5/4)-radius;
		for(x=0.0;x<=y;) {
			glVertex2f(xx+x, yy+y);
			glVertex2f(xx-x, yy+y);
			glVertex2f(xx+x, yy-y);
			glVertex2f(xx-x, yy-y);
			glVertex2f(xx+y, yy+x);
			glVertex2f(xx+y, yy-x);
			glVertex2f(xx-y, yy+x);
			glVertex2f(xx-y, yy-x);
			if(p<0)
			{
				x=x+0.0001;
				p=p+2*x+0.0001;
			}
			else
			{
				x=x+0.0001;
				y=y-0.0001;
				p=p+2*x-2*y+0.0001;
			}
	
		}
	}

};///< Class that holds static functions that implement the basic drawing algorithms.
/** Line class:
 * Implements all the functionalities required for a line. Various types
 * of constructors, own color, etc
 */
class Line{
	public:
		Point a;
		Point b;
		Color color;
		/// Constructor - Takes two Point objects from and to.
		Line(Point from, Point to){
			a=from;
			b=to;
			Color color (1.0f, 1.0f, 1.0f);
		};
		/// Empty Constructor
		Line(){};
		/// Constructor - Takes two point objects from and to, and a Color object.
		Line(Point from, Point to, Color c){
			a=from;
			b=to;
			color=c;
		};
		/// Returns a Point - one of the from and two. Pass an int - 0 for 'from' and nonzero for 'to'.
		Point getPoint(int index){
			if(index){
				return b;
			}
			else{
				return a;
			}
		}
		/// Draws the line itself using Operations::bresenham.
		void draw(){
			color.set();
			Operations::bresenham(a, b);
		}
};///<  Class that stores the fromand to Point objects of a line and its Color.
/** Class that stores the attributes required for a circle.
 * This has a Point, a radius and a color.
 * has a draw() function that calls the midpointcircle() function and draw itself.
 */
class Circle{
	public:
		Point centre;
		Color c;
		int state;
		float radius;
		/// Constructor that takes only a Point and a radius
		Circle(Point p, float r){
			Color c (1.0f, 1.0f, 1.0f);
			radius=r;
			centre=p;
		};
		/// Constructor that takes a Point, a radius, a Color.
		Circle(Point p, float r, Color color){
			c=color;
			radius=r;
			centre=p;
		};
		/// returns Point.
		Point getCentre(){
			return centre;
		};
		/// calls midpointcircle() function to draw itself.
		void draw(){
			c.set();
			Operations::midpointcircle(centre, radius);
		}
};
/** Implemented Quadrangle. a four-sided quadrangle, arbit vertices can be given.
 * Only two vertices can also be given, in which case they will be the bottom left and the 
 * top right vertices.
 * a state variable decides whether the quadrangle is filled or not. (0 or nonzero).
 * Two colors - one is line color and the other is fill color.
 */
class Quadrangle{
	public:
		Point a;
		Point b;
		Point c;
		Point d;
		Color linecolor;
		Color fillcolor;
		///filled=1, empty=0
		int state;
		/// Constructor that takes 4 vertices and a state.
		Quadrangle(Point one, Point two, Point three, Point four, int s){
			a=one;
			b=two;
			c=three;
			d=four;
			state=s;
			Color fillcolor (1.0f, 1.0f, 1.0f);
			Color linecolor(1.0f, 1.0f, 1.0f);
		};
		/// Constructor that takes two vertices - bottom left and top right and a state - 0 unfilled and 1 filled, and a linecolor and a fillcolor Color objects.
		Quadrangle(Point one, Point two, int s, Color l, Color f){
			a=one;
			Point b (one.getCoords()[0], two.getCoords()[1]);
			Point c (two.getCoords()[0], one.getCoords()[1]);
			d=two;
			state=s;
			fillcolor=f;
			linecolor=l;
		};
		/// Constructor that simply takes two points , bottom left and top right
		Quadrangle(Point one, Point two){
			a=one;
			Point b(one.getCoords()[0], two.getCoords()[1]);
			Point c(two.getCoords()[0], one.getCoords()[1]);
			d=two;
			state=0;
			Color fillcolor(1.0f, 1.0f, 1.0f);
			Color linecolor(1.0f , 1.0f , 1.0f);
		};
		/// Constructor which takes everything, 4 Point Objects, state (0 unfilled, 1 filled), 2 Color objects for line and fill colors
		Quadrangle(Point one, Point two, Point three, Point four, int s, Color l, Color f){
			a=one;
			b=two;
			c=three;
			d=four;
			state=s;
			linecolor=l;
			fillcolor=f;
		};
		/// Constructor that takes just 4 points and initializes both colors to white and state to unfilled (0)
		Quadrangle(Point one, Point two, Point three, Point four){
			a=one;
			b=two;
			c=three;
			d=four;
			state=0;
			Color fillcolor(1.0f, 1.0f, 1.0f);
			Color linecolor(1.0f, 1.0f, 1.0f);
		};
		/// Get back one of the points - pass 0-3 as arguments
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
		/// draws itself using Operations::bresenham() for every pair of vertices
		void draw(){
			linecolor.set();
			Operations::bresenham(a, b);
			Operations::bresenham(b, c);
			Operations::bresenham(c, d);
			Operations::bresenham(d, a);
		}
		/// Fill algoritm not implemented fully - so will take time for this to come to working condition
		void fill(){
			if(state){
			fillcolor.set();
		//	fillPolygon(a, b, c, d);
			}
		}
};///< Implemented a quadrangle using 4 or 2 Point objects, a state variable that decides filling or not, a fillcolor and a linecolor Color objects


