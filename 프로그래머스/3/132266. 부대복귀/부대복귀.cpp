#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer(sources.size(),-1);
    map<int,vector<int>> mp;
    queue<int> q;
    for(auto r : roads)
    {
        mp[r[0]].push_back(r[1]);
        mp[r[1]].push_back(r[0]);
    }
    vector<int> distance(n+1,-1);
    distance[destination] = 0;
    q.push(destination);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        for(auto m : mp[curr])
        {
            if(distance[m]==-1){
                distance[m] = distance[curr] + 1;
                q.push(m);
            }
        }
    }
    for(int i=0;i<sources.size();i++)
    {
        answer[i] = (distance[sources[i]]);
    }
    return answer;
}