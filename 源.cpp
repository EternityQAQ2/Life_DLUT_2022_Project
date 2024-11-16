#include "life.h"
#include "functions.h"
//1280 *720
IMAGE background, role, roleY;
IMAGE YES, SET;
int imageNum = 0;
Role NPC_1(300, 300);
Role Myself(600, 500, 64, 64);
Role Myself_panel(1090, 590, 120, 120);
Role NPC_1_panel(80, 600, 90, 90);
Role NPC_MENGLIN(500, 300, 32, 48);
Role NPC_MENGLIN_PANEL(30, 578, 150, 132);
Role NPC_LIKE(750, 500, 32, 48);
Role NPC_LIKE_PANEL(30, 560, 150, 150);
Role Chuansongzhen(770, 150, 220, 220);
Role NPC_0(80, 590, 120, 120);
//CHAPTER 2
Role WEIQI(560, 390, 48, 60);
Role WEIQI_PANEL(30, 560, 150, 150);
Role ZHUOYOU(560, 240, 48, 60);
Role ZHUOYOU_PANEL(30, 566, 150, 144);
Role YOUYONG(750, 525, 48, 60);
Role YOUYONG_PANEL(30, 560, 150, 150);
Role HUIHUA(950, 525, 48, 60);
Role HUIHUA_PANEL(20, 555, 160, 155);
Role CAIDAN(810, 425, 32, 48);
Role CAIDAN_PANEL(20, 560, 150, 150);
IMAGE bk2;
IMAGE BK3;
Role YUEYUE_PANEL(20, 560, 150, 150);
Role QIYANA_PANEL(20, 560, 150, 150);
Role TONGREN(1090, 560, 150, 150);
char TOCHAPTERTWO[3] = { 0 };
char TOCHAPTERTHREE[4] = { 0 };
void Initialize()
{
	cleardevice();
	//对弹珠游戏进行书写
	putimage(40, 40, &YES);
	IMAGE set;
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy_s(f.lfFaceName, _T("Arial"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	TCHAR S[20] = L"选择";
	int h = textheight(S);
	int w = textwidth(S);
	outtextxy(Width / 2 - w / 2, Height / 4 - h / 2, S);

	//画开始摁妞
	setlinestyle(PS_SOLID, 2);
	setlinecolor(WHITE);
	rectangle(Width / 2 - 75, Height / 2 + 50, Width / 2 + 75, Height / 2 + 100);
	TCHAR SS[20] = L"开始游戏";
	settextstyle(24, 0, _T("Consolas"));
	setbkmode(TRANSPARENT);
	outtextxy(Width / 2 - textwidth(SS) / 2, Height / 2 + 75 - textheight(SS) / 2, SS);
	//退出游戏摁妞
	setlinestyle(PS_SOLID, 2);
	setlinecolor(WHITE);
	rectangle(Width / 2 - 75, Height / 2 + 150, Width / 2 + 75, Height / 2 + 200);
	TCHAR SSS[20] = L"关闭游戏";
	settextstyle(24, 0, _T("Consolas"));
	setbkmode(TRANSPARENT);
	outtextxy(Width / 2 - textwidth(SSS) / 2, Height / 2 + 175 - textheight(SSS) / 2, SSS);

	setlinestyle(PS_SOLID, 2);
	setlinecolor(CYAN);
	rectangle(20, 670, 50, 700);
	settextstyle(12, 0, _T("Consolas"));
	TCHAR SSSS[20] = L"设置";
	outtextxy(35 - textwidth(SSSS) / 2, 685 - textheight(SSSS), SSSS);
}
void Initialize_chapter2()
{
	loadimage(&bk2, _T("res\\BK2_2.png"));

	Myself.x = 450;
	Myself.y = 550;
	putimage(0, 0, &bk2);
	//放置围棋组
	putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
	putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
	//放置桌游组
	putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
	putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
	//放置游泳组
	putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
	putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
	//放置绘画组
	putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
	putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
	//放置自己
	putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
	putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
}
double Distance(int x1, int y1, int x2, int y2)
{
	return sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
}

void keyDonw()
{
	char choice = _getch();
	switch (choice)
	{
	case 'w':
	case 'W':
	case 72:
		putimage(0, 0, &background);

		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
		//加载莉可
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//传送法阵
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 192, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 192, SRCPAINT);

		imageNum++;
		if (Myself.y > 0) Myself.y -= 10;//别撞头
		if (imageNum == 3) imageNum = 0;
		break;
	case 's':
	case 'S':
	case 80:
		putimage(0, 0, &background);

		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
		//加载莉可
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//传送法阵
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 0, SRCPAINT);


		imageNum++;
		if (Myself.y + Myself.roleheight <= 720)Myself.y += 10;//别撞南墙
		if (imageNum == 3)
			imageNum = 0;
		break;
	case 'a':
	case 'A':
	case 75:
		putimage(0, 0, &background);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
		//梦林加载
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
		//加载莉可
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//传送法阵
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 64, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 64, SRCPAINT);


		imageNum++;
		if (Myself.x >= 0) Myself.x -= 10;
		if (imageNum == 3)
			imageNum = 0;
		break;
	case 'd':
	case 'D':
	case 77:
		putimage(0, 0, &background);

		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
		//梦林加载
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
		//加载莉可
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//传送法阵
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 128, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 128, SRCPAINT);
		imageNum++;
		if (Myself.x + Myself.rolewidth <= 1280) Myself.x += 10;
		if (imageNum == 3)
			imageNum = 0;
		break;
	}
}
void keyDonw_Chapter2()
{
	char choice = _getch();
	switch (choice)
	{
	case 'w':
	case 'W':
	case 72:
		putimage(0, 0, &bk2);
		//放置围棋组
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//放置桌游组
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//放置游泳组
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//放置绘画组
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 192, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 192, SRCPAINT);
		imageNum++;
		if (Myself.y > 0) Myself.y -= 10;//别撞头
		if (imageNum == 3) imageNum = 0;
		break;

	case 's':
	case 'S':
	case 80:
		putimage(0, 0, &bk2);
		//放置围棋组
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//放置桌游组
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//放置游泳组
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//放置绘画组
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 0, SRCPAINT);
		imageNum++;
		if (Myself.y + Myself.roleheight <= 720)Myself.y += 10;//别撞南墙
		if (imageNum == 3)
			imageNum = 0;
		break;
	case 'a':
	case 'A':
	case 75:
		putimage(0, 0, &bk2);
		//放置围棋组
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//放置桌游组
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//放置游泳组
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//放置绘画组
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 64, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 64, SRCPAINT);
		imageNum++;
		if (Myself.x >= 0) Myself.x -= 10;
		if (imageNum == 3)
			imageNum = 0;
		break;
	case 'd':
	case 'D':
	case 77:
		putimage(0, 0, &bk2);
		//放置围棋组
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//放置桌游组
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//放置游泳组
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//放置绘画组
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 128, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 128, SRCPAINT);
		imageNum++;
		if (Myself.x + Myself.rolewidth <= 1280) Myself.x += 10;
		if (imageNum == 3)
			imageNum = 0;
		break;
	}

}
void dialogetishi(Role user1)
{
	TCHAR TISHI[30] = _T("PRESS SPACE TO TALK");
	int kuan = textwidth(TISHI);
	int gao = textheight(TISHI);
	settextstyle(18, 0, _T("Consolas"));
	if (Distance(user1.x + user1.rolewidth / 2, user1.y + user1.roleheight / 2, Myself.x + Myself.rolewidth / 2, Myself.y + Myself.roleheight / 2) <= 80)
	{
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		outtextxy(640 - kuan / 2, 640, TISHI);
	}
}
void Chuansongmentishi(Role user1)
{
	TCHAR TISHI[70] = _T("PRESS SPACE TO GO TO THE NEXT CHAPTER AFTER YOU FINISH THE CHAPTER");
	int kuan = textwidth(TISHI);
	int gao = textheight(TISHI);
	settextstyle(18, 0, _T("Consolas"));
	if (Distance(user1.x + user1.rolewidth / 2, user1.y + user1.roleheight / 2, Myself.x + Myself.rolewidth / 2, Myself.y + Myself.roleheight / 2) <= 80)
	{
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		outtextxy(640 - kuan / 2, 640, TISHI);
	}
}
void INTRODUCESTRORY()
{
	IMAGE bk0;
	loadimage(&bk0, _T("res\\SCHOOL1280.jpg"));
	putimage(0, 0, &bk0);
	TCHAR** CHAPTERONE = new TCHAR * [MAX_ROWS];
	for (int i = 0; i < MAX_ROWS; i++) {
		CHAPTERONE[i] = new TCHAR[MAX_COLS];
	}


	FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
	errno_t err = _tfopen_s(&file, _T("res\\story\\Introduce.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
	if (file == NULL) {
		// 处理文件打开失败的情况
		return;
	}
	int rowIndex = 0;
	while (_fgetts(CHAPTERONE[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
		rowIndex++;
		if (rowIndex >= MAX_ROWS) {
			// 处理数组内存溢出的情况
			break;
		}
	}
	fclose(file);
	rowIndex = 0;
	settextstyle(22, 0, _T("宋体"), 0, 0, 700, false, false, false);
	bool onechancetouse = true;
	while (rowIndex < BEGINSTORY)//需要改 目前是6
	{
		//对话框大小及位置
		setlinecolor(BLACK);
		rectangle(200, 600, 1080, 700);
		settextcolor(LIGHTRED);
		setbkmode(TRANSPARENT);

		outtextxy(210, 640, CHAPTERONE[rowIndex] + 1);
		if (CHAPTERONE[rowIndex][0] == '1' && onechancetouse)
		{
			putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
			putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
			onechancetouse = false;
		}
		int CHANCE = 0;
		if (int CHANCE = _getch())
		{
			if (CHANCE == 32)
			{
				cleardevice();//这里是清除之前的矩形框。主打的就是懒。
				rowIndex++;
				putimage(0, 0, &bk0);
				if (CHAPTERONE[rowIndex][0] == '1')//如果是1则是我
				{
					//这里有问题，图片的问题，至少是白底黑掩码图才对。代码先写着，等着换元。
					putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
					putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
				}
			}
		}


	}

}
void dialogewithNPC1(char choice)
{
	//bool restart_flag = true;
	if (choice == 32 && Distance(NPC_1.x + NPC_1.rolewidth / 2, NPC_1.y + NPC_1.roleheight / 2, Myself.x + Myself.rolewidth / 2, Myself.y + Myself.roleheight / 2) <= 80)
	{
		//这里的IF语句是进入对话。
		TCHAR** CHAPTERONE = new TCHAR * [MAX_ROWS];
		for (int i = 0; i < MAX_ROWS; i++) {
			CHAPTERONE[i] = new TCHAR[MAX_COLS];
		}
		settextstyle(24, 0, _T("宋体"));
		//这是在清除 press space to talk
		cleardevice();
		putimage(0, 0, &background);

		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
		//梦林加载
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
		//莉可加载
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//传送法阵
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);

		TOCHAPTERTWO[0] = 'A';

		_setmode(_fileno(stdout), _O_U8TEXT);  // 设置控制台输出为UTF-8编码

		FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
		errno_t err = _tfopen_s(&file, _T("res\\story\\NPC1-CHAPTER1.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
		if (file == NULL) {
			// 处理文件打开失败的情况
			return;
		}
		int rowIndex = 0;
		while (_fgetts(CHAPTERONE[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
			rowIndex++;
			if (rowIndex >= MAX_ROWS) {
				// 处理数组内存溢出的情况
				break;
			}
		}
		fclose(file);
		//检测文本的函数，以后删掉。
		//for (int i = 0; i < rowIndex; i++) {
		//	_tprintf(_T("%s"), CHAPTERONE[i]);
		//}


		//对话循环
		rowIndex = 0;
		bool onechancetouse = true;
		while (rowIndex < CHAPTERONE_NPC1_ROW)//需要改 目前是6
		{
			//对话框大小及位置
			setlinecolor(WHITE);
			rectangle(200, 600, 1080, 700);
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			outtextxy(210, 640, CHAPTERONE[rowIndex] + 1);
			//这里因为我提前把矩形框位围出来了，所以图片也必须提前，但是是一次性的，感觉不是很好看（代码），因此期望以后优化。
			if (CHAPTERONE[rowIndex][0] == '1' && onechancetouse)
			{
				putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
				putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
				onechancetouse = false;
			}
			else if (CHAPTERONE[rowIndex][0] == '2' && onechancetouse)
			{
				putimage(NPC_1_panel.x, NPC_1_panel.y, NPC_1_panel.rolewidth, NPC_1_panel.roleheight, &NPC_1_panel.roleY, 0, 0, SRCAND);
				putimage(NPC_1_panel.x, NPC_1_panel.y, NPC_1_panel.rolewidth, NPC_1_panel.roleheight, &NPC_1_panel.role, 0, 0, SRCPAINT);
				onechancetouse = false;
			}
			int CHANCE = 0;
			if (int CHANCE = _getch())
			{
				if (CHANCE == 32)
				{
					//即使退出了循环也能初始化场景。
					cleardevice();//这里是清除之前的矩形框。主打的就是懒。
					putimage(0, 0, &background);
					//放角色
					putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
					putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
					//梦林加载
					putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
					putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
					//莉可加载
					putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
					putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
					//传送法阵
					putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
					putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);

					//这么重要的东西放在这？？？
					rowIndex++;
					//这么重要的东西放在这？？？
					//说明一下，因为已经清屏，所以，这里的图片先载入没什么问题。
					if (CHAPTERONE[rowIndex][0] == '1')//如果是1则是我
					{
						//这里有问题，图片的问题，至少是白底黑掩码图才对。代码先写着，等着换元。
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
					}
					else if (CHAPTERONE[rowIndex][0] == '2')
					{
						putimage(NPC_1_panel.x, NPC_1_panel.y, NPC_1_panel.rolewidth, NPC_1_panel.roleheight, &NPC_1_panel.roleY, 0, 0, SRCAND);
						putimage(NPC_1_panel.x, NPC_1_panel.y, NPC_1_panel.rolewidth, NPC_1_panel.roleheight, &NPC_1_panel.role, 0, 0, SRCPAINT);
					}



				}
			}
		}


		//释放内存代码
		for (int i = 0; i < MAX_ROWS; i++) {
			delete[] CHAPTERONE[i];
		}
		delete[] CHAPTERONE;


	}

}
void dialogewithNPC2(char choice)
{
	bool whototalk = false;//false 是主人公。
	bool restart_flag = true;
	if (choice == 32 && Distance(NPC_MENGLIN.x + NPC_MENGLIN.rolewidth / 2, NPC_MENGLIN.y + NPC_MENGLIN.roleheight / 2, Myself.x + Myself.rolewidth / 2, Myself.y + Myself.roleheight / 2) <= 80)
	{
		//这里的IF语句是进入对话。
		//const int MAX_ROWS = 40;  // 最大行数
		//const int MAX_COLS = 40;  // 最大列数
		////TCHAR CHAPTERONE[MAX_ROWS][MAX_COLS]; 定义二维数组
		TCHAR** CHAPTERONE = new TCHAR * [MAX_ROWS];
		for (int i = 0; i < MAX_ROWS; i++) {
			CHAPTERONE[i] = new TCHAR[MAX_COLS];
		}

		settextstyle(24, 0, _T("宋体"));
		//这是在清除 press space to talk
		cleardevice();
		putimage(0, 0, &background);

		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
		//梦林加载
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
		//莉可加载
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//传送法阵
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);

		TOCHAPTERTWO[1] = 'B';

		FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
		errno_t err = _tfopen_s(&file, _T("res\\story\\NPC2-CHAPTER1.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
		if (file == NULL) {
			// 处理文件打开失败的情况
			return;
		}
		int rowIndex = 0;
		while (_fgetts(CHAPTERONE[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
			rowIndex++;
			if (rowIndex >= MAX_ROWS) {
				// 处理数组内存溢出的情况
				break;
			}
		}
		fclose(file);
		//检测文本的函数，以后删掉。

		//对话循环
		rowIndex = 0;
		bool onechancetouse = true;
		while (rowIndex < CHAPTERONE_NPC2_ROW)//需要改 目前是6
		{
			//对话框大小及位置
			setlinecolor(WHITE);
			rectangle(200, 600, 1080, 700);
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			outtextxy(210, 640, CHAPTERONE[rowIndex] + 1);
			//这里因为我提前把矩形框位围出来了，所以图片也必须提前，但是是一次性的，感觉不是很好看（代码），因此期望以后优化。
			if (CHAPTERONE[rowIndex][0] == '1' && onechancetouse)
			{
				putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
				putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
				onechancetouse = false;
			}
			else if (CHAPTERONE[rowIndex][0] == '3' && onechancetouse)
			{
				putimage(NPC_MENGLIN_PANEL.x, NPC_MENGLIN_PANEL.y, NPC_MENGLIN_PANEL.rolewidth, NPC_MENGLIN_PANEL.roleheight, &NPC_MENGLIN_PANEL.roleY, 0, 0, SRCAND);
				putimage(NPC_MENGLIN_PANEL.x, NPC_MENGLIN_PANEL.y, NPC_MENGLIN_PANEL.rolewidth, NPC_MENGLIN_PANEL.roleheight, &NPC_MENGLIN_PANEL.role, 0, 0, SRCPAINT);
				onechancetouse = false;
			}
			int CHANCE = 0;
			if (int CHANCE = _getch())
			{
				if (CHANCE == 32)
				{
					//即使退出了循环也能初始化场景。
					cleardevice();//这里是清除之前的矩形框。主打的就是懒。
					putimage(0, 0, &background);
					//放角色
					putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
					putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
					//梦林加载
					putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
					putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
					//莉可加载
					putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
					putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
					//传送法阵
					putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
					putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);

					//这么重要的东西放在这？？？
					rowIndex++;
					//这么重要的东西放在这？？？
					//说明一下，因为已经清屏，所以，这里的图片先载入没什么问题。
					if (CHAPTERONE[rowIndex][0] == '1')//如果是1则是我
					{
						//这里有问题，图片的问题，至少是白底黑掩码图才对。代码先写着，等着换元。
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
					}
					else if (CHAPTERONE[rowIndex][0] == '3')
					{
						putimage(NPC_MENGLIN_PANEL.x, NPC_MENGLIN_PANEL.y, NPC_MENGLIN_PANEL.rolewidth, NPC_MENGLIN_PANEL.roleheight, &NPC_MENGLIN_PANEL.roleY, 0, 0, SRCAND);
						putimage(NPC_MENGLIN_PANEL.x, NPC_MENGLIN_PANEL.y, NPC_MENGLIN_PANEL.rolewidth, NPC_MENGLIN_PANEL.roleheight, &NPC_MENGLIN_PANEL.role, 0, 0, SRCPAINT);
					}



				}
			}
		}


		//释放内存代码
		for (int i = 0; i < MAX_ROWS; i++) {
			delete[] CHAPTERONE[i];
		}
		delete[] CHAPTERONE;


	}
}
void dialogewithNPC3(char choice)
{
	bool whototalk = false;//false 是主人公。
	bool restart_flag = true;
	if (choice == 32 && Distance(NPC_LIKE.x + NPC_LIKE.rolewidth / 2, NPC_LIKE.y + NPC_LIKE.roleheight / 2, Myself.x + Myself.rolewidth / 2, Myself.y + Myself.roleheight / 2) <= 80)
	{
		//这里的IF语句是进入对话。

		TCHAR** CHAPTERONE = new TCHAR * [MAX_ROWS];
		for (int i = 0; i < MAX_ROWS; i++) {
			CHAPTERONE[i] = new TCHAR[MAX_COLS];
		}

		settextstyle(24, 0, _T("宋体"));
		//这是在清除 press space to talk
		cleardevice();
		putimage(0, 0, &background);

		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
		//梦林加载
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
		//莉可加载
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//传送法阵
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
		//密钥
		TOCHAPTERTWO[2] = 'C';
		FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
		errno_t err = _tfopen_s(&file, _T("res\\story\\NPC3-CHAPTER1.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
		if (file == NULL) {
			// 处理文件打开失败的情况
			return;
		}
		int rowIndex = 0;
		while (_fgetts(CHAPTERONE[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
			rowIndex++;
			if (rowIndex >= MAX_ROWS) {
				// 处理数组内存溢出的情况
				break;
			}
		}
		fclose(file);
		//检测文本的函数，以后删掉。
		/*for (int i = 0; i < rowIndex; i++) {
			_tprintf(_T("%s"), CHAPTERONE[i]);
		}*/


		//对话循环
		rowIndex = 0;
		bool onechancetouse = true;
		while (rowIndex < CHPTERONE_NPC3_ROW)//需要改 目前是6
		{
			//对话框大小及位置
			setlinecolor(WHITE);
			rectangle(200, 600, 1080, 700);
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			outtextxy(210, 640, CHAPTERONE[rowIndex] + 1);
			//这里因为我提前把矩形框位围出来了，所以图片也必须提前，但是是一次性的，感觉不是很好看（代码），因此期望以后优化。
			if (CHAPTERONE[rowIndex][0] == '1' && onechancetouse)
			{
				putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
				putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
				onechancetouse = false;
			}
			else if (CHAPTERONE[rowIndex][0] == '4' && onechancetouse)
			{
				putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.roleY, 0, 0, SRCAND);
				putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.role, 0, 0, SRCPAINT);
				onechancetouse = false;
			}
			int CHANCE = 0;
			if (int CHANCE = _getch())
			{
				if (CHANCE == 32)
				{
					//即使退出了循环也能初始化场景。
					cleardevice();//这里是清除之前的矩形框。主打的就是懒。
					putimage(0, 0, &background);
					//放角色
					putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
					putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
					//梦林加载
					putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
					putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
					//莉可加载
					putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
					putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
					//传送法阵
					putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
					putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);

					//这么重要的东西放在这？？？
					rowIndex++;
					//这么重要的东西放在这？？？
					//说明一下，因为已经清屏，所以，这里的图片先载入没什么问题。
					if (CHAPTERONE[rowIndex][0] == '1')//如果是1则是我
					{
						//这里有问题，图片的问题，至少是白底黑掩码图才对。代码先写着，等着换元。
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
					}
					else if (CHAPTERONE[rowIndex][0] == '4')
					{
						putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.roleY, 0, 0, SRCAND);
						putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.role, 0, 0, SRCPAINT);
					}



				}
			}
		}


		//释放内存代码
		for (int i = 0; i < MAX_ROWS; i++) {
			delete[] CHAPTERONE[i];
		}
		delete[] CHAPTERONE;


	}
}
void dialogewithNPC0()
{
	TCHAR** CHAPTERONE = new TCHAR * [MAX_ROWS];
	for (int i = 0; i < MAX_ROWS; i++) {
		CHAPTERONE[i] = new TCHAR[MAX_COLS];
	}
	settextstyle(24, 0, _T("宋体"));
	FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
	errno_t err = _tfopen_s(&file, _T("res\\story\\NPC0-CHAPTER1.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
	if (file == NULL) {
		// 处理文件打开失败的情况
		return;
	}
	int rowIndex = 0;
	while (_fgetts(CHAPTERONE[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
		rowIndex++;
		if (rowIndex >= MAX_ROWS) {
			// 处理数组内存溢出的情况
			break;
		}
	}
	fclose(file);
	//检测文本的函数，以后删掉。
	/*for (int i = 0; i < rowIndex; i++) {
		_tprintf(_T("%s"), CHAPTERONE[i]);
	}*/
	rowIndex = 0;
	bool onechancetouse = true;
	while (rowIndex < CHPTERONE_NPC0_ROW)//需要改 目前是6
	{
		//对话框大小及位置
		setlinecolor(WHITE);
		rectangle(200, 600, 1080, 700);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		outtextxy(210, 640, CHAPTERONE[rowIndex] + 1);
		//这里因为我提前把矩形框位围出来了，所以图片也必须提前，但是是一次性的，感觉不是很好看（代码），因此期望以后优化。
		if (CHAPTERONE[rowIndex][0] == '1' && onechancetouse)
		{
			putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
			putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
			onechancetouse = false;
		}
		else if (CHAPTERONE[rowIndex][0] == '0' && onechancetouse)
		{
			putimage(NPC_0.x, NPC_0.y, NPC_0.rolewidth, NPC_0.roleheight, &NPC_0.roleY, 0, 0, SRCAND);
			putimage(NPC_0.x, NPC_0.y, NPC_0.rolewidth, NPC_0.roleheight, &NPC_0.role, 0, 0, SRCPAINT);
			onechancetouse = false;
		}
		if (int CHANCE = _getch())
		{
			if (CHANCE == 32)
			{
				//即使退出了循环也能初始化场景。
				cleardevice();//这里是清除之前的矩形框。主打的就是懒。
				putimage(0, 0, &background);
				//放角色
				putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
				putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
				//梦林加载
				putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
				putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
				//莉可加载
				putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
				putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
				//传送法阵
				putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
				putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
				putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
				putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);

				//这么重要的东西放在这？？？
				rowIndex++;
				//这么重要的东西放在这？？？
				//说明一下，因为已经清屏，所以，这里的图片先载入没什么问题。
				if (CHAPTERONE[rowIndex][0] == '1')//如果是1则是我
				{
					//这里有问题，图片的问题，至少是白底黑掩码图才对。代码先写着，等着换元。
					putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
					putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
				}
				else if (CHAPTERONE[rowIndex][0] == '0')
				{
					putimage(NPC_0.x, NPC_0.y, NPC_0.rolewidth, NPC_0.roleheight, &NPC_0.roleY, 0, 0, SRCAND);
					putimage(NPC_0.x, NPC_0.y, NPC_0.rolewidth, NPC_0.roleheight, &NPC_0.role, 0, 0, SRCPAINT);
				}



			}
		}
	}
	//清除堆内存
	for (int i = 0; i < MAX_ROWS; i++) {
		delete[] CHAPTERONE[i];
	}
	delete[] CHAPTERONE;

}
void Makeyourchoice(bool& chapter_1, bool& gamestarted)
{
	IMAGE BADEND;
	loadimage(&BADEND, _T("res\\BADEND2.jpg"));
	setlinestyle(PS_SOLID, 1);
	settextstyle(18, 0, _T("宋体"));
	setbkmode(TRANSPARENT);
	TCHAR CHOICE[30] = L"MAKE YOUR CHOICE";
	int width = textwidth(CHOICE);
	int height = textheight(CHOICE);
	outtextxy(640 - width / 2, 545 - height / 2, CHOICE);
	TCHAR CHOICE1[30] = L"宅在宿舍";
	TCHAR CHOICE2[30] = L"参加嘉年华";
	rectangle(200, 595, 400, 645);
	width = textwidth(CHOICE1);
	height = textheight(CHOICE1);
	outtextxy(300 - width / 2, 620 - height / 2, CHOICE1);
	rectangle(880, 595, 1080, 645);
	width = textwidth(CHOICE2);
	height = textheight(CHOICE2);
	outtextxy(980 - width / 2, 620 - height / 2, CHOICE2);
	//创建二维数组

	while (1)
	{
		//bool onechancetouse = true;
		if (MouseHit())
		{
			MOUSEMSG m = GetMouseMsg();
			if (m.x >= 200 && m.x <= 400 && m.y >= 595 && m.y <= 645 && m.uMsg == WM_LBUTTONDOWN)//宅在宿舍的选项
			{
				TCHAR** CHAPTERZERO = new TCHAR * [MAX_ROWS];
				for (int i = 0; i < MAX_ROWS; i++) {
					CHAPTERZERO[i] = new TCHAR[MAX_COLS];
				}
				cleardevice();
				putimage(40, 40, &BADEND);
				//关闭恐怖阴森的音乐
				mciSendString(_T("stop HAIPA"), 0, 0, 0);
				mciSendString(_T("close HAIPA"), 0, 0, 0);
				//播放背景音乐
				mciSendString(_T("open res/Music/402422124.mp3 alias SONG"), 0, 0, 0);
				mciSendString(_T("play SONG repeat"), 0, 0, 0);

				FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
				errno_t err = _tfopen_s(&file, _T("res\\story\\BADENDCHAPTER1.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
				if (file == NULL) {
					// 处理文件打开失败的情况
					return;
				}

				int rowIndex = 0;

				while (_fgetts(CHAPTERZERO[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
					rowIndex++;
					if (rowIndex >= MAX_ROWS) {
						// 处理数组内存溢出的情况
						break;
					}
				}
				fclose(file);
				rowIndex = 0;
				settextstyle(24, 0, _T("宋体"));
				//实现打字机效果
				while (rowIndex < BADENDCHAPTER1)
				{
					//确保文字居中。
					width = textwidth(CHAPTERZERO[rowIndex]);
					height = textheight(CHAPTERZERO[rowIndex]);
					for (int i = 0; CHAPTERZERO[rowIndex][i] != NULL; i++)
					{
						int u = textwidth(CHAPTERZERO[rowIndex][i]);
						outtextxy(Width / 2 - width / 2 + i * u, 1.5 * height * (rowIndex + 1), CHAPTERZERO[rowIndex][i]);
						Sleep(100);
					}
					rowIndex++;
				}
				//重启游戏
				//Sleep(10000);
				TCHAR CHOICE_RESTART[30] = L"RESTART GAME?";
				width = textwidth(CHOICE_RESTART);
				height = textheight(CHOICE_RESTART);
				outtextxy(100 - width / 2, 360 - height / 2, CHOICE_RESTART);
				TCHAR RESTART[10] = L"是";
				width = textwidth(RESTART);
				height = textheight(RESTART);
				rectangle(50, 395, 150, 445);
				outtextxy(100 - width / 2, 420 - height / 2, RESTART);
				while (1)
				{
					if (MouseHit())
					{
						MOUSEMSG n = GetMouseMsg();
						if (n.x >= 50 && n.x <= 150 && n.y >= 395 && n.y <= 445 && n.uMsg == WM_LBUTTONDOWN)
						{
							chapter_1 = false;
							gamestarted = false;//重启游戏
							TOCHAPTERTWO[0] = '0';
							TOCHAPTERTWO[1] = '0';
							TOCHAPTERTWO[2] = '0';
							Myself.x = 600;
							Myself.y = 500;
							mciSendString(_T("stop SONG"), 0, 0, 0);
							mciSendString(_T("close SONG"), 0, 0, 0);
							break;
						}
					}
				}
				for (int i = 0; i < MAX_ROWS; i++) {
					delete[] CHAPTERZERO[i];
				}
				delete[] CHAPTERZERO;
				//退出WHILE(1)用
				break;
			}
			else if (m.x >= 880 && m.x <= 1080 && m.y >= 595 && m.y <= 645 && m.uMsg == WM_LBUTTONDOWN)
			{
				int rowIndex = 0;
				//判断第一次的放置图片问题
				mciSendString(_T("stop HAIPA"), 0, 0, 0);
				mciSendString(_T("close HAIPA"), 0, 0, 0);
				mciSendString(_T("open res/Music/BGM.mp3 alias BGM"), 0, 0, 0);
				mciSendString(_T("play BGM repeat"), 0, 0, 0);
				settextstyle(24, 0, _T("宋体"));
				bool onechancetouse = true;
				TCHAR** CHAPTERZEROAFTER = new TCHAR * [MAX_ROWS];
				for (int i = 0; i < MAX_ROWS; i++) {
					CHAPTERZEROAFTER[i] = new TCHAR[MAX_COLS];
				}

				FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
				errno_t err = _tfopen_s(&file, _T("res\\story\\NPC0-CHAPTER1-AFTER.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
				if (file == NULL) {
					// 处理文件打开失败的情况
					return;
				}

				while (_fgetts(CHAPTERZEROAFTER[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
					rowIndex++;
					if (rowIndex >= MAX_ROWS) {
						// 处理数组内存溢出的情况
						break;
					}
				}

				rowIndex = 0;

				setlinecolor(WHITE);
				settextcolor(WHITE);
				setbkmode(TRANSPARENT);

				cleardevice();
				putimage(0, 0, &background);
				//放角色
				putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
				putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
				//梦林加载
				putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
				putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
				//莉可加载
				putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
				putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
				//传送法阵
				putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
				putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
				putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
				putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
				while (rowIndex < BADENDCHAPTER1_AFTER)//需要改 目前是6
				{
					//对话框大小及位置
					rectangle(200, 600, 1080, 700);
					outtextxy(210, 640, CHAPTERZEROAFTER[rowIndex] + 1);
					//这里因为我提前把矩形框位围出来了，所以图片也必须提前，但是是一次性的，感觉不是很好看（代码），因此期望以后优化。
					if (CHAPTERZEROAFTER[rowIndex][0] == '1' && onechancetouse)
					{
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
						onechancetouse = false;
					}
					else if (CHAPTERZEROAFTER[rowIndex][0] == '0' && onechancetouse)
					{
						putimage(NPC_0.x, NPC_0.y, NPC_0.rolewidth, NPC_0.roleheight, &NPC_0.roleY, 0, 0, SRCAND);
						putimage(NPC_0.x, NPC_0.y, NPC_0.rolewidth, NPC_0.roleheight, &NPC_0.role, 0, 0, SRCPAINT);
						onechancetouse = false;
					}
					int CHANCE = 0;
					if (CHANCE = _getch())
					{
						if (CHANCE == 32)
						{
							//即使退出了循环也能初始化场景。
							cleardevice();//这里是清除之前的矩形框。主打的就是懒。
							putimage(0, 0, &background);
							//放角色
							putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
							putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
							//梦林加载
							putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
							putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
							//莉可加载
							putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
							putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
							//传送法阵
							putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
							putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
							putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
							putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);

							//这么重要的东西放在这？？？
							rowIndex++;
							//这么重要的东西放在这？？？
							//说明一下，因为已经清屏，所以，这里的图片先载入没什么问题。
							if (CHAPTERZEROAFTER[rowIndex][0] == '1')//如果是1则是我
							{
								//这里有问题，图片的问题，至少是白底黑掩码图才对。代码先写着，等着换元。
								putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
								putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
							}
							else if (CHAPTERZEROAFTER[rowIndex][0] == '0')
							{
								putimage(NPC_0.x, NPC_0.y, NPC_0.rolewidth, NPC_0.roleheight, &NPC_0.roleY, 0, 0, SRCAND);
								putimage(NPC_0.x, NPC_0.y, NPC_0.rolewidth, NPC_0.roleheight, &NPC_0.role, 0, 0, SRCPAINT);
							}



						}
					}

				}
				for (int i = 0; i < MAX_ROWS; i++) {
					delete[] CHAPTERZEROAFTER[i];
				}
				delete[] CHAPTERZEROAFTER;
				//退出WHILE(1)用
				break;
			}
		}

	}
}
void INTRODUCESTORY2()
{
	TCHAR** CHAPTERONE = new TCHAR * [MAX_ROWS];
	for (int i = 0; i < MAX_ROWS; i++) {
		CHAPTERONE[i] = new TCHAR[MAX_COLS];
	}


	FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
	errno_t err = _tfopen_s(&file, _T("res\\story\\Introduce2.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
	if (file == NULL) {
		// 处理文件打开失败的情况
		return;
	}
	int rowIndex = 0;
	while (_fgetts(CHAPTERONE[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
		rowIndex++;
		if (rowIndex >= MAX_ROWS) {
			// 处理数组内存溢出的情况
			break;
		}
	}
	fclose(file);
	rowIndex = 0;
	settextstyle(22, 0, _T("宋体"), 0, 0, 700, false, false, false);
	setlinestyle(PS_SOLID, 2);
	bool onechancetouse = true;
	IMAGE BUFF;
	getimage(&BUFF, 0, 0, 1280, 720);
	while (rowIndex < Introduce2)//需要改 目前是6
	{
		setlinecolor(BLACK);
		rectangle(200, 600, 1080, 700);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);

		outtextxy(210, 640, CHAPTERONE[rowIndex] + 1);
		if (CHAPTERONE[rowIndex][0] == '1' && onechancetouse)
		{
			putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
			putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
			onechancetouse = false;
		}
		int CHANCE = 0;
		if (int CHANCE = _getch())
		{
			if (CHANCE == 32)
			{
				cleardevice();//这里是清除之前的矩形框。主打的就是懒。
				rowIndex++;
				putimage(0, 0, &BUFF);
				if (CHAPTERONE[rowIndex][0] == '1')//如果是1则是我
				{
					//这里有问题，图片的问题，至少是白底黑掩码图才对。代码先写着，等着换元。
					putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
					putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
				}
			}
		}

	}
}
void dialogewithWEIQI(char choice)
{
	if (choice == 32 && Distance(WEIQI.x + WEIQI.rolewidth / 2, WEIQI.y + WEIQI.roleheight / 2, Myself.x + Myself.rolewidth / 2, Myself.y + Myself.roleheight / 2) <= 80)
	{
		TCHAR** CHAPTER2 = new TCHAR * [MAX_ROWS];
		for (int i = 0; i < MAX_ROWS; i++) {
			CHAPTER2[i] = new TCHAR[MAX_COLS];
		}
		settextstyle(22, 0, _T("宋体"));
		//这是在清除 press space to talk
		cleardevice();
		putimage(0, 0, &bk2);
		//放置围棋组
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//放置桌游组
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//放置游泳组
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//放置绘画组
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		//放置自己
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
		TOCHAPTERTHREE[0] = 'A';
		FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
		errno_t err = _tfopen_s(&file, _T("res\\story\\NPC-WEIQI-CHAPTER2.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
		if (file == NULL) {
			// 处理文件打开失败的情况
			return;
		}

		_setmode(_fileno(stdout), _O_U8TEXT);  // 设置控制台输出为UTF-8编码

		int rowIndex = 0;
		while (_fgetts(CHAPTER2[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
			rowIndex++;
			if (rowIndex >= MAX_ROWS) {
				// 处理数组内存溢出的情况
				break;
			}
		}
		for (int i = 0; i < CHAPTER2_WEIQI; i++) {
			_tprintf(_T("%s"), CHAPTER2[i]);
		}
		fclose(file);
		rowIndex = 0;
		bool onechancetouse = true;
		while (rowIndex < CHAPTER2_WEIQI)//需要改 目前是6
		{
			setlinecolor(WHITE);
			rectangle(200, 600, 1080, 700);
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			outtextxy(210, 640, CHAPTER2[rowIndex] + 1);
			if (CHAPTER2[rowIndex][0] == '1' && onechancetouse)
			{
				putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
				putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
				onechancetouse = false;
			}
			else if (CHAPTER2[rowIndex][0] == '5' && onechancetouse)
			{
				putimage(WEIQI_PANEL.x, WEIQI_PANEL.y, WEIQI_PANEL.rolewidth, WEIQI_PANEL.roleheight, &WEIQI_PANEL.roleY, 0, 0, SRCAND);
				putimage(WEIQI_PANEL.x, WEIQI_PANEL.y, WEIQI_PANEL.rolewidth, WEIQI_PANEL.roleheight, &WEIQI_PANEL.role, 0, 0, SRCPAINT);
				onechancetouse = false;
			}
			int CHANCE = 0;
			if (int CHANCE = _getch())
			{
				if (CHANCE == 32)
				{
					//即使退出了循环也能初始化场景。
					cleardevice();//这里是清除之前的矩形框。主打的就是懒。
					putimage(0, 0, &bk2);
					//放置围棋组
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
					//放置桌游组
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
					//放置游泳组
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
					//放置绘画组
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
					//放置自己
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
					//这么重要的东西放在这？？？
					rowIndex++;
					//这么重要的东西放在这？？？
					//说明一下，因为已经清屏，所以，这里的图片先载入没什么问题。
					if (CHAPTER2[rowIndex][0] == '1')//如果是1则是我
					{
						//这里有问题，图片的问题，至少是白底黑掩码图才对。代码先写着，等着换元。
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
					}
					else if (CHAPTER2[rowIndex][0] == '5')
					{
						putimage(WEIQI_PANEL.x, WEIQI_PANEL.y, WEIQI_PANEL.rolewidth, WEIQI_PANEL.roleheight, &WEIQI_PANEL.roleY, 0, 0, SRCAND);
						putimage(WEIQI_PANEL.x, WEIQI_PANEL.y, WEIQI_PANEL.rolewidth, WEIQI_PANEL.roleheight, &WEIQI_PANEL.role, 0, 0, SRCPAINT);
					}



				}
			}
		}
		for (int i = 0; i < MAX_ROWS; i++) {
			delete[] CHAPTER2[i];
		}
		delete[] CHAPTER2;
	}

}
void dialogewithZHUOYOU(char choice)
{
	if (choice == 32 && Distance(ZHUOYOU.x + ZHUOYOU.rolewidth / 2, ZHUOYOU.y + ZHUOYOU.roleheight / 2, Myself.x + Myself.rolewidth / 2, Myself.y + Myself.roleheight / 2) <= 80)
	{
		TCHAR** CHAPTER2 = new TCHAR * [MAX_ROWS];
		for (int i = 0; i < MAX_ROWS; i++) {
			CHAPTER2[i] = new TCHAR[MAX_COLS];
		}
		settextstyle(22, 0, _T("宋体"));
		//这是在清除 press space to talk
		cleardevice();
		putimage(0, 0, &bk2);
		//放置围棋组
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//放置桌游组
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//放置游泳组
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//放置绘画组
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		//放置自己
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
		TOCHAPTERTHREE[1] = 'B';
		FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
		errno_t err = _tfopen_s(&file, _T("res\\story\\NPC-ZHUOYOU-CHAPTER2.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
		if (file == NULL) {
			// 处理文件打开失败的情况
			return;
		}

		_setmode(_fileno(stdout), _O_U8TEXT);  // 设置控制台输出为UTF-8编码

		int rowIndex = 0;
		while (_fgetts(CHAPTER2[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
			rowIndex++;
			if (rowIndex >= MAX_ROWS) {
				// 处理数组内存溢出的情况
				break;
			}
		}
		/*for (int i = 0; i < CHAPTER2_WEIQI; i++) {
			_tprintf(_T("%s"), CHAPTER2[i]);
		}*/
		fclose(file);
		rowIndex = 0;
		bool onechancetouse = true;

		while (rowIndex < CHAPTER2_ZHUOYOU)//需要改 目前是6
		{
			setlinecolor(WHITE);
			rectangle(200, 600, 1080, 700);
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			outtextxy(210, 640, CHAPTER2[rowIndex] + 1);
			if (CHAPTER2[rowIndex][0] == '1' && onechancetouse)
			{
				putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
				putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
				onechancetouse = false;
			}
			else if (CHAPTER2[rowIndex][0] == '6' && onechancetouse)
			{
				putimage(ZHUOYOU_PANEL.x, ZHUOYOU_PANEL.y, ZHUOYOU_PANEL.rolewidth, ZHUOYOU_PANEL.roleheight, &ZHUOYOU_PANEL.roleY, 0, 0, SRCAND);
				putimage(ZHUOYOU_PANEL.x, ZHUOYOU_PANEL.y, ZHUOYOU_PANEL.rolewidth, ZHUOYOU_PANEL.roleheight, &ZHUOYOU_PANEL.role, 0, 0, SRCPAINT);
				onechancetouse = false;
			}
			int CHANCE = 0;
			if (int CHANCE = _getch())
			{
				if (CHANCE == 32)
				{
					//即使退出了循环也能初始化场景。
					cleardevice();//这里是清除之前的矩形框。主打的就是懒。
					putimage(0, 0, &bk2);
					//放置围棋组
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
					//放置桌游组
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
					//放置游泳组
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
					//放置绘画组
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
					//放置自己
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
					//这么重要的东西放在这？？？
					rowIndex++;
					//这么重要的东西放在这？？？
					//说明一下，因为已经清屏，所以，这里的图片先载入没什么问题。
					if (CHAPTER2[rowIndex][0] == '1')//如果是1则是我
					{
						//这里有问题，图片的问题，至少是白底黑掩码图才对。代码先写着，等着换元。
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
					}
					else if (CHAPTER2[rowIndex][0] == '6')
					{
						putimage(ZHUOYOU_PANEL.x, ZHUOYOU_PANEL.y, ZHUOYOU_PANEL.rolewidth, ZHUOYOU_PANEL.roleheight, &ZHUOYOU_PANEL.roleY, 0, 0, SRCAND);
						putimage(ZHUOYOU_PANEL.x, ZHUOYOU_PANEL.y, ZHUOYOU_PANEL.rolewidth, ZHUOYOU_PANEL.roleheight, &ZHUOYOU_PANEL.role, 0, 0, SRCPAINT);
					}



				}
			}
		}
		for (int i = 0; i < MAX_ROWS; i++) {
			delete[] CHAPTER2[i];
		}
		delete[] CHAPTER2;
	}

}
void dialogewithYOUYONG(char choice)
{
	if (choice == 32 && Distance(YOUYONG.x + YOUYONG.rolewidth / 2, YOUYONG.y + YOUYONG.roleheight / 2, Myself.x + Myself.rolewidth / 2, Myself.y + Myself.roleheight / 2) <= 80)
	{
		TCHAR** CHAPTER2 = new TCHAR * [MAX_ROWS];
		for (int i = 0; i < MAX_ROWS; i++) {
			CHAPTER2[i] = new TCHAR[MAX_COLS];
		}
		settextstyle(22, 0, _T("宋体"));
		//这是在清除 press space to talk
		cleardevice();
		putimage(0, 0, &bk2);
		//放置围棋组
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//放置桌游组
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//放置游泳组
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//放置绘画组
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		//放置自己
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
		TOCHAPTERTHREE[2] = 'C';
		FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
		errno_t err = _tfopen_s(&file, _T("res\\story\\NPC-YOUYONG-CHAPTER2.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
		if (file == NULL) {
			// 处理文件打开失败的情况
			return;
		}

		_setmode(_fileno(stdout), _O_U8TEXT);  // 设置控制台输出为UTF-8编码

		int rowIndex = 0;
		while (_fgetts(CHAPTER2[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
			rowIndex++;
			if (rowIndex >= MAX_ROWS) {
				// 处理数组内存溢出的情况
				break;
			}
		}
		/*for (int i = 0; i < CHAPTER2_WEIQI; i++) {
			_tprintf(_T("%s"), CHAPTER2[i]);
		}*/
		fclose(file);
		rowIndex = 0;
		bool onechancetouse = true;

		while (rowIndex < CHAPTER2_YOUYONG)//需要改 目前是6
		{
			setlinecolor(WHITE);
			rectangle(200, 600, 1080, 700);
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			outtextxy(210, 640, CHAPTER2[rowIndex] + 1);
			if (CHAPTER2[rowIndex][0] == '1' && onechancetouse)
			{
				putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
				putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
				onechancetouse = false;
			}
			else if (CHAPTER2[rowIndex][0] == '7' && onechancetouse)
			{
				putimage(YOUYONG_PANEL.x, YOUYONG_PANEL.y, YOUYONG_PANEL.rolewidth, YOUYONG_PANEL.roleheight, &YOUYONG_PANEL.roleY, 0, 0, SRCAND);
				putimage(YOUYONG_PANEL.x, YOUYONG_PANEL.y, YOUYONG_PANEL.rolewidth, YOUYONG_PANEL.roleheight, &YOUYONG_PANEL.role, 0, 0, SRCPAINT);
				onechancetouse = false;
			}
			int CHANCE = 0;
			if (int CHANCE = _getch())
			{
				if (CHANCE == 32)
				{
					//即使退出了循环也能初始化场景。
					cleardevice();//这里是清除之前的矩形框。主打的就是懒。
					putimage(0, 0, &bk2);
					//放置围棋组
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
					//放置桌游组
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
					//放置游泳组
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
					//放置绘画组
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
					//放置自己
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
					//这么重要的东西放在这？？？
					rowIndex++;
					//这么重要的东西放在这？？？
					//说明一下，因为已经清屏，所以，这里的图片先载入没什么问题。
					if (CHAPTER2[rowIndex][0] == '1')//如果是1则是我
					{
						//这里有问题，图片的问题，至少是白底黑掩码图才对。代码先写着，等着换元。
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
					}
					else if (CHAPTER2[rowIndex][0] == '7')
					{
						putimage(YOUYONG_PANEL.x, YOUYONG_PANEL.y, YOUYONG_PANEL.rolewidth, YOUYONG_PANEL.roleheight, &YOUYONG_PANEL.roleY, 0, 0, SRCAND);
						putimage(YOUYONG_PANEL.x, YOUYONG_PANEL.y, YOUYONG_PANEL.rolewidth, YOUYONG_PANEL.roleheight, &YOUYONG_PANEL.role, 0, 0, SRCPAINT);
					}



				}
			}
		}
		for (int i = 0; i < MAX_ROWS; i++) {
			delete[] CHAPTER2[i];
		}
		delete[] CHAPTER2;
	}

}
void dialogewithHUIHUA(char choice)
{
	if (choice == 32 && Distance(HUIHUA.x + HUIHUA.rolewidth / 2, HUIHUA.y + HUIHUA.roleheight / 2, Myself.x + Myself.rolewidth / 2, Myself.y + Myself.roleheight / 2) <= 80)
	{
		TCHAR** CHAPTER2 = new TCHAR * [MAX_ROWS];
		for (int i = 0; i < MAX_ROWS; i++) {
			CHAPTER2[i] = new TCHAR[MAX_COLS];
		}
		settextstyle(22, 0, _T("宋体"));
		//这是在清除 press space to talk
		cleardevice();
		putimage(0, 0, &bk2);
		//放置围棋组
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//放置桌游组
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//放置游泳组
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//放置绘画组
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		//放置自己
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
		TOCHAPTERTHREE[3] = 'D';
		FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
		errno_t err = _tfopen_s(&file, _T("res\\story\\NPC-HUIHUA-CHAPTER2.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
		if (file == NULL) {
			// 处理文件打开失败的情况
			return;
		}

		_setmode(_fileno(stdout), _O_U8TEXT);  // 设置控制台输出为UTF-8编码

		int rowIndex = 0;
		while (_fgetts(CHAPTER2[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
			rowIndex++;
			if (rowIndex >= MAX_ROWS) {
				// 处理数组内存溢出的情况
				break;
			}
		}
		/*for (int i = 0; i < CHAPTER2_WEIQI; i++) {
			_tprintf(_T("%s"), CHAPTER2[i]);
		}*/
		fclose(file);
		rowIndex = 0;
		bool onechancetouse = true;

		while (rowIndex < CHAPTER2_HUIHUA)//需要改 目前是6
		{
			setlinecolor(WHITE);
			rectangle(200, 600, 1080, 700);
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			outtextxy(210, 640, CHAPTER2[rowIndex] + 1);
			if (CHAPTER2[rowIndex][0] == '1' && onechancetouse)
			{
				putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
				putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
				onechancetouse = false;
			}
			else if (CHAPTER2[rowIndex][0] == '8' && onechancetouse)
			{
				putimage(HUIHUA_PANEL.x, HUIHUA_PANEL.y, HUIHUA_PANEL.rolewidth, HUIHUA_PANEL.roleheight, &HUIHUA_PANEL.roleY, 0, 0, SRCAND);
				putimage(HUIHUA_PANEL.x, HUIHUA_PANEL.y, HUIHUA_PANEL.rolewidth, HUIHUA_PANEL.roleheight, &HUIHUA_PANEL.role, 0, 0, SRCPAINT);
				onechancetouse = false;
			}
			int CHANCE = 0;
			if (int CHANCE = _getch())
			{
				if (CHANCE == 32)
				{
					//即使退出了循环也能初始化场景。
					cleardevice();//这里是清除之前的矩形框。主打的就是懒。
					putimage(0, 0, &bk2);
					//放置围棋组
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
					//放置桌游组
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
					//放置游泳组
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
					//放置绘画组
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
					//放置自己
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
					//这么重要的东西放在这？？？
					rowIndex++;
					//这么重要的东西放在这？？？
					//说明一下，因为已经清屏，所以，这里的图片先载入没什么问题。
					if (CHAPTER2[rowIndex][0] == '1')//如果是1则是我
					{
						//这里有问题，图片的问题，至少是白底黑掩码图才对。代码先写着，等着换元。
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
						putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
					}
					else if (CHAPTER2[rowIndex][0] == '8')
					{
						putimage(HUIHUA_PANEL.x, HUIHUA_PANEL.y, HUIHUA_PANEL.rolewidth, HUIHUA_PANEL.roleheight, &HUIHUA_PANEL.roleY, 0, 0, SRCAND);
						putimage(HUIHUA_PANEL.x, HUIHUA_PANEL.y, HUIHUA_PANEL.rolewidth, HUIHUA_PANEL.roleheight, &HUIHUA_PANEL.role, 0, 0, SRCPAINT);
					}



				}
			}
		}
		for (int i = 0; i < MAX_ROWS; i++) {
			delete[] CHAPTER2[i];
		}
		delete[] CHAPTER2;
	}

}
void dialogewithCAIDAN(char choice)
{
	if (choice == 32 && Distance(810, 425, Myself.x + Myself.rolewidth / 2, Myself.y + Myself.roleheight / 2) <= 80)
	{
		cleardevice();
		putimage(0, 0, &bk2);
		//放置围棋组
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//放置桌游组
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//放置游泳组
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//放置绘画组
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		//放置自己
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
		setlinecolor(YELLOW);
		rectangle(200, 600, 1080, 700);
		settextcolor(YELLOW);
		setbkmode(TRANSPARENT);
		settextstyle(24, 0, _T("宋体"));
		TCHAR CAIDAN[30] = _T("游戏社社长：要试试我们新做的弹球游戏吗？");
		outtextxy(210, 640, CAIDAN);
		putimage(CAIDAN_PANEL.x, CAIDAN_PANEL.y, CAIDAN_PANEL.rolewidth, CAIDAN_PANEL.roleheight, &CAIDAN_PANEL.roleY, 0, 0, SRCAND);
		putimage(CAIDAN_PANEL.x, CAIDAN_PANEL.y, CAIDAN_PANEL.rolewidth, CAIDAN_PANEL.roleheight, &CAIDAN_PANEL.role, 0, 0, SRCPAINT);
		char CHOICE = _getch();
		if (CHOICE == 32)
		{
			cleardevice();
			putimage(0, 0, &bk2);
			//放置围棋组
			putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
			putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
			//放置桌游组
			putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
			putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
			//放置游泳组
			putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
			putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
			//放置绘画组
			putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
			putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
			//放置自己
			putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
			putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
			//绘制选项
			settextstyle(18, 0, _T("宋体"));
			TCHAR CHOICE1[20] = L"游玩";
			TCHAR CHOICE2[20] = L"不游玩";
			rectangle(200, 595, 400, 645);
			int width = textwidth(CHOICE1);
			int height = textheight(CHOICE1);
			outtextxy(300 - width / 2, 620 - height / 2, CHOICE1);
			rectangle(880, 595, 1080, 645);
			width = textwidth(CHOICE2);
			height = textheight(CHOICE2);
			outtextxy(980 - width / 2, 620 - height / 2, CHOICE2);
			while (1)
			{
				if (MouseHit())
				{
					MOUSEMSG m = GetMouseMsg();
					if (m.x >= 200 && m.x <= 400 && m.y >= 595 && m.y <= 645 && m.uMsg == WM_LBUTTONDOWN)//游玩选项
					{
						//从上往下移动60 从左往右移动340
						playgame();
						cleardevice();
						setlinecolor(YELLOW);
						settextcolor(YELLOW);
						putimage(0, 0, &bk2);
						//放置围棋组
						putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
						putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
						//放置桌游组
						putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
						putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
						//放置游泳组
						putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
						putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
						//放置绘画组
						putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
						putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
						//放置自己
						putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
						putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
						TCHAR THANKS[20] = _T("感谢您的游玩");
						rectangle(200, 600, 1080, 700);
						outtextxy(210, 640, THANKS);
						putimage(CAIDAN_PANEL.x, CAIDAN_PANEL.y, CAIDAN_PANEL.rolewidth, CAIDAN_PANEL.roleheight, &CAIDAN_PANEL.roleY, 0, 0, SRCAND);
						putimage(CAIDAN_PANEL.x, CAIDAN_PANEL.y, CAIDAN_PANEL.rolewidth, CAIDAN_PANEL.roleheight, &CAIDAN_PANEL.role, 0, 0, SRCPAINT);
						while (1)
						{
							int u = _getch();
							if (u == 32)
							{
								cleardevice();
								putimage(0, 0, &bk2);
								//放置围棋组
								putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
								putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
								//放置桌游组
								putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
								putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
								//放置游泳组
								putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
								putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
								//放置绘画组
								putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
								putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
								//放置自己
								putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
								putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
								break;
							}
						}
						break;
					}
					else if (m.x >= 880 && m.x <= 1080 && m.y >= 595 && m.y <= 645 && m.uMsg == WM_LBUTTONDOWN)//不游玩选项
					{
						cleardevice();
						putimage(0, 0, &bk2);
						//放置围棋组
						putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
						putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
						//放置桌游组
						putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
						putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
						//放置游泳组
						putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
						putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
						//放置绘画组
						putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
						putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
						//放置自己
						putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
						putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
						settextstyle(24, 0, _T("宋体"));
						TCHAR WUWU[20] = _T("好吧欢迎下次游玩");
						rectangle(200, 600, 1080, 700);
						outtextxy(210, 640, WUWU);
						putimage(CAIDAN_PANEL.x, CAIDAN_PANEL.y, CAIDAN_PANEL.rolewidth, CAIDAN_PANEL.roleheight, &CAIDAN_PANEL.roleY, 0, 0, SRCAND);
						putimage(CAIDAN_PANEL.x, CAIDAN_PANEL.y, CAIDAN_PANEL.rolewidth, CAIDAN_PANEL.roleheight, &CAIDAN_PANEL.role, 0, 0, SRCPAINT);
						while (1)
						{
							int u = _getch();
							if (u == 32)
							{
								cleardevice();
								putimage(0, 0, &bk2);
								//放置围棋组
								putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
								putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
								//放置桌游组
								putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
								putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
								//放置游泳组
								putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
								putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
								//放置绘画组
								putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
								putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
								//放置自己
								putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
								putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
								break;
							}
						}
						break;

					}
				}
			}


		}

	}
}
void LIKECOMEON(bool& chapter_2, bool& chapter_3)//集齐四把钥匙后方可启动
{
	NPC_LIKE.x = 500;
	NPC_LIKE.y = -48;
	int NUMBERSOFIMAGE = 0;
	//莉可加载
	bool left = false;
	bool right = false;
	putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
	putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
	if (NPC_LIKE.x < Myself.x) right = true;
	else if (NPC_LIKE.x > Myself.x) left = true;
	while (1)//小人移动
	{
		putimage(0, 0, &bk2);
		//放置围棋组
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//放置桌游组
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//放置游泳组
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//放置绘画组
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 0, SRCPAINT);
		//放置莉可
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, NUMBERSOFIMAGE * NPC_LIKE.rolewidth,
			0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, NUMBERSOFIMAGE * NPC_LIKE.rolewidth,
			0, SRCPAINT);
		NUMBERSOFIMAGE++;
		if (NPC_LIKE.y + NPC_LIKE.roleheight <= 720)NPC_LIKE.y += 10;//别撞南墙
		if (NUMBERSOFIMAGE == 4)
			NUMBERSOFIMAGE = 0;
		Sleep(100);
		//if (NPC_LIKE.y - Myself.y <= 5 || Myself.y - NPC_LIKE.y <= 5) break;
		if (abs(NPC_LIKE.y - Myself.y) <= 5) break;
		/*if ((Myself.x - NPC_LIKE.x == Myself.rolewidth || NPC_LIKE.x - Myself.x == Myself.rolewidth) && NPC_LIKE.y == Myself.y) break;*/
	}
	while (1)
	{
		if (left && NPC_LIKE.x - Myself.x >= Myself.rolewidth)//防止按头小分队
		{
			putimage(0, 0, &bk2);
			//放置围棋组
			putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
			putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
			//放置桌游组
			putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
			putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
			//放置游泳组
			putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
			putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
			//放置绘画组
			putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
			putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
			putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 0, SRCAND);
			putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 0, SRCPAINT);
			//放置可爱莉可
			putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, NUMBERSOFIMAGE * NPC_LIKE.rolewidth,
				48, SRCAND);
			putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, NUMBERSOFIMAGE * NPC_LIKE.rolewidth,
				48, SRCPAINT);
			/*putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 192, SRCAND);
			putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 192, SRCPAINT);*/
			NUMBERSOFIMAGE++;
			if (NPC_LIKE.x >= 0) NPC_LIKE.x -= 10;
			if (NUMBERSOFIMAGE == 3) NUMBERSOFIMAGE = 0;
		}
		else if (right && Myself.x - NPC_LIKE.x >= NPC_LIKE.rolewidth)//防止按头小分队
		{
			putimage(0, 0, &bk2);
			//放置围棋组
			putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
			putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
			//放置桌游组
			putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
			putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
			//放置游泳组
			putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
			putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
			//放置绘画组
			putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
			putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
			putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 0, SRCAND);
			putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 0, SRCPAINT);
			//放置可爱莉可
			putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, NUMBERSOFIMAGE * NPC_LIKE.rolewidth,
				96, SRCAND);
			putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, NUMBERSOFIMAGE * NPC_LIKE.rolewidth,
				96, SRCPAINT);
			/*putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 192, SRCAND);
			putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 192, SRCPAINT);*/
			NUMBERSOFIMAGE++;
			if (NPC_LIKE.x + NPC_LIKE.rolewidth <= 1280) NPC_LIKE.x += 10;
			if (NUMBERSOFIMAGE == 4) NUMBERSOFIMAGE = 0;

		}
		Sleep(100);
		//
		//if (abs(Myself.x - NPC_LIKE.x - Myself.rolewidth) <=5|| abs(NPC_LIKE.x - Myself.x - Myself.rolewidth)<=5) break;
		//if(abs(Myself.x - NPC_LIKE.x)<=5) break;
		if (right && Myself.x - NPC_LIKE.x - NPC_LIKE.rolewidth <= 5) break;
		else if (left && NPC_LIKE.x - Myself.x - Myself.x <= 5) break;
	}
	//_tprintf(_T("yeeee"));
	//Sleep(100000);
	TCHAR** CHAPTER2 = new TCHAR * [MAX_ROWS];
	for (int i = 0; i < MAX_ROWS; i++) {
		CHAPTER2[i] = new TCHAR[MAX_COLS];
	}
	FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
	errno_t err = _tfopen_s(&file, _T("res\\story\\NPC-SCORE3-LIKE-CHAPTER2.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
	if (file == NULL) {
		// 处理文件打开失败的情况
		return;
	}
	int rowIndex = 0;
	while (_fgetts(CHAPTER2[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
		rowIndex++;
		if (rowIndex >= MAX_ROWS) {
			// 处理数组内存溢出的情况
			break;
		}
	}
	/*for (int i = 0; i < CHAPTER2_WEIQI; i++) {
			_tprintf(_T("%s"), CHAPTER2[i]);
		}*/
	fclose(file);
	rowIndex = 0;
	bool onechancetouse = true;

	while (rowIndex < CHAPTER2_LIKE)//需要改 目前是6
	{
		setlinecolor(WHITE);
		rectangle(200, 600, 1080, 700);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		outtextxy(210, 640, CHAPTER2[rowIndex] + 1);
		if (CHAPTER2[rowIndex][0] == '1' && onechancetouse)
		{
			putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
			putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
			onechancetouse = false;
		}
		else if (CHAPTER2[rowIndex][0] == '4' && onechancetouse)
		{
			putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.roleY, 0, 0, SRCAND);
			putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.role, 0, 0, SRCPAINT);
			onechancetouse = false;
		}
		int CHANCE = 0;
		if (int CHANCE = _getch())
		{
			if (CHANCE == 32)
			{
				//即使退出了循环也能初始化场景。
				cleardevice();//这里是清除之前的矩形框。主打的就是懒。
				putimage(0, 0, &bk2);
				//放置围棋组
				putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
				putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
				//放置桌游组
				putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
				putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
				//放置游泳组
				putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
				putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
				//放置绘画组
				putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
				putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
				//放置自己
				putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
				putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
				//放置莉可
				putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
				putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
				//这么重要的东西放在这？？？
				rowIndex++;
				//这么重要的东西放在这？？？
				//说明一下，因为已经清屏，所以，这里的图片先载入没什么问题。
				if (CHAPTER2[rowIndex][0] == '1')//如果是1则是我
				{
					//这里有问题，图片的问题，至少是白底黑掩码图才对。代码先写着，等着换元。
					putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
					putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
				}
				else if (CHAPTER2[rowIndex][0] == '4')
				{
					putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.roleY, 0, 0, SRCAND);
					putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.role, 0, 0, SRCPAINT);
				}
			}

		}
	}
	//进入会场
	//结束 章节二，进入章节三
	chapter_2 = false;
	chapter_3 = true;

	for (int i = 0; i < MAX_ROWS; i++) {
		delete[] CHAPTER2[i];
	}
	delete[] CHAPTER2;


}
void  dialogewithYUEYUE()
{
	TCHAR** CHAPTER2 = new TCHAR * [MAX_ROWS];
	for (int i = 0; i < MAX_ROWS; i++) {
		CHAPTER2[i] = new TCHAR[MAX_COLS];
	}
	settextstyle(22, 0, _T("宋体"));
	//putimage()
	FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
	errno_t err = _tfopen_s(&file, _T("res\\story\\MUSICBEGIN-CHAPTER3.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
	if (file == NULL) {
		// 处理文件打开失败的情况
		return;
	}
	int rowIndex = 0;
	while (_fgetts(CHAPTER2[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
		rowIndex++;
		if (rowIndex >= MAX_ROWS) {
			// 处理数组内存溢出的情况
			break;
		}
	}
	/*for (int i = 0; i < CHAPTER2_WEIQI; i++) {
		_tprintf(_T("%s"), CHAPTER2[i]);
	}*/
	fclose(file);
	rowIndex = 0;
	while (rowIndex < CHAPTER3_BEGIN)//需要改 目前是6
	{
		setlinecolor(WHITE);
		rectangle(200, 600, 1080, 700);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		outtextxy(210, 640, CHAPTER2[rowIndex] + 1);
		putimage(YUEYUE_PANEL.x, YUEYUE_PANEL.y, YUEYUE_PANEL.rolewidth, YUEYUE_PANEL.roleheight, &YUEYUE_PANEL.roleY, 0, 0, SRCAND);
		putimage(YUEYUE_PANEL.x, YUEYUE_PANEL.y, YUEYUE_PANEL.rolewidth, YUEYUE_PANEL.roleheight, &YUEYUE_PANEL.role, 0, 0, SRCPAINT);
		int CHANCE = 0;
		if (int CHANCE = _getch())
		{
			if (CHANCE == 32)
			{
				cleardevice();//这里是清除之前的矩形框。主打的就是懒。
				putimage(0, 0, &BK3);
				putimage(YUEYUE_PANEL.x, YUEYUE_PANEL.y, YUEYUE_PANEL.rolewidth, YUEYUE_PANEL.roleheight, &YUEYUE_PANEL.roleY, 0, 0, SRCAND);
				putimage(YUEYUE_PANEL.x, YUEYUE_PANEL.y, YUEYUE_PANEL.rolewidth, YUEYUE_PANEL.roleheight, &YUEYUE_PANEL.role, 0, 0, SRCPAINT);
				rowIndex++;

			}
		}
	}


}
void Afterstory()
{
	cleardevice();
	putimage(0, 0, &BK3);
	TCHAR** CHAPTER2 = new TCHAR * [MAX_ROWS];
	for (int i = 0; i < MAX_ROWS; i++) {
		CHAPTER2[i] = new TCHAR[MAX_COLS];
	}
	settextstyle(22, 0, _T("宋体"));
	//putimage()
	FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
	errno_t err = _tfopen_s(&file, _T("res\\story\\MUSICAFTER-CHAPTER3.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
	if (file == NULL) {
		// 处理文件打开失败的情况
		return;
	}
	int rowIndex = 0;
	while (_fgetts(CHAPTER2[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
		rowIndex++;
		if (rowIndex >= MAX_ROWS) {
			// 处理数组内存溢出的情况
			break;
		}
	}
	/*for (int i = 0; i < CHAPTER2_WEIQI; i++) {
		_tprintf(_T("%s"), CHAPTER2[i]);
	}*/
	fclose(file);
	rowIndex = 0;//AFTERSTORY
	bool onechancetouse = true;
	while (rowIndex < AFTERSTORY)//需要改 目前是6
	{
		setlinecolor(WHITE);
		rectangle(200, 600, 1080, 700);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		outtextxy(210, 640, CHAPTER2[rowIndex] + 1);
		if (CHAPTER2[rowIndex][0] == '1' && onechancetouse)
		{
			putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
			putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
			onechancetouse = false;
		}
		else if (CHAPTER2[rowIndex][0] == '4' && onechancetouse)
		{
			putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.roleY, 0, 0, SRCAND);
			putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.role, 0, 0, SRCPAINT);
			onechancetouse = false;
		}
		int CHANCE = 0;
		if (int CHANCE = _getch())
		{
			if (CHANCE == 32)
			{
				cleardevice();
				putimage(0, 0, &BK3);
				rowIndex++;
				if (CHAPTER2[rowIndex][0] == '1')//如果是1则是我
				{
					//这里有问题，图片的问题，至少是白底黑掩码图才对。代码先写着，等着换元。
					putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
					putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
				}
				else if (CHAPTER2[rowIndex][0] == '4')
				{
					putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.roleY, 0, 0, SRCAND);
					putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.role, 0, 0, SRCPAINT);
				}
			}
		}

	}
}
void FIN()
{
	cleardevice();
	IMAGE FINAL;
	loadimage(&FINAL, _T("res\\Final.jpg"));
	putimage(40, 0, &FINAL);
	TCHAR** CHAPTERONE = new TCHAR * [MAX_ROWS];
	for (int i = 0; i < MAX_ROWS; i++) {
		CHAPTERONE[i] = new TCHAR[MAX_COLS];
	}
	FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // 使用 _tfopen 打开文档
	errno_t err = _tfopen_s(&file, _T("res\\story\\AFTERSTORYOFMIUMIU.txt"), _T("r,ccs=UTF-8"));//使用UTF-8编码方式打开
	if (file == NULL) {
		// 处理文件打开失败的情况
		return;
	}
	int rowIndex = 0;
	while (_fgetts(CHAPTERONE[rowIndex], MAX_COLS, file)) {  // 使用 _fgetts 读取文档内容
		rowIndex++;
		if (rowIndex >= MAX_ROWS) {
			// 处理数组内存溢出的情况
			break;
		}
	}
	fclose(file);
	rowIndex = 0;
	settextstyle(22, 0, _T("宋体"), 0, 0, 700, false, false, false);
	bool onechancetouse = true;
	//IMAGE BUFF;
	//getimage(&BUFF, 0, 0, 1280, 720);
	while (rowIndex < FINISH)//需要改 目前是6
	{
		setlinecolor(WHITE);
		rectangle(200, 600, 1080, 700);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);

		outtextxy(210, 640, CHAPTERONE[rowIndex] + 1);
		if (CHAPTERONE[rowIndex][0] == '1' && onechancetouse)
		{
			putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
			putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
			onechancetouse = false;
		}
		else if (CHAPTERONE[rowIndex][0] == '2')
		{
			putimage(NPC_1_panel.x, NPC_1_panel.y, NPC_1_panel.rolewidth, NPC_1_panel.roleheight, &NPC_1_panel.roleY, 0, 0, SRCAND);
			putimage(NPC_1_panel.x, NPC_1_panel.y, NPC_1_panel.rolewidth, NPC_1_panel.roleheight, &NPC_1_panel.role, 0, 0, SRCPAINT);
			onechancetouse = false;
		}
		else if (CHAPTERONE[rowIndex][0] == '3' && onechancetouse)
		{
			putimage(NPC_MENGLIN_PANEL.x, NPC_MENGLIN_PANEL.y, NPC_MENGLIN_PANEL.rolewidth, NPC_MENGLIN_PANEL.roleheight, &NPC_MENGLIN_PANEL.roleY, 0, 0, SRCAND);
			putimage(NPC_MENGLIN_PANEL.x, NPC_MENGLIN_PANEL.y, NPC_MENGLIN_PANEL.rolewidth, NPC_MENGLIN_PANEL.roleheight, &NPC_MENGLIN_PANEL.role, 0, 0, SRCPAINT);
			onechancetouse = false;
		}
		else if (CHAPTERONE[rowIndex][0] == '4' && onechancetouse)
		{
			putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.roleY, 0, 0, SRCAND);
			putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.role, 0, 0, SRCPAINT);
			onechancetouse = false;
		}
		int CHANCE = 0;
		if (int CHANCE = _getch())
		{
			if (CHANCE == 32)
			{
				cleardevice();//这里是清除之前的矩形框。主打的就是懒。

				rowIndex++;

				putimage(40, 0, &FINAL);
				//putimage(0, 0, &BUFF);
				if (CHAPTERONE[rowIndex][0] == '1')//如果是1则是我
				{
					//这里有问题，图片的问题，至少是白底黑掩码图才对。代码先写着，等着换元。
					putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.roleY, 0, 0, SRCAND);
					putimage(Myself_panel.x, Myself_panel.y, Myself_panel.rolewidth, Myself_panel.roleheight, &Myself_panel.role, 0, 0, SRCPAINT);
				}
				else if (CHAPTERONE[rowIndex][0] == '2')
				{
					putimage(NPC_1_panel.x, NPC_1_panel.y, NPC_1_panel.rolewidth, NPC_1_panel.roleheight, &NPC_1_panel.roleY, 0, 0, SRCAND);
					putimage(NPC_1_panel.x, NPC_1_panel.y, NPC_1_panel.rolewidth, NPC_1_panel.roleheight, &NPC_1_panel.role, 0, 0, SRCPAINT);
				}
				else if (CHAPTERONE[rowIndex][0] == '3')
				{
					putimage(NPC_MENGLIN_PANEL.x, NPC_MENGLIN_PANEL.y, NPC_MENGLIN_PANEL.rolewidth, NPC_MENGLIN_PANEL.roleheight, &NPC_MENGLIN_PANEL.roleY, 0, 0, SRCAND);
					putimage(NPC_MENGLIN_PANEL.x, NPC_MENGLIN_PANEL.y, NPC_MENGLIN_PANEL.rolewidth, NPC_MENGLIN_PANEL.roleheight, &NPC_MENGLIN_PANEL.role, 0, 0, SRCPAINT);
				}
				else if (CHAPTERONE[rowIndex][0] == '4')
				{
					putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.roleY, 0, 0, SRCAND);
					putimage(NPC_LIKE_PANEL.x, NPC_LIKE_PANEL.y, NPC_LIKE_PANEL.rolewidth, NPC_LIKE_PANEL.roleheight, &NPC_LIKE_PANEL.role, 0, 0, SRCPAINT);
				}
			}
		}

	}

}
int main()
{

	initgraph(Width, Height);
	bool closetheexe = false;//控制整个程序关闭
	bool gameStarted = false;//控制第一页内容
	while (!closetheexe)
	{
		
		loadimage(&YES, _T("res\\YES.jpg"));
		loadimage(&SET, _T("res\\SET.jpg"));
		
		Initialize();
		bool returntostart = false;//设置摁妞与返回摁妞的互通有无
		IMAGE BUFFER;
		getimage(&BUFFER, 0, 0, Width, Height);
		//下面的循环是开始游戏前的时候
		while (!gameStarted)
		{//gamestarted = false启动

			if (MouseHit()) {
				MOUSEMSG m = GetMouseMsg();
				if (m.x >= (Width / 2 - 75) && m.x <= Width / 2 + 75 && m.y >= Height / 2 + 50 && m.y <= Height / 2 + 100 && m.uMsg == WM_LBUTTONDOWN) {
					//开始游戏摁妞 rectangle(Width/2-75, Height/2+50, Width/2+75, Height/2+100);
					/*cleardevice();
					setbkcolor(BLACK);*/
					gameStarted = true;
				}
				else if (m.x >= (Width / 2 - 75) && m.x <= Width / 2 + 75 && m.y >= Height / 2 + 150 && m.y <= Height / 2 + 200 && m.uMsg == WM_LBUTTONDOWN) {
					//退出摁妞
					cleardevice();
					setbkcolor(BLACK);
					gameStarted = true;
					closetheexe = true;
				}
				else if (returntostart)
				{
					if (m.x >= 20 && m.x <= 50 && m.y >= 670 && m.y <= 700 && m.uMsg == WM_LBUTTONDOWN) {
						putimage(0, 0, &BUFFER);
						returntostart = false;
					}
				}
				else if (m.x >= 20 && m.x <= 50 && m.y >= 670 && m.y <= 700 && m.uMsg == WM_LBUTTONDOWN)//点到设置
				{
					cleardevice();
					putimage(40, 25, &SET);
					setbkcolor(BLACK);
					setlinestyle(PS_SOLID, 2);
					setlinecolor(CYAN);
					rectangle(20, 670, 50, 700);
					settextstyle(12, 0, _T("Consolas"));
					TCHAR SSSS[20] = L"返回";
					outtextxy(35 - textwidth(SSSS) / 2, 685 - textheight(SSSS), SSSS);
					settextstyle(48, 0, _T("Consolas"));
					TCHAR WWW[20] = L"特此鸣谢:LLX";
					int hh = textheight(WWW);
					int ww = textwidth(WWW);
					outtextxy(Width / 2 - ww / 2, Height / 4 - hh / 2, WWW);
					returntostart = true;
				}


			}
		}
		mciSendString(_T("open res/Music/BGM.mp3 alias BGM"), 0, 0, 0);
		mciSendString(_T("play BGM repeat"), 0, 0, 0);
		bool chapter_1 = false;
		bool chapter_0 = true;
		//加载缪缪
		loadimage(&Myself_panel.role, _T("res\\miumiu.png"));
		loadimage(&Myself_panel.roleY, _T("res\\miumiuY.png"));
		cleardevice();
		if (chapter_0)
		{
			INTRODUCESTRORY();
			chapter_1 = true;
		}
		cleardevice();
		TCHAR BEGIN[30] = _T("三周后，九月二十二日，星露21舍405宿舍。");
		int WWW = textwidth(BEGIN);
		int HHH = textheight(BEGIN);
		setlinecolor(WHITE);
		settextcolor(WHITE);
		outtextxy(Width / 2 - WWW / 2, Height / 2 - HHH / 2, BEGIN);
		Sleep(3000);
		loadimage(&background, _T("res\\BK1.jpg"));
		//加载背景图片
		putimage(0, 0, &background);
		//IMAGE role, roleY;//64*64 整张图是192*256
		//下面的是有问题的图片组
		//loadimage(&role, _T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\human_life2.png"));//前景图
		//loadimage(&roleY, _T("D:\\Dlutlearning\\程序设计开发\\Bighomework\\Life\\res\\human_life1.png"));//遮掩图
		//putimage(100, 500, 64, 64, &roleY, 0, 200, SRCAND);//遮掩图
		//putimage(100, 500, 64, 64, &role, 0, 200, SRCPAINT);//前景图
		loadimage(&Myself.role, _T("res\\human_life.png"));
		loadimage(&Myself.roleY, _T("res\\human_lifeY.png"));
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
		NPC_1.rolewidth = 25;
		NPC_1.roleheight = 38;
		loadimage(&NPC_1.role, _T("res\\333.png"));
		loadimage(&NPC_1.roleY, _T("res\\333Y.png"));

		//加载奈良良
		loadimage(&NPC_1_panel.role, _T("res\\ww.png"));
		loadimage(&NPC_1_panel.roleY, _T("res\\wwY.png"));
		//梦林的加载
		loadimage(&NPC_MENGLIN.role, _T("res\\MENGLIN.png"));
		loadimage(&NPC_MENGLIN.roleY, _T("res\\MENGLINY.png"));
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
		//梦林的平面图加载
		loadimage(&NPC_MENGLIN_PANEL.role, _T("res\\MENGLIN_PANEL2.png"));
		loadimage(&NPC_MENGLIN_PANEL.roleY, _T("res\\MENGLIN_PANELY2.png"));
		//放置哆啦A梦
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
		//加载莉可
		loadimage(&NPC_LIKE.role, _T("res\\莉可Q.png"));
		loadimage(&NPC_LIKE.roleY, _T("res\\莉可QY.png"));
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//加载平面莉可
		loadimage(&NPC_LIKE_PANEL.role, _T("res\\LIKE_PANNEL.png"));
		loadimage(&NPC_LIKE_PANEL.roleY, _T("res\\LIKE_PANNELY.png"));
		//加载传送法阵
		loadimage(&Chuansongzhen.role, _T("res\\CHAPTER2enterQ.png"));
		loadimage(&Chuansongzhen.roleY, _T("res\\CHAPTER2enterQY.png"));
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
		//加载影子
		loadimage(&NPC_0.role, _T("res\\miumiuY.png"));
		loadimage(&NPC_0.roleY, _T("res\\miumiuYY.png"));

		bool onechancewithNPC0 = true;
		bool key = false;
		bool chapter_2 = false;
		bool chapter_3 = false;
		while (chapter_1)
		{
			keyDonw();
			//对话提示
			dialogetishi(NPC_1);
			dialogetishi(NPC_MENGLIN);
			dialogetishi(NPC_LIKE);
			Chuansongmentishi(Chuansongzhen);
			char choice = _getch();//选择得放外面
			dialogewithNPC1(choice);
			dialogewithNPC2(choice);
			dialogewithNPC3(choice);
			if (choice == 'R')//快速第二章通道
			{
				//TOCHAPTERTWO[0] == 'A';
				//TOCHAPTERTWO[1] == 'B';
				//TOCHAPTERTWO[2] == 'C';
				key = true;
			}
			if (TOCHAPTERTWO[0] == 'A' && TOCHAPTERTWO[1] == 'B' && TOCHAPTERTWO[2] == 'C')
			{

				if (Distance(Chuansongzhen.x, Chuansongzhen.y, Myself.x, Myself.y) <= 200 && onechancewithNPC0 == true)
				{
					//g关音乐
					mciSendString(_T("stop BGM"),0,0,0);
					mciSendString(_T("close BGM"), 0, 0, 0);
					mciSendString(_T("open res/music/HOYO-MiX-Broken-Blade-破裂的剑刃.mp3 alias HAIPA"),0,0,0);
					mciSendString(_T("play HAIPA repeat"), 0, 0, 0);
					dialogewithNPC0();
					key = true;
					onechancewithNPC0 = false;
					Makeyourchoice(chapter_1, gameStarted);
				}

			}
			/*_tprintf(_T("%f"), Distance(Chuansongzhen.x + Chuansongzhen.rolewidth / 2, Chuansongzhen.y + Chuansongzhen.roleheight / 2,
				Myself.x + Myself.rolewidth / 2, Myself.y + Myself.roleheight / 2));*/
			//_tprintf(_T("%d"), key);
			//传送门
			if (key && Distance(Chuansongzhen.x + Chuansongzhen.rolewidth / 2, Chuansongzhen.y + Chuansongzhen.roleheight / 2,
				Myself.x + Myself.rolewidth / 2, Myself.y + Myself.roleheight / 2) <= 80 && choice == 32)
			{
				cleardevice();
				//xiu~
				PlaySound(TEXT("res\\Music\\XIU.wav"), NULL, SND_FILENAME | SND_ASYNC);
				mciSendString(_T("stop BGM"), 0, 0, 0);
				mciSendString(_T("close BGM"), 0, 0, 0);
				chapter_1 = false;
				chapter_2 = true;
			}

		}
		mciSendString(_T("open res/Music/HOYO-MiX-The-Exquisite-Night-Chimes-磬弦奏华夜.mp3 alias BGM2"), 0, 0, 0);
		mciSendString(_T("play BGM2 repeat"), 0, 0, 0);
		if (chapter_2)
		{
			loadimage(&WEIQI.role, _T("res\\WEIQINPC1.png"));
			loadimage(&WEIQI.roleY, _T("res\\WEIQINPC1Y.png"));
			//围棋平面
			loadimage(&WEIQI_PANEL.role, _T("res\\WEIQI1.png"));
			loadimage(&WEIQI_PANEL.roleY, _T("res\\WEIQI1Y.png"));
			loadimage(&ZHUOYOU.role, _T("res\\ZHUOYOU.png"));
			loadimage(&ZHUOYOU.roleY, _T("res\\ZHUOYOUY.png"));
			//桌游平面
			loadimage(&ZHUOYOU_PANEL.role, _T("res\\ZHUOYOUPANEL.png"));
			loadimage(&ZHUOYOU_PANEL.roleY, _T("res\\ZHUOYOUPANELY.png"));
			loadimage(&YOUYONG.role, _T("res\\YOUYONG.png"));
			loadimage(&YOUYONG.roleY, _T("res\\YOUYONGY.png"));
			//游泳平面
			loadimage(&YOUYONG_PANEL.role, _T("res\\YOUYONGPANEL.png"));
			loadimage(&YOUYONG_PANEL.roleY, _T("res\\YOUYONGPANELY.png"));
			//绘画平面
			loadimage(&HUIHUA_PANEL.role, _T("res\\HUIHUAPANEL.png"));
			loadimage(&HUIHUA_PANEL.roleY, _T("res\\HUIHUAPANELY.png"));
			//彩蛋加载
			loadimage(&CAIDAN_PANEL.role, _T("res\\CAIDANDANDANDANR.png"));
			loadimage(&CAIDAN_PANEL.roleY, _T("res\\CAIDANDANDANDANRY.png"));
			loadimage(&HUIHUA.roleY, _T("res\\HUIHUAY.png"));
			loadimage(&HUIHUA.role, _T("res\\HUIHUA.png"));
			loadimage(&BK3, _T("res\\CONCERT2.jpg"));

			Initialize_chapter2();
			INTRODUCESTORY2();
		}
		//初始化下，其实不初始化好像也行
		imageNum = 0;
		while (chapter_2) {
			keyDonw_Chapter2();
			dialogetishi(WEIQI);
			dialogetishi(HUIHUA);
			dialogetishi(YOUYONG);
			dialogetishi(ZHUOYOU);
			dialogetishi(CAIDAN);
			char Choice2 = _getch();//选择得放外面

			dialogewithWEIQI(Choice2);
			dialogewithZHUOYOU(Choice2);
			dialogewithYOUYONG(Choice2);
			dialogewithHUIHUA(Choice2);
			dialogewithCAIDAN(Choice2);
			//定位到角色为810 425 坐标
			//setlinecolor(WHITE);
			//circle(810, 425, 10);
			if (TOCHAPTERTHREE[0] == 'A' && TOCHAPTERTHREE[1] == 'B' && TOCHAPTERTHREE[2] == 'C' && TOCHAPTERTHREE[3] == 'D')
			{
				LIKECOMEON(chapter_2, chapter_3);
			}
		}
		Sleep(1000);
		mciSendString(_T("stop BGM2"), 0, 0, 0);
		mciSendString(_T("close BGM2"), 0, 0, 0);
		
		if (chapter_3)
		{
			putimage(0, 0, &BK3);
			loadimage(&YUEYUE_PANEL.role, _T("res\\YUEYUEPANEL.png"));
			loadimage(&YUEYUE_PANEL.roleY, _T("res\\YUEYUEPANELY.png"));

			dialogewithYUEYUE();
			cleardevice();
			IMAGE YANCHANGHUI;
			loadimage(&YANCHANGHUI, _T("res\\K-ON!!2.jpg"));
			putimage(0, 0, &YANCHANGHUI);
			mciSendString(_T("play res/Music/HTT.mp3"), 0, 0, 0);
			Sleep(257000);//4min17s   257s  257000ms
			mciSendString(_T("open res/Music/BGM.mp3 alias BGM"), 0, 0, 0);
			mciSendString(_T("play BGM repeat"), 0, 0, 0);
			Afterstory();
			mciSendString(_T("stop BGM"), 0, 0, 0);
			mciSendString(_T("close BGM"), 0, 0, 0);
			mciSendString(_T("open res/Music/HOYO-MiX-The-Caress-of-Three-Mothers-女主人的叮咛.mp3 alias BGM3"), 0, 0, 0);
			mciSendString(_T("play BGM3 repeat"), 0, 0, 0);
			FIN();
			
			cleardevice();
			IMAGE BB1;
			loadimage(&BB1, _T("res\\Final.jpg"));
			putimage(40, 0, &BB1);
			setlinecolor(BLACK);
			TCHAR BB[30] = _T("THANKS FOR PLAYING");
			int width = textwidth(BB);
			int height = textheight(BB);
			outtextxy(Width / 2 - width / 2, Height / 2 - height / 2, BB);
			Sleep(5000);
			mciSendString(_T("stop BGM3"), 0, 0, 0);
			mciSendString(_T("close BGM3"), 0, 0, 0);
			gameStarted = false;
		}

	}

	closegraph();
	_getch();
	return 0;
}