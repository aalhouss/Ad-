#include "queue2.h"
#include "evkd1.cpp"
#include <cstddef>
#include <iostream>
using namespace std;


EVKD *QUEUE::getEnter(){
	return Enter;
};

QUEUE::QUEUE(){
 this->Enter=NULL;
 this->Anz=0;
};
void QUEUE::queueIn (char *InText){
        EVKD* newEvkd=new EVKD(InText,nullptr);
   EVKD *tmp = Enter;
   this->Anz++;
	if ( tmp != NULL ) {
		// Elemente bereits in der Liste vorhanden
		// Gehe zum Ende der Liste
		while ( tmp->getNext() != NULL ) {
			tmp = tmp->getNext();

		}

		// Zeiger vom letzten Listenelement aufs neue setzen
		tmp->setNext(newEvkd);
	}
	else {
		// Erstes Element in der Liste
		Enter = newEvkd;
	}
}
char* QUEUE::queueOut (){
if(this->Anz==0)
    return nullptr;
char* data=this->Enter->getDaten();
EVKD *x=this->Enter->getNext();
delete Enter;
Enter=x;
(this->Anz)--;
return data;

}
EVKD* QUEUE::loesche(int Pos){

 EVKD* tmp,*tmp1;

tmp=Enter;
tmp1=nullptr;
/*if(Pos==1){
    Enter=Enter->getNext();
    return tmp;
}*/
 //if(Pos>Anz){ return nullptr;
 for(int i=1;i<Pos;i++){
    tmp1=tmp;
    tmp=tmp->getNext();
 }
 tmp1->setNext(tmp->getNext());
 //std::cout<<"tmp"<<tmp->getDaten()<<endl;
 return tmp;

}



 void QUEUE::einfuegeSortiert (EVKD *In, int Max ){

  EVKD* tmp=this->Enter;
  EVKD* letzte =nullptr;
  if(*Enter>*In){
    In->setNext(Enter);
    Enter=In;
  }
  else {


 for(int i=0;i<Max;i++){
 	if((*In>*tmp)||(*In==*tmp))
        {
	letzte=tmp;
	tmp=tmp->getNext();
	// break;
 	 }
 	 else{
 	 break;
 	 }
 }

 	In->setNext(tmp);
    letzte->setNext(In);
  }
 	}



void QUEUE::iSort(){

for(int i=2;i<=Anz;i++){
    EVKD *abc=this->loesche(i);
    this->einfuegeSortiert(abc,i-1);
}

}

QUEUE::~QUEUE(){

}


void QUEUE::zeigDich() {
	// Temp pointer
	EVKD *tmp = Enter;

	// Kein Element
	if ( tmp == NULL ) {
		cout << "LEER" << endl;
		return;
	}

	else {
		// iteriere durch die Liste und gebe sie aus
		do {
			cout << tmp->getDaten()<<" ( "<<tmp<<"|"<<"Next addresse "<<tmp->getNext()<<" )"<<endl;
			//cout << " --> ";
		//	cout<<" ( "<<tmp<<"|"<<
			tmp = tmp->getNext();
		}
		while ( tmp != NULL );

		cout << "NULL" << endl;
	}
}
