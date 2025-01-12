#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(int idx, const vector<string>& referral, unordered_map<string, int>& mpIndex, int profit, vector<int>& answer) 
{
    if (profit == 0) return;
    int share = profit / 10;
    answer[idx] += profit - share;
    if (referral[idx] != "-" && share > 0) {
        dfs(mpIndex[referral[idx]], referral, mpIndex, share, answer);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(),0);
    unordered_map<string,int> mpIndex;

    for(int i=0;i<enroll.size();i++){
        mpIndex[enroll[i]] = i;        
    }
    
    for(int i=0;i<seller.size();i++)
    {
        int idx = mpIndex[seller[i]];
        int profit = amount[i]*100;
        dfs(idx, referral, mpIndex, profit, answer);

    }
    
    return answer;
}