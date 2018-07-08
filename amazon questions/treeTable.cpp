#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
using namespace std;

//Time Complexity : nlogn
void findTypeOfNode(unordered_map<int,int>& table)
{
    unordered_set<int> Id;  //ids of the nodes
    unordered_set<int> Pid; //ids of the parent set
    
    map<int,string> result;
    for(auto& n: table)
    {
        int key=n.first;
        if(n.second == 0) //no parent
        {
            result[n.first]="Root";
            continue;
        }
        Id.insert(n.first);
        Pid.insert(n.second);
        
    }
    
    //check whether the node is parent
    for(auto& n: Id)
    {

        if(Pid.find(n) == Pid.end()) //if the node is not the parent the node is leaf node
        {
            result[n]="Leaf";
        }
        else
        {
            result[n]="Inner";
        }
    }
    
    for(auto& n: result)
    {
        cout<<n.first<<':'<<n.second<<endl;
    }
    
}

int main() 
{
    
    //sample tree for test
    //          1
    //        /   \
    //      2       3
    //    /  \     /  \
    //   4    5   6    7
    // /  \  
    //8    9 
    
    unordered_map<int,int> table;
    
    table[1]=0;
    table[2]=1;
    table[3]=1;
    table[4]=2;
    table[5]=2;
    table[6]=3;
    table[7]=3;
    table[8]=4;
    table[9]=4;
    
    findTypeOfNode(table);
	return 0;
}
