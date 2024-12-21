#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
int strToInt(string time)
{
    int h1 = time[0] - '0';
    int h2 = time[1] - '0';
    int m1 = time[3] - '0';
    int m2 = time[4] - '0';
    return 600 * h1 + 60 * h2 + 10* m1  + m2;
}
int addTime(string time,int min)
{
    return strToInt(time) + min;
}
int getLastTime(int n,int t, int m)
{
    return strToInt("09:00") + (n-1) * t;
}
string intToStr(int t)
{
    string time="";
    time+=to_string(t/600);
    t = t%600;
    time+=to_string(t/60);
    t = t%60;
    time+=':';
    time+=to_string(t/10);
    t = t % 10;
    time+=to_string(t);
    return time;
}
string solution(int n, int t, int m, vector<string> timetable) {

    sort(timetable.begin(),timetable.end());
    int busTime = strToInt("09:00");
    int idx = 0;
    for(int i=1;i<=n;i++)
    {
        int numGetOn = 0;
        while(numGetOn < m && idx < timetable.size())
        {
            if(strToInt(timetable[idx]) <= busTime)
            {
                numGetOn++;
                idx++;
            }
            else break;
        }
        if(i==n)
        {
            if(numGetOn < m)
                return intToStr(busTime);
            return intToStr(strToInt(timetable[idx-1]) - 1);
        }
        busTime += t;
    }
    return 0;
}