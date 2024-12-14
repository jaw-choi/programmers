#include <string>
#include <vector>
#define INF 10000000
using namespace std;

int DFS(vector<vector<int>> graph, int node,int parent)
{
    int cnt = 1;
    for(auto neighbor : graph[node])
    {
        if(neighbor != parent)
            cnt += DFS(graph,neighbor,node);
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INF;
    vector<vector<int>> graph(n+1);
    for(auto w : wires)
    {
        graph[w[0]].push_back(w[1]);
        graph[w[1]].push_back(w[0]);
    }
    for(int i=0;i<wires.size();i++)
    {
        int cnt = DFS(graph,wires[i][0],wires[i][1]);
        answer = min(answer , abs((n-cnt) - (cnt)));
    }
    return answer;
}