#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    vector<vector<pair<int,int>>> graph(n+1);
    for(auto& p : paths)
    {
        int u = p[0];
        int v = p[1];
        int w = p[2];
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    
    vector<int> dist(n+1,INF);
    vector<int> isSum(n+1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    
    for(auto& g : gates)
    {
        dist[g] = 0;
        pq.push({dist[g],g});
    }
    
    for(auto& s : summits)
    {
        isSum[s] = true;
    }
    
    while(!pq.empty())
    {
        auto [d,curr] = pq.top();
        pq.pop();
        
        if(dist[curr] < d) continue;
        if(isSum[curr]) continue;
        
        for(auto& g : graph[curr])
        {
            int next = g.first;
            int weight = g.second;
            int intesity = max(d,weight);
            if(dist[next] > intesity){
                dist[next] = intesity;
                pq.push({dist[next],next});
            }
        }
    }
    sort(summits.begin(),summits.end());
    int peak = 0;
    int minIntensity = INF;
    for(int i=0;i<summits.size();i++)
    {
        if(dist[summits[i]] < minIntensity)
        {
            peak = summits[i];
            minIntensity = dist[summits[i]];
        }
    }
    
    return {peak,minIntensity};
}