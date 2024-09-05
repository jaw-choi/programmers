#include <iostream>
#include <vector>
using namespace std;

int DP[100001];
int solution(vector<int> sticker)
{
    if(sticker.size()==1)
        return sticker[0];
    if(sticker.size()==2)
        return max(sticker[0],sticker[1]);
    int answer =0;
    DP[0]=sticker[0];
    DP[1]=sticker[0];
    for(int i=2;i<sticker.size()-1;i++)
    {
        DP[i] = max(DP[i-2] + sticker[i], DP[i-1]);
    }
    answer = max(answer,DP[sticker.size()-2]);
    DP[0]=0;
    DP[1]=sticker[1];
    for(int i=2;i<sticker.size();i++)
    {
        DP[i] = max(DP[i-2] + sticker[i], DP[i-1]);
    }
    answer = max(answer,DP[sticker.size()-1]);

    return answer;
}