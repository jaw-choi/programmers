#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> island(101);

bool cmp(vector<int> a , vector<int> b)
{
    return a[2]<b[2];
}

int findParents(int num)
{
    if(island[num] == num)
        return num;
    return findParents(island[num]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(),costs.end(),cmp);
    
    for(int i=0;i<n;i++)
    {
        island[i] = i;
    }
    for(int i=0;i<costs.size();i++)
    {
        int start = findParents(costs[i][0]);
        int end = findParents(costs[i][1]);
        int cost = costs[i][2];
        
        if(start!=end)
        {
            answer += cost;
            island[end] = start;
        }
    }
    return answer;
}