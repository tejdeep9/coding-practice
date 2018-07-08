#include <iostream>
#include <vector>

using namespace std;

class MinStack {
private:
    vector<int> vect;
    vector<int> minVect;
public:
    void push(int x) {
        
        vect.push_back(x);
        if(minVect.empty())
            minVect.push_back(x);
        else
        {
            int min=minVect.back();
            if(x<min)
                min=x;
            minVect.push_back(min);
        }
        
    }

    void pop() {
        vect.pop_back();
        minVect.pop_back();
    }

    int top() {
        return vect.back();
    }

    int getMin() {
        return minVect.back();
    }
};

int main()
{
	MinStack s;
	s.push(2);
	s.push(0);
	s.push(3);
	s.push(0);

	cout << s.getMin() << endl;
	s.pop();
	cout << s.getMin() << endl;
	s.pop(); 
	cout << s.getMin() << endl; 
	s.pop(); 
	cout << s.getMin() << endl;

	return 0;
}