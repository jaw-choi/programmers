#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    if(n>s)
        return {-1};
    vector<int> answer(n,s/n);
    int remain = s%n;
    for(int i=0;i<remain;i++)
    {
        answer[i]++;
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}