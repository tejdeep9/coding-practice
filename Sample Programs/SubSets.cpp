#include <iostream>
#include <vector>
using namespace std;

void subSets(vector<char>& elems)
{
	int n=elems.size();
	//generate numbers from 0 to 2^n-1
	for(int i=0; i < (1<<n); i++)
	{	
		cout<<"{";
		for(int j=0; j<n; j++)
		{
			if( i & (1<<j)) //if the corresponding bit is set in the i
				cout<<elems[j]<<" ";
		}
		cout<<"}"<<endl;
	}	
}

int main() {
	vector<char> elems={'a', 'b', 'c'};
	subSets(elems);
	return 0;
	
}