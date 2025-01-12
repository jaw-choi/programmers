#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(int idx, const vector<string>& enroll, const vector<string>& referral, unordered_map<string, int>& mpIndex, int profit, vector<int>& answer) {
    if (profit == 0) return; // Base case
    int share = profit / 10;
    answer[idx] += profit - share; // Current profit calculation
    if (referral[idx] != "-" && share > 0) { // Recursively call if valid referral
        dfs(mpIndex[referral[idx]], enroll, referral, mpIndex, share, answer);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    unordered_map<string, int> mpIndex;

    // Map each person to their index
    for (int i = 0; i < enroll.size(); i++) {
        mpIndex[enroll[i]] = i;
    }

    // Process sellers
    for (int i = 0; i < seller.size(); i++) {
        int idx = mpIndex[seller[i]];
        int profit = amount[i] * 100;
        dfs(idx, enroll, referral, mpIndex, profit, answer);
    }

    return answer;
}
