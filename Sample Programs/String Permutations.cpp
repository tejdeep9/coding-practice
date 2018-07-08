#include <iostream>
#include <algorithm>
using namespace std;


void permute(string str, int l, int r)
{

   if (l == r)
     cout<<str<<endl;
   else
   {
       for (int i = l; i <= r; i++)
       {
          swap(str[l], str[i]);
          permute(str, l+1, r);
          swap(str[l], str[i]); //backtrack
       }
   }
}
 
/* Driver program to test above functions */
int main()
{
    string str = "ABC";
    int n = str.length();
    permute(str, 0, n-1);
    return 0;
}