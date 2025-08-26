#include <string>
#include <vector>

using namespace std;
vector<int> dr = {1, 0, 0, -1};  // d, l, r, u
vector<int> dc = {0, -1, 1, 0};
vector<string> dir = {"d", "l", "r", "u"};
 int N, M, K;
string answer = "impossible";

void dfs(int row, int col, int r,int c,int cnt ,string path)
{
    if (answer!="impossible") return;
    if (cnt == K) {
        if (row == r && col == c) {
            answer = path;
        }
        return;
    }
    
    int remainingMoves = K - cnt;
        int minDistToEnd = abs(r - row) + abs(c - col);
        if (remainingMoves < minDistToEnd) return;
    
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        // 7. 격자 범위를 벗어나지 않는 경우에만 탐색
        if (nr >= 1 && nr <= N && nc >= 1 && nc <= M) {

            dfs(nr, nc, r, c, cnt + 1, path + dir[i]);
        }
    }
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    
    N = n;
    M = m;
    K = k;
    int minDist=0;
    minDist+= abs(x-r);
    minDist+= abs(y-c);
    if((minDist%2==1 && k%2==0)||minDist%2==0 && k%2==1)
        return "impossible";
    dfs(x,y,r,c,0,"");
    
    return answer;
}