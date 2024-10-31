#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
int dfs(int curr,int pre,unordered_map<int,vector<int>> graph,int& minSize,int n)
{
    int sum = 1;
    for(auto g : graph[curr])
    {
        if(g!=pre)
        {
            int count = dfs(g,curr,graph,minSize,n);
            minSize = min(minSize,abs((n-count)-count));
            sum += count;
        }
    }
    return sum;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    int minSize = n;
    unordered_map<int,vector<int>> graph;
    for(auto a: wires)
    {
        graph[a[0]].push_back(a[1]);
        graph[a[1]].push_back(a[0]);
    }
    dfs(1,0,graph,minSize,n);
    return minSize;
}