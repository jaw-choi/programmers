#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;
int timeToSec(string time)
{
    int hour = stoi(time.substr(0,2));
    int min = stoi(time.substr(3,2));
    return hour * 60 + min;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    int cnt = 0;
    vector<int> answer;
    string time,num,move;
    map<string,int> mp;
    for(auto r : records)
    {
        stringstream ss(r);
        ss >> time >> num >> move;
        if(move=="IN")
            mp[num]-=timeToSec(time);
        else
            mp[num]+=timeToSec(time);
    }
    for(auto& m : mp)
    {
        if(m.second <= 0)
            m.second += timeToSec("23:59");
        //cout << cnt++ << " " << m.second << endl;
    }
    for(auto m : mp)
    {
        int fee = 0;
        
        if(m.second > fees[0]){
            fee+=fees[1];
            if((m.second - fees[0])%fees[2]==0)
                fee +=((m.second - fees[0])/fees[2]) * fees[3];
            else
                fee += (((m.second - fees[0])/fees[2])+1) * fees[3];
        }
        else
            fee = fees[1];
        answer.push_back(fee);
    }
    return answer;
}