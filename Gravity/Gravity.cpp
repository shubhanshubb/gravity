// Gravity.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

#include<stdlib.h> 
#include <glut.h>
#include <vector>
#include <cmath>
#define M_PI 3.14
struct Particle {
	float x;
	float y;
	float r;
	float vx;
	float vy;
	float m;
	float color[3];
};
void timer(int = 0);
void display();
void mouse(int, int, int, int);
void mouseMotion(int, int);
void addParticle(float, float, bool = true, float = 0, float = 0);
void removeParticles();
void keyboard(unsigned char, int, int);
int Mx, My;
float m=0.0;
int t;
bool PRESSED_LEFT = false, PRESSED_RIGHT = false,
PRESSED_MIDDLE = false, SPEED_PARTICLES = false;

std::vector<Particle> particles;

void drawCircle(float x1,float y1, double radius)
{
    float x2,y2;
	float angle;
	glPointSize(1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1,y1);
	for (angle=0.0f;angle<=3*3.14159f;angle+=0.2)
	{
		x2 = x1+sin(angle)*radius;
		y2 = y1+cos(angle)*radius;
		glVertex2f(x2,y2);
	}
	glEnd();
	
}
void draw_pixel(GLint cx, GLint cy)
{
	
	glBegin(GL_POINTS);
	glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}


void draw()
{
	int l;
	////////////////////////////////////////////////////////////////////////////////////////////////
	//sky
	if(t==0)
	{	glBegin(GL_POLYGON);
	glColor3f(0,0.6,0.8);
	glVertex2f(-500,0);
	glVertex2f(0,-500);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(500,0);
	glVertex2f(0,500);
	glEnd();
	
	//sun
	
	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,0.9,0.0);
		drawCircle(-150,-125,l);
	}
	}
	else if(t==1)
	{  
		//sky
		//glColor3f(2,0.425,0.2);
		glBegin(GL_POLYGON);
		
		glColor3f(2,0.325,0.2);
		glVertex2f(-500,0);
		glVertex2f(0,-500);
		
		
		glColor3f(1.0,1.4,0);
		glVertex2f(500,0);
		glVertex2f(0,500);
		
		glEnd();
		
		
		
		
		//sun
		
		for(l=0;l<=35;l++)
		{
			glColor3f(1.0,0.2,0.0);
			drawCircle(170,-125,l);
			
		} 
	}
	else if(t==2)
	{
		glColor3f(0.0,0.0,0.0);
		glVertex2f(-500,0);
		glVertex2f(0,-500);
		
		
		glColor3f(0.0,0.0,0.0);
		glVertex2f(500,0);
		glVertex2f(0,500);
		// moon
		
		for(l=0;l<=35;l++)
		{
			glColor3f(1.0,1.0,1.0);
			drawCircle(170,-125,l);
			
		} 
	}
}
void man()
{    draw();

//glColor3f(.5,.6,0.0);
glColor3ub(255,191,128);
drawCircle(0,0,25);//face
//	glColor3f(0.0,0.0,1.0);
glColor3ub(55,50,70);
glBegin(GL_POLYGON);//shirt
glVertex2i(-17.5,25);
glVertex2i(-50,50);
glVertex2i(-37.5,65);
glVertex2i(-25,60.0);
glVertex2i(-25.0,87.5);
glVertex2i(25.0,87.5);
glVertex2i(25.0,60.0);
glVertex2i(37.5,65);
glVertex2i(50,50);
glVertex2i(17.5,25);
glEnd();
glColor3ub(10,120,130);//belt
glBegin(GL_POLYGON);
glVertex2i(-25.0,87.5);
glVertex2i(25.0,87.5);
glVertex2i(25.0,100);
glVertex2i(-25.0,100);
glEnd();
glColor3ub(100,140,10);
glBegin(GL_POLYGON);// pant
glVertex2f(25.0,100);
glVertex2f(-25.0,100);
glVertex2f(-37.5,175);
glVertex2f(-12.5,175);
glVertex2f(-5,137.5);
glVertex2f(12.5,175);
glVertex2f(37.5,175);
glEnd();
glColor3ub(200,140,110);
glBegin(GL_POLYGON);//colar
glVertex2f(-17.5,25);
glVertex2f(17.5,25);
glVertex2f(12.5,50);
glVertex2f(-12.5,50);
glEnd();
glColor3ub(20,140,110);
glBegin(GL_POLYGON);//small colar
glVertex2f(-12.5,50);
glVertex2f(12.5,50);
glVertex2f(0,32.5);
glEnd();
glColor3f(0.0,0.0,0.0);
glPointSize(3.0);
glBegin(GL_POINTS);//eyes
glVertex2i(10,-4);
glVertex2i(-10,-4);
glEnd();
glBegin(GL_LINES);//eyebrows right
glVertex2i(-5,-9);
glVertex2i(-14,-9);
glEnd();
glBegin(GL_LINES);//eyebrows right
glVertex2i(5,-9);
glVertex2i(14,-9);
glEnd();
glBegin(GL_LINES);//nose
glVertex2i(1,0);
glVertex2i(1,6);
glEnd();
glBegin(GL_LINES);//mouth
glVertex2i(5,14);
glVertex2i(-5,14);
glEnd();
glColor3f(0.0,0.0,0.0);
glPointSize(3.0);
glBegin(GL_POINTS);//buttons
glVertex2i(1,55);
glVertex2i(1,65);
glVertex2i(1,75);
glVertex2i(1,85);
glEnd();
glBegin(GL_LINE_LOOP);//belt buckle
glVertex2f(10,87.5);
glVertex2f(-10,87.5);
glVertex2f(-10,100);
glVertex2f(10,100);
glEnd();
glColor3f(0.0,1.0,1.0);
glBegin(GL_LINES);//belt buckle inner line
glVertex2f(-10,98);
glVertex2f(10,89.5);
glEnd();
glBegin(GL_LINES);//belt buckle inner line
glVertex2f(10,98);
glVertex2f(-10,89.5);
glEnd(); 
}

void menu(int id)
{
	switch(id)
	{
	case 1: t=0;
		break;
	case 2: t=1;
		break;
	case 3: t=2;
		break;
    case 4: exit(0);
		break;
	}
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
	
} 
int main(int argc, char **argv)
{
	Particle p1,p2;
	//initial centered Huge mass particle
	p1.x =55;
	p1.y =66 ;
	p1.vx = 0;
	p1.vy = 0;
	p1.m = 10000;
	p1.r = 14;
	p1.color[0] = 1;
	p1.color[1] = 0.8;
	p1.color[2] = 0.5;
	particles.push_back(p1);
	p2.x =-55;
	p2.y = 66;
	p2.vx =0;
	p2.vy = 0;
	p2.m = 10000;
	p2.r = 14;
	p2.color[0] = 1;
	p2.color[1] = 0.8;
	p2.color[2] = 0.5;
	particles.push_back(p2);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Gravity");
	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-250.0,250.0, 250.0, -250.0, 0, 1);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	timer();
    glutCreateMenu(menu);
	glutAddMenuEntry("Dawn",1);
	glutAddMenuEntry("Dusk",2);
	glutAddMenuEntry("Night",3);
	glutAddMenuEntry("Exit",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON); 
	glutMainLoop();
	return 0;
}

void timer(int)
{
	display();
	if(PRESSED_LEFT && !SPEED_PARTICLES)
	{
		addParticle(10, 3); //add tiny particle
		PRESSED_LEFT = false;
	}
	for(int i = 0; i < particles.size(); i++)
	{
		Particle &p = particles[i];
		bool not_fall = true;
		for(int j = 0; j < particles.size(); j++)
		{
			if(j == i || p.m >= 10000) // we consider the 10000 as infinit (big mass) so this particles won't move
				continue; 
			
			const Particle &p1 = particles[j];
			
			float d = sqrt((p1.x - p.x)*(p1.x - p.x) + (p1.y - p.y)*(p1.y - p.y));
			
			if(d > p1.r)
			{
				p.vx += 0.03 * p1.m / (d*d) * (p1.x - p.x)/d; //f = ma => a = f/m
				p.vy += 0.03 * p1.m / (d*d) * (p1.y - p.y)/d;
			}
			else
				not_fall = false;
		}
		
		if(not_fall)	
		{
			p.x += p.vx;
			p.y += p.vy;
		}
		else
			particles.erase(particles.begin()+i);
	}
	
	glutTimerFunc(1, timer, 0);
}

void display()
{
	float a;
	glClear(GL_COLOR_BUFFER_BIT);
	man(); 
	//draw particles
	for(int i = 0; i < particles.size(); i++)
	{
		Particle &p = particles[i];
		glColor3f(p.color[0], p.color[1], p.color[2]);
		glBegin(GL_POLYGON);
		for( a = 0; a < 2*M_PI; a+=0.2)
			glVertex2f(p.r*cos(a) + p.x, p.r*sin(a) + p.y);
		glEnd(); 
	} 
	glFlush();
	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y)
{
	//set the coordinates
	Mx = x-250;
	My = y-250;
	//check which button is pressed
	if(button == GLUT_LEFT_BUTTON)
		PRESSED_LEFT = state == GLUT_DOWN;
	else if(button == GLUT_RIGHT_BUTTON)
		PRESSED_RIGHT = state == GLUT_DOWN;
	else if(button == GLUT_MIDDLE_BUTTON)
		PRESSED_MIDDLE = state == GLUT_DOWN;
}

void addParticle(float m, float r, bool randColor, float vx, float vy)
{
	Particle p;
	p.x = Mx;
	p.y = My;
	p.vx = vx / 30; // /30 in case it is a speed particle,
	p.vy = vy / 30; // slow down the speed a little
	p.m = m;
	p.r = r;
	if(randColor)
	{
		p.color[0] = rand()%200 / 200.0;
		p.color[1] = rand()%200 / 200.0;
		p.color[2] = rand()%200 / 200.0;
	}
	particles.push_back(p);	
}
