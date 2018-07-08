#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class TrieNode
{
public:
	char elem;
	int wordCount;
	int prefixCount;
	unordered_map<char, TrieNode*> characterMap;
	unordered_set<string> wordSet;

	TrieNode(char elem = ' ')
	{
		this->elem = elem;
		prefixCount = 0;
		wordCount = 0;
	}
};

class Trie
{
public:
	TrieNode* root;

	Trie()
	{
		root = new TrieNode('\0');
	}

	void addWord(string word)
	{
		if (word.empty())
			return;

		TrieNode* current = root;
		int length = word.length();
		for (int i = 0; i<word.length(); i++)
		{
			//check whether the node has character
			if (current->characterMap.find(word[i]) != current->characterMap.end())
			{
				//check whether the set has word;
				if (current->wordSet.find(word.substr(i, length - i)) == current->wordSet.end())
				{
					current->wordSet.insert(word.substr(i, length - i));
				}
				current = current->characterMap[word[i]];
				current->prefixCount++;
			}
			else
			{
				current->characterMap[word[i]] = new TrieNode(word[i]);
				//current->prefixCount++;
				//adding word to the wordSet
				current->wordSet.insert(word.substr(i, length - i));
				current = current->characterMap[word[i]];
				current->prefixCount++;
			}
		}
		current->wordCount++;
	}

	unordered_set<string> autoComplete(string prefix)
	{
		unordered_set<string> words;
		if (prefix.empty())
			return words;

		TrieNode* current = root;

		for (int i = 0; i<prefix.length(); i++)
		{
			if (current->characterMap.find(prefix[i]) != current->characterMap.end())
			{
				current = current->characterMap[prefix[i]];
			}
			else
				return words;
		}
		words = current->wordSet;
		return words;
	}

};

int main() {
	Trie t;

	t.addWord("san franciso");
	t.addWord("san bernadio");
	t.addWord("san antanio");
	t.addWord("santa clara");
	t.addWord("newyork");
	t.addWord("houston");

	string prefix;
	getline(cin, prefix);

	unordered_set<string> words = t.autoComplete(prefix);

	for (unordered_set<string>::iterator it = words.begin(); it != words.end(); ++it)
	{
		string complete = prefix + *it;
		cout << complete << endl;
	}
	return 0;
}