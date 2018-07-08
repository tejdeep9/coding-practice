public int MaxSubArray(vect<int> nums) 
{
	if (nums.size() == 0) return 0;
	if (nums.size() == 1) return nums[0];
	
	int array[nums.size()] ={0};
	array[0] = nums[0];
	int maxElem = array[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (array[i-1] < 0) 
		{
			array[i] = nums[i]; //if the previous sum is negative start again from current  number
		}
		else 
		{
			array[i] = array[i-1] + nums[i];
		}
		maxElem = max(maxElem, array[i]);
	}
	return maxElem;
}
	
	/*
	array         DP= prev Sum +Last elem      sum
	3              3                            3
	3,-2           3+ -2   						1
	3, -2, 5       1+ 5    						6
	3, -2, 5, -1   6+ -1   						5  