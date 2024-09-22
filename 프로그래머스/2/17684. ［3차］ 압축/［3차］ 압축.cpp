#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string,int> mp;
    int index = 0;
    for(int i=0;i<26;i++,index++)
    {
        char alp = 'A' + i;
        string word = "";
        word+=alp;
        mp[word] = i+1;
    }
    string curr = "";
    for(int i=0;i<msg.length();i++)
    {
        curr += msg[i];
        if(mp[curr]==0)
        {
            mp[curr] = ++index;
            curr = curr.substr(0,curr.length()-1);
            answer.push_back(mp[curr]);
            i--;
            curr = "";
        }
    }
    answer.push_back(mp[curr]);
    return answer;
}