#ifndef QUEUE2_H_INCLUDED
#define QUEUE2_H_INCLUDED
#include "Evkd2.h"
class QUEUE {
private:
    EVKD *Enter;
    int Anz;
public:
    QUEUE();
     ~QUEUE();
    void queueIn (char *);
    EVKD* getEnter();
    char* queueOut ();
    void einfuegeSortiert (EVKD *In, int Max );
    EVKD * loesche(int );
    void iSort();
    void zeigDich();
};

#endif // QUEUE2_H_INCLUDED
