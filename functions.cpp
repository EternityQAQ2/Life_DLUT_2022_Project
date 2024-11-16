#include "functions.h"
IMAGE buffer;
void initialcontrolrectangle(Rectanglecontrol& rect)
{
	setlinestyle(PS_SOLID, 2);
	setlinecolor(WHITE);
	rectangle(rect.left, rect.top, rect.right, rect.bottom);
}
void clearRectangle(Rectanglecontrol& a)
{
	setlinestyle(PS_SOLID, 2);
	setlinecolor(getbkcolor());
	rectangle(a.left, a.top, a.right, a.bottom);
}
void drawcontrolrectangle(Rectanglecontrol& a, int key)
{
	clearRectangle(a);
	bool flag_left = true;
	bool flag_right = true;
	if (a.left <= 0 + FORWARD) flag_left = false;
	else flag_left = true;
	if (a.right >= 600 + FORWARD) flag_right = false;
	else flag_right = true;
	switch (key)
	{
	case 'a':
	case 'A':
	case VK_LEFT: // Left arrow key or 'A' is pressed
		if (flag_left)
		{
			a.left -= a.dx;
			a.right -= a.dx;
		}
		break;
	case 'd':
	case 'D':
	case VK_RIGHT: // Right arrow key or 'D' is pressed
		if (flag_right)
		{
			a.left += a.dx;
			a.right += a.dx;
		}
		break;
	}
	setlinestyle(PS_SOLID, 2);
	setlinecolor(WHITE);
	rectangle(a.left, a.top, a.right, a.bottom);
	//FlushBatchDraw();
}
double Distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void Autoball(Ball& a, Rectanglecontrol& b)
{
	setfillcolor(getbkcolor());
	solidcircle(a.x, a.y, a.r);
	a.Move();
	a.Bounce(b);
	setfillcolor(a.color);
	solidcircle(a.x, a.y, a.r);
	//FlushBatchDraw();
	//EndBatchDraw();
}
void Blockbreak(int numbers, block BLL[200], Ball& ball)
{
	for (int i = 0; i < numbers; i++)
	{
		if (BLL[i].type == true)
		{
			if (ball.x >= BLL[i].left && ball.x <= BLL[i].right && ball.y + ball.r >= BLL[i].top && ball.y + ball.r <= BLL[i].buttom)//碰到了顶部
			{
				ball.dy = -ball.dy;
				BLL[i].type = false;
				PlayHitSound();
				//ball.Move();
			}
			else if (ball.x >= BLL[i].left && ball.x <= BLL[i].right && ball.y - ball.r <= BLL[i].buttom && ball.y - ball.r >= BLL[i].top)//碰到了底部
			{
				ball.dy = -ball.dy;
				BLL[i].type = false;
				PlayHitSound();
				//ball.Move();
			}
			else if (ball.y >= BLL[i].top && ball.y <= BLL[i].buttom && ball.x + ball.r >= BLL[i].left && ball.x + ball.r <= BLL[i].right)
			{
				ball.dx = -ball.dx;
				BLL[i].type = false;
				PlayHitSound();
				//ball.Move();
			}
			else if (ball.y >= BLL[i].top && ball.y <= BLL[i].buttom && ball.x - ball.r <= BLL[i].right && ball.x - ball.r >= BLL[i].left)
			{
				ball.dx = -ball.dx;
				BLL[i].type = false;
				PlayHitSound();
				//ball.Move();
			}
			else if (Distance(BLL[i].left, BLL[i].top, ball.x, ball.y) - ball.r < 0.5)
			{
				ball.dx = -ball.dx;
				ball.dy = -ball.dy;
				BLL[i].type = false;
				PlayHitSound();
			}
			else if (Distance(BLL[i].right, BLL[i].top, ball.x, ball.y) - ball.r < 0.5)
			{
				ball.dx = -ball.dx;
				ball.dy = -ball.dy;
				BLL[i].type = false;
				PlayHitSound();
			}
			else if (Distance(BLL[i].left, BLL[i].buttom, ball.x, ball.y) - ball.r < 0.5)
			{
				ball.dx = -ball.dx;
				ball.dy = -ball.dy;
				BLL[i].type = false;
				PlayHitSound();
			}
			else if (Distance(BLL[i].right, BLL[i].buttom, ball.x, ball.y) - ball.r < 0.5)
			{
				ball.dx = -ball.dx;
				ball.dy = -ball.dy;
				BLL[i].type = false;
				PlayHitSound();
			}

		}

	}

}
void balldisplay(int& numbers)
{
	TCHAR SS[20] = L"球的数量";
	settextstyle(24, 0, _T("Consolas"));
	setbkmode(TRANSPARENT);
	int w = textwidth(SS);
	int h = textheight(SS);
	outtextxy(300 - w / 2 + FORWARD, 580 - h / 2 + DOWN, SS);
	clearrectangle(320 + w / 2 + FORWARD, 580 - h / 2 + DOWN, 340 + w / 2 + FORWARD, 604 - h / 2 + DOWN);
	TCHAR NUMBERS[5];
	settextcolor(WHITE);
	_stprintf_s(NUMBERS, _T("%d"), numbers);
	outtextxy(300 + w / 2 + 20 + FORWARD, 580 - h / 2 + DOWN, NUMBERS);
}
void Ball_Return(Ball& a, Rectanglecontrol& rect)
{
	a.x = (rect.left + rect.right) / 2;
	a.y = (rect.top - 20);
	a.dx = 0;
	a.dy = 0;

}
void balldecrese(Ball& a, int& numbers, int& minflag, Rectanglecontrol& rect)
{
	if (a.y + a.r >= HEIGHT + DOWN)
	{
		setfillcolor(getbkcolor());
		solidcircle(a.x, a.y, a.r);
		numbers--;
		Ball_Return(a, rect);
		minflag = 1;
	}
}
void gamefailuredetect(bool& gameflag, int& ballnumbers, bool& continuegame)
{
	int select;
	if (ballnumbers < 0)
	{
		HWND hwnd = GetHWnd();
		select = MessageBox(hwnd, _T("你输了，重新开始？还是退出游戏？"), _T("请选择"), MB_YESNO | MB_DEFBUTTON1);
		if (select == IDYES)				// 选择再来一次
		{
			gameflag = false;
		}
		else if (select == IDNO)	// 选择退出游戏
		{
			continuegame = false;
			gameflag = false;
		}
	}

}
void gamesuccessdetect(bool& gameflag, bool& continuegame, block BLL[], int blocknumbers)
{
	int select;
	bool gamesuccessflag = true;
	for (int i = 0; i < blocknumbers; i++)
	{
		if (BLL[i].type == 1) gamesuccessflag = false;
	}
	if (gamesuccessflag)
	{
		HWND hwnd = GetHWnd();

		select = MessageBox(hwnd, _T("恭喜你获得游戏胜利！重新开始？还是退出游戏？"), _T("请选择"), MB_YESNO | MB_DEFBUTTON1);
		if (select == IDYES)				// 选择再来一次
		{
			gameflag = false;
		}
		else if (select == IDNO)	// 选择退出游戏
		{
			continuegame = false;
			gameflag = false;
		}
	}
}
void Rectanglecenter_fourcourner(int numbers, block BLL[200])
{
	for (int i = 0; i < numbers; i++)
	{
		BLL[i].left = BLL[i].x - 4;
		BLL[i].right = BLL[i].x + 4;
		BLL[i].top = BLL[i].y + 4;
		BLL[i].buttom = BLL[i].y - 4;
	}
}
void BLOCKLEVEL_1_FATE(block BLL[200])
{
	BLL[0].x = 650;
	BLL[0].y = 360;
	BLL[0].left = 640;
	BLL[0].right = 660;
	BLL[0].top = 350;
	BLL[0].buttom = 370;
	if (BLL[0].type == 1)
	{
		setfillcolor(YELLOW);
		solidrectangle(BLL[0].left, BLL[0].top, BLL[0].right, BLL[0].buttom);
	}
	else if (BLL[0].type == 0)
	{
		setfillcolor(getbkcolor());
		solidrectangle(BLL[0].left, BLL[0].top, BLL[0].right, BLL[0].buttom);
	}

}
void BLOCKLEVEL_1(block BLL[200])
{
	//brown color 65,34,13
	for (int i = 0; i < 3; i++)
	{
		BLL[i].x = 75 + FORWARD;
		BLL[i].y = 195 + i * 10 + DOWN;
	}
	for (int i = 3; i < 7; i++)
	{
		BLL[i].y = 175 + (i - 3) * 10 + DOWN;
		BLL[i].x = 85 + FORWARD;
	}
	/*BLL[7].x = 95;
	BLL[8].x = 95;
	BLL[9].x = 95;
	BLL[10].x = 95;
	BLL[11].x = 95;*/
	for (int i = 7; i < 12; i++)
	{
		BLL[i].x = 95 + FORWARD;
		BLL[i].y = 165 + (i - 7) * 10 + DOWN;
	}
	for (int i = 12; i < 14; i++)
	{
		BLL[i].x = 105 + FORWARD;
	}
	BLL[12].y = 155 + DOWN;
	BLL[13].y = 195 + DOWN;
	for (int i = 14; i < 16; i++)
	{
		BLL[i].x = 115 + FORWARD;
	}
	BLL[14].y = 145 + DOWN;
	BLL[15].y = 195 + DOWN;
	for (int i = 16; i < 18; i++)
	{
		BLL[i].x = 125 + FORWARD;
	}
	BLL[16].y = 135 + DOWN;
	BLL[17].y = 185 + DOWN;
	for (int i = 18; i < 22; i++)
	{
		BLL[i].x = 135 + FORWARD;
		if (i != 18)//start from 19
		{
			BLL[i].y = 195 + (i - 19) * 10 + DOWN;
		}
		else BLL[i].y = 125 + DOWN;
	}
	for (int i = 22; i < 26; i++)
	{
		BLL[i].x = 145 + FORWARD;
		if (i == 22) BLL[i].y = 115 + DOWN;
		else BLL[i].y = 225 + (i - 23) * 10 + DOWN;
	}
	for (int i = 26; i < 28; i++)
	{
		BLL[i].x = 155 + FORWARD;
	}
	BLL[26].y = 105 + DOWN;
	BLL[27].y = 255 + DOWN;
	for (int i = 28; i < 35; i++)
	{
		BLL[i].x = 165 + FORWARD;
		if (i == 28) BLL[i].y = 95 + DOWN;
		else BLL[i].y = (i - 29) * 10 + 265 + DOWN;
	}
	//the eye part;
	BLL[35].x = 165 + FORWARD;
	BLL[36].x = 165 + FORWARD;
	BLL[35].y = 155 + DOWN;
	BLL[36].y = 165 + DOWN;
	for (int i = 37; i < 40; i++)
	{
		BLL[i].x = 175 + FORWARD;
		if (i == 37) BLL[i].y = 95 + DOWN;
		else BLL[i].y = (i - 38) * 10 + 325 + DOWN;
	}
	// the eye part;
	BLL[40].x = 175 + FORWARD;
	BLL[41].x = 175 + FORWARD;
	BLL[40].y = 145 + DOWN;
	BLL[41].y = 165 + DOWN;
	for (int i = 42; i < 45; i++)
	{
		BLL[i].x = 185 + FORWARD;
	}
	BLL[42].y = 85 + DOWN;
	BLL[43].y = 155 + DOWN;
	BLL[44].y = 345 + DOWN;
	for (int i = 45; i < 47; i++)
	{
		BLL[i].x = 195 + FORWARD;
	}
	BLL[45].y = 85 + DOWN;
	BLL[46].y = 355 + DOWN;
	for (int i = 47; i < 49; i++)
	{
		BLL[i].x = 205 + FORWARD;
	}
	BLL[47].y = 85 + DOWN;
	BLL[48].y = 355 + DOWN;
	for (int i = 49; i < 51; i++) BLL[i].x = 215 + FORWARD;
	BLL[49].y = 75 + DOWN;
	BLL[50].y = 355 + DOWN;
	for (int i = 51; i < 53; i++) BLL[i].x = 225 + FORWARD;
	BLL[51].y = 75 + DOWN;
	BLL[52].y = 345 + DOWN;
	for (int i = 53; i < 55; i++) BLL[i].x = 235 + FORWARD;
	BLL[53].y = 65 + DOWN;
	BLL[54].y = 335 + DOWN;
	for (int i = 55; i < 57; i++) BLL[i].x = 245 + FORWARD;
	BLL[55].y = 65 + DOWN;
	BLL[56].y = 335 + DOWN;
	for (int i = 57; i < 61; i++) BLL[i].x = 255 + FORWARD;
	BLL[57].y = 55 + DOWN;
	BLL[58].y = 125 + DOWN;
	BLL[59].y = 135 + DOWN;
	BLL[60].y = 335 + DOWN;
	for (int i = 61; i < 65; i++) BLL[i].x = 265 + FORWARD;
	BLL[61].y = 45 + DOWN;
	BLL[62].y = 115 + DOWN;
	BLL[63].y = 135 + DOWN;
	BLL[64].y = 345 + DOWN;
	for (int i = 65; i < 68; i++) BLL[i].x = 275 + FORWARD;
	BLL[65].y = 45 + DOWN;
	BLL[66].y = 125 + DOWN;
	BLL[67].y = 355 + DOWN;
	for (int i = 68; i < 71; i++)
	{
		BLL[i].x = 285 + FORWARD;
		BLL[i].y = (i - 68) * 10 + 35 + DOWN;
	}
	for (int i = 71; i < 74; i++)
	{
		BLL[i].x = 285 + FORWARD;
		BLL[i].y = (i - 71) * 10 + 85 + DOWN;
	}
	BLL[74].x = 285 + FORWARD;
	BLL[74].y = 355 + DOWN;
	for (int i = 75; i < 80; i++)
	{
		BLL[i].x = 295 + FORWARD;
		BLL[i].y = (i - 75) * 10 + 35 + DOWN;
	}
	for (int i = 80; i < 82; i++)
	{
		BLL[i].x = 295 + FORWARD;
		BLL[i].y = (i - 80) * 10 + 115 + DOWN;
	}
	BLL[82].x = 295 + FORWARD;
	BLL[82].y = 355 + DOWN;
	for (int i = 83; i < 86; i++)
	{
		BLL[i].x = 305 + FORWARD;
		BLL[i].y = (i - 83) * 10 + 35 + DOWN;
	}
	BLL[86].x = 305 + FORWARD;
	BLL[86].y = 135 + DOWN;
	BLL[87].x = 305 + FORWARD;
	BLL[87].y = 345 + DOWN;
	//
	BLL[88].x = 315 + FORWARD;
	BLL[88].y = 35 + DOWN;
	BLL[89].x = 315 + FORWARD;
	BLL[89].y = 145 + DOWN;
	BLL[90].x = 315 + FORWARD;
	BLL[90].y = 335 + DOWN;
	//
	BLL[91].x = 325 + FORWARD;
	BLL[91].y = 155 + DOWN;
	BLL[92].x = 325 + FORWARD;
	BLL[92].y = 315 + DOWN;
	BLL[93].x = 325 + FORWARD;
	BLL[93].y = 325 + DOWN;
	BLL[119].x = 325 + FORWARD;
	BLL[119].y = 305 + DOWN;
	//
	BLL[94].x = 335 + FORWARD;
	BLL[94].y = 155 + DOWN;
	for (int i = 95; i < 100; i++)
	{
		BLL[i].x = 335 + FORWARD;
		BLL[i].y = 255 + (i - 95) * 10 + DOWN;
	}
	BLL[100].x = 345 + FORWARD;
	BLL[100].y = 145 + DOWN;
	BLL[101].x = 345 + FORWARD;
	BLL[101].y = 245 + DOWN;
	BLL[101].x = 345 + FORWARD;
	BLL[101].y = 255 + DOWN;

	BLL[102].x = 355 + FORWARD;
	BLL[102].y = 145 + DOWN;
	BLL[103].x = 355 + FORWARD;
	BLL[103].y = 225 + DOWN;
	for (int i = 104; i < 106; i++)
	{
		BLL[i].x = 355 + FORWARD;
		BLL[i].y = (i - 104) * 10 + 245 + DOWN;
	}

	BLL[106].x = 365 + FORWARD;
	BLL[106].y = 145 + DOWN;
	BLL[107].x = 365 + FORWARD;
	BLL[107].y = 215 + DOWN;
	for (int i = 108; i < 110; i++)
	{
		BLL[i].x = 365 + FORWARD;
		BLL[i].y = (i - 108) * 10 + 235 + DOWN;
	}
	BLL[110].x = 375 + FORWARD;
	BLL[110].y = 145 + DOWN;
	BLL[111].x = 375 + FORWARD;
	BLL[111].y = 205 + DOWN;
	BLL[112].x = 385 + FORWARD;
	BLL[112].y = 155 + DOWN;
	BLL[113].x = 385 + FORWARD;
	BLL[113].y = 195 + DOWN;
	BLL[114].x = 395 + FORWARD;
	BLL[114].y = 165 + DOWN;
	BLL[115].x = 395 + FORWARD;
	BLL[115].y = 195 + DOWN;
	for (int i = 116; i < 118; i++)
	{
		BLL[i].x = 405 + FORWARD;
		BLL[i].y = 175 + (i - 116) * 10 + DOWN;
	}
	BLL[118].x = 415 + FORWARD;
	BLL[118].y = 185 + DOWN;
	Rectanglecenter_fourcourner(142, BLL);
	for (int i = 0; i < 120; i++)
	{
		if (BLL[i].type == true)
		{
			BLL[i].color = RGB(65, 34, 13);
			setfillcolor(BLL[i].color);
			solidrectangle(BLL[i].left, BLL[i].top, BLL[i].right, BLL[i].buttom);
		}
		else
		{
			BLL[i].color = getbkcolor();
			setfillcolor(BLL[i].color);
			solidrectangle(BLL[i].left, BLL[i].top, BLL[i].right, BLL[i].buttom);
		}
	}
	//start from 120
	//244,195,56
	//max left =75 max top = 35;
	//outside part :
	int j = 0;
	int i = 0;
	for (j = 120; j < 122; j++)
	{
		BLL[j].x = 75 + FORWARD;
		BLL[j].y = 75 + (j - 120) * 10 + DOWN;
	}
	for (j = 122; j < 125; j++)
	{
		BLL[j].x = 85 + FORWARD;
		BLL[j].y = 75 + (j - 122) * 10 + DOWN;
	}
	for (j = 125; j < 127; j++)
	{
		BLL[j].x = 95 + FORWARD;
		BLL[j].y = 85 + (j - 125) * 10 + DOWN;
	}
	//4 列
	for (j = 127; j < 129; j++)
	{
		BLL[j].x = 105 + FORWARD;
		BLL[j].y = 55 + (j - 127) * 10 + DOWN;
	}
	for (j = 129; j < 131; j++)
	{
		BLL[j].x = 105 + FORWARD;
		BLL[j].y = 95 + (j - 129) * 10 + DOWN;
	}
	for (j = 131; j < 134; j++)
	{
		BLL[j].x = 115 + FORWARD;
		BLL[j].y = 55 + (j - 131) * 10 + DOWN;
	}
	for (j = 134, i = 0; j < 136; j++, i++)
	{
		BLL[j].x = 125 + FORWARD;
		BLL[j].y = 75 + i * 10 + DOWN;
	}
	for (j = 136, i = 0; j < 138; j++, i++)
	{
		BLL[j].x = 135 + FORWARD;
		BLL[j].y = 35 + i * 10 + DOWN;
	}
	for (j = 138, i = 0; j < 141; j++, i++)
	{
		BLL[j].x = 145 + FORWARD;
		BLL[j].y = 35 + i * 10 + DOWN;
	}
	Rectanglecenter_fourcourner(142, BLL);
	for (i = 120; i < 141; i++)
	{
		if (BLL[i].type == true)
		{
			BLL[i].color = RGB(244, 195, 56);
			setfillcolor(RGB(244, 195, 56));
			solidrectangle(BLL[i].left, BLL[i].top, BLL[i].right, BLL[i].buttom);
		}
		else
		{
			setfillcolor(getbkcolor());
			solidrectangle(BLL[i].left, BLL[i].top, BLL[i].right, BLL[i].buttom);
		}
	}


}
void PlayHitSound()
{
	static bool flag = true;			// 乒乓碰撞声交替标记
	static clock_t record = 0;			// 上次操作的记录
	/* const TCHAR* pingSoundPath = _T("res/music/ping.mp3");
		const TCHAR* pongSoundPath = _T("res/music/pong.mp3");*/
		// 避免过快操作，否则会一直从 0 开始播放，发不出声音
	if (clock() - record > 30)
	{
		//D:\Dlutlearning\程序设计开发\Bighomework\弹球小游戏\res\music
		if (flag)
			mciSendString(_T("play res/Music/ping.mp3 from 0"), NULL, 0, NULL);
		else
			mciSendString(_T("play res/Music/pong.mp3 from 0"), NULL, 0, NULL);
		record = clock();
		flag = !flag;
	}
}
void Initializeball()
{
	//对弹珠游戏进行书写
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 48;
	_tcscpy_s(f.lfFaceName, _T("Arial"));
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	TCHAR S[20] = L"弹珠游戏";
	int h = textheight(S);
	int w = textwidth(S);
	outtextxy(WIDTH / 2 - w / 2 + FORWARD, HEIGHT / 4 - h / 2 + DOWN, S);

	//画开始摁妞
	setlinestyle(PS_SOLID, 2);
	setlinecolor(WHITE);
	rectangle(225 + FORWARD, 350 + DOWN, 375 + FORWARD, 400 + DOWN);
	TCHAR SS[20] = L"开始游戏";
	settextstyle(24, 0, _T("Consolas"));
	setbkmode(TRANSPARENT);
	outtextxy(300 - textwidth(SS) / 2 + FORWARD, 375 - textheight(SS) / 2 + DOWN, SS);

}
void playgame()
{

	cleardevice();
	setlinestyle(PS_SOLID, 2);
	setlinecolor(CYAN);
	rectangle(FORWARD, DOWN, FORWARD + WIDTH, DOWN + HEIGHT);
	//背景图片
	IMAGE BRF;
	loadimage(&BRF, _T("res\\cover.jpg"));
	putimage(FORWARD, +DOWN, &BRF, SRCCOPY);
	//背景音乐


	Initializeball();
	if (0 == PlaySound(TEXT("res\\Music\\Bk.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP))
	{
		printf("playsound false");
	}
	bool gameStarted = false;

	while (!gameStarted)
	{

		if (MouseHit()) {
			MOUSEMSG m = GetMouseMsg();
			if (m.x >= 225 + FORWARD && m.x <= 375 + FORWARD && m.y >= 350 + DOWN && m.y <= 400 + DOWN && m.uMsg == WM_LBUTTONDOWN) {
				cleardevice();
				setbkcolor(BLACK);
				gameStarted = true;
			}
		}
	}

	int select;
	bool continuegame = true;
	int ballnumbers = 3;//球的数量

	while (continuegame)
	{
		//初始化部分
		cleardevice();
		rectangle(FORWARD, DOWN, FORWARD + WIDTH, DOWN + HEIGHT);
		bool gameflag = true;
		int ballnumbers = 3;//球的数量
		Rectanglecontrol rect(250 + FORWARD, 500 + DOWN, 350 + FORWARD, 510 + DOWN, 10);//创建矩型
		Ball ball(300 + FORWARD, 480 + DOWN, 0, 0, WHITE, 5);//Ball(int a, int b, int c, int d,COLORREF e,int f) :x(a), y(b), dx(c), dy(d),color(e),r(f) {};
		//Ball ball(550, 10, 0, 0, WHITE, 5);
		int blocknumbers = BLOCKNUMBERS;
		block BLL[BLOCKNUMBERS];
		BeginBatchDraw();
		//游戏部分
		int flag = 1;
		int minflag = 1;//control the ball initial v

		while (gameflag) {
			//cleardevice();
			setlinestyle(PS_SOLID, 2);
			setlinecolor(CYAN);
			rectangle(FORWARD, DOWN, FORWARD + WIDTH, DOWN + HEIGHT);
			gamefailuredetect(gameflag, ballnumbers, continuegame);
			gamesuccessdetect(gameflag, continuegame, BLL, 140);//真正的第一关，后面的数字必须准确
			//gamesuccessdetect(gameflag, continuegame, BLL, 1);
			balldisplay(ballnumbers);
			balldecrese(ball, ballnumbers, minflag, rect);


			if (flag == 1)
			{
				initialcontrolrectangle(rect);
				flag = 0;
			}
			Blockbreak(BLOCKNUMBERS, BLL, ball);//第一关
			//Blockbreak(1, BLL, ball);
			BLOCKLEVEL_1(BLL);

			Autoball(ball, rect);//画自动小球
			FlushBatchDraw();

			if (_kbhit()) {
				int key = _getch();
				//下面是启动时赋予初速度
				if (minflag)
				{
					ball.dx =2;
					ball.dy = 3;
					minflag = 0;
				}
				drawcontrolrectangle(rect, key);
				if (key == 27)
				{
					HWND hwnd = GetHWnd();
					select = MessageBox(hwnd, _T("重新开始？还是退出游戏？"), _T("请选择"), MB_YESNOCANCEL | MB_DEFBUTTON1);
					if (select == IDYES)				// 选择再来一次
					{
						gameflag = false;
					}
					else if (select == IDNO)	// 选择退出游戏
					{
						continuegame = false;
						gameflag = false;
					}
					else if (select == IDCANCEL)	// 关闭消息框
					{
					}
				}
			}

			Sleep(10);
		}
		EndBatchDraw();
		
		
	}
	PlaySound(NULL, 0, NULL);
	//return 1;//我打算胜利返回1 有奖品 但还不打算做
}
