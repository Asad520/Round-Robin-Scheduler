#include "process.h"

process::process()
{
}

process::process(string PName, int ATime, int STime, int stTime, int FTime, int WTime, int TATime)
{
	this->PName = PName;
	this->ATime = ATime;
	this->STime = STime;
	this->next = NULL;
}

string process::getPName()
{
	return this->PName;
}

int process::getATime()
{
	return this->ATime;
}

int process::getSTime()
{
	return this->STime;
}

int process::getFTime()
{
	return FTime;
}

process* process::getNext()
{
	return next;
}

void process::setPNAme(string PName)
{
	this->PName = PName;
}

void process::setATime(int ATime)
{
	this->ATime = ATime;
}

void process::setSTime(int STime)
{
	this->STime = STime;
}

void process::setFTime(int FTime)
{
	this->FTime = FTime;
}


