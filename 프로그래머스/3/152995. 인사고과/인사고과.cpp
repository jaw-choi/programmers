#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;
bool cmp(vector<int> a, vector<int> b)
{
    return a[0]+a[1] > b[0]+b[1];
}
int solution(vector<vector<int>> scores) {
    int answer = 1;
    int target = scores[0][0]+scores[0][1];
    sort(scores.begin()+1,scores.end(),cmp);
    //22,14,32,32,21
    map<int,int> mp;
    for(int i=1;i<scores.size();i++)
    {
        if(scores[0][0]<scores[i][0] && scores[0][1] < scores[i][1])
            return -1;
        if(scores[i][0]+scores[i][1] > target)
            answer++;
        else
            break;
    }
int wanho = answer;
    for(int c = 2; c < wanho; ++c)
    {
        for(int p = 1; p < c; ++p)
        {        
            if(scores[c][0] < scores[p][0] 
               && scores[c][1] < scores[p][1])
            {
                --answer;
                break;
            }
        }
    }
    
    //14,22,21,32,32
    return answer;
}