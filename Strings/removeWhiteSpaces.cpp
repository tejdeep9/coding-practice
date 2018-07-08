#include <iostream>
#include <cstring>
using namespace std;

void removeWhiteSpace(char* str)
{
	int count=0;
	int n=strlen(str);
	for(int i=0; i<n; i++)
		if(str[i]!=' ')
			str[count++]=str[i];
	str[count]='\0';
}

int main() {
	char str[]="g eeks for ge eeks";
	removeWhiteSpace(str);
	cout<<str<<endl;
	return 0;
}