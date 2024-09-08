#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int timeToMinute(string time)
{
    return (time[0] - '0') * 600 + (time[1] - '0') * 60 +(time[3] - '0') * 10+(time[4] - '0');
}

string minuteToTime(int minute)
{
    string ans="00:00";
    int a = minute / 600;
    int b = (minute % 600) / 60;
    int c = ((minute % 600) % 60) / 10;
    int d = (((minute % 600) % 60) % 10);
    ans[0]= '0' + a;
    ans[1]= '0' + b;
    ans[3]= '0' + c;
    ans[4]= '0' + d;
    return ans;
}

string addTime(string currTime, int minute)
{
    int min = timeToMinute(currTime) + minute;
    return minuteToTime(min);
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    sort(timetable.begin(),timetable.end());
    unordered_map<string,vector<string>> mp;
    string currTime = "09:00";
    int index = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(index < timetable.size()){
                if(timetable[index] > currTime)
                    break;
                mp[currTime].push_back(timetable[index]);
                index++;
            }
        }
        if(i!=n-1)
            currTime = addTime(currTime,t);
    }
    sort(mp[currTime].begin(),mp[currTime].end());
    string lastTime{};
    if(mp[currTime].size() >= m)
    {
        lastTime = mp[currTime][m-1];
        answer = addTime(lastTime, -1);
    }
    else
    {
        answer = currTime;
    }
    //n개의 map
    //최대m개씩
    //++t
    //모두 찼을 때 가장 마지막 맵의 가장마지막멤버보다 1분 앞선 시간
    //덜찼으면 가장 마지막맵의 출발시간과 동일
    return answer;
}