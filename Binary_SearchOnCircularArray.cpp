#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class CircularArray
{
	vector<int> arr;
	int start;
	public:	
	CircularArray() { start =-1;}
    
	// linear complexity
	void insert(int num)
	{
		if(arr.empty())
		{
			arr.push_back(num);
			start=0;

		}
		else
		{
			int prev=-1;
			int next=start;
			
			 while(arr[next] > num )
			{
				prev=next;
				next = (prev+1)% arr.size();
				if(next==start || arr[prev] > arr[next])
					break;

			}
			
			while(arr[next] <= num )
			{
				prev=next;
				next = (prev+1)% arr.size();
				if(next==start || arr[prev] > arr[next])
					break;

			}

			vector<int>::iterator it=arr.begin();
			advance(it,next);
			arr.insert(it,num);
		}
	}
	int Binary_search(int left, int right, int num)
	{
		int left=start;
		if(left < 0)
			return left;
		int right = arr.size()-1;
		
		while(left < right)
		{
			int mid =(left +right)/2;
			if(arr[mid] == num)
				return mid;
			else if (arr[mid]>num)
				right = mid-1;
			else
				left= mid+1;
		}
		if(arr[left]==num)
			return left
		else
			return -1;
	}
	int findPivot()
	{
		int left=start;
		if(left <0)
			return left;
		int right =arr.size()-1;
		int low=0;
		int high=right;
		while(left <right)
		{
			int mid= (left+right)/2;
			if( mid >0 && arr[mid] < arr[mid-1])
				return mid-1;
			else if(arr[mid] > arr[low])
				left =mid+1;
			else
				right =mid-1;
		}
		
		if(left >0 && arr[left] < arr[left-1])
			return left;
		else
			return -1;
	}
    
	int PivotedSearch(int num)
	{
		int pivot= findPivot();
		if(pivot < 0)
			return Binary_search(0,arr.size()-1, num);
		
		int l = Binary_search(0,pivot, num);
		int r= Binary_search(pivot+1,arr.size()-1, num);
		
		if(l >0)
			return l;
		else
			return r;
		
	}
	void Display()
	{
		for(auto& num: arr)
			cout<<num<<'\t';
		cout<<endl;
	}
	
	int getRandIndex()
	{
		srand(time(NULL));
		if(arr.empty())
			return -1;
		if(arr.size()==1)
			return 0;
		int index = (double)rand()/arr.size();
		return index;
	}

};


int main()
{
	CircularArray arr;
	arr.insert(5);
	arr.insert(6);
	arr.insert(7);
	arr.insert(1);
	arr.insert(2);
	arr.insert(3);
	arr.insert(12);
	arr.Display();
	cout<<PivotedSearch(12)<<endl;
	return 0;
}