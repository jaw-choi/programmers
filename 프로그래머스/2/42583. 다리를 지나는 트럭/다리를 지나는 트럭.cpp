#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    int idx = 0;
    int curr_sum = 0;
    for(int i=0;i<bridge_length;i++)
        q.push(0);
    while(!q.empty())
    {
        answer++;
        curr_sum -= q.front();
        q.pop();
        if(idx < truck_weights.size())
        {
            if(curr_sum + truck_weights[idx] <= weight)
            {
                curr_sum += truck_weights[idx];
                q.push(truck_weights[idx]);
                idx++;
            }
            else
            {
                q.push(0);
            }
        }
    }
    return answer;
}