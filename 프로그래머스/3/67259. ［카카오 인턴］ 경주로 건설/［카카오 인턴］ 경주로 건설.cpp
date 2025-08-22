#include <string>
#include <vector>

using namespace std;
vector<int> dirY = {1,0,-1,0};
vector<int> dirX = {0,1,0,-1}; // down, right , up ,left
unsigned int result = -1;
void dfs(vector<vector<int>>& board,vector<vector<vector<unsigned int>>>& visited,int n, int y, int x, int dir,unsigned int cost)
{
    if(y<0||y>=n||x<0||x>=n) return;
    if(board[y][x]==1 || visited[y][x][dir] < cost) return;
    
    visited[y][x][dir]=cost;
    
    if(y==n-1 && x==n-1)
    {
        if(result > cost)
            result = cost;
        return;
    }
    
    for(int i=0;i<4;i++)
    {
        int nextDir = (dir+i)%4;
        int ny = y + dirY[nextDir];
        int nx = x + dirX[nextDir];
        if(i==0)
            dfs(board,visited,n,ny,nx,nextDir,cost+100);
        else
            dfs(board,visited,n,ny,nx,nextDir,cost+600); 
    }
    
}
int solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<vector<unsigned int>>> visited(25,vector<vector<unsigned int>>(25,vector<unsigned int>(4,-1)));
    dfs(board,visited,n,0,0,0,0);
    dfs(board,visited,n,0,0,1,0);
    return result;
}