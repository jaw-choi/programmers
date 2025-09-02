#include <string>
#include <vector>

using namespace std;


    int getMax(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);

        dp[0]=nums[0];
        dp[1]= dp[0] > nums[1] ? dp[0] : nums[1];
        for(int i=2;i<n;i++)
        {
            if(dp[i-2]+nums[i] > dp[i-1])
                dp[i] = dp[i-2]+nums[i];
            else
                dp[i] = dp[i-1];
        }
        return dp[n-1];
    }
int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        if(n==3)
            return max(nums[2],max(nums[0],nums[1]));
        vector<int> a(nums.begin(),nums.end()-1);
        vector<int> b(nums.begin()+1,nums.end());
       return max(getMax(a),getMax(b));
    }
int solution(vector<int> money) {
    return rob(money);
}
