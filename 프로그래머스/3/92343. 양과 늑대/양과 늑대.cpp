#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int n = info.size();
    vector<vector<int>> graph(n);
    for(auto e : edges)
    {
        graph[e[0]].push_back(e[1]);
       // graph[e[1]].push_back(e[0]);
    }

    vector<int> iState = {0,0,0}; // curr,wolf,sheep;
    queue<vector<int>> q;
    for(auto g : graph[0])
        iState.push_back(g);
    q.push(iState); //{0, [1,8]}
    while(!q.empty())
    {
        vector<int> state = q.front();
        q.pop();
        
        int curr = state[0];
        int wolf = state[1];
        int sheep = state[2];
        
        if(info[curr]==0)//sheep
            sheep++;
        else
            wolf++;
        if(sheep<=wolf) continue;
        answer = max(answer,sheep);
        
        for(int i=3;i<state.size();i++)
        {
            int next = state[i];
            vector<int> nextState = {next,wolf,sheep};
            for(int j=3;j<state.size();j++){
                if(i!=j)
                    nextState.push_back(state[j]);
            }
            for(auto g : graph[next])
                nextState.push_back(g);
            q.push(nextState);
        }
        
        
    }
    return answer;
}