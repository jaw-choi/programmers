#include <string>
#include <vector>

using namespace std;
//1 - Attack
//2 - Heal
//r1,c1 start
//r2,c2 end
//degree - amount
//0이하면 파괴된건물
//else 파괴x
//return 파괴x 수


int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int sum[1002][1002];
    int type;
    int x1,x2,y1,y2;
    int degree;
    for(auto s : skill)
    {
        type = s[0];
        x1 = s[1];
        y1 = s[2];
        x2 = s[3];
        y2 = s[4];
        degree = s[5];
        degree = type == 1 ? degree * -1 : degree;
        sum[x1][y1] += degree;
        sum[x2+1][y2+1] += degree;
        sum[x1][y2+1] -= degree;
        sum[x2+1][y1] -= degree;
    }
    for (int i = 0; i <= board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            sum[i][j + 1] += sum[i][j];
        }
    }
 
    for (int j = 0; j <= board[0].size(); j++) {
        for (int i = 0; i < board.size(); i++) {
            sum[i + 1][j] += sum[i][j];
        }
    }
    
    for(int i=0;i<board.size();i++)//100
    {
        for(int j=0;j<board[0].size();j++)//100
        {
            if(board[i][j]+sum[i][j]>0)
                answer++;
        }
    }
    
    return answer;
}