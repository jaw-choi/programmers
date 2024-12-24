#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<int> st;
    for(auto c : s)
    {
        if(st.empty())
            st.push(c);
        else if(st.top()!=c)
            st.push(c);
        else
            st.pop();
    }
    if(st.empty())
        return 1;
    return 0;
}