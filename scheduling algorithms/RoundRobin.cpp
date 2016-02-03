#include <iostream>
#include <queue>


using namespace std;


//A program which returns the average waiting time of the jobs using Shortest Job First Scheduling 
double RoundRobin(int* startTimes, int n, int* durations, int TQ)
{
	int visitTime = 0;
	int waitTime = 0;
	queue<pair<int, int>> q;


	//the process that arrived firt will be executed irrespective of it duration
	visitTime = startTimes[0];

	q.push(make_pair(startTimes[0], durations[0]));


	int i = 1;

	while (!q.empty())
	{
		int startTime = q.front().first;
		int duration = q.front().second;

		waitTime += visitTime - startTime; //add the wait time for each process
		if (duration <= TQ)
			visitTime += duration;
		else
			visitTime += TQ;

		//storing all the processes the came during this visiting time
		while (i<n&&startTimes[i] <= visitTime)
		{
			q.push(make_pair(startTimes[i], durations[i]));
			i++;
		}

		//pop the process, if it is still pop it
		if (duration <= TQ)
		{
			q.pop();
		}
		else
		{
			q.pop();
			q.push(make_pair(visitTime, duration - TQ));
		}
	}

	double avgWaitTime = (double)waitTime / n;

	//return average waiting time for the SJF
	return avgWaitTime;
}


int main() {

	//int startTimes[]  = {0,1,2,4,6,7};  
	//int  Durations[] = {4,5,6,1,3,2};
	int startTimes[] = { 0, 2, 4, 5 };
	int  Durations[] = { 7, 4, 1, 4 };
	cout << "avg waiting time is " << RoundRobin(startTimes, 4, Durations, 2) << endl;
	return 0;
}