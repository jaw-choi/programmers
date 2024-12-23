#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> dp(n+1,0);
    dp[0]=1;
    sort(money.begin(),money.end());
    for(int j=0;j<money.size();j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i-money[j] <0)
                continue;
            dp[i] += dp[i-money[j]]%1000000007;
        }
    }
    
   
    return dp[n];
}