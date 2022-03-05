
#include "mylib.h"
#include <string>
#include <stdlib.h>
#include "sjf.h"
#include "sjf.cpp"
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
	SetColor(10);
	gotoXY(x + 1, y + 1);
	cout << nd;
}
void taokhung(int x, int y, int w, int h, int t=0) {
    textcolor(10);
    gotoXY(x, y);cout << char(218);
    Sleep(t);
    for (int i=1;i<w;i++) {
        gotoXY(x+i, y);
        cout << char(196);
        Sleep(t);
    }

    gotoXY(x + w, y);cout << char(191);
    Sleep(t);
    for (int i=1;i<h;i++) {
        gotoXY(x+w, y+i);
        cout << char(179);
        Sleep(t);
    }

    gotoXY(x + w, y + h);cout << char(217); 
    
    Sleep(t);
    for (int i=1;i<w;i++) {
        gotoXY(x+(w-i), y+h);
        cout << char(196);
        Sleep(t);
    }

    gotoXY(x, y + h);cout << char(192);
    Sleep(t);
    for (int i=1;i<h;i++) {
        gotoXY(x, y+(h-i));
        cout << char(179);
        Sleep(t);
    }
    
	
	
	   
}
void xuat(int x, int y, string s) {
    gotoXY(x, y);
    cout << s;
}
int options() {
    system("cls");
    taokhung(20, 10, 100, 15);
    taokhung(40, 12, 60, 2);
    taokhung(40, 15, 60, 2);
    taokhung(40, 18, 60, 2);
    taokhung(40, 21, 60, 2);

    gotoXY(66, 13);
    cout << "Option!";
    gotoXY(56, 16);
    cout << "Nonpreemptive SJF scheduling";
    gotoXY(57, 19);
    cout << "Preemptive SJF scheduling";
    gotoXY(68, 22);
    cout << "Exit";

    int xp = 40;int yp = 15;//tọa độ thanh sáng
	int xcu = xp;int ycu = yp;
	bool kt = true;
	while (true)
	{
		//------ in ----
		if (kt == true)
		{
            string nd;
            if (ycu == 15)
                nd = "                Nonpreemptive SJF scheduling";
            else if (ycu == 18)
                nd = "                 Preemptive SJF scheduling";
            else if (ycu == 21) 
                nd = "                            Exit";
			//----- back space ----
			gotoXY(xcu, ycu);
			thanh_sang(xcu, ycu, 60, 2, 1, nd);//rs thanh sang cu
            // gotoXY(xcu+1, ycu+1);
			xcu = xp;ycu = yp;
            if (yp == 15)
                nd = "                Nonpreemptive SJF scheduling";
            else if (yp == 18)
                nd = "                 Preemptive SJF scheduling";
            else if (yp == 21) 
                nd = "                            Exit";
			//-------------
			thanh_sang(xp, yp, 60, 2, 75, nd);
			kt = false;
            // gotoXY(xp+1, yp+1);
		}
		//----- dieu khien ---- //----- di chuyen ----
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				kt = true;// đã bấm
				c = _getch();
                cout << c;
				if (c == 72)
				{
					if(yp != 15) yp -= 3;
					else
					{
						yp = 21;
					}
				}
				else if (c == 80 )
				{
					if(yp != 21)yp += 3;
					else
					{
						yp = 15;
					}
                    
				} 

			} else if (c == 13)
                break;
		}
		//---- speed ----
	}
    textcolor(1);
    SetColor(7);
    system("cls");
    if (yp == 21)
        return -1;
    else if (yp == 18) 
        return 1;
    else return 0; 
}
vector<Process> nhapui() {
    vector<Process> P;
    Process::stt.clear();
    system("cls");
    taokhung(50, 10, 50, 15);
    taokhung(60, 12, 30, 2);
    xuat(65, 13, "Nhap so tien trinh: ");
    int n;
    gotoXY(85, 13);
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=11;j<25;j++) 
            xuat(51, j, "                                             ");
        int a, b;
        taokhung(60, 12, 30, 2);
        xuat(68, 13, "Nhap tien trinh " + to_string(i+1));
        taokhung(55, 15, 40, 2);
        xuat(60, 15, "Nhap arrival time"); 
        gotoXY(61, 16);
        cin >> a;
        taokhung(55, 18, 40, 2);
        xuat(60, 18, "Nhap burst time");
        gotoXY(61, 19);
        cin >> b;
        P.push_back(Process(i+1, a, b));
    }
    textcolor(1);
    SetColor(7);
    system("cls");
    return P;
}
void table(vector<Process> P, int x=10, int y=2) {
    taokhung(x, y, 10, 2);
    xuat(x+1, y+1, "Name");
    taokhung(x+10, y, 15, 2);
    xuat(x+11, y+1, "Arrival Time");
    taokhung(x+25, y, 15, 2);
    xuat(x+26, y+1, "Burst Time");
    taokhung(x, y+2, 40, P.size()+1);
    for (int i=0;i<P.size();i++) {
        xuat(x+1, y+i+3, "P"+to_string(P[i].id));
        xuat(x+11, y+i+3, to_string(P[i].arrivalTime));
        xuat(x+26, y+i+3, to_string(P[i].burstTime2));
    }
    gotoXY(x, y+2);
    cout << char(195);
    gotoXY(x+40, y+2);
    cout << char(180);
    gotoXY(x+10, y);
    cout << char(194);
    gotoXY(x+25, y);
    cout << char(194);
    gotoXY(x+10, y+2);
    cout << char(193);
    gotoXY(x+25, y+2);
    cout << char(193);
}


void gantt(vector<Process> P, int x=0, int y=0) {
    int t = -1;
    for (int i: Process::stt) {
        taokhung(P[i-1].start[0]*3+x, y, (P[i-1].end[0]-P[i-1].start[0])*3, 2);
        xuat(x, y+3, "0");
        xuat(P[i-1].start[0]*3+1+x, y+1, "P"+to_string(i));
        xuat(P[i-1].start[0]*3+x, y+3, to_string(P[i-1].start[0]));
        xuat(P[i-1].end[0]*3+x, y+3, to_string(P[i-1].end[0]));
        //cout << i << "(" << P[i-1].start[0] << "," << P[i-1].end[0] << ")"<< " "; 
        
        if (t == P[i-1].start[0]) {
            gotoXY(x+t*3, y);
            cout << char(194);
            gotoXY(x+t*3, y+2);
            cout << char(193);
        }

        t = P[i-1].end[0];


        P[i-1].start.erase(P[i-1].start.begin());
        P[i-1].end.erase(P[i-1].end.begin());
    }
}
// int main() {
//     int k = options();
//     if (k == -1)
//         return 0;
//     nhapui();
// }