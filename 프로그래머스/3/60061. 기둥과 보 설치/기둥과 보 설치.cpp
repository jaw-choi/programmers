#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 구조물 정보를 저장할 set
set<vector<int>> structure;

// 특정 구조물이 설치 가능한지 확인하는 함수
bool isValid() {
    for (const auto& b : structure) {
        int x = b[0], y = b[1], a = b[2];

        if (a == 0) { // 기둥
            if (y == 0 || structure.count({x, y - 1, 0}) ||
                structure.count({x - 1, y, 1}) || structure.count({x, y, 1})) {
                continue;
            }
        } else { // 보
            if (structure.count({x, y - 1, 0}) || structure.count({x + 1, y - 1, 0}) ||
                (structure.count({x - 1, y, 1}) && structure.count({x + 1, y, 1}))) {
                continue;
            }
        }
        return false; // 하나라도 조건 만족하지 않으면 false
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    for (const auto& bf : build_frame) {
        int x = bf[0], y = bf[1], a = bf[2], b = bf[3];

        if (b == 1) { // 설치
            structure.insert({x, y, a});
            if (!isValid()) {
                structure.erase({x, y, a}); // 유효하지 않으면 원복
            }
        } else { // 삭제
            structure.erase({x, y, a});
            if (!isValid()) {
                structure.insert({x, y, a}); // 유효하지 않으면 원복
            }
        }
    }

    // 결과 벡터 생성 및 정렬
    vector<vector<int>> answer(structure.begin(), structure.end());
    sort(answer.begin(), answer.end());

    return answer;
}
