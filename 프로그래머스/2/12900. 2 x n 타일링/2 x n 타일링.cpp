#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(int n) {
    int answer = 0;
    int dp[60001] = {0};
    dp[1]=1;
    dp[2]=2;
    if(n==1)
        return dp[1];
    if(n==2)
        return dp[2];
    for(int i=3;i<=n;i++)
    {
        dp[i] = (dp[i-1] + dp[i-2])% 1000000007;
    }
    return dp[n] ;
}
//1 1가지
//2 11,2 2가지
//3 111,12,21 3가지
//4 1111, 112,121,211,22 5가지
// 11111, 1112,1121,1211,2111,122,212,221
//5 11111,1112,1121,1211,2111,122,212,221 8가지
//점프 1칸 or 2칸
//n=4
//1111
//112
//121
//211
//22
//5가지