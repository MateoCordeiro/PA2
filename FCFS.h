#ifndef FCFS_H
#define FCFS_H
#include <list>
#include <queue>
#include"PQ.cpp"
using namespace std;

class FCFS
{
private:

public:


    
  FCFS();
  void hi();
  void init(int l, float AST, int SC);
  void BuildList();
  float genRand0_1();
  float genIntArrTime();
  float genServiceTime();
  void runSim();

    int lambda;
    float averageServiceTime;
    int stopCondition;
    int readyQueueCount;
    bool isIdle;

};
#endif