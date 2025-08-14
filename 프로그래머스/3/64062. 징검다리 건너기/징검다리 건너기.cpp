#include <string>
#include <vector>

using namespace std;
bool helper(int mid, vector<int>& stones,int k)
{
    int cnt = 0;
    for(int i=0;i<stones.size();i++){
        if(stones[i] <= mid)
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
    int left = 0;
    int right = 200000000;
    while(left <= right)
    {
        int mid = (right-left)/2 + left;
        if(!helper(mid,stones,k))
            right = mid - 1;
        else
            left = mid + 1;
        
    }
    return left;
}