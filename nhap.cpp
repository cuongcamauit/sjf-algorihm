#include <iostream>
#include <string>
#include "mylib.h"
#define MAX 100
using namespace std;
int x = 50;int y = 5;
//===============
void box(int x, int y, int w, int h, int t_color, int b_color,string nd);
void n_box(int x, int y, int w, int h, int t_color, int b_color, string nd, int sl);
void menu();
void thanh_sang(int x, int y, int w, int h, int b_color, string nd);
main()
{
    system("cls");
	//--- menu dong ----
	menu();
	

}
void menu()
{
	ShowCur(1);
	//----- setting ----
	int w = 20;
	int h = 2;
	int t_color = 11;
	int b_color = 1;
	int b_color_sang = 75;
	string nd = "hello";
	int sl = 4;
	n_box(x, y, w, h, t_color, b_color, nd, sl);
	
	//-------------
	int xp = x;int yp = y;//tọa độ thanh sáng
	int xcu = xp;int ycu = yp;
	bool kt = true;
	while (true)
	{
		//------ in ----
		if (kt == true)
		{
			//----- back space ----
			gotoXY(xcu, ycu);
			thanh_sang(xcu, ycu, w, h, b_color, nd);//rs thanh sang cu
			xcu = xp;ycu = yp;
			//-------------
			thanh_sang(xp, yp, w, h, b_color_sang, nd);
			kt = false;
		}
		//----- dieu khien ---- //----- di chuyen ----
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				kt = true;// đã bấm
				c = _getch();
				if (c == 72)
				{
					if(yp != y)yp -= 2;
					else
					{
						yp = y + h*(sl - 1);
					}
				}
				else if (c == 80 )
				{
					if(yp != y + h*(sl - 1))yp += 2;
					else
					{
						yp = y;
					}
				}
			}
		}
		//---- speed ----
	}

}
void thanh_sang(int x,int y,int w,int h,int b_color,string nd)
{
	textcolor(b_color);
	for (int iy = y + 1;iy <= y + h - 1;iy++)
	{
		for (int ix = x + 1;ix <= x + w - 1;ix++)
		{
			gotoXY(ix, iy);cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 1, y + 1);
	cout << nd;
}
void box(int x, int y,int w,int h,int t_color,int b_color, string nd)
{
	textcolor(b_color);
	for (int iy = y+1;iy <= y + h-1;iy++)
	{
		for (int ix = x+1;ix <= x + w-1;ix++)
		{
			gotoXY(ix, iy);cout << " ";
		}
	}
	SetColor(7);
	gotoXY(x + 1, y + 1);
	cout << nd;
	//============= ve vien =============
	textcolor(1);
	SetColor(t_color);//update
	if (h <= 1 || w<=1)return;
	for (int ix = x;ix <= x + w;ix++)
	{
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y;iy <= y + h;iy++)
	{
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y);cout << char(218);
	gotoXY(x + w, y);cout << char(191);
	gotoXY(x, y + h);cout << char(192);
	gotoXY(x + w, y + h);cout << char(217);

}
void n_box(int x, int y, int w, int h, int t_color, int b_color, string nd,int sl)
{
	for (int i = 0;i < sl;i++)
	{
		box(x, y + (i * 2), w, h, t_color, b_color, nd);//i = 0 => x,y, i = 1: x,y+2
		if (i != 0)
		{
			gotoXY(x, y + (i * 2));cout << char(195);
			gotoXY(x + w, y + (i * 2));cout << char(180);
		}
	}
}