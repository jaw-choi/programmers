#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    
    stack<int> st;
    
    for(int i = numbers.size() -1; i >= 0; i--)
    {
        while(1)
        {
            if(st.empty())
            {
                answer[i] = -1;
                break;
            }
            if(st.top() > numbers[i])
            {
                answer[i] = st.top();
                break;
            }
            st.pop();
        }
        st.push(numbers[i]);
    }
    return answer;
}