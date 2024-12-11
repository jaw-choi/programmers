#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool helper(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t,long long mid)
{
    long long totalGold=0;
    long long totalSilver=0;
    long long totalMineral=0;
    for(int i=0;i<g.size();i++)
    {
        long long time = t[i];
        long long roundTime = t[i]*2;
        long long cnt = mid /roundTime;
        if(mid % roundTime >=time)
            cnt++;
        long long maxTry = cnt * w[i];
        totalGold += min((long long)g[i],maxTry);
        totalSilver += min((long long)s[i],maxTry);
        totalMineral += min((long long)g[i]+s[i],maxTry);
    }
    if(totalGold>=a&&totalSilver>=b&&totalMineral>=a+b)
        return true;
    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = 0;
    long long left = 0;
    //(10^5 * 2) * ((2 * 10^9) / 1) + 10^5
    long long right = 10e15;
    long long mid;
    answer = right;
    while(left<=right)
    {
        mid = (left+right)/2;
        if(helper(a,b,g,s,w,t,mid))
        {
            answer = min(answer,mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return answer;
}