#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    long long cnt1 = 0;
    long long cnt2 = 0;
    int n = sequence.size();
    vector<int> v1 = sequence;
    vector<int> v2 = sequence;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            v1[i]=-v1[i];
        else
            v2[i]=-v2[i];
    }
    for(int i=0;i<n;i++)
    {
        if(cnt1 < 0)
            cnt1 = v1[i];
        else
            cnt1 += v1[i];
        if(cnt2 < 0)
            cnt2 = v2[i];
        else
            cnt2 += v2[i];
        answer = max(answer,cnt1);
        answer = max(answer,cnt2);
    }
    //cout << answer;
    return answer;
}