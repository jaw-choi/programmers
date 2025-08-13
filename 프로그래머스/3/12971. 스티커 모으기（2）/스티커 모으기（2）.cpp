#include <iostream>
#include <vector>
using namespace std;

static int linearDP(const vector<int>& stickers, int startIdx, int endIdx) {
    int prevMax = 0;      // dp[i-1]
    int prevPrevMax = 0;  // dp[i-2]
    for (int i = startIdx; i <= endIdx; ++i) {
        int currentMax = max(prevMax, prevPrevMax + stickers[i]);
        prevPrevMax = prevMax;
        prevMax = currentMax;
    }
    return prevMax;
}

int solution(vector<int> sticker) {
    int n = (int)sticker.size();
    if (n == 1) return sticker[0];
    if (n == 2) return max(sticker[0], sticker[1]);
    
    int case1 = linearDP(sticker, 0, n - 2);
    int case2 = linearDP(sticker, 1, n - 1);
    return max(case1, case2);
}