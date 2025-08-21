#include <string>
#include <vector>

using namespace std;

vector<bool> visited(201, false);

void Dfs(vector<vector<int>> v, int here, int n)
{
    int index = 0;
    visited[here] = true;

    // 연결된 노드 확인
    for (int there : v[here])
    {
        // computer[i][i]는 항상 1이기에 패스
        if (here == index)
        {
            index++;
            continue;
        }

        // 연결된 노드가 있고 방문하지 않았으면...
        if (there == 1 && visited[index] == false)
        {
            Dfs(v, index, n);
        }

        index++;
    }
}

// 모든 노드 탐색
int DfsAll(vector<vector<int>> v, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            // 이어진 노드 탐색
            Dfs(v, i, n);

            // 하나의 사이클이 끝나면 +1
            count++;
        }
    }

    return count;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    answer = DfsAll(computers, n);

    return answer;
}