#include <iostream>
#include <queue>

using namespace std;
#define INF 1e9



int main(void)
{
    int V,E;
    int start;
    int u,v,w;
    cin >> V>>E>>start;
    vector<vector<pair<int,int>>> graph(V+1);
    vector<int> dist(V+1,INF);
    for(int i=0;i<E;i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    dist[start] = 0;
    pq.push({0,start});
    
    while(!pq.empty())
    {
        int distance = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        for(auto& edge : graph[curr])
        {
            int next = edge.first;
            int cost = edge.second;
            if(dist[next] > distance + cost){
                dist[next] = distance + cost;
                pq.push({dist[next],next});
            }
                
        }
    }
for(int i=1;i<=V;i++) {
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}