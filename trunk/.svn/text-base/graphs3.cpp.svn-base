class datareader 
{
  public :
	vector<vector<float> > allYears;
	vector<vector<Point> > scaledAllYears;
	vector<Point>::iterator m;
	vector<float>::iterator n;
	int year,y,count,n;
	float c;
	float ymax,ymin;
	float xmin,xmax;
	~datareader () {};
	datareader()    
	{
	      c=0;
	      y=0;
	      count=0;
	};
	vector<vector<Point> >getInput(){
		return allYears;
	} 

	void read()
	{
		float yvalue=0;
		scanf("%d",&count);
		for(int wx=0;wx<5;wx++){	
			vector<float> popInput;
			vector<Point> scaledPopInput;
			for(y=0;y<count;y++) {
				scanf("%f",&yvalue);
				if(!y){ xmax=yvalue;xmin=yvalue;ymax=yvalue;ymin=yvalue;}
				if(yvalue>ymax)
					ymax=yvalue;
				if(yvalue<ymin)
					ymin=yvalue;
				if(c>xmax)
					xmax=c;
				if(c<xmin)
					xmin=c;
				popInput.push_back(yvalue);
				c++;
			}
			for(n=popInput.begin();n!=popInput.end();n++){
				float a=(float)wx/5;
				float b= *n-ymin/(ymax-ymin);
				Point p((float)a,b);
				scaledPopInput.push_back(p);
			}
			allYears.push_back(popInput);
			scaledAllYears.push_back(scaledPopInput);
		}
    }
};  

class Graph_Environment{
public:
	int x_div, y_div; 
	float x_avail, y_avail,x_origin,y_origin;
	float x_offset,y_offset;
	float x_dragged, y_dragged;
	float x_box_origin,y_box_origin;          
	float x_box_end,y_box_end;
	enum graphStates{PLOT1, PLOT2, GROW, FALL, ANIMATETO} ;
	graphStates state;
	float deltaX;
	float zoomFactor;
	Point Origin;
	/// Labels <<for each axis
	int* x_labels, y_labels;
	int drawline;
	int choice;
	datareader2 d2;
	vector<Circle> circ;
	int index;	
	~Graph_Population() {};
	Graph_Population()
	{	x_div=0;
		y_div=0;
		x_origin=50;
		y_origin=50;
		//x_offset=0;
		zoomFactor=1;
		deltaX=0;
		Origin.setCoords(x_origin,y_origin);
		x_dragged=0;
		y_dragged=0;
		choice=0;
		index=1;
		state=PLOT1;
	}
	void setState(int i){
		switch(i){
			case 0:
				state=PLOT1;
				break;
			case 1:
				state=PLOT2;
				break;
			case 2:
				state=GROW;
				break;
		}
	}
	float* getDeltaX(){
		return &deltaX;
	}
	float* getDraggedX(){
		return &x_avail;
	}
	float* getDraggedY(){
		return &y_avail;
	}
	void setIndex (int i) {
		index = i;
	}
	void setChoice(int c){
		choice=c;
	}
	
	void setDeltaX(float xi,float xf){
		deltaX=(xi - xf);
	}
	
	Graph_Population(float x,float y, float x_length,float y_length)
	{
		x_origin=x;
		y_origin=y;
		x_avail=x_length;
		y_avail=y_length;
		x_offset=x_length/10;
		y_offset=y_length/10;
		zoomFactor=1;
		deltaX=0;
		Origin.setCoords(x_origin,y_origin);
	}
	void setDivisions(int x, int y){
		x_div=x;
		y_div=y;
		
	//	cout<<x_div<<","<<y_div<<"\n";
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
			// read the data here
			d2.read();
			createCircle();
		}		
		
		void delay(){
			int c,d;
			for(c=1;c<30000;c++)
				for(d=1;d<30000;d++)
					{}
		}

			
		void drawAxes(){
			Point x_end(x_origin+x_avail+2*x_offset,y_origin);
			Point y_end(x_origin,y_origin+y_avail+2*y_offset);
			Line x_axis(Origin,x_end,pallete[0],1);
			Line y_axis(Origin,y_end,pallete[0],1);
			x_axis.setThickness(2);
			y_axis.setThickness(2);
			x_axis.draw();
			y_axis.draw();
		}
		
		void drawBox(){
			Point r1(x_box_origin,y_box_origin);
			Point r2(x_box_end,y_box_end);
			Rectangle rect(r1,r2,pallete[3],1,pallete[4],1);
			rect.draw();                             // new added end
		}
		void createCircle(){
			vector<vector<Point> >::iterator i;
			vector<Point>::iterator j;
			i=scaledAllYears.begin();
			for(j=i->begin();(j+1)!=i->end();j++)
			{
				float a=j->getCoords()[0];
				a=a*x_avail+x_origin;
				a*=zoomFactor;
				a+=deltaX;
				a+=x_offset;
				float b=j->getCoords()[1];
				b=b*y_avail+y_origin+y_offset;
				
				Point left(a,b);
				Circle cn(left,0.2,pallete[2],1,pallete[3],1);
				circ.push_back(cn);
			}
		}
		void plot(){
		if(state==PLOT1 || state==GROW || state==FALL){
			
			
			//float x_box_origin,y_box_origin;          
			//float x_box_end,y_box_end;
			x_box_origin=x_origin-x_avail/10;
			y_box_origin=y_origin-y_avail/10;
			x_box_end=x_box_origin+x_avail+2*x_avail/10+2*x_offset;
			y_box_end=y_box_origin+y_avail+2*y_avail/10+2*y_offset;
			
			Area graph;
			graph.x0=x_box_origin*unit;
			graph.y0=y_box_origin*unit;
			graph.x1=x_box_end*unit;
			graph.y1=y_box_end*unit;
			graph.label=GRAPHAREA;
			Operations::registerArea(graph);
			
			graph.x0=(x_box_end-2.0f)*unit;
			graph.y0=(y_box_end-2.0f)*unit;
			graph.x1=(x_box_end+2.0f)*unit;
			graph.y1=(y_box_end+2.0f)*unit;
			graph.label=RESIZE_CORNER;
			Operations::registerArea(graph);
			
			drawBox();
			
			vector<vector<Point> >::iterator i;
			i=scaledAllYears.begin();

			drawAxes();
		
			vector<Point>::iterator j;
			//loop for divisions
			for(j=i->begin();j!=i->end();j++)
			{
				float r=j->getCoords()[0];
				r=r*x_avail+x_origin;
				r*=zoomFactor;
				r+=x_offset;
				r+=deltaX;
				Point r1(r,y_origin);
				Point r2(r,y_origin-1);
				Line lr(r1,r2,x_origin+x_offset,x_origin+x_avail+2*x_offset);
				lr.color=pallete[0];
				lr.clipDraw();
			}	
		
				vector<Circle>::iterator ic;
				int done=1;
				int counter=0;
				for(ic=circ.begin();ic!=circ.end();ic++){
					if(state==GROW){
						if((ic->radius)<(ic->centre.coords[1]/10)){
							ic->radius+=1.0f;
							done=0;	
						}
					}
					if(state==FALL){
						if((ic->centre.coords[1])>(x_origin+ic->radius)){
							ic->centre.coords[1]-=1.5f;
							done=0;
						}
					}	
					ic->draw();
					
					//cout<<counter<<endl;
					counter++;
				}
				if(state==GROW && done){
					state=FALL;
				}
				else if(state==FALL && done){
					state=ANIMATETO;
				}
				if(state!=FALL){
					for(j=i->begin();(j+1)!=i->end();j++)
					{
						float a=j->getCoords()[0];
						a=a*x_avail+x_origin;
						a*=zoomFactor;
						a+=deltaX;
						a+=x_offset;
						float b=j->getCoords()[1];
						b=b*y_avail+y_origin+y_offset;
						float c=(j+1)->getCoords()[0];
						c=c*x_avail+x_origin;
						c*=zoomFactor;
						c+=x_offset;
						c+=deltaX;
						float d=(j+1)->getCoords()[1];
						d=d*y_avail+y_origin+y_offset;
						Point squarebotfrom(a-0.3,b-0.3);                  // new strtt
						Point squarebotto(a+0.3,b+0.3);
						Color sq=pallete[2];
						Rectangle square(squarebotfrom,squarebotto,sq,1,sq,1);
						//square.draw();
				
						//Point squarebotfrom2(c-0.3,d-0.3);
						//Point squarebotto2(c+0.3,d+0.3);
				
						//Rectangle square2(squarebotfrom2,squarebotto2,sq,1,sq,1);
						if(((a-0.3)>(x_origin+x_offset)) && ((a+0.3)<(x_origin+x_avail+2*x_offset)))
						{
							square.draw();                                     // new end
						}
								Point left(a,b);	
						Point right(c,d);
						Line l1(left,right,x_origin+x_offset,x_origin+x_avail+2*x_offset);
						l1.color=pallete[1];
						l1.clipDraw();
					}
				}
				
				
		}
		else if(state==PLOT2){
			float x_box_origin,y_box_origin;             // new added start
			float x_box_end,y_box_end;
			x_box_origin=x_origin-x_avail/10;
			y_box_origin=y_origin-y_avail/10;
			x_box_end=x_box_origin+x_avail+2*x_avail/10+2*x_offset;
			y_box_end=y_box_origin+y_avail+2*y_avail/10+2*y_offset;
			
			Point r1(x_box_origin,y_box_origin);
			Point r2(x_box_end,y_box_end);
			Rectangle rect(r1,r2,pallete[3],1,pallete[4],1);
			rect.draw();                                // new added end

			vector<vector<Point> >::iterator i;
			int m=index,k=1;
			for(i=d2.scaledAllYears.begin();k<m;i++)
			  k++;
			Point x_end((x_origin+x_avail+2*x_offset),(y_origin));
			Point y_end((x_origin),(y_origin+y_avail+2*y_offset));
			Line x_axis(Origin,x_end);
			x_axis.color=pallete[0];
			Line y_axis(Origin,y_end);
			y_axis.color=pallete[0];
			x_axis.setThickness(5);
			y_axis.setThickness(5);
			x_axis.draw();
			y_axis.draw();
			vector<Point>::iterator j;
			//the for loop below draws the divisions on the x-axis
			for(j=i->begin();j!=i->end();j++)
			{
				float r=j->getCoords()[0];
				r=r*x_avail+x_origin;
				r*=zoomFactor;
				r+=x_offset;
				r+=deltaX;
				Point r1(r,y_origin);
				Point r2(r,y_origin-1);
				Line lr(r1,r2,x_origin+x_offset,x_origin+x_avail+2*x_offset);
				lr.color=pallete[0];
				lr.clipDraw();
			}
			//loop for other fields like food
			for(j=i->begin();(j+1)!=i->end();j++)
			{
				float a=j->getCoords()[0];
				a=a*x_avail+x_origin;
				a*=zoomFactor;
				a+=x_offset;
				a+=deltaX;
				float b=j->getCoords()[1];
				b=b*y_avail+y_origin+y_offset;
				float c=(j+1)->getCoords()[0];
				c=c*x_avail+x_origin;
				c*=zoomFactor;
				c+=x_offset;
				c+=deltaX;
				float d=(j+1)->getCoords()[1];
				d=d*y_avail+y_origin+y_offset;
				//draws square for otherdata like food
				Point squarebotfrom(a-0.3,b-0.3);                  // new strtt
				Point squarebotto(a+0.3,b+0.3);
				Color sq=pallete[2];
				Rectangle square(squarebotfrom,squarebotto,sq,1,sq,1);
				//square.draw();
				
				//Point squarebotfrom2(c-0.3,d-0.3);
				//Point squarebotto2(c+0.3,d+0.3);
				
				//Rectangle square2(squarebotfrom2,squarebotto2,sq,1,sq,1);
				if(((a-0.3)>(x_origin+x_offset)) && ((a+0.3)<(x_origin+x_avail+2*x_offset)))
				{
					square.draw();                                     // new end
				}
				Point left(a,b);
				Point right(c,d);
				Line l1(left,right,x_origin+x_offset,x_origin+x_avail+2*x_offset);
				l1.color=pallete[2];
				l1.clipDraw();
			}
			i=d2.scaledAllYears.begin();
			
			//loop population with circles
			for(j=i->begin();(j+1)!=i->end();j++)
			{
				float a=j->getCoords()[0];
				a=a*x_avail+x_origin;
				a*=zoomFactor;
				a+=x_offset;
				a+=deltaX;
				float b=j->getCoords()[1];
				b=b*y_avail+y_origin+y_offset;
				float c=(j+1)->getCoords()[0];
				c=c*x_avail+x_origin;
				c*=zoomFactor;
				c+=x_offset;
				c+=deltaX;
				float d=(j+1)->getCoords()[1];
				d=d*y_avail+y_origin+y_offset;

				// after obtaining values scale them
				//not yet done
				Color c3=pallete[1];                     // new strt
				Point left2(a,b);
				Circle cn(left2,0.3,c3,1,c3,1);
				if((a>x_origin+x_offset) && (a<x_origin+x_avail+2*x_offset))
				{
					cn.draw();
				}
				Point right2(c,d);                    // new end

				Line l2(left2,right2,x_origin+x_offset,x_origin+x_avail+2*x_offset);
				l2.color=pallete[1];
				l2.clipDraw();
			}	
			
				
		}
		}
		
		void zoomInGraph(){
				zoomFactor+=0.1;
		}
		
		void zoomOutGraph(){
			if(zoomFactor>1)
				zoomFactor-=0.1;
		}
};
  
		
	
	


