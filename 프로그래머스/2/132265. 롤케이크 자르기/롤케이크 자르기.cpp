#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int,int> mp1;
    unordered_map<int,int> mp2;
    for(auto t : topping)
    {
        mp1[t]++;
    }
    for(int i=0 ;i<topping.size();i++)
    {
        if(mp1.find(topping[i])!=mp1.end())
        {
            mp1[topping[i]]--;
            mp2[topping[i]]++;
            if(mp1[topping[i]] ==0)
                mp1.erase(topping[i]);            
        }
        if(mp1.size()==mp2.size())
            answer++;
    }
    return answer;
}