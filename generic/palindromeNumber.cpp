#include <iostream>
#include <cmath>
using namespace std;



bool isPalindrome(int x) 
{
    if(x<0)
        return false;
    long res=0;
    int val=x;
    
    while(val!=0)
    {
        res=res*10+val%10;
        val=val/10;
    }
     
    if(res==x)
        return true;
    else
        return false;
}


int main() {
	int x=323;
	if(isPalindrome(x))
		cout<<"number is palindrome"<<endl;
	else
		cout<<"not palindrome"<<endl;
	
	return 0;
}