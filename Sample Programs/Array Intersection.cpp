//************* SORTED ARRAY *******************************

//union
int printUnion(vector<int>& vect1, vector<int>& vect2)
{
  int i = 0, j = 0;
  int m=vect1.size();
  int n=vect2.size();
  while (i < m && j < n)
  {
    if (vect1[i] < vect2[j])
		cout<<vect[i++];
    else if (arr2[j] < arr1[i])
		cout<<vect2[j++];
    else //print any number
	{
		cout<<vect2[j++];
		i++;	
	}
  }
 
  /* Print remaining elements of the larger array */
  while(i < m)
   cout<<vect1[i++];
  while(j < n)
   cout<<vect2[j++];
}

int printIntersection(vector<int>& vect1, vector<int>& vect2)
{
  int i = 0, j = 0;
  int m=vect1.size();
  int n=vect2.size();
  while (i < m && j < n)
  {
    if (vect1[i] < vect2[j])
      i++;
    else if (vect2[j] < vect1[i])
      j++;
    else /* if arr1[i] == arr2[j] */
    {
      cout<<vect2[j++]);
      i++;
    }
  }
}
 
 //************* UNSORTED ARRAY *************************************

#include <iostream>
#include <algorithm>    // std::binary_search, std::sort
#include <vector>       // std::vector
using namespace std;
 
 /* Union:
1) Initialize union U as empty.
2) Find smaller of m and n and sort the smaller array.
3) Copy the smaller array to U.
4) For every element x of larger array, do following
…….b) Binary Search x in smaller array. If x is not present, then copy it to U.
5) Return U.
*/

//pass the lesser size vector as the first parameter
void Driver(vector<int>& vect1, vector<int>& vect2)
{
	if(vect1.size() <= vect2.size())
	{
		printUnion(vect1, vect2);
	}
	else
	{
		printUnion(vect2, vect1);	
	}

}
void printUnion(vector<int>& vect1, vector<int>& vect2)
{

    // Sort the first array and print its elements (these two
    // steps can be swapped as order in output is not important)
    sort(vect1.begin(), vect1.end());
    for (int i=0; i<vect1.size(); i++)
        cout << vect1[i] << " ";
 
    // Search every element of bigger array in smaller array
    // and print the element if not found
    for (int i=0; i<vect2.size(); i++)
		if(!binary_search (vect1.begin(), vect1.end(), vect2[i]))
            cout << arr2[i] << " ";
}
 
/*
Intersection:
1) Initialize intersection I as empty.
2) Find smaller of m and n and sort the smaller array.
3) For every element x of larger array, do following
…….b) Binary Search x in smaller array. If x is present, then copy it to I.
4) Return I.
*/
void printIntersection(vector<int>& vect1, vector<int>& vect2)
{
 
    // Sort smaller array arr1[0..m-1]
    sort(vect1.begin(), vect1.end());
 
    // Search every element of bigger array in smaller array
    // and print the element if found
    for (int i=0; i<vect2.size(); i++)
		if(binary_search (vect1.begin(), vect1.end(), vect2[i]))
            cout << arr2[i] << " ";
}