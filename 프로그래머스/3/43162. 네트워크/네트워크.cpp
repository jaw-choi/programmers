#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <map>

using namespace std;
void DFS(int curr, int prev,unordered_map<int,vector<int>> graph, set<int>& net,vector<bool>& visited)
{
    if(visited[curr]==true)
        return;
    net.insert(curr);
    visited[curr]=true;
    for(auto g : graph[curr])
    {
        if(g!=prev)
        {
            DFS(g,curr,graph,net,visited);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n+1,false);
    unordered_map<int,vector<int>> graph;
    map<set<int>,int> netCnt;
    for(int i =0;i<computers.size();i++)
    {
        for(int j =0;j<computers.size();j++)
        {
            if(computers[i][j]==1&&i!=j)
                graph[i+1].push_back(j+1);
        }
    }
    
    for(int i=1;i<=n;i++){
        set<int> net;
        DFS(i,0,graph,net,visited);
        if(!net.empty())
            netCnt[net]++;
    }

    return netCnt.size();
}