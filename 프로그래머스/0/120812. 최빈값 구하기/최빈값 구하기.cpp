#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int ans = 0;
    sort(array.begin(),array.end());
    map<int,int> mp;
    for(auto a: array)
        mp[a]++;
    map<int,int> cnt;
    for(auto m : mp)
    {
        if(m.second > answer){
            answer = m.second;
            ans = m.first;
        }
        cnt[m.second]++;
    }
    if(cnt[answer]>1)
        return -1;
    return ans;
}