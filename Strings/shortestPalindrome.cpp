#include <iostream>
#include <string>
using namespace std ;

bool isPalindrome(string& str)
{
	bool palin=true;
	for(int i=0,j=str.length()-1;i<j;i++,j--)
		if(str[i]!=str[j])
		{
			palin=false;
			break;
		}
	return palin;
}
string ShortestPalindrome_addAtFront(string& str)
{
	string result=str;
	for(string::reverse_iterator it=str.rbegin();it!=str.rend()-1;++it)
	{	if(isPalindrome(result))
			break;
		result=*it+result;
	}
	return result;
}
string ShortestPalindrome_addAtEnd(string& str)
{
	string result=str;
	for(string::reverse_iterator it=str.rbegin()+1;it!=str.rend();++it)
	{	if(isPalindrome(result))
			break;
		result.push_back(*it);
	}
	return result;
}
int main()
{
    //string str = "aaacecaa" ; //palindrome by adding at end
    //string str = "aacecaa" ; //palindrome
    string str="aacecaaa"; //palindrome by adding at front
   	cout << ShortestPalindrome_addAtEnd(str)<<endl;
    cout<< ShortestPalindrome_addAtFront(str)<<endl;
}