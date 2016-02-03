#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;
int lru_implementation(int cache_size, int* pages, int page_size)
{
	list<int> cache;
	unordered_map<int, list<int>::iterator> map;
	int page_hit = 0;
	for (int i = 0; i<page_size; i++)
	{
		if (map.count(pages[i]) == 0) //miss
		{
			if (cache.size() == cache_size)
			{
				//remove the last element in the cache
				list<int>::iterator it = next(cache.end(), -1);
				map.erase(*it);
				cache.erase(it);
			}
			cache.push_front(pages[i]);
			map[pages[i]] = cache.begin();
		}
		else //hit
		{
			list<int>::iterator it = map[pages[i]];
			cache.erase(it);
			cache.push_front(pages[i]);
			map[pages[i]] = cache.begin();
			page_hit++;
		}

	}

	for (list<int>::iterator it = cache.begin(); it != cache.end(); ++it)
		cout << *it << '\t';

	cout << endl;
	return page_hit;
}

int main() {

	//int  pages[] = {2,3,1,3,2,1,4,3,2};
	//case 1
	//int  pages[]= {1,2,3,4,1,2,5,1,2,3,4,5};
	int  pages[] {4, 7, 0, 7, 1, 0, 1, 2, 1, 2, 7};
	int cacheSize = 5;
	cout << "The number of page hits are " << lru_implementation(cacheSize, pages, 11)<<endl;

	return 0;
}