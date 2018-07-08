#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <climits>
using namespace std;
 
void removeRedundants(long long num)
{
	string str=to_string(num);
	string prefix;
	char prev;
	long long max=LLONG_MIN;
	cout<<str<<endl;
 
	int n=str.length();
	for(int i=0; i<n; i++)
	{
		if(prev == str[i])
		{
			string res=prefix+str.substr(i+1,n-i-1);
			cout<<res<<endl;
			long long current=stoll(res);
			if(max < current) max=current;
			prefix+=str[i];

		}
		else
		{
			prefix+=str[i];
		}
		prev=str[i];
	}
 	
 	cout<<endl;
	cout<<max;
 
}
 
int main() {
	long long num=434456777843443;
	removeRedundants(num);
	return 0;
}