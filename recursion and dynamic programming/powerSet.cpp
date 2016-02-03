#include <iostream>
#include <math.h>
using namespace std;
/*
for n elements there are 2^n subsets
algorithm:
 1. for count =0 to 2^n.
	index=0;
	2. for k= count to num of bits to represent it in the binary number
	   check (k&1)==1 or not, if so output the element set[index].
	   index++
Time Complexity:O(logn*2^n)
Space Compexity:O(1).		
*/

void powerSet_logn2pown(int s[], int n) 
{
	int max=1<<n;
	for(int count=0;count<max;count++)
	{	int index=0;
		for(int k=count;k>0;k>>=1)
		{
			if((k&1)==1)
			cout<<s[index];
			index++;
		}
		cout<<endl;
	}
} 

/*
 for n element set there are 2^n possible subssets.
 algorithm:
	1. for count=0 to 2^n,
		2. for i=0 to name
			find the bit at ith position is set or not, is set output the elements.

Time Complexity: O(n*2^n);
Space Complexity:O(1);			
*/

void powerSet_n2pown(int s[], int n) 
{
	int max=1<<n;
	for(int count=0;count<max;count++)
	{
		for(int i=0;i<n;i++)
		{
			if((1<<i)&count)
			cout<<s[i];
		}
		cout<<endl;
	}
} 

int main() {
	int set[] = {1,2,3};
    powerSet_n2pown(set, 3);

	return 0;
}