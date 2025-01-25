#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0;
    while(idx<progresses.size())
    {
        int cnt = 0;
        for(int i=idx;i<progresses.size();i++)
        {
            progresses[i] += speeds[i];
        }
        int currIdx = idx;
        for(int i=currIdx;i<progresses.size();i++)
        {
            if(progresses[i]>=100){
                cnt++;
                idx++;
            }
            else
                break;
        }
        if(cnt!=0)
            answer.push_back(cnt);
    }
    return answer;
}