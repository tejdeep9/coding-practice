#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void smallestKIntegers(vector<int>& vect, int k)
{
	priority_queue<int> pq;
	
	for(int i=0; i<k; i++)
		pq.push(vect[i]);
		
	for(int i=k; i<vect.size(); i++)
	{
		if(pq.top() > vect[i])
		{
			pq.pop();
			pq.push(vect[i]);
		}
	}
	
	retrun pq.top();
}

int main() {
	// your code goes here
	return 0;
}