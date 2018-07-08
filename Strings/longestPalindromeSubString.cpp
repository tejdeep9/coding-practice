#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
1. form a palindrome square matrix with the length of the string as dimensions.
2. for the substrings of the length 1. set the values as true;
3. for substrings of the length 2. check and set the values.
4. for the substrings length morethan 2. check the first and last character match 
   and increment i and decrement j and check whether the substring is palindrome.
   
   Time complexity: O(n2)
   Space complexity: O(n2)
*/
char* longestPalindromeSubString_N2(char* S)
{
	int n=strlen(S);
	int start=0;
	int max_len=1;
	bool** palindrome= new bool*[n];
	for(int i=0;i<n;i++)
		palindrome[i]=new bool[n];
		
	//make sustrings of length 1 as palindrome
	for(int i=0;i<n;i++)
		palindrome[i][i]=true;
	
	//check the substring of length 2 are palindromes or not
	for(int i=0;i<n-1;i++)
	{
		if(S[i]==S[i+1])
		{
			palindrome[i][i+1]=true;
			start=i;
			max_len=2;
		}
	}
	//check for the strings of more than 2 are palindromes or not.
	for(int curren_len=3;curren_len<n;curren_len++)
	{
		for(int i=0; i<n-curren_len+1;i++)
		{
			int j=i+curren_len-1;
			if((S[i]==S[j])&&palindrome[i+1][j-1])
			{
				palindrome[i][j]=true;
				start=i;
				max_len=curren_len;
			}
		}
	}
	
	char* res= new char[max_len+1];
	res[max_len]='\0';
	for(int i=start; i<start+max_len;i++)
		res[i-start]=S[i];
		
	for(int i=0; i<n;i++)
		delete palindrome[i];
	delete palindrome;
	
	return res;
}


bool checkPalindrome(string& str, int start, int end)
{
    int len= end-start+1;
    
    for(int i=start; i< start+(len/2) ; i++)
    {
        if(str[i] != str[end-(i-start)])
            return false;
    }
    
    return true;
}
void LonPalSubStr_Recur(string& str, int l)
{   
    int len=str.length();
    if(l <= 1)
    {
        //there is no longest palindromic substring
        return;
    }
    
    //declare a sliding window for chekcing the given string is a palindrome
    for(int i=0 ;i <= len-l; i++)
    {
        int j=i+l-1;
        if(checkPalindrome(str, i,j ))
        {
            cout<<" The Longest Palindromic Substring is "<< str.substr(i,l)<<endl;
            return;
        }
    }
    
    
    LonPalSubStr_Recur(str, l-1);
}


int main() {
	//char S[]="bananas";
	char S[]="forgeeksskeegfor";
	char* res=longestPalindromeSubString_N2(S);
	string str="forgeeksskeegfor";
	LonPalSubStr_Recur(str, str.length());
	cout<<res<<endl;
	return 0;
}