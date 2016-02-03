#include <iostream>
#include <cstring>
#include <tr1/unordered_map>
#define ASCII_SIZE 256
using namespace std;

char maxFreqCharWithMap(char* str){
	tr1::unordered_map<char, int> map;
	int n = strlen(str);
	int count = 0;
	for (int i = 0; i<n; i++)
		map[str[i]]++;

	int max = 0;
	for (int i = 0; i<n; i++)
	{
		if (max<map[str[i]])
			max = i;

	}

	return str[max];
}
char maxFreqCharacter(char* str){

	int count[ASCII_SIZE] = { 0 };
	int n = strlen(str);

	for (int i = 0; i<n; i++)
		count[str[i]]++;

	int max = 0;
	for (int i = 0; i<n; i++)
	{
		if (max<count[str[i]])
			max = i;
	}

	return str[max];
}

int main() {

	char str[] = "tewaeeet";
	cout << maxFreqCharWithMap(str);
	return 0;
}
