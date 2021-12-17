#ifndef EVKD2_H_INCLUDED
#define EVKD2_H_INCLUDED
using namespace std;

class EVKD{
protected:
    char *Daten;
    int Anz;
    EVKD *Next;
public:
    //char *LPSZDaten;
    EVKD();
    ~EVKD();
    EVKD(char * LPSZDaten,EVKD * N);
    char *getDaten();
    void setNext(EVKD*);
    int getAnz();
    EVKD *getNext();
   bool  operator == ( EVKD &);
    bool  operator > ( EVKD &);
    //int strcmp(char * S1, char * S2)
};


#endif // EVKD2_H_INCLUDED
