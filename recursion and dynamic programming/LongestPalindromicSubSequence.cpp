#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//Time Complexity: explonential complexity
int LPSSeq_recur(char* str, int start, int end)
{   
    //base case
    if(start > end)
        return 0;
    if(start == end)
        return 1;
    
    //when last two characters of the strings match then  longest palindromic sub sequence 
    //so the start and end characters of the string will be in solution set LPSS[i..j]= LPSS[i+1 ... j-1] +2;
    if(str[start] == str[end])
    {
        return LPSSeq_recur(str, start+1, end-1)+2;
    }
    else //if not MAX(LPSS(0..n-1),(1..n));
    {
        return max(LPSSeq_recur(str,start+1,end),LPSSeq_recur(str,start, end-1));
    }
}

//Time complexity :O(n2)
int LPSSeq_dp(char* str, int n)
{
    if(n <= 0)
        return 0;
    if( n == 1)
        return 1;
    //declare dp array to store length of longest palindromic sub sequence
    int dp[n][n];
    
    //string of the length 1 has longest palindromic sub sequence 1
    for(int i=0; i<n; i++)
        dp[i][i]=1;
    
    for(int len=2; len <= n; len++)
    {
        //update the dp table
        for(int i=0; i<= n-len; i++)
        {
            int j= i+len-1; //length of the sub string from start to end.
            if(str[i] == str[len-1-i])
            {
                dp[i][j] = dp[i+1][j-1]+2;
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
    }
    
    return dp[0][n-1];
}
int main() {
	char* str="agdbdba";
	//char* str="BBABCBCAB";
	int len=strlen(str);
	cout<<LPSSeq_recur(str,0,len-1)<<endl;
	cout<<LPSSeq_dp(str,len)<<endl;
	return 0;
}
