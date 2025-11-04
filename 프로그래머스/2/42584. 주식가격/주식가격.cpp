#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n,0);
    stack<int> st;
    for(int i=0;i<prices.size();i++)
    {
        while(!st.empty() && prices[i] < prices[st.top()])
        {
            int top = st.top();
            st.pop();
            answer[top] = i - top;
        }
        st.push(i);
    }
    while(!st.empty())
    {
        int top = st.top();
        st.pop();   
        answer[top] = (n-1) - top;
    }
    return answer;
}