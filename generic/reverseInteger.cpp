#include <iostream>
#include <climits>
using namespace std;

int reverse(int x) 
{
    int val=abs(x);
    long res=0;
    while(val!=0)
    {
        res=10* res+val%10;
        val=val/10;
    }
    
    if(res>INT_MAX || res <INT_MIN)
        return 0;
    else
        return x>0?res:-res;
}

int main() {
	int x=123;
	cout<<reverse(x)<<endl;
	
	return 0;
}