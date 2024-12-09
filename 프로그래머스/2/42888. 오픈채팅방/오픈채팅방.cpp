#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> mp;
    string s1,s2,s3;
    for(auto str : record){
        stringstream ss(str);
        ss >>s1>>s2>>s3;
        string tmp;
        tmp = s2;
        if(s1=="Enter" || s1=="Change")
        {
            mp[s2] = s3;
        }
        if(s1=="Enter"){
            tmp+="님이 들어왔습니다.";
            answer.push_back(tmp);
        }
        else if(s1=="Leave"){
            tmp+="님이 나갔습니다.";
            answer.push_back(tmp);
        }
    }
    for(auto& str:answer)
    {
        size_t pos = str.find("님");
        str.replace(0,pos,mp[str.substr(0,pos)]);
        
    }
    return answer;
}