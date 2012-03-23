int c, y;
float ymax=0,ymin=0,value[250],mean[50],total[50],a[245][50];
Point p[245][50];
void input_points()
{
	for(y=0;y<49;y++)
	{
		for(c=0;c<244;c++)
		{
			scanf("%f",&a[c][y]);
			if(c==0){
				ymin=a[c][y];
				total[y]=a[c][y];
			}
			else{
				if(a[c][y]<ymin)
				ymin=a[c][y];
				total[y]+=a[c][y];
			}
			if(a[c][y]>ymax)
			ymax=a[c][y];
			
		}
		mean[y]=total[y]/244;
	}
	float width=(float)ww/(float)unit;
	float index=-width;
	for(int y=0;y<49;y++)
	{
		for(int c=0;c<244;c++)
		{
			p[c][y].setCoords(index, (a[c][y]*3.0f)/mean[y],0.0f);
			index+=width/244;	
		}
	}	
}
