#include "FunTest.h" 

#include <windows.h>
#include <math.h>
#include <graphics.h>
#include <time.h>
#include <conio.h>
#define PI 3.1415926
HDC hDc;

void Koch_Curve(double ax, double ay, double bx, double by)
{
	int c = 100;
	if (((bx - ax)*(bx - ax) + (by - ay)*(by - ay)) < c)
	{
		MoveToEx(hDc, ax + 50, 360 - ay, NULL);
		LineTo(hDc, bx + 50, 360 - by);
	}
	else
	{
		double cx, cy, dx, dy, ex, ey;
		double l, alfa;
		cx = ax + (bx - ax) / 3;  cy = ay + (by - ay) / 3;
		ex = bx - (bx - ax) / 3;  ey = by - (by - ay) / 3;
		Koch_Curve(ax, ay, cx, cy);
		Koch_Curve(ex, ey, bx, by);
		l = sqrt((ex - cx)*(ex - cx) + (ey - cy)*(ey - cy));
		alfa = atan((ey - cy) / (ex - cx));
		if (alfa >= 0 && (ex - cx) < 0 || alfa < 0 && (ex - cx) < 0)
			alfa = alfa + PI;
		dx = cx + cos(alfa + PI / 3)*l;
		dy = cy + sin(alfa + PI / 3)*l;
		Koch_Curve(cx, cy, dx, dy);
		Koch_Curve(dx, dy, ex, ey);
	}
}

void testFractal()
{
	HWND hwnd = GetConsoleWindow();
	hDc = GetDC(hwnd);
	system("color 2f");
	Koch_Curve(80, 40, 240, 360);
	Koch_Curve(240, 360, 420, 100);
	Koch_Curve(420, 100, 80, 40);
}

void InitWin(int Width, int Height, COLORREF color=WHITE)
{
	initgraph(Width, Height);
	if (WHITE != color)
	{
		setlinecolor(color);
	}

	for (int y = 0; y < Height; y++)
	{
		line(0, y, Width, y);
	}
}


void GraphicsTest()
{
	const int Width = 640;
	const int Height = 480;
	// ´´½¨»æÍ¼´°¿Ú
	InitWin(Width, Height);
	setbkcolor(WHITE);
	settextstyle(20, 10, "Times New Roman");
	const COLORREF colorArray[] = { BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, YELLOW };
	for (int i = 0; i < 100; i++)
	{
		settextcolor(colorArray[i % 10]);
		outtextxy(250, 250, "Hello bobo");
		Sleep(200);
		if (_kbhit())
			break;
	}
	//saveimage("d:\\Users\\jin-bo.huang\\Desktop\\1.bmp");

	
	closegraph();
	return;
}
