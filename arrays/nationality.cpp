#include <iostream>
#include <vector>
#include <ctime>  
using namespace std;
enum Country
{
	USA,
	CANADA,
	CHINA,
	INDIA,
	NONE
};
double getRandomNumber()
{
	srand (time(NULL));
	double num = (double) rand()/RAND_MAX;
	return num;
}

Country Binary_Search(vector<double>& cumDis, double num)
{
	int left= 0;
	int right = cumDis.size()-1;
	
	while(left < right)
	{
		int mid=(left+right)/2;
		
		if(mid > 0 && cumDis[mid] > num && cumDis[mid-1] <= num)
			return static_cast<Country>(mid);
		else if(mid == 0 && cumDis[mid] > num)
			return static_cast<Country>(mid);
		else if(num > cumDis[mid])
			 left=mid+1;
		else
			 right=mid-1;
	}
	
	if(left > 0 && cumDis[left] > num && cumDis[left-1] <= num)
			return static_cast<Country>(left);
	else if(left == 0 && cumDis[left] > num)
			return static_cast<Country>(left);
};

Country FindNationality(vector<int>& population) 
{
	if(population.empty())
		return NONE;
	int total=0;
	for(auto& x: population)
		total+=x;

	
	vector<double> cumDis;
	
	double min=0; 
	for(auto & x: population)
	{
	    double val= ((double)x/total)+min;
		cout<<val<<' ';
		cumDis.push_back(val);
		min=val;
	}
	cout<<endl;
	double randomNumber = getRandomNumber();
	cout<<randomNumber<<endl;
	
	return Binary_Search(cumDis,randomNumber);
}

int main ()
{
	vector<int> population = {1000,2000,3000,4000};
	Country c=FindNationality(population);
	
	if(c == USA)
		cout<<"USA"<<endl;
	else if(c == CANADA)
		cout<<"CANADA"<<endl;
	else if(c == INDIA)
		cout<<"INDIA"<<endl;
	else if(c == CHINA)
		cout<<"CHINA"<<endl;
	else
		cout<<"NONE"<<endl;
	return 0;
}