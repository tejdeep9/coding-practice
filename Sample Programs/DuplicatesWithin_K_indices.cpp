#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*the idea is to add the element to the set till k elements return true if element is present
if the currrent ineds is more than k, remove first element in the set which is at i-k, which 
makes the set to have k elements at any time
*/

bool checkDuplicatesWithinK(vector<int> vect ,int k)
{
    unordered_set<int> set;
    
    for(int i=0; i<vect.size(); i++)
    {
        if(set.find(vect[i])!=set.end())
            return true;
        set.insert(vect[i]);
        
        if(i >= k)
            set.erase(vect[i-k]);
    
    }
    return false;
}
int main() {
	//vector<int> vect= {1, 2, 3, 4, 1, 2, 3, 4};
	vector<int> vect = {1, 2, 3, 1, 4, 5};
	cout<<checkDuplicatesWithinK(vect,3)<<endl;
	return 0;
}
