#include <iostream>
#include <string>
using namespace std;

string convertToBinary_BitManip(int num)
{
	string str;
	while(num!=0)
	{
		int shifted=num&1;
		char r= shifted==0?'0':'1';
		str=r+str;
		num=num>>1;
	}
	return str;
}

string convertToBinary_iter(int num)
{
	string str;
	while(num!=0)
	{
		char r=num%2==0?'0':'1';
		str=r+str;
		num=num/2;
	}
	return str;
}

string convertToBinary_recur(int num)
{
	string str="";
	if(num==0)
		return str;
	char r= num%2==0?'0':'1';
	str=convertToBinary_recur(num/2)+r;
	return str;
}

int main() {
	
	int num=13;
	cout<<convertToBinary_recur(num)<<endl;
	return 0;
}