#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    for(int i=1;i<order.size()+1;i++)
    {
        s.push(i);
        while(!s.empty() && s.top()==order[answer])
        {
            s.pop();
            answer++;
        }
    }
    return answer;
}
//나온 컨테이너와 넣을려는 컨테이너의 숫자가 같으면 체크지를 넘어간다
//다를떄
//체크지와 같은 숫자가 나올때 까지 스택에 넣는다.
//나오면 넣고 
//다음 숫자가 스택에 있는지 아직 안나왔는지 체크 후
//스택에 있으면 가장 위에 있으면 넣고 가장 위에 있는게 아니면 return
//스택에 없으면 체크지와 같은 숫자가 나올때 까지 스택에 넣는다

