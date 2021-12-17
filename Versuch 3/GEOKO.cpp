#include "GEOKO.h"
#include"TE.h"


 GEOKO::GEOKO(double b, double l) :TE(nullptr, nullptr, nullptr) {
     this->setbreite(l);
    this->setlange(b);
    this->setBrGr((int)breite % 3600);
    this->setLaGr((int)lange % 3600);
    this->setBrMin((int)(breite - getBrGr()) % 60);
    this->setLaMin((int)(lange - getLaMin()) % 60);
    this->setBrSec(breite - getBrGr() - getBrMin());
    this->setLaSec(lange - getLaGr() - getLaMin());
    Abstand = 0;
}
void GEOKO::setBrGr(int a) {
    this->BrGr = a;
}
void GEOKO::setLaGr(int b) {
    this->LaGr = b;
}
 void GEOKO::setBrMin(int c) {
    this->BrMin = c;
}
 void GEOKO::setLaMin(int d) {
    this->LaMin = d;
}
void GEOKO::setBrSec(double e) {
    this->BrSec = e;
}
 void GEOKO::setLaSec(double f) {
    this->LaSec = f;
}
 void GEOKO::setAbstand(double abs) {
    this->Abstand = abs;
}
 void GEOKO::setlange(double l) {
     this->lange = l;
 }
 void GEOKO::setbreite(double b) {
     this->breite = b;
 }
 double GEOKO::getlange() {
     return this->lange;
 }
 double GEOKO::getbreite() {
     return this->breite;
 }
 int GEOKO::getBrGr() {
    return this->BrGr;
}
 int GEOKO::getLaGr() {
    return this->LaGr;
}
 int GEOKO::getBrMin() {
    return this->BrMin;
}
int GEOKO::getLaMin() {
    return this->LaMin;
}
  double GEOKO::getBrSec() {
    return this->BrSec;
}
 double GEOKO::getLaSec() {
    return this->LaSec;
}
double GEOKO::getAbstand() {
    return this->Abstand;
}

 bool  GEOKO::operator == (GEOKO& a) {
    //a.Abstandberechenen(a);
    return (this->Abstand == a.Abstand);
}
 bool  GEOKO::operator > (GEOKO& b) {
    //b.Abstandberechenen(b);
    return (Abstand > b.Abstand);
}




