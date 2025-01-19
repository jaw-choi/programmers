#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,vector<string>> mp;
    for(auto c : clothes)
        mp[c[1]].push_back(c[0]);
    for(auto m : mp)
    {
        answer *= (m.second.size()+1);
    }
    return answer-1;
}