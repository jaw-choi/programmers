#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#define MAX 500
using namespace std;

bool visited[MAX] = {false};

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int i=0;
    int time=0;
    sort(jobs.begin(),jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> q;
    while(i < jobs.size() || !q.empty())
    {
        if(i < jobs.size() && time >= jobs[i][0])
        {
            q.push(jobs[i++]);
            continue;
        }
        if(!q.empty())
        {
            time += q.top()[1];
            answer += time - q.top()[0];
            q.pop();
        }
        else
        {
            time = jobs[i][0];
        }
    }
    return answer / jobs.size();
}