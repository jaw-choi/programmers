#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 999999
#define  UP 0
#define  DOWN 1
#define  LEFT 2
#define  RIGHT 3
using namespace std;
struct POS{
  int y,x,cost,dir;  
};
struct cmp{
    bool operator()(const POS& a, const POS& b)
    {
        return a.cost > b.cost;
    }
};


int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    
    int dirY[4] = {-1,1,0,0};
    int dirX[4] = {0,0,-1,1};
    
    int cost[25][25][4]; 
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < 4; ++k)
                cost[i][j][k] = INF;
    for (int i = 0; i < 4; ++i) // 출발지 4 방향 0 으로 초기화
        cost[0][0][i] = 0;
    
    priority_queue<POS,vector<POS>,cmp> pq;
    pq.push({0,0,0,-1});
    
    while(!pq.empty())
    {
        POS now = pq.top();
        pq.pop();
        
        for(int i=0;i<4;i++)
        {
            int nextY = now.y + dirY[i];
            int nextX = now.x + dirX[i];
            int nextDir = i;
            int nextCost = now.cost;
            
            if(nextY < 0 || nextY >=n || nextX< 0||nextX>=n || board[nextY][nextX]==1)
                continue;
            
            nextCost+=100;
            
            if(now.dir == UP || now.dir == DOWN)
                if(nextDir==LEFT || nextDir==RIGHT)
                    nextCost+=500;
            if(now.dir == LEFT || now.dir == RIGHT)
                if(nextDir==UP || nextDir==DOWN)
                    nextCost+=500;
            if (nextCost < cost[nextY][nextX][nextDir]) {
                cost[nextY][nextX][nextDir] = nextCost;
                pq.push({ nextY, nextX, nextCost, nextDir });
            }
        }
    }
    answer = *min_element(cost[n - 1][n - 1], cost[n - 1][n - 1] + 4);
    return answer;
}