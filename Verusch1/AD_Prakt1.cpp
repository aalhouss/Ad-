#include <iostream>

#include "Myclasses.h"

/*
AD-Praktikum SoSe 2021
Gruppe:11
Name, Vorname, Mat.-Nr.:Al Housseini, Ahmad , 11145964
Name, Vorname, Mat.-Nr. des Praktikumsparners: Al Khattabi, Fatima,11145655
Abgabe am:27/05/2021
Praktikumsblatt:1
Compiler Flags:gcc.exe
Linker libraries/options:
*/
using namespace std;
int main() {
  CIRCLE * K1 = NULL, * K2 = NULL;
  POINT * m1, * m2;
  double xm1, ym1, xm2, ym2, d2;
  double r1, r2, xA, yA, xB, yB, xC, yC;
  int a, anzahl, anzahl1, anzahl2, anzahl3, anzahl4, anzahl5, answer = 1;
  bool test1;
  POINT * A, * B, * C;
  POINT * S1, * S2, * S3, * S4, * Sa, * Sb;
  bool test2;
  double xA2, yA2, xB2, yB2, xD2, yD2;
  POINT * A2, * B2, * D2;
  CIRCLE * C1, * C2, * C3, * C4;
  //POINT *S1,S2,S3,*S4;
  LINE * L1, * L2;
  CIRCLE * Ci1, * Ci2, * Ci3, * Ci4, * Kr1, * Kr2;
  POINT * H1, * H2, * H3, * H4;
  LINE * G1, * G2;

  //void CIRCLE::show(){
  while (answer == 1) {
    cout << "Mit dieses Programm kann man das fogendes machen:" << endl;
    cout << " 1. zwei kreise mit 2 Punkte und Radien " << endl;
    cout << " 2.Kreise mittels mit 3 Punkte  " << endl;
    cout << " 9. beenden " << endl;

    cin >> a;

    if (a == 1)

    {

      /*1)Zwei beliebige Kreise je mit Mittelpunkt und Radius angeben und zum Schnitt
bringen. Verhältnis der Kreise zu einander angeben und gegebenenfalls Berührpunkt
oder Schnittpunkte anzeigen. */

      cout << "Mittelpunkt für K1 eingeben :" << endl;
      cin >> xm1 >> ym1;
      cout << "Radius des Kreises K1 eingeben:" << endl;
      cin >> r1;
      POINT * m1 = new POINT(xm1, ym1);
      CIRCLE * K1 = new CIRCLE(m1, r1);

      cout << "Mittelpunkt für K2 eingeben :" << endl;
      cin >> xm2 >> ym2;
      cout << "Radius des Kreises K2 eingeben:" << endl;
      cin >> r2;
      POINT * m2 = new POINT(xm2, ym2);
      CIRCLE * K2 = new CIRCLE(m2, r2);

      double d1 = (K1 -> getMiddle()) -> distanceTo( * K2 -> getMiddle());
      cout << "Die Entfernung zwichen m1 un m2 ist : " << d1 << endl;

      K1 -> meetsOther(K2, anzahl, & S1, & S2);
      if (anzahl == 0)
        cout << "die Kreise schneiden sich nicht !" << endl;
      else if (anzahl == 1) {
        cout << "die Kreise beruehren sich in S1:" << endl;
        S1 -> show();
      } else
        cout << "die Kreise scheiden sich in : S1 und in S2" << endl;
      S1 -> show();
      S2 -> show();
      /*  Zwei Kreise mit Hilfe von jeweils drei beliebigen Punkten konstruieren und zum
Schnitt bringen. Verhältnis der Kreise zu einander angeben und gegebenenfalls
Berührpunkt oder Schnittpunkte anzeigen.

*/

    } else if (a == 2) {

      cout << "Erstellen des Kreis 1: " << endl;

      //do{
      do {

        cout << "x und y für den Punkt A eingeben :" << endl;
        cin >> xA >> yA;
        A = new POINT(xA, yA);

        cout << "x und y für den Punkt B eingeben :" << endl;
        cin >> xB >> yB;
        B = new POINT(xB, yB);

        cout << "x und y für den Punkt C eingeben :" << endl;
        cin >> xC >> yC;
        C = new POINT(xC, yC);

        test1 = (A -> distanceTo( * B) < Epsilon || A -> distanceTo( * C) < Epsilon || B -> distanceTo( * C) < Epsilon);
        //test1=A->equalto(B)||A->equal(C)||B->equal(C);
        if (test1 == true)
          cout << "die Punkte sollen nicht gleich sein !" << endl;
      } while (test1 == true);

      C1 = new CIRCLE(A, A -> distanceTo( * B));
      C2 = new CIRCLE(B, B -> distanceTo( * A));
      C3 = new CIRCLE(C, C -> distanceTo( * B));
      C4 = new CIRCLE(B, B -> distanceTo( * C));

      C1 -> meetsOther(C2, anzahl1, & S1, & S2);
      cout << "die Kreise C1 und C2 scheiden sich in : S1 und in S2" << endl;
      S1 -> show();
      S2 -> show();
      C3 -> meetsOther(C4, anzahl2, & S3, & S4);
      cout << "die Kreise C3 und C4 scheiden sich in : S3 und in S4" << endl;
       delete C1;
       delete C2;
       delete C3;
       delete C4;
      S3 -> show();
      S4 -> show();
       //delete S3;
       //delete S4;

      LINE * L1 = new LINE(S1, S2);
      LINE * L2 = new LINE(S3, S4);

      POINT * Ps = L1 -> meets(L2);
       //Ps->show();
      //}while(L1->parallelTo(L2));

      POINT * Mc = L1 -> meets(L2);
      delete S1;
      delete S2;
      delete S3;
      delete S4;
      delete L1;
      delete L2;
      double Rc = Mc -> distanceTo( * A);
      CIRCLE * Kr1 = new CIRCLE(Mc, Rc);
      cout << "Der Mittelpunkt des Kreises Kr1 ist: " << endl;
      Mc -> show();
      //delete Mc;
      cout << "Das Radius des Kreises Kr1 ist :  " << Rc << endl;

      cout << "Erstellen des Kreises 2:" << endl;

      do {
        //do{

        cout << "x und y für den Punkt A2 eingeben :" << endl;
        cin >> xA2 >> yA2;
        A2 = new POINT(xA2, yA2);

        cout << "x und y für den Punkt B2 eingeben :" << endl;
        cin >> xB2 >> yB2;
        B2 = new POINT(xB2, yB2);

        cout << "x und y für den Punkt D2 eingeben :" << endl;
        cin >> xD2 >> yD2;
        D2 = new POINT(xD2, yD2);

        test2 = (A2 -> distanceTo( * B2) < Epsilon || A2 -> distanceTo( * D2) < Epsilon || B2 -> distanceTo( * D2) < Epsilon);
        if (test2 == true)
          cout << "die Punkte sollen nicht gleich sein !" << endl;
      } while (test2 == true);

      Ci1 = new CIRCLE(A2, A2 -> distanceTo( * B2));
      Ci2 = new CIRCLE(B2, B2 -> distanceTo( * A2));
      Ci3 = new CIRCLE(D2, D2 -> distanceTo( * B2));
      Ci4 = new CIRCLE(B2, B2 -> distanceTo( * D2));

      Ci1 -> meetsOther(Ci2, anzahl3, & H1, & H2);
      cout << "die Kreise Ci1 und Ci2 scheiden sich in : H1 und in H2" << endl;
      H1 -> show();
      H2 -> show();
      Ci3 -> meetsOther(Ci4, anzahl4, & H3, & H4);
      cout << "die Kreise Ci3 und Ci4 scheiden sich in : H3 und in H4" << endl;
      H3 -> show();
      H4 -> show();
      G1 = new LINE(H1, H2);
      G2 = new LINE(H3, H4);

       delete Ci1;
       delete Ci2;
       delete Ci3;
       delete Ci4;

      POINT * Me = G1 -> meets(G2);
      //}while(G1->parallelTo(G2));

      POINT * Mci = G1 -> meets(G2);
       delete G1;
       delete G2;

      double Rci = Mc -> distanceTo( * A2);
      Kr2 = new CIRCLE(Mci, Rci);
      delete Kr2;
      cout << "Der Mittelpunkt des Kreises Kr2 ist: " << endl;
      Mci -> show();
      delete Mci;
      cout << "Das Radius des Kreises Kr2 ist :  " << Rci << endl;

      d2 = (Kr1 -> getMiddle()) -> distanceTo( * Kr2 -> getMiddle());
      cout << "Die Entfernung zwichen  die Mittelpukte ist : " << d2 << endl;

      Kr1 -> meetsOther(Kr2, anzahl5, & Sa, & Sb);
      if (anzahl5 == 0)
        cout << "die Kreise Kr1 und Kr2 schneiden sich nicht !" << endl;
      else if (anzahl5 == 1) {
        cout << "die Kreise Kr1 und Kr2 berühren sich in Sa : (" << & Sa << endl;
        Sa -> show();
      } else {
        cout << "die Kreise Kr1 und Kr2scheiden sich in : Sa und in Sb" << endl;
        Sa -> show();
        Sb -> show();
        delete Sa;
        delete Sb;
      }
    } else  {

      cout << "      ENDE      " << endl;
      break;
    }

    cout << "weiter berechnen? falls ja bitte 1 eingeben, ansonst wird das Programm aufgehoert" << endl;
    cin >> answer;
    if (answer == 1) {
      answer=1;
    } else {
      cout << "Aufwiedersehen ! " << endl;
      break;
    }
  }
}
