#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;
string timeToString(int time)
{
    string ans="";
    ans += (time/36000) +'0';
    time  = time % 36000;
    ans += (time/3600) +'0';
    time = time%3600;
    ans+=':';
    
    ans += (time/600) +'0';
    time  = time % 600;
    ans += (time/60) +'0';
    time = time%60;
    ans+=':';
    
    ans += (time/10) +'0';
    time  = time % 10;
    ans += (time) +'0';
    return ans;
}
int getSeconds(string str)
{
    int time = 0;
    stringstream ss(str);
    string token;
    getline(ss,token,':');
    time += 3600 * (10*(token[0]-'0')+(token[1]-'0'));
    getline(ss,token,':');
    time += 60 * (10*(token[0]-'0')+(token[1]-'0'));
    getline(ss,token,':');
    time += (10*(token[0]-'0')+(token[1]-'0'));
    return time;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    string token;
    int play_time_seconds = getSeconds(play_time);
    int adv_time_seconds  = getSeconds(adv_time);

    vector<long long> timeline(play_time_seconds+2, 0);
vector<long long> preSum(play_time_seconds+2, 0);

for (string& log : logs) {
    stringstream ss(log);
    getline(ss, token, '-');
    int start = getSeconds(token);
    getline(ss, token, '-');
    int end = getSeconds(token);

    timeline[start] += 1;
    timeline[end ] -= 1; // 닫힌 구간
}

for (int i = 1; i <= play_time_seconds; i++)
    timeline[i] += timeline[i - 1];

for (int i = 1; i <= play_time_seconds; i++)
    preSum[i] = preSum[i - 1] + timeline[i];

long long res = -1;
int k = 0;
for (int i = 0; i + adv_time_seconds <= play_time_seconds; i++) {
    int end = i + adv_time_seconds - 1; // 반열린 구간 [i, i+adv_time_seconds)
    long long cnt = preSum[end] - (i > 0 ? preSum[i-1] : 0);
    if (cnt > res) {
        res = cnt;
        k = i;
    }
}


return timeToString(k);

}