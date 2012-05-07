/** \file classes.h
 * Has definitions of all the classes that are used in the code.
 * The classes currently implemented are: Color, Point, Line, Quadrangle. 
 * \author Akhil, Anantha, Chandrakanth, Shrimai, Siddhartha
 * \date Mar22, 2012
 */
/// Color
/// A class that has an array of size three, holding the r, g, b details of the Color object. 
/// 
<<<<<<< HEAD
ofstream segfile;

struct area {
	int x0, x1, y0, y1;
	element label;
};
typedef struct area Area;
vector<Area> areas;

=======
vector<void* > rows(2000);
vector< vector<void*> > segfile(2000, rows);
>>>>>>> 09950c976b5a614a45a67cda2544cee9295383b3
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
		/// Sets r, g, b as the colors of the current Color object
		void setColor(float r, float g, float b){
			rgb[0]=r;
			rgb[1]=g;
			rgb[2]=b;
		}
};///< Stores color in float[3] 
/// A universal color pallete. Any other place, you can use it by just calling pallete[x], where 1<x<5. The colors are set in Operations::setPallete(), And this function has to be customised to take a 2 dimensional array of float values and set them as the current pallete. Expecting color scheming work from Shrimai
Color pallete[6];
Color uicolors[6];

/**! \class Point
 * Stores the 3 dimensional coordinates and the color of the particular point.
 */
class Point {
	
	public:	
		/// stores the x, y, z Coordinates of the points
		float coords[3];
		/// The Thickness of the point.	
		float thickness;
		/// stores the color of the point, rarely required, will probably remove in future.
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
		void setThickness(float x){
			thickness=x;
		}
		/// call it with two arguments to set the coordinates of a point. Added due to demand	
		void setCoords(float x, float y){
			coords[0]=x;
			coords[1]=y;
			coords[2]=0.0f;
		}
		/// General constructors and destructors, empty
		Point() {coords[0]=0.0f, coords[1]=0.0f,coords[2]=0.0f;};
		~Point() {};
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
			segfile<<1<<" "<<coords[0]<<" "<<coords[1]<<" "<<coords[2]<<endl;
			color.set();
			glPointSize(thickness);
			glBegin(GL_POINTS);
			glVertex3f(coords[0], coords[1], coords[2]);
			glEnd();
			glPointSize(1.0f);
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
class Operations {
<<<<<<< HEAD


=======
>>>>>>> 09950c976b5a614a45a67cda2544cee9295383b3
	public:
	/// takes no arguments as of now, sets the pallete[] to various colors. In future, should be configured to take  array of colors and set the values of the array as the colors for palletes. 
	static void setPallete(int index){
		static float palletes[][18]={{0.7f, 0.7f, 0.7f,
					 0.5f, 0.4f, 0.4f,
					 0.0f, 0.77f, 1.0f,
					 0.3f, 0.5f, 0.2f,
					 0.02f, 0.01f, 0.02f,
					 0.01f, 0.05f, 0.14f},
					 {0.568f, 0.015f, 0.345f,
					 0.0f, 0.329f, 0.65f,
					 0, 0.65f, 0.317f,
					 1.0f, 0.949f, 0.0f,
					 0.0f, 0.0f, 0.0f,
					 1.0f, 1.0f, 1.0f},
					 {.376f, .223f, .074,
					 1.0f, 1.0f, 0.0f,
					 0.0f, .749f, .952f, 
					 .4f, 0.176f, .568f, 
					 .925f, 0, 0.549f,
					 0.0f, 0.0f, 0.0f},
					 {0.949f, 0.4f, 0.133f,
					 0.242f, 0, 0.549f,
					 0, 0.68f, 0.937f,
					 0, 0.650f, 0.317f,
					 0, 0.356f, 0.498f,
					 0,0,0},
					 {0.294f, 0, 0.286f,
					 1, 0.949f, 0,
					 0.929f, 0.109f, 0.141f,
					 0, 0, 1.0f,
					 0, 0.650f, 0.317f,
					 0, 0, 0} };
		for(int i=0;i<6;i++){
			pallete[i].setColor(palletes[index][i*3], palletes[index][i*3+1], palletes[index][i*3+2]);
		}
	}
	/// Registers an Area struct in the areas vector
	static void registerArea(Area x){
		areas.push_back(x);
	}
	static element fetchArea(int x, int y){
		vector<Area>::iterator it;
		element l;
		for (it=areas.begin(); it!=areas.end(); it++){
//			cout<<it->x0<<", "<<it->y0<<", "<<it->x1<<", "<<it->y1<<"\n";
			if(it->x0<=x && it->y0<=y && it->x1>=x && it->y1>=y){
				l=it->label;
			}
		}
		return l;
	}
	/// takes min and max and gives the color of the current val.
	static Color valueBasedColor( float val, float min, float max){
		
		float mean,r,g,b;
		mean=0.5f;
		val=val-min;
		val=val/(max-min);
		if(val>mean)
		{
			r=val;
			g=1-val;
			b=0.0f;
		}
		else
		{
			r=1-val;
			g=val;
			b=0.0f;
		}
		Color c (r,g,b);
		return c;
	}

			


	/// The generic simple slope line draw. Works for any slope, any angle, anything!. Pass the from, to and the thickness
	static void simple_line(Point a, Point b,float thickness=1.0f ){
	
		float x0=a.getCoords()[0];
		float y0=a.getCoords()[1];
		float x1=b.getCoords()[0];
		float y1=b.getCoords()[1];
		segfile<<1<<" "<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<endl;
		float diffx=(x1-x0)<0?(x0-x1):(x1-x0);
		float diffy=(y1-y0)<0?(y0-y1):(y1-y0);
		int density=(diffx)>(diffy)?(diffx)*1000:(diffy)*1000;
		//cout<<x0<<","<<y0<<" to "<<x1<<","<<y1<<"\n";
		diffx=x1-x0;
		diffy=y1-y0;
		float INCRX=(diffx)/density;
		float INCRY=(diffy)/density;
		
		for(int i=0;i<density;i++){
			glPointSize(thickness);
			glBegin(GL_POINTS);
			glVertex2f(x0, y0);
			glEnd();
			glPointSize(1.0f);
			x0+=INCRX;
			y0+=INCRY;
		}
	}
	
//clip simple line starts

	static void clip_simple_line(Point a, Point b,float xmin,float xmax,float thickness=1.0f ){
		float x0=a.getCoords()[0];
		float y0=a.getCoords()[1];
		float x1=b.getCoords()[0];
		float y1=b.getCoords()[1];
		segfile<<1<<" "<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<endl;
		float diffx=(x1-x0)<0?(x0-x1):(x1-x0);
		float diffy=(y1-y0)<0?(y0-y1):(y1-y0);
		int density=(diffx)>(diffy)?(diffx)*1000:(diffy)*1000;
		//cout<<x0<<","<<y0<<" to "<<x1<<","<<y1<<"\n";
		diffx=x1-x0;
		diffy=y1-y0;
		float INCRX=(diffx)/density;
		float INCRY=(diffy)/density;
		
		for(int i=0;i<density;i++){
			glPointSize(thickness);
			glBegin(GL_POINTS);
			if((x0<xmax)&& (x0>xmin))
			glVertex2f(x0, y0);
			glEnd();
			glPointSize(1.0f);
			x0+=INCRX;
			y0+=INCRY;
		}
	}


//clip simple line ends	
	
	
	/// managed to write a function that takes the density of the line by the user. Density specified as dots per unit, will draw the line with somany dots per unit. 
	static void simple_line_sparse(Point a, Point b, int den=100, float thickness=1.0f ){
		float x0=a.getCoords()[0];
		float y0=a.getCoords()[1];
		float x1=b.getCoords()[0];
		float y1=b.getCoords()[1];
		segfile<<1<<" "<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<endl;
		float diffx=(x1-x0)<0?(x0-x1):(x1-x0);
		float diffy=(y1-y0)<0?(y0-y1):(y1-y0);
		//cout<<x0<<","<<y0<<" to "<<x1<<","<<y1<<"\n";
		int density=(diffx)>(diffy)?(diffx)*den:(diffy)*den;
		diffx=x1-x0;
		diffy=y1-y0;
		float INCRX=(diffx)/density;
		float INCRY=(diffy)/density;
		
		for(int i=0;i<density;i++){
			glPointSize(thickness);
			glBegin(GL_POINTS);
			glVertex2f(x0, y0);
			glEnd();
			glPointSize(1.0f);
			x0+=INCRX;
			y0+=INCRY;
		}
	}///< This can be of use when there is heavy filling work. We can fill it cheaply using about 50 dots per unit. Can also be used for drawing dotted lines ;) as a fluke.
	

	/// The generic bresenham. Works for any slope, any angle, anything!
<<<<<<< HEAD
	static void bresenham(Point a, Point b, float thickness=1.0f ){
=======
	static void bresenham(Point a, Point b ){
>>>>>>> 09950c976b5a614a45a67cda2544cee9295383b3
		float x0=a.getCoords()[0];
		float y0=a.getCoords()[1];
		float x1=b.getCoords()[0];
		float y1=b.getCoords()[1];
<<<<<<< HEAD
		segfile<<1<<" "<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<endl;
=======
>>>>>>> 09950c976b5a614a45a67cda2544cee9295383b3
		//cout<<x0<<","<<y0<<" to "<<x1<<","<<y1<<"\n";

		float INCR=0.00001;
		float INCRX=0.00001;
		float INCRY=0.00001;
		float dx=x1-x0;
		float dy=y1-y0;
		float x=x0;
		float y=y0;

		glPointSize(thickness);
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
				glBegin(GL_POINTS);
				glVertex2f(x0, y0);
				glEnd();
				y0+=INCRY;
			}
			return;
		}
		float tdy=2*dy;
		float tdyminustdx=tdy-2*dx;

		float p=tdy-dx;
		for(int i=0;i<(dx/INCR);i++){
<<<<<<< HEAD
			//cout<<(int)(x*unit)<<","<<(int)(y*unit)<<"\n";
			glBegin(GL_POINTS);
			glVertex2f(x, y);
			glEnd();

			if(p<0.1){
=======
		//	glPointSize(2.5f);
			//cout<<(int)(x*unit)<<","<<(int)(y*unit)<<"\n";
			glVertex2f(x, y);

			if(p<0){
>>>>>>> 09950c976b5a614a45a67cda2544cee9295383b3
				x+=INCRX;
				p=p+tdy;
			}
			else{
				x+=INCRX;
				y+=INCRY;
				p=p+tdyminustdx;
			}
		}
		glPointSize(1.0f);
	}
<<<<<<< HEAD
	
//clip bresenham starts

	static void clipBresenham(Point a, Point b,float xmin, float xmax , float thickness=1.0f){
		float x0=a.getCoords()[0];
		float y0=a.getCoords()[1];
		float x1=b.getCoords()[0];
		float y1=b.getCoords()[1];
		segfile<<1<<" "<<x0<<" "<<y0<<" "<<x1<<" "<<y1<<endl;
		//cout<<x0<<","<<y0<<" to "<<x1<<","<<y1<<"\n";

		float INCR=0.00001;
		float INCRX=0.00001;
		float INCRY=0.00001;
		float dx=x1-x0;
		float dy=y1-y0;
		float x=x0;
		float y=y0;

		glPointSize(thickness);
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
				glBegin(GL_POINTS);
				if((x0<xmax) && (xmin<x0))
				glVertex2f(x0, y0);
				glEnd();
				y0+=INCRY;
=======
	/// This function draws a circle at the given Point, and with radius.
	static void midpointcircle(Point point, float radius){
		float xx,yy;
		xx=point.getCoords()[0];
		yy=point.getCoords()[1];
		//cout<<xx<<","<<yy<<"\n";
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
>>>>>>> 09950c976b5a614a45a67cda2544cee9295383b3
			}
			return;
		}
		float tdy=2*dy;
		float tdyminustdx=tdy-2*dx;

		float p=tdy-dx;
		for(int i=0;i<(dx/INCR);i++){
			//cout<<(int)(x*unit)<<","<<(int)(y*unit)<<"\n";
			glBegin(GL_POINTS);
			if((x0<xmax) && (xmin<x0))
			glVertex2f(x, y);
			glEnd();

			if(p<0.1){
				x+=INCRX;
				p=p+tdy;
			}
			else{
				x+=INCRX;
				y+=INCRY;
				p=p+tdyminustdx;
			}
		}
		glPointSize(1.0f);
	}
		
	


//clip bresenham ends
	/// Just the prototype here - declared later for obvious reasons  - it needs line object and the line objects are declared and defined only later.
	static void midpointcircle(Point, float,Color,  int, Color, float);
	static void semicircle(Point, float, int, Color, float);
/*	/// Not in working condition yet
	static void addToSegfile( label, int x, int y){
		segfile[x][y]=ob;
	}
	/// Not in working Condition yet
	static void* getFromSegfile(int x, int y){
		cout<<x<<", "<<y<<"\n";
		return segfile[x][y];
	}
<<<<<<< HEAD
	*/

=======
	static void addToSegfile(void* ob, int x, int y){
		segfile[x][y]=ob;
	}
	static void* getFromSegfile(int x, int y){
		cout<<x<<", "<<y<<"\n";
		return segfile[x][y];
	}
>>>>>>> 09950c976b5a614a45a67cda2544cee9295383b3

};///< Class that holds static functions that implement the basic drawing algorithms.
/** Line class:
 * Implements all the functionalities required for a line. Various types
 * of constructors, own color, etc
 */
class Line{
	public:
		/// begin point. Can be any point, because the draw function works for +/- slopes.
		Point a;
		/// end point. :P
		Point b;
		/// Color of the line. Need to set this because the drawing function explicitly sets the color. If part of the rectangle or somethnig, have to set this color, otherwise this DEFAULTS TO BLACK.
		Color color;
		/// Thickness. Mother of God, this is not working!
		float thickness;
		/// Constructor - Takes two Point objects from and to.
		float xmin;
		float xmax;
		//new constructor
		Line(Point from,Point to,float xmin1,float xmax1,float t=1.0f){
			xmin=xmin1;
			xmax=xmax1;
			a=from;
			b=to;
			Color color (0.0f, 0.0f, 0.0f);
			thickness=t;
		};
		Line(Point from, Point to, float t=1.0f){
			xmin=0;
			xmax=X;
			a=from;
			b=to;
			Color color (0.0f, 0.0f, 0.0f);
			thickness=t;
		};
		/// Empty Constructor 
		Line(){};
		/// and destructor. Phew!
		~Line() {};
		/// Constructor - Takes two point objects from and to, and a Color object.
		Line(Point from, Point to, Color c, float t =1.0f){
			xmin=0;
			xmax=X;
			a=from;
			b=to;
			color=c;
			thickness=t;
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
		/// changes the start and end to some other point. Useful to avoaoid creating new line objects for no reason.
		void setPoints(Point p1, Point p2){
			a=p1;
			b=p2;
		}
		/// Draws the line itself using Operations::simple_line.
		void draw(){
			color.set();
<<<<<<< HEAD
			Operations::simple_line(a, b, thickness);
		}
		void clipDraw(){
			color.set();
			Operations::clip_simple_line(a,b,xmin,xmax,thickness);
=======
			Operations::bresenham(a, b);
>>>>>>> 09950c976b5a614a45a67cda2544cee9295383b3
		}
		/// sets the thickness of the line - not working
		void setThickness(float th){
			thickness=th;
		}
		/// increases thickness - not working
		void incThickness(float th){
			thickness+=1;
		}
		/// decreases thickness - not working
		void decThickness(float th){
			if(thickness>0){
				thickness--;
			}
		}
};///<  Class that stores the fromand to Point objects of a line and its Color.	
/** FillLine class:
 *	This is a customized Line class - but not inherited - because its too much headache right now 
 *	This takes the density argument when being declared, and this calles the Operations::simple_line_sparse() which takes density as an argument. 
 */
class FillLine{
	public:
		Point a;
		Point b;
		Color color;
		int density;
		/// Constructor - Takes two Point objects from and to.
		FillLine(Point from, Point to, int den=100 ){
			a=from;
			b=to;
			Color color (0.0f, 0.0f, 0.0f);
			density=den;
		};
		/// Empty Constructor
		FillLine(){};
		~FillLine() {};
		/// Constructor - Takes two point objects from and to, and a Color object.
		FillLine(Point from, Point to, Color c, int den){
			a=from;
			b=to;
			color=c;
			density=den;
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
		/// Set the begin and end points as p1 and p2
		void setPoints(Point p1, Point p2){
			a=p1;
			b=p2;
		}
		/// Draws the line itself using Operations::simple_line_sparse which takes density as an argument. Density in dots per unit.
		void draw(){
			color.set();
			Operations::simple_line_sparse(a, b, density);
		}
};///<  Class for filler lines - less intensity.	
/** This is a class that takes the left bottom and top right points of a rectangle and draws a rectangle
  * and even fills it for you. Easy to use and can be useful in various places like bar graph and menu button.
  */
class Rectangle{
	public:
		/// bottom left point
		Point a;
		/// top right point
		Point b;
		/// The border color
		Color line_color;
		/// the fill color
		Color fill_color;
		/// thickness of the border
		float thickness;
		/// filled or not?
		int state;
		/// Constructor - Takes two Point objects from and to. and the thickness of the borderline
		Rectangle(Point from, Point to, float t= 1.0f){
			a=from;
			b=to;
			Color line_color (0.0f, 0.0f, 0.0f);
			state=0;
			thickness=t;
		};
		/// Empty Constructor
		Rectangle(){};
		~Rectangle() {};
		/// Constructor - Takes two point objects from and to, and a Color object.
		Rectangle(Point from, Point to, Color c, float t= 1.0f){
			a=from;
			b=to;
			line_color=c;
			state=0;
			thickness=t;
		};
		/// Most useful constructor - takes from, to, the line ccolor, the fill state (1 - filled, 0 - unfilled), the fill color
		Rectangle(Point from, Point to, Color c, int st, Color c2, float t=1.0f){
			a=from;
			b=to;
			line_color=c;
			state=st;
			fill_color=c2;
			thickness=t;
		}
		/// Returns a Point - one of the from and two. Pass an int - 0 for 'from' and nonzero for 'to'.
		Point getPoint(int index){
			if(index){
				return b;
			}
			else{
				return a;
			}
		}
		/// can be used to change the points of the rectangle. Useful in resizing.
		void setPoints(Point p1, Point p2){
			a=p1;
			b=p2;
		}
		/// toggleFill.
		void toggleFill(){
			if(state) state=0;
			else state=1;
		}
		/// Draws itself using Operations::simple_line and fills itself using Operations::simple_line_sparse.
		void draw(){
			if(state){
				Point beg = a;
				Point end = b;
				FillLine l (a, b, fill_color, 100);
				for(float y=a.getCoords()[1]; y<b.getCoords()[1];y+=0.1){
					beg.setCoords(beg.getCoords()[0], y);
					end.setCoords(end.getCoords()[0], y);
					l.setPoints(beg, end);	
					l.draw();
				}
			}
			line_color.set();
			Point p = b;
			p.setCoords(a.getCoords()[0], b.getCoords()[1]);
			Operations::simple_line(a, p, thickness);
			Operations::simple_line(p, b, thickness);
			p.setCoords(b.getCoords()[0], a.getCoords()[1]);
			Operations::simple_line(p,b, thickness);
			Operations::simple_line(a,p, thickness);
		}
};///<  Class that creates a rectangle and fills it.

/// This function draws a circle at the given Point, and with radius. This takes Line color, state fo the circle and fill color as arguments.
void Operations::  midpointcircle(Point point, float radius, Color lc, int fill, Color fc, float thickness=1.0f){
		float xx,yy;
		
		xx=point.getCoords()[0];
		yy=point.getCoords()[1];
		segfile<<3<<xx<<" "<<yy<<" "<<radius<<endl;
		Point beg (0.0f, 0.0f, 0.0f);
		Point end (0.0f, 0.0f, 0.0f);	
		FillLine l (beg, end, fc,20);
		//cout<<xx<<","<<yy<<"\n";
		float p;
		float x,y;
		y=radius;
		p=(5/4)-radius;
		for(x=0.0;x<=y;) {

			if(fill){
				beg.setCoords(xx-x, yy+y);
				end.setCoords(xx+x, yy+y);
				l.setPoints(beg, end);
				l.draw();
				beg.setCoords(xx-y, yy+x);
				end.setCoords(xx+y, yy+x);
				l.setPoints(beg, end);
				l.draw();
				beg.setCoords(xx-x, yy-y);
				end.setCoords(xx+x, yy-y);
				l.setPoints(beg, end);
				l.draw();
				beg.setCoords(xx-y, yy-x);
				end.setCoords(xx+y, yy-x);
				l.setPoints(beg, end);
				l.draw();
			}
			lc.set();
		//	glPointSize(thickness);
			glBegin(GL_POINTS);
			glVertex2f(xx+x, yy+y);
			glVertex2f(xx-x, yy+y);
			glVertex2f(xx+x, yy-y);
			glVertex2f(xx-x, yy-y);
			glVertex2f(xx+y, yy+x);
			glVertex2f(xx+y, yy-x);
			glVertex2f(xx-y, yy+x);
			glVertex2f(xx-y, yy-x);
			glEnd();
			if(p<0)
			{
				x=x+0.005;
				p=p+2*x+0.005;
			}
			else
			{
				x=x+0.005;
				y=y-0.005;
				p=p+2*x-2*y+0.005;
			}
	
		}
				
	}
	void Operations:: semicircle(Point point, float radius, int o, Color lc, float thickness=1.0f){
		float xx,yy;
		xx=point.getCoords()[0];
		yy=point.getCoords()[1];
		cout<<4<<xx<<" " <<yy<<" "<<radius<<" "<<o<<endl;
		//cout<<xx<<","<<yy<<"\n";
		float p;
		float x,y;
		y=radius;
		p=(5/4)-radius;
		for(x=0.0;x<=y;) {
			lc.set();
			glPointSize(thickness);
			glBegin(GL_POINTS);
			switch (o){
				case 0:
					glVertex2f(xx+x, yy+y);
					glVertex2f(xx-x, yy+y);
					glVertex2f(xx+y, yy+x);
					glVertex2f(xx-y, yy+x);
					break;
				case 1:
					glVertex2f(xx+x, yy+y);
					glVertex2f(xx+x, yy-y);
					glVertex2f(xx+y, yy+x);
					glVertex2f(xx+y, yy-x);
					break;
				case 2:
					glVertex2f(xx-x, yy+y);
					glVertex2f(xx-x, yy-y);
					glVertex2f(xx-y, yy+x);
					glVertex2f(xx-y, yy-x);
					break;
				case 3:
					glVertex2f(xx+x, yy-y);
					glVertex2f(xx-x, yy-y);
					glVertex2f(xx+y, yy-x);
					glVertex2f(xx-y, yy-x);
					break;
				default:
					break;
			}
				glEnd();
				if(p<0)
				{
					x=x+0.005;
					p=p+2*x+0.005;
				}
				else
				{
					x=x+0.005;
					y=y-0.005;
					p=p+2*x-2*y+0.005;
				}
		
			}
		}
/** Class that stores the attributes required for a circle.
 * This has a Point, a radius and a color.
 * has a draw() function that calls the midpointcircle() function and draw itself.
 */
class Circle{
	public:
		/// the centre of the circle
		Point centre;
		/// the line color of the circle
		Color line_color;
		/// the fill color of the circle
		Color fill_color;
		/// filled or not?
		int state;
		/// the radius.
		float radius;
		/// The tthickness of the border
		float thickness;
		/// Constructor that takes only a Point and a radius and the state of the circle (1-filled, 0-empty, and the thickness of the circle border
		Circle(Point p, float r, int st=0, float th=1.0f){
			Color c (0.0f, 0.0f, 0.0f);
			line_color=c;
			fill_color=c;
			radius=r;
			centre=p;
			state=st;
			thickness=th;
		};
		/// Constructor that takes a Point, a radius, a Color.
		Circle(Point p, float r, Color color, float th=1.0f){
			line_color=color;
			radius=r;
			centre=p;
			state=0;
			thickness=th;
		};
		/// takes the centre as a Point, the radius, the line color, the state of the circle (0 - ufilled, 1 - filled), the fill colore.
		Circle(Point p, float r, Color lcolor, int st, Color fcolor, float th=1.0f){
			line_color=lcolor;
			fill_color=fcolor;
			radius=r;
			centre=p;
			state=1;
			thickness=th;
		};
		/// Destructor
		~Circle() {} ;
		/// returns Point.
		Point getCentre(){
			return centre;
		};
		Point setCentre(Point c){
			centre = c;
		};
		/// calls midpointcircle() function to draw itself.
		void draw(){
			line_color.set();
			for(int i=0;i<(int)thickness;i++){
				Operations::midpointcircle(centre, radius, line_color, state, fill_color, 1.0f);
				radius-=0.1f;
			}
		}
};
class PrintText{
	public:
	float cursor_x, cursor_y, x, y, size ;
	string content;
	Color textColor;
	float thickness;
	
	PrintText(string cont, float xx, float yy, float s, Color c, float thick){
		content=cont;
		x=xx;
		y=yy;
		size=s-thick/s/4;
		textColor=c;
		thickness=thick;
		
		
	}
	
	void setText(string s){
		content=s;
	}
	void setSize(float x){
		size=x;
	}
	void setxy(float xx, float yy){
		x=xx;
		y=yy;
	}
	void draw(){
		cursor_x=x;
		cursor_y=y;
		cout<<content.size()<<endl;
		for(int j=0;j<content.size();j++){
			ifstream f;
			int i;
			switch(content[j]){
				case 'a':
				case 'A':
					f.open("fonts/A.disp", ios::in);
					break;
				case 'b':
				case 'B':
					f.open("fonts/B.disp", ios::in);
					break;
				case 'c':
				case 'C':
					f.open("fonts/C.disp", ios::in);
					break;
				case 'd':
				case 'D':
					f.open("fonts/D.disp", ios::in);
					break;
				case 'e':
				case 'E':
					f.open("fonts/E.disp", ios::in);
					break;
				case 'f':
				case 'F':
					f.open("fonts/F.disp", ios::in);
					break;
				case 'g':
				case 'G':
					f.open("fonts/G.disp", ios::in);
					break;
				case 'h':
				case 'H':
					f.open("fonts/H.disp", ios::in);
					break;
				case 'i':
				case 'I':
					f.open("fonts/I.disp", ios::in);
					break;
				case 'j':
				case 'J':
					f.open("fonts/J.disp", ios::in);
					break;
				case 'k':
				case 'K':
					f.open("fonts/K.disp", ios::in);
					break;
				case 'l':
				case 'L':
					f.open("fonts/L.disp", ios::in);
					break;
				case 'm':
				case 'M':
					f.open("fonts/M.disp", ios::in);
					break;
				case 'n':
				case 'N':
					f.open("fonts/N.disp", ios::in);
					break;
				case 'o':
				case 'O':
					f.open("fonts/O.disp", ios::in);
					break;
				case 'p':
				case 'P':
					f.open("fonts/P.disp", ios::in);
					break;
				case 'q':
				case 'Q':
					f.open("fonts/Q.disp", ios::in);
					break;
				case 'r':
				case 'R':
					f.open("fonts/R.disp", ios::in);
					break;
				case 's':
				case 'S':
					f.open("fonts/S.disp", ios::in);
					break;
				case 't':
				case 'T':
					f.open("fonts/T.disp", ios::in);
					break;
				case 'u':
				case 'U':
					f.open("fonts/U.disp", ios::in);
					break;
				case 'v':
				case 'V':
					f.open("fonts/V.disp", ios::in);
					break;
				case 'w':
				case 'W':
					f.open("fonts/W.disp", ios::in);
					break;
				case 'x':
				case 'X':
					f.open("fonts/X.disp", ios::in);
					break;
				case 'y':
				case 'Y':
					f.open("fonts/Y.disp", ios::in);
					break;
				case 'z':
				case 'Z':
					f.open("fonts/Z.disp", ios::in);
					break;
				case '1':
					f.open("fonts/1.disp", ios::in);
					break;
				case '2':
					f.open("fonts/2.disp", ios::in);
					break;
				case '3':
					f.open("fonts/3.disp", ios::in);
					break;
				case '4':
					f.open("fonts/4.disp", ios::in);
					break;
				case '5':
					f.open("fonts/5.disp", ios::in);
					break;
				case '6':
					f.open("fonts/6.disp", ios::in);
					break;
				case '7':
					f.open("fonts/7.disp", ios::in);
					break;
				case '8':
					f.open("fonts/8.disp", ios::in);
					break;
				case '9':
					f.open("fonts/9.disp", ios::in);
					break;
				case '0':
					f.open("fonts/0.disp", ios::in);
					break;
				case ' ':
					cursor_x+=size;
					continue;
			}
			int p;
			f>>p;
			for(i=0;i<p;i++){
				float x,y;
				f>>x;
				f>>y;
				Point p (x*size+cursor_x, y*size+cursor_y, textColor);
				p.draw();
			}
			f>>p;
			for(i=0;i<p;i++){
				float x0,y0,x1, y1;
				f>>x0;
				f>>y0;
				f>>x1;
				f>>y1;
				Point p1 (x0*size+cursor_x, y0*size+cursor_y);
				Point p2 (x1*size+cursor_x, y1*size+cursor_y);
				Line l (p1, p2, textColor, thickness);
				l.draw();
			}
			f>>p;
			for(i=0;i<p;i++){
				float x, y, radius;
				int orientation;
				f>>x;
				f>>y;
				f>>radius;
				f>>orientation;
				Point c (x*size+cursor_x, y*size+cursor_y);
				Operations::semicircle(c, radius*size, orientation, textColor, thickness);
			}
			float nextspace;
			f>>nextspace;
			cursor_x+=nextspace*size+thickness/7;
		
		}
	}
};
<<<<<<< HEAD
			
=======
class Graph {
	public:
		/// Number of divisions on each axes
		int x_div, y_div, x_avail, y_avail;
		/// Labels <<for each axis
		int* x_labels, y_labels;
		int drawline;
		vector<vector<Point> > data;	
		/// Constructor that takes data, x divisions, y divisions.
		Graph (){drawline=1;x_div=0;y_div=0;
		};
		void setDivisions(int x, int y){
			x_div=x;
			y_div=y;
			cout<<x_div<<","<<y_div<<"\n";
		}
		int getDivisions(int index){
			if(!index){
				return x_div;
			}
			else{
				return y_div;
			}
		}
		void read(){
			datareader d1;
			d1.read();
			data.push_back( d1.getTotals() );
		}			
			
		/// Test drawing function.
		void plot(){
			Point origin (0.5f, 0.5f);
			Point x_end (X-0.5f, 0.5f);
			Point y_end (0.5f, Y-0.5f);
			Line x_axis (origin, x_end);
			Line y_axis (origin, y_end);
			x_axis.setThickness(7);
			y_axis.setThickness(6);
			x_axis.draw();
			y_axis.draw();
			vector<vector<Point> >::iterator i;
			vector<Point>::iterator j;
			for(i=data.begin(); i!=data.end();i++){
				int size_x=i->size();
				float scale_x;
				if(!x_div) scale_x=(X-0.5f)/size_x;
				else scale_x=(X-0.5f)/x_div;

				for(j=i->begin();j!=i->end();j++){
					float a=j->getCoords()[0];
					float b=j->getCoords()[1];
					int opt=0;
					if(j!=i->end()){
						float c=(j+1)->getCoords()[0];
						float d=(j+1)->getCoords()[1];
						if(a*scale_x+0.5f < X ){
							Point p1 (a*scale_x+0.5f, b*Y+0.5f);
							Point p2 (c*scale_x+0.5f, d*Y+0.5f);
							//p1.draw();
							//p2.draw();
							Circle c (p1, 1.0f);
							Line l (p1, p2);
							l.setThickness(100);
							c.draw();
							l.draw();
						}
					}	
				}
			}
						


		}


};
>>>>>>> 09950c976b5a614a45a67cda2544cee9295383b3

