#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


//time complexity: O(n)
void verifyItems(vector<string>& origItems, vector<double>& origPrices, vector<string>& items, vector<double>& prices)
{
    int deceiveCount=0;
    unordered_map<string,double> inventoryItems;
	unordered_map<string,double> soldItems;
    //storing the information of the inventory items and their price
    for(int i=0 ;i < origItems.size(); i++)
    {
        inventoryItems[origItems[i]] = origPrices[i];
    }
	
    //storing the information of the sold items and their price
    for(int i=0 ;i < items.size(); i++)
    {
        soldItems[items[i]] = prices[i];
    }
    
    //iterate through the sold items and see the difference from actual price to the sold price
    for(int i=0; i < items.size(); i++)
    { 
        if( inventoryItems[items[i]]  != soldItems[items[i]])
            deceiveCount++;
    }
    
    cout<<deceiveCount<<endl;
}

