#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string makeSentence(string& str, unordered_set<string>& dict)
{
	string temp = "";
	if (str.compare(" ") == 0)
		return temp;
	vector<string> output;
	for (int i = 0; i<str.length(); i++)
	{
		if (str[i] == ' ')
			continue;
		else
		{
			temp.push_back(str[i]);
			//if you find the word in the dictionary
			if (dict.find(temp) != dict.end())
			{
				output.push_back(temp);
				temp.erase(temp.begin(),temp.end());
			}
		}

	}

	string result = "";
	for (int i = 0; i<output.size(); i++)
	{
		if (i == output.size() - 1)
			result += output[i];
		else
			result += output[i] + " ";
	}

	return result;
}
int main()
{
	//string str = "theskyisblue";
	string str="thegrassisgreen";
	unordered_set<string> set;
	set.insert("the");
	set.insert("is");
	set.insert("sky");
	set.insert("green");
	set.insert("grass");
	set.insert("blue");
	cout << makeSentence(str, set) << endl;
	return 0;
}
