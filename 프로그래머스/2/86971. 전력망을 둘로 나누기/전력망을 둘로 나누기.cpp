#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int dfs(vector<vector<int>> tree, int node, int parent)
{
    int cnt = 1;
    for(auto neighbor : tree[node])
    {
        if(neighbor!=parent)
        {
            cnt+=dfs(tree,neighbor,node);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    vector<vector<int>> tree(n+1);
    for(auto w : wires)
    {
        tree[w[0]].push_back(w[1]);
        tree[w[1]].push_back(w[0]);
    }
    for(int i=0;i<wires.size();i++)
    {
        int cnt = dfs(tree,wires[i][0],wires[i][1]);
        answer = min(answer, abs((n-2*cnt)));
    }

    return answer;
}