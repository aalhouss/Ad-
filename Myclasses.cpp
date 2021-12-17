#include "Myclasses.h"

#include <Math.h>

#include <iostream>

/* Dateiname: Myclasses.cpp:

Programmkopf mit Programmname, Autor(en)...
Beschreibung, usw.
Enthält den Code der Methoden der Klassen POINT, LINE und CIRCLE
::
*/
using namespace std;
void POINT::setX(double X) {
  this -> X = X;
}
void POINT::setY(double Y) {
  this -> Y = Y;
}
POINT::POINT() {};
POINT::POINT(double X, double Y) {
  this -> X = X;
  this -> Y = Y;
}
double POINT::getX() {
  return this -> X;
}
double POINT::getY() {
  return this -> Y;
}
POINT::POINT(POINT & point) { //Copy-Konstruktor P2=new Point(P2)
  this -> X = point.X;
  this -> Y = point.Y;
}
double POINT::distanceTo(const POINT & P) {
  double Diff_X, Diff_Y;
  Diff_X = getX() - P.X;
  Diff_Y = getY() - P.Y;
  return sqrt(Diff_X * Diff_X + Diff_Y * Diff_Y);
}

POINT & POINT::operator + (const POINT & a) {
  POINT * erg;
  erg = new POINT((this -> X + a.X), (this -> Y + a.Y));
  return *erg;
}
POINT & POINT::operator - (const POINT & b) {
  // Überladener Subtraktionsoperator
  POINT * erg;
  erg = new POINT((this -> X - b.X), (this -> Y + b.Y));
  return *erg;
}
POINT & POINT::operator * (double c) { // Überladener Multiplikationsoperator, POINT * Skalar
  POINT * erg;
  erg = new POINT(((this -> X) * c), ((this -> Y) * c));
  return *erg;
}

void POINT::show() {
  cout << "( " << getX() << " | " << getY() << " )" << endl;
}; // Ausgabe der Koordinaten in der Form ( x | y )
POINT::~POINT() {}; // Virtueller Destruktor, wird automatisch aufgerufen durch die Destruktoren von LINE und CIRCLE

LINE::LINE(POINT * P1, POINT * P2): POINT( * P1) {
  this -> P2 = new POINT( * P2);
  this -> A = (P1 -> getY()) - (P2 -> getY());
  this -> B = (P1 -> getX()) - (P2 -> getX());
  this -> C = (P1 -> getX()) * (P2 -> getY()) - (P2 -> getX()) * (P1 -> getY());
  normalize();
};

void LINE::normalize(void) {
  double NormA, NormB, NormC;
  if (A * A + B * B != 0) {
    NormA = (this -> A) / sqrt(A * A + B * B);
    NormB = (this -> B) / sqrt(A * A + B * B);
    NormC = (this -> C) / sqrt(A * A + B * B);
    cout << "Die Normaliesierung von A ist" << NormA << endl;
    cout << "Die Normaliesierung von B ist" << NormB << endl;
    cout << "Die Normaliesierung von C ist" << NormC << endl;
  }
};
POINT * LINE::meets(const LINE * L) { //Schnittpunkt für zwei Geraden
  double Xs, Ys;
  POINT * Ps = new POINT(Xs, Ys);
  Xs = ((L -> B) * (this -> C) - (L -> C) * (this -> B)) / ((L -> A) * (this -> B) - (this -> A) * (L -> B));
  Ys = ((L -> C) * (this -> A) - (L -> A) * (this -> C)) / ((L -> A) * (this -> B) - (this -> A) * (L -> B));
  return Ps;
};
bool LINE::parallelTo(const LINE * L) { //Feststellen, ob zwei Geraden parallel sind
  return abs((L -> A) * (this -> B) - (this -> A) * (L -> B)) < Epsilon;
};
void LINE::show() {
  std::cout << "(" << getX() << "|" << getY() << ", (" << P2 -> getX() << "|" << P2 -> getY() << ")" << endl;
}

CIRCLE::CIRCLE(POINT * M, double R): POINT( * M) { //Initialisierungskonstruktor 1
  this -> Radius = R;
};
CIRCLE::CIRCLE(POINT * N, POINT * F, POINT * G): POINT( * N) {
  F = new POINT( * F);
  G = new POINT( * G);
};
POINT * CIRCLE::getMiddle() {
  POINT * M = new POINT(this -> getX(), this -> getY());
  return M;
}
double CIRCLE::skPro(POINT & Poin, POINT & Poin1) {
  double ERG;
  ERG = Poin.getX() * Poin1.getX() + Poin.getY() * Poin1.getY();
  return ERG;
};
double CIRCLE::getR() {
  return this -> Radius;
}
void CIRCLE::show() {
  std::cout << "Mittelpunkt :" << getMiddle() << " Radius: " << getR() << endl;
}
bool CIRCLE::isInCircle(const POINT & p) {
  double D = distanceTo(p);
  if (D <= getR()) return true;
  return false;
}
/* http://walter.bislins.ch/blog/index.asp?page=Schnittpunkte+zweier+Kreise+berechnen+%28JavaScript%29
Link für die methode , die wir für meetsother benutzt haben
*/
void CIRCLE::meetsOther(CIRCLE * C, int & Anzahl, POINT ** S1, POINT ** S2) {
  double d, a, dx, dy, h, x1, y1, x2, y2;
  d = this -> distanceTo( * (C -> getMiddle()));
  a = ((C -> Radius * C -> Radius) - (Radius * Radius) + (d * d)) / (2.0 * d);
  dx = (this -> getX()) - (C -> getX());
  dy = this -> getY() - C -> getY();
  h = sqrt((C -> Radius * C -> Radius) - (a * a));
  x1 = (C -> getX() + ((a / d) * dx) - ((h / d) * dy));
  y1 = (C -> getY() + ((a / d) * dy) + ((h / d) * dx));
  x2 = (C -> getX() + (a / d) * dx + (h / d) * dy);
  y2 = (C -> getY() + (a / d) * dy - (h / d) * dx);
  * S1 = new POINT(x1, y1);
  * S2 = new POINT(x2, y2);
}


