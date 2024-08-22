#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    pair<int,int> pa;
    int idx=0;
    priority_queue<int,vector<int>,less<int>> pq;
    queue<pair<int,int>> q;
    for(auto p : priorities)
    {
        pq.push(p);
        q.push(make_pair(p,idx++));
    }
    int cnt = 1;
    while(true)
    {
        auto tmp = q.front();
        q.pop();
        if(tmp.first != pq.top()){
            q.push(tmp);
        }
        else{
            if(tmp.second==location)
                return cnt;
            else{
                cnt++;
                pq.pop();
            }
        }
    }
    
    return answer;
}
//2132
//1322
//3221
//221
//21
//1
//CDA