#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0,100001};
    set<string> s;
    map<string,int> mp;
    int left=0;
    for(auto& g : gems)
    {
        s.insert(g);
    }
    int size_ = s.size();
    for(int right=0;right<gems.size();right++)
    {
        mp[gems[right]]++;
        if(mp.size()==size_){
            while(mp.size()==size_){
            if(answer[1]-answer[0] > right - left){
                answer = {left+1,right+1};
            }
                mp[gems[left]]--;
                if(mp[gems[left]]==0){
                    mp.erase(gems[left]);
                }
                left++;
            }
        }
    }
    return answer;
}