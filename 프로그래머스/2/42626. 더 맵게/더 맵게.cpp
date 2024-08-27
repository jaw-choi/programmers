#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto s : scoville)
    {
        pq.push(s);
    }
    
    while(true)
    {
        if(pq.size()==1 && pq.top() < K)
            return -1;
        if(pq.top() >= K)
            return answer;
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int newFood = a + (2 * b);
        pq.push(newFood);
        answer++;
    }
    
    return answer;
}