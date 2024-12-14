#include <string>
#include <vector>
#include <iostream>

using namespace std;


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    int dp[n][n];
    dp[0][0] = triangle[0][0];
    cout <<dp[0][0]<<endl;
    for(int i=1;i<triangle.size();i++)
    {
        for(int j=0;j<triangle[i].size();j++)
        {
            if(j==0){
                dp[i][j] = triangle[i][j] + dp[i-1][j];
            }
            else if(j==triangle[i].size()-1){
                dp[i][j] = triangle[i][j] + dp[i-1][j-1];
            }
            else{
                dp[i][j] = triangle[i][j] + max(dp[i-1][j-1],dp[i-1][j]);
            }
        }
    }
    for(auto v:dp[triangle.size()-1])
        answer = max(answer,v);
    return answer;
}