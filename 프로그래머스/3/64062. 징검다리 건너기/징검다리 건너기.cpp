#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 1;
    int right = *max_element(stones.begin(),stones.end());

    while(left<=right)
    {
        int mid = (right-left)/2 + left;
        bool flag = true;
        int cnt = 0;
        for(auto& s :stones)
        {
            if(s<mid){
                cnt++;
                if(cnt>=k)
                {
                    flag = false;
                    break;
                }
            }
            else
                cnt=0;
        }
        if(flag)
        {
            answer = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
        //cout << mid <<endl;
    }
    return answer;
}