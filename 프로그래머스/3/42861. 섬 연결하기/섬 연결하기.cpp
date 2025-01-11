#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <tuple> // for std::tuple
#define INF 10000000
using namespace std;

int solution(int n, vector<vector<int>> costs) {
    vector<vector<pair<int, int>>> graph(n);
    
    // 그래프 초기화
    for (const auto& c : costs) {
        int u = c[0], v = c[1], cost = c[2];
        graph[u].emplace_back(v, cost);
        graph[v].emplace_back(u, cost);
    }
    
    // 프림 알고리즘
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, 0); // 비용 0, 시작 노드 0
    
    int mst_cost = 0;
    int edges_used = 0;
    
    while (!pq.empty() && edges_used < n) {
        auto [cost, current] = pq.top();
        pq.pop();
        
        if (visited[current]) continue;
        visited[current] = true;
        mst_cost += cost;
        edges_used++;
        
        for (const auto& [next, next_cost] : graph[current]) {
            if (!visited[next]) {
                pq.emplace(next_cost, next);
            }
        }
    }
    
    return mst_cost;
}
