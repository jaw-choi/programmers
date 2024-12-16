#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<int>> v(info.size());
    for (int i = 0; i < edges.size(); i++) 
        v[edges[i][0]].push_back(edges[i][1]);
    
    int answer = 1; // 최대 양의 수
    queue<tuple<int, int, int, vector<int>>> q; // 큐: (현재 노드, 늑대 수, 양 수, 다음 노드 리스트)
    
    vector<int> nextNode(v[0].begin(), v[0].end());
    q.push({0, 0, 0, nextNode}); // 초기 상태 enqueue
    
    while (!q.empty()) {
        auto [curr_idx, w, s, nextNode] = q.front();
        q.pop();
        
        int animal = info[curr_idx];
        if (animal == 0) s++;
        else w++;
        
        answer = max(answer, s);
        if (w >= s) continue; // 늑대가 양 이상인 경우 무효
        
        // 다음 가능한 노드들을 탐색
        for (int i = 0; i < nextNode.size(); i++) {
            vector<int> next = nextNode; // 현재 상태 복사
            next.erase(next.begin() + i); // 선택한 노드 제거
            for (int child : v[nextNode[i]]) 
                next.push_back(child); // 자식 노드 추가
            
            q.push({nextNode[i], w, s, next}); // 새로운 상태 enqueue
        }
    }
    
    return answer;
}
