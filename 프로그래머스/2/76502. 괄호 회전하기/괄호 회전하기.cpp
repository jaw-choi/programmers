#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool helper(string s)
{
    stack<char> st;
    
    for(int i=0;i<s.length();i++)
    {
        if(st.empty()){
            st.push(s[i]);
            continue;
        } 
        
        if(s[i]==')'&&st.top()=='(')
            st.pop();
        else if(s[i]=='}'&&st.top()=='{')
            st.pop();
        else if(s[i]==']'&&st.top()=='[')
            st.pop();
        else
            st.push(s[i]);
    }

    return st.empty();
}
void rotate(string& s)
{
    string tmp1 = s.substr(0,1);
    string tmp2 = s.substr(1);
   
    s = tmp2 + tmp1;
}
int solution(string s) {
    if(s.length()==1)
        return 0;
    int answer = 0;
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        if(helper(s)){
            answer++;
        }
        //cout << s << endl;
        rotate(s);
    }
    
    return answer;
}