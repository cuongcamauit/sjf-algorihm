#pragma once
#include <bits/stdc++.h>
// #include <vector>
// #include <iostream>
// #include <algorithm> 
// #include <iomanip>
using namespace std;

// Process class
class Process {  
    public:

        // attributes of Process: id(Ordinal number),...
        int id, arrivalTime, burstTime, waitingTime, turnaroundTime, completeTime, burstTime2; // burstTime will change but burstTime2 will not change

        // start and end point of each period
        vector<int> start, end;

        // Total of burstTime
        static int totalTime;

        // execution order of the process
        static vector<int> stt;

        // Contructor
        Process(int, int, int);
};