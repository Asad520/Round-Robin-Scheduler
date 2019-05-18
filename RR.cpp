#include "RR.h"

RR::RR()
{
	head = NULL;
	rear = NULL;
	cur = NULL;
}

bool RR::isEmpty()
{
	return (head == NULL);
}

void RR::insert(process& newP)
{
	process* t = new process(newP.PName, newP.ATime, newP.STime);
	if (head == NULL)
	{
		head = t;
		cur = head;
		rear = t;
		t->next = t;
	}
	else
	{
		process* temp = head;
		while (temp->next != head)
		{
			temp = temp->next;
		}
		temp->next = t;
		rear = t;
		t->next = head;
	}
}

void RR::display()
{
	if (head == NULL)
	{
		cout << "QUEUE HAS BEEN EMPTIED!!!!\n\n\n";
	}
	else
	{
		cout << "Process Names:" << "\t" << "Arrival Times:" << "\t" << "Rem Service Times:" << "\n";
		process* t = head;
		do
		{
			cout << t->PName << setw(18) << t->ATime << setw(18) << t->STime << setw(18) << "\n" ;
			t = t->next;
		} while (t!=head);
	}
}

void RR::remove()
{
	if (head->next == head)
	{
		head = NULL;
		rear = NULL;
		cur = NULL;
	}
	else if (cur==head)
	{
		process* t = head;
		head = head->next;
		cur = head;
		rear->next = head;
		delete t;
	}
	else if (cur->next == head)
	{
		process* t = head;
		while (t->next != cur)
		{
			t = t->next;
		}
		cur = head;
		t->next = head;
	}
	else
	{
		process* t = head;
		while (t->next != cur)
		{
			t = t->next;
		}
		t->next = cur->next;
		cur = cur->next;
	}
}

void RR::gotoNext()
{
	if (cur->next == head)
	{
		cur = head;
		cur->next = head -> next;
	}
	else
	{
		cur = cur->next;
	}
}

process* RR::getNext()
{
	return cur->next;
}

void RR::setPNAme(string PName)
{
	cur->PName = PName;
}

void RR::setATime(int ATime)
{
	cur->ATime = ATime;
}

void RR::setSTime(int STime)
{
	cur->STime = STime;
}

void RR::setFTime(int FTime)
{
	cur->FTime = FTime;
}

string RR::getPName()
{
	return cur->PName;
}

int RR::getATime()
{
	return cur->ATime;
}

int RR::getSTime()
{
	return cur->STime;
}

int RR::getFTime()
{
	return cur->FTime;
}
