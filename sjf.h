#pragma once
#include <vector>
#include <iostream>
#include <algorithm> 
#include <iomanip>
using namespace std;
class Process {
    public:
        int id, arrivalTime, burstTime, waitingTime, turnaroundTime, completeTime, burstTime2;
        vector<int> start, end;
        static int totalTime;
        static vector<int> stt;
        Process(int, int, int);
};