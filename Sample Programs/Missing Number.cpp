#include <iostream>
#include <vector>
using namespace std;

int missingNumber_normal(vector<int>& vect)
{
	int sum=0;	
	for(int i=0; i < vect.size(); i++)
	{
		sum+=vect[i];
	}
	
	int n=vect.size();
	int total=((n+1)*(n+2))/2;
	
	return total-sum;
};

int missingNumber_XOR(vector<int>& vect)
{
	int x1=vect[0];
	int x2=1;
	
	for(int i=1; i<vect.size(); i++)
		x1^=vect[i];
		
	for(int i=2; i<=vect.size()+1; i++)
		x2^=i;
		
	return x1^x2;
}
int main() {
	// your code goes here
	vector<int> vect = {1, 2, 4,6, 3, 7, 8};
	cout<<missingNumber_XOR(vect)<<endl;
	return 0;
}