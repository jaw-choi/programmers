#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
#define MAX 5
#define MIN -5
string reverse(string s)
{
    string r = "";
    r += s[2];
    r += s[3];
    r += s[0];
    r += s[1];
    return r;
}
int solution(string dirs) {
    int answer = 0;
    unordered_map<string,int> mp;
    string key = "";
    string rev = "";
    int curr[2] = {0,0};
    int x[4] = {0,0,-1,1};
    int y[4] = {1,-1,0,0};
    for(int i=0;i<dirs.size();i++)
    {
        key = (curr[0] + 'f');
        key += (curr[1] + 'f');
        if(dirs[i]=='U' && curr[1]!=MAX)
        {
            curr[1]+=y[0];
        }
        else if(dirs[i]=='D' && curr[1]!=MIN)
        {
            curr[1]+=y[1];
        }
        else if(dirs[i]=='L' && curr[0]!=MIN)
        {
            curr[0]+=x[2];
        }
        else if(dirs[i]=='R' && curr[0]!=MAX)
        {
            curr[0]+=x[3];
        }
        key += (curr[0] + 'f');
        key += (curr[1] + 'f');
        rev = reverse(key);
        if(mp.find(key)==mp.end() && mp.find(rev)==mp.end())
        {
            if(key.substr(0,2)!=key.substr(2,2))
                answer++;
        }
            mp[rev]++;
            mp[key]++;

    }
    
    return answer;
}