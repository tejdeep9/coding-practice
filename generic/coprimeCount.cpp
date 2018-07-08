#include <iostream>
#include <vector>
using namespace std;

int getCount(int num)
{
	float res=num;
	
	for(int i=2; i*i<=num;i++)
	{
		if(num%i==0)
		{
			while(num%i==0)
			num=num/i;
			res=res*(1.0-(1.0/(float)i));
		}
		
	}
	
	if(num>1)
	res=res* (1.0-(1.0/(float)num));
	
	return (int) res;
}

vector<int> coprimeCount(vector<int>& vect)
{
	vector<int> result;
	for(int i=0;i<vect.size(); i++)
	{
		result.push_back(getCount(vect[i]));
	}
	
	return result;
}

int* coprimeCount(int* A ,int n)
{
	int* B =new int[n];
	
	for(int i=0 ;i<n; i++)
		B[i]=getCount(A[i]);
		
	return B;
}

int main() {
	
	int A[]={5,6,3,8,9,6};
	int n=extent<decltype(A)>::value;
	for(int i=0;i<n;i++)
		cout<<A[i]<<'\t';
	cout<<endl;
	int* B=coprimeCount(A ,n);
	
	vector<int> vect;
	vect.assign(A,A+n);
	for(int i=0;i<n;i++)
		cout<<B[i]<<'\t';
	cout<<endl;
	
	vector<int> result=coprimeCount(vect);
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<'\t';
	cout<<endl;
	
	delete B;
	return 0;
}