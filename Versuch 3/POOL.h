
#ifndef POOL_H_INCLUDED
#define POOL_H_INCLUDED
#include "GEOKO.h"
#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
using namespace std;

class POOL {
private:
    TE* Root;
    GEOKO* Mitte;
    long Max;
    long Anz;
    GEOKO** Index;

public:
    POOL(long);
    TE* getRoot();
    void Mitteberechnung();
    long getAnz();
    long getMax();
    void setRoot(TE*);
    void setMitte(GEOKO*);
    void setMax(long);
    void setAnz(long);
    void Abstandberechnen(long);
    bool addElement(GEOKO*);
    bool pruefeBaum();
    void insertionsort();
    void erzeugeHeap();
    void heapSort();
    void loesche(int);
    void versinke(long,int );
    void vertausche(int, int);
    void inSort();
    void inSort_aufruf();
    double getMitte_lange();
    double getMitte_breite();
    string get_kooordinaten(long);
    void fixtree();
};

#endif // POOL_H_INCLUDED



