#include<vector>
#include<queue>
using namespace std;

vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

int solution(vector<vector<int> > maps)
{
    int answer = 10001;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<pair<int,int>,int>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maps[i][j]==0)
                visited[i][j]=true;
        }
    }
    q.push({{0,0},1});
    while(!q.empty())
    {
        auto [curr,cnt] = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();
        
        if(x==n-1 && y==m-1)
            return cnt;
        for(auto d : dir){
            int nextX = x + d.first;
            int nextY = y + d.second;
            if(nextX >=0 && nextX <n &&nextY>=0&&nextY<m){
                if(visited[nextX][nextY]==false && maps[nextX][nextY]==1){
                    visited[nextX][nextY]=true;
                    q.push({{nextX,nextY},cnt+1});
                }
            }
        }
        
    }
    return -1;
}