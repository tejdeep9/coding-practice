#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <unordered_map>

using namespace std;

class myDS{
	private:
		vector<int> vect;
		unordered_map<int, int> map;
	public:
		void add(int num)
		{
			if(map.find(num)!=map.end())
				return;
			vect.push_back(num);
			int size=vect.size()-1;
			map[num]=size;
		}
		
		void remove(int num)
		{
			if(map.find(num)==map.end())
				return;
			int index=map[num];
			map.erase(num);
			int last=vect[vect.size()-1];
			swap(vect[index],vect[vect.size()-1]);
			vect.pop_back();
			map[last]=index;
			
		}
		
		int getRandom()
		{
			srand(time(NULL));
			int index=rand()%(vect.size()-1);
			return vect[index];
		}
		
		
};
int main() {
	// your code goes here
	return 0;
}