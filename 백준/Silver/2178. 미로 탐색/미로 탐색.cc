#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dirY = {1,-1,0,0};
vector<int> dirX = {0,0,-1,1};    

int bfs(int n,int m, vector<vector<int>>& graph )
{
    if (graph[0][0] == 0 || graph[n-1][m-1] == 0) return -1;
    
    vector<vector<int>> dist(n,vector<int>(m,0));
    queue<pair<int,int>> q;
        
    dist[0][0] = 1;   
    q.push({0,0});
    
    while(!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if (y == n - 1 && x == m - 1) {
            return dist[y][x]; // Found shortest path
        }
        
        for(int i=0;i<4;i++)
        {
            int ny = y + dirY[i];
            int nx = x + dirX[i];
            if(ny<0 || ny >=n || nx < 0 || nx >=m)
                continue;
            if(graph[ny][nx]==0)
                continue;
            if(dist[ny][nx]!=0)
                continue;
            dist[ny][nx]=dist[y][x] + 1;
            q.push({ny,nx});
        }
    }
    return -1;
}
int main(void)
{
    int n,m;
    int ans = 0;
    cin >> n >> m;
    vector<vector<int>> graph(n,vector<int>(m,0));
for (int i = 0; i < n; i++) {
    string row;
    cin >> row;                 // "101111" 같은 한 줄
    for (int j = 0; j < m; j++) {
        graph[i][j] = row[j] - '0';
    }
}

    ans = bfs(n,m,graph);
    cout << ans;
    return 0;
}    
    
    
    
    