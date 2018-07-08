#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

/* if the element occurs before the element put 1 else put 0
similarly put 1 if element occurs after it */

void checkElemAndPrint(vector<int>& vect)
{
	string str="";
	int n=vect.size();
	unordered_set<int> set;
	for(int i=0;i<vect.size();i++)
	{
		if(set.find(vect[i])!=set.end())
		{
			str.push_back('1');
		}
		else
		{
			str.push_back('0');
			set.insert(vect[i]);
		}
		
	}
	cout<<str<<endl;
	string str1="";
	set.clear();
	for(int i=n-1; i>=0; i--)
	{
		if(set.find(vect[i])!=set.end())
		{
			str1.insert(str1.begin(),'1');
		}
		else
		{
			str1.insert(str1.begin(),'0');
			set.insert(vect[i]);
		}
	}
	cout<<str1<<endl;
}

int main() {
	int arr[]={1,1,2,4,4,5};
	int n=extent<decltype(arr)>::value;
	vector<int> vect;
	vect.assign(arr,arr+n);
	checkElemAndPrint(vect);
	return 0;
}