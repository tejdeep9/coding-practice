#include <iostream>
#include <ctime>
using namespace std;

int main() {
	srand(time(NULL)); //initializes with time value which is long that changes every second
	double r = ((double) rand() / (RAND_MAX));
	cout<<r<<endl;
	/* generate secret number between 1 and 10: */
  	//rand() % 30 + 1985;   // v3 in the range 1985-2014 
	 int  i = rand() % 10 + 1;
	  cout<<i<<endl;
	return 0;
}
//********************** Bigger number to the smaller number ******************************************************
//simulate R(10) => R(7) , get the value from 1 to 10 and map [1 to 5 ] and [6 to 10] to [1 to 5] as 10 is multiple of 5
//if R(13) => R(5) neglect 11, 12, 13 and map  [1 to 10 ] to [ 1 to 5]
/*

	if(m > n) R(m) => R(m-m%n) => R(n)

//********************** smaller number to the bigger number ******************************************************
/* R(5) =>R(7) how to do it?
  use R(5) twice to get the values randing from 1 to 25 =R(5) * R(5) => R(25) map [1 to 21] to [1 to 7] and neglect remaining
  
  R(5)=> R(135) : R(5) => R(25) => R(125) => R(625) then simulate R(137)
  
  m < n
  m^(k-1) < n < m^k  the R(m) => R(m^k) => R(m)
  