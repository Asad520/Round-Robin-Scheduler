#pragma once
#include "process.h"

class RR
{
	process* head;
	process* rear;
	process* cur;
public:
	RR();
	bool isEmpty();
	void insert(process& newP);
	void display();
	void remove();
	void gotoNext();
	process* getNext();
	void setPNAme(string PName);
	void setATime(int ATime);
	void setSTime(int STime);
	void setFTime(int FTime);
	string getPName();
	int getATime();
	int getSTime();
	int getFTime();
	int getWTime();
	int getTATime();
};
