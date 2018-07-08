#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int>& a, vector<int>& b)
{
    int m=a.size();
    int n=b.size();
    
    int i=0, j=0;
    vector<int> result;
    
    while( i<m && j<n)
    {
        if(a[i] < b [j])
        {
            result.push_back(a[i]);
            i++;
        }
        else
        {
            result.push_back(b[i]);
            j++;
        }
    }
    
    while( i < m)
    {
        result.push_back(a[i]);
        i++;
    }
    
    while(j<n)
    {
        result.push_back(b[j]);
        j++;
    }
    
    return result;
}

int main() {

	vector<int> a={5,10,15};
	vector<int> b={2,3,20};

	vector<int> result=merge(a,b);
	for(auto &x: result)
	{
	    cout<<x<<" ";
	}
	return 0;
}
