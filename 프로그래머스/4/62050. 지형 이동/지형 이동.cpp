#include <string>
#include <vector>
#include <tuple>
#include <cmath>
#include <queue>
#include <iostream>

using namespace std;
vector<int> dirY = {-1,1,0,0};
vector<int> dirX = {0,0,-1,1};


int solution(vector<vector<int>> land, int height) {
    int ans = 0;
    int n = land.size();
    vector<vector<int>> visited(n,vector<int>(n,0));

    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    pq.push({0,0,0});//height,y,x
    while(!pq.empty())
    {
        auto [curr_height,y,x] = pq.top();
        pq.pop();
        
        if(visited[y][x]==1) continue;
        
        visited[y][x]=1;
        ans+=curr_height;

        for(int i=0;i<4;i++)
        {
            int nextY = y + dirY[i];
            int nextX = x + dirX[i];
            
            if(nextY<0 || nextY>=n || nextX<0 || nextX>=n) continue;
            if(visited[nextY][nextX]!=0) continue;
            int diff = abs(land[y][x] - land[nextY][nextX]);

            if(diff <=height)
                pq.push({0,nextY,nextX});
            else
                pq.push({diff,nextY,nextX});
        }
    }
    
        
    return ans;
}
