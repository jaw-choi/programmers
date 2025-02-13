#include <string>
#include <vector>
#include <map>
#include <iostream>
#define MAX 100005
using namespace std;
void makeLower(string& str)
{
    for(auto& s : str)
    {
        if(s>='A' && s<='Z')
            s +=32;
    }
}
void LRU(map<string,int>& mp)
{
    string tmp;
    int minVal=MAX;
    for(auto m : mp)
    {
        if(m.second < minVal)
        {
            minVal = m.second;
            tmp = m.first;
        }
    }
    mp.erase(tmp);
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int idx = 0;
    if(cacheSize==0)
        return cities.size()*5;
    map<string,int> mp;
    for(auto c : cities)
    {
        makeLower(c);
        if(mp.find(c)==mp.end())
        {
            if(mp.size()>=cacheSize)//delete oldest one
                LRU(mp);
            answer+=5;
        }
        else
            answer++;
        mp[c] = idx++;
    }
    return answer;
}