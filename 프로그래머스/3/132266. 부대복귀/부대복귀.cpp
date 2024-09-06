#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;
#define MAX 100001
int ans = 100001;
bool visited[MAX]={false};


vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> dist(n+1);
    unordered_map<int,vector<int>> mp;
    for(auto r : roads)
    {
        mp[r[0]].push_back(r[1]);
        mp[r[1]].push_back(r[0]);
    }
    for(int i=1;i<=n;i++)
        dist[i] = MAX;
    
    queue<pair<int,int>> q;
    q.push({destination,0});
    dist[destination] = 0;
    
    while(!q.empty())
    {
        int s = q.front().first;
        int d = q.front().second;
        q.pop();
        
    for(int i=0; i<mp[s].size();i++)
    {
        if(visited[mp[s][i]]==false)
        {
            visited[mp[s][i]] = true;
            dist[mp[s][i]] = min(dist[mp[s][i]],d + 1);
            q.push({mp[s][i],dist[mp[s][i]]});
        }
    }
        
        
    }
    for(auto s : sources)
    {
        if(dist[s]==MAX)
            answer.push_back(-1);
        else
            answer.push_back(dist[s]);
    }

    return answer;
}

//1 2,4
//2 1,4,5
//3 
//4 1,2,5
//5 2,4