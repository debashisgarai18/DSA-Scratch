#include <bits/stdc++.h>
using namespace std;

// this is the function to check whether the given brackets string is balanced or not!!
// example of balanced parenthesis :
bool solve(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); ++i)
    {
        // if the stack is empty, push the data
        if (st.empty())
            st.push(str[i]);
        else if ((str[i] == ')' && st.top() != '(') || (str[i] == '}' && st.top() != '{') || (str[i] == ']' && st.top() != '['))
            return false;
        else if ((str[i] == ')' && st.top() == '(') || (str[i] == '}' && st.top() == '{') || (str[i] == ']' && st.top() == '['))
            st.pop();
        else
            st.push(str[i]);
    }

    return true;
}

int main()
{
    string expresssion = "(()()[{]})";
    if (solve(expresssion))
        cout << "It is balanced";
    else
        cout << "It is not balanced";

    return 0;
}