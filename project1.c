#include<GL/glut.h>
#include<math.h>
# define pi 3.14

float j;


void myInit(void){
	glClearColor(0.12,0.01,0.0,1.0);

	 glPointSize(6.0);
	
	 glMatrixMode(GL_PROJECTION);
	 glLoadIdentity();
	 gluOrtho2D(-800,800,-550,550);        
}


void DDALine(double x1,double y1,double x2,double y2){
	
    double dx=x2-x1;
	double dy=y2-y1;
	
	double m=dy/dx;
	 
	 double x,y=y1;
	 
 	 for(x=x1;x<=x2;x+=0.01){
	 	glVertex2i(x,round(y));
	 	y+=(0.01)*m;
	 }



}

void CirclePoints(float x,float y,float xc,float yc)
{
	glVertex2i(x+xc,y+yc);
	glVertex2i(y+xc,x+yc);
	glVertex2i(x+xc,-y+yc);
	glVertex2i(y+xc,-x+yc);
	glVertex2i(-x+xc,-y+yc);
	glVertex2i(-y+xc,-x+yc);
	glVertex2i(-x+xc,y+yc);
	glVertex2i(-y+xc,x+yc);
	
}

void MidPointCircle(float xc,float yc,float radius)
{    
    float x=0;
	float y=radius;
	double d=5.0/4.0 - radius;       //it is initial value of d
	
	CirclePoints(x,y,xc,yc);
	while(y>x){
		if(d<0){
			d+=2.0*x + 3.0;
			x++;
		}
		else{
			d+= 2*(x-y)+5.0;
			y--;
			x++;
		}
		CirclePoints(x,y,xc,yc);
	}
	
}


void drawHalfCircle(int xc,int yc,int r){       
	float i;
	for(i=0;i>=-3.14;i-=0.01){                    // circle will be drawn in the lower half only that's why lopp  
		glVertex2i(xc+r*cos(i),yc+r*sin(i));       //is incremented from 0 to -pi
	}
}

void drawSemiCircleUp(int xc,int yc,int r){
	float i;                                    //points will be plotted clock wise.
	                                              
	for(i=1.04;i<=2.09;i+=0.01){                //60 degree = pi/3 =1.04,  120 degree=2*pi/3  =2.09
		glVertex2i(xc+r*cos(i),yc+r*sin(i));
	}
}



void drawFullEllipse(int xc,int yc,int a,int b){         
	float i;
	for(i=0;i<=6.29;i+=0.01){
		glVertex2i(xc+a*cos(i),yc+b*sin(i));
	}
}



void FillFullCircle(int xc,int yc,int r){
      float i,j;
	  for(j=0;j<=r;j++){              //several circles with same centre, radius is incremented by 1 to get a solid fill circle
      
	   MidPointCircle(xc,yc,j);
  }
  }


void FillFullRectangle(int x1,int x2,int y1,int y2){
 float i,j;
 for(i=x1;i<=x2;i+=1){
   for(j=y1;j<=y2;j+=1){
         glVertex2i(i,j);
   }
 }

}

void LeftFullTriangle(float xc,float yc,float b){         
	
	float i,j;
    for(i=0;i<=b;i+=1){
    	for(j=0;j<=i;j+=1){
    		glVertex2i(xc+i,yc+j);
		}
	}
}

void RightFullTriangle(float xc,float yc,float b){
	
	float i,j;
    for(i=0;i>=-b;i-=1){
    	for(j=0;j<=-i;j+=1){
    		glVertex2i(xc+i,yc+j);
		}
	}
}

void Display(void){

	for( j=0;j<1000;j+=0.01){
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0,0.4,0.0);
	glBegin(GL_POINTS);
	FillFullCircle(0,0,20);                       //Centre of clock
	glEnd();
	
	glBegin(GL_POINTS);
	
	glColor3f(0.4,0.02,0.0);                    //upper hat of the clock
	MidPointCircle(0,400,130);
	MidPointCircle(0,400,135);
	
    glColor3f(1.0,sin(10*j),0.0);                        //to change the colour continuously the upper ball is made
    FillFullCircle(0,400,100);
    
	glColor3f(0.0,1.0,0.0);          
	int k;
	for(k=280;k<=400;k++){
		drawSemiCircleUp(0,0,k);
	}
	

	MidPointCircle(0,0,250);                    //boundary of the clock
	MidPointCircle(0,0,255);
	MidPointCircle(0,0,260);
	MidPointCircle(0,0,280);
	
	drawHalfCircle(0,0,320);                     //design on the boundary
	drawHalfCircle(0,0,340);     
	MidPointCircle(330,20,20);                         //right static circle
	MidPointCircle(-330,20,20);                        //left  static circle
    MidPointCircle(0,0,5);                      //centre point of clock
	
	glColor3f(1.0,1.0,1.0);
	glVertex2i(0,230);                           //12 numbers of clock marked as point
	glVertex2i(-230,0);
	glVertex2i(230,0);
    glVertex2i(0,-230);
	glVertex2i(230*cos(pi/3),230*sin(pi/3));
	glVertex2i(230*cos(pi/6),230*sin(pi/6));
	glVertex2i(230*cos(pi/3),-230*sin(pi/3));
	glVertex2i(230*cos(pi/6),-230*sin(pi/6));
    glVertex2i(-230*cos(pi/3),230*sin(pi/3));
	glVertex2i(-230*cos(pi/6),230*sin(pi/6));
	glVertex2i(-230*cos(pi/3),-230*sin(pi/3));
	glVertex2i(-230*cos(pi/6),-230*sin(pi/6));
	
	glColor3f(0.0,1.0,0.0);
	glVertex2i(330+50*cos(j*50),15+20*sin(j*50));       //esternal rotating little points in elliptical path
	glVertex2i(-330+50*cos(j*50),15+20*sin(j*50));
     
	 
	 MidPointCircle(330,80+20*sin(20*j),20);
	 MidPointCircle(-330,80+20*sin(20*j),20);
	 
	

	 
	 glColor3f(1.0,0.0,0.0);
	 FillFullRectangle(-200,200,-500,-348);              //lower base of clock
	 LeftFullTriangle(-352,-500,152);
	 RightFullTriangle(352,-500,152);
    glEnd();
    

    
    
    //pendulam making
    if(sin(j)>=0)                  //sine curve alternatively changes with a duration of pi
	{
	 glBegin(GL_POINTS);                                     
	glColor3f(0.0,1.0,1.1);                                   //clockwise path 
    FillFullCircle(400*cos(j),400*sin(-j),60);                //outer rotating large pendulam(light green)
    glEnd();

     glBegin(GL_POINTS);
    glColor3f(0.0,0.0,1.0);
    FillFullCircle(400*cos(j),400*sin(-j),40);                //outer small small pendulam(blue)
    glEnd();
    }
    else
	{
	glBegin(GL_POINTS);
	glColor3f(0.0,1.0,1.1);                                  //anti clockwise path
    FillFullCircle(400*cos(j),400*sin(j),60);                //outer rotating large pendulam
    glEnd();
    
     glBegin(GL_POINTS);
    glColor3f(0.0,0.0,1.0);
    FillFullCircle(400*cos(j),400*sin(j),40);                //outer rotating small pendulam
    glEnd();
    }
    
	
	
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POINTS);                                     //Hands of the clock
	
	DDALine(0,0,200*sin(j/4),200*cos(j/4));         //the algorithm for DDA line is valid only when (x1,y1) is in the left side of (x2,y2)
	DDALine(200*sin(j/4),200*cos(j/4),0,0);
	
	DDALine(0,0,180*sin(j/200 ),180*cos(j/200));
	DDALine(180*sin(j/200 ),180*cos(j/200 ),0,0);
	
	glColor3f(1.0,1.0,1.0);                   //corner design
	MidPointCircle(800,550,100);         
	MidPointCircle(800,550,120);
	MidPointCircle(800,550,140);
	MidPointCircle(800,550,160);
	MidPointCircle(800,550,180);         
	MidPointCircle(800,550,200);
	MidPointCircle(800,550,220);
	MidPointCircle(800,550,240);
	MidPointCircle(800,550,260);
	MidPointCircle(800,550,280);
	
	MidPointCircle(-800,550,100);
	MidPointCircle(-800,550,120);
	MidPointCircle(-800,550,140);
	MidPointCircle(-800,550,160);
	MidPointCircle(-800,550,180);
	MidPointCircle(-800,550,200);
	MidPointCircle(-800,550,220);
	MidPointCircle(-800,550,240);
	MidPointCircle(-800,550,260);
	MidPointCircle(-800,550,280);
	
	MidPointCircle(800,-550,100);         
	MidPointCircle(800,-550,120);
	MidPointCircle(800,-550,140);
	MidPointCircle(800,-550,160);
	MidPointCircle(800,-550,180);         
	MidPointCircle(800,-550,200);
	MidPointCircle(800,-550,220);
	MidPointCircle(800,-550,240);
	MidPointCircle(800,-550,260);
	MidPointCircle(800,-550,280);
	
	MidPointCircle(-800,-550,100);
	MidPointCircle(-800,-550,120);
	MidPointCircle(-800,-550,140);
	MidPointCircle(-800,-550,160);
	MidPointCircle(-800,-550,180);
	MidPointCircle(-800,-550,200);
	MidPointCircle(-800,-550,220);
	MidPointCircle(-800,-550,240);
	MidPointCircle(-800,-550,260);
	MidPointCircle(-800,-550,280);

		glEnd();
		
		

		

	    glFlush();
	}
	
}

void main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	
	glutInitWindowSize(1200,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("CLOCK");
	
	
	myInit();
	glutDisplayFunc(Display);
	
	glutMainLoop();
}
