#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int>& arr, int N) {
    int i;

    i = N;
    while (i!=0) {
    	i--;
        N ^= i ^ arr[i];
   
    }

    return N;
}

int main() {
	int arr[]={0, 1,2, 3, 4,9,5,7,6};
	vector<int> vect;
	vect.assign(arr,arr+9);
	int N=9;
	cout<<findMissingNumber(vect,N)<<endl;
	return 0;
}