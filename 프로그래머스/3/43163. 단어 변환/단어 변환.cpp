#include <string>
#include <vector>
#include <algorithm> // min 함수 사용

using namespace std;

bool canChange(const string& a, const string& b) {
    int cnt = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i])
            cnt++;
    }
    return cnt == 1;
}

void dfs(int cnt, string curr, const string& target, const vector<string>& words, vector<int>& visited, int& answer) {
    if (curr == target) {
        answer = min(answer, cnt);
        return;
    }
    for (int i = 0; i < words.size(); i++) {
        if (!visited[i] && canChange(curr, words[i])) {
            visited[i] = 1;
            dfs(cnt + 1, words[i], target, words, visited, answer);
            visited[i] = false; // 백트래킹
        }
    }
}

int solution(string begin, string target, vector<string> words) {

    int answer = 51; // 충분히 큰 값으로 초기화
    vector<int> visited(words.size(), 0); // 방문 여부 체크 배열
    dfs(0, begin, target, words, visited, answer);

    return answer == 51 ? 0 : answer;
}
