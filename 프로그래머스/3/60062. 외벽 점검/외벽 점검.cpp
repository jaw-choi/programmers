#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist){
    int m = weak.size();
    vector<vector<int>> v(m+1);
    for(int i=1; i<(1<<m); i++){
        v[__builtin_popcount(i)].push_back(i);
    }
    sort(rbegin(dist), rend(dist));
    for(int k=1; k<=min(m, (int)dist.size()); k++){
        for(auto& mask: v[k]){
            vector<int> t;
            for(int b=0; b<m; b++){
                if(mask>>b&1) t.push_back(b);
            }
            priority_queue<int> pq;
            for(int i=0; i<k; i++){
                if(i < k-1) pq.push(weak[t[i+1]-1] - weak[t[i]]);
                else pq.push((t[0] ? n + weak[t[0]-1] : weak[m-1]) - weak[t[k-1]]);
            }
            int curr = 0;
            bool flag = true;
            while(!pq.empty()){
                if(pq.top() > dist[curr]){
                    flag = false;
                    break;
                }
                curr++;
                pq.pop();
            }
            if(flag) return k;
        }
    }
    return -1;
}