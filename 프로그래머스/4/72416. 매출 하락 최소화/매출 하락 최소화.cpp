#include <string>
#include <vector>

using namespace std;
void dfs(int curr,const vector<int>& sales,const vector<vector<int>>& graph, vector<vector<int>>& dp)
{
    bool isLeaf = true;
    for(int i=0;i<graph[curr].size();i++){
        int next = graph[curr][i];
        isLeaf = false;
        dfs(next,sales,graph,dp);
    }
    if(isLeaf){
        dp[curr][0]=0;
        dp[curr][1]=sales[curr-1];
        return;
    }
    int sum = 0;
    int minCost = 987654321;
    bool attend = true;
    for(int i=0;i<graph[curr].size();i++)
    {
        int child = graph[curr][i];
        sum += min(dp[child][0],dp[child][1]);
        if(dp[child][0]>=dp[child][1])
            attend = false;
        minCost = min(minCost,dp[child][1]-dp[child][0]);
    }
    dp[curr][1] = sales[curr-1] + sum;
    if(!attend)
        dp[curr][0]=sum;
    else
        dp[curr][0]=sum+minCost;
}
int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    int n = sales.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    vector<vector<int>> graph(n+1);
    for(auto l : links)
        graph[l[0]].push_back(l[1]);
    dfs(1,sales,graph,dp);
    answer = min(dp[1][0],dp[1][1]);
    return answer;
}