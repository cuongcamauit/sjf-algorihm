
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
void xuat(int x, int y, string s, int color=7) {
    textcolor(color);
    gotoXY(x, y);
    cout << s;
}
int options(int x=18, int y=5) {
    system("cls");
    taokhung(x, y, 80, 15, 1);
    taokhung(x+10, y+2, 60, 2);
    taokhung(x+10, y+5, 60, 2);
    taokhung(x+10, y+8, 60, 2);
    taokhung(x+10, y+11, 60, 2);

    gotoXY(x+36, y+3);
    cout << "Option!";
    gotoXY(x+26, y+6);
    cout << "Nonpreemptive SJF scheduling";
    gotoXY(x+27, y+9);
    cout << "Preemptive SJF scheduling";
    gotoXY(x+38, y+12);
    cout << "Exit";

    int xp = x+10;int yp = y+5;//tọa độ thanh sáng
	int xcu = xp;int ycu = yp;
	bool kt = true;
	while (true)
	{
		//------ in ----
		if (kt == true)
		{
            string nd;
            if (ycu == y+5)
                nd = "                Nonpreemptive SJF scheduling";
            else if (ycu == y+8)
                nd = "                 Preemptive SJF scheduling";
            else if (ycu == y+11) 
                nd = "                            Exit";
			//----- back space ----
			gotoXY(xcu, ycu);
			thanh_sang(xcu, ycu, 60, 2, 1, nd);//rs thanh sang cu
            // gotoXY(xcu+1, ycu+1);
			xcu = xp;ycu = yp;
            if (yp == y+5)
                nd = "                Nonpreemptive SJF scheduling";
            else if (yp == y+8)
                nd = "                 Preemptive SJF scheduling";
            else if (yp == y+11) 
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
					if(yp != y+5) yp -= 3;
					else
					{
						yp = y+11;
					}
				}
				else if (c == 80 )
				{
					if(yp != y+11)yp += 3;
					else
					{
						yp = y+5;
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
    if (yp == y+11)
        return -1;
    else if (yp == y+8) 
        return 1;
    else return 0; 
}
vector<Process> nhapui(int x=30, int y=5) {
    vector<Process> P;
    Process::stt.clear();
    system("cls");
    taokhung(x, y, 50, 15, 1);
    taokhung(x+10, y+2, 30, 2);
    xuat(x+15, y+3, "Nhap so tien trinh: ");
    int n;
    gotoXY(x+35, y+3);
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=y+1;j<y+15;j++) 
            xuat(x+1, j, "                                             ");
        int a, b;
        taokhung(x+10, y+2, 30, 2);
        xuat(x+18, y+3, "Nhap tien trinh " + to_string(i+1));
        taokhung(x+5, y+5, 40, 2);
        xuat(x+10, y+5, "Nhap arrival time"); 
        gotoXY(x+11, y+6);
        cin >> a;
        taokhung(x+5, y+8, 40, 2);
        xuat(x+10, y+8, "Nhap burst time");
        gotoXY(x+11, y+9);
        cin >> b;
        P.push_back(Process(i+1, a, b));
    }
    textcolor(1);
    SetColor(7);
    system("cls");
    return P;
}
void table(vector<Process> P, int x=10, int y=2) {
    xuat(x+11, y-1, "Sorted by Arrival Time");
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
    textcolor(10);
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
    xuat(x, y-1, "Gannt chart");
    int t = -1;
    for (int i: Process::stt) {
        taokhung(P[i-1].start[0]*3+x, y, (P[i-1].end[0]-P[i-1].start[0])*3, 2);
        xuat(x, y+3, "0");
        xuat(P[i-1].start[0]*3+1+x, y+1, "P"+to_string(i), P[i-1].id);
        xuat(P[i-1].start[0]*3+x, y+3, to_string(P[i-1].start[0]));
        xuat(P[i-1].end[0]*3+x, y+3, to_string(P[i-1].end[0]));
        //cout << i << "(" << P[i-1].start[0] << "," << P[i-1].end[0] << ")"<< " "; 
        
        
        if (t == P[i-1].start[0]) {
            textcolor(10);
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

void tablefull(vector<Process> P, int x=10, int y=2) {
    xuat(x+33, y-1, "Sorted by Complete Time");
    taokhung(x, y, 10, 2);
    xuat(x+1, y+1, "Name");

    taokhung(x+10, y, 15, 2);
    xuat(x+11, y+1, "Arrival Time");

    taokhung(x+25, y, 15, 2);
    xuat(x+26, y+1, "Burst Time");

    taokhung(x+40, y, 15, 2);
    xuat(x+41, y+1, "Waiting Time");

    taokhung(x+55, y, 20, 2);
    xuat(x+56, y+1, "Turnarround Time");

    taokhung(x+75, y, 15, 2);
    xuat(x+76, y+1, "Complete Time");

    taokhung(x, y+2, 90, P.size()+1);

    gotoXY(x, y+2);
    cout << char(195);
    gotoXY(x+90, y+2);
    cout << char(180);

    gotoXY(x+10, y);
    cout << char(194);
    gotoXY(x+25, y);
    cout << char(194);
    gotoXY(x+40, y);
    cout << char(194);
    gotoXY(x+55, y);
    cout << char(194);
    gotoXY(x+75, y);
    cout << char(194);

    gotoXY(x+10, y+2);
    cout << char(193);
    gotoXY(x+25, y+2);
    cout << char(193);
    gotoXY(x+40, y+2);
    cout << char(193);
    gotoXY(x+55, y+2);
    cout << char(193);
    gotoXY(x+75, y+2);
    cout << char(193);

    int sum = 0;
    for (int i=0;i<P.size();i++) {
        sum += P[i].waitingTime;
        xuat(x+1, y+i+3, "P"+to_string(P[i].id));
        xuat(x+11, y+i+3, to_string(P[i].arrivalTime));
        xuat(x+26, y+i+3, to_string(P[i].burstTime2));
        xuat(x+41, y+i+3, to_string(P[i].waitingTime));
        xuat(x+56, y+i+3, to_string(P[i].turnaroundTime));
        xuat(x+76, y+i+3, to_string(P[i].completeTime));
    }

    xuat(1, P.size()+y+12, "Sum waiting time: "+to_string(sum));
    xuat(1, P.size()+y+13, "Average waiting time: "+to_string(sum/P.size()));

    gotoXY(1, P.size()+y+13);
    cout << "Average waiting time: " << setprecision(2) << float(sum)/P.size();


}
// int main() {
//     int k = options();
//     if (k == -1)
//         return 0;
//     nhapui();
// }