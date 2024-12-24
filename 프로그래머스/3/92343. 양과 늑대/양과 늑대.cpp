#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    vector<vector<int>> graph(info.size());
    for(auto e : edges)
    {
        graph[e[0]].push_back(e[1]);
    }
    vector<int> iState = {0,0,0}; // curr,wolf,sheep
    queue<vector<int>> q;
    for(auto child : graph[0])
        iState.push_back(child);
    q.push(iState);
    int curr,wolf,sheep;
    while(!q.empty())
    {
        vector<int> state = q.front();
        q.pop();
        
        curr = state[0];
        wolf = state[1];
        sheep = state[2];
        
        if(info[curr]==0)
            sheep++;
        else
            wolf++;
        if(wolf>=sheep)
            continue;
        answer = max(answer,sheep);
        
        for(int i=3;i<state.size();i++)
        {
            int next_node = state[i];
            vector<int> nextState = {next_node,wolf,sheep};
            for(int j=3;j<state.size();j++)
                if(i!=j)
                    nextState.push_back(state[j]);
            for(auto g : graph[next_node])
                nextState.push_back(g);
            q.push(nextState);
        }
    }
    return answer;
}