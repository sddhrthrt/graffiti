/** \file classes.h
 * Has definitions of all the classes that are used in the code.
 * The classes currently implemented are: Color, Point, Line, Quadrangle. 
 * \author Akhil, Anantha, Chandrakanth, Shrimai, Siddhartha
 * \date Mar22, 2012
 */
/// Color
/// A class that has an array of size three, holding the r, g, b details of the Color object. 
/// 
vector<void* > rows(2000);
vector< vector<void*> > segfile(2000, rows);
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
class Point {
	
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
class Operations {
	public:
	/// The generic bresenham. Works for any slope, any angle, anything!
	static void bresenham(Point a, Point b ){
		float x0=a.getCoords()[0];
		float y0=a.getCoords()[1];
		float x1=b.getCoords()[0];
		float y1=b.getCoords()[1];
		//cout<<x0<<","<<y0<<" to "<<x1<<","<<y1<<"\n";

		float INCR=0.00001;
		float INCRX=0.00001;
		float INCRY=0.00001;
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
		//	glPointSize(2.5f);
			//cout<<(int)(x*unit)<<","<<(int)(y*unit)<<"\n";
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
			}
			else
			{
				x=x+0.0001;
				y=y-0.0001;
				p=p+2*x-2*y+0.0001;
			}
	
		}
	}
	static void addToSegfile(void* ob, int x, int y){
		segfile[x][y]=ob;
	}
	static void* getFromSegfile(int x, int y){
		cout<<x<<", "<<y<<"\n";
		return segfile[x][y];
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
			Operations::bresenham(a, b);
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
/** A class to read data.
 *
 */
class datareader{
	vector<vector<Point> > allyears;
	vector<Point> totals;
	int year, c, y, count;
	int years[50];
	float ymax,ymin,value[250],mean[50],total[50];
	public:
		datareader () {year;c=0;y=0;count=0;};
		vector<vector<Point> > getInput(){
			return allyears;
		}
		vector<Point> getTotals(){
			return totals;
		}
		void read(){
			ymax=0;
			ymin=0;
			float totalmax=0;
			float yvalue;
			scanf("%d", &count);
			for(y=0;y<count;y++){
				years[y]=0;
			}
			for(y=0;y<count;y++){
				scanf("%d", &year);
				years[year-1960]=1;
			}
			for(y=0;y<count;y++)
			{
				if(years[y]){
					vector <Point> input;
					for(c=0;c<244;c++)
					{
						scanf("%f",&yvalue);
						if(c==0){
							ymin=yvalue;
							total[y]=yvalue;
						}
						else{
							if(yvalue<ymin)
								ymin=yvalue;
							total[y]+=yvalue;
						}
						if(yvalue>ymax)
						ymax=yvalue;
						Point p ((float)c, yvalue);
						input.push_back(p);
					}
				allyears.push_back(input);
				if(y==0)
					totalmax=total[y];
				else {
					if(totalmax<total[y]){
						totalmax=total[y];
					}
				}
				
			//	std::cout<<mean[y]<<"\n";	
				}
			}
			for(y=0;y<count;y++){
				total[y]=total[y]/totalmax;
				Point tot ((float)y, total[y]);
				totals.push_back( tot);
				mean[y]=total[y]/(float)244;
			}
		}
};
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

