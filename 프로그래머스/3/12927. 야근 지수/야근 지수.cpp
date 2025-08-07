#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int,vector<int>> pq;
    for(auto w : works)
    {
        pq.push(w);
    }
    while(!pq.empty())
    {
        if(n==0)
            break;
        int num = pq.top();
        pq.pop();
        num--;
        n--;
        pq.push(num);
    }
    while(!pq.empty())
    {
        int tmp = pq.top();
        pq.pop();
        if(tmp>=0)
            answer += (tmp*tmp);
    }
    return answer;
}