#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 40000
using namespace std;
vector<int> dirY = {-1,1,0,0};
vector<int> dirX = {0,0,-1,1};

pair<int, int> move(int currY,int currX,int nextY,int nextX,const vector<string>& board)
{
    currY = currY + nextY;
    currX = currX + nextX;

    while (currY >= 0 && currY < board.size() && currX >= 0 && currX < board[0].size() && board[currY][currX] != 'D') {

        currY = currY + nextY;
        currX = currX + nextX;
    }
    currY = currY - nextY;
    currX = currX - nextX;
    return {currY,currX};
}

void bfs(int& answer,pair<int,int> start, pair<int,int> goal,vector<vector<bool>> visited,const vector<string>& board)
{
    
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{start.first,start.second}});
    visited[start.first][start.second] = true;
    while(!pq.empty())
    {
        int tryNum = pq.top().first;
        int currY = pq.top().second.first;
        int currX = pq.top().second.second;
        pq.pop();

        //if(tryNum > answer)
            //continue;
        if(make_pair(currY,currX) == goal){
            answer = tryNum;
            return;
        }
        
        for(int i=0;i<4;i++)
        {
            int nextY = currY + dirY[i];
            int nextX = currX + dirX[i];
            if(nextY < 0 || nextY >= board.size() || nextX <0 || nextX >= board[0].size())
                continue;
            pair<int,int> a = move(currY,currX,dirY[i],dirX[i],board);
            
            if(visited[a.first][a.second]==true)
                continue;
            
            //cout << a.first << " "<<a.second <<" "<<tryNum<< endl;
            pq.push({tryNum+1,{a.first,a.second}});
            visited[a.first][a.second] = true;
        }
    }
}

int solution(vector<string> board) {
    int answer = -1;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    pair<int,int> start;
    pair<int,int> goal;
    for(int y=0;y<board.size();y++)
        for(int x=0;x<board[0].size();x++){
            if(board[y][x]=='R')
                start = {y,x};
            if(board[y][x]=='G')
                goal = {y,x};
        }
    bfs(answer,start,goal,visited,board);
    return answer;
}