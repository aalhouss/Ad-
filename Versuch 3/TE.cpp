#include "TE.h"

TE::TE() {}


TE::TE(TE* a, TE* b, TE* c) {
    this->P = a;
    this->L = b;
    this->R = c;

}
TE* TE::getP() {
    return this->P;
}
 TE* TE::getL() {
    return this->L;
}
TE* TE::getR() {
    return this->R;
}
 void TE::setP(TE* wert) {
    this->P = wert;
}
 void TE::setL(TE* value) {
    this->L = value;
}
 void TE::setR(TE* val) {
    this->R = val;
}
TE::~TE(){}

