#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> W(N+1), V(N+1);
    for (int i=1; i<=N; i++) {
        cin >> W[i] >> V[i];
    }

    vector<int> dp(K+1, 0);

    for (int i=1; i<=N; i++) {
        for (int w=K; w>=W[i]; w--) {
            dp[w] = max(dp[w], dp[w - W[i]] + V[i]);
        }
    }

    cout << dp[K] << "\n";
    return 0;
}
