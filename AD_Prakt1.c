#include <iostream>
#include "Myclasses.h"

using namespace std;
int main() {
 CIRCLE* K1=NULL, *K2=NULL;
 POINT* m1,*m2;
 double xm1,ym1,xm2,ym2
 double r1,r2,anzahl, xA,yA,xB,yB,xC,yC;
 int a;
 bool test1;
 POINT* A,*B,*C;
 POINT** S1,*S2,S3,*S4;
 bool test2;
 double xA2,yA2,xB2,yB2,xC2,yC2,anzahl;
 POINT* A2,B2,*C2,H1,H2,H3,*H4;
 CIRCLE *C1,*C2,*C3,*C4;
POINT *S1,S2,S3,*S4;
LINE L1,L2;

void CIRCLE::show(){
	do{
  cout<<"Mit dieses Programm kann man das fogendes machen:/n"<<endl;
  cout<<" 1. das Erstellen von Zwei Kreisen jeweils durch Eingabe der Mittelpunkt und Radius und auch die Ausgabe der Verhältnis zueinander"<<endl;
  cout<<" 2.Kreise mittels 3 Punkte erstellen und auch die Ausgabe der Verhältnis zueinander /n"<<endl;
  cout<<"Menu /n 1.Kreise Mittels Mittelpunkt und Radius/n 2.Kreise mittels 3 Punkte"<<endl;
  cout<<"für die Funktion 1 geben Sie bitte 1 ein und für die Funktion 2 geben Sie bitte 2 ein falls Sie das Programm beenden möchten giben Site bitte 9: "<<
  cin>>a;

  switch(a) {

    case 1:
    /*1)Zwei beliebige Kreise je mit Mittelpunkt und Radius angeben und zum Schnitt
bringen. Verhältnis der Kreise zu einander angeben und gegebenenfalls Berührpunkt
oder Schnittpunkte anzeigen. */


 cout<<"Mittelpunkt für K1 eingeben :"<<endl;
 cout<<"xm1 : "<<cin>>K1->xm1;
 cout<<"ym1 : "<<cin>>ym1;
 cout<<"Radius des Kreises K1 eingeben:"<<endl;
 cout<<"r1 : "<<cin>>r1;
 POINT m1  = new POINT(xm,ym1);
 CIRCLE K1 = new CIRCLE(m1,r1);

 cout<<"Mittelpunkt für K2 eingeben :"<<endl;
 cout<<"xm2 : "<<cin>>xm2;
 cout<<"ym2 : "<<cin>>ym2;
 cout<<"Radius des Kreises K2 eingeben:"<<endl;
 cout<<"r2 : "<<cin>>r2;
 POINT m2 = new POINT(xm2,ym2);
 CIRCLE K2= new CIRCLE (m2,r2);

 d1 = (K1->getMiddle())->distanceTo(K2->getMiddle());
 cout<<"Die Entfernung zwichen m1 un m2 ist : "<<cin>>d1;
 K1->meetsOther(K2,anzahl,&S1,&S2);
 if (anzahl==0)
 cout<<"die Kreise schneiden sich nicht !"<<endl;
    else if(anzahl=1)
    cout<<"die Kreise berühren sich in S1:"<<&S1<<endl;
        else
        cout<<"die Kreise scheiden sich in : S1"<<&S1<<"und in S2"<<&S2<<endl;
   /*  Zwei Kreise mit Hilfe von jeweils drei beliebigen Punkten konstruieren und zum
Schnitt bringen. Verhältnis der Kreise zu einander angeben und gegebenenfalls
Berührpunkt oder Schnittpunkte anzeigen.

*/
}
case 2:
   cout<<"Erstellen des Kreis 1: "<<endl;
 do{
 do{


 cout<<"x und y für den Punkt A eingeben :"<<endl;
 cout<<"xA : "<<cin>>xA;
 cout<<"yA : "<<cin>>yA;
 A=new POINT(xA,yA);

 cout<<"x und y für den Punkt B eingeben :"<<endl;
 cout<<"xB : "<<cin>>xB;
 cout<<"yB : "<<cin>>yB;
 B=new POINT(xB,yB);

 cout<<"x und y für den Punkt C eingeben :"<<endl;
 cout<<"xC : "<<cin>>xC;
 cout<<"yA : "<<cin>>yC;
 C=new POINT(xC,yC);
 test=equal(POINT->A,POINT->B)||equal(POINT->A,POINT->C)||equal(POINT->C,POINT->B);
 cout<<"die Punkte sollen nicht gleich sein !"<<endl;
 }while(test1==true);

 CIRCLE C1=new CIRCLE (A,A->distanceTo(B));
 CIRCLE C2=(B,B->distanceTo(A));
 CIRCLE C3=(C,C->distanceTo(B));
 CIRCLE C4=(B,B->distanceTo(C));
 C1->meetsOther(C2,anzahl,&S1,&S2);
 cout<<"die Kreise scheiden sich in : S1"<<&S1<<"und in S2"<<&S2<<endl;
 C3->meetsOther(C4,anzahl,&S3,&S4);
 cout<<"die Kreise scheiden sich in : S3"<<&S3<<"und in S4"<<&S4 <<endl;

 LINE L1=new LINE(S1,S2);
 LINE L2=new LINE(S3,S4);
}while(L1->parallelTo(L2));
POINT* Mc=L1->meets(L2);
double Rc=Mc->distanceTo(A);
CIRCLE C=new(Mc,Rc);
cout<<"Der Mittelpunkt des Kreises C ist: "<<cin>>Mc<<endl;
cout<<"Das Radius des Kreises C ist :  "<<cin>>Rc<<endl;

cout<<"Erstellen des Kreises 2:"<<endl;

do{
 do{


 cout<<"x und y für den Punkt A2 eingeben :"<<endl;
 cout<<"xA2 : "<<cin>>xA2;
 cout<<"yA2 : "<<cin>>yA2;
 A2=new POINT(xA2,yA2);

 cout<<"x und y für den Punkt B2 eingeben :"<<endl;
 cout<<"xB : "<<cin>>xB2;
 cout<<"yB : "<<cin>>yB2;
 B2=new POINT(xB2,yB2);

 cout<<"x und y für den Punkt C2 eingeben :"<<endl;
 cout<<"xC2 : "<<cin>>xC2;
 cout<<"yC2 : "<<cin>>yC2;
 C2=new POINT(xC2,yC2);
 test2=equal(POINT->A2,POINT->B2)||equal(POINT->A2,POINT->C2)||equal(POINT->C2,POINT->B2);
 cout<<"die Punkte sollen nicht gleich sein !"<<endl;
 }while(test2==true);
  CIRCLE *Ci1,*Ci2,*Ci3,*Ci4;
  POINT** H1,*H2,H3,*H4;
 CIRCLE Ci1=new CIRCLE (A2,A2->distanceTo(B2));
 CIRCLE Ci2=(B2,B2->distanceTo(A2));
 CIRCLE Ci3=(C2,C2->distanceTo(B2));
 CIRCLE Ci4=(B2,B2->distanceTo(C2));
 Ci1->meetsOther(Ci2,anzahl,&H1,&H2);
 cout<<"die Kreise scheiden sich in : H1 "<<&H1<<"und in H2"<<&H2<<endl;
 C3->meetsOther(C4,anzahl,&H3,&H4);
 cout<<"die Kreise scheiden sich in : H3 "<<&H3<<"und in H4"<<&H4<<endl;
 LINE G1,G2;
 LINE G1=new LINE(G1,G2);
 LINE G2=new LINE(G3,G4);
}while(G1->parallelTo(G2));
POINT* Mci=G1->meets(G2);
double Rci=Mc->distanceTo(A2);
CIRCLE Ci=new(Mci,Rci);
cout<<"Der Mittelpunkt des Kreises Ci ist: "<<cin>>Mci<<endl;
cout<<"Das Radius des Kreises Ci ist :  "<<cin>>Rci<<endl;

double d2;
d2 = (C->getMiddle())->distanceTo(Ci->getMiddle());
 cout<<"Die Entfernung zwichen  die Mittelpukte ist : "<<cin>>d2<<endl;
C->meetsOther(Ci,anzahl,&Sa,&Sb);
 if (anzahl==0)
 cout<<"die Kreise schneiden sich nicht !"<<endl;
    else if(anzahl=1)
    cout<<"die Kreise berühren sich in Sa : ("<<&Sa<<endl;
        else
        cout<<"die Kreise scheiden sich in : Sa "<<&Sa<<"und in Sb"<<%Sb<<endl;

}
case 9:

    cout<<"      ENDE      "<<endl;
	break;
}
