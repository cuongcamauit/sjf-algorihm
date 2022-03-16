#include "sjf.h"
int Process::totalTime = 0;  // initial
vector<int> Process::stt = {};// initial

// Contructor
Process::Process(int id, int arrivalTime, int burstTime) {
    this->id = id;
    this->arrivalTime = arrivalTime;
    this->burstTime = burstTime;
    this->burstTime2 = burstTime;
    totalTime += this->burstTime;
}