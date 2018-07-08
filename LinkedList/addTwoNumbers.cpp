#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
ListNode* getResultNode(ListNode* l1,ListNode* l2,int& carry, ListNode* result)
{
    int sum,val1,val2;
    if(l1==NULL)
      val1=0;
    else
      val1=l1->val;
    if(l2==NULL)
      val2=0;
    else
      val2=l2->val;
    
    sum= val1+val2+carry;
    carry=sum/10;
    ListNode* temp=new ListNode(sum%10);
    if(result==NULL)
        result=temp;
    else
    {
        result->next=temp;
        result=result->next;
    }
    return result;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    if(l1==NULL && l2==NULL)
        return NULL;
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    
    ListNode* result=NULL,* head= NULL;
    int sum=0; int carry=0; 
    
    while(l1->next!=NULL && l2->next!=NULL)
    {
        if(head==NULL)
        {
            sum= l1->val+l2->val;
            carry=sum/10;
            ListNode* temp=new ListNode(sum%10);
            head=temp;
            result=head;
        }
        else
        {
            result=getResultNode(l1,l2,carry,result);
        }

        l1=l1->next;

        l2=l2->next;
    }
    
    if(l1->next==NULL && l2->next==NULL)
    {   
        if(head)
            result=getResultNode(l1,l2,carry,result);
        else
        {
            result=getResultNode(l1,l2,carry,result);
            head=result;
        }
        if(carry==1)
        {
            ListNode* temp2=new ListNode(1);
            result->next=temp2;
        }
    }
    else if(l1->next==NULL)
    {
        if(head)
            result=getResultNode(l1,l2,carry,result);
        else
        {
            result=getResultNode(l1,l2,carry,result);
            head=result;
        }
         
         l2=l2->next;
         l1=l1->next;
         while(l2!=NULL)
         {
            result=getResultNode(l1,l2,carry,result);
            l2=l2->next;
         }
         
        if(carry==1)
        {
            ListNode* temp2=new ListNode(1);
            result->next=temp2;
        }
         
    }
    else
    {
        if(head)
            result=getResultNode(l1,l2,carry,result);
        else
        {
            result=getResultNode(l1,l2,carry,result);
            head=result;
        }

         l2=l2->next;
         l1=l1->next;
         while(l1!=NULL)
         {
            result=getResultNode(l1,l2,carry,result);
            l1=l1->next;
         }
         
        if(carry==1)
        {
            ListNode* temp2=new ListNode(1);
            result->next=temp2;
        }
        
    }

    return head;
}
//*************** implementation 2

 ListNode*  reverse(ListNode* l)
 {
 	if(l==nullptr)
 		return l;
 	ListNode* prev=nullptr, *cur=l, *next=nullptr;
 	
 	while(cur)
 	{
 		next=cur->next;
 		cur->next=prev;
 		prev=cur;
 		cur=next;
 	}
 	return prev;
 }
 
 
 ListNode* add(ListNode* l1, ListNode* l2)
 {

	if(l1==nullptr && l2==nullptr)
		return l1;
	else if(l1==nullptr)
		return l2;
	else if(l2==nullptr)
		return l1;
		
	l1=reverse(l1);
	l2=reverse(l2);
	
	ListNode* r=new ListNode(0);
	ListNode* head=r;
	int sum=0, carry=0;
	while(l1!=nullptr && l2!=nullptr)
	{
		sum=l1->val + l2->val + carry;
		r->next=new ListNode(sum%10);
		carry=sum/10;
		
		l1=l1->next;
		l2=l2->next;
		r=r->next;
	}
	
	while(l1!=nullptr)
	{
		sum=l1->val + carry;
		r->next=new ListNode(sum%10);
		carry=sum/10;
		l1=l1->next;
		r=r->next;
	}
	while(l2!=nullptr)
	{
		sum=l2->val + carry;
		r->next=new ListNode(sum%10);
		carry=sum/10;
		l2=l2->next;
		r=r->next;
	}
	if(carry)
	{
		r->next=new ListNode(carry);
	}
	
	return reverse(head->next);
 }
int main() {
	ListNode* l1=new ListNode(2);
	l1->next= new ListNode(4);
	l1->next->next= new ListNode(3);
	
	ListNode* l2=new ListNode(5);
	l2->next= new ListNode(6);
	l2->next->next= new ListNode(4);
	ListNode* head=addTwoNumbers(l1,l2);
	
	while(head)
	{
		cout<<head->val<<'\t';
		head=head->next;
	}
	return 0;
}