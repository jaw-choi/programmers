#include <string>
#include <vector>

using namespace std;

int time(string s)
{
    int a = s[0] - '0';
    int b = s[1] - '0';
    int c = s[3] - '0';
    int d = s[4] - '0';
    return a * 600 + b * 60 + c * 10 + d;
}

string timeToStr(string len, int t)
{
    int end = time(len);
    if(t > end)
        return len;
    else if(t < 0)
        return "00:00";
    string ans = "";
    int a = t / 600;
    int b = (t % 600) / 60;
    int c = ((t % 600) % 60) / 10;
    int d = ((t % 600) % 60) % 10;
    ans+= a +'0';
    ans+= b +'0';
    ans+= ':';
    ans+= c +'0';
    ans+= d +'0';
    return ans;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string curr = pos;
    for(int i=0;i<commands.size();i++)
    {
        if(time(op_start) <= time(curr) && time(curr) < time(op_end))
        {
            curr = op_end;
        }
        
        if(commands[i] == "next")
        {
            curr = timeToStr(video_len,time(curr) + 10);
        }
        else
        {
            curr = timeToStr(video_len,time(curr) - 10);
        }
    }
    if(time(op_start) <= time(curr) && time(curr) < time(op_end))
    {
        curr = op_end;
    }
    return curr;
}