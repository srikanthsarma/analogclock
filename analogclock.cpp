	#include<graphics.h>
	#include<cmath>
	#include<ctime>
	#define PI 3.1415
	
	const	int maxX=GetSystemMetrics(SM_CXSCREEN);
	const	int maxY=GetSystemMetrics(SM_CYSCREEN);
	
	const	int radius=200;
	const int midX =maxX/2;
	const int midY =maxY/2;
	
	main(){
		initwindow(maxX,maxY);
		int page = 0;		
																					 			
	  while(true){
	  	    
	  	setactivepage(page);
	  	setvisualpage(1-page);
	  	cleardevice();
	  setcolor(WHITE);	
	 	settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
		outtextxy(50,50,"ANALOG_CLOCK :");	
	  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
		outtextxy(750,650,"PRESS ESC TO EXIT");	
	  
		setcolor(LIGHTRED);	
		circle(midX,midY,3);
		circle(midX,midY,radius);
		circle(midX,midY,radius+1);
		circle(midX,midY,radius+2);
		setcolor(WHITE);
		circle(midX,midY,radius+3);
		circle(midX,midY,radius+4);
		setfillstyle(SOLID_FILL,WHITE);
		floodfill(midX,midY,LIGHTRED);
		int offset0=radius-20;
		
		setcolor(LIGHTRED);
		settextstyle(BOLD_FONT,HORIZ_DIR,1);
		const int OSX=7,OSY=7;
		
		outtextxy(midX+offset0*sin(PI/6)-OSX , midY-offset0*cos(PI/6)-OSY ,  "1");
		outtextxy(midX+offset0*sin(2*PI/6)-OSX , midY-offset0*cos(2*(PI/6)) -OSY,  "2");
		outtextxy(midX+offset0*sin(3*(PI/6))-OSX, midY-offset0*cos(3*(PI/6)) -OSY,  "3");	
		outtextxy(midX+offset0*sin(4*(PI/6))-OSX , midY-offset0*cos(4*(PI/6)) -OSY,  "4");
		outtextxy(midX+offset0*sin(5*(PI/6))-OSX , midY-offset0*cos(5*(PI/6)) -OSY,  "5");
		outtextxy(midX+offset0*sin(6*(PI/6))-OSX , midY-offset0*cos(6*(PI/6))-OSY ,  "6");
		outtextxy(midX+offset0*sin(7*(PI/6))-OSX , midY-offset0*cos(7*(PI/6)) -OSY,  "7");
		outtextxy(midX+offset0*sin(8*(PI/6))-OSX , midY-offset0*cos(8*(PI/6)) -OSY,  "8");
		outtextxy(midX+offset0*sin(9*(PI/6))-OSX , midY-offset0*cos(9*(PI/6)) -OSY,  "9");
		outtextxy(midX+offset0*sin(10*(PI/6))-OSX , midY-offset0*cos(10*(PI/6))-OSY ,  "10");
		outtextxy(midX+offset0*sin(11*(PI/6))-OSX, midY-offset0*cos(11*(PI/6)) -OSY,  "11");
		outtextxy(midX+offset0*sin(12*(PI/6))-OSX , midY-offset0*cos(12*(PI/6)) -OSY,  "12");
						
	
		
	
		
	//	fetching time
	
	
		time_t now = time(0);
		tm *ltm = localtime(&now);
		
		
		setcolor(WHITE);
		
	//seconds hand
		line(midX , midY, 
			midX+165*sin(ltm->tm_sec*PI/30) , midY-165*cos(ltm->tm_sec*PI/30) );
		
																		 	 																			 			 				
	//minute hand																					
		double mindeg = (ltm->tm_min*PI/30)  + (ltm->tm_sec*(PI/1800));
		line(midX , midY , 
			midX+140*sin(mindeg) , midY-140*cos(mindeg) );			
		
	
	// hour hand	
		 if(ltm->tm_hour>12) ltm->tm_hour = ltm->tm_hour-12;
		 double hrdeg = ((ltm->tm_hour)*PI/6) + (ltm->tm_min*(PI/360));
			line(midX , midY , 
			midX+100*sin(hrdeg) , midY-100*cos(hrdeg));
	
			
	
												 	 										 										 
		if(GetAsyncKeyState(VK_ESCAPE)) break;
		delay(10);
		
		
		page = 1- page;
	  }
	  
		closegraph();
	
	}

