#include <string>
#include <vector>

#define MAX 1000001

using namespace std;
int helper(int x, int y, int n, int ans)
{
    if(x==y)
        return ans;
    
    if(x*3 <= y)
        return helper(x*3,y,n,ans+1);
    if(x*2 <= y)
        return helper(x*2,y,n,ans+1);
    if(x+n <= y)
        return helper(x+n,y,n,ans+1);
}
int solution(int x, int y, int n) {
    vector<int> dp(MAX,MAX);
    int answer = 0;
    dp[y]=0;
    for(int i = y;i>x;i--)
    {
        if(dp[i]!=MAX)
        {
            if(i%3==0)
                dp[i/3] = min(dp[i]+1,dp[i/3]);
            if(i%2==0)
                dp[i/2] = min(dp[i]+1,dp[i/2]);
            if(i-n>0)
                dp[i-n] = min(dp[i]+1,dp[i-n]);
        }
    }
    if(dp[x]==MAX)
        return -1;   
    answer = dp[x];
    return answer;
}