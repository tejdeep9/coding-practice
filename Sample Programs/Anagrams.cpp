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


bool anagrams(string str1, string str2)
{
	if(str1.length() ==str2.length())
		return false;
	int count1[NO_OF_CHARS] = {0};
	int count2[NO_OF_CHARS] = {0};
	int i;
 
	// For each character in input strings, increment count in
	// the corresponding count array
	for (i = 0; str1[i] && str2[i];  i++)
	{
		count1[str1[i]]++;
		count2[str2[i]]++;
	}
 
	// Compare count arrays
	for (i = 0; i < NO_OF_CHARS; i++)
		if (count1[i] != count2[i])
			return false;
 
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