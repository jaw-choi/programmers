#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 1;
    int right = *max_element(stones.begin(),stones.end());
    int consecutive = 0;
    bool ok = true;
    while(left<=right)
    {
        int mid = (right-left)/2 + left;
        consecutive = 0;
        ok = true;
        for(auto& s : stones)
        {
            if(s < mid)
            {
                consecutive++;
                if(consecutive>=k){
                    ok = false;
                    break;
                }
            }
            else{
                consecutive = 0;
            }
        }
        if(ok){
            answer = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return answer;
}