#include <string>
#include <vector>

using namespace std;
int toTime(int time)
{
    int h = time / 100;
    int m = time %100;
    if(m>=60){
        h++;
        m-=60;
    }
    return h*100 + m;
}
int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i=0;i<schedules.size();i++)
    {
        int tmp = startday;
        for(int j=0;j<timelogs[0].size();j++)
        {
            if(tmp>7)
                tmp=1;
            if(tmp<6)
            {
                if(toTime(schedules[i]+10)<toTime(timelogs[i][j]))
                    break;
            }
            tmp++;
            if(j==6)
                answer++;
        }
    }
    return answer;
}