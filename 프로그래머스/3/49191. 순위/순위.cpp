#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> vs(n+1,vector<int>(n+1,0));
    for(auto& r : results)
    {
        vs[r[0]][r[1]] = 1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            for(int k = 1;k<=n;k++)
            {
                if(vs[j][i]==1 && vs[i][k]==1)
                    vs[j][k]=1;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        int tmp = 0;
        for(int j = 1;j<=n;j++)
        {
            if(vs[i][j]==1)
                tmp++;
            if(vs[j][i]==1)
                tmp++;
        }
        if(tmp==n-1)
            answer++;
    }
    
    return answer;
}