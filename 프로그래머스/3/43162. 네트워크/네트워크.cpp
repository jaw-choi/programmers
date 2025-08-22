#include <string>
#include <vector>

using namespace std;
void dfs(int curr, int& ans,vector<int>& visited, const vector<vector<int>>& computers )
{
    
    for(int i=0;i<computers[curr].size();i++)
    {
        if(visited[i]==1) continue;
        if(computers[curr][i]==1){
            visited[i] = 1;
            dfs(i,ans,visited,computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visited(n,0);
    for(int i=0;i<computers.size();i++)
    {
        if(visited[i]==0){
            answer++;
            visited[i]=1;
            dfs(i,answer,visited,computers);
        }
    }
    return answer;
}