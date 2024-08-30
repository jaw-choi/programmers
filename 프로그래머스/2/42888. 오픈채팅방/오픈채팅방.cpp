#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string s1,s2,s3;
    unordered_map<string,string> mp;
    for(auto str : record)
    {
        string tmp{};
        stringstream s(str);
        s >> s1>>s2>>s3;
        if(s1=="Leave")
            continue;
        
        mp[s2] = s3;
    }
    for(auto str : record)
    {
        string tmp{};
        stringstream s(str);
        s >> s1>>s2>>s3;
        if(s1=="Change")
            continue;
        tmp += mp[s2];
        tmp += "님이 ";
        if(s1=="Enter")
            tmp+="들어왔습니다.";
        else if(s1=="Leave")
            tmp+="나갔습니다.";
        answer.push_back(tmp);
    }

    return answer;
}