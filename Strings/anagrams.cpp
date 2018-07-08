#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

bool anagrams(string str1, string str2)
{
	if(str1.length()!=str2.length())
		return false;
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
	sort(str1.begin(),str1.end());
	sort(str2.begin(), str2.end());
	cout<<str1<<endl;
	cout<<str2<<endl;
	for(int i=0; i<str1.length(); i++)
	{
		if(str1[i]!=str2[i])
			return false;
	}
	return true;
}

int main() {
	string str1="tejdeeps";
	string str2="speedJet";
	if(anagrams(str1,str2))	
		cout<<"anagrams"<<endl;
	else
		cout<<"not anagram"<<endl;
	return 0;
}