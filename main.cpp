#include "ui.cpp"

//tg-th second
int tg;

// function sorted by complete time
bool cmp_completeTime (Process P1, Process P2) {
    return P1.completeTime < P2.completeTime;
}

// function sorted by arrival time
bool cmp_arrivalTime (Process P1, Process P2) {
    return P1.arrivalTime < P2.arrivalTime;
}

bool cmp_id(Process P1, Process P2) {
    return P1.id < P2.id;
}

// find process, which have minimum burst time in time tg-th
int min_validity(vector<Process> P, bool a[]) {
    int min = 999999999;
    int index = -1;
    for (int i=0;i<P.size();i++) 
        if ((a[i]) && (P[i].burstTime<min) && (P[i].arrivalTime<=tg)) {
            min = P[i].burstTime;
            index = i;
        }
    return index;
}

// function sjf
void sjf_option(vector<Process> P, bool option) {
    int x = 50, y = 2;
    tg = 0;
    // option -> preemptive
    
    // sort by arrival time
    sort(P.begin(), P.end(), cmp_arrivalTime);

    // variable save the number of Process
    int num_Pro = P.size();

    // tick Process
    bool a[num_Pro];
    for (int i=0;i<num_Pro;i++)
        a[i] = true;
    
    //
    textcolor(5);
    table(P, x, y);
    while (num_Pro) {

        // find index Process
        int k = min_validity(P, a);

        if (k!=-1) {
            // per second or per process
            int step = P[k].burstTime;               // none-preempty
            if (option)                                
                step = 1;                            // preempty

            
            P[k].burstTime -= step;

            // calculation when k-th process completed
            if (P[k].burstTime ==0) {
                num_Pro --;
                a[k] = false;
                P[k].completeTime = tg + step;
                P[k].turnaroundTime = P[k].completeTime - P[k].arrivalTime;
                P[k].waitingTime = P[k].turnaroundTime - P[k].burstTime2;
            }

            // save order execution
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
    
    sort(P.begin(), P.end(), cmp_completeTime);
    tablefull(P, x-25, P.size()+6+y);
    sort(P.begin(), P.end(), cmp_id);
    gantt(P, 1, P.size()*2+y+12);
    gotoXY(0, P.size()+P.size()+6+y+14);  
}


// main function
int main() {
    int k = options(); // selection
    while (k!=-1) {    // if not select exit
        sjf_option(input_ui(), k);
        getch();       // press any key to continue
        k = options();
    }
    
}