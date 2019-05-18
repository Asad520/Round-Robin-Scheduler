#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

class process
{
	string PName;
	int ATime;
	int STime;
	int FTime;
	int WTime;
	int TATime;
	process* next;
	friend class RR;
public:
	process();
	process(string PName, int ATime, int STime, int stTime = 0, int FTime=0, int WTime=0, int TATime=0);
	string getPName();
	int getATime();
	int getSTime();
	int getFTime();
	process* getNext();
	void setPNAme(string PName);
	void setATime(int ATime);
	void setSTime(int STime);
	void setFTime(int FTime);
};