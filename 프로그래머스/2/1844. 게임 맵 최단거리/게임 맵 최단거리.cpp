#include<vector>
#include<queue>
using namespace std;

vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}}; // 상, 하, 좌, 우 이동 방향

int solution(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<bool>> visited(n, vector<bool>(m, false)); // 방문 체크 배열
    queue<pair<pair<int, int>, int>> q; // 큐: ((현재 위치), 이동 횟수)
    
    // 시작 위치 설정
    q.push({{0, 0}, 1});
    visited[0][0] = true;

    // BFS 시작
    while (!q.empty()) {
        auto [curr, cnt] = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();

        // 목표 지점 도달 시 이동 횟수 반환
        if (x == n - 1 && y == m - 1) {
            return cnt;
        }

        // 4방향으로 이동
        for (auto d : dir) {
            int nextX = x + d.first;
            int nextY = y + d.second;

            // 다음 위치가 유효한지 확인
            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
                // 방문하지 않았고 벽이 아닌 경우
                if (!visited[nextX][nextY] && maps[nextX][nextY] == 1) {
                    visited[nextX][nextY] = true;
                    q.push({{nextX, nextY}, cnt + 1});
                }
            }
        }
    }

    // 목표 지점에 도달할 수 없는 경우
    return -1;
}