#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 1e9

using namespace std;
#define INF 1e9

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    //vector<vector<pair<int,int>>> graph(n+1,{});
    vector<vector<pair<int,int>>> graph(n+1);
    int minResult = INF;
    for(auto p : paths)
    {
        int i = p[0];
        int j = p[1];
        int w = p[2];
        graph[i].push_back({j,w});
        graph[j].push_back({i,w});
    }
    

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        vector<int> dist(n+1,INF);
    vector<bool> isSummit(n+1, false);
for (int s : summits) isSummit[s] = true;
    for(int g : gates) {
        dist[g] = 0;
        pq.push({0, g});
    }
        
        while(!pq.empty())
        {
            int d = pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            if(d > dist[curr]) continue;
            if(isSummit[curr]) continue;
            for(auto node : graph[curr])
            {
                int next = node.first;
                int weight = node.second;
                int nd = max(d,weight);
                if(dist[next] > nd){
                    dist[next] = nd;
                    pq.push({nd,next});
                }
            }
        }
sort(summits.begin(), summits.end());
int bestSummit = -1, bestIntensity = INF;
for(int s : summits) {
    if(dist[s] < bestIntensity) {
        bestSummit = s;
        bestIntensity = dist[s];
    }
}



     return {bestSummit, bestIntensity};
}