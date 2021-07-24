#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // later encountered, firstly closed -> stack
    bool isValid(string s)
    {
        stack<char> st;
        char top;
        unordered_map<char, char> pair = {{'}', '{'}, {']', '['}, {')', '('}};
        st.push('a');
        for (int i = 0; i < s.size(); i++)
        {
            if (pair.find(s[i]) != pair.end())
            {
                if (st.top() != pair[s[i]])
                    return false;
                else
                    st.pop();
            }
            else
                st.push(s[i]);
        }
        if (st.size()==1 && st.top() == 'a')
            return true;
        return false;
    }
};

int main(){
    string s = "()[]{}";
    Solution res;
    printf("%d\n", res.isValid(s));
}