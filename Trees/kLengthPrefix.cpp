#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class TrieNode
{
	public:
		char elem;
		int prefixCount;
		int wordCount;
		unordered_map<char,TrieNode*> characterMap;
		
		TrieNode(char elem=' ')
		{
			this->elem=elem;
			prefixCount=0;
			wordCount=0;
		}
};

class Trie
{
	public:
	
	TrieNode* root;
	
	Trie()
	{
		root=new TrieNode('\0');
	}
	
	void addWord(string word)
	{
		if(word.empty())
			return;
		
		TrieNode* current= root;
		
		for(int i=0; i<word.length(); i++)
		{
			if(current->characterMap.find(word[i])!=current->characterMap.end())
			{
				current=current->characterMap[word[i]];
				current->prefixCount++;
			}
			else
			{
				current->characterMap[word[i]]=new TrieNode(word[i]);
				current=current->characterMap[word[i]];
				current->prefixCount++;
			}
		}
		
		current->wordCount++;
	}
	
	void kLengthPrefixes(int k)
	{
		unordered_set<string> result;
		unordered_set<string> set;
		if(k<=0 || root== NULL)
			return ;	
		string prefix="";
		//call dfs
		dfs(k+1,result, root, prefix);
		
		for(unordered_set<string>::iterator it=result.begin(); it!=result.end(); ++it)
		{
			int len=(*it).length();
			for(int i=1; i<=len; i++)
			{	
				string temp=(*it).substr(0,i);
				if(set.find(temp)==set.end())
				{
					cout<<temp<<endl;
					set.insert(temp);
				}
			}
		}
	
	}
	
	void dfs(int k, unordered_set<string>& result, TrieNode* node, string prefix)
	{

		if(node->elem!='\0')
			prefix.push_back(node->elem);
			
		if(k==1)
		{
			result.insert(prefix);
			return;
		}
		else if(node->wordCount>0)
		{
			result.insert(prefix);
		}

		
		for(unordered_map<char, TrieNode*>::iterator it=node->characterMap.begin(); it!=node->characterMap.end(); ++it)
		{
			dfs(k-1,result,it->second,prefix);
		}
		
	}
		
};
int main() {
	
	Trie t;
	t.addWord("apple");
	t.addWord("applet");
	t.addWord("apetizer");
	t.addWord("aroma");
	t.addWord("arrogant");
	t.addWord("trie");
	t.addWord("trump");
	t.addWord("text");
	t.addWord("tree");
	t.addWord("newyork");
	t.addWord("houston");
	
	t.kLengthPrefixes(3);
	return 0;
}