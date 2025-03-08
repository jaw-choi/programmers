#include <string>
#include <vector>
#include <iostream>

using namespace std;

int helper(int idx, int k, int val, vector<int>& server)
{
    if(server[idx]!=0)
        val = val - server[idx];
    for(int i=idx;i<idx+k;i++)
    {
        if(i>=server.size())
            break;
        server[i]+=val;
    }
    return val;
}

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int curr = 0;
    vector<int> server(24,0);
    for(int i=0;i<players.size();i++)
    {
        if(players[i] >= (server[i]+1)*m){
            curr = players[i]/m;
            answer += helper(i,k,curr,server);

        }
    }

    
    return answer;
}