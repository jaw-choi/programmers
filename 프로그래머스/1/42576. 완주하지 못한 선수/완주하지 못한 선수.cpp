#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> mp;
    for(auto p : participant)
        mp[p]++;
    for(auto c : completion)
        mp[c]--;
    for(auto m : mp)
        if(m.second != 0)
            return m.first;
    return answer;
}