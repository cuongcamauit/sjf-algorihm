#include "mylib.h"
#include "sjf.h"
#include "sjf.cpp"

// #include <string>
// #include <stdlib.h>


// light bar when select
void light_bar(int x,int y,int w,int h,int b_color,string nd)
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

// make a frame
void framing (int x, int y, int w, int h, int t=0) {
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

// output text with color and particular position
void out_format(int x, int y, string s, int color=7) {
    textcolor(color);
    gotoXY(x, y);
    cout << s;
}

// select preempty/nonpreempty/exit
int options(int x=18, int y=5) {
    system("cls");
    framing (x, y, 80, 15, 1);
    framing (x+10, y+2, 60, 2);
    framing (x+10, y+5, 60, 2);
    framing (x+10, y+8, 60, 2);
    framing (x+10, y+11, 60, 2);

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
			light_bar(xcu, ycu, 60, 2, 1, nd);//rs thanh sang cu
            // gotoXY(xcu+1, ycu+1);
			xcu = xp;ycu = yp;
            if (yp == y+5)
                nd = "                Nonpreemptive SJF scheduling";
            else if (yp == y+8)
                nd = "                 Preemptive SJF scheduling";
            else if (yp == y+11) 
                nd = "                            Exit";
			//-------------
			light_bar(xp, yp, 60, 2, 75, nd);
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

// input Processes
vector<Process> input_ui(int x=30, int y=5) {
    vector<Process> P;
    Process::stt.clear();
    Process::totalTime = 0;
    system("cls");
    framing (x, y, 50, 15, 1);
    framing (x+10, y+2, 30, 2);
    out_format(x+15, y+3, "Number of process: ");
    int n;
    gotoXY(x+35, y+3);
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=y+1;j<y+15;j++) 
            out_format(x+1, j, "                                             ");
        int a, b;
        framing (x+10, y+2, 30, 2);
        out_format(x+18, y+3, "Enter Process " + to_string(i+1));
        framing (x+5, y+5, 40, 2);
        out_format(x+10, y+5, "Enter arrival time"); 
        gotoXY(x+11, y+6);
        cin >> a;
        framing (x+5, y+8, 40, 2);
        out_format(x+10, y+8, "Enter burst time");
        gotoXY(x+11, y+9);
        cin >> b;
        P.push_back(Process(i+1, a, b));
    }
    textcolor(1);
    SetColor(7);
    system("cls");
    return P;
}

// print origin table
void table(vector<Process> P, int x=10, int y=2) {
    out_format(x+11, y-1, "Sorted by Arrival Time");
    framing (x, y, 10, 2);
    out_format(x+1, y+1, "Name");
    framing (x+10, y, 15, 2);
    out_format(x+11, y+1, "Arrival Time");
    framing (x+25, y, 15, 2);
    out_format(x+26, y+1, "Burst Time");
    framing (x, y+2, 40, P.size()+1);
    for (int i=0;i<P.size();i++) {
        out_format(x+1, y+i+3, "P"+to_string(P[i].id));
        out_format(x+11, y+i+3, to_string(P[i].arrivalTime));
        out_format(x+26, y+i+3, to_string(P[i].burstTime2));
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

// print gantt_chart
void gantt(vector<Process> P, int x=0, int y=0) {
    out_format(x, y-1, "Gannt chart");
    int t = -1;
    for (int i: Process::stt) {
        framing (P[i-1].start[0]*3+x, y, (P[i-1].end[0]-P[i-1].start[0])*3, 2);
        out_format(x, y+3, "0");
        out_format(P[i-1].start[0]*3+1+x, y+1, "P"+to_string(i), P[i-1].id);
        out_format(P[i-1].start[0]*3+x, y+3, to_string(P[i-1].start[0]));
        out_format(P[i-1].end[0]*3+x, y+3, to_string(P[i-1].end[0]));
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

// print executed table
void tablefull(vector<Process> P, int x=10, int y=2) {
    out_format(x+33, y-1, "Sorted by Complete Time");
    framing (x, y, 10, 2);
    out_format(x+1, y+1, "Name");

    framing (x+10, y, 15, 2);
    out_format(x+11, y+1, "Arrival Time");

    framing (x+25, y, 15, 2);
    out_format(x+26, y+1, "Burst Time");

    framing (x+40, y, 15, 2);
    out_format(x+41, y+1, "Waiting Time");

    framing (x+55, y, 20, 2);
    out_format(x+56, y+1, "Turnarround Time");

    framing (x+75, y, 15, 2);
    out_format(x+76, y+1, "Complete Time");

    framing (x, y+2, 90, P.size()+1);

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
        out_format(x+1, y+i+3, "P"+to_string(P[i].id));
        out_format(x+11, y+i+3, to_string(P[i].arrivalTime));
        out_format(x+26, y+i+3, to_string(P[i].burstTime2));
        out_format(x+41, y+i+3, to_string(P[i].waitingTime));
        out_format(x+56, y+i+3, to_string(P[i].turnaroundTime));
        out_format(x+76, y+i+3, to_string(P[i].completeTime));
    }

    out_format(1, P.size()+y+12, "Sum waiting time: "+to_string(sum));
    out_format(1, P.size()+y+13, "Average waiting time: "+to_string(sum/P.size()));

    gotoXY(1, P.size()+y+13);
    cout << "Average waiting time: " << setprecision(2) << float(sum)/P.size();


}