#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char ,int>mp;
    int cnt = 0;
    for(auto s :  skill)
    {
        mp[s] = cnt++;
    }
    for(auto sk : skill_trees)
    {
        int num = 0;
        for(int i=0;i<sk.length();i++)
        {
            if(mp.find(sk[i])!=mp.end())
            {
                if(mp[sk[i]]==num)
                    num++;
                else
                    break;
            }
            if(i==sk.length()-1){
                cout << sk <<endl;
                answer++;
            }
        }
    }
    return answer;
}