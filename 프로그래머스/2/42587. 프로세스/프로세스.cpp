#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
    queue<pair<int,int>> q;//priorities,location
    int cnt = 1;
    for(int i=0;i<priorities.size();i++)
    {
        pq.push({priorities[i],i});
        q.push({priorities[i],i});
    }
    while(!q.empty())
    {
        auto tmp = q.front();
        q.pop();
        if(tmp.first==pq.top().first)
        {
            if(tmp.second==location)
                return cnt;
            else{
                pq.pop();
                cnt++;
            }
        }
        else
        {
            
            q.push(tmp);
        }
    }
    return answer;
}