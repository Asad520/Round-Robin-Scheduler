#include "RR.h"

int main()
{
	string PName[50] = { " " };
	int ATime[50] = { 99 };
	fill_n(ATime, 50, 9999);
	int STime[50] = { 99 };
	fill_n(STime, 50, 9999);
	int stTime[50] = { 99 };
	fill_n(stTime, 50, 9999);
	int FTime[50] = { 99 };
	fill_n(FTime, 50, 9999);
	int nop = 0;
	int TS = 1;
	fstream file("input.txt");
	file >> nop;
	if (nop > 50)
	{
		cout << "NOT ENOUGH SPACE AVAILABLE IN MEMORY! CPU CRASHED!!! BOOM BUMM BOOOOM!!!!\n\n";
		return 0;
	}
	int nops = nop;
	file >> TS;
	for (int i = 0; i < nop; i++)
	{
		file >> PName[i];
		file >> ATime[i];
		file >> STime[i];
	}

	for (int i = 0; i < nop; i++)
	{
		for (int j = 0; j < nop; j++)
		{
			if (ATime[i] < ATime[j])
			{
				int TpATime = ATime[i];
				int TpSTime = STime[i];
				string TpPName = PName[i];
				ATime[i] = ATime[j];
				STime[i] = STime[j];
				PName[i] = PName[j];
				ATime[j] = TpATime;
				STime[j] = TpSTime;
				PName[j] = TpPName;
			}
			else if (ATime[i] == ATime[j])
			{
				if (STime[i] < STime[j])
				{
					int TpATime = ATime[i];
					int TpSTime = STime[i];
					string TpPName = PName[i];
					ATime[i] = ATime[j];
					STime[i] = STime[j];
					PName[i] = PName[j];
					ATime[j] = TpATime;
					STime[j] = TpSTime;
					PName[j] = TpPName;
				}
			}

		}

	}


	RR r1;
	process PList[50];
	for (int i = 0; i < nop; i++)
	{
		PList[i].setPNAme(PName[i]);
		PList[i].setATime(ATime[i]);
		PList[i].setSTime(STime[i]);
	}
	
	int pid = 0;
	int num = 0;
	int index = 0;
	double tTAT = 0;
	double tWT = 0;
	while (nops > 0)
	{
		while (ATime[index] <= num)
		{
			r1.insert(PList[index]);
			index++;
		}


		r1.setSTime(r1.getSTime()-TS);
		if (r1.getSTime() <= 0)
		{
			r1.setFTime(num);
			cout << "Process " << r1.getPName() << " has been completed!!! Process attributes are:- \n\n";
			for (int i = 0; i < nop; i++)
			{
				if(r1.getPName()==PName[i])
				{
					pid = i;
				}
			}
			cout << "Process Name:" << "\t" << "Arrival Time:" << "\t" << "Service Time:" << "\t" << "Finish Time:" << "\t" << "TA Time:" << "\t" << "Waiting Time:\n";
			cout << PName[pid] << setw(18) << ATime[pid] << setw(18) << STime[pid] << setw(18) << r1.getFTime() << setw(18) << r1.getFTime() - ATime[pid] << setw(18) << (r1.getFTime() - ATime[pid]) - STime[pid] << "\n\n";
			tTAT += r1.getFTime() - ATime[pid];
			tWT += (r1.getFTime() - ATime[pid]) - STime[pid];
			system("pause");
			cout << endl;
		
			r1.remove();
			cout << "Remaining queue is as follows:- \n\n";
			r1.display();
			system("pause");
			cout << endl;
			nops--;
		}
		else
		{
			r1.gotoNext();
		}

		num++;
		if (num > 99)
		{
			cout << "NOT ENOUGH MEMORY!!! CPU CRASHED!!! \n AAAAAAAAAAAAAAAAAAAAAAAAA \n";
				break;
		}
	}
	r1.display();

	cout << "Average TurnAround Time = " << tTAT / nop << endl;
	cout << "Average Waiting Time = " << tWT / nop << endl;
}
