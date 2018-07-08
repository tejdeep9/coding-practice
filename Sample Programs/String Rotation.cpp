#include <iostream>
#include <string>
using namespace std;

bool isRotation(string& str1, string& str2)
{
	int n1=str1.length();
	int n2=str2.length();
	string result="";
	
	if( n1 == n2 && n1 > 0)
	{
		result= str1+str1;
		return result.find(str2)!=string::npos;
		
	}
	return false;
};

int main() {
	string str1="waterbottle";
	string str2="erbottlewat";
	cout<<isRotation(str1,str2);
	return 0;
}