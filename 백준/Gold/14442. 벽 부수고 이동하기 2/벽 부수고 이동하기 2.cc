#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

struct Node {
    int y, x, broken, dist;
};

vector<int> dirY = {-1,1,0,0};
vector<int> dirX = {0,0,-1,1};

int solve_maze(const vector<vector<int>>& grid, int K) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(K+1, 0)));

    queue<Node> q;
    q.push({0,0,0,1}); // 시작 지점 (거리 1부터)
    visited[0][0][0] = 1;

    while(!q.empty()) {
        auto [y,x,broken,dist] = q.front();
        q.pop();

        if(y==n-1 && x==m-1) return dist;

        for(int i=0;i<4;i++){
            int ny=y+dirY[i], nx=x+dirX[i];
            if(ny<0||nx<0||ny>=n||nx>=m) continue;

            // 빈 칸
            if(grid[ny][nx]==0 && !visited[ny][nx][broken]) {
                visited[ny][nx][broken]=1;
                q.push({ny,nx,broken,dist+1});
            }
            // 벽인데 부술 수 있음
            else if(grid[ny][nx]==1 && broken<K && !visited[ny][nx][broken+1]) {
                visited[ny][nx][broken+1]=1;
                q.push({ny,nx,broken+1,dist+1});
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M,K;
    cin >> N >> M >>K;
    vector<vector<int>> grid(N, vector<int>(M));
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        for(int j=0;j<M;j++) grid[i][j] = s[j]-'0';
    }

    cout << solve_maze(grid,K) << "\n"; 
}
