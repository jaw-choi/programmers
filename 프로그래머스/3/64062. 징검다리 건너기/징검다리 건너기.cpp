#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;

    int begin = *min_element(stones.begin(), stones.end());
    int end = *max_element(stones.begin(), stones.end());
    int mid;
    while (begin <= end) {
        mid = (begin + end) / 2;

        int skip_count = 0;
        int max_skip_count = 0;
        vector<int> tmp(stones);
        for (int i = 0; i < tmp.size(); i++) {
            tmp[i] -= mid;
            if (tmp[i] < 0)
                skip_count++;
            else
                skip_count = 0;
            max_skip_count = max(max_skip_count, skip_count);
        }

        if (max_skip_count < k) {
            answer = max(answer,mid);
            begin = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return answer;
}
