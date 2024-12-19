#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    map<int,vector<int>> mp;
    vector<int> visited(200,0);
    for(int i=0;i<computers.size();i++)
    {
        for(int j=0;j<computers[0].size();j++)
        {
            if(computers[i][j]==1){
                mp[i].push_back(j);
            }
        }
    }
    for(int k=0;k<n;k++)
    {
        if(visited[k]) continue;
        visited[k]=1;
        answer++;
        queue<int> q;
        q.push(k);
        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();
            for(int i=0;i<mp[tmp].size();i++)
            {
                if(visited[mp[tmp][i]]==1) continue;
                visited[mp[tmp][i]] = 1;
                q.push(mp[tmp][i]);
            }
        }
    }
    return answer;
}