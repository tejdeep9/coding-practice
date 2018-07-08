#include <iostream>
#include <string>
using namespace std;
string longestPalindrome(string s) {
    cout<<s.length()<<endl;
    string res="";
    int start=0, size=0;
    if(s.length()>=1000)
        return res;
        
    size=1;
    int n=s.length();
    bool** table=new bool*[n];
    for(int i=0; i<n;i++)
        table[i]= new bool[n];
    

    // for sub strings of length 1
    for(int i=0; i<n ; i++)
    {
        table[0][i]=true;
    }
    
    // for substrings of length 2
    for(int i=1; i<n ;i++)
    {
        if(s[i-1]==s[i])
        {
            table[1][i]=true;
            start= i-1;
            size=  i+1;
        }
    }

    for(int i=2 ;i<n ; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(s[j-i]==s[j] && table[i-2][j-1])
            {
                table[i][j]=true;
                start=j-i;
                size=i+1;
            }
        }
    }
    res=s.substr(start,size);
    for(int i=0; i<n; i++)
        delete table[i];
    delete table;
    return res;
}
int main() {
	string str="haideepeedssaiiass";
	cout<<longestPalindrome(str)<<endl;
	return 0;
}