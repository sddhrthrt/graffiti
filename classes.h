/** \file classes.h
 * Has definitions of all the classes that are used in the code.
 * The classes currently implemented are: Color, Point, Line, Quadrangle. 
 * \author Akhil, Anantha, Chandrakanth, Shrimai, Siddhartha
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
		Color(){rgb[0]=0.0f; rgb[1]=0.0f; rgb[2]=0.0f;};
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
			Color color (0.0f, 0.0f, 0.0f);
		};
		/// Constructor with only 2 coordinates and no color, z and color default to 0 and white respectively
		Point(float x, float y){
			coords[0]=x;
			coords[1]=y;
			coords[2]=0.0f;
			Color color(0.0f, 0.0f, 0.0f);
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
		/// multiply the point's x, y coordinates by a particular scale. Helpful in Graph, i think. Takes two arguments, x_scale, y_scale. Remember, multiplies.
		void scale(float x_factor, float y_factor){
			coords[0]*=x_factor;
			coords[1]*=y_factor;
		}
		/// multiply the point's x, y, z coordinates by a particular scale. Helpful in Graph, i think. Takes three arguments, x_scale, y_scale, z_scale.
		void scale(float x_factor, float y_factor, float z_factor){
			coords[0]*=x_factor;
			coords[1]*=y_factor;
			coords[2]*=z_factor;
		}
};///<Store the x, y, z float coordinates and the Color object of a Point.
/** Operations : A class that has static functions.
 * meaning, you can call these functions as Operations::function() without bothering to
 * create an object of that particular class.
 */
class Operations{
	public:
	/// The generic bresenham. Works for any slope, any angle, anything!
	static void bresenham(Point a, Point b, int thickness){
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

		glPointSize(10.0f);
		float p=tdy-dx;
		for(int i=0;i<(dx/INCR);i++){
			glVertex2f(x, y);
/*			for(int th=1; th<thickness; th++){
				glVertex2f(x+th*INCR, y);
				glVertex2f(x-th*INCR, y);
				glVertex2f(x, y+th*INCR);
				glVertex2f(x, y-th*INCR);
			}
*/
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
		int thickness;
		/// Constructor - Takes two Point objects from and to.
		Line(Point from, Point to){
			a=from;
			b=to;
			Color color (0.0f, 0.0f, 0.0f);
			thickness=1;
		};
		/// Empty Constructor
		Line(){};
		/// Constructor - Takes two point objects from and to, and a Color object.
		Line(Point from, Point to, Color c){
			a=from;
			b=to;
			color=c;
			thickness=1;
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
		void setPoints(Point p1, Point p2){
			a=p1;
			b=p2;
		}
		/// Draws the line itself using Operations::bresenham.
		void draw(){
			color.set();
			Operations::bresenham(a, b, thickness);
		}
		/// sets the thickness of the line
		void setThickness(int th){
			thickness=th;
		}
		/// increases thickness
		void incThickness(int th){
			thickness+=1;
		}
		/// decreases thickness
		void decThickness(int th){
			if(thickness>0){
				thickness--;
			}
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
			Color c (0.0f, 0.0f, 0.0f);
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
class Graph{
	public:
		/// Number of divisions on each axes
		int x_div, y_div, x_avail, y_avail;
		/// Labels for each axis
		int* x_labels, y_labels;
		int year;
		int join;
		/// Constructor that takes data, x divisions, y divisions.
		Graph (int row, int xx, int x, int yy, int y){
			year=row;
			x_div=x;
			x_avail=xx;
			y_avail=yy;
			y_div=y;
			join=(int)(x_avail/x_div);
		} 
		/// Test drawing function.
		void plot(){
			Point origin (0.5f, 0.5f);
			Point x_end (X-0.5f, 0.5f);
			Point y_end (0.5f, Y-0.5f);
			Line x_axis (origin, x_end);
			Line y_axis (origin, y_end);
			x_axis.setThickness(10);
			x_axis.draw();
			y_axis.draw();
			float total;
			for(int i=0;i<x_div;i++){
				total=0;
				for(int j=1;j<=join;j++){
					if((join*i+j)<x_avail)
						total+=mean[join*i+j];
				}
				
				total=(float)total/(float)join;
				std::cout <<total<<"\n";
				glVertex2f( ((X-0.5f)/x_div)*(i+1)+0.5f, total+0.5f);
			}
			
		}

};

