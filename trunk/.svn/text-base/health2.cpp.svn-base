/*This class is used to read the data of fertility rate on X-axis and life expectancy on Y-axis and plot the circles on the screen color them and then translate them as the years pass by and finally the radius of the circle indicates the population of that country in that year.*/

class datareader3
{
	public :
		vector<vector<Point> > allData;
		vector<vector< long int> > allPopData;
		vector<vector<float> > scaledAllPopData;
		vector<vector<Point> > scaledAllData;
		vector<Point> data;
		int countries, count;
		double xmin,ymin;
		double xmax,ymax;
		double popmin,popmax;
		datareader3()
		{
		}
		
		vector<vector<Point> > getInput()
		{
			return allData;
		}
		
		void read()
		{
			ymax=0;
			ymin=22222222222;
			xmax=0;
			xmin=22222222222;
			popmax=0;
			popmin=22222222222;
			long int population=0;
			float yvalue=0;
			float xvalue=0;
			scanf("%d",&countries);
			scanf("%d",&count);
			vector<Point>::iterator m;
			for(int x=0;x<countries;x++)
			{
				vector<Point> ordinateData;
				vector<Point> scaledOrdinateData;
				
				for(int y=0;y<count;y++)
				{
					scanf("%f",&yvalue);
					if(yvalue>ymax)
					ymax=yvalue;
					if(yvalue<ymin)
					ymin=yvalue;	
					Point p;
					p.coords[1]=yvalue;
					ordinateData.push_back(p);
					//allData.push_back(ordinateData);
				}
			
				for(m=ordinateData.begin();m!=ordinateData.end();m++)
				{
					scanf("%f",&xvalue);
					if(xvalue>xmax)
						xmax=xvalue;
					if(xvalue<xmin)
						xmin=xvalue;	
					m->coords[0]=xvalue;	
				}
				allData.push_back(ordinateData);
			
				for(m=ordinateData.begin();m!=ordinateData.end();m++)
				{
					float a= (m->getCoords()[0]*10/*-xmin)/(xmax-xmin*/);
					float b= (m->getCoords()[1]/*-ymin)/(ymax-ymin*/);		
					Point p((float)a,b);
					scaledOrdinateData.push_back(p);
				}
				scaledAllData.push_back(scaledOrdinateData);
			}
			for(int x=0;x<countries;x++)
			{
				vector<long int> popData;
				
				for(int y=0;y<count;y++)
				{

					scanf("%ld",&population);
						if(population>popmax)
							popmax=population;
						if(population<popmin)
							popmin=population;	
						popData.push_back(population);
						//cout<<population<<"\n";
				}
				allPopData.push_back(popData);
				vector<float > scaledPopData	;
				vector< long int >::iterator p;	

			for(p=popData.begin();p!=popData.end();p++)
			{
				
				float a= (float)(*p)/7000000;
				//float b= (m->getCoords()[1]-ymin)/(ymax-ymin);		
				//m->coords[0]=a;
				scaledPopData.push_back(a);
			// cout<<a*10<<"\n";
			}
			
			
				scaledAllPopData.push_back(scaledPopData);
			}
		}
};

class Graph_Health
{
	public:
		int x_div, y_div, x_avail, y_avail,x_origin,y_origin, choice;
		/// Labels <<for each axis
		int* x_labels, y_labels;
		enum graphstates { STATIC, ANIMATE };
		graphstates state;
		int drawline;
		int current_year;
		datareader3 d3;
	//	vector<vector<Point> > data;	
		Graph_Health()
		{
			x_div=0;
			y_div=0;
			x_origin=5;
			y_origin=5;
			choice=1;
			state=STATIC;
			current_year=0;
		}
		Graph_Health(int x,int y,int x_length,int y_length)
		{
			x_div=8;
			y_div=8;
			x_origin=x;
			y_origin=y;
			x_avail=x_length;
			y_avail=y_length;
			choice=1;
			state=STATIC;
			current_year=0;
		}
		void setDivisions(int x, int y)
		{
			x_div=x;
			y_div=y;
			cout<<x_div<<","<<y_div<<"\n";
		}
		
		void setChoice(int ch){
			choice=ch;
		}
		void setState(int ch){
			switch(ch){
				case 0:
					state=STATIC;
				case 1:
					state=ANIMATE;
			}
		}
		int getDivisions(int index)
		{
			if(!index)
			{
				return x_div;
			}
			else
			{
				return y_div;
			}
		}
	 
		void read()
		{
			// read the data here
			d3.read();
			cout<<"HEllo"<<endl;
		}		
		
			void plot()
			{
				cout<<state<<endl;
				vector<vector<Point> >::iterator i;
				int m=choice,k=1;
				for(i=d3.scaledAllData.begin();k<m;i++) 
				{ 
					k++;
				}
				//check if the way iterator used is proper
					//for(;k<m;k++,i++);
				 
					Point Origin((float)x_origin,(float)y_origin);
					Point x_end((float)(x_origin+x_avail),(float)(y_origin));
					Point y_end((float)(x_origin),(float)(y_origin+y_avail));
					Color col;
					col.setColor(0.0f,0.0f,0.0f);
					Line x_axis(Origin,x_end, col);
					Line y_axis(Origin,y_end, col);
					
					x_axis.setThickness(3);
					y_axis.setThickness(3);
					x_axis.draw();
					y_axis.draw();
					
					for(int p=1;p<=x_div;p++)
					{
						Point p1((float)x_origin+p*10,(float)y_origin);
						Point end((float)x_origin+p*10,(float)y_origin+(y_div)*10);
						
						col.setColor(0.9f,0.9f,0.9f);
						Line x_line(p1,end,col);
						//Line y_axis(Origin,y_end, c);
						x_line.setThickness(3);
						//y_axis.setThickness(3);
						x_line.draw();
						//y_axis.draw();
					}
			
					
					for(int p=1;p<=y_div;p++)
					{
						Point p2((float)x_origin,(float)y_origin+p*10);
						Point end((float)x_origin+x_div*10,(float)y_origin+p*10);
						
						col.setColor(0.9f,0.9f,0.9f);
						//Line x_line(p1,end,c);
						Line y_line(p2,end,col);
						//x_line.setThickness(3);
						y_line.setThickness(3);
						y_line.draw();
						//y_axis.draw();
					}
					
					vector<Point>::iterator j;
				
					vector<vector<float> >::iterator e;
					k=1;
					vector<float> ::iterator f;
					
					for(e=d3.scaledAllPopData.begin();k<m;e++) 
					{ 
						k++;
					}
					f=e->begin();
					k=0;
					for(j=i->begin();k<current_year;k++,j++,f++);
					
					
						float a=j->getCoords()[0];
						a=a+x_origin;
						float b=j->getCoords()[1];
						b=b+y_origin;
						float c=(j+1)->getCoords()[0];
						c=c+x_origin;
						float d=(j+1)->getCoords()[1];
						d=d+y_origin;
						int y=0;
						Point left(a,b);
						Point right(c,d);
						//Line l1(left,right,pallete[m]);
						//l1.setThickness(2);
						//l1.draw();
						//cout<<*f<<endl; 	
						float g= (*f);
						Color colour1(1.0f,0.0f,0.0f);
						Circle c1(left,g,colour1,1,pallete[m-1],1.0f);
						c1.draw();
					if(state==ANIMATE && current_year<49){ cout<<"Yeah"<<endl;current_year++;}
					else if(state==ANIMATE && current_year==49) state==STATIC;	
					
						
						//animation missing, so write function called drawAnimationLine for line class
						//pointer, a object has to created for each field
						
//						j++;/*remove if not wporking*/
						

}
};
