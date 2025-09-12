#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool canCross(int mid, int k, const vector<int>& stones)
{
    int cnt = 0;
    for(auto& s : stones)
    {
        if(s<=mid)
            cnt++;
        else
            cnt = 0;
        if(cnt>=k)
            return false;
    }
    return true;
    
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 1, right = *max_element(stones.begin(),stones.end());
    
    while(left<=right)
    {
        int mid = (right-left)/2 + left;
        
        if(canCross(mid,k,stones))
        {
            answer = mid;
            left = mid + 1;
        }
        else
            right = mid-1;
    }
    return left;
}