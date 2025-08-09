#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto& s : scoville)
        pq.push(s);
    while(pq.top()<K)
    {
        int first = pq.top();
        pq.pop();
        if(pq.empty())
            return -1;
        int second = pq.top();
        pq.pop();
        int result = first + (second * 2);
        pq.push(result);
        answer++;
    }
    return answer;
}