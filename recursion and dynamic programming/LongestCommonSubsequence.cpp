#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//Time Complexity: O(m*n)
int LCS_DP(string& X, string& Y, int m, int n)
{
    //declare an table to store tha values for the sub problems
    int dp[m+1][n+1]; //extra dimension is used to include results for strings of length 0
    
    //load the first row and first coloumn to zero as the largest common subsequence with string of
    //length 0 is 0.
    for(int i=0; i<=m; i++)
        dp[i][0]=0;
    for(int j=0;j<=n; j++)
        dp[0][j]=0;
    
    //calculate the dp table
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            //if the last characters of the strings match 
            if(X[i-1] == Y[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    
    return dp[m][n];
}

// Time Complexity: O(2^n)
int LCS_Recur(string& X, string& Y, int m, int n)
{
    //if any of the string is empty LCS is zero.
    if( m==0 || n==0)
        return 0;
    
    //if the last characters of the strings match. then this character contributes to the LCS
    // and the optimal solution of the substrings with length 1 less than the string will be added.
    // l("AGGTAB", "GXTXAYB")= 1+ L("AGGTA", "GXTAY")
    if( X[m-1] == Y[n-1])
        return 1+ LCS_Recur(X,Y,m-1,n-1);
    else 
        return max( LCS_Recur(X,Y,m-1,n), LCS_Recur(X,Y,m,n-1));
    //the LCS is maximum LCS among given string and one less the length of the other,
    // L("ABCDGH","AEDFH")=MAX( L("ABCDG","AEDFH"), L("ABCDG"."AEDF")
}

int main() {
	string X="AGGTAB";
	string Y="GXTXAYB";
	
	//cout<<LCS_Recur(X,Y,X.length(),Y.length())<<endl;
	cout<<LCS_DP(X,Y,X.length(),Y.length())<<endl;
	return 0;
}
