#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/* 

dir1
	dir11
	dir12
		picture.jpg
		dir121
		file1.txt
dir2
	file2.gif
	dir21
		dir211
			file3.gif

Sample input: dir1\n dir11\n dir12\n  picture.jpeg\n  dir121\n  file1.txt\ndir2\n file2.gif\n dir21\n  dir211\n   file3.gif
*/
Time Complexity: O(n)
Space Complexity: less than O(n)

void getPath(int& prevLevel, int& level, string& path, string& temp, size_t& maxLength)
{
	if (prevLevel != 0 && prevLevel >= level)
	{
		int index = path.length();
		for (int j = path.length(); j >= 0 && prevLevel >= level; j--)
		{
			if (path[j] == '/')
			{
				index = j;
				prevLevel--;
			}

		}
		path.erase(index, path.length() - index);
	};
	if (!temp.empty())
	{
		string entry = "/" + temp;
		path += entry;
	}

	if (temp.find('.') != string::npos) //file name
	{
		if (temp.find(".gif") != string::npos || temp.find(".png") != string::npos || temp.find(".jpeg") != string::npos) //image file
		{
			maxLength = max(maxLength, path.length());
		}
	}

	temp.clear();
	prevLevel = level;
	level = 0;
}
//longest abosulte path for the inage file
int solution(string str) {

	string temp;
	string path;
	size_t maxLength = 0;
	int prevLevel = 0;
	int level = 0;
	for (int i = 0; i<str.length(); i++)
	{
		if (str[i] != '\n' && str[i] != ' ')
		{
			temp.push_back(str[i]); //loading the file name
		}
		else if (str[i] == ' ')
		{
			level++;
		}
		else if (str[i] == '\n')
		{
			getPath(prevLevel, level, path, temp, maxLength);
		}
	}
	if(!temp.empty())
		getPath(prevLevel, level, path, temp, maxLength);
	return maxLength;
}




int main()
{

	//string str = "dir1\n dir11\n dir12\n  picture.jpeg\n  dir121\n  file1.txt\n dir2\n  file2.gif";
	string str = "dir1\n dir11\n dir12\n  picture.jpeg\n  dir121\n  file1.txt\ndir2\n file2.gif\n dir21\n  dir211\n   file3.gif";
	cout << solution(str) << endl;
	return 0;
}
