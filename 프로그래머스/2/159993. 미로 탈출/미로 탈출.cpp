#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
int solution(vector<string> maps) {
    int answer = 0;
    int m = maps.size();
    int n = maps[0].size();
    queue<pair<int,pair<int,int>>> q;
    pair<int,int> start;
    vector<vector<int>> visited(m,vector<int>(n,false));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(maps[i][j]=='S')
                start = {i,j};
    q.push({0,{start}});
    visited[start.first][start.second] = true;
    bool isLever = false;
    while(!q.empty())
    {
        int currX = q.front().second.second;
        int currY = q.front().second.first;
        int cost = q.front().first;
        q.pop();
        if(!isLever && maps[currY][currX]=='L')
        {
            fill(visited.begin(), visited.end(), vector(visited[0].size(), 0));
            visited[currY][currX] = true;
            q = queue<pair<int,pair<int,int>>>();
            isLever = true;                        
        }
        else if(maps[currY][currX]=='E' && isLever){
            if(isLever==true){
                return cost;
            }                    
        }
        for(int i=0;i<4;i++)
        {
            int nextX = currX + dir[i].second;
            int nextY = currY + dir[i].first;
            if(nextY >=0 && nextY < m && nextX >=0 && nextX <n)
            {
                if(visited[nextY][nextX]==false && maps[nextY][nextX]!='X'){
                    visited[nextY][nextX] = true;
                    q.push({cost+1,{nextY,nextX}});
                }
            }
        }
    }
    if(answer==0)
        return -1;
    return answer;
}