#include "tubesQueue.h"
int main()
{
    int Q, prioUp,time;
    Queue pTinggi, pSedang, pRendah,temp;

    createQueue(pTinggi);
    createQueue(pSedang);
    createQueue(pRendah);
    createQueue(temp);

    cout<<"Quantum :";
    cin>>Q;
    while(Q<=0){
        cout<<"Input tidak boleh nol dan negative, silahkan coba lagi"<<endl;
        cout<<"Quantum :";
        cin>>Q;
    }
    cout<<"PrioUp :";
    cin>>prioUp;
    while(prioUp<0){
        cout<<"Input tidak boleh negative, silahkan coba lagi"<<endl;
        cout<<"PrioUp :";
        cin>>prioUp;
    }
    time = 0;

    cout<<"Let's start"<<endl;
    start(pTinggi,pSedang,pRendah);
    penjadwalan(pTinggi,pSedang,pRendah,temp,Q,time,prioUp);


    printf("Average Turn Around Time: %.3f", averageTurnAroundTime(temp));
    printf("\nAverage Waiting Time: %.3f\n", averageWaitingTIme(temp));

    cout << "Hello world!" << endl;
    return 0;
}
