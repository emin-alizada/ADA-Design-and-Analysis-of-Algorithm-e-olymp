#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int i, n;
string str;

class MyStack
{
private:
    stack<int> s, mn;
public:
    void push(int x)
    {
        s.push(x);
        if (mn.empty()) mn.push(x);
        else mn.push(min(mn.top(), x));
    }

    int pop(void)
    {
        int temp = s.top();
        s.pop();
        mn.pop();
        return temp;
    }

    int top(void)
    {
        return s.top();
    }

    int GetMin(void)
    {
        return mn.top();
    }

    int GetSize(void)
    {
        return s.size();
    }
};

int main(void)
{
    MyStack s;
    while (cin >> str)
    {
        if (str == "push")
        {
            cin >> n;
            s.push(n);
        }
        else
        if (str == "pop")
        {
            cout << s.top() << endl;
            s.pop();
        }
        else
        if (str == "top")
        {
            cout << s.top() << endl;
        }
        else
        if (str == "size")
        {
            cout << s.GetSize() << endl;
        }
        else
        if (str == "GetMin")
        {
            cout << s.GetMin() << endl;
        }
    }
    return 0;
}
