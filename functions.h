#include <graphics.h>
#include <conio.h>
#include<stdio.h>
#include<time.h>
#include<iostream>
#include<math.h>

void PlayHitSound();
using namespace std;
const int WIDTH = 600;
const int HEIGHT = 600;
#define BLOCKNUMBERS 200
#define DOWN 60//所有的y+60
#define FORWARD 340//所有的X+340
double Distance(double x1, double y1, double x2, double y2);
class Rectanglecontrol {
public:
	int left;
	int top;
	int right;
	int bottom;
	int dx;//横坐标增量
	Rectanglecontrol(int a, int b, int c, int d,int e) :left(a), top(b), right(c), bottom(d),dx(e) {};
	Rectanglecontrol(){};
};
class Ball {
public:
	int x;
	int y;
	int r;
	int dx;
	int dy;
	COLORREF color;
	Ball(int a, int b, int c, int d,COLORREF e,int f) :x(a), y(b), dx(c), dy(d),color(e),r(f) {};
	Ball() {};
	void Move() {
		x += dx;
		y += dy;
	}
	void Bounce(Rectanglecontrol& rect) {
		if (x - r <= FORWARD || x + r >= WIDTH+FORWARD) {
			dx = -dx;
			Move();
		}
		if (y - r <= 0+DOWN ) {
			dy = -dy;
			Move();
		}
		//cout << rect.left << rect.top << rect.right << rect.bottom << endl;
		if (x >= rect.left&& x<= rect.right&& y+r >= rect.top&&y+r<=rect.bottom)//碰到了顶部
		{
			dy = -dy;
			PlayHitSound();
			Move();
		}
		if (x >= rect.left&& x <= rect.right&&y - r <= rect.bottom&&y-r>=rect.top)//碰到了底部
		{
			dy = -dy;
			PlayHitSound();
			Move();
		}
		if (y >= rect.top && y <= rect.bottom&& x + r >= rect.left&&x+r<=rect.right)
		{
			dx = -dx;
			PlayHitSound();
			Move();
		}
		if (y >= rect.top && y <= rect.bottom&& x - r <= rect.right&&x-r>=rect.left)
		{
			dx = -dx;
			PlayHitSound();
			Move();
		}
		if (Distance(rect.left, rect.top, x, y) - r < 0.5)
		{
			dx = -dx;
			dy = -dy;
			PlayHitSound();
			Move();
		}
		if (Distance(rect.right, rect.top, x, y) - r < 0.5)
		{
			dx = -dx;
			dy = -dy;
			PlayHitSound();
			Move();
		}
		if (Distance(rect.left, rect.bottom, x, y) - r < 0.5)
		{
			dx = -dx;
			dy = -dy;
			PlayHitSound();
			Move();
		}
		if (Distance(rect.right, rect.bottom, x, y) - r < 0.5)
		{
			dx = -dx;
			dy = -dy;
			PlayHitSound();
			Move();
		}

	}
};
class block
{
public:
	int type;//0 则 empty 1则可消灭实体 2则不可消灭实体
	int x;
	int y;
	COLORREF color;
	int left;
	int top;
	int right;
	int buttom;
	/*block(int type, COLORREF c, int left, int top, int right, int buttom) :type(type), color(c), left(left), top(top), right(right), buttom(buttom) {};
	block();*/
	block(){type = 1; };
};
void drawcontrolrectangle(Rectanglecontrol& a,int key);
void Autoball(Ball& a, Rectanglecontrol& b);
void Blockbreak( int numbers,block BLL[200], Ball &ball);
void initialcontrolrectangle(Rectanglecontrol& rect);
void balldisplay(int &numbers);
void balldecrese(Ball& a, int &numbers, int &minflag,Rectanglecontrol &rect);
void Ball_Return(Ball& a, Rectanglecontrol& rect);
void gamefailuredetect(bool& gameflag,int &ballnumbers,bool &continuegame);
void gamesuccessdetect(bool& gameflag, bool& continuegame,block BLL[],int blocknumbers);
void Rectanglecenter_fourcourner(int numbers,block BLL[200]);
void BLOCKLEVEL_1(block BLL[200]);
void PlayHitSound();
void Initializeball();
void playgame();


