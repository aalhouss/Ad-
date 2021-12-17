#include <iostream>
#include "queue2.h"
#include "Evkd2.h"
#include <string.h>
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
using namespace std;
int main() {
EVKD *K1=NULL;
QUEUE *obj=nullptr;

int anz,p,a,laenge,antw;
antw=1;
//char* Daten[100];
char wort[100];
char wort1[100];
obj=new QUEUE();

while(antw==1){
  cout<<"Mit dieses Programm kann man das fogendes machen:"<<endl;
  cout<<" 1. Warteschlange erstellen"<<endl;
  cout<<" 2. Verketete Liste Anzeigen "<<endl;
  cout<<" 3. Neues Element an Warteschlange einfuegen"<<endl;
  cout<<" 4. Element aus der Warteschlange entfernen "<<endl;
  cout<<" 5. Liste sortieren "<<endl;
  cout<<" 12. Ende"<<endl;
  cout<<"bitte die werte von a eingeben, sodass von der Menu waehlen koennen"<<endl;
  cin>>a;
  //switch(a) {

  	//case 1: // Warteschlange erstellen
  	  if(a==1)  {


char *Daten[]={(char*)"Schmitz, Josef",(char*)"Mueller, Josi",(char*)"Schmitz, Anna",
 (char*)"Mueller, Josef",(char*)"Schmitz, Josi",(char*)"Mueller, Anna",
 (char*)"Meier, Josef",(char*)"Zacher, Josi",(char*)"Anker, Anna"};
  laenge=sizeof(Daten)/sizeof(char*);
  for(int i=0;i<laenge;i++){
    obj->queueIn(Daten[i]);

  }

  	    }
else if(a==2)
{

    obj->zeigDich();

    }

else if(a==3)
{

char *x;
 cout<<"geben Sie ein Element die Sie zur Liste einfügen wollen  :"<<endl;
 cout<<"Name : "<<endl;
 cin>>wort;
cout<<"Vorname : "<<endl;
cin>>wort1;
x=strcat(wort,", ");
x=strcat(x,wort1);
  obj->queueIn(x);

}

   else if(a==4)
{
    if(obj->queueOut()==nullptr)
        cout<<" Liste leer"<<endl;
            else
 cout<<obj->queueOut()<<endl;


}


else if(a==5)
{
obj->iSort();
}

   else if(a==12)
{


   cout<<"      ENDE      "<<endl;
	 break;
}

else {
    cout<<"was sie eingegben haben , ist kein methode"<<endl;
}
  //}
   cout << "weiter berechnen? falls ja bitte 1 eingeben, ansonst wird das Programm aufgehoert" << endl;
    cin >> antw;
    if (antw == 1) {
      antw=1;
    } else {
      cout << "Aufwiedersehen ! " << endl;
      break;
    }
}
}
