#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<vector<pair<int,int>>> graph(n);
    vector<int> visited(n,0);
    for(auto c : costs)
    {
        int u = c[0];
        int v = c[1];
        int cost = c[2];
        graph[u].push_back({v,cost});
        graph[v].push_back({u,cost});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,0});//cost,curr
    int sum = 0;
    int edge = 0;
    while(!pq.empty()||edge<n)
    {
        auto [cost, curr] = pq.top();
        pq.pop();
        if(visited[curr]==1) continue;
        visited[curr]=1;
        sum+=cost;
        edge++;
        for(auto g : graph[curr])
        {
            auto [next,next_cost] = g;
            pq.push({next_cost,next});
        }
    }
    return sum;
}