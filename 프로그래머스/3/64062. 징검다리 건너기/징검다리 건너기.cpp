#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    
    int begin = *min_element(stones.begin(),stones.end());
    int end = *max_element(stones.begin(),stones.end());
    int mid = 0;
    int cnt = 0;
    int maxSkip = 0;
    int answer=0;
    while(begin<=end)
    {
        mid = (begin+end)/2;
        
        cnt=0;
        maxSkip=0;
        for(int i=0;i<stones.size();i++)
        {
            if(stones[i] < mid)
                cnt++;
            else
                cnt=0;
            maxSkip = max(maxSkip,cnt);
        }
        
        if(maxSkip < k){
            begin = mid+1;
            answer = max(answer,mid);
        }
        else{
            end = mid - 1;
        }
    }
    return answer;
}
