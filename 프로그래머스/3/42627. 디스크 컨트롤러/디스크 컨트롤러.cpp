#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(),jobs.end());
    using T = tuple<int,int,int>; // (소요시간, 요청시각,작업번호)
    priority_queue<T, vector<T>, greater<T>> pq;

    long long totalWait = 0;
    int n = (int)jobs.size();
    int idx = 0;            // 아직 큐에 넣지 않은 다음 작업의 인덱스
    long long now = 0;      // 현재 시각
    int done = 0;           // 완료한 작업 수
    while(done < n)
    {
        while(idx< n && jobs[idx][0] <= now){
            pq.push(make_tuple(jobs[idx][1], jobs[idx][0],idx));
            ++idx;
        }
        
        if(pq.empty()){
            now = max<long long>(now,jobs[idx][0]);
            continue;
        }
        auto [dur,req,numIdx] = pq.top();
        pq.pop();
        now += dur;
        totalWait += (now - req);
        ++done;
    }
    return totalWait / n;
}


//소요시간,작업요청시각,작업번호




