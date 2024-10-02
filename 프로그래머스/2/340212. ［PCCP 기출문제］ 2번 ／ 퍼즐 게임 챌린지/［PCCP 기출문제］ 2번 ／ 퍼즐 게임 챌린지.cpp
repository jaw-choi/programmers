#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

long long func(int n, vector<int> diffs, vector<int> times)
{
    long long ans = 0;
    for(int i=0;i<diffs.size();i++)
    {
        if(diffs[i] <= n)
        {
            ans += times[i];
        }
        else
        {
            ans += (diffs[i] - n) * (times[i] + times[i-1]) + times[i];
        }
    }
    return ans;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int start = 1;
    int end = *max_element(diffs.begin(),diffs.end());
    cout <<end;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(func(mid,diffs,times) <= limit) // 실력이 너무 좋음 -> 낮춰도 됨
        {
            answer = mid;
            end = mid - 1;
        }
        else // 실력이 안좋음 -> 더 키워야 됨
        {
            start = mid + 1;
        }
    }
    return answer;
}