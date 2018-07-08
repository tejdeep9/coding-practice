/*word wrapping to width, passed into a function, every line should be <= 6 characters wide

INPUT
"aaa bb cc ddddd"
width = 6

OUTPUT
"aaa bb\ncc\nddddd"

aaa bb 
cc 
ddddd

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string  WordWrap(string input,int width)
{
    string result="";
    
    if(input.empty())
        return result;
        
    vector<string> words;
    string temp;
    for(int i=0; i<input.length(); i++)
    {
        if(input[i]== ' ')
        {
             if(!temp.empty())
             {
                words.push_back(temp);  
                temp.clear();  
             }
        }
        else
        {
            temp.push_back(input[i]);
         
        }
    }
    
    if(!temp.empty())
    {
        words.push_back(temp);
        temp.clear();
    }
    
  
    int w = 0;
    bool space = true;
    for(string& str: words)
    {
        
        if(str.length() > width) //for single word
        {
            
            for(int i=0; i<str.length(); i++)
            {
               if(w < width)
               {
                   result.push_back(str[i]);
                   w++;
               }
               else
               {
                   result.push_back('\n');
                   w=0;
                   result.push_back(str[i]);
                   w++;
               }
            }
        }
        else 
        {
               if(w==0 && !space)
                              result+=" ";
            for(int i=0; i<str.length(); i++)
            {
               if(w < width)
               {
                   result.push_back(str[i]);
                   w++;
               }
               else
               {
                   result.push_back('\n');
                   w=0;
                   result.push_back(str[i]);
                   w++;
               }
            }
            
            if(w < width)
            {
              result+=" ";
              space=false;
              w++;
            } 
            
            if(w == width)
            {
                 result.push_back('\n');
                 space=true;
                 w=0;
            }
            
        }
    }
    return result;
}

int main() {
               string input ="aaa bb cc ddddd";
               cout<<WordWrap(input,6)<<endl;
               return 0;
}

/*
aaa
bb
cc
ddddd

w=4
aaa bb\n
//"aaa bb cc ddddd"


// GREEDY SOLUTION, PRODUCES SHORT LINES SOMETIMES
aaa bb 
cc 
ddddd

// THIS IS A LITTLE BETTER LOOKING, LINES ARE MORE EVEN
aaa
bb cc
ddddd

// ideas?
*/