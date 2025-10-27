#include<vector>
#include<queue>
using namespace std;

vector<int> dirY = {-1,1,0,0};
vector<int> dirX = {0,0,-1,1};
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> visited(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},1});
    visited[0][0]=1;
    while(!q.empty())
    {
        auto[pos,cnt] = q.front();
        int currY = pos.first;
        int currX = pos.second;
        q.pop();
        if(currY==n-1 && currX == m-1)
            return cnt;
        for(int i=0;i<4;i++)
        {
            int ny = currY + dirY[i];
            int nx = currX + dirX[i];
            if(ny<0 || nx<0 || ny>=n || nx>=m) continue;
            if(maps[ny][nx]==0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx]=1;
            q.push({{ny,nx},cnt+1});
        }
    }
    return -1;
}