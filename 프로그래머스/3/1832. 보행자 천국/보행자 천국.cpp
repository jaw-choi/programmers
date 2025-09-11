#include <vector>
using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(2, 0)));

    dp[1][1][0] = 1;
    dp[1][1][1] = 1;

    for(int y=1; y<=m; y++){
        for(int x=1; x<=n; x++){
            if(y==1 && x==1) continue;
            if(city_map[y-1][x-1]==0)
            {
                dp[y][x][0] = (dp[y-1][x][0] + dp[y][x-1][1]) % MOD;
                dp[y][x][1] = (dp[y-1][x][0] + dp[y][x-1][1]) % MOD;
            }
            else if(city_map[y-1][x-1] == 1) continue;
            else{
                dp[y][x][0] = (dp[y-1][x][0]) % MOD;
                dp[y][x][1] = (dp[y][x-1][1]) % MOD;
            }
        }
    }

    return (dp[m][n][1]) % MOD;
}
