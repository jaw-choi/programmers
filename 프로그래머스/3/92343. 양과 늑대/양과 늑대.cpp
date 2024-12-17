#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<int>> graph(info.size());
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
    }

    int answer = 1; // 최대 양의 수
    queue<vector<int>> q; // 큐: [현재 노드, 늑대 수, 양 수, ...다음 노드 리스트]

    vector<int> initial_state = {0, 0, 0};
    for (int child : graph[0]) {
        initial_state.push_back(child); // 루트 노드의 자식 노드들 추가
    }
    q.push(initial_state); // 초기 상태 enqueue

    while (!q.empty()) {
        vector<int> state = q.front();
        q.pop();

        int curr_idx = state[0];
        int wolf_count = state[1];
        int sheep_count = state[2];

        if (info[curr_idx] == 0) sheep_count++; // 양이면 양 카운트 증가
        else wolf_count++; // 늑대면 늑대 카운트 증가

        answer = max(answer, sheep_count);
        if (wolf_count >= sheep_count) continue; // 늑대가 양 이상인 경우 무효

        // 다음 가능한 노드들을 탐색
        for (int i = 3; i < state.size(); i++) {
            int next_node = state[i];
            vector<int> next_state = {next_node, wolf_count, sheep_count};

            for (int j = 3; j < state.size(); j++) {
                if (i != j) next_state.push_back(state[j]); // 현재 선택된 노드를 제외한 나머지 노드들 추가
            }
            for (int child : graph[next_node]) {
                next_state.push_back(child); // 선택한 노드의 자식 노드들 추가
            }

            q.push(next_state); // 새로운 상태 enqueue
        }
    }

    return answer;
}
