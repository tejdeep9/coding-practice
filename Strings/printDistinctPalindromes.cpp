#include <iostream>
#include <string>
#include <unordered_set>
#include <climits>
#include <algorithm>
using namespace std;

string preProcess(string str)
{
	int n=str.length();
	string res="(#";
	for(int i=0; i<n; i++)
	{
		res=res+str[i]+'#';
	}
	res=res+')';
	return res;
}

void distinctPalindromes(string str)
{
	unordered_set<string> set;
	
	for(int i=0; i<str.length(); i++)
	{
		if(set.find(string(1,str[i]))==set.end())
			set.insert(string(1,str[i]));
	}
	
	string temp=preProcess(str);
	int n=temp.length();
	
	int* len = new int[n];
	int center=0, right=0;
	for(int i=1; i<n-1 ;i++)
	{
		int mirror=2*center-i;
		
		if(i<right)
			len[i]=min(right-i,len[mirror]);
		else
			len[i]=0;
	
		while(temp[i+len[i]+1]==temp[i-len[i]-1])
			len[i]++;
		
		if(i+len[i]>right)
		{
			center=i;
			right=i+len[i];
			
		}
	}
	
	for(int i=1; i<n-1; i++)
	{
		if(len[i]>1)
		{
			int start=(i-len[i])/2;
			string elem=str.substr(start,len[i]);
			if(set.find(elem)==set.end())
				set.insert(elem);
		}
	}
	
	for(unordered_set<string>::iterator it=set.begin(); it!=set.end(); ++it)
	{
		cout<<*it<<endl;
	}
	
	
}

int main() {
	distinctPalindromes("geek");
	return 0;
}