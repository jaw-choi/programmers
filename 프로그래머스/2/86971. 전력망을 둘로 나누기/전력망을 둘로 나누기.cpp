#include <string>
#include <vector>

using namespace std;
int dfs(int node, int parent, const vector<vector<int>>& graph)
{
    int cnt = 1;
    for(auto neighbor : graph[node])
    {
        if(neighbor != parent)
            cnt += dfs(neighbor,node,graph);
    }
    return cnt;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    vector<vector<int>> graph(n+1);
    for(auto w : wires)
    {
        graph[w[0]].push_back(w[1]);
        graph[w[1]].push_back(w[0]);
    }
    for(int i=0;i<wires.size();i++)
    {
        int cnt = dfs(wires[i][0],wires[i][1],graph);
        answer = min(answer,abs(n-2*cnt));
    }
    return answer;
}