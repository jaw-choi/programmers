#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    //작업의 소요시간이 짧은 것, 작업의 요청 시각이 빠른 것, 작업의 번호가 작은 것

    int n = jobs.size();
    sort(jobs.begin(),jobs.end());
    
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
    int time = 0;
    int idx = 0;
    long long total = 0;

    while(idx<n || !pq.empty())
    {
        while(idx<n && jobs[idx][0]<=time)
        {
            pq.push({jobs[idx][1],jobs[idx][0],idx});
            idx++;
        }
        
        if(!pq.empty())
        {
            auto [a,b,c] = pq.top();
            pq.pop();
            time += a;
            total += (time - b);
        }
        else
        {
            time = jobs[idx][0];
        }
        
    }
    return total/n;
}

