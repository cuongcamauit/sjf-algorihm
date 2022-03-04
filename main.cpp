#include "ui.cpp"

int tg;
bool cmp_burstTime (Process P1, Process P2) {
    return P1.burstTime < P2.burstTime;
}

bool cmp_arrivalTime (Process P1, Process P2) {
    return P1.arrivalTime < P2.arrivalTime;
}

void out(vector<Process> P) {
    int sum = 0;
    cout << "Id\tArrivalTime\tBurstTime\tWaitingTime\tTurnaroundTime\tCompleteTime" << endl;
    for (Process p: P) {
        cout << "P" << p.id << '\t' << p.arrivalTime << '\t' << p.burstTime2 << '\t' << p.waitingTime << '\t' << p.turnaroundTime << "\t" << p.completeTime << endl;
        sum += p.waitingTime;
    }
    cout << "Sum waiting time: " << sum << endl;
    cout << "Average waiting time: " << sum / P.size() << endl;
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
    // option -> preemptive
    tg = 0;
    sort(P.begin(), P.end(), cmp_arrivalTime);
    int num_Pro = P.size();
    bool a[num_Pro];
    for (int i=0;i<num_Pro;i++)
        a[i] = true;
    for (Process p: P) {
        cout << p.id << '\t' << p.arrivalTime << "\t" << p.burstTime2 << endl;
    }
    while (num_Pro) {
        int k = minvaliable(P, a);
        if (k!=-1) {
            if (option) {
                // excute per second
                P[k].burstTime -= 1;
                if (P[k].burstTime == 0) {
                    num_Pro --;
                    a[k] = false;
                    P[k].completeTime = tg+1;
                    P[k].turnaroundTime = P[k].completeTime - P[k].arrivalTime;
                    P[k].waitingTime = P[k].turnaroundTime - P[k].burstTime2; 
                }
                if (P[k].start.size() == 0 || P[k].end[P[k].end.size()-1] != tg) {
                    P[k].start.push_back(tg);
                    P[k].end.push_back(tg+1);
                    Process::stt.push_back(P[k].id);
                } else {
                    P[k].end[P[k].end.size()-1] += 1;
                }

            } else {
                // excute per process
                num_Pro --;
                a[k] = false;
                P[k].completeTime = tg+P[k].burstTime2;
                P[k].turnaroundTime = P[k].completeTime - P[k].arrivalTime;
                P[k].waitingTime = P[k].turnaroundTime - P[k].burstTime2;
                P[k].start.push_back(tg);
                P[k].end.push_back(tg+P[k].burstTime2);
                tg += P[k].burstTime2-1;    
                Process::stt.push_back(P[k].id);            
            }
        }
        tg ++;
    }
    out(P);

    for (int i: Process::stt) {
       cout << i << "(" << P[i-1].start[0] << "," << P[i-1].end[0] << ")"<< " "; 
       P[i-1].start.erase(P[i-1].start.begin());
       P[i-1].end.erase(P[i-1].end.begin());
    }
        
    
}

int main() {
    int k = options();
    if (k == -1)
        return 0;
    sjf_option(nhapui(), k);
    

}