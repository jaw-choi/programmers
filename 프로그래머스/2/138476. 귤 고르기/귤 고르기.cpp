#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int num = tangerine.size() - k;
    map<int,int> mp;
    for(auto t:tangerine)
        mp[t]++;
    vector<pair<int,int>> v;
    for(auto m : mp)
        v.push_back({m.second,m.first});
    sort(v.begin(),v.end(),greater<pair<int,int>>());

    
     int count = 0;
    for (auto vv : v) {
        k -= vv.first;
        count++;
        if (k <= 0) {
            answer = count;
            break;
        }
    }
    
    return answer;
}