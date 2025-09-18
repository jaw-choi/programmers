#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> work(works.begin(),works.end());
    while(n!=0)
    {
        if(work.empty())
            return 0;
        int num = work.top();
        work.pop();
        num--;
        if(num!=0)
            work.push(num);
        n--;
    }
    while(!work.empty())
    {
        int num = work.top();
        work.pop();
        answer += ( num * num);
    }
    return answer;
}