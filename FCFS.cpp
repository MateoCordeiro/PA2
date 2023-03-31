#include <iostream>
#include <iomanip>
#include <list>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "FCFS.h"
using namespace std;

FCFS::FCFS() {
        bool seeded=false;
    if (!seeded)
    {
        srand(time(nullptr));
        seeded=true;
    }
}

void FCFS::hi() {
    cout << "hi" << "\n" << endl;
}

void FCFS::init(int l, float AST, int SC) {

    lambda = l;
    averageServiceTime = AST;
    stopCondition = SC;
    readyQueueCount = 0;
}

void FCFS::BuildList() {

    for (int i = 0; i < stopCondition; i++)
    {
        
    }
}

float FCFS::genRand0_1() {

    return ((double) rand() /RAND_MAX);
}

float FCFS::genIntArrTime() {
double value = 0;
while (value <= 0) {
  value = -(1 / lambda) * log(rand());
}
return value;
}

float FCFS::genServiceTime() {
    float u, x;
    x = 0;
    while (x == 0)
    {
        u = genRand0_1();
        x = (averageServiceTime * -log(1 - u));
    }
    return x ;
}

void FCFS::runSim() {

    //first needs
    //1. BuildList
    //2. scheduleEvent
    //3. genRand0_1
    //4. genIntArrTimes

 } 