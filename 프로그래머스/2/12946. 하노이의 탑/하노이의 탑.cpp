#include <string>
#include <vector>

using namespace std;

void Hanoi(int n,int start,int destination,vector<vector<int>>& answer)
{
    if(n<=1)
    {
        answer.push_back({start,destination});
        return;
    }
    Hanoi(n-1,start,6-start-destination,answer);
    answer.push_back({start,destination});
    Hanoi(n-1,6-start-destination,destination,answer);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    Hanoi(n,1,3,answer);
    return answer;
}