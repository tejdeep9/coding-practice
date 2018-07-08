#include <iostream>
using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    if(head==NULL)
        return NULL;
    ListNode* temp1=head;
    ListNode* temp2=head;
    int i=0;
    for( i=0;i<n-1 && temp2->next!=NULL;i++)
    {
        temp2=temp2->next;
    }
	if(i!=n-1)
		return NULL;
    ListNode* prev=head;
    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
        prev=temp1;
        temp1=temp1->next;
    }
    
    if(temp1==head)
    {
        head=head->next;
        delete temp1;
    }
    else
    {
        prev->next=temp1->next;
        delete temp1;
    }
    
    return head;
    
}

void Display(ListNode* head)
{
	while (head != NULL)
	{
		cout << head->val << '\t';
		head = head->next;
	}
	cout << endl;
}
int main()
{
	ListNode* head = NULL;
	head = new ListNode(1);
	head->next = new ListNode(2);
	Display(head);
	head = removeNthFromEnd(head, 1);
	Display(head);
	return 0;
}