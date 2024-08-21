#include <string>
#include <vector>
#include <queue>
#define MAX 8
int answer = 0;
bool visited[MAX] = {false};
using namespace std;
void DFS(int count,int k, vector<vector<int>> dungeons)
{
    if(count > answer)
        answer = count;
    for(int i=0;i<dungeons.size();i++)
    {
        if(k>=dungeons[i][0] && !visited[i]){
            visited[i]=true;
            DFS(count+1,k-dungeons[i][1],dungeons);
            visited[i]=false;
        }
            
        
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    DFS(0,k,dungeons);
    return answer;
}