#include <stack>
class Queue {
    stack<int> s1;
    stack<int> s2;
    int top;
public:
    // Push element x to the back of queue.
    void push(int x) {
        if(s1.empty())
            top=x;
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
            
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            
            s2.pop();
            if(!s2.empty())
                top=s2.top();
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
    }

    // Get the front element.
    int peek(void) {
       return top;
    }

    // Return whether the queue is empty.
    bool empty(void) {
            if(s1.empty())
                return true;
            else
                return false;
    }
};


#include <stack>
class Queue {
private:
 stack<int> s1,s2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        this->peek();
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        
        if(!s2.empty())
            return s2.top();
            
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty()&& s2.empty();
        
    }
};