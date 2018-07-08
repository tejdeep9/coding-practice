    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int n=lists.size();
        if(n==0)
            return NULL;
        if(n==1)
            return lists[0];
            
        return partition(lists, 0, n-1);
    }
    
    ListNode* partition(vector<ListNode*>& lists,int start,int end)
    {
        if(start==end)
            return lists[start];
        int mid=(start+end)/2;
        ListNode* l1=partition(lists, start, mid);
        ListNode* l2=partition(lists, mid+1, end);
        return merge(l1, l2);
    }
    
    ListNode* merge( ListNode* l1, ListNode* l2)
    {
        if(l1==NULL && l2==NULL)
            return NULL;
        if(l2==NULL)
            return l1;
        if(l1==NULL)
            return l2;
        
     
        ListNode* current = new ListNode(0);
        ListNode* head=current;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                current->next=l1;
                l1=l1->next;
            }
            else
            {
                current->next=l2;
                l2=l2->next;
            }
            current=current->next;
        }
        
        if (l1 != NULL)
            current->next = l1;
        else
            current->next = l2;
        
        head=head->next;
        return head;
        
    } 