#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    unordered_map<int,vector<int>> graph;
    vector<int> visited(n+1,0);
    vector<int> maxNum(n+1,0);
    int max_distance = 0;
    visited[1]=1;
    for(auto e : edge)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    queue<pair<int,int>> q;
    q.push({1,0});//node,cost
    while(!q.empty())
    {
        int curr = q.front().first;
        int distance = q.front().second;

        q.pop();
        // 최대 거리 갱신 및 해당 거리의 노드 수 계산
        if (distance > max_distance) {
            max_distance = distance;
            answer = 1;
        } else if (distance == max_distance) {
            answer++;
        }
        
        for (auto neighbor : graph[curr]) {
            if (visited[neighbor] == 0) {
                q.push({neighbor, distance + 1});
                visited[neighbor] = 1;
            }
        }
    }
    return answer;
}