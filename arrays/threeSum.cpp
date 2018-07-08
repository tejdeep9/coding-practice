#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

/* time complexity -O(n2) */
vector<vector<int>> threeSum_optimized(vector<int>& nums) 
{
	sort(nums.begin(),nums.end());
	vector<vector<int>> result;
	int n=nums.size();
	
	for(int i=0;i<n-2;i++)
	{
		int left=i+1, right =n-1;
		int target=-nums[i];
		
		if(i!=0 && nums[i]==nums[i-1])
			continue;
		
		while(left<right)
		{
			if(nums[left]+nums[right]==target)
			{
				vector<int> temp;
				temp.push_back(nums[i]);
				temp.push_back(nums[left]);
				temp.push_back(nums[right]);
				result.push_back(temp);
				
				while(left<right && nums[left]==nums[left+1])
				 ++left;
				while(left<right && nums[right]==nums[right-1])
				 --right;
				 
				++left;
				--right;
			}
			else if(nums[left]+nums[right]<target)
				++left;
			else
				--right;
		}
	}
	
	return result;
}

/*
O(n2): complexity.
*/
vector<vector<int>> threeSum(vector<int>& nums) {
    
    vector<vector<int>> result;
    set<string> uniqueResult;
    for(int i=0;i<nums.size();i++)
    {   
        vector<int> temp;
        int target=nums[i]*-1;
        unordered_map<int,int> map;
        
        for(int j=0;j<nums.size();j++)
        {
            if(i==j)
                continue;
            else
            {
                if(map.find(nums[j])!=map.end())
                {
                    int arr[]={nums[i],nums[j],map[nums[j]]};
                    temp.assign(arr,arr+3);
                    sort(temp.begin(),temp.end());
                    string s=to_string(temp[0])+','+to_string(temp[1])+','+to_string(temp[1]);
                    if(uniqueResult.find(s)==uniqueResult.end())
                    {
                    	result.push_back(temp);
                    	uniqueResult.insert(s);
                    }
                }
                else
                {
                    map[target-nums[j]]=nums[j];
                }
            }
        }
    }
    
    return result;
}

int main() {
	int S[] = {-1, 0 ,1 ,2 ,-1 ,-4};
	vector<int> vect;
	vect.assign(S,S+6);
	vector<vector<int>> res=threeSum(vect);
	for(int i=0; i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<'\t';
		cout<<endl;
	}
	return 0;
}