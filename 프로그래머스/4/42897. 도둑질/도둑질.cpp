#include <string>
#include <vector>

using namespace std;
int helper(const vector<int>& money)
{
    int n = money.size();
    vector<int> dp(n,0);
    
    dp[0] = money[0];
    dp[1] = money[0]>money[1]? money[0]:money[1];
    for(int i=2;i<n;i++)
    {
        dp[i] = max(dp[i-1],dp[i-2]+money[i]);
    }
    return dp[n-1];
}
int solution(vector<int> money) {
    if(money.size()==3)
        return max(money[0],max(money[1],money[2]));
    vector<int> a(money.begin(),money.end()-1);
    vector<int> b(money.begin()+1,money.end());
    return max(helper(a),helper(b));
}