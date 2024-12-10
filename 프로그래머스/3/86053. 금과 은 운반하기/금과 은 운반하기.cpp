#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool helper(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t,long long mid){
    long long totalGold=0;
    long long totalSilver=0;
    long long totalMineral=0;
    
    for(int i=0;i<g.size();i++)
    {
        long long time = t[i];
        
        long long roundTime = time*2;
        long long cnt = mid / roundTime;
        if(mid%roundTime >= time) cnt++;
        long long maxTake = cnt * w[i];
        
        totalGold += min((long long)g[i],maxTake);
        totalSilver += min((long long)s[i],maxTake);
        totalMineral += min((long long)(g[i]+s[i]),maxTake);
    }
    if(totalGold >=a && totalSilver >=b && totalMineral >= a+b)
        return true;
    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = 0;

    long long left,right,mid,cnt;
    left = 0;
    right = 10e14*3;
    answer = right;
    while(left<=right)
    {
        mid = (left+right) / 2;
        if(helper(a,b,g,s,w,t,mid)==true){
            answer = min(answer,mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return answer;
}