#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long> w(1001,0);
    for(auto weight : weights)
    {
        w[weight]++;
    }
    for(int i=100;i<=1000;i++)
    {
        if(w[i]==0) continue;
        
        if(w[i]>=2)
            answer += (w[i]*(w[i]-1))/2;
        
        if((i*3) % 2 ==0 && i*3/2 <=1000)
            answer += w[i]*w[i*3/2];
        if(i*2 <=1000)
            answer += w[i]*w[i*2];
        if((i*4)%3 == 0 && i*4/3 <=1000)
            answer += w[i]*w[i*4/3];
    }
    
    return answer;
}