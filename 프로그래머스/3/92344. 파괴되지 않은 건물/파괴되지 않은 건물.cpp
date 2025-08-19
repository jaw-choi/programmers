#include <string>
#include <vector>

using namespace std;
void helper(vector<vector<int>>& preSum, const vector<vector<int>>& skill,int idx)
{
    int type = skill[idx][0];
    int r1 = skill[idx][1];
    int c1 = skill[idx][2];
    int r2 = skill[idx][3];
    int c2 = skill[idx][4];
    int degree = skill[idx][5];
    if(type==1)
        degree = -degree;
    
    preSum[r1][c1] += degree;
    preSum[r2+1][c1] -= degree;
    preSum[r1][c2+1] -= degree;
    preSum[r2+1][c2+1] += degree;

}
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();
    //type, r1, c1, r2, c2, degree
    vector<vector<int>> preSum(n+1,vector<int>(m+1,0));
    for(int i=0;i< skill.size();i++)
    {
        helper(preSum,skill,i);
    }
    for(int i=0;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            preSum[i][j] +=preSum[i][j-1];
        }
    }
    for(int j=0;j<m+1;j++)
    {
        for(int i=1;i<n+1;i++)
        {
            preSum[i][j] +=preSum[i-1][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            board[i][j]+=preSum[i][j];
            if(board[i][j] > 0)
                answer++;
        }
    }
    return answer;
}