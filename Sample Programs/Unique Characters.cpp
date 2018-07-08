#include <iostream>
#include <string>
#include <unordered_map>
#define ASCII_SIZE 256
using namespace std;

//time complexity O(n) and space complexity O(1);
bool hasUniqueChar_ASCII(string& str){
    
    int count[ASCII_SIZE]={0};
    for(unsigned i=0; i<str.length(); i++){
        if(count[str[i]])
            return false;
        count[str[i]]++;
    }
    return true;
}

bool hasUniqueChar(string& str)
{
	unordered_map<chat,int> map;
	for(int i=0; i<str.size(); i++)
	{
		map[str[i]]++;
		if(map[str[i]] > 1)
			return false;
	}
	return true;
}
int main()
{
    string str="abcdefge";
    if(hasUniqueChar_ASCII(str))
        cout<<"it has the unique character"<<endl;
    else
        cout<<"its not unique"<<endl;
  return 0;
}
