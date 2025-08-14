#include <string>
#include <vector>
#include <algorithm>
#include <map>
//#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
    if(k==1)
        return *min_element(stones.begin(),stones.end());
    
    map<int,int> mp;
    for(int i=0;i<k;i++)
    {
        mp[stones[i]]++;
    }
    int answer = mp.rbegin()->first;
    for(int i=k;i<stones.size();i++)
    {
        mp[stones[i]]++;
        mp[stones[i-k]]--;
        if(mp[stones[i-k]]==0)
            mp.erase(stones[i-k]);
        if(answer>mp.rbegin()->first)
            answer = mp.rbegin()->first;
    }
    return answer;
}