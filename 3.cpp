#include<GL/glut.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include <stdlib.h>
void initfun();
void draw(void);

void writing(int a,int b);

void color_menu(int ch);
void display();
void display1(void);
void redisplay(void);
void mouse(int b,int s,int x,int y);
void keyboard(unsigned char key,int x,int y);
void keyboard1(unsigned char key,int x,int y);
void keyboard2(unsigned char key,int x,int y);
void Write(double x,double y,double z,double scale,char *s);
void enter();
 
GLfloat scanArray[100][2];
int count=0,i,j,num=0,FLAG=1;
int conMatrix[10][10],conMatrix1[10][10];
int xx,yy;
char str2[100];
char cmpstr[200][200];
char number[100]={"123456789"};

int parent[10],min,ne=1,minconMatrix=0,spacecount=0;
int array[10][3];
int count1=0;
 int a,b,u,v;
int win1,win2;

//----------------------------


void initfun()
{
glClearColor(1.0,0.0,0.0,1.0);
}

void draw(void)
{
	glPointSize(40.0);
	glBegin(GL_POINTS);
	for(i=0;i<num;i++)
	{
	glVertex3f(scanArray[i][0],scanArray[i][1],0);
	}
	glEnd();
	glFlush();
	
	for(i=0;i<num;i++)
	{
		glColor3f(0.0,1.0,0.0); 
	glRasterPos2f(scanArray[i][0]-10,scanArray[i][1]+40);
	
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,number[i]);
	
	}
	

if(count>=num)
{
	glLineWidth(10.0);
	glBegin(GL_LINES);
	for(i=0;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
		if(conMatrix1[i][j]!=99)
			{
				glColor3f(0.5,0.5,0.5); 
				glVertex3f(scanArray[i][0],scanArray[i][1],0);
				glVertex3f(scanArray[j][0],scanArray[j][1],0);
//					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str2[i]);
		//		glFlush();
			}
		}
	}
	
	glEnd();
}
for(i=0;i<num;i++)
	{
		glColor3f(1.0,0.0,0.0); 
	glRasterPos2f(scanArray[i][0]-10,scanArray[i][0]);
	//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str2[i]);

	//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,number[i]);
	
	}
	

	glPopMatrix();
glutSwapBuffers();
glFlush();	
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D (0.0,1024.0,0.0,768.0);
	glColor3f(0.0,1.0,0.0);
	draw();
	//Write(-1.0,-0.5,0.0,0.0004,"   EDGE");
		   //writing(a,b);
}

void display1(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	Write(-0.4,0.80,0.0,0.0007,"ABOUT DFS");
	Write(-1.0,0.50,0.0,0.0005,"DEPTH FIRST SEARCH");
	Write(-1.0,0.40,0.0,0.0005," It is alorithm for traversing ");
	Write(-1.0,0.30,0.0,0.0005,"  a tree data structure.");
	Write(-1.0,0.20,0.0,0.0005,"It was first invented in 1950");
	Write(-1.0,0.10,0.0,0.0005," by E.F.Moore");
	Write(-1.0,0.00,0.0,0.0005," Enter the no of nodes in a graph");
	Write(-1.0,-0.10,0.0,0.0005," and adjacency matrix");
	Write(-1.0,-0.20,0.0,0.0005," and adjacency matrix");
	Write(-0.6,-0.80,0.0,0.0008," Press 'T' or 't' to continue");
	glFlush();
}



void display2(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	Write(-0.4,0.80,0.0,0.0007,str2);
	
	glFlush();
}
void redisplay(void)
{
	const char text[] = "This is some text";
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
		Write(-1.0,0.75,0.0,0.0007,"SAMBHRAM INSTITUTE OF TECHNOLOGY");
	Write(-0.55,0.60,0.0,0.0007,"Depth First Search");
	Write(-1.0,0.2,0.0,0.0006,"  Submitted By:");
	Write(-1.0,0.1,0.0,0.0006,"  Banupraksh K C(1ST13CS712)");
	Write(-1.0,0.0,0.0,0.0006,"  Farooqui Mohammed (1ST13CS718)");
	Write(-1.0,-0.1,0.0,0.0006,"  SAIT");
	Write(-1.0,-0.3,0.0,0.0006,"  Under the Guidance of:");
	Write(-1.0,-0.4,0.0,0.0006,"  Mr.Srinath K.S");
	Write(-1.0,-0.5,0.0,0.0004,"   B.E.,M.Tech.");
	Write(-0.8,-0.8,0.0,0.0008,"  Press 'R' or 'r' to continue");
glFlush();
}

float clr=4,clr2=4;
void mouse(int b,int s,int x,int y)
{
	
	if(b==GLUT_LEFT_BUTTON && s==GLUT_DOWN && count<num)
	{
		scanArray[count][0]=x;
		scanArray[count][1]=768-y;
	 	count++;
//	 	clr++;
	// 	clr2=clr2+3;
	 	glClearColor (clr2, clr, 0.0,0.0);
	}
	//if(b==GLUT_RIGHT_BUTTON&&s==GLUT_DOWN)
	//{
		//gl
	glutPostRedisplay();
}

void keyboard(unsigned char key,int x,int y)
{
if(key==' '&&spacecount<count)
	spacecount+=1;
	glutPostRedisplay();
}

void keyboard1(unsigned char key,int x,int y)
{
if(key=='c'||key=='c')
	glutDestroyWindow(win1);
	win2=glutCreateWindow("intermediate");
	glutDisplayFunc(display1);
	glutKeyboardFunc(keyboard2);
}

void keyboard2(unsigned char key,int x,int y)
{
	if(key=='p' || key=='P' )
	glutDestroyWindow(win2);
	glClearColor(1.0,0.0,0.0,1.0);
	glutCreateWindow("example");
	
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	enter();
	
	
}

void Write(double x,double y,double z,double scale,char *s)
{
   int i,l=strlen(s);
   glPushMatrix();
   glTranslatef(x,y,z);
   glScalef(scale,scale,scale);
     for (i=0;i <l;i++)
   glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
   glPopMatrix();
}
void enter()
{
	glClearColor(1.0,0.0,0.0,1.0);
	glutCreateWindow("DFS");
	glClearColor(1.0,0.0,0.0,1.0);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard1);
	glutMouseFunc(mouse);
	//initRendering();
//glutDisplayFunc(drawScene);
//glutKeyboardFunc(handleKeypress);
//glutReshapeFunc(handleResize);
//glutTimerFunc(25,update,0);

	std::cout<<"enter the no. of nodes\n";
	std::cin>>num;
	std::cout<<"enter the adjacency matrix\n";
	for(i=0;i<num;i++)
	  for(j=0;j<num;j++)
	  {
	      std::cin>>conMatrix[i][j];
	      if(conMatrix[i][j]==0)
		 conMatrix[i][j]=99;
		  conMatrix1[i][j]=conMatrix[i][j];
	   }

	std::cout<<"Edges of minimum spanning tree are:\n";
	while(ne<num)
	{
	   for(i=0,min=99;i<num;i++)
	      for(j=0;j<num;j++)
		if(conMatrix[i][j]<min)
		 {
		    min=conMatrix[i][j];
		    a=u=i;
		    b=v=j;
		 }

		 while(parent[u])
		    u=parent[u];
		 while(parent[v])
		    v=parent[u];

	   if(u!=v)
	   {
		  std::cout<<ne++<<"\t Edge "<<"("<<a<<","<<b<<")="<<min;
		   array[count1][0]=a;
		   array[count1][1]=b;
		   
		   minconMatrix+=min;
	       parent[v]=u;
		   count1++;
	   }
	   conMatrix[a][b]=conMatrix[b][a]=99;
	}
}


/*void enter(){
char str3[20];
	glutCreateWindow("DFS");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard1);
	glutMouseFunc(mouse);
	std::cout<<"enter the no. of nodes\n";
	std::cin>>num;
	std::cout<<"enter the adjacency matrix\n";
	for(i=0;i<num;i++)
	  for(j=0;j<num;j++)
	  {
	      std::cin>>conMatrix[i][j];
	      if(conMatrix[i][j]==0)
		 conMatrix[i][j]=99;
		  conMatrix1[i][j]=conMatrix[i][j];
	   }

	std::cout<<"Edges of minimum spanning tree are:\n";
	while(ne<num)
	{
	   for(i=0,min=99;i<num;i++)
	      for(j=0;j<num;j++)
		if(conMatrix[i][j]<min)
		 {
		    min=conMatrix[i][j];
		    a=u=i;
		    b=v=j;
		 }
		 while(parent[u])
		    u=parent[u];
		 while(parent[v])
		 
		    v=parent[u];
	   if(u!=v)
	   {
		  std::cout<<ne++<<"\t Edge "<<"("<<a<<","<<b<<")="<<min;
		   array[count1][0]=a;
		   array[count1][1]=b;
		   minconMatrix+=min;
	       parent[v]=u;
		   count1++;
		/*   sprintf(str3, "%d", a);
		   strcpy(str2,"edge (");
		   strcat(str2,str3);
		   strcat(str2,",");
		   sprintf(str3, "%d", b);
		   strcat(str2,str3);
		   strcat(str2,")");
		   strcat(str2,"=");
		   sprintf(str3, "%d", min);
		   strcat(str2,str3);
		   strcat(str2,"\n\n");
		   		for(int row=0; row < 10; row++)
      {
            for(int column=0;column < strlen(str2); column++)
            {
               cmpstr[row][column] = str2[row];
              
            }
        }*/
		   
	   
   
   //	for(int row=0; row < 10; row++)
     // {
       //     for(int column=0;column < strlen(str2); column++)
         //   {
    
	   //std::cout<<cmpstr[row][column];
   //}}
	 //  conMatrix[a][b]=conMatrix[b][a]=99;
	
	//}
//	glutCreateWindow("result");
	//glutDisplayFunc(display2);
	//glutKeyboardFunc(keyboard);

           //writing(a,b);
	




void writing(int a,int b)
{ 
	

		   
}
void init(){
	glClearColor(1.0,1.0,0.0,1.0);
}
using namespace std;

int main(int argc,char **argv) 
{	
	glutInit(&argc,argv);    // had not put
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	init();
	glutInitWindowSize(1000, 700);
	glutInitWindowPosition(0.0,0.0);
	win1=glutCreateWindow("introduction");
	glClearColor(1.0,0.0,0.0,1.0);
	glutDisplayFunc(redisplay);
	glutKeyboardFunc(keyboard1);
	init();
	glutMainLoop();
	return 0;
}


