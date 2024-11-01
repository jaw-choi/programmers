#include <string>
#include <vector>

using namespace std;
void DFS(int from,int n,vector<bool>& visited,const vector<vector<int>>& computers)
{
    visited[from]=true;
    for(int i=0;i<n;i++)
    {
        if(from!=i&&computers[from][i]==1 && visited[i]==false)
            DFS(i,n,visited,computers);
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==true)
            continue;
        answer++;
        
        DFS(i,n,visited,computers);
    }
    
    return answer;
}