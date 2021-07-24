#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> St1, reverseSt1;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        St1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (reverseSt1.empty())
        {
            while (!St1.empty())
            {
                reverseSt1.push(St1.top());
                St1.pop();
            }
        }

        int res = reverseSt1.top();
        reverseSt1.pop();
        return res;
    }

    /** Get the front element. */
    int peek()
    {
        if (reverseSt1.empty())
        {
            while (!St1.empty())
            {
                reverseSt1.push(St1.top());
                St1.pop();
            }
        }
        return reverseSt1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        if (St1.empty() && reverseSt1.empty())
            return true;
        else
            return false;
    }
};

int main()
{

    // Your MyQueue object will be instantiated and called as such:
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    // int param_3 = obj->peek();
    int param_2 = obj->pop();
    obj->push(5);
    int param_3 = obj->pop();
    int param_4 = obj->pop();
    int param_5 = obj->pop();
    int param_6 = obj->pop();
    printf("%d\t", param_2);
    printf("%d\t", param_3);
    printf("%d\t", param_4);
    printf("%d\t", param_5);
    printf("%d\t\n", param_6);
}
