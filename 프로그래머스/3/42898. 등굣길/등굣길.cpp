#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int mod = 1e9 + 7;
    set<pair<int,int>> pud;
    for(auto& p : puddles)
    {
        pud.insert({p[0],p[1]});
    }
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    dp[1][1]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(pud.find({i,j})!=pud.end()) continue;
            if(i>1&&j>1)
                dp[i][j]=(dp[i][j-1] + dp[i-1][j])%mod;
            else if(i>1)
                dp[i][j] = dp[i-1][j];
            else if(j>1)
                dp[i][j] = dp[i][j-1];
                
        }
    }
    return dp[m][n];
}