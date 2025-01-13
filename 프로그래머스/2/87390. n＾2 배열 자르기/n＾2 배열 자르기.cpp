#include <string>
#include <vector>

using namespace std;
int helper(long long idx, int n)
{
    int row = idx / n;
    int col = idx % n;
    if(col <=row)
        return row +1;
    return col + 1;
}
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i = left;i<=right;i++)
    {
        answer.push_back(helper(i,n));
    }
    
    return answer;
}