#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    map<int,vector<int>> mp;
    vector<int> visited(n+1,0);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(computers[i][j]==1)
                mp[i].push_back(j);
        }
    }
    for(int i=0;i<n;i++)
    {

        if(visited[i]==1) continue;
        answer++;
        visited[i] =1;
        queue<int> q;
        q.push(i);
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int j=0;j<mp[curr].size();j++)
            {
                int next = mp[curr][j];
                if(visited[next]==1) continue;
                visited[next]=1;
                q.push(next);
            }
        }
    }

    return answer;
}





