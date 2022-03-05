#include "ui.cpp"

int tg;
bool cmp_completeTime (Process P1, Process P2) {
    return P1.completeTime < P2.completeTime;
}

bool cmp_arrivalTime (Process P1, Process P2) {
    return P1.arrivalTime < P2.arrivalTime;
}

int minvaliable(vector<Process> P, bool a[]) {
    int min = 999999999;
    int index = -1;
    for (int i=0;i<P.size();i++) 
        if ((a[i]) && (P[i].burstTime<min) && (P[i].arrivalTime<=tg)) {
            min = P[i].burstTime;
            index = i;
        }
    return index;
}

void sjf_option(vector<Process> P, bool option) {
    int x = 50, y = 2;
    // option -> preemptive
    tg = 0;
    sort(P.begin(), P.end(), cmp_arrivalTime);
    int num_Pro = P.size();
    bool a[num_Pro];
    for (int i=0;i<num_Pro;i++)
        a[i] = true;
    textcolor(5);
    table(P, x, y);
    while (num_Pro) {
        int k = minvaliable(P, a);
        if (k!=-1) {
            // per second or per process
            int step = P[k].burstTime;
            if (option)
                step = 1;
            P[k].burstTime -= step;
            if (P[k].burstTime ==0) {
                num_Pro --;
                a[k] = false;
                P[k].completeTime = tg + step;
                P[k].turnaroundTime = P[k].completeTime - P[k].arrivalTime;
                P[k].waitingTime = P[k].turnaroundTime - P[k].burstTime2;
            }
            if (P[k].start.size() == 0 || P[k].end[P[k].end.size()-1] != tg) {
                P[k].start.push_back(tg);
                P[k].end.push_back(tg+step);
                Process::stt.push_back(P[k].id);
            } else {
                    P[k].end[P[k].end.size()-1] += 1;
                }

            tg += step-1;
        }
        tg ++;
    }
    gantt(P, 1, P.size()*2+y+12);
    sort(P.begin(), P.end(), cmp_completeTime);
    tablefull(P, x-25, P.size()+6+y);
    gotoXY(0, 44);  
}

int main() {
    int k = options();
    while (k!=-1) {
        sjf_option(nhapui(), k);
        getch();
        k = options();
    }
    
}