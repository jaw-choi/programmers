#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    long long MOD = 1000000007;
    vector<vector<int>> dp(n,vector<int>(m,0));
    dp[0][0] = 1;
    for(auto p : puddles)
        dp[p[1]-1][p[0]-1] = -1;
    for(int i=0;i<m;i++)
    {
        if(dp[0][i]==-1)
            break;
        else
            dp[0][i]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(dp[i][0]==-1)
            break;
        else
            dp[i][0]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(dp[i][j]==-1) continue;
            if(dp[i-1][j] == -1)
                dp[i][j] = dp[i][j-1];
            else if(dp[i][j-1] == -1)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = (dp[i-1][j] % MOD + dp[i][j-1] % MOD) % MOD;
        }
    }
    return dp[n-1][m-1];
}