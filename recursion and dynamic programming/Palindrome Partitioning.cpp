#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

bool isPalin(string& str, int start, int end)
{
    for(int i=start; i< end-start+1; i++ )
    {
        if(str[i] != str[end-(i-start)])
            return false;
    }
    return true;
}

//recursive solution with optimal substructure:
//time complexity: exponential
int palindromePartioning_recur(string& str,int start, int end)
{
    int n= end-start+1;
    if(n <= 1)
        return 0;
        
    if(isPalin(str,start,end))
        return 0;
    else
    {
        int minSplit=INT_MAX;
        int split;
        for(int k=start; k<=end-1; k++)
        {
            split= 1+palindromePartioning_recur(str, start, k)+palindromePartioning_recur(str,k+1,end);
            minSplit = min(minSplit, split);
        }
        
        return minSplit ==INT_MAX?1:minSplit;
    }
    
    
}


//split the string into number of partitions such that the each partition is the palindrome
//output the minimum number of splits needed to make a string palindrome.
//output: O(n2);
int palindromePartioning(string& str)
{
    int n=str.length();
    
    int dp[n][n];
    
    //minimum number of splits needed for the single letter 
    // to make it a palindrome is 0
    for(int i=0; i<n; i++)
        dp[i][i]=0;
    

    
    //for various lengths of the strings starting with length 2 to the length of the string
    for(int l=2; l<=n; l++)
    {
        for(int i=0; i<=n-l; i++)
        {
            int j=i+l-1;
            //if the string is palindrome no splits are needed
            if(str[i] == str[j])
            {
                dp[i][j]=0;
            }
            else 
            {
                int minSplit=INT_MAX;
                int split;
                //split the string at all positions. ex:- for abcb: split a bcb => 1 split, ab cb=> 3 splits,
                //abc b=> 3 splits: min split is 1
                for(int k=i; k<=j-1; k++)
                {
                    split=1+dp[i][k]+dp[k+1][j];
                    minSplit=min(minSplit,split);
                }
                dp[i][j]=minSplit==INT_MAX?1:minSplit;
            }
        }
    }
    
    return dp[0][n-1];
}

int main() {
	// your code goes here
	string str="abcbm";
	cout<<palindromePartioning(str)<<endl;
	return 0;
}
