#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
#define MAX 500000
long long DP[MAX];
long long DP2[MAX];
long long solution(vector<int> sequence) {
    if(sequence.size()==1)
        return max(sequence[0],-sequence[0]);
    long long answer1 = -100001;
    long long answer2 = -100001;
    long long answer = -100001;
    vector<int>purse1 = sequence;
    vector<int>purse2 = sequence;
    int num = -1;
    for(auto& p : purse1){
        p *= num;
        num*=-1;
    }
    for(auto& p : purse2){
        num*=-1;
        p *= num;
    }

    DP[0] = purse1[0];
    DP2[0] = purse2[0];
    for(int i = 1;i < purse1.size();i++)
    {
        DP[i] = max(DP[i-1] + (long long)purse1[i],(long long)purse1[i]);
        if(answer1 < DP[i])
            answer1 = DP[i];
        
    }
    for(int i = 1;i < purse2.size();i++)
    {
        DP2[i] = max(DP2[i-1] + (long long)purse2[i], (long long)purse2[i]);
        if(answer2 < DP2[i])
            answer2 = DP2[i];
        
    }
    return max(answer1,answer2);
}
//-2,3,6,1,-3
//dp[0]=-2
//dp[1]=1or3
//dp[2]=9or6
//dp[3]=10or1
//dp[4]=7,-3
//2,-3,-6,-1,3