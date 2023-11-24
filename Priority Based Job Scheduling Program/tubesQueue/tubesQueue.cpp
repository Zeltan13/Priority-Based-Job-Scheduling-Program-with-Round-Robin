#include "tubesQueue.h"
void createQueue(Queue &Q){
    Head(Q) = NULL;
    Tail(Q) = NULL;
}

adr createElement(infotype x){
    adr p = new element;
    info(p) = x;
    next(p) = NULL;
    return p;
}

void enqueue(Queue &Q, adr p){
    if (Head(Q) == NULL && Tail(Q) == NULL){
        Head(Q) = p;
        Tail(Q) = p;
    }else{
        next(Tail(Q)) = p;
        Tail(Q) = p;
    }
}

void dequeue(Queue &Q, adr p){
    if (Head(Q) == NULL && Tail(Q) == NULL){
        cout<<"Queue Kosong"<<endl;
    }else if (Head(Q) == Tail(Q)){
        Head(Q) = NULL;
        Tail(Q) = NULL;
    }else{
        p = Head(Q);
        Head(Q) = next(Head(Q));
        next(p) = NULL;
    }
}

void showSemuaQueue(Queue Q){
    adr p = Head(Q);
    if (Head(Q)== NULL){
        cout<<"Kosong"<<endl;
    }else{
        while (p!= NULL){
            //keluarin (cout) info apa aja yang perlu ditunjukin
            cout << "Kegiatan : " << info(p).job << ", Sisa Burst Time: "<<info(p).burstTime<<endl;
            cout << "WT="<<info(p).waitingTime << ", "<<"TAT="<<info(p).turnAroundTime<<endl;
            p = next(p);
        }
    }

}
float averageTurnAroundTime(Queue Q){
    float nData = 0, jumTAT = 0;
    adr p = Head(Q);
    while(p != NULL){
        nData++;
        jumTAT = jumTAT + info(p).turnAroundTime;
        p = next(p);
    }
    return jumTAT/nData;
}

float averageWaitingTIme(Queue Q){
    float nData = 0, jumWT = 0;
    adr p = Head(Q);
    while(p != NULL){
        nData++;
        jumWT = jumWT + info(p).waitingTime;
        p = next(p);
    }
    return jumWT/nData;
}

void do1Round(Queue &Q, Queue &R, Queue &S, int kuantum,Queue &temp){
    adr q = Head(Q); //tetep head
    adr r = Head(R);
    adr s = Head(S);
    adr t = Head(temp);
    adr addq = Head(Q); //yg gerak
    adr addr = Head(R); //yg gerak
    adr adds = Head(S); //yg gerak
    //cout<<info(q).burstTime;
    //cout<<kuantum;
    if (info(q).burstTime <= kuantum){
        while (addq!=NULL){
            info(addq).turnAroundTime += info(q).burstTime;
            addq = next(addq);
        }
        while (addr!=NULL){
            info(addr).turnAroundTime += info(q).burstTime;
            addr = next(addr);
        }
        while(adds!=NULL){
            info(adds).turnAroundTime += info(q).burstTime;
            adds = next(adds);
        }
        dequeue(Q,q);

        addq = Head(Q);
        addr = Head(R);
        adds = Head(S);
        while (addq!=NULL){
            info(addq).waitingTime += info(q).burstTime ;
            addq = next(addq);
        }
        while (addr!=NULL){
            info(addr).waitingTime += info(q).burstTime;
            addr = next(addr);
        }
        while(adds!=NULL){
            info(adds).waitingTime += info(q).burstTime;
            adds = next(adds);
        }
        info(q).burstTime = 0;
        enqueue(temp,q);
    }else{
        while (addq!=NULL){
            info(addq).turnAroundTime += kuantum ;
            addq = next(addq);
        }
        while (addr!=NULL){
            info(addr).turnAroundTime += kuantum;
            addr = next(addr);
        }
        while(adds!=NULL){
            info(adds).turnAroundTime += kuantum;
            adds = next(adds);
        }

        dequeue(Q,q);

        addq = Head(Q);
        addr = Head(R);
        adds = Head(S);
        while (addq!=NULL){
            info(addq).waitingTime += kuantum ;
            addq = next(addq);
        }
        while (addr!=NULL){
            info(addr).waitingTime += kuantum;
            addr = next(addr);
        }
        while(adds!=NULL){
            info(adds).waitingTime += kuantum;
            adds = next(adds);
        }
        info(q).burstTime -= kuantum;
        enqueue(Q,q);
    }

}


void start(Queue &Q, Queue &R, Queue &S){
    int x,i,quota1,quota2,quota3;
    i = 0;
    cout << "Jumlah kegiatan yang dilakukan :";
    cin>> x;
    while (x<0){
        cout<<"Input tidak boleh negative, silahkan coba lagi"<<endl;
        cout << "Jumlah kegiatan yang dilakukan :";
        cin>> x;
    }

    cout<< "Jumlah awal kegiatan Prioritas Tinggi :";
    cin>>quota1;
    while (quota1<0){
        cout<<"Input tidak boleh negative, silahkan coba lagi"<<endl;
        cout<< "Jumlah awal kegiatan Prioritas Tinggi :";
        cin>>quota1;
    }

    cout<< "Jumlah awal kegiatan Prioritas Sedang :";
    cin>>quota2;
    while (quota2<0){
        cout<<"Input tidak boleh negative, silahkan coba lagi"<<endl;
        cout<< "Jumlah awal kegiatan Prioritas Sedang :";
        cin>>quota2;
    }

    cout<< "Jumlah awal kegiatan Prioritas Rendah :";
    cin>>quota3;
    while (quota3<0){
        cout<<"Input tidak boleh negative, silahkan coba lagi"<<endl;
        cout<< "Jumlah awal kegiatan Prioritas Rendah :";
        cin>>quota3;
    }

    if (x == 0){
        cout<<"BGP menyantai..."<<endl;
    }else if ((quota1 + quota2 + quota3) == x){
         while (i<x){
            while (quota1>0){
                //cout<<"FIRST";
                adr p;
                infotype x;
                int burst;

                x.job = "keg" + to_string(i+1);
                x.turnAroundTime = 0;
                x.waitingTime = 0;
                cout<<x.job<<",";
                cout<< "burst time : ";
                cin>>burst;
                x.burstTime = burst;
                p = createElement(x);
                enqueue(Q,p);
                quota1--;
                i++;
            }
            while (quota2>0){
                //cout<<"Second";
                adr p;
                infotype x;
                int burst;

                x.job = "keg" + to_string(i+1);
                x.turnAroundTime = 0;
                x.waitingTime = 0;
                cout<<x.job<<",";
                cout<< "burst time : ";
                cin>>burst;
                x.burstTime = burst;
                p = createElement(x);
                enqueue(R,p);
                quota2--;
                i++;
            }
            while (quota3>0){
                //cout<<"Third";
                adr p;
                infotype x;
                int burst;

                x.job = "keg" + to_string(i+1);
                x.turnAroundTime = 0;
                x.waitingTime = 0;
                cout<<x.job<<",";
                cout<< "burst time : ";
                cin>>burst;
                x.burstTime = burst;
                p = createElement(x);
                enqueue(S,p);
                quota3--;
                i++;
            }
        }
    }else{
        cout<<"Jumlah kegiatan kelebihan atau Jumlah awal kegiatan Prioritas Kurang"<<endl;
    }

};

void penjadwalan(Queue &pTinggi,Queue &pSedang,Queue &pRendah,Queue &temp,int Q,int time,int prioUp){
    int jum;
    jum=0;
    while(Head(pTinggi)!= NULL || Head(pSedang)!= NULL|| Head(pRendah)!= NULL){
            cout<<endl;
            cout<<"Round " + to_string(jum)<<endl;
            jum++;
            cout<<"Prioritas Tinggi"<<endl;
            showSemuaQueue(pTinggi);
            cout<<"Prioritas Sedang"<<endl;
            showSemuaQueue(pSedang);
            cout<<"Prioritas Rendah"<<endl;
            showSemuaQueue(pRendah);
            cout<<"Kegiatan yang sudah selesai"<<endl;
            showSemuaQueue(temp);

            if (Head(pTinggi) != NULL){ //ada, any, any
                //cout<<"Test1"<<endl;
                if (info(Head(pTinggi)).burstTime < Q){
                    time += info(Head(pTinggi)).burstTime;
                }else{
                    time += Q;
                }
                do1Round(pTinggi,pSedang,pRendah,Q,temp);
            }else if (Head(pTinggi) == NULL && Head(pRendah)==NULL){//kosong,ada,kosong
                //cout<<"Test2"<<endl;
                if (info(Head(pSedang)).burstTime < Q){
                    time += info(Head(pSedang)).burstTime;
                }else{
                    time += Q;
                }
                do1Round(pSedang,pTinggi,pRendah,Q,temp);
            }else if (Head(pTinggi) == NULL && Head(pSedang)==NULL){//kosong,kosong,ada
                //cout<<"Test3"<<endl;
                if (info(Head(pRendah)).burstTime < Q){
                    time += info(Head(pRendah)).burstTime;
                }else{
                    time += Q;
                }
                do1Round(pRendah,pTinggi,pSedang,Q,temp);
            }else if (Head(pTinggi) == NULL && Head(pSedang) != NULL && Head(pRendah) != NULL){ //kosong,ada,ada
                //cout<<"Test4"<<endl;
                if (info(Head(pSedang)).burstTime < Q){
                    time += info(Head(pSedang)).burstTime;
                }else{
                    time += Q;
                }
                do1Round(pSedang,pTinggi,pRendah,Q,temp);
            }
            if(time >= prioUp){
                while(Head(pSedang)!=NULL){
                    adr z;
                    z = Head(pSedang);
                    dequeue(pSedang,z);
                    enqueue(pTinggi,z);
                }
                while(Head(pRendah)!=NULL){
                    adr z;
                    z = Head(pRendah);
                    dequeue(pRendah,z);
                    enqueue(pSedang,z);
                }
                time -= prioUp;
            }
    }
    cout<<endl;
    cout<<"Round " + to_string(jum)<<endl;
    cout<<"Prioritas Tinggi"<<endl;
    showSemuaQueue(pTinggi);
    cout<<"Prioritas Sedang"<<endl;
    showSemuaQueue(pSedang);
    cout<<"Prioritas Rendah"<<endl;
    showSemuaQueue(pRendah);
    cout<<"Kegiatan yang sudah selesai"<<endl;
    showSemuaQueue(temp);
};
