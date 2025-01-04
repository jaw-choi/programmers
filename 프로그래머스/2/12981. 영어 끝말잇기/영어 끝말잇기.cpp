#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_map<string,int> mp;
    int turn = 1;
    int person = 1;
    
    for(int i=0;i<words.size();i++)
    {
        if(i!=0){
            char prev = words[i-1][words[i-1].length()-1];
            char curr = words[i][0];
            if(prev!=curr)
                return {person,turn};
        }            
        if(mp.find(words[i])!=mp.end())
            return {person,turn};
        
        mp[words[i]]++;        
        person++;
        if(person==n+1){
            person=1;
            turn++;
        }
    }
    return {0,0};
}