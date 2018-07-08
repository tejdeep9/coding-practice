struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) 
{
	ListNode* result= new ListNode(0);
	ListNode* current=result;
	while(true)
	{
		if(l1==nullptr)
		{
			current->next=l2;
			break;
		}
		else if(l2 == nullptr)
		{
			current->next=l1;
			break;
		}
		else if( l1->val <= l2->val)
		{
			current->next=l1;
			l1=l1->next
		}
		else
		{
			current->next=l2;
			l2=l2->next;
		}
		current=current->next;
	}
	return result->next;
}

//with recursion
ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) 
{
	ListNode* result=nullptr;
	if(!l1)
		return l2;
	if(!l2)
		return l1;
	if(l1->val <= l2->val)
	{
		result=l1;
		result->next=mergeTwoLists(l1->next, l2); 
	}
	else
	{
		result=l1;
		result->next=mergeTwoLists(l1, l2->next); 
	}
	
	return result;
}