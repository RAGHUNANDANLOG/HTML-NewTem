#include<stdio.h>
#include <graphics.h>
#include<graphics.h>
#include<dos.h>
void printMsg()
{
	int gdriver = DETECT,gmode,i,g=7;
	clrscr();
	initgraph(&gdriver,&gmode,"C:\\tc\\BGI");
	for (i=7; i<15; i++)
	{
		setcolor(i);
		settextstyle(i,0,4);
		outtextxy(100,20*i,"Project on Hospital Management");
		outtextxy(100,24*i,"In C language");
		delay(800);
	}
	system("cls");
	initgraph(&gdriver,&gmode,"C:\\tc\\BGI");
	setcolor(4);
	settextstyle(g,0,g);
	outtextxy(20,20*g,"+");
	setcolor(g);
	outtextxy(75,20*g,"iBirds Hospital");
	setcolor(4);
	outtextxy(600,20*g,"+");
	settextstyle(g,0,2);
	setcolor(3);
	outtextxy(430,52*g,"by...");
	setcolor(6);
	outtextxy(460,55*g,"Bhavya Goyal...*");
	outtextxy(495,57.6*g,"&");
	outtextxy(460,60*g,"Nizaam Uddin...*");
	getch();
}
