#include <iostream>
#include <vector>
using namespace std;

/*
The idea is simple. Count how many times does every number appear in every position using the most significant digits and using the least significant digits and itself. 
The 0 should be corrected as it could not be the most significant digit.

For example:
n = 209
for the units:
0 to 9 will appear 20 times (from 00 to 19 inclusive) + 1 more time for 20 
for the tens:
0 to 9 will appear 2 times * 10 (from 0 to 1 inclusive) + (9+1) more times for 0
for the hundreds:
0 to 9 will appear 0 times * 100 (from 0 to 0) + 1 more time *100 for 0 and 1 - 100 for 0 + (9+1) times for 2
*/

//https://www.careercup.com/question?id=5627710193795072
void numberOfDigits_opt(int num)
{
	int n=num, factor=1;
	vector<int> digits;
 
	//load all the values to zero.
	for(int i=0; i<10; i++)
		digits.push_back(0);
 
	while( n>0 )
	{
		int current_digit= n%10; //goes from unit place to the high significant place
		for(int i=0; i<10; i++)
		{
			//units place:incase of 209 0->9 occurs 20 times(209/10 =20)
			//tens place; incase of 209 0->9 occurs 2(20/10)* (factor=10) times
			digits[i]+= (n/10)* factor;
			//for example in 209 0->9 occurs 1 time from 200 to 209
			//in case of tenths place 0 (current_digit=0) occurs 10 times 
			if(i < current_digit)
				digits[i]+=1*factor;
		}
		//need to think with other example
		digits[current_digit]+=(num%factor)+1;
		if(factor > 1) //get rid of higher significant zeros
			digits[0]-=factor;
 
		n/=10;
		factor*=10;
 
	}
 
	for(int i=0; i<digits.size(); i++)
		cout<<i<<","<<digits[i]<<endl;
 
};

//naive solution time complexity: O(n* floor(log10(n)+1) )
vector<int> numberOfDigits_naive(int num)
{
    vector<int> result;
    
    for(int i=0; i<=9; i++)
        result.push_back(0);
        
    for(int i=1; i<=num; i++)
    {
        int n=i;
        
        while(n!=0)
        {
            result[n%10]++;
            n=n/10;
        }
    }
    
    return result;
}

int main() {
	numberOfDigits_opt(323);
	
	return 0;
}
