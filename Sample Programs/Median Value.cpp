#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*
 we can use a max heap on left side to represent elements that are less than effective median, and a min heap on right side to represent elements that are greater than effective median.

After processing an incoming element, the number of elements in heaps differ utmost by 1 element. When both heaps contain same number of elements, we pick average of heaps root data as effective median. 
When the heaps are not balanced, we select effective median from the root of heap containing more elements.
*/

double MedianValue(vector<int> vect)
{
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    
    for(auto &x: vect)
    {
        maxHeap.push(x);
        
        if(maxHeap.size() == minHeap.size())
        {
            if(!minHeap.empty() && maxHeap.top() > minHeap.top())
            {
                int t1=maxHeap.top();
                int t2= minHeap.top();
                maxHeap.pop();
                minHeap.pop();
                maxHeap.push(t2);
                minHeap.push(t1);
            }
        }
        else
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    if(maxHeap.size() == minHeap.size())
        return (double)(maxHeap.top()+minHeap.top())/2;
    else
       return minHeap.top();
}
int main() {
	vector<int> vect= {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
	cout<<MedianValue(vect);
	return 0;
}
