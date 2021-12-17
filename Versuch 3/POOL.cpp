//#pragma once
#include "POOL.h"
#include "GEOKO.h"
#include <cmath>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include<string>
#include <sstream>
#include <chrono>
#include<ctime>
//using namespace std;

/*
AD-Praktikum SoSe 2021
Gruppe:11
Name, Vorname, Mat.-Nr.:Al Housseini, Ahmad , 11145964
Name, Vorname, Mat.-Nr. des Praktikumsparners: Al Khattabi, Fatima,11145655
Abgabe am:21/06/2021
Praktikumsblatt:2
Compiler Flags:gcc.exe
Linker libraries/options:
*/



POOL::POOL(long  Maximal)
{
    Max = Maximal;
    Index = new GEOKO * [Maximal];
    Anz = 0;
    Root = nullptr;
    Mitte = nullptr;
}
TE* POOL::getRoot() {
    return Root;
}
long POOL::getAnz() {
    return this->Anz;
}
long POOL::getMax() {
    return this->Max;
}
void POOL::setRoot(TE* a) {
    this->Root = a;
}
void POOL::setMitte(GEOKO* b) {
    this->Mitte = b;
}
void POOL::setMax(long c) {
    this->Max = c;
}
void POOL::setAnz(long d) {
    this->Anz = d;
}

bool POOL::pruefeBaum() {
   long h = (log(this->Anz + 1) / log(2)) - 1;
    for (long i = 0; i < h; i++) {
        for (long j = 0; j < pow(2, i); j++) {
            if ((j * 2 + 1) > Anz) { break; }
            TE* l1 = Index[j]->getL();
            TE* l2 = Index[j * 2 + 1];
            TE* lp1 = Index[j];
            TE* lp2 = Index[j * 2 + 1]->getP();
            if (l1 != l2||lp1!=lp2) { return false; }

            if ((j * 2 + 2) < Anz) { break; }
            TE* r1 = Index[j]->getR();
            TE* r2 = Index[j * 2 + 2];
            TE* rp1 = Index[j];
            TE* rp2 = Index[j * 2 + 2]->getP();
            if (r1 != r2||rp1!=rp2) { return false; }

        }


    }

}
void POOL::Abstandberechnen(long i) {
    double erg;
    double b = ((Index[i]->getbreite()) - (Mitte->getbreite()));
    double a= ((Index[i]->getlange())-( Mitte->getlange()));
    a = pow(a, 2);
    b = pow(b, 2);
    erg = sqrt(a + b);
    Index[i]->setAbstand(erg);

}


bool POOL::addElement(GEOKO* d) {
    long x;
    if (Anz == Max) { return false; }
    else {
        Index[Anz] = d;
        if (Anz == 0) {
            Root = d;
            Mitte = new GEOKO(0, 0);
        }
        else {
            x = (Anz + 1) / 2;
            if (Index[x - 1]->getL() == nullptr)
                Index[x - 1]->setL(Index[Anz]);
            else {
                Index[x - 1]->setR(Index[Anz]);
                Index[Anz]->setP(Index[x - 1]);
                Index[Anz-1]->setP(Index[x - 1]);
            }


        }

        Mitte->setbreite((Mitte->getbreite()*Anz + d->getbreite()) / (Anz+1));
        Mitte->setlange((Mitte->getlange()*Anz + d->getlange()) / (Anz+1));
        Anz++;
        return true;

    }





}
void POOL::versinke(long Anz,int i) {
    while (i <= Anz / 2) {
        int LN = i * 2;
        if (LN < Anz) {
        if (*Index[LN] > *Index[LN - 1])
            LN++;
        }
        if (*Index[LN - 1] > *Index[i - 1]) {
            vertausche(i - 1, LN - 1);
            i = LN;
        }
        else i = Anz;
    }
}
void POOL::erzeugeHeap() {
    int N = (Anz / 2);
    for (int i = N; i >= 1; i--)
        versinke(Anz, i);
}
void POOL::heapSort() {
   for (int i = 0; i < Anz; i++) {
        Abstandberechnen(i);
    } // Die Zeitmessung +++++++++++++++++++++++++++++++++++++++++++++++
    using namespace std::chrono;
    std::chrono::time_point<std::chrono::system_clock> start, ende;
    start = std::chrono::system_clock::now();
    erzeugeHeap();
    for (int i = Anz; i > 1; i--) {
        vertausche(0, i - 1);
        versinke(i - 1, 1);
    }

    ende = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = (ende - start)*1000000;
    std::time_t end_time = std::chrono::system_clock::to_time_t(ende);

    std::cout << "finished computation at " << std::ctime(&end_time)
        << "die benötigte Zeit für das Verfahren ist : " << elapsed_seconds.count() << " mikrosec \n";
    //Die Zeitmessung +++++++++++++++++++++++++++++++++++++++++++++++++++
    fixtree();
}
void POOL::vertausche(int Von, int Nach) {
    GEOKO* Tmp = Index[Von];
    Index[Von] = Index[Nach];
    Index[Nach] = Tmp;
}


void POOL::Mitteberechnung() {
    double lm = 0;
    double bm = 0;
    for (int i = 0; i <Anz; i++) {
        lm =( Index[i]->getlange()) + lm;
        bm = (Index[i]->getbreite()) + bm;
    }
    Mitte->setlange(lm/Anz);
    Mitte->setbreite(bm/Anz);

}
double POOL::getMitte_lange() {
    return Mitte->getlange();
}
double POOL::getMitte_breite() {
    return Mitte->getbreite();
}
string POOL::get_kooordinaten(long i) {

    ostringstream s;
    s << setprecision(10) <<Index[i]->getlange() << "," << setprecision(10) <<Index[i]->getbreite() << "," << setprecision(10) <<Index[i]->getAbstand() << endl;
    return s.str();
}
void POOL::fixtree() {
    long x;
    Root = Index[0];
    Index[0]->setP(nullptr);
    for (long i = 0; i <= Anz / 2; i++) {
        x = i * 2 + 1;
        if (x ==Anz) break;
        Index[i]->setL(Index[x]);
        if (x + 1 == Anz) break;

        Index[i]->setR(Index[x + 1]);
        Index[x]->setP(Index[i]);
        Index[x + 1]->setP(Index[i]);
    }
}



void POOL::inSort()
{
    for (long i = 0; i < Anz; i++) {
        Abstandberechnen(i);
    }

    long i, j;
    GEOKO* key;
    //Die Zeitmessung********************************
    using namespace std::chrono;
    std::chrono::time_point<std::chrono::system_clock> start, ende;
    start = std::chrono::system_clock::now();

        for (i = 1; i < Anz; i++)
        {
            key = Index[i];
            j = i - 1;


            while (j >= 0 && *Index[j] > *key)
            {
                Index[j + 1] = Index[j];
                j = j - 1;

            }
            Index[j + 1] = key;
        }
        ende = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = (ende - start)*1000000;
        std::time_t end_time = std::chrono::system_clock::to_time_t(ende);

        std::cout << "finished computation at " << std::ctime(&end_time)
            << "die benötigte Zeit für das Verfahren ist : " << elapsed_seconds.count() << " microsec \n";
        //Die Zeitmessung *************************************+
        fixtree();

    }



