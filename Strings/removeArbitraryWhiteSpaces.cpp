#include <iostream>
#include <cstring>
using namespace std;

void removeArbitraryWhiteSpaces(char* str)
{
	int n=strlen(str);
	int index=0;
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]==' ')
		{
			if(count>=1)
				count++;
			else
			{
				if(i!=0 && i!=n-1)
					str[index++]=str[i];
				count++;
			}
		}
		else
		{
			str[index++]=str[i];
			count=0;
		}
		
	}
	str[index]='\0';
}

int main() {
	char str[]="    The        sky     is    blue    ";
	removeArbitraryWhiteSpaces(str);
	cout<<str<<endl;
	return 0;
}