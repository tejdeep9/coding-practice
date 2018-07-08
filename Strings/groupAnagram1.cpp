#include <utility>
#define NO_OF_CHARS 256
class Solution {
public:
    bool anagram(string str1, string str2)
    {
        int count1[NO_OF_CHARS] = {0};
        int count2[NO_OF_CHARS] = {0};
        int i;
     
        // For each character in input strings, increment count in
        // the corresponding count array
        for (i = 0; str1[i] && str2[i];  i++)
        {
            count1[str1[i]]++;
            count2[str2[i]]++;
        }
     
        // If both strings are of different length. Removing this
        // condition will make the program fail for strings like
        // "aaca" and "aca"
        if (str1[i] || str2[i])
          return false;
     
        // Compare count arrays
        for (i = 0; i < NO_OF_CHARS; i++)
            if (count1[i] != count2[i])
                return false;
     
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> result;
        bool added;
        for(int i=0; i < strs.size(); i++)
        {
            added=false;
            if(result.empty())
            {
                vector<string> s;
                s.push_back(strs[i]);
                result.push_back(s);
            }
            else
            {
                for(int j=0; j < result.size(); j++)
                {
                    if(!result[j].empty())
                    {
                        if(anagram(result[j][0],strs[i]))
                        {
                            result[j].push_back(strs[i]);
                            added=true;
                            break;
                        }
                    }
                }
                
                if(!added)
                {
                    vector<string> s;
                    s.push_back(strs[i]);
                    result.push_back(s);
                }
            }
            
        }
        
        return result;
        
        
    }
};

#include <utility>
#include <unordered_map>
#include <list>
#define NO_OF_CHARS 256
class Solution {
public:
    bool anagram(string str1, string str2)
    {
        int count1[NO_OF_CHARS] = {0};
        int count2[NO_OF_CHARS] = {0};
        int i;
     
        for (i = 0; str1[i] && str2[i];  i++)
        {
            count1[str1[i]]++;
            count2[str2[i]]++;
        }
     

        if (str1[i] || str2[i])
          return false;
     
 
        for (i = 0; i < NO_OF_CHARS; i++)
            if (count1[i] != count2[i])
                return false;
     
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
            
        unordered_map<int, vector<string>> map;
        vector<vector<string>> result;
        
        for(int i=0 ;i<strs.size(); i++)
        {
            if(map.find(strs[i].length())==map.end())
            {
                vector<string> samp;
                samp.push_back(strs[i]);
                map[strs[i].length()]=samp;
            }
            else
            {
                map[strs[i].length()].push_back(strs[i]);
            }
        }
        
        
        for(unordered_map<int, vector<string>>::iterator it=map.begin(); it!=map.end(); ++it)
        {
            vector<vector<string>> temp;
            bool added;
            for(int i=0; i< (*it).second.size(); i++)
            {
                added=false;
                if(temp.empty())
                {
                    vector<string> s;
                    s.push_back((*it).second[i]);
                    temp.push_back(s);
                }
                else
                {
                    for(int j=0; j<temp.size(); j++)
                    {
                        if(anagram(temp[j][0],(*it).second[i]))
                        {
                            temp[j].push_back((*it).second[i]);
                            added=true;
                            break;
                        }
                    }
                    if(!added)
                    {
                        vector<string> s;
                        s.push_back((*it).second[i]);
                        temp.push_back(s);
                    }
                }
                
            }
            
            for(int j=0; j<temp.size(); j++)
            {
                result.push_back(temp[j]);
            }
        }
        
        return result;
    }
};