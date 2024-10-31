#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int ans = 0;
    int MaxN = 0;

    map<int,int> mp;
    for(auto a: array)
        mp[a]++;
    for(auto m : mp)
    {
        if(m.second > MaxN){
            MaxN = m.second;
            ans = m.first;
        }
        else if(m.second == MaxN){
            ans = -1;
        }
    }
    return ans;
}