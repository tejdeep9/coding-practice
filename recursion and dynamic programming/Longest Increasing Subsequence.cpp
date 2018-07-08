#include <iostream>
#include <algorithm>
using namespace std;


//optimal subproblem LIS(i)= {1+max(LIS(j))} where for all j<i, return max(LIS[i)).
//Time Complexity: exponential.
int LIS_driver(int* arr, int n, int& lis)
{
    //base case for the recursion
    if(n == 0)
        return 0;
    
    int res; //store the lis for each iteration.
    int current_max=1; //used to store the current max lis for the given element as the last
    
    for(int i=1; i<n; i++)
    {
        res=LIS_driver(arr,i,lis); //get the LIS for the ith position as the last element
        
        if(arr[i-1] < arr[n-1] ) 
        {
            //As the ith element is less than the given last element last element will be in the result set, so +1
            res=res+1; 
            if(res > current_max) 
                current_max=res;  //update the current max      
        }
    }
    
    //finally the if the current_max is more than the overall LIS update it.
    if( lis < current_max)
        lis=current_max;
        
    return current_max; //maxmimum possible LIS for the array of given length
}

int LIS_recur(int* arr, int n )
{
    int lis=1;
    
    LIS_driver(arr,n,lis);
    return lis;
}

//Time Complexity: O(n2)
int LIS_DP(int* arr, int n)
{
    //base case
    if(n ==1 )
        return 1;
     int dp[n];  
     
    //initialize the given array with the value 1 every element is LIS of length 1
    for(int i=0; i<n; i++)
        dp[i]=1;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if( arr[j] < arr[i] &&  dp[j]+1 > dp[i])
                dp[i]= dp[j]+1;
        }
    }
    
    int max=1;
    //iterate throguh the dp array to get the maximum LIS in the array.
    for(int i=0; i<n; i++)
    {
        if(max < dp[i])
            max=dp[i];
    }
    
    return max;
}
int main() {
	
	int arr[]={10,22,9,33,21,41,60,80};
	//int arr[]={3,4,-1,0,6,2,3};
	int n= sizeof(arr)/sizeof(int);
	//cout<<LIS_recur(arr,n)<<endl;
	cout<<LIS_DP(arr,n)<<endl;
	return 0;
}
