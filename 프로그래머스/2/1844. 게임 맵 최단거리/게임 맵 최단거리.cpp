#include <vector>
#include <queue>
#define INF 10001
using namespace std;

int solution(vector<vector<int>> maps) {
    int m = maps.size();
    int n = maps[0].size();

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // 모든 칸을 INF로 초기화 (방문하지 않은 상태)
    vector<vector<int>> dist(m, vector<int>(n, INF));

    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1; // 시작점은 1로 초기화

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || maps[ny][nx] == 0)
                continue;

            if (dist[ny][nx] > dist[y][x] + 1) {
                dist[ny][nx] = dist[y][x] + 1;
                q.push({nx, ny});
            }
        }
    }

    return dist[m - 1][n - 1] == INF ? -1 : dist[m - 1][n - 1];
}