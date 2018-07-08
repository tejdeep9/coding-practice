class Graph
{
    private:
        unordered_set<char> vertices;
        unordered_map<char, unordered_set<char>> map;
        char firstVertex;
        bool set;
        
        void DFSUtil(char u, stack<char>& s,unordered_set<char>& visited)
        {
            visited.insert(u);
            unordered_set<char>::iterator v;
            
            for(v=map[u].begin(); v!=map[u].end(); ++v)
            {
                if(visited.find(*v)==visited.end())
                {
                    DFSUtil(*v,s, visited);
                }
            }
            
            s.push(u);
        }
    public:
        Graph()
        {
            set=false;
        }
        void addVertex(char v)
        {
            if(vertices.find(v)==vertices.end())
                vertices.insert(v);
            if(!set)
                firstVertex=v;
        }
        void addEdge(char v, char w)
        {
            if(!set)
                firstVertex=v;
            if(vertices.find(v)==vertices.end())
                vertices.insert(v);
            if(vertices.find(w)==vertices.end())
                vertices.insert(w);
            if(map[v].find(w)==map[v].end())
                map[v].insert(w);
        }
        
        string DFS()
        {
            unordered_set<char> visited;
            unordered_set<char>::iterator u;
            
            string result="";
            stack<char> s;
            for(u=vertices.begin(); u!=vertices.end(); ++u)
            {
                if(visited.find(*u)==visited.end())
                {
                    DFSUtil(*u,s, visited);
                }
                
            }
            while(!s.empty())
            {
                result=result+s.top();
                s.pop();
            }
            return result;
        }
};


class Solution {
public:
    void findMinMax(int& minLen, int& maxLen, string& minWord, string& maxWord)
    {
        if(minWord.length()<=maxWord.length())
        {
            minLen=minWord.length();
            maxLen=maxWord.length();
        }
        else
        {
            minLen=maxWord.length();
            maxLen=minWord.length();
            //swap
            string temp=maxWord;
            maxWord=minWord;
            minWord=temp;
            
        }
    }
    string alienOrder(vector<string>& words) 
    {
        Graph g;
        int numOfWords=words.size();
        for(int i=1; i<numOfWords; i++)
        {   
            //iterate through each word
            int minLen=0,maxLen=0;
            string minWord=words[i-1],maxWord=words[i];
            
            findMinMax(minLen,maxLen, minWord, maxWord);
            int j=0;
            for(j=0; j<minLen; j++)
            {
                if(words[i][j] != words[i-1][j] )
                {
                    g.addEdge(words[i-1][j],words[i][j] );
                }
                else
                    g.addVertex(words[i][j]);
            }
            
            for(int x=j;x<maxLen; x++)
            {
                g.addVertex(maxWord[x]);
            }
        }
        
        

        
 /*       for(int i=0; i<numOfWords; i++)
        {
            //iterate through each word
            int len=words[i].length();
            for(int j=1; j<len; j++)
            {
                if(words[i][j]!=words[i][j-1])
                {
                    g.addEdge(words[i][j-1],words[i][j] );
                }
            }
        }
*/
        
        return g.DFS();
    }
};

