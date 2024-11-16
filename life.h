
#include <graphics.h>
#include <conio.h>
#include<time.h>
#include<iostream>
#include<math.h>
#include<fstream>
#include <io.h>
#include <fcntl.h>
#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
const int Width = 1280;
const int Height = 720;
#define BEGINSTORY 25
#define Introduce2 23
#define CHAPTERONE_NPC1_ROW 48//以后会改的
#define CHAPTERONE_NPC2_ROW 33
#define CHPTERONE_NPC3_ROW 25
#define CHPTERONE_NPC0_ROW 25
#define BADENDCHAPTER1 17
#define BADENDCHAPTER1_AFTER 2

#define CHAPTER2_WEIQI 10
#define CHAPTER2_ZHUOYOU 7
#define CHAPTER2_YOUYONG 11
#define CHAPTER2_HUIHUA 24
#define CHAPTER2_LIKE 31
#define CHAPTER3_BEGIN 16
#define AFTERSTORY 20
#define FINISH 22
const int MAX_ROWS = 60;  // 最大行数
const int MAX_COLS = 60;  // 最大列数
//TCHAR CHAPTERONE[MAX_ROWS][MAX_COLS]; 定义二维数组
class Role
{
public:
	int x;
	int y;
	IMAGE role;
	IMAGE roleY;
	int rolewidth;
	int roleheight;
	Role(int x, int y) :x(x), y(y) {};
	Role(int a, int b, int c, int d) :x(a), y(b), rolewidth(c), roleheight(d) {};
};

