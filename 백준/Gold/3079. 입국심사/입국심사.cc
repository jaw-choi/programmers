#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<long long> time(N);
    for (int i = 0; i < N; i++) {
        cin >> time[i];
    }

    long long left = 1;
    long long right = *max_element(time.begin(), time.end()) * (long long)M;
    long long answer = right;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;

        for (auto &t : time) {
            cnt += mid / t;
            if (cnt >= M) break; // 오버플로우 방지 + 불필요 계산 제거
        }

        if (cnt >= M) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << "\n";
    return 0;
}
