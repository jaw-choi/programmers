#include <string>
#include <vector>
#include <set>

using namespace std;
int get_Ns(int n, int idx)
{
    int ans = n;
    for(int i=0;i<idx-1;i++)
    {
        ans = ans*10 + n;
    }
    return ans;
}
void cal(vector<set<int>>& dp,int left, int right,int idx)
{
    for(auto a : dp[left])
    {
        for(auto b : dp[right])
        {
            dp[idx].insert(a + b);
            dp[idx].insert(a - b);
            dp[idx].insert(b - a);
            dp[idx].insert(a * b);
            if(b != 0) dp[idx].insert(a / b);
            if(a != 0) dp[idx].insert(b / a);
        }
    }
}
void helper(vector<set<int>>& dp,int n,int idx)
{
    int left = 1;
    int right = idx - 1;
    while(right>=1)
    {
        cal(dp,left,right,idx);
        left++;
        right--;
    }
}
int solution(int N, int number) {
    if(N==number)
        return 1;
    int answer = 0;
    vector<set<int>> dp(9);
    dp[1].insert(N);
    for(int i=2;i<=8;i++)
    {
        dp[i].insert(get_Ns(N,i));
        helper(dp,N,i);
        if(dp[i].find(number)!=dp[i].end())
            return i;
    }
    return -1;
}