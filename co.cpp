void input_points()
{
	scanf("%d", &count);
	for(y=0;y<count;y++){
		years[y]=0;
	}
	for(y=0;y<count;y++){
		scanf("%d", &year);
		years[year-1960]=1;
	}
	for(y=0;y<49;y++)
	{
		if(years[y]){
			for(c=0;c<244;c++)
			{
				scanf("%f",&a[y][c][1]);
				if(c==0){
					ymin=a[y][c][1];
					total[y]=a[y][c][1];
				}
				else{
					if(a[y][c][1]<ymin)
						ymin=a[y][c][1];
					total[y]+=a[y][c][1];
				}
				if(a[y][c][1]>ymax)
				ymax=a[y][c][1];
				
			}
		mean[y]=total[y]/(float)244;
	//	std::cout<<mean[y]<<"\n";	
		}
	}
	float width=(float)ww/(float)unit;
	float index=-width;
	for(int y=0;y<49;y++)
	{
		if(years[y]){
			for(int c=0;c<244;c++)
			{
				a[y][c][1]=a[y][c][1]/ymax*1000.0f;
				a[y][c][0]=(float)X/(float)244*c;
			}
		}
		mean[y]=mean[y]/ymax*1000.0f;
	}	
}
