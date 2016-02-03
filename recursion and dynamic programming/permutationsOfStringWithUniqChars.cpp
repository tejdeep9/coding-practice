/*
statement: write the permutations of a string with unique characters.

approach: we are following base case and build approach. the base case is permutation of empty string.
for n=1 the permutation will be a1.
for n-2 the permutation will be a2a1,a1a2.
for n=3 the permutations will be a1a2a3,a3a1a2,a1a3a2, a3a2a1,a2a3a1,a2a1a3.
we will get step n=3 by inserting a3 in each and every position of n=2

algorithm:
1. Construct a recursive function  with base case as string length=0, add it to the empty list and return.
2. If string length is not empty get the first character in the string and store it.
3. Form a sub string with the from original string from second character to end and pass it to same function recursively.
4. get the list returned by the recursive function and stored character to each position for every string in the list.
5. return the updated list.

Time Complexity: O(n!)
Space Complexity: O(n!)
*/

#include <iostream>
#include <string>
#include <list>
using namespace std;

list<string> getPerms(string str)
{
	if (str.length() == 0)
	{
		list<string> perms;
		perms.push_back("");
		return perms;
	}
	else
	{
		list<string> perms;
		char elem = str.at(0);
		string sub_str = str.substr(1);
		list<string> words = getPerms(sub_str);
		for (string& s : words)
		{
			int i;
			list<string> temp;
			string newString=s;
			for (i = 0; i<s.length(); i++)
			{
				newString = s;
				newString.insert(i, 1, elem);
				perms.push_back(newString);
			}
			newString = s;
			newString.insert(i, 1, elem);
			perms.push_back(newString);
		}
		
		return perms;
	}
}

int main() {
	string str = "1234";
	list<string> perms = getPerms(str);
	for (list<string>::iterator it = perms.begin(); it != perms.end(); ++it)
		cout << *it << endl;
	return 0;
}