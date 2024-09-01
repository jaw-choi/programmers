#include <string>
#include <vector>
#define MAX 1000001

using namespace std;

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
    answer = dp[x];
    
    if(answer==MAX)
        return -1;   
    return answer;
}