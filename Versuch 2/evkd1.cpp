#include "Evkd2.h"
#include <iostream>
#include <string.h>
using namespace std;

inline EVKD::EVKD(char *LPSZDaten, EVKD* N){
  Anz=strlen(LPSZDaten);
  Daten=new char[Anz];
  //this->Daten=LPSZDaten;
  for(int i=0;i<Anz;i++)
    Daten[i]=LPSZDaten[i];
  this->Next=N;

	}
inline char* EVKD::getDaten(){
 char *daten=new char[Anz+1];
 //for(int i=0;i<Anz;i++)
    //*(daten+i)=*(this->Daten+i);
    strcpy(daten,Daten);
 daten[Anz]='\0';
 return daten;
}

inline int EVKD::getAnz(){
	return this->Anz;
}
inline void EVKD::setNext(EVKD *E1){
	this->Next=E1;
}

inline EVKD *EVKD::getNext(){
	return Next;
}

inline bool  EVKD::operator == (  EVKD &evkd){
 /*if(this->getDaten()==evkd.getDaten() && this->getAnz()==evkd.getAnz())
    return 1;
 return 0;*/
 int tmp;
 tmp=strcmp(getDaten(),evkd.getDaten());
 if(tmp==0)
    return true;
 return false;
}



inline bool  EVKD::operator
>  ( EVKD &evkd){
 /*EVKD* Ek;
 Ek=new EVKD(Ek->getDaten(),Ek->getAnz());
 (this->Ek)>(EVKD.evkd);
 return 0;
 */
 int tmp;
 tmp=strcmp(getDaten(),evkd.getDaten());
 if(tmp>0)
    return true;
 return false;
}

inline EVKD::~EVKD(){
    delete[] Daten;
}



