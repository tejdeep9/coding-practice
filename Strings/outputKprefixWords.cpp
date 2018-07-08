#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
void k_PrefixWords(vector<string> vect,int k)
{
	unordered_map<string,list<string>> map;
	for(int i=0;i<vect.size();i++)
	{
		map[vect[i].substr(0,k)].push_back(vect[i]);
	}
	
	for (auto& x: map) 
	{
		if(x.second.size()>=2)
		{
			for(list<string>::iterator it=x.second.begin();it!=x.second.end();it++)
			 cout<<*it<<endl;
		}
	}

}
int main() {
	
	vector<string> vect;
	vect.push_back("algo");
	vect.push_back("also");
	vect.push_back("algorithm");
	vect.push_back("trie");
	vect.push_back("trying");
	vect.push_back("trump");
	vect.push_back("tea");
	vect.push_back("teak");
	vect.push_back("tiger");
	vect.push_back("lion");
	k_PrefixWords(vect,2);
	return 0;
}