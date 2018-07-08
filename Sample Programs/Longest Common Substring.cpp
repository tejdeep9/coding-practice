#include <iostream>
#include <string>
using namespace std;

//Time Complesity:O( m*n)
// Create a table to store lengths of longest common suffixes of
// substrings.   Notethat dp[i][j] contains length of longest
// common suffix of str1[0..i-1] and str2[0..j-1]. The first row and
// first column entries have no logical meaning, they are used only
// for simplicity of program
int LongestCommonSubString(string& str1, string& str2)
{
    int m=str1.length();
    int n= str2.length();
    int dp[m+1][n+1];
    
    int maxLen=0, max_i=0, max_j=0;
    
    for(int i=0; i<=m; i++)
        dp[i][0]=0;
    for(int j=0; j<=n; j++)
        dp[0][j]=0;
    
    for( int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j]= dp[i-1][j-1]+1;
                
                if(maxLen < dp[i][j])
                {
                    maxLen=dp[i][j];
                    max_i=i;
                    max_j=j;
                }
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    
    string result="";
    while( dp[max_i][max_j] )
    {
        result.insert(0, 1, str1[max_i-1]);
        max_i--;
        max_j--;
    }
    cout<<result<<","<<max_i<<" length "<<maxLen<<endl;
}
    

int main() {
	string str1="abcdaf";
	string str2="zbcdf";
	LongestCommonSubString(str1,str2);
	return 0;
}
