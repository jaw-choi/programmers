#include <string>
#include <vector>

using namespace std;

int answer = 0;
void fall(int m, int n, vector<string>& board)
{
    int tmp = 0;
    char tmpChar = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (board[i][j] == '@' && i != 0)
            {
                tmp = i;
                while (tmp != -1 && board[tmp][j]=='@')
                {
                    tmp--;
                }
                if (tmp == -1)
                    continue;
                board[i][j] = board[tmp][j];
                board[tmp][j] = '@';
            }

        }
    }
}

void bomb(vector<vector<bool>>& visited, int m, int n, vector<string>& board)
{
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (visited[i][j])
            {
                if (board[i][j] != '@')
                    answer++;
                if (board[i][j + 1] != '@')
                    answer++;
                if (board[i + 1][j] != '@')
                    answer++;
                if (board[i + 1][j + 1] != '@')
                    answer++;
                board[i][j] = '@';
                board[i][j + 1] = '@';
                board[i + 1][j] = '@';
                board[i + 1][j + 1] = '@';
                visited[i][j] = false;
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {

    vector<vector<bool>> visited(m, (vector<bool>(n, false)));
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (board[i][j] == board[i][j] &&
                    board[i][j] == board[i][j + 1] &&
                    board[i][j] == board[i + 1][j] &&
                    board[i][j] == board[i + 1][j + 1]
                    && board[i][j]!= '@') {
                    visited[i][j] = true;
                    flag = true;
                }

            }
        }
        if (!flag)
            break;
        //check 후 만족하면  0 으로
        //하고 다시 다 false로
        bomb(visited, m, n, board);
        //0일때 가장 가까운 i-...알파벳을 그 자리로
        fall(m, n, board);

    }
    return answer;
}
//CCBDE
//AAADE
//AAABF
//CCBBF

//CCBDE
//000DE
//000BF
//CCBBF

//000DE
//000DE
//CCBBF
//CCBBF

//0000E
//0000E
//000DF
//000DF