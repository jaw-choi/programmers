#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(string start, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& answer) {
    answer.push_back(start);
    
    // 모든 티켓을 사용해서 만들어진 경로는 티켓 개수 + 1이어야 함
    if(answer.size() == tickets.size() + 1)
        return true;

    for(int i = 0; i < tickets.size(); i++) {
        if(start == tickets[i][0] && !visited[i]) {
            visited[i] = true;
            if(DFS(tickets[i][1], tickets, visited, answer))
                return true;
            visited[i] = false;
        }
    }
    
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets, visited, answer);
    return answer;
}
