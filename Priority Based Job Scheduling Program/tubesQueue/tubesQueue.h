#ifndef TUBESQUEUE_H_INCLUDED
#define TUBESQUEUE_H_INCLUDED
#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define Head(Q) (Q).Head
#define Tail(Q) (Q).Tail


struct infotype{
    string job;
    int waitingTime;
    int turnAroundTime;
    int burstTime;
};
typedef struct element *adr;
struct element{
    infotype info;
    adr next;
};
struct Queue{
    adr Head;
    adr Tail;
};


void createQueue(Queue &Q);
adr createElement(infotype x);
void enqueue(Queue &Q, adr p);
void dequeue(Queue &Q, adr p);
void showSemuaQueue(Queue Q);
void do1Round(Queue &Q, Queue &R, Queue &S,int kuantum,Queue &temp);
float averageTurnAroundTime(Queue Q);
float averageWaitingTIme(Queue Q);
void start(Queue &Q,Queue &R,Queue &S);
void penjadwalan(Queue &pTinggi,Queue &pSedang,Queue &pRendah,Queue &temp,int Q,int time,int prioUp);

#endif // TUBESQUEUE_H_INCLUDED
