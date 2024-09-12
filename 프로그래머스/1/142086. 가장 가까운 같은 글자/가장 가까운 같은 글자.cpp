#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char,int> mp;
    int index = 0;
    for(auto c : s)
    {
        if(mp.find(c)==mp.end())
            answer.push_back(-1);
        else
            answer.push_back(index - mp[c]);
        mp[c] = index;
        index++;
            
    }
    return answer;
}