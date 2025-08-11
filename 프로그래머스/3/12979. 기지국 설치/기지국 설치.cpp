#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int cover = 2*w+1;
    int left = 1;
    for(int i=0;i<stations.size();i++)
    {
        int start = stations[i]-w;
        int end = stations[i]+w;
        if(left < start)
        {
            float gap = start - left;
            answer += ceil(gap / cover);
        }
        left = end+1;
    }
    if(left <=n)
    {
        float gap = n - left + 1;
        answer += ceil(gap/cover);
    }
    return answer;
}