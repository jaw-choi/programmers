#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(const vector<int>& a, const vector<int>& b)
{
    return a[1]<b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(),routes.end(),cmp);

    int right = routes[0][1];
    for(int i=1;i<routes.size();i++)
    {
        if(right < routes[i][0]){
            answer++;
            right = routes[i][1];
        }
    }
    return answer;
}