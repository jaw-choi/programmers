#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left= 0;
    long long right = (long long)n * (1e9);
    long long cnt = 0;
    while(left<=right)
    {
        long long mid = (long long)(right-left)/2 + left;
        cnt = 0;
        for(int i=0;i<times.size();i++)
        {
            cnt += (long long)(mid/times[i]);
        }
        if(cnt >= n)
        {
            answer = mid;
            right = mid - 1;
        }
        else
            left = mid+1;
        //cout << answer <<endl;
    }
    return answer;
}