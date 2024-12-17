#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define INF 50001
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int maxNum = 0;
    vector<vector<int>> graph(n+1);
    for(auto e : edge){
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    vector<int> node(n+1,INF);
    node[1] = 0;
    //parent,neighbor,cnt
    queue<pair<int,int>> q;//curr,cnt
    q.push({1,0});
    while(!q.empty())
    {
        int curr_node = q.front().first;
        int cnt = q.front().second;
        maxNum = max(maxNum,cnt);
        q.pop();
        
        for(auto g : graph[curr_node]){
            if(node[g] > cnt + 1){
                node[g] = cnt + 1;
                q.push({g,cnt+1});
            }
        }
    }
    for(auto n : node)
        if(n==maxNum)
            answer++;
    return answer;
}