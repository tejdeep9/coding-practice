#include <iostream>
#include <queue>
#include <functional>
#include <cstdlib>


using namespace std;


bool compare(const pair<int, int>& p1, const pair<int, int>& p2){

	if (p1.second == p2.second) //if the durations are same,order by the arrival time
	{
		if (p1.first>p2.first)
			return true;
		else
			return false;
	}
	else
	{
		if (p1.second>p2.second)
			return true;
		else
			return false;
	}
}
//A program which returns the average waiting time of the jobs using Shortest Job First Scheduling 
double SJF(int* startTimes, int n, int* durations)
{
	if (n <= 0)
		return NULL;
	int visitTime = 0;
	int waitTime = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(const pair<int, int>&, const pair<int, int>&)>> pq(compare);

	//the processes that arrived first will be executed 
	int initArrivalTime = startTimes[0];
	int i ;
	//checking whether the other process has same arrival times of the first process
	for (i = 0; i<n&&initArrivalTime == startTimes[i]; i++)
		pq.push(make_pair(startTimes[i], durations[i]));

	visitTime = startTimes[0];

	while (!pq.empty())
	{

		int startTime = pq.top().first;
		waitTime += visitTime - startTime; //add the wait time for each process
		visitTime += pq.top().second;
		pq.pop();
		//storing all the processes the came during this visiting time
		while (i<n&&startTimes[i] <= visitTime)
		{
			pq.push(make_pair(startTimes[i], durations[i]));
			i++;
		}

	}

	double avgWaitTime = (double)waitTime / n;

	//return average waiting time for the SJF
	return avgWaitTime;
}



int main() {

	//case 1 //answer 2.4
	//int startTimes[] = { 0, 2, 4, 6, 7 };
	//int  Durations[] = { 5, 3, 2, 4, 1 };
	//case 2 //answer 7.5
	//int startTimes[] = { 0, 2, 4, 6, 8, 11 };
	//int  Durations[] = { 9, 7, 5, 4, 3, 2 };
	//case 3 same burst time //3.714
	int startTimes[] = { 0, 2, 4, 6, 6, 7, 8};
	int  Durations[] = { 5, 3, 3, 2, 4, 1, 1};
	//case 4 same burst and arrival times //answer 7.857
	//int startTimes[] = { 0, 2, 2, 4, 6, 6, 7 };
	//int  Durations[] = { 5, 3, 3, 3, 6, 6, 5 };
	//case 5 same initial arrival times
	//int startTimes[] = { 0, 0, 4, 5 };
	//int  Durations[] = { 7, 4, 1, 4 };

	cout << "avg waiting time is " << SJF(startTimes, 7, Durations) << endl;
	return 0;
}