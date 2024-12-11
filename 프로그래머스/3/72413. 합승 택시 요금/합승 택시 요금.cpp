#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 100000000
using namespace std;

vector<int> dijkstra(int start,int n, vector<pair<int,int>> graph[])
{
    vector<int> dist(n+1,INF);
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    
    while(!pq.empty())
    {
        int curr_dist = pq.top().first;
        int curr_node = pq.top().second;
        pq.pop();
        
        for(int i=0;i<graph[curr_node].size();i++)
        {
            int next_node = graph[curr_node][i].first;
            int next_dist = curr_dist + graph[curr_node][i].second;
            if(dist[next_node] > next_dist)
            {
                dist[next_node] = next_dist;
                pq.push({next_dist,next_node});
            }
        }
    }
    for(int i=0;i<dist.size();i++)
        cout << dist[i] << " ";
    cout <<endl;
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<pair<int,int>> graph[n+1];
    for(auto f : fares)
    {
        int from  = f[0];
        int to    = f[1];
        int weight= f[2];
        graph[from].push_back({to,weight});
        graph[to].push_back({from,weight});
    }
    vector<int> vs = dijkstra(s,n,graph);
    vector<int> va = dijkstra(a,n,graph);
    vector<int> vb = dijkstra(b,n,graph);
    for(int i=1;i<=n;i++)
    {
        answer = min(answer,vs[i]+va[i]+vb[i]);
    }
    return answer;
}