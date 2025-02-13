#include <string>
#include <vector>
int answer = 0;
using namespace std;
void dfs(int curr,int k, vector<int>& visited,vector<vector<int>> dungeons)
{
    if(curr > answer)
        answer = curr;
    for(int i = 0;i<dungeons.size();i++)
    {
        if(dungeons[i][0]<=k && visited[i]==0)
        {
            visited[i]=1;
            dfs(curr+1,k-dungeons[i][1],visited,dungeons);
            visited[i]=0;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    vector<int> visited(dungeons.size(),0);
    dfs(0,k,visited,dungeons);
    return answer;
}