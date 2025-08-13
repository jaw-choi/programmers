#include <iostream>
#include <vector>
using namespace std;
int dp(vector<int>& v,int start, int end)
{
    int prevMax = 0;
    int prevprevMax = 0;
    for(int i= start;i<=end;i++)
    {
        int currMax = max(prevMax,prevprevMax + v[i]);
        prevprevMax = prevMax;
        prevMax = currMax;
    }
    return prevMax;
}
int solution(vector<int> sticker)
{
    int answer =0;
    int n = sticker.size();
    if(n==1) return sticker[0];
    if(n==2) return max(sticker[0],sticker[1]);
    int case1 = dp(sticker,0,n-2);
    int case2 = dp(sticker,1,n-1);
    return max(case1,case2);
}