#ifndef TE_H_INCLUDED
#define TE_H_INCLUDED


class TE {
private:
	TE* P;
	TE* L;
	TE* R;
public:
	TE();
	~TE();
	TE(TE*, TE*, TE*);
	TE* getP();
	TE* getL();
	TE* getR();
	void setP(TE*);
	void setL(TE*);
	void setR(TE*);

};





#endif // TE_H_INCLUDED
