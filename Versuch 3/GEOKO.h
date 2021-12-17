#ifndef GEOKO_H_INCLUDED
#define GEOKO_H_INCLUDED

#include "TE.h"


class GEOKO :public TE {
private:
    int BrGr;
    int LaGr;
    int BrMin;
    int LaMin;
    double lange;
    double breite;
    double BrSec;
    double LaSec;
    double Abstand;
public:
    GEOKO(double, double);
    void setBrGr(int);
    void setLaGr(int);
    void setBrMin(int);
    void setLaMin(int);
    void setBrSec(double);
    void setLaSec(double);
    void setAbstand(double);
    void setbreite(double);
    void setlange(double);
    double getlange();
    double getbreite();
    int getBrGr();
    int getLaGr();
    int getBrMin();
    int getLaMin();
    double getBrSec();
    double getLaSec();
    double getAbstand();

    bool  operator == (GEOKO&);
    bool  operator > (GEOKO&);
};

#endif // GEOKO_H_INCLUDED
