#include <iostream>
using namespace std;

bool coprimes(int num1, int num2)
{
    while(num2!=0)
    {
        int temp=num2;
        num2 = num1%num2;
        num1 = temp;
    }
    return num1 == 1;
}

int main() {
	cout<<coprimes(21,24)<<endl;
	return 0;
}
