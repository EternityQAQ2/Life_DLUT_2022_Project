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
	//�Ե�����Ϸ������д
	putimage(40, 40, &YES);
	IMAGE set;
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy_s(f.lfFaceName, _T("Arial"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	TCHAR S[20] = L"ѡ��";
	int h = textheight(S);
	int w = textwidth(S);
	outtextxy(Width / 2 - w / 2, Height / 4 - h / 2, S);

	//����ʼ���
	setlinestyle(PS_SOLID, 2);
	setlinecolor(WHITE);
	rectangle(Width / 2 - 75, Height / 2 + 50, Width / 2 + 75, Height / 2 + 100);
	TCHAR SS[20] = L"��ʼ��Ϸ";
	settextstyle(24, 0, _T("Consolas"));
	setbkmode(TRANSPARENT);
	outtextxy(Width / 2 - textwidth(SS) / 2, Height / 2 + 75 - textheight(SS) / 2, SS);
	//�˳���Ϸ���
	setlinestyle(PS_SOLID, 2);
	setlinecolor(WHITE);
	rectangle(Width / 2 - 75, Height / 2 + 150, Width / 2 + 75, Height / 2 + 200);
	TCHAR SSS[20] = L"�ر���Ϸ";
	settextstyle(24, 0, _T("Consolas"));
	setbkmode(TRANSPARENT);
	outtextxy(Width / 2 - textwidth(SSS) / 2, Height / 2 + 175 - textheight(SSS) / 2, SSS);

	setlinestyle(PS_SOLID, 2);
	setlinecolor(CYAN);
	rectangle(20, 670, 50, 700);
	settextstyle(12, 0, _T("Consolas"));
	TCHAR SSSS[20] = L"����";
	outtextxy(35 - textwidth(SSSS) / 2, 685 - textheight(SSSS), SSSS);
}
void Initialize_chapter2()
{
	loadimage(&bk2, _T("res\\BK2_2.png"));

	Myself.x = 450;
	Myself.y = 550;
	putimage(0, 0, &bk2);
	//����Χ����
	putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
	putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
	//����������
	putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
	putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
	//������Ӿ��
	putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
	putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
	//���û滭��
	putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
	putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
	//�����Լ�
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
		//�������
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//���ͷ���
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 192, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 192, SRCPAINT);

		imageNum++;
		if (Myself.y > 0) Myself.y -= 10;//��ײͷ
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
		//�������
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//���ͷ���
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 0, SRCPAINT);


		imageNum++;
		if (Myself.y + Myself.roleheight <= 720)Myself.y += 10;//��ײ��ǽ
		if (imageNum == 3)
			imageNum = 0;
		break;
	case 'a':
	case 'A':
	case 75:
		putimage(0, 0, &background);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
		//���ּ���
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
		//�������
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//���ͷ���
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
		//���ּ���
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
		//�������
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//���ͷ���
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
		//����Χ����
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//����������
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//������Ӿ��
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//���û滭��
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 192, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 192, SRCPAINT);
		imageNum++;
		if (Myself.y > 0) Myself.y -= 10;//��ײͷ
		if (imageNum == 3) imageNum = 0;
		break;

	case 's':
	case 'S':
	case 80:
		putimage(0, 0, &bk2);
		//����Χ����
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//����������
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//������Ӿ��
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//���û滭��
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 0, SRCPAINT);
		imageNum++;
		if (Myself.y + Myself.roleheight <= 720)Myself.y += 10;//��ײ��ǽ
		if (imageNum == 3)
			imageNum = 0;
		break;
	case 'a':
	case 'A':
	case 75:
		putimage(0, 0, &bk2);
		//����Χ����
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//����������
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//������Ӿ��
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//���û滭��
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
		//����Χ����
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//����������
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//������Ӿ��
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//���û滭��
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


	FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
	errno_t err = _tfopen_s(&file, _T("res\\story\\Introduce.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
	if (file == NULL) {
		// �����ļ���ʧ�ܵ����
		return;
	}
	int rowIndex = 0;
	while (_fgetts(CHAPTERONE[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
		rowIndex++;
		if (rowIndex >= MAX_ROWS) {
			// ���������ڴ���������
			break;
		}
	}
	fclose(file);
	rowIndex = 0;
	settextstyle(22, 0, _T("����"), 0, 0, 700, false, false, false);
	bool onechancetouse = true;
	while (rowIndex < BEGINSTORY)//��Ҫ�� Ŀǰ��6
	{
		//�Ի����С��λ��
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
				cleardevice();//���������֮ǰ�ľ��ο�����ľ�������
				rowIndex++;
				putimage(0, 0, &bk0);
				if (CHAPTERONE[rowIndex][0] == '1')//�����1������
				{
					//���������⣬ͼƬ�����⣬�����ǰ׵׺�����ͼ�Ŷԡ�������д�ţ����Ż�Ԫ��
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
		//�����IF����ǽ���Ի���
		TCHAR** CHAPTERONE = new TCHAR * [MAX_ROWS];
		for (int i = 0; i < MAX_ROWS; i++) {
			CHAPTERONE[i] = new TCHAR[MAX_COLS];
		}
		settextstyle(24, 0, _T("����"));
		//��������� press space to talk
		cleardevice();
		putimage(0, 0, &background);

		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
		//���ּ���
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
		//��ɼ���
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//���ͷ���
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);

		TOCHAPTERTWO[0] = 'A';

		_setmode(_fileno(stdout), _O_U8TEXT);  // ���ÿ���̨���ΪUTF-8����

		FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
		errno_t err = _tfopen_s(&file, _T("res\\story\\NPC1-CHAPTER1.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
		if (file == NULL) {
			// �����ļ���ʧ�ܵ����
			return;
		}
		int rowIndex = 0;
		while (_fgetts(CHAPTERONE[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
			rowIndex++;
			if (rowIndex >= MAX_ROWS) {
				// ���������ڴ���������
				break;
			}
		}
		fclose(file);
		//����ı��ĺ������Ժ�ɾ����
		//for (int i = 0; i < rowIndex; i++) {
		//	_tprintf(_T("%s"), CHAPTERONE[i]);
		//}


		//�Ի�ѭ��
		rowIndex = 0;
		bool onechancetouse = true;
		while (rowIndex < CHAPTERONE_NPC1_ROW)//��Ҫ�� Ŀǰ��6
		{
			//�Ի����С��λ��
			setlinecolor(WHITE);
			rectangle(200, 600, 1080, 700);
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			outtextxy(210, 640, CHAPTERONE[rowIndex] + 1);
			//������Ϊ����ǰ�Ѿ��ο�λΧ�����ˣ�����ͼƬҲ������ǰ��������һ���Եģ��о����Ǻܺÿ������룩����������Ժ��Ż���
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
					//��ʹ�˳���ѭ��Ҳ�ܳ�ʼ��������
					cleardevice();//���������֮ǰ�ľ��ο�����ľ�������
					putimage(0, 0, &background);
					//�Ž�ɫ
					putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
					putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
					//���ּ���
					putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
					putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
					//��ɼ���
					putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
					putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
					//���ͷ���
					putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
					putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);

					//��ô��Ҫ�Ķ��������⣿����
					rowIndex++;
					//��ô��Ҫ�Ķ��������⣿����
					//˵��һ�£���Ϊ�Ѿ����������ԣ������ͼƬ������ûʲô���⡣
					if (CHAPTERONE[rowIndex][0] == '1')//�����1������
					{
						//���������⣬ͼƬ�����⣬�����ǰ׵׺�����ͼ�Ŷԡ�������д�ţ����Ż�Ԫ��
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


		//�ͷ��ڴ����
		for (int i = 0; i < MAX_ROWS; i++) {
			delete[] CHAPTERONE[i];
		}
		delete[] CHAPTERONE;


	}

}
void dialogewithNPC2(char choice)
{
	bool whototalk = false;//false �����˹���
	bool restart_flag = true;
	if (choice == 32 && Distance(NPC_MENGLIN.x + NPC_MENGLIN.rolewidth / 2, NPC_MENGLIN.y + NPC_MENGLIN.roleheight / 2, Myself.x + Myself.rolewidth / 2, Myself.y + Myself.roleheight / 2) <= 80)
	{
		//�����IF����ǽ���Ի���
		//const int MAX_ROWS = 40;  // �������
		//const int MAX_COLS = 40;  // �������
		////TCHAR CHAPTERONE[MAX_ROWS][MAX_COLS]; �����ά����
		TCHAR** CHAPTERONE = new TCHAR * [MAX_ROWS];
		for (int i = 0; i < MAX_ROWS; i++) {
			CHAPTERONE[i] = new TCHAR[MAX_COLS];
		}

		settextstyle(24, 0, _T("����"));
		//��������� press space to talk
		cleardevice();
		putimage(0, 0, &background);

		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
		//���ּ���
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
		//��ɼ���
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//���ͷ���
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);

		TOCHAPTERTWO[1] = 'B';

		FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
		errno_t err = _tfopen_s(&file, _T("res\\story\\NPC2-CHAPTER1.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
		if (file == NULL) {
			// �����ļ���ʧ�ܵ����
			return;
		}
		int rowIndex = 0;
		while (_fgetts(CHAPTERONE[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
			rowIndex++;
			if (rowIndex >= MAX_ROWS) {
				// ���������ڴ���������
				break;
			}
		}
		fclose(file);
		//����ı��ĺ������Ժ�ɾ����

		//�Ի�ѭ��
		rowIndex = 0;
		bool onechancetouse = true;
		while (rowIndex < CHAPTERONE_NPC2_ROW)//��Ҫ�� Ŀǰ��6
		{
			//�Ի����С��λ��
			setlinecolor(WHITE);
			rectangle(200, 600, 1080, 700);
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			outtextxy(210, 640, CHAPTERONE[rowIndex] + 1);
			//������Ϊ����ǰ�Ѿ��ο�λΧ�����ˣ�����ͼƬҲ������ǰ��������һ���Եģ��о����Ǻܺÿ������룩����������Ժ��Ż���
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
					//��ʹ�˳���ѭ��Ҳ�ܳ�ʼ��������
					cleardevice();//���������֮ǰ�ľ��ο�����ľ�������
					putimage(0, 0, &background);
					//�Ž�ɫ
					putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
					putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
					//���ּ���
					putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
					putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
					//��ɼ���
					putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
					putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
					//���ͷ���
					putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
					putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);

					//��ô��Ҫ�Ķ��������⣿����
					rowIndex++;
					//��ô��Ҫ�Ķ��������⣿����
					//˵��һ�£���Ϊ�Ѿ����������ԣ������ͼƬ������ûʲô���⡣
					if (CHAPTERONE[rowIndex][0] == '1')//�����1������
					{
						//���������⣬ͼƬ�����⣬�����ǰ׵׺�����ͼ�Ŷԡ�������д�ţ����Ż�Ԫ��
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


		//�ͷ��ڴ����
		for (int i = 0; i < MAX_ROWS; i++) {
			delete[] CHAPTERONE[i];
		}
		delete[] CHAPTERONE;


	}
}
void dialogewithNPC3(char choice)
{
	bool whototalk = false;//false �����˹���
	bool restart_flag = true;
	if (choice == 32 && Distance(NPC_LIKE.x + NPC_LIKE.rolewidth / 2, NPC_LIKE.y + NPC_LIKE.roleheight / 2, Myself.x + Myself.rolewidth / 2, Myself.y + Myself.roleheight / 2) <= 80)
	{
		//�����IF����ǽ���Ի���

		TCHAR** CHAPTERONE = new TCHAR * [MAX_ROWS];
		for (int i = 0; i < MAX_ROWS; i++) {
			CHAPTERONE[i] = new TCHAR[MAX_COLS];
		}

		settextstyle(24, 0, _T("����"));
		//��������� press space to talk
		cleardevice();
		putimage(0, 0, &background);

		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
		//���ּ���
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
		//��ɼ���
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//���ͷ���
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
		//��Կ
		TOCHAPTERTWO[2] = 'C';
		FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
		errno_t err = _tfopen_s(&file, _T("res\\story\\NPC3-CHAPTER1.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
		if (file == NULL) {
			// �����ļ���ʧ�ܵ����
			return;
		}
		int rowIndex = 0;
		while (_fgetts(CHAPTERONE[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
			rowIndex++;
			if (rowIndex >= MAX_ROWS) {
				// ���������ڴ���������
				break;
			}
		}
		fclose(file);
		//����ı��ĺ������Ժ�ɾ����
		/*for (int i = 0; i < rowIndex; i++) {
			_tprintf(_T("%s"), CHAPTERONE[i]);
		}*/


		//�Ի�ѭ��
		rowIndex = 0;
		bool onechancetouse = true;
		while (rowIndex < CHPTERONE_NPC3_ROW)//��Ҫ�� Ŀǰ��6
		{
			//�Ի����С��λ��
			setlinecolor(WHITE);
			rectangle(200, 600, 1080, 700);
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			outtextxy(210, 640, CHAPTERONE[rowIndex] + 1);
			//������Ϊ����ǰ�Ѿ��ο�λΧ�����ˣ�����ͼƬҲ������ǰ��������һ���Եģ��о����Ǻܺÿ������룩����������Ժ��Ż���
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
					//��ʹ�˳���ѭ��Ҳ�ܳ�ʼ��������
					cleardevice();//���������֮ǰ�ľ��ο�����ľ�������
					putimage(0, 0, &background);
					//�Ž�ɫ
					putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
					putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
					//���ּ���
					putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
					putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
					//��ɼ���
					putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
					putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
					//���ͷ���
					putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
					putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);

					//��ô��Ҫ�Ķ��������⣿����
					rowIndex++;
					//��ô��Ҫ�Ķ��������⣿����
					//˵��һ�£���Ϊ�Ѿ����������ԣ������ͼƬ������ûʲô���⡣
					if (CHAPTERONE[rowIndex][0] == '1')//�����1������
					{
						//���������⣬ͼƬ�����⣬�����ǰ׵׺�����ͼ�Ŷԡ�������д�ţ����Ż�Ԫ��
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


		//�ͷ��ڴ����
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
	settextstyle(24, 0, _T("����"));
	FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
	errno_t err = _tfopen_s(&file, _T("res\\story\\NPC0-CHAPTER1.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
	if (file == NULL) {
		// �����ļ���ʧ�ܵ����
		return;
	}
	int rowIndex = 0;
	while (_fgetts(CHAPTERONE[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
		rowIndex++;
		if (rowIndex >= MAX_ROWS) {
			// ���������ڴ���������
			break;
		}
	}
	fclose(file);
	//����ı��ĺ������Ժ�ɾ����
	/*for (int i = 0; i < rowIndex; i++) {
		_tprintf(_T("%s"), CHAPTERONE[i]);
	}*/
	rowIndex = 0;
	bool onechancetouse = true;
	while (rowIndex < CHPTERONE_NPC0_ROW)//��Ҫ�� Ŀǰ��6
	{
		//�Ի����С��λ��
		setlinecolor(WHITE);
		rectangle(200, 600, 1080, 700);
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		outtextxy(210, 640, CHAPTERONE[rowIndex] + 1);
		//������Ϊ����ǰ�Ѿ��ο�λΧ�����ˣ�����ͼƬҲ������ǰ��������һ���Եģ��о����Ǻܺÿ������룩����������Ժ��Ż���
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
				//��ʹ�˳���ѭ��Ҳ�ܳ�ʼ��������
				cleardevice();//���������֮ǰ�ľ��ο�����ľ�������
				putimage(0, 0, &background);
				//�Ž�ɫ
				putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
				putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
				//���ּ���
				putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
				putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
				//��ɼ���
				putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
				putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
				//���ͷ���
				putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
				putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
				putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
				putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);

				//��ô��Ҫ�Ķ��������⣿����
				rowIndex++;
				//��ô��Ҫ�Ķ��������⣿����
				//˵��һ�£���Ϊ�Ѿ����������ԣ������ͼƬ������ûʲô���⡣
				if (CHAPTERONE[rowIndex][0] == '1')//�����1������
				{
					//���������⣬ͼƬ�����⣬�����ǰ׵׺�����ͼ�Ŷԡ�������д�ţ����Ż�Ԫ��
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
	//������ڴ�
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
	settextstyle(18, 0, _T("����"));
	setbkmode(TRANSPARENT);
	TCHAR CHOICE[30] = L"MAKE YOUR CHOICE";
	int width = textwidth(CHOICE);
	int height = textheight(CHOICE);
	outtextxy(640 - width / 2, 545 - height / 2, CHOICE);
	TCHAR CHOICE1[30] = L"լ������";
	TCHAR CHOICE2[30] = L"�μӼ��껪";
	rectangle(200, 595, 400, 645);
	width = textwidth(CHOICE1);
	height = textheight(CHOICE1);
	outtextxy(300 - width / 2, 620 - height / 2, CHOICE1);
	rectangle(880, 595, 1080, 645);
	width = textwidth(CHOICE2);
	height = textheight(CHOICE2);
	outtextxy(980 - width / 2, 620 - height / 2, CHOICE2);
	//������ά����

	while (1)
	{
		//bool onechancetouse = true;
		if (MouseHit())
		{
			MOUSEMSG m = GetMouseMsg();
			if (m.x >= 200 && m.x <= 400 && m.y >= 595 && m.y <= 645 && m.uMsg == WM_LBUTTONDOWN)//լ�������ѡ��
			{
				TCHAR** CHAPTERZERO = new TCHAR * [MAX_ROWS];
				for (int i = 0; i < MAX_ROWS; i++) {
					CHAPTERZERO[i] = new TCHAR[MAX_COLS];
				}
				cleardevice();
				putimage(40, 40, &BADEND);
				//�رտֲ���ɭ������
				mciSendString(_T("stop HAIPA"), 0, 0, 0);
				mciSendString(_T("close HAIPA"), 0, 0, 0);
				//���ű�������
				mciSendString(_T("open res/Music/402422124.mp3 alias SONG"), 0, 0, 0);
				mciSendString(_T("play SONG repeat"), 0, 0, 0);

				FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
				errno_t err = _tfopen_s(&file, _T("res\\story\\BADENDCHAPTER1.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
				if (file == NULL) {
					// �����ļ���ʧ�ܵ����
					return;
				}

				int rowIndex = 0;

				while (_fgetts(CHAPTERZERO[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
					rowIndex++;
					if (rowIndex >= MAX_ROWS) {
						// ���������ڴ���������
						break;
					}
				}
				fclose(file);
				rowIndex = 0;
				settextstyle(24, 0, _T("����"));
				//ʵ�ִ��ֻ�Ч��
				while (rowIndex < BADENDCHAPTER1)
				{
					//ȷ�����־��С�
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
				//������Ϸ
				//Sleep(10000);
				TCHAR CHOICE_RESTART[30] = L"RESTART GAME?";
				width = textwidth(CHOICE_RESTART);
				height = textheight(CHOICE_RESTART);
				outtextxy(100 - width / 2, 360 - height / 2, CHOICE_RESTART);
				TCHAR RESTART[10] = L"��";
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
							gamestarted = false;//������Ϸ
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
				//�˳�WHILE(1)��
				break;
			}
			else if (m.x >= 880 && m.x <= 1080 && m.y >= 595 && m.y <= 645 && m.uMsg == WM_LBUTTONDOWN)
			{
				int rowIndex = 0;
				//�жϵ�һ�εķ���ͼƬ����
				mciSendString(_T("stop HAIPA"), 0, 0, 0);
				mciSendString(_T("close HAIPA"), 0, 0, 0);
				mciSendString(_T("open res/Music/BGM.mp3 alias BGM"), 0, 0, 0);
				mciSendString(_T("play BGM repeat"), 0, 0, 0);
				settextstyle(24, 0, _T("����"));
				bool onechancetouse = true;
				TCHAR** CHAPTERZEROAFTER = new TCHAR * [MAX_ROWS];
				for (int i = 0; i < MAX_ROWS; i++) {
					CHAPTERZEROAFTER[i] = new TCHAR[MAX_COLS];
				}

				FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
				errno_t err = _tfopen_s(&file, _T("res\\story\\NPC0-CHAPTER1-AFTER.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
				if (file == NULL) {
					// �����ļ���ʧ�ܵ����
					return;
				}

				while (_fgetts(CHAPTERZEROAFTER[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
					rowIndex++;
					if (rowIndex >= MAX_ROWS) {
						// ���������ڴ���������
						break;
					}
				}

				rowIndex = 0;

				setlinecolor(WHITE);
				settextcolor(WHITE);
				setbkmode(TRANSPARENT);

				cleardevice();
				putimage(0, 0, &background);
				//�Ž�ɫ
				putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
				putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
				//���ּ���
				putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
				putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
				//��ɼ���
				putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
				putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
				//���ͷ���
				putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
				putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
				putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
				putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
				while (rowIndex < BADENDCHAPTER1_AFTER)//��Ҫ�� Ŀǰ��6
				{
					//�Ի����С��λ��
					rectangle(200, 600, 1080, 700);
					outtextxy(210, 640, CHAPTERZEROAFTER[rowIndex] + 1);
					//������Ϊ����ǰ�Ѿ��ο�λΧ�����ˣ�����ͼƬҲ������ǰ��������һ���Եģ��о����Ǻܺÿ������룩����������Ժ��Ż���
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
							//��ʹ�˳���ѭ��Ҳ�ܳ�ʼ��������
							cleardevice();//���������֮ǰ�ľ��ο�����ľ�������
							putimage(0, 0, &background);
							//�Ž�ɫ
							putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
							putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
							//���ּ���
							putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
							putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
							//��ɼ���
							putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
							putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
							//���ͷ���
							putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
							putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
							putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
							putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);

							//��ô��Ҫ�Ķ��������⣿����
							rowIndex++;
							//��ô��Ҫ�Ķ��������⣿����
							//˵��һ�£���Ϊ�Ѿ����������ԣ������ͼƬ������ûʲô���⡣
							if (CHAPTERZEROAFTER[rowIndex][0] == '1')//�����1������
							{
								//���������⣬ͼƬ�����⣬�����ǰ׵׺�����ͼ�Ŷԡ�������д�ţ����Ż�Ԫ��
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
				//�˳�WHILE(1)��
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


	FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
	errno_t err = _tfopen_s(&file, _T("res\\story\\Introduce2.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
	if (file == NULL) {
		// �����ļ���ʧ�ܵ����
		return;
	}
	int rowIndex = 0;
	while (_fgetts(CHAPTERONE[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
		rowIndex++;
		if (rowIndex >= MAX_ROWS) {
			// ���������ڴ���������
			break;
		}
	}
	fclose(file);
	rowIndex = 0;
	settextstyle(22, 0, _T("����"), 0, 0, 700, false, false, false);
	setlinestyle(PS_SOLID, 2);
	bool onechancetouse = true;
	IMAGE BUFF;
	getimage(&BUFF, 0, 0, 1280, 720);
	while (rowIndex < Introduce2)//��Ҫ�� Ŀǰ��6
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
				cleardevice();//���������֮ǰ�ľ��ο�����ľ�������
				rowIndex++;
				putimage(0, 0, &BUFF);
				if (CHAPTERONE[rowIndex][0] == '1')//�����1������
				{
					//���������⣬ͼƬ�����⣬�����ǰ׵׺�����ͼ�Ŷԡ�������д�ţ����Ż�Ԫ��
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
		settextstyle(22, 0, _T("����"));
		//��������� press space to talk
		cleardevice();
		putimage(0, 0, &bk2);
		//����Χ����
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//����������
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//������Ӿ��
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//���û滭��
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		//�����Լ�
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
		TOCHAPTERTHREE[0] = 'A';
		FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
		errno_t err = _tfopen_s(&file, _T("res\\story\\NPC-WEIQI-CHAPTER2.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
		if (file == NULL) {
			// �����ļ���ʧ�ܵ����
			return;
		}

		_setmode(_fileno(stdout), _O_U8TEXT);  // ���ÿ���̨���ΪUTF-8����

		int rowIndex = 0;
		while (_fgetts(CHAPTER2[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
			rowIndex++;
			if (rowIndex >= MAX_ROWS) {
				// ���������ڴ���������
				break;
			}
		}
		for (int i = 0; i < CHAPTER2_WEIQI; i++) {
			_tprintf(_T("%s"), CHAPTER2[i]);
		}
		fclose(file);
		rowIndex = 0;
		bool onechancetouse = true;
		while (rowIndex < CHAPTER2_WEIQI)//��Ҫ�� Ŀǰ��6
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
					//��ʹ�˳���ѭ��Ҳ�ܳ�ʼ��������
					cleardevice();//���������֮ǰ�ľ��ο�����ľ�������
					putimage(0, 0, &bk2);
					//����Χ����
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
					//����������
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
					//������Ӿ��
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
					//���û滭��
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
					//�����Լ�
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
					//��ô��Ҫ�Ķ��������⣿����
					rowIndex++;
					//��ô��Ҫ�Ķ��������⣿����
					//˵��һ�£���Ϊ�Ѿ����������ԣ������ͼƬ������ûʲô���⡣
					if (CHAPTER2[rowIndex][0] == '1')//�����1������
					{
						//���������⣬ͼƬ�����⣬�����ǰ׵׺�����ͼ�Ŷԡ�������д�ţ����Ż�Ԫ��
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
		settextstyle(22, 0, _T("����"));
		//��������� press space to talk
		cleardevice();
		putimage(0, 0, &bk2);
		//����Χ����
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//����������
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//������Ӿ��
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//���û滭��
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		//�����Լ�
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
		TOCHAPTERTHREE[1] = 'B';
		FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
		errno_t err = _tfopen_s(&file, _T("res\\story\\NPC-ZHUOYOU-CHAPTER2.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
		if (file == NULL) {
			// �����ļ���ʧ�ܵ����
			return;
		}

		_setmode(_fileno(stdout), _O_U8TEXT);  // ���ÿ���̨���ΪUTF-8����

		int rowIndex = 0;
		while (_fgetts(CHAPTER2[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
			rowIndex++;
			if (rowIndex >= MAX_ROWS) {
				// ���������ڴ���������
				break;
			}
		}
		/*for (int i = 0; i < CHAPTER2_WEIQI; i++) {
			_tprintf(_T("%s"), CHAPTER2[i]);
		}*/
		fclose(file);
		rowIndex = 0;
		bool onechancetouse = true;

		while (rowIndex < CHAPTER2_ZHUOYOU)//��Ҫ�� Ŀǰ��6
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
					//��ʹ�˳���ѭ��Ҳ�ܳ�ʼ��������
					cleardevice();//���������֮ǰ�ľ��ο�����ľ�������
					putimage(0, 0, &bk2);
					//����Χ����
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
					//����������
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
					//������Ӿ��
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
					//���û滭��
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
					//�����Լ�
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
					//��ô��Ҫ�Ķ��������⣿����
					rowIndex++;
					//��ô��Ҫ�Ķ��������⣿����
					//˵��һ�£���Ϊ�Ѿ����������ԣ������ͼƬ������ûʲô���⡣
					if (CHAPTER2[rowIndex][0] == '1')//�����1������
					{
						//���������⣬ͼƬ�����⣬�����ǰ׵׺�����ͼ�Ŷԡ�������д�ţ����Ż�Ԫ��
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
		settextstyle(22, 0, _T("����"));
		//��������� press space to talk
		cleardevice();
		putimage(0, 0, &bk2);
		//����Χ����
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//����������
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//������Ӿ��
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//���û滭��
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		//�����Լ�
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
		TOCHAPTERTHREE[2] = 'C';
		FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
		errno_t err = _tfopen_s(&file, _T("res\\story\\NPC-YOUYONG-CHAPTER2.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
		if (file == NULL) {
			// �����ļ���ʧ�ܵ����
			return;
		}

		_setmode(_fileno(stdout), _O_U8TEXT);  // ���ÿ���̨���ΪUTF-8����

		int rowIndex = 0;
		while (_fgetts(CHAPTER2[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
			rowIndex++;
			if (rowIndex >= MAX_ROWS) {
				// ���������ڴ���������
				break;
			}
		}
		/*for (int i = 0; i < CHAPTER2_WEIQI; i++) {
			_tprintf(_T("%s"), CHAPTER2[i]);
		}*/
		fclose(file);
		rowIndex = 0;
		bool onechancetouse = true;

		while (rowIndex < CHAPTER2_YOUYONG)//��Ҫ�� Ŀǰ��6
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
					//��ʹ�˳���ѭ��Ҳ�ܳ�ʼ��������
					cleardevice();//���������֮ǰ�ľ��ο�����ľ�������
					putimage(0, 0, &bk2);
					//����Χ����
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
					//����������
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
					//������Ӿ��
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
					//���û滭��
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
					//�����Լ�
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
					//��ô��Ҫ�Ķ��������⣿����
					rowIndex++;
					//��ô��Ҫ�Ķ��������⣿����
					//˵��һ�£���Ϊ�Ѿ����������ԣ������ͼƬ������ûʲô���⡣
					if (CHAPTER2[rowIndex][0] == '1')//�����1������
					{
						//���������⣬ͼƬ�����⣬�����ǰ׵׺�����ͼ�Ŷԡ�������д�ţ����Ż�Ԫ��
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
		settextstyle(22, 0, _T("����"));
		//��������� press space to talk
		cleardevice();
		putimage(0, 0, &bk2);
		//����Χ����
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//����������
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//������Ӿ��
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//���û滭��
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		//�����Լ�
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
		TOCHAPTERTHREE[3] = 'D';
		FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
		errno_t err = _tfopen_s(&file, _T("res\\story\\NPC-HUIHUA-CHAPTER2.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
		if (file == NULL) {
			// �����ļ���ʧ�ܵ����
			return;
		}

		_setmode(_fileno(stdout), _O_U8TEXT);  // ���ÿ���̨���ΪUTF-8����

		int rowIndex = 0;
		while (_fgetts(CHAPTER2[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
			rowIndex++;
			if (rowIndex >= MAX_ROWS) {
				// ���������ڴ���������
				break;
			}
		}
		/*for (int i = 0; i < CHAPTER2_WEIQI; i++) {
			_tprintf(_T("%s"), CHAPTER2[i]);
		}*/
		fclose(file);
		rowIndex = 0;
		bool onechancetouse = true;

		while (rowIndex < CHAPTER2_HUIHUA)//��Ҫ�� Ŀǰ��6
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
					//��ʹ�˳���ѭ��Ҳ�ܳ�ʼ��������
					cleardevice();//���������֮ǰ�ľ��ο�����ľ�������
					putimage(0, 0, &bk2);
					//����Χ����
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
					putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
					//����������
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
					putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
					//������Ӿ��
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
					putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
					//���û滭��
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
					putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
					//�����Լ�
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
					putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
					//��ô��Ҫ�Ķ��������⣿����
					rowIndex++;
					//��ô��Ҫ�Ķ��������⣿����
					//˵��һ�£���Ϊ�Ѿ����������ԣ������ͼƬ������ûʲô���⡣
					if (CHAPTER2[rowIndex][0] == '1')//�����1������
					{
						//���������⣬ͼƬ�����⣬�����ǰ׵׺�����ͼ�Ŷԡ�������д�ţ����Ż�Ԫ��
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
		//����Χ����
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//����������
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//������Ӿ��
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//���û滭��
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		//�����Լ�
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
		setlinecolor(YELLOW);
		rectangle(200, 600, 1080, 700);
		settextcolor(YELLOW);
		setbkmode(TRANSPARENT);
		settextstyle(24, 0, _T("����"));
		TCHAR CAIDAN[30] = _T("��Ϸ���糤��Ҫ�������������ĵ�����Ϸ��");
		outtextxy(210, 640, CAIDAN);
		putimage(CAIDAN_PANEL.x, CAIDAN_PANEL.y, CAIDAN_PANEL.rolewidth, CAIDAN_PANEL.roleheight, &CAIDAN_PANEL.roleY, 0, 0, SRCAND);
		putimage(CAIDAN_PANEL.x, CAIDAN_PANEL.y, CAIDAN_PANEL.rolewidth, CAIDAN_PANEL.roleheight, &CAIDAN_PANEL.role, 0, 0, SRCPAINT);
		char CHOICE = _getch();
		if (CHOICE == 32)
		{
			cleardevice();
			putimage(0, 0, &bk2);
			//����Χ����
			putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
			putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
			//����������
			putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
			putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
			//������Ӿ��
			putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
			putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
			//���û滭��
			putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
			putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
			//�����Լ�
			putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
			putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
			//����ѡ��
			settextstyle(18, 0, _T("����"));
			TCHAR CHOICE1[20] = L"����";
			TCHAR CHOICE2[20] = L"������";
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
					if (m.x >= 200 && m.x <= 400 && m.y >= 595 && m.y <= 645 && m.uMsg == WM_LBUTTONDOWN)//����ѡ��
					{
						//���������ƶ�60 ���������ƶ�340
						playgame();
						cleardevice();
						setlinecolor(YELLOW);
						settextcolor(YELLOW);
						putimage(0, 0, &bk2);
						//����Χ����
						putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
						putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
						//����������
						putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
						putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
						//������Ӿ��
						putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
						putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
						//���û滭��
						putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
						putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
						//�����Լ�
						putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
						putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
						TCHAR THANKS[20] = _T("��л��������");
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
								//����Χ����
								putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
								putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
								//����������
								putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
								putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
								//������Ӿ��
								putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
								putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
								//���û滭��
								putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
								putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
								//�����Լ�
								putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
								putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
								break;
							}
						}
						break;
					}
					else if (m.x >= 880 && m.x <= 1080 && m.y >= 595 && m.y <= 645 && m.uMsg == WM_LBUTTONDOWN)//������ѡ��
					{
						cleardevice();
						putimage(0, 0, &bk2);
						//����Χ����
						putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
						putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
						//����������
						putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
						putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
						//������Ӿ��
						putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
						putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
						//���û滭��
						putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
						putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
						//�����Լ�
						putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
						putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
						settextstyle(24, 0, _T("����"));
						TCHAR WUWU[20] = _T("�ðɻ�ӭ�´�����");
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
								//����Χ����
								putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
								putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
								//����������
								putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
								putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
								//������Ӿ��
								putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
								putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
								//���û滭��
								putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
								putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
								//�����Լ�
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
void LIKECOMEON(bool& chapter_2, bool& chapter_3)//�����İ�Կ�׺󷽿�����
{
	NPC_LIKE.x = 500;
	NPC_LIKE.y = -48;
	int NUMBERSOFIMAGE = 0;
	//��ɼ���
	bool left = false;
	bool right = false;
	putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
	putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
	if (NPC_LIKE.x < Myself.x) right = true;
	else if (NPC_LIKE.x > Myself.x) left = true;
	while (1)//С���ƶ�
	{
		putimage(0, 0, &bk2);
		//����Χ����
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
		putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
		//����������
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
		putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
		//������Ӿ��
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
		putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
		//���û滭��
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
		putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 0, SRCPAINT);
		//�������
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, NUMBERSOFIMAGE * NPC_LIKE.rolewidth,
			0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, NUMBERSOFIMAGE * NPC_LIKE.rolewidth,
			0, SRCPAINT);
		NUMBERSOFIMAGE++;
		if (NPC_LIKE.y + NPC_LIKE.roleheight <= 720)NPC_LIKE.y += 10;//��ײ��ǽ
		if (NUMBERSOFIMAGE == 4)
			NUMBERSOFIMAGE = 0;
		Sleep(100);
		//if (NPC_LIKE.y - Myself.y <= 5 || Myself.y - NPC_LIKE.y <= 5) break;
		if (abs(NPC_LIKE.y - Myself.y) <= 5) break;
		/*if ((Myself.x - NPC_LIKE.x == Myself.rolewidth || NPC_LIKE.x - Myself.x == Myself.rolewidth) && NPC_LIKE.y == Myself.y) break;*/
	}
	while (1)
	{
		if (left && NPC_LIKE.x - Myself.x >= Myself.rolewidth)//��ֹ��ͷС�ֶ�
		{
			putimage(0, 0, &bk2);
			//����Χ����
			putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
			putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
			//����������
			putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
			putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
			//������Ӿ��
			putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
			putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
			//���û滭��
			putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
			putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
			putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 0, SRCAND);
			putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 0, SRCPAINT);
			//���ÿɰ����
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
		else if (right && Myself.x - NPC_LIKE.x >= NPC_LIKE.rolewidth)//��ֹ��ͷС�ֶ�
		{
			putimage(0, 0, &bk2);
			//����Χ����
			putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
			putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
			//����������
			putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
			putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
			//������Ӿ��
			putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
			putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
			//���û滭��
			putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
			putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
			putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, imageNum * Myself.rolewidth, 0, SRCAND);
			putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, imageNum * Myself.rolewidth, 0, SRCPAINT);
			//���ÿɰ����
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
	FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
	errno_t err = _tfopen_s(&file, _T("res\\story\\NPC-SCORE3-LIKE-CHAPTER2.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
	if (file == NULL) {
		// �����ļ���ʧ�ܵ����
		return;
	}
	int rowIndex = 0;
	while (_fgetts(CHAPTER2[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
		rowIndex++;
		if (rowIndex >= MAX_ROWS) {
			// ���������ڴ���������
			break;
		}
	}
	/*for (int i = 0; i < CHAPTER2_WEIQI; i++) {
			_tprintf(_T("%s"), CHAPTER2[i]);
		}*/
	fclose(file);
	rowIndex = 0;
	bool onechancetouse = true;

	while (rowIndex < CHAPTER2_LIKE)//��Ҫ�� Ŀǰ��6
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
				//��ʹ�˳���ѭ��Ҳ�ܳ�ʼ��������
				cleardevice();//���������֮ǰ�ľ��ο�����ľ�������
				putimage(0, 0, &bk2);
				//����Χ����
				putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.roleY, 0, 0, SRCAND);
				putimage(WEIQI.x, WEIQI.y, WEIQI.rolewidth, WEIQI.roleheight, &WEIQI.role, 0, 0, SRCPAINT);
				//����������
				putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.roleY, 0, 0, SRCAND);
				putimage(ZHUOYOU.x, ZHUOYOU.y, ZHUOYOU.rolewidth, ZHUOYOU.roleheight, &ZHUOYOU.role, 0, 0, SRCPAINT);
				//������Ӿ��
				putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.roleY, 0, 0, SRCAND);
				putimage(YOUYONG.x, YOUYONG.y, YOUYONG.rolewidth, YOUYONG.roleheight, &YOUYONG.role, 0, 0, SRCPAINT);
				//���û滭��
				putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.roleY, 0, 0, SRCAND);
				putimage(HUIHUA.x, HUIHUA.y, HUIHUA.rolewidth, HUIHUA.roleheight, &HUIHUA.role, 0, 0, SRCPAINT);
				//�����Լ�
				putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
				putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
				//�������
				putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
				putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
				//��ô��Ҫ�Ķ��������⣿����
				rowIndex++;
				//��ô��Ҫ�Ķ��������⣿����
				//˵��һ�£���Ϊ�Ѿ����������ԣ������ͼƬ������ûʲô���⡣
				if (CHAPTER2[rowIndex][0] == '1')//�����1������
				{
					//���������⣬ͼƬ�����⣬�����ǰ׵׺�����ͼ�Ŷԡ�������д�ţ����Ż�Ԫ��
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
	//����᳡
	//���� �½ڶ��������½���
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
	settextstyle(22, 0, _T("����"));
	//putimage()
	FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
	errno_t err = _tfopen_s(&file, _T("res\\story\\MUSICBEGIN-CHAPTER3.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
	if (file == NULL) {
		// �����ļ���ʧ�ܵ����
		return;
	}
	int rowIndex = 0;
	while (_fgetts(CHAPTER2[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
		rowIndex++;
		if (rowIndex >= MAX_ROWS) {
			// ���������ڴ���������
			break;
		}
	}
	/*for (int i = 0; i < CHAPTER2_WEIQI; i++) {
		_tprintf(_T("%s"), CHAPTER2[i]);
	}*/
	fclose(file);
	rowIndex = 0;
	while (rowIndex < CHAPTER3_BEGIN)//��Ҫ�� Ŀǰ��6
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
				cleardevice();//���������֮ǰ�ľ��ο�����ľ�������
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
	settextstyle(22, 0, _T("����"));
	//putimage()
	FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
	errno_t err = _tfopen_s(&file, _T("res\\story\\MUSICAFTER-CHAPTER3.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
	if (file == NULL) {
		// �����ļ���ʧ�ܵ����
		return;
	}
	int rowIndex = 0;
	while (_fgetts(CHAPTER2[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
		rowIndex++;
		if (rowIndex >= MAX_ROWS) {
			// ���������ڴ���������
			break;
		}
	}
	/*for (int i = 0; i < CHAPTER2_WEIQI; i++) {
		_tprintf(_T("%s"), CHAPTER2[i]);
	}*/
	fclose(file);
	rowIndex = 0;//AFTERSTORY
	bool onechancetouse = true;
	while (rowIndex < AFTERSTORY)//��Ҫ�� Ŀǰ��6
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
				if (CHAPTER2[rowIndex][0] == '1')//�����1������
				{
					//���������⣬ͼƬ�����⣬�����ǰ׵׺�����ͼ�Ŷԡ�������д�ţ����Ż�Ԫ��
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
	FILE* file;// = _tfopen_s(_T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\story\\NPC1-CHAPTER1.txt"), _T("r")); // ʹ�� _tfopen ���ĵ�
	errno_t err = _tfopen_s(&file, _T("res\\story\\AFTERSTORYOFMIUMIU.txt"), _T("r,ccs=UTF-8"));//ʹ��UTF-8���뷽ʽ��
	if (file == NULL) {
		// �����ļ���ʧ�ܵ����
		return;
	}
	int rowIndex = 0;
	while (_fgetts(CHAPTERONE[rowIndex], MAX_COLS, file)) {  // ʹ�� _fgetts ��ȡ�ĵ�����
		rowIndex++;
		if (rowIndex >= MAX_ROWS) {
			// ���������ڴ���������
			break;
		}
	}
	fclose(file);
	rowIndex = 0;
	settextstyle(22, 0, _T("����"), 0, 0, 700, false, false, false);
	bool onechancetouse = true;
	//IMAGE BUFF;
	//getimage(&BUFF, 0, 0, 1280, 720);
	while (rowIndex < FINISH)//��Ҫ�� Ŀǰ��6
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
				cleardevice();//���������֮ǰ�ľ��ο�����ľ�������

				rowIndex++;

				putimage(40, 0, &FINAL);
				//putimage(0, 0, &BUFF);
				if (CHAPTERONE[rowIndex][0] == '1')//�����1������
				{
					//���������⣬ͼƬ�����⣬�����ǰ׵׺�����ͼ�Ŷԡ�������д�ţ����Ż�Ԫ��
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
	bool closetheexe = false;//������������ر�
	bool gameStarted = false;//���Ƶ�һҳ����
	while (!closetheexe)
	{
		
		loadimage(&YES, _T("res\\YES.jpg"));
		loadimage(&SET, _T("res\\SET.jpg"));
		
		Initialize();
		bool returntostart = false;//��������뷵����椵Ļ�ͨ����
		IMAGE BUFFER;
		getimage(&BUFFER, 0, 0, Width, Height);
		//�����ѭ���ǿ�ʼ��Ϸǰ��ʱ��
		while (!gameStarted)
		{//gamestarted = false����

			if (MouseHit()) {
				MOUSEMSG m = GetMouseMsg();
				if (m.x >= (Width / 2 - 75) && m.x <= Width / 2 + 75 && m.y >= Height / 2 + 50 && m.y <= Height / 2 + 100 && m.uMsg == WM_LBUTTONDOWN) {
					//��ʼ��Ϸ��� rectangle(Width/2-75, Height/2+50, Width/2+75, Height/2+100);
					/*cleardevice();
					setbkcolor(BLACK);*/
					gameStarted = true;
				}
				else if (m.x >= (Width / 2 - 75) && m.x <= Width / 2 + 75 && m.y >= Height / 2 + 150 && m.y <= Height / 2 + 200 && m.uMsg == WM_LBUTTONDOWN) {
					//�˳����
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
				else if (m.x >= 20 && m.x <= 50 && m.y >= 670 && m.y <= 700 && m.uMsg == WM_LBUTTONDOWN)//�㵽����
				{
					cleardevice();
					putimage(40, 25, &SET);
					setbkcolor(BLACK);
					setlinestyle(PS_SOLID, 2);
					setlinecolor(CYAN);
					rectangle(20, 670, 50, 700);
					settextstyle(12, 0, _T("Consolas"));
					TCHAR SSSS[20] = L"����";
					outtextxy(35 - textwidth(SSSS) / 2, 685 - textheight(SSSS), SSSS);
					settextstyle(48, 0, _T("Consolas"));
					TCHAR WWW[20] = L"�ش���л:LLX";
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
		//��������
		loadimage(&Myself_panel.role, _T("res\\miumiu.png"));
		loadimage(&Myself_panel.roleY, _T("res\\miumiuY.png"));
		cleardevice();
		if (chapter_0)
		{
			INTRODUCESTRORY();
			chapter_1 = true;
		}
		cleardevice();
		TCHAR BEGIN[30] = _T("���ܺ󣬾��¶�ʮ���գ���¶21��405���ᡣ");
		int WWW = textwidth(BEGIN);
		int HHH = textheight(BEGIN);
		setlinecolor(WHITE);
		settextcolor(WHITE);
		outtextxy(Width / 2 - WWW / 2, Height / 2 - HHH / 2, BEGIN);
		Sleep(3000);
		loadimage(&background, _T("res\\BK1.jpg"));
		//���ر���ͼƬ
		putimage(0, 0, &background);
		//IMAGE role, roleY;//64*64 ����ͼ��192*256
		//��������������ͼƬ��
		//loadimage(&role, _T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\human_life2.png"));//ǰ��ͼ
		//loadimage(&roleY, _T("D:\\Dlutlearning\\������ƿ���\\Bighomework\\Life\\res\\human_life1.png"));//����ͼ
		//putimage(100, 500, 64, 64, &roleY, 0, 200, SRCAND);//����ͼ
		//putimage(100, 500, 64, 64, &role, 0, 200, SRCPAINT);//ǰ��ͼ
		loadimage(&Myself.role, _T("res\\human_life.png"));
		loadimage(&Myself.roleY, _T("res\\human_lifeY.png"));
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.roleY, 0, 0, SRCAND);
		putimage(Myself.x, Myself.y, Myself.rolewidth, Myself.roleheight, &Myself.role, 0, 0, SRCPAINT);
		NPC_1.rolewidth = 25;
		NPC_1.roleheight = 38;
		loadimage(&NPC_1.role, _T("res\\333.png"));
		loadimage(&NPC_1.roleY, _T("res\\333Y.png"));

		//����������
		loadimage(&NPC_1_panel.role, _T("res\\ww.png"));
		loadimage(&NPC_1_panel.roleY, _T("res\\wwY.png"));
		//���ֵļ���
		loadimage(&NPC_MENGLIN.role, _T("res\\MENGLIN.png"));
		loadimage(&NPC_MENGLIN.roleY, _T("res\\MENGLINY.png"));
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.roleY, 0, 0, SRCAND);
		putimage(NPC_MENGLIN.x, NPC_MENGLIN.y, NPC_MENGLIN.rolewidth, NPC_MENGLIN.roleheight, &NPC_MENGLIN.role, 0, 0, SRCPAINT);
		//���ֵ�ƽ��ͼ����
		loadimage(&NPC_MENGLIN_PANEL.role, _T("res\\MENGLIN_PANEL2.png"));
		loadimage(&NPC_MENGLIN_PANEL.roleY, _T("res\\MENGLIN_PANELY2.png"));
		//���ö���A��
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.roleY, 0, 0, SRCAND);
		putimage(NPC_1.x, NPC_1.y, NPC_1.rolewidth, NPC_1.roleheight, &NPC_1.role, 0, 0, SRCPAINT);
		//�������
		loadimage(&NPC_LIKE.role, _T("res\\���Q.png"));
		loadimage(&NPC_LIKE.roleY, _T("res\\���QY.png"));
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.roleY, 0, 0, SRCAND);
		putimage(NPC_LIKE.x, NPC_LIKE.y, NPC_LIKE.rolewidth, NPC_LIKE.roleheight, &NPC_LIKE.role, 0, 0, SRCPAINT);
		//����ƽ�����
		loadimage(&NPC_LIKE_PANEL.role, _T("res\\LIKE_PANNEL.png"));
		loadimage(&NPC_LIKE_PANEL.roleY, _T("res\\LIKE_PANNELY.png"));
		//���ش��ͷ���
		loadimage(&Chuansongzhen.role, _T("res\\CHAPTER2enterQ.png"));
		loadimage(&Chuansongzhen.roleY, _T("res\\CHAPTER2enterQY.png"));
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.roleY, 0, 0, SRCAND);
		putimage(Chuansongzhen.x, Chuansongzhen.y, Chuansongzhen.rolewidth, Chuansongzhen.roleheight, &Chuansongzhen.role, 0, 0, SRCPAINT);
		//����Ӱ��
		loadimage(&NPC_0.role, _T("res\\miumiuY.png"));
		loadimage(&NPC_0.roleY, _T("res\\miumiuYY.png"));

		bool onechancewithNPC0 = true;
		bool key = false;
		bool chapter_2 = false;
		bool chapter_3 = false;
		while (chapter_1)
		{
			keyDonw();
			//�Ի���ʾ
			dialogetishi(NPC_1);
			dialogetishi(NPC_MENGLIN);
			dialogetishi(NPC_LIKE);
			Chuansongmentishi(Chuansongzhen);
			char choice = _getch();//ѡ��÷�����
			dialogewithNPC1(choice);
			dialogewithNPC2(choice);
			dialogewithNPC3(choice);
			if (choice == 'R')//���ٵڶ���ͨ��
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
					//g������
					mciSendString(_T("stop BGM"),0,0,0);
					mciSendString(_T("close BGM"), 0, 0, 0);
					mciSendString(_T("open res/music/HOYO-MiX-Broken-Blade-���ѵĽ���.mp3 alias HAIPA"),0,0,0);
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
			//������
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
		mciSendString(_T("open res/Music/HOYO-MiX-The-Exquisite-Night-Chimes-�����໪ҹ.mp3 alias BGM2"), 0, 0, 0);
		mciSendString(_T("play BGM2 repeat"), 0, 0, 0);
		if (chapter_2)
		{
			loadimage(&WEIQI.role, _T("res\\WEIQINPC1.png"));
			loadimage(&WEIQI.roleY, _T("res\\WEIQINPC1Y.png"));
			//Χ��ƽ��
			loadimage(&WEIQI_PANEL.role, _T("res\\WEIQI1.png"));
			loadimage(&WEIQI_PANEL.roleY, _T("res\\WEIQI1Y.png"));
			loadimage(&ZHUOYOU.role, _T("res\\ZHUOYOU.png"));
			loadimage(&ZHUOYOU.roleY, _T("res\\ZHUOYOUY.png"));
			//����ƽ��
			loadimage(&ZHUOYOU_PANEL.role, _T("res\\ZHUOYOUPANEL.png"));
			loadimage(&ZHUOYOU_PANEL.roleY, _T("res\\ZHUOYOUPANELY.png"));
			loadimage(&YOUYONG.role, _T("res\\YOUYONG.png"));
			loadimage(&YOUYONG.roleY, _T("res\\YOUYONGY.png"));
			//��Ӿƽ��
			loadimage(&YOUYONG_PANEL.role, _T("res\\YOUYONGPANEL.png"));
			loadimage(&YOUYONG_PANEL.roleY, _T("res\\YOUYONGPANELY.png"));
			//�滭ƽ��
			loadimage(&HUIHUA_PANEL.role, _T("res\\HUIHUAPANEL.png"));
			loadimage(&HUIHUA_PANEL.roleY, _T("res\\HUIHUAPANELY.png"));
			//�ʵ�����
			loadimage(&CAIDAN_PANEL.role, _T("res\\CAIDANDANDANDANR.png"));
			loadimage(&CAIDAN_PANEL.roleY, _T("res\\CAIDANDANDANDANRY.png"));
			loadimage(&HUIHUA.roleY, _T("res\\HUIHUAY.png"));
			loadimage(&HUIHUA.role, _T("res\\HUIHUA.png"));
			loadimage(&BK3, _T("res\\CONCERT2.jpg"));

			Initialize_chapter2();
			INTRODUCESTORY2();
		}
		//��ʼ���£���ʵ����ʼ������Ҳ��
		imageNum = 0;
		while (chapter_2) {
			keyDonw_Chapter2();
			dialogetishi(WEIQI);
			dialogetishi(HUIHUA);
			dialogetishi(YOUYONG);
			dialogetishi(ZHUOYOU);
			dialogetishi(CAIDAN);
			char Choice2 = _getch();//ѡ��÷�����

			dialogewithWEIQI(Choice2);
			dialogewithZHUOYOU(Choice2);
			dialogewithYOUYONG(Choice2);
			dialogewithHUIHUA(Choice2);
			dialogewithCAIDAN(Choice2);
			//��λ����ɫΪ810 425 ����
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
			mciSendString(_T("open res/Music/HOYO-MiX-The-Caress-of-Three-Mothers-Ů���˵Ķ���.mp3 alias BGM3"), 0, 0, 0);
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