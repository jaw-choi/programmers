#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool helper(const int n,const long long total,const vector<int>& times)
{
    long long num = 0;
    for(int i=0;i<times.size();i++)
    {
        num += total / times[i];
    }
    return n <= num;
}
long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    
    long long left = 0;
    long long right = 1e18;
    long long mid;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(helper(n,mid,times))
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return answer;
}