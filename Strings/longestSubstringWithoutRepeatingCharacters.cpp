#include <iostream>
#include <climits>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) 
{
   string  temp="";
   int length=0;
   for(int i=0; i<s.length();i++)
   {
       size_t pos=temp.find(s[i]);
       if(pos!=string::npos)
       {
           if(length<temp.length())
                length=temp.length();
           temp.erase(0,pos+1);
           temp.push_back(s[i]);
       }
       else
       {
           temp.push_back(s[i]);
       }
   }
   if(length<temp.length())
        length=temp.length();
   return length;
}

int main() {
	string str = "abba";
	cout << lengthOfLongestSubstring(str);
	return 0;
}