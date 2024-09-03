#include <string>
#include <vector>

using namespace std;
int answer = 0;

void DFS(int open, int close,int cnt, int total)
{
    if(open>total/2||close>total/2)
        return;
    if(close>open)
        return;
    if(cnt==total){
        answer++;
        return;
    }
    DFS(open+1,close,cnt+1,total);
    DFS(open,close+1,cnt+1,total);
}
int solution(int n) {
    DFS(0,0,0,2*n);
    return answer;
}

